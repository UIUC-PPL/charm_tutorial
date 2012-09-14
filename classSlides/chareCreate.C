#include <stdio.h>
#include "MyModule.decl.h"

struct Main : public CBase_Main {
  Main(CkArgMsg* m) {
    ckout << "Hello World!" << endl;
    if (m->argc > 1) ckout << " Hello " << m->argv[1] << "!!!" << endl;
    double pi = 3.1415;
    CProxy_Simple::ckNew(12, pi);
  };
};
struct Simple : public CBase_Simple {
 Simple(int x, double y) {
   ckout << "Hello from a simple chare running on " << CkMyPe() << endl;
   ckout << "Area of a circle of radius" << x << " is " << y*x*x << endl;
   CkExit();
 }
};

#include "MyModule.def.h"
