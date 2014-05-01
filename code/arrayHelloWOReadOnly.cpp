#include "arr.decl.h"

struct Main : CBase_Main {
  Main(CkArgMsg* msg) {
    int arraySize = atoi(msg->argv[1]);
    CProxy_hello p = CProxy_hello::ckNew(arraySize, arraySize);
    p[0].printHello();
  }
};

struct hello : CBase_hello {
  hello(int n) : arraySize(n) { }
  hello(CkMigrateMessage*) { }
  void printHello() {
    CkPrintf("PE[%d]: hello from p[%d]\n", CkMyPe(), thisIndex);
    if (thisIndex == arraySize - 1) CkExit();
    else thisProxy[thisIndex + 1].printHello();
  }
  private:
  int arraySize;
};

#include "arr.def.h"
