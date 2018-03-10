#ifndef __ABC__
#define __ABC__

#include <math.h>

#include "TObject.h"
#include "TFile.h"
#include "TProfile.h"
#include "TH1F.h"
#include "TH1.h"
#include "TH2F.h"
#include "TRandom.h"
#include "TNtuple.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TChain.h"
#include "TF1.h"
#include "TLatex.h"
#include "TBranch.h"
#include "TCutG.h"
#include "TROOT.h"
#include "TLine.h"
#include "TLegend.h"
#include "TChainElement.h"
#include "TSpectrum.h"
#include "TMarker.h"
#include "TMath.h"
#include "TControlBar.h"
#include "TApplication.h"
#include "TMatrixD.h"
#include "TVector3.h"
#include "TVectorD.h"
#include "TClonesArray.h"
#include "TVirtualFitter.h"
//#include "TFitResult.h"
//#include "TFitResultPtr.h"


#include <vector>
#include <cstdlib>
#include <iostream>
#include <list>

//#include "mktreeraw.hxx"
using namespace std;

///////////////////////////////////////////////////////////////////////////////

struct PeakData{
  Int_t mod;
  Int_t n_sample[3];
  Int_t evt[3];
  Double_t pds[3];
  Double_t pdr[3];
  Double_t tls[3];
  Double_t tlo[3];
  Double_t tm[3];
  Double_t am[3];
  Double_t at[3];
  
  Double_t sam[3];	//amplitude
  Double_t sat[3]; //position of maximum - absolute - wrt 0


  Double_t p0[3];
  Double_t p1[3];
  Double_t p2[3];
  Double_t p3[3];
  Double_t p4[3];
  Double_t p5[3];
  Double_t p6[3];
  Double_t p7[3];
  Double_t p8[3];
  Double_t p9[3];
  Double_t p10[3];
  Double_t rc[3];
  Double_t chi2[3];
  Double_t dfadc[3][1024];
PeakData(){
  mod=-1;
  n_sample[0]=n_sample[1]=n_sample[2]=0;
  evt[0]=evt[1]=evt[2]=0;
  pds[0]=pds[1]=pds[2]=0;
  pdr[0]=pdr[1]=pdr[2]=0;
  tls[0]=tls[1]=tls[2]=0;
  tlo[0]=tlo[1]=tlo[2]=0;
  tm[0]=tm[1]=tm[2]=0;
  am[0]=am[1]=am[2]=0;
  at[0]=at[1]=at[2]=0;

  sam[0]=sam[1]=sam[2]=0;
  sat[0]=sat[1]=sat[2]=0;

  p0[0]=p0[1]=p0[2]=0;
  p1[0]=p1[1]=p1[2]=0;
  p2[0]=p2[1]=p2[2]=0;
  p3[0]=p3[1]=p3[2]=0;
  p4[0]=p4[1]=p4[2]=0;
  p5[0]=p5[1]=p5[2]=0;
  p6[0]=p6[1]=p6[2]=0;
  p7[0]=p7[1]=p7[2]=0;
  p8[0]=p8[1]=p8[2]=0;
  p9[0]=p9[1]=p9[2]=0;
  p10[0]=p10[1]=p10[2]=0;
  rc[0]=rc[1]=rc[2]=0;
  chi2[0]=chi2[1]=chi2[2]=0;
  //printf("new PeakData\n");
}
// ~PeakData(){
//  // printf("del PeakData\n");
// }

};


class ASYFadcPeak : public TObject{
public:
  Int_t mod;	//module number [0-34]
  Float_t pds0;	//baseline
  Float_t pdr0;	//baseline rms
  Float_t tls0;	//=tail inv. slope -> from fit of exp(-t/tail+offset) to the tail of the waveform
  Float_t tlo0;	//=tail offset
  Float_t tm0;	//raw time offset, beginning of the pulse (for PD0)
  Float_t am0;	//raw amplitude for PD0
  Float_t at0;	//raw position of maximum

  Float_t pds1;	//baseline
  Float_t pdr1;	//baseline rms
  Float_t tls1;	//=tail inv. slope -> from fit of exp(-t/tail+offset) to the tail of the waveform
  Float_t tlo1;	//=tail offset
  Float_t tm1;	//raw time offset, beginning of the pulse (for PD0)
  Float_t am1;	//raw amplitude for PD0
  Float_t at1;	//raw position of maximum

