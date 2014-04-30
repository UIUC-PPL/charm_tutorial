#include "prefix.decl.h"
#include <stdlib.h>

class Main : public CBase_Main {
  public:
  CProxy_Prefix prefixArray;

  Main(CkArgMsg* msg) {
    int numElements = 10;
    if (msg->argc > 1) 
      numElements = atoi(msg->argv[1]);
    prefixArray = CProxy_Prefix::ckNew(numElements, thisProxy, numElements);
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
    int stage, targetIndex, value, numElements;
    CProxy_Main mainProxy;

    Prefix(int n, CProxy_Main p) : numElements(n), mainProxy(p) {
      srand(thisIndex);
      value = rand() % 10;      // Random positive int between 0 and 9 (inclusive)
    }
    Prefix(CkMigrateMessage *msg) { }

};
#include "prefix.def.h"
