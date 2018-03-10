# Makefile of ROOT for Linux with glibc and egcs (RH5.1)

include make-chain

CXX           = g++
#CC            = gcc
KRRun         = /home/ciepal/Main/KRATTA/test-2014-10/mktreedst/fit/z4dexp2tr_new_last_last

ROOTCFLAGS   := $(shell root-config --cflags) 
ROOTLDFLAGS  := $(shell root-config --ldflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTGLIBS    := $(shell root-config --glibs)
HASTHREAD    := $(shell root-config --has-thread)
PLATFORM     := $(shell root-config --platform)

#CXXFLAGS      = -O -Wall -fPIC -Dbaribal $(ROOTCFLAGS) -I$(FBRun)
CXXFLAGS      = -Wall -fPIC -Dklon $(ROOTCFLAGS) -I$(KRRun)

CFLAGS        = -Wall -fPIC  -DR__GLIBC -I$(ROOTSYS)/include 
OPT           = -g
OPT1          = -o 

LD            = g++
LDFLAGS       = $(OPT)
SOFLAGS       = -shared -Wl,-soname,
SOEXT         = so
SYSLIBS       = -L/usr/lib -lm 
SYSXLIBS      =  -ldl  
XLIBS         = $(ROOTSYS)/lib/libXpm.a -L/usr/X11R6/lib -lX11
CILIBS        = -lm -ltermcap -lbsd -ldl -shared 

LIBS          = $(ROOTLIBS)
GLIBS         = $(ROOTGLIBS)  -L./ -lKRRun

COMP          =klon

##### MACROS and TARGETS #####

include Make-macros




