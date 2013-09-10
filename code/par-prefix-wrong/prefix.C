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
    doneCount++;
    if(doneCount >= numElements){
      CkExit();
    }
  }
};

struct Prefix : public CBase_Prefix {
  int value;
  int stage;
  int numStages;
  Prefix() {
    stage = 0;
    numStages = log2(numElements);
    srand(time(NULL));
    value = rand() % 10;
    run();
  }
  Prefix(CkMigrateMessage*){};

  void run(){
    if(thisIndex%(int)pow(2,stage)==0)
      thisProxy[thisIndex+pow(2,stage)].getValue(stage, value);
  }

  void getValue(int stage, int incoming_value){
    value += incoming_value;
    if(numStages >= stage){
      stage++;
      run();
    }
    else{
      mainProxy.done();
      CkPrintf("\nPrefix[%d].value = %d\n", CkMyPe(), value);
    }
  }

};

#include "prefix.def.h"
