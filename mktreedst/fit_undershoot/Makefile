ObjSuf        = o
SrcSuf        = cxx
ExeSuf        =
DllSuf	      = so
PROGRAMLIB    = $(PROGRAMO)
OutPutOpt     = -o

ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs)

ROOTLIBS      += -lFumili

# Linux with egcs
# CXX           = g++
# CXXFLAGS      = -g -pg -O2 -Wall -fPIC
# LD            = g++
# LDFLAGS       = -g -pg
# SOFLAGS       = -shared
CXX           = g++
CXXFLAGS      =  -O2 -Wall -fPIC
# CXXFLAGS      =  -O2 -g -Wall -fPIC
LD            = g++
LDFLAGS       = 
SOFLAGS       = -shared

CXXFLAGS     += $(ROOTCFLAGS)
LIBS          = $(ROOTLIBS)
GLIBS         = $(ROOTGLIBS)

CXXFLAGS     += -I$(S394WRK) -I$(S394WRK)/geo -I$(S394REF)/src/TAGbase -I$(S394REF)/src/TAGmbs
LIBS         += $(S394WRK)/mktreeraw_C.so
LIBS         += $(S394WRK)/geo/geo_C.so
#LIBS         += -lgmp
LIBS         += -L$(S394REF)/lib -lTAGbase -lTAGmbs

#------------------------------------------------------------------------------

PROGRAMO        = mktreedstchain_sct_fitABC.$(ObjSuf) \
                mktreedstchain_sct_fitABCCint.$(ObjSuf)

PROGRAMS        = mktreedstchain_sct_fitABC.$(SrcSuf) \
                mktreedstchain_sct_fitABCCint.$(SrcSuf)

MAINPROGRAMO    = mktreedstchain_sct_fitABC_main.$(ObjSuf)
MAINPROGRAMS    = mktreedstchain_sct_fitABC_main.$(SrcSuf)

PROGRAM         = mktreedstchain_sct_fitABC$(ExeSuf)
PROGRAMSO       = libmktreedstchain_sct_fitABC.$(DllSuf)

OBJS          = $(PROGRAMO) $(MAINPROGRAMO) 

all:            $(PROGRAM)

$(PROGRAM):	$(PROGRAMO) $(MAINPROGRAMO)
		$(LD) $(SOFLAGS) $(LDFLAGS) $(PROGRAMO) $(OutPutOpt) $(PROGRAMSO)
		$(LD) $(LDFLAGS) $(MAINPROGRAMO) $(PROGRAMLIB) $(LIBS) $(OutPutOpt) $(PROGRAM)
		@echo "$(PROGRAM) done"

#cp:
#		@cp libre_tab.so $(re_tab)/lib
#		@cp re_tab.hxx $(re_tab)/include
#		@cp re_tab.cxx $(re_tab)/src
#		@echo "files copied to $(re_tab)"
clean:
		@rm -f $(OBJS) mktreedstchain_sct_fitABCCint.$(SrcSuf) mktreedstchain_sct_fitABCCint.h  core libmktreedstchain_sct_fitABC.so mktreedstchain_sct_fitABC

.SUFFIXES: .$(SrcSuf)

###

mktreedstchain_sct_fitABC.o: mktreedstchain_sct_fitABC.hxx
mktreedstchain_sct_fitABC_main.o: mktreedstchain_sct_fitABC.hxx

mktreedstchain_sct_fitABCCint.$(SrcSuf): mktreedstchain_sct_fitABC.hxx LinkDef.h
	@echo "Generating dictionary ..."
	@$(ROOTSYS)/bin/rootcint -f mktreedstchain_sct_fitABCCint.$(SrcSuf) -c mktreedstchain_sct_fitABC.hxx LinkDef.h

.$(SrcSuf).$(ObjSuf):
	$(CXX) $(CXXFLAGS) -c $<
