CHARM_HOME=~/Programming/libraries/charm/

EXES=arrayHello chareCreate fib fibSDAG jacobi3d pi reductionMainTarget

all: $(EXES)

arrayHello: arrayHello.ci arrayHello.cpp
	$(CHARM_HOME)/bin/charmc arrayHello.ci arrayHello.cpp -o arrayHello

chareCreate: chareCreate.ci chareCreate.C
	$(CHARM_HOME)/bin/charmc chareCreate.ci chareCreate.C -o chareCreate

fib: fib.ci fib.C
	$(CHARM_HOME)/bin/charmc fib.ci fib.C -o fib

fibSDAG: fibSDAG.ci fibSDAG.cc
	$(CHARM_HOME)/bin/charmc fibSDAG.ci fibSDAG.cc -o fibSDAG

jacobi3d: jacobi3d.ci jacobi3d.C
	$(CHARM_HOME)/bin/charmc jacobi3d.ci jacobi3d.C -o jacobi3d

reductionMainTarget: reductionMainTarget.ci reductionMainTarget.cpp
	$(CHARM_HOME)/bin/charmc reductionMainTarget.ci reductionMainTarget.cpp -o reductionMainTarget

pi: pi.ci pi.C
	$(CHARM_HOME)/bin/charmc pi.ci pi.C -o pi

clean:
	rm -rf *.def.h *.decl.h *.o charmrun $(EXES)
