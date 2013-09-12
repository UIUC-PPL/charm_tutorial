#CHARMC = /home/njain/charms/charm/pamilrts-bluegeneq-xlc/bin/charmc $(OPTS)
CHARMC = $(HOME)/charm_no_touch/net-darwin-x86_64/bin/charmc $(OPTS)
#CHARMC = $(HOME)/workspace/charm/bin/charmc $(OPTS)

default: all
all: prefix


prefix : prefix.o
	$(CHARMC) -language charm++ -o prefix prefix.o

prefix.o : prefix.C prefix.decl.h prefix.def.h 
	$(CHARMC) -o prefix.o prefix.C

prefix.decl.h prefix.def.h : prefix.ci
	$(CHARMC) prefix.ci

clean:
	rm -f prefix.decl.h prefix.def.h prefix.o
	rm -f prefix charmrun
