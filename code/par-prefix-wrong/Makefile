#CHARMC=/home/acun2/charm/net-linux-x86_64/bin/charmc $(OPTS)
CHARMC=/Users/bilge/charm_no_touch/net-darwin-x86_64/bin/charmc $(OPTS)

M = 10

all: prefix

prefix:   prefix.o
	$(CHARMC) prefix.o -o prefix -language charm++ 

prefix.o : prefix.C prefix.def.h prefix.decl.h
	$(CHARMC) -c prefix.C

prefix.def.h prefix.decl.h : prefix.ci
	$(CHARMC) prefix.ci

test: all
	./charmrun prefix $(M) +p4 ++local

clean:
	rm -f conv-host *.o charmrun prefix
	rm -f *.def.h *.decl.h
	rm -f *.log.gz *.projrc *.topo *.sts

