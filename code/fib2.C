#define THRESHOLD 10

class Fib {
  Fib parent; bool isRoot; int result; int count;

  Fib(int n, bool isRoot_, Fib parent_)
    : parent(parent_)
    , isRoot(isRoot_)
    , result(0)
    , count(2)
  {
    if (n < THRESHOLD) respond(seqFib(n));
    else {
      // create new parallel object Fib(n - 1, false, this);
      // create new parallel object Fib(n - 2, false, this);
    }
  }

  int seqFib(int n) { return (n < 2) ? n : seqFib(n - 1) + seqFib(n - 2); }

  void respond(int val) {
    result += val;
    if (--count == 0 || n < THRESHOLD) {
      if (isRoot) {
        printf("Fibonacci number is: %d\n", result); 
        exit();
      } else {
        parent.respond(result);
      }
    }
  }
};
