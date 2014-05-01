#include "sdag.decl.h"
#define THRESHOLD 10

class Main : public CBase_Main {
public: Main(CkArgMsg* m) { CProxy_Fib::ckNew(atoi(m->argv[1]), true, CProxy_Fib()); }
};

class Fib : public CBase_Fib {
public:
  Fib_SDAG_CODE
  CProxy_Fib parent; bool isRoot;

  Fib(int n, bool isRoot_, CProxy_Fib parent_)
    : parent(parent_), isRoot(isRoot_) {
    calc(n);
  }

  int seqFib(int n) { return (n < 2) ? n : seqFib(n - 1) + seqFib(n - 2); }

  void respond(int val) {
    if (!isRoot) {
      parent.response(val);
      delete this;
    } else {
      CkPrintf("Fibonacci number is: %d\n", val);
      CkExit();
    }
  }
};

#include "sdag.def.h"
