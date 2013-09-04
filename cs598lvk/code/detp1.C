#include "Determinants.decl.h"
#include <cstdlib>
#include <vector>

struct Main : public CBase_Main {
  int count; std::vector<int> dets;
  Main(CkArgMsg *msg) {
    if (msg->argc < 3) CkAbort("Usage: det <n> <m>");
    int n = std::atoi(msg->argv[1]), m = std::atoi(msg->argv[2]);
    std::srand(29);
    count = n + m;
    dets.resize(n + m);

    for (int i = 0; i < n + m; ++i) {
      int matrix[9];
      int size = i < n ? 2 : 3;
      for (int j = 0; j < size*size; ++j)
        matrix[j] = std::rand();
      CProxy_DeterminantChare::ckNew(thisProxy, i, size, matrix);
    }
  }

  void response(int index, int det) {
    dets[index] = det;
    if (--count == 0) {
      for (int i = 0; i < dets.size(); ++i)
        CkPrintf("Determinant of matrix %d is %d\n", i, dets[i]);
      CkExit();
    }
  }
};
