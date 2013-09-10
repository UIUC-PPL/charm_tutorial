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
  int value;
  int distance;
  Prefix() {
    distance = 1;
    srand(time(NULL));
    value = rand() % 10;
    step();
  }
  Prefix(CkMigrateMessage*){};

  void step(){
    if(thisIndex+distance<numElements)
      thisProxy[thisIndex+distance].passValue(value);
  }

  void passValue(int incoming_value){
    value += incoming_value;
    distance = distance*2;
    if(distance < numElements){
      step();
    }
    else{
      CkPrintf("\nPrefix[%d].value = %d\n", thisIndex, value);
      contribute(CkCallback(CkReductionTarget(Main, done), mainProxy));
    }
  }

};

#include "prefix.def.h"
