#include "Determinants.decl.h"
#include <cstdlib>
using std::atoi; using std::rand; using std::srand;

struct Main : public CBase_Main {
  Main_SDAG_CODE
  int i, n, m;
  Main(CkArgMsg *msg) {
    __sdag_init();
    if (msg->argc < 3) CkAbort("Usage: det <n> <m>");
    n = atoi(msg->argv[1]); m = atoi(msg->argv[2]);
    srand(29);
    run();
  }
};
struct DeterminantChare : public CBase_DeterminantChare {
  DeterminantChare(CProxy_Main main, int i, int n, int *matrix) {
    int retVal;
    if (n == 2) retVal = matrix[0]*matrix[3] - matrix[1]*matrix[2];
    else if (n == 3)
      retVal = matrix[0]*matrix[4]*matrix[8]
             + matrix[1]*matrix[5]*matrix[6]
             + matrix[2]*matrix[3]*matrix[7]
             - matrix[0]*matrix[5]*matrix[7]
             - matrix[1]*matrix[3]*matrix[8]
             - matrix[2]*matrix[4]*matrix[6];
    else CkAbort("Only supports determinants of size 2 or 3!");
    main.response(i, retVal);
  }
};

#include "Determinants.def.h"
