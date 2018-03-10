#ifndef __GEO_CLASS__
#define __GEO_CLASS__

#include "TObject.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////

class ASYsignal : public TObject{

 
public:
  Int_t number;    // signal number (label) within a module [0..2]
  Int_t module;    // module number (label)
  Int_t fadc_mod;  // fadc module number (label)
  Int_t fadc_chn;  // fadc channel number [0-7]
  Int_t ok;        // OK flag [0,1]
  Float_t theta;   // theta
  Float_t phi;     // phi
  Float_t thick;   // thickness
  Float_t tbin;    // FADC time bin
  string slab;     // label
  ASYsignal();
  virtual ~ASYsignal();
  //void Set
  ClassDef(ASYsignal,1)  //signal
};

class ASYgeo : public TObject{
 
public:
  TClonesArray *tca_signal;      // signal structure
  Int_t nfadc_mod;
  Int_t min_fadc_mod;
  Int_t max_fadc_mod;
  Int_t nmodule;
  Int_t nsignal;
  Int_t *signalpermod;
  Float_t *gain_fct;
  Float_t P4[35][3],P5[35][3],P6[35][3],P7[35][3],P8[35][3],P9[35][3];
  Float_t P10[35][3],P11[35][3],P12[35][3];
  ASYgeo();
  virtual ~ASYgeo();
  void     ReadGeo(const char *dat_file=0);
  void     LoadParRCGAM8SI(const int irun=0, const char *dat_file=0);
  void     LoadParRCGAM10SI(const int irun=0, const char *dat_file=0);
  void     LoadParRC3GAM2DEXP13(const int irun=0, const char *dat_file=0);
  ASYsignal*  NewSignal(Int_t n){return new((*tca_signal)[n]) ASYsignal();} // Setup signal
  ASYsignal*  Signal(Int_t n) const {return (ASYsignal*)((*tca_signal)[n]);} // Get signal
  Int_t GetSignalNo(Int_t indx)
        {return (indx>=0 && indx<nsignal) ? Signal(indx)->number : -1;}
  Int_t GetSignalOK(Int_t indx)
        {return (indx>=0 && indx<nsignal) ? Signal(indx)->ok : -1;}
  Int_t GetModuleNo(Int_t indx)
        {return (indx>=0 && indx<nsignal) ? Signal(indx)->module : -1;}
  Int_t GetFadcChannelNo(Int_t indx)
        {return (indx>=0 && indx<nsignal) ? Signal(indx)->fadc_chn : -1;}
  Int_t GetFadcModuleNo(Int_t indx)
        {return (indx>=0 && indx<nsignal) ? Signal(indx)->fadc_mod : -1;}
  string GetLabel(Int_t indx)
        {return (indx>=0 && indx<nsignal) ? Signal(indx)->slab : "";}

  Int_t GetSignalNoFromFadc(Int_t ifadcmod, Int_t ifadcchan){
        return GetSignalNo(GetIndexFromFadc(ifadcmod, ifadcchan));}

  Int_t GetSignalNoFromSignal(Int_t imod, Int_t isignal){
        return GetSignalNo(GetIndexFromSignal(imod, isignal));}

  Int_t GetIndexFromFadc(Int_t ifadcmod, Int_t ifadcchan);
  Int_t GetIndexFromSignal(Int_t imodule, Int_t isignal);

  void ListChannels();
//  void DrawSetup();
//  void ReadGainFactors(Int_t irun, const char *dat_file=0);

// TCanvas *GetCanvasX(){return csignals;}
// TCanvas *GetCanvasY(){return ctime;}
// TCanvas *csignals;
// TCanvas *ctime;
// TH1F *GetSnullX(){return snullx;}
// TH1F *snullx;
// TH1F *GetSnullY(){return snully;}
// TH1F *snully;

//  Int_t  fadc_mod(Int_t ifadcmod){return nfadc_mod;}
//  Int_t  Signal(Int_t ifadcmod, Int_t ichan){return nfadc_mod;}
  
  
  ClassDef(ASYgeo,1)  //geometry
};

///////////////////////////////////////////////////////////////////////////////

#endif
