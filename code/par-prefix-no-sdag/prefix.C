#include "prefix.decl.h"
#include <math.h> 

/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ CProxy_Prefix prefixArray;
/*readonly*/ int numElements;

struct Main : public CBase_Main {
  Main(CkArgMsg* msg) {
    mainProxy= thisProxy;
    numElements = 8;  // Default numElements to 8
    if (msg->argc > 1) numElements = atoi(msg->argv[1]);
    delete msg;
    prefixArray = CProxy_Prefix::ckNew(numElements);
  }
  Main(CkMigrateMessage* msg) {};

  void done() { CkExit(); }
};



struct Prefix : public CBase_Prefix {
  int* valueBuf, *flagBuf, value, stage, numStages;
  Prefix() {
    stage = 0;
    numStages = log2(numElements);
    valueBuf = (int*)malloc(numStages*sizeof(int));
    flagBuf = (int*)calloc(numStages, sizeof(int));
    srand(time(NULL)+thisIndex);
    value = rand()%10+1;
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
    flagBuf[incoming_stage] = 1;
    valueBuf[incoming_stage] = incoming_value;

    for(int i=stage; i<numStages; i++){
        if(flagBuf[i] == 0) break; 
        value += valueBuf[i];
        stage++;
        step(value);
    }
  }
};

#include "prefix.def.h"
