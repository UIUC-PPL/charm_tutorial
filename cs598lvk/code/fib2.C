#define THRESHOLD 10

struct Main : public CBase_Main { /* ... same as before ... */ };

struct Fib : public CBase_Fib {
  CProxy_Fib parent; bool isRoot; int result, count;

  Fib(int n, bool isRoot_, CProxy_Fib parent_)
    : parent(parent_), isRoot(isRoot_), result(0), count(n < THRESHOLD ? 1 : 2) {

    if (n < THRESHOLD) response(seqFib(n));
    else {
      CProxy_Fib::ckNew(n - 1, false, thisProxy);
      CProxy_Fib::ckNew(n - 2, false, thisProxy);
    }
  }

  int seqFib(int n) { return (n < 2) ? n : seqFib(n - 1) + seqFib(n - 2); }

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
