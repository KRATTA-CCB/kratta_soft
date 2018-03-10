#  Makefile for compilation of tree maker

OutPutOpt     = -o 
CXX           = g++
LD            = g++
LDFLAGS       = -O -L. -L/usr/X11R6/lib -lX11 -lXext
SOFLAGS       = -shared
#CXXFLAGS      = -Wall $(ROOTCFLAGS) -I$(incdirD) -I$(incdirF) -I$(incdirP) -Dreadline 
CXXFLAGS      = -Wall $(ROOTCFLAGS)  -Dreadline 

ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --new --libs)
ROOTGLIBS    := $(shell root-config --new --glibs)

LIBS         = $(ROOTLIBS) $(SYSLIBS) -lncurses
GLIBS        = $(ROOTGLIBS) $(SYSLIBS)

coincid: coincid.o

	$(LD) $(LDFLAGS) $^ $(GLIBS) $(OutPutOpt) $@

clear:
	rm  -f  coincid coincid.o

info:
	echo $(ROOTGLIBS)
	echo $(shell pwd)
	echo $(shell date)
