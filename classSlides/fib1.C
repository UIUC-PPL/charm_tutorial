struct Main : public CBase_Main {
  Main(CkArgMsg* m) { 
    CProxy_Fib::ckNew(atoi(m->argv[1]), true, CProxy_Fib()); 
  }
};

struct Fib : public CBase_Fib {
  CProxy_Fib parent; bool isRoot; int result, count;

  Fib(int n, bool isRoot_, CProxy_Fib parent_)
    : parent(parent_), isRoot(isRoot_), result(0), count(n < 2 ? 1 : 2) {

    if (n < 2) response(n); 
    else {
      CProxy_Fib::ckNew(n - 1, false, thisProxy);
      CProxy_Fib::ckNew(n - 2, false, thisProxy);
    }
  }

  void response(int val) {
    result += val;
    if (--count == 0) {
      if (isRoot) {
        CkPrintf("Fibonacci number is: %d\n", result); 
        CkExit();
      } else {
        parent.response(result);
        delete this;
      }
    }
  }
};
