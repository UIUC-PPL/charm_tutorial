#include "fib.decl.h"

class Main : public CBase_Main {
public: Main(CkArgMsg* m) {
    CProxy_Fib::ckNew(atoi(m->argv[1]), true, CProxy_Fib()); 
  }
};

class Fib : public CBase_Fib {
public: CProxy_Fib parent; bool isRoot; int result, count, n;

  Fib(int n_, bool isRoot_, CProxy_Fib parent_)
    : parent(parent_), isRoot(isRoot_), result(0), count(2), n(n_) {

    if (n < 2) respond(n);
    else {
      CProxy_Fib::ckNew(n - 1, false, thisProxy);
      CProxy_Fib::ckNew(n - 2, false, thisProxy);
    }
  }

  void respond(int val) {
    result += val;
    if (--count == 0 || n < 2) {
      if (isRoot) {
        CkPrintf("Fibonacci number is: %d\n", result); 
        CkExit();
      } else {
        parent.respond(result);
        delete this;
      }
    }
  }
};

#include "fib.def.h"
