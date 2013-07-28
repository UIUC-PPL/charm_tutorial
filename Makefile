#include LaTeX.mk

TARGET = tutorial.pdf
ANL_TARGET = tutorial_ATPESC.pdf

.PHONY: all web

all: clean $(TARGET) web
anl: clean $(ANL_TARGET)

%.pdf: %.tex
	pdflatex $<
	pdflatex $<
	#bibtex $(basename $<)
	#pdflatex $<

clean:
	rm -f $(wildcard *.ilg *.aux *.log *.dvi *.idx *.toc *.lof *.lot *.spl *.blg *.bbl *.out *.nav *.snm *.ps *~)
	rm -f $(TARGET) $(ANL_TARGET)

web: $(TARGET)
	if test -d "/www/users/ramv"; then cp $< /www/users/ramv/2012-charm-tutorial.pdf; fi

