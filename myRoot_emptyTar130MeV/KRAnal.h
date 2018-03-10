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
  float p0_1[20], p1_1[20], p2_1[20];
 float p0_2[20], p1_2[20], p2_2[20];
 float enCsI1, enCsI2;
 
 
 TH2F *hamp01[20];
 TH2F *hamp12[20];
 TH2F *hamp01Cut[20];
 TH2F *hamp12Cut[20];


 TH2F *hp12_p13[20];
 TH2F *hp22_p23[20];
 TH2F *hp10_p12p13[20];
 TH2F *hp10_enProt[20];
 
 TH2F *hp10_p12p13st[20];
 TH2F *hp10_p12p13stCut[20];
 TH2F *hp10_p12p13c[20];
 TH2F *hp20_p22p23[20];
 
 

 TH1F *htm1[20];
 TH1F *hpdr1[20];
 TH1F *hchi21[20];
 TH1F *hpds1[20];


 TH1F *hp22p23[20];
 TH1F *hp22p23c[20];

 TH1F *hp12p13[20];
 TH1F *hp12p13c[20];
 
 TH1F *hen_prot[20];

 TCutG *cutg[16];
 TCutG *cutg1[16];
TCutG *cutg2[16];


 TCutG *fcut1_mod14;
 TCutG *fcut2_mod5;

 TGraph *gr[5];
 TCanvas *c1;

 float p14min[20],p14max[20];
 float p24min[20],p24max[20];


};



R__EXTERN KRAnal *gKRA; // external pointer to KRAnal.

#endif


