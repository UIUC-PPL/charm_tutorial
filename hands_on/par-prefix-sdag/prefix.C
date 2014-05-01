#include "prefix.decl.h"
#include <stdlib.h>
/* readonly */ CProxy_Main mainProxy;
/* readonly */ int numElements;

class Main : public CBase_Main {
  public:
  CProxy_Prefix prefixArray;

  Main(CkArgMsg* msg) {
    numElements = 8;
    if (msg->argc > 1) numElements = atoi(msg->argv[1]);
    mainProxy = thisProxy;
    prefixArray = CProxy_Prefix::ckNew(numElements);
    prefixArray.startPrefixCalculation();
  }
  Main(CkMigrateMessage* msg) { }

  void checkIn() {
    CkExit();
  }
};

class Prefix : public CBase_Prefix {
  Prefix_SDAG_CODE

  public:
    int stage, targetIndex, value;

    Prefix() {
      srand(thisIndex);
      value = rand() % 10;      // Random positive int between 0 and 9 (inclusive)
    }
    Prefix(CkMigrateMessage *msg) { }

};
#include "prefix.def.h"
