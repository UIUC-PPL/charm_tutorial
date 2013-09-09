#include "arr.decl.h"

/*readonly*/ int arraySize;

struct Main : CBase_Main {
  Main(CkArgMsg* msg) {
    arraySize = atoi(msg->argv[1]);
    CProxy_hello p = CProxy_hello::ckNew(arraySize);
    p[0].printHello();
  }
};

struct hello : CBase_hello {
  hello() { }
  hello(CkMigrateMessage*) { }
  void printHello() {
    CkPrintf("PE[%d]: hello from p[%d]\n", CkMyPe(), thisIndex);
    if (thisIndex == arraySize - 1) CkExit();
    else thisProxy[thisIndex + 1].printHello();
  }
};

#include "arr.def.h"
