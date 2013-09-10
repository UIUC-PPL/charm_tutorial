#include "prefix.decl.h"
#include <math.h> 

/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ CProxy_Prefix prefixArray;
/*readonly*/ int numElements;

struct Main : public CBase_Main {
  int doneCount;
  Main(CkArgMsg* msg) {
    mainProxy= thisProxy;
    numElements = 8;  // Default numElements to 8
    doneCount = 0;
    if (msg->argc > 1)
      numElements = atoi(msg->argv[1]);
    delete msg;
    CkPrintf("\nRunning \"Parallel Prefix\" with %d elements "
                "using %d processors.\n", numElements, CkNumPes());

    prefixArray = CProxy_Prefix::ckNew(numElements);
  }
  Main(CkMigrateMessage* msg) {};

  void done(){
      CkExit();
  }
};

struct Prefix : public CBase_Prefix {
  int* buffer;
  int value, stage, numStages, flag;
  Prefix() {
    stage = 0;
    flag = 0;
    numStages = log2(numElements);
    buffer = (int*)calloc(numStages, sizeof(int));
    srand(time(NULL)+thisIndex);
    value = rand()%10+1;
    CkPrintf("Before Prefix[%d].value = %d\n", thisIndex, value);
    step(value);
  }
  Prefix(CkMigrateMessage*){};

  void step(int value){
    if(stage >= numStages){
      CkPrintf("Prefix[%d].value = %d\n", thisIndex, value);
      contribute(CkCallback(CkReductionTarget(Main, done), mainProxy));
    }
    else{
      int sendIndex = thisIndex + (1<<stage);
      if(sendIndex < numElements)
        thisProxy[sendIndex].passValue(stage, value);
      //if you no longer receive, but need to continue sending
      if(thisIndex-(1<<stage) < 0){
        stage++;
        step(value);              
      }
    }
  }




  void passValue(int incoming_stage, int incoming_value){
    //CkPrintf("[%d] get value from stage [%d]\n", thisIndex, incoming_stage);
    buffer[incoming_stage] = incoming_value;

    //if the data is coming from a higher stage, set the flag
    if(incoming_stage > stage) flag = 1;
    else{
      value += buffer[incoming_stage];
      stage++;
      step(value);
      if(flag == 1){
        for(int i=stage; i<numStages; i++){
            if(buffer[i] == 0) break; 
            value += buffer[i];
            stage++;
            step(value);
            flag = 0;
        }
      }
    }
  }
};

#include "prefix.def.h"
