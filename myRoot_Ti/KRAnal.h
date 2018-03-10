#ifndef KRAnal_h
#define KRAnal_h
#include "mktreedstchain_sct_fitABC.hxx"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TEventList.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include "TCanvas.h"
#include "ClassName.h"
#include "utility.h"
#include "TLorentzVector.h"
#include "TCutG.h"


class KRAnal: public InheritClass {

  TFile *theOut;
  Char_t theOutFileName[64];
  Bool_t WriteTree;
  Int_t Pen;
  TFile *f;
  
  Int_t OpenGeometry(); // Gets the geometry information
  void CreateHistos();
  void WriteHistos();
  //void WriteTGraphs();
  

 public:
  KRAnal(TTree *tree=0);
  ~KRAnal();
  void   Init();
  void   Loop(Char_t *file);
  Int_t  ReadLine(FILE *fID, char *line);
  void SetWriteTree(Bool_t f) {WriteTree = f;}
  void SetEnergy(int en) {Pen = en;}

  float a0_1,a1_1,a2_1,tls0_1,p14_1,p04_1,p24_1;
  float p10_1,p12_1,p13_1,p20_1,p22_1,p23_1;
  int mod_1,evnb;
 
 TH2F *hamp01[20];
 TH2F *hamp01a[20];

 TH2F *hamp12[20];
 TH2F *hamp12a[20];

 TH2F *hp14_p24[20];

 TH2F *hp12_p13[20];
 TH2F *hp12_p13a[20];
 TH2F *hp12_p13b[20];
 TH2F *hp12_p13c12[20];
 TH2F *hp12_p13ac12[20];
 TH2F *hp12_p13bc12[20];

 TH2F *hp10_p12p13[20];
 TH2F *hp10_p12p13c[20];

 TH2F *hp22_p23[20];
 TH2F *hp22_p23a[20];
 TH2F *hp22_p23b[20];
 TH2F *hp22_p23c12[20];
 TH2F *hp22_p23ac12[20];
 TH2F *hp22_p23bc12[20];

 TH2F *htmaxt0_vs_tls2[20];
 TH2F *hrc_vs_chi2[20];

 TH1F *hrc00[20];
 TH1F *htls00[20];
 TH1F *hrc0[20];
 TH1F *htls0[20];

 TH1F *hrc10[20];
 TH1F *htls10[20];
 TH1F *hrc1[20];
 TH1F *htls1[20];
 TH1F *hrc2[20];
 TH1F *htls2[20];

 TH1F *hpds0[20];
 TH1F *hpds1[20];
 TH1F *hpds2[20];

 TH1F *hpdr0[20];
 TH1F *hpdr1[20];
 TH1F *hpdr2[20];
 
 TH2F *htls2_vs_chi2[20];
 TH2F *htmaxt0_vs_chi2[20];
 TH2F *hpds0_vs_pdr0[20],*hpds1_vs_pdr1[20],*hpds2_vs_pdr2[20];



 TCutG *cutg[16];
 TCutG *fcut1_mod14;
 TCutG *fcut2_mod5;

 TGraph *gr[5];
 TCanvas *c1;

 float p14min[20],p14max[20];
 float p24min[20],p24max[20];


};



R__EXTERN KRAnal *gKRA; // external pointer to KRAnal.

#endif