  Float_t pds2;	//baseline
  Float_t pdr2;	//baseline rms
  Float_t tls2;	//=tail inv. slope -> from fit of exp(-t/tail+offset) to the tail of the waveform
  Float_t tlo2;	//=tail offset
  Float_t tm2;	//raw time offset, beginning of the pulse (for PD0)
  Float_t am2;	//raw amplitude for PD0
  Float_t at2;	//raw position of maximum

//smooth values  
  Float_t sam0;	//amplitude
  Float_t sat0; //position of maximum - absolute - wrt 0

  Float_t sam1;	//amplitude
  Float_t sat1; //position of maximum - absolute - wrt 0

  Float_t sam2;	//amplitude
  Float_t sat2; //position of maximum - absolute - wrt 0


//fit parameters  
  Float_t p00;	//amplitude of Si component in PD0
  Float_t p04;	//time offset (from fit) for PD0
  Float_t p05;	//fall time of Si component in PD0
  Float_t p06;	//undershoot time
  Float_t p09;	//rise time of Si component in PD0
  Float_t rc0;	//rc in PD0
  Float_t p10;	//amplitude of Si component in PD1
  Float_t p12;	//amplitude of Fast CsI(Tl) in PD1 
  Float_t p13;	//amplitude of Slow CsI(Tl) in PD1 
  Float_t p14;	//time offset (from fit) for PD1 
  Float_t p15;	//fall time of Si component in PD1
  Float_t p16;	//undershoot time
  Float_t p17;	//fall time of Fast CsI(Tl) in PD1 
  Float_t p18;	//fall time of Slow CsI(Tl) in PD1 
  Float_t p19;	//rise time of Si component in PD1
  Float_t p110;	//rise time of CsI(Tl) in PD1
  Float_t rc1;	//rc in PD1
  Float_t p20;	//p2* -> same as p1* but for PD2
  Float_t p22;
  Float_t p23;
  Float_t p24;
  Float_t p25;
  Float_t p26;
  Float_t p27;
  Float_t p28;
  Float_t p29;
  Float_t p210;
  Float_t rc2;
  Float_t chi20;//chi2 in PD0
  Float_t chi21;//chi2 in PD1
  Float_t chi22;//chi2 in PD2

  ASYFadcPeak();
  virtual ~ASYFadcPeak(){Clear();}
  void     Clear(Option_t *option="");
  
  ClassDef(ASYFadcPeak,1)  //A peak segment
};

//------------------------------------------------------------------------------


class ASYEvent : public TObject{
public:
  Int_t   run;     // run number
  Int_t   evt;     // event number
  Int_t   npeak;   // multiplicity of peaks
  
  Int_t HADC[32]; //HECTOR ADC
  Int_t HTDC[32]; //HECTOR TDC
  Int_t PADC[32]; //HECTOR ADC
  Int_t PTDC[32]; //HECTOR TDC
  
    
  TClonesArray  *peak;  //->

  ASYEvent();
  virtual ~ASYEvent();
  void     Clear(Option_t* opt="");
// //  ASYFadcPeak*  AddPeak(){return new  ASYFadcPeak();} // Setup Peak
    ASYFadcPeak*  AddPeak(){return new((*peak)[npeak++]) ASYFadcPeak();} // Setup Peak
// // ASYFadcPeak*  AddPeak(){return (ASYFadcPeak*)peak->ConstructedAt(npeak++);} // Setup Peak
  ASYFadcPeak*  Peak(Int_t n) const {return (ASYFadcPeak*)((*peak)[n]);} // Get Peak

//   ASYFadcPeak*  AddPeak();
//   ASYFadcPeak*  Peak(Int_t n); // Get Peak
  
  
  ClassDef(ASYEvent,1)  //Event structure
};

//___________________________________________________________________

Double_t Det(const int n, Double_t  A[9][9]);
Double_t Det2(Double_t A[2][2]);
Double_t Det3(Double_t A[3][3]);
Double_t Det4(Double_t A[4][4]);
//___________________________________________________________________

//double RCGAM8PRIM(Double_t *xx, Double_t *par);
double zbr(double eps,int nsig,double &a,double &b,int &maxfn,int &ier,
double *xx,double *par);
double zbrprim(double eps,int nsig,double &a,double &b,int &maxfn,int &ier,
double *xx,double *par);

//double parab(TH1D *hfit,int b0,int bl,int br,double &a,double &b,double &c);

#endif
