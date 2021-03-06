#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iomanip>
#include "TBrowser.h"
#include "TPostScript.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TF1.h"
#include "TNtuple.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TSocket.h"
#include "TServerSocket.h"
#include "TMonitor.h"
#include "TMessage.h"
#include "TMath.h"
#include "TRandom.h"
#include "TList.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TMapFile.h"
#include "TCutG.h"
#include "TKey.h"
#include <TSystem.h>
#include "string"
#ifndef __CINT__
#include "TError.h"
#endif
using namespace std;
//#include "write_bin8.h"

int main()
{
  //gROOT->Reset();
Double_t pi=TMath::Pi();

 Int_t  evnb_1;
 Int_t   mod_1;
 Float_t tls0_1, tm1_1, tm2_1, a0_1, a1_1, a2_1, p04_1, p14_1, p24_1, p10_1, p12_1, p13_1, p20_1, p22_1, p23_1, enCsI1_1, enCsI2_1,  en_1;
 Int_t  evnb_2,  mod_2;
 Float_t tls0_2, tm1_2, tm2_2, a0_2, a1_2, a2_2, p04_2, p14_2, p24_2, p10_2, p12_2, p13_2, p20_2, p22_2, p23_2, enCsI1_2, enCsI2_2, en_2;

 int licznik=0;
 TH2F *htm1tm2_1, *htm1tm2_2;
 TH2F *htm1Ltm1R, *htm2Ltm2R;
 TH2F *henLenR, *henLenRcut,*hp14Lp14R;


htm1tm2_1 = new TH2F("tm1tm2_1","tm1tm2_1",100,100,300,100,100,300);
htm1tm2_2 = new TH2F("tm1tm2_2","tm1tm2_2",100,100,300,100,100,300);

htm1Ltm1R = new TH2F("tm1Ltm1R","tm1Ltm1R",100,0,300,100,0,300);
htm2Ltm2R = new TH2F("tm1Ltm1R","tm1Ltm1R",100,0,300,100,0,300);
hp14Lp14R = new TH2F("p14Lp14R","p14Lp14R",100,0,300,100,0,300);

henLenR = new TH2F("enLenR","enLenR",100,0,300,100,0,300);
henLenRcut = new TH2F("enLenRcut","enLenRcut",100,0,300,100,0,300);





 TChain fChain("TT");

 TFile f2("/home/ciepal/Main/KRATTA/spall-2017-06/myRoot_C230MeV/KRAnal.root");
 if (f2.IsZombie()) cout<<"no file"<<endl;;
 fChain.Add("/home/ciepal/Main/KRATTA/spall-2017-06/myRoot_C230MeV/KRAnal.root");
 f2.Close();
              

   fChain.SetBranchAddress("evnb_1", &evnb_1);
   fChain.SetBranchAddress("mod_1", &mod_1);
   fChain.SetBranchAddress("tls0_1", &tls0_1);
   fChain.SetBranchAddress("tm1_1", &tm1_1);
   fChain.SetBranchAddress("tm2_1", &tm2_1);
   fChain.SetBranchAddress("a0_1", &a0_1);
   fChain.SetBranchAddress("a1_1", &a1_1);
   fChain.SetBranchAddress("a2_1", &a2_1);
   fChain.SetBranchAddress("p04_1", &p04_1);
   fChain.SetBranchAddress("p14_1", &p14_1);
   fChain.SetBranchAddress("p24_1", &p24_1);
   fChain.SetBranchAddress("p10_1", &p10_1);
   fChain.SetBranchAddress("p12_1", &p12_1);
   fChain.SetBranchAddress("p13_1", &p13_1);
   fChain.SetBranchAddress("p20_1", &p20_1);
   fChain.SetBranchAddress("p22_1", &p22_1);
   fChain.SetBranchAddress("p23_1", &p23_1);
   fChain.SetBranchAddress("enCsI1_1", &enCsI1_1);
   fChain.SetBranchAddress("enCsI2_1", &enCsI2_1);
   fChain.SetBranchAddress("en_1", &en_1);

   fChain.SetBranchAddress("evnb_2", &evnb_2);
   fChain.SetBranchAddress("mod_2", &mod_2);
   fChain.SetBranchAddress("tls0_2", &tls0_2);
   fChain.SetBranchAddress("tm1_2", &tm1_2);
   fChain.SetBranchAddress("tm2_2", &tm2_2);
   fChain.SetBranchAddress("a0_2", &a0_2);
   fChain.SetBranchAddress("a1_2", &a1_2);
   fChain.SetBranchAddress("a2_2", &a2_2);
   fChain.SetBranchAddress("p04_2", &p04_2);
   fChain.SetBranchAddress("p14_2", &p14_2);
   fChain.SetBranchAddress("p24_2", &p24_2);
   fChain.SetBranchAddress("p10_2", &p10_2);
   fChain.SetBranchAddress("p12_2", &p12_2);
   fChain.SetBranchAddress("p13_2", &p13_2);
   fChain.SetBranchAddress("p20_2", &p20_2);
   fChain.SetBranchAddress("p22_2", &p22_2);
   fChain.SetBranchAddress("p23_2", &p23_2);
   fChain.SetBranchAddress("enCsI1_2", &enCsI1_2);
   fChain.SetBranchAddress("enCsI2_2", &enCsI2_2);
   fChain.SetBranchAddress("en_2", &en_2);

    
   int nevent1 = fChain.GetEntries();
     
   for(int i=1; i<nevent1;i++)
     {
  
       fChain.GetEvent(i);

       if(!(licznik%1000000)) cout<<licznik<<endl;
       licznik++;
       cout<<evnb_1<<" "<<evnb_2<<endl;
       //if (tm1_1)cout<<tm1_1<<endl;

       if (tm1_1)htm1tm2_1->Fill(tm2_1,tm1_1); 
       if (tm1_2)htm1tm2_2->Fill(tm2_2,tm1_2);
       htm1Ltm1R->Fill(tm1_1,tm1_2);
       htm2Ltm2R->Fill(tm2_1,tm2_2);
     
hp14Lp14R->Fill(p14_1,p14_2);
//htm2Ltm2R->Fill(tm2_1,tm2_2);
  henLenR->Fill(en_1,en_2);




     }

   TCanvas *c1 = new TCanvas("h","h");
   c1->Divide(3,2);

   c1->cd(1);
   htm1tm2_1->Draw("col");

   c1->cd(2);
   htm1tm2_2->Draw("col");

   c1->cd(3);
   htm1Ltm1R->Draw("col");

   c1->cd(4);
   htm2Ltm2R->Draw("col");
   c1->cd(5);
   hp14Lp14R->Draw("col");
c1->cd(6);
henLenR->Draw("col");

   c1->SaveAs("test.root");


}



