//{

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "TBrowser.h"
#include "TPostScript.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraph.h"
#include "TF1.h"
#include "TNamed.h"
#include "TNtuple.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TPaveText.h"
#include "TFrame.h"
#include "TSocket.h"
#include "TServerSocket.h"
#include "TMonitor.h"
#include "TMessage.h"
#include "TMath.h"
#include "TRandom.h"
#include "TList.h"
#include "TApplication.h"
#include "TFile.h"
#include "TBranchElement.h"
#include "TTree.h"
#include "TClass.h"
#include "TChain.h"
#include "TMapFile.h"
#include "TCutG.h"
#include "TKey.h"
#include "TStyle.h"
#include "TROOT.h"
#include <TSystem.h>
#include "string"
#ifndef __CINT__
#include "TError.h"
#include "/home/ciepal/FBRun_CCB/Macros/histos.h"
#include "/home/ciepal/FBRun_CCB/Macros/FBEHits.h"
#include "/home/ciepal/FBRun_CCB/Macros/FBdEHits.h"
#include "/home/ciepal/FBRun_CCB/Macros/NPHit.h"
#include "/home/ciepal/FBRun_CCB/Macros/FBEventHits.h"

#endif
using namespace std;

void can1(int a);
void can2(int a);
void can_sing(int a);
void can_sing_run(void);

int main(){
gSystem->Load("libTree.so");
//gSystem->Load("libEvent");
gStyle->SetOptStat("");
gStyle->SetPalette(1);

char rootfile[300];
//TChain chain("T");
//static int run=0;

//TChain *chain=new TChain("T");
//specADC=new TH1F("", "", 1500, 0, 1500);


 for (int i=0;i<14;i++) {
 hdE19vsE7[i]=new TH2D("","",250,0,1500,250,0,500);

  }

for(int nrfile=1; nrfile<=13;nrfile++)
            {
   if (nrfile<10)sprintf(rootfile,"/home2/CCB/LMD/BINA100%d.lmd.root",nrfile);
   if (nrfile>=10)sprintf(rootfile,"/home2/CCB/LMD/BINA10%d.lmd.root",nrfile);
              TFile f2(rootfile);
              if (f2.IsZombie()) continue;
	      // chain->Add(rootfile);
              //f2.Close();
              cout<<"Add file "<<nrfile<<endl;

               TTree *t1=(TTree*)f2.Get("T");

t1->SetMakeClass(1);
      
//tree=chain;
//cout<<"zzzz"<<endl;
//chain->SetMakeClass(1);


//Event
FullEvent Event; 
unsigned short  fQuartE1, fQuartE2, fQuartdE1, fQuartdE2;
unsigned short fQual1, fQual2,fN, fE1, fE2, fdE1, fdE2,fE1_conv1, fE1_conv2, fdE1_conv, fdE2_conv;
unsigned short  fE2_conv1,fE2_conv2;
Float_t fX1, fX2, fY1, fY2;
 int frunnb;


//splited branches
TBranch *bEvent = t1->GetBranch("Event");

bEvent->SetAddress(&Event);

//sub-branches

//Event
TBranch *bE2 = t1->GetBranch("Event.fE2");
bE2->SetAddress(&fE2);
TBranch *bE1 = t1->GetBranch("Event.fE1");
bE1->SetAddress(&fE1);

TBranch *bdE2 = t1->GetBranch("Event.fdE2");
bdE2->SetAddress(&fdE2);
TBranch *bdE1 = t1->GetBranch("Event.fdE1");
bdE1->SetAddress(&fdE1);

TBranch *bX1 = t1->GetBranch("Event.fX1");
bX1->SetAddress(&fX1);
TBranch *bY1 = t1->GetBranch("Event.fY1");
bY1->SetAddress(&fY1);
TBranch *bX2 = t1->GetBranch("Event.fX2");
bX2->SetAddress(&fX2);
TBranch *bY2 = t1->GetBranch("Event.fY2");
bY2->SetAddress(&fY2);
TBranch *bQual1 = t1->GetBranch("Event.fQual1");
bQual1->SetAddress(&fQual1);
TBranch *bQual2 = t1->GetBranch("Event.fQual2");
bQual2->SetAddress(&fQual2);
TBranch *bE1_conv1 = t1->GetBranch("Event.fE1_conv1");
bE1_conv1->SetAddress(&fE1_conv1);
TBranch *bE1_conv2 = t1->GetBranch("Event.fE1_conv2");
bE1_conv2->SetAddress(&fE1_conv2);
TBranch *bE2_conv1 = t1->GetBranch("Event.fE2_conv1");
bE2_conv1->SetAddress(&fE2_conv1);
TBranch *bE2_conv2 = t1->GetBranch("Event.fE2_conv2");
bE2_conv2->SetAddress(&fE2_conv2);
TBranch *bdE1_conv = t1->GetBranch("Event.fdE1_conv");
bdE1_conv->SetAddress(&fdE1_conv);
TBranch *bdE2_conv = t1->GetBranch("Event.fdE2_conv");
bdE2_conv->SetAddress(&fdE2_conv);

TBranch *bN = t1->GetBranch("Event.fN");
bN->SetAddress(&fN);
TBranch *bQuartE1 = t1->GetBranch("Event.fQuartE1");
bQuartE1->SetAddress(&fQuartE1);
TBranch *bQuartE2 = t1->GetBranch("Event.fQuartE2");
bQuartE2->SetAddress(&fQuartE2);
TBranch *bQuartdE1 = t1->GetBranch("Event.fQuartdE1");
bQuartdE1->SetAddress(&fQuartdE1);
TBranch *bQuartdE2 = t1->GetBranch("Event.fQuartdE2");
bQuartdE2->SetAddress(&fQuartdE2);

TBranch *brunnb = t1->GetBranch("Event.frun_nb");
brunnb->SetAddress(&frunnb);

//cout<<"zzzz"<<endl;
 Long64_t nevent1 = t1->GetEntries();
  cout<< nevent1<<endl;

for( Long64_t i=1; i<nevent1;i++)
{
  //bE->GetEntry(i);
  bEvent->GetEntry(i);
  //chain->GetEntry(i);


 
 if(i%100000==0) cout<<i<<endl;

float fE1_sum, fE2_sum;
// cout<<"  ---  "<<fN<<" "<<fE1_conv1<<" "<<fE1_conv2<<" "<<fE2_conv1<<" "<<fE2_conv2<<endl;
//cout<<fQuartE1<<" fQ:  "<<fQual1<<" "<<fQual2<<endl;
// cout<<fQuartE1<<" "<<fQuartE2<<" "<<fN<<endl;

fE1_sum= sqrt(fE1_conv1*fE1_conv2);
fE2_sum= sqrt(fE2_conv1*fE2_conv2);

  //cout<<fE1_sum<<" "<<fE2_sum<<" "<<fN<<endl;

  //#######################
 //single
 //if (fQual1==1 && fQual2==0&&(fE1_conv1<60000&&fE1_conv2<60000)){
 if (fN==1){ //&& (fE1_conv1<60000&&fE1_conv2<60000)){
   if (fE1_conv1>60000)fE1_sum=fE1_conv2;
   if (fE1_conv2>60000)fE1_sum=fE1_conv1;
   if (fE2_conv1>60000)fE1_sum=fE2_conv2;
   if (fE2_conv2>60000)fE1_sum=fE2_conv1;
   
   // hdEvsE_sing_sum[fdE1][fE1]->Fill(fE1_sum,fdE1_conv);
    //  if (fE2_conv2>30000)cout<<"  ---  "<<fN<<" "<<fE1_conv1<<" "<<fE1_conv2<<" "<<fE2_conv1<<" "<<fE2_conv2<<" "<<fdE1_conv<<" "<<fdE2_conv<<endl;
   // if (fdE1==18 && fE1==6) hdE19vsE7[frunnb]->Fill(fE1_sum,fdE1_conv);
   //  if (fdE1==18 && fE1==8) hdE19vsE7[frunnb]->Fill(fE1_sum,fdE1_conv);
if (fdE1==5 && fE1==3) hdE19vsE7[frunnb]->Fill(fE1_sum,fdE1_conv);



 }




 }////
 
  
	    }

    
// can1(run);
//can2(run);
can_sing_run();
}


//sprintf(qf_lab,"#theta=%d^{0}#pm1^{0}",k);
//pt= new TPaveText(x1, y1, x2, y2,"NDC");
//pt.SetFillColor(0);
//pt.AddText(qf_lab);
//pt.SetBorderSize(0);
//pt.SetTextSize(0.06);
//pt.SetTextColor(2);
//pt.Draw();
//###########################################
void can_sing(int run){
float x1=0.55, y1=0.71, x2=0.85, y2=0.82;
TPaveText *pt;
TCanvas *c11, *c21, *c31, *c41;
char aa[200], ab[200], ac[200];
sprintf(ab,"dE_E_hodoscops_sing_run%d.root",run);

TFile *histfile = new TFile(ab,"recreate");


sprintf(ac,"dEvsE_sing_Quater4_run%d",run);
c11 = new TCanvas(ac,ac);
c11->SetFillColor(10);
c11->Divide(6,5);


 int k=0;
for (int i=4;i>=0;i--){
for (int j=5;j>=0;j--){
  k++;
c11->cd(k);
gPad->SetFillColor(10);
gPad->SetLogz();
hdEvsE_sing_sum[j][i]->GetXaxis()->SetTitle("#sqrt(PM1*PM2)");
//hdEvsE_sum1_cor[j][i]->GetXaxis()->SetTitleSize(0.05);
hdEvsE_sing_sum[j][i]->GetXaxis()->SetTitleColor(9);
hdEvsE_sing_sum[j][i]->GetXaxis()->CenterTitle();
hdEvsE_sing_sum[j][i]->GetYaxis()->SetTitle("#Delta E [channel]");
//hdEvsE_sum1_cor[j][i]->GetYaxis()->SetTitleSize(0.05);
hdEvsE_sing_sum[j][i]->GetYaxis()->SetTitleColor(9);
hdEvsE_sing_sum[j][i]->GetYaxis()->CenterTitle();
hdEvsE_sing_sum[j][i]->Draw("colz");


 sprintf(aa,"dE=%d,E=%d",j+1,i+1);
pt= new TPaveText(x1, y1, x2, y2,"NDC");
pt->SetFillColor(0);
pt->AddText(aa);
pt->SetBorderSize(0);
pt->SetTextSize(0.08);
pt->SetTextColor(2);
pt->Draw();
 }
 }
 
//#############################
sprintf(ac,"dEvsE_sing_Quater3_run%d",run);
c21 = new TCanvas(ac,ac);
c21->SetFillColor(10);
c21->Divide(6,5);

int k1=0;
for (int i=4;i>=0;i--){
for (int j=11;j>=6;j--){
  k1++;
c21->cd(k1);
gPad->SetFillColor(10);
gPad->SetLogz();
hdEvsE_sing_sum[j][i]->GetXaxis()->SetTitle("#sqrt(PM1*PM2)");
//hdEvsE_sum1_cor[j][i]->GetXaxis()->SetTitleSize(0.05);
hdEvsE_sing_sum[j][i]->GetXaxis()->SetTitleColor(9);
hdEvsE_sing_sum[j][i]->GetXaxis()->CenterTitle();
hdEvsE_sing_sum[j][i]->GetYaxis()->SetTitle("#Delta E [channel]");
//hdEvsE_sum1_cor[j][i]->GetYaxis()->SetTitleSize(0.05);
hdEvsE_sing_sum[j][i]->GetYaxis()->SetTitleColor(9);
hdEvsE_sing_sum[j][i]->GetYaxis()->CenterTitle();
hdEvsE_sing_sum[j][i]->Draw("colz");


sprintf(aa,"dE=%d,E=%d",j+1,i+1);
pt= new TPaveText(x1, y1, x2, y2,"NDC");
pt->SetFillColor(0);
pt->AddText(aa);
pt->SetBorderSize(0);
pt->SetTextSize(0.08);
pt->SetTextColor(2);
pt->Draw();
 }
 }

//################
sprintf(ac,"dEvsE_sing_Quater1_run%d",run);
c31 = new TCanvas(ac,ac);
c31->SetFillColor(10);
c31->Divide(6,5);

int k2=0;
for (int i=9;i>=5;i--){
for (int j=17;j>=12;j--){
  k2++;
c31->cd(k2);
gPad->SetFillColor(10);
gPad->SetLogz();
hdEvsE_sing_sum[j][i]->GetXaxis()->SetTitle("#sqrt(PM1*PM2)");
//hdEvsE_sum1_cor[j][i]->GetXaxis()->SetTitleSize(0.05);
hdEvsE_sing_sum[j][i]->GetXaxis()->SetTitleColor(9);
hdEvsE_sing_sum[j][i]->GetXaxis()->CenterTitle();
hdEvsE_sing_sum[j][i]->GetYaxis()->SetTitle("#Delta E [channel]");
//hdEvsE_sum1_cor[j][i]->GetYaxis()->SetTitleSize(0.05);
hdEvsE_sing_sum[j][i]->GetYaxis()->SetTitleColor(9);
hdEvsE_sing_sum[j][i]->GetYaxis()->CenterTitle();
hdEvsE_sing_sum[j][i]->Draw("colz");


sprintf(aa,"dE=%d,E=%d",j+1,i+1);
pt= new TPaveText(x1, y1, x2, y2,"NDC");
pt->SetFillColor(0);
pt->AddText(aa);
pt->SetBorderSize(0);
pt->SetTextSize(0.08);
pt->SetTextColor(2);
pt->Draw();
 }
 }
//################
sprintf(ac,"dEvsE_sing_Quater2_run%d",run);
c41 = new TCanvas(ac,ac);
c41->SetFillColor(10);
c41->Divide(6,5);

int k3=0;
for (int i=9;i>=5;i--){
for (int j=23;j>=18;j--){
  k3++;
c41->cd(k3);
gPad->SetFillColor(10);
gPad->SetLogz();
hdEvsE_sing_sum[j][i]->GetXaxis()->SetTitle("#sqrt(PM1*PM2)");
//hdEvsE_sum1_cor[j][i]->GetXaxis()->SetTitleSize(0.05);
hdEvsE_sing_sum[j][i]->GetXaxis()->SetTitleColor(9);
hdEvsE_sing_sum[j][i]->GetXaxis()->CenterTitle();
hdEvsE_sing_sum[j][i]->GetYaxis()->SetTitle("#Delta E [channel]");
//hdEvsE_sum1_cor[j][i]->GetYaxis()->SetTitleSize(0.05);
hdEvsE_sing_sum[j][i]->GetYaxis()->SetTitleColor(9);
hdEvsE_sing_sum[j][i]->GetYaxis()->CenterTitle();
hdEvsE_sing_sum[j][i]->Draw("colz");


sprintf(aa,"dE=%d,E=%d",j+1,i+1);
pt= new TPaveText(x1, y1, x2, y2,"NDC");
pt->SetFillColor(0);
pt->AddText(aa);
pt->SetBorderSize(0);
pt->SetTextSize(0.08);
pt->SetTextColor(2);
pt->Draw();
 }
 }


c11->Write();c21->Write();c31->Write();c41->Write();

histfile->Write();
histfile->Close();
}

//####################################

void can_sing_run(void){
  //float x1=0.55, y1=0.71, x2=0.85, y2=0.82;
float x1=0.55, y1=0.78, x2=0.85, y2=0.89;
TPaveText *pt;
TCanvas *c11, *c21, *c31, *c41;
 char aa[200], ab[200], ac[200], ad1[200], ad2[200], ad3[200];
sprintf(ab,"dE_E_sing.root");

TFile *histfile = new TFile(ab,"recreate");


sprintf(ac,"dEvsE_sing");
c11 = new TCanvas(ac,ac);
c11->SetFillColor(10);
c11->Divide(5,3);

for (int i=1;i<14;i++){
c11->cd(i);
gPad->SetFillColor(10);
gPad->SetLogz();
hdE19vsE7[i]->GetXaxis()->SetTitle("#sqrt{PM1*PM2}");
hdE19vsE7[i]->GetXaxis()->SetTitleSize(0.05);
//hdE19vsE7[i]->GetXaxis()->SetTitleColor(9);
hdE19vsE7[i]->GetXaxis()->CenterTitle();
hdE19vsE7[i]->GetYaxis()->SetTitle("#Delta E [channel]");
hdE19vsE7[i]->GetYaxis()->SetTitleSize(0.05);
//hdE19vsE7[i]->GetYaxis()->SetTitleColor(9);
hdE19vsE7[i]->GetYaxis()->CenterTitle();
hdE19vsE7[i]->Draw("colz");


sprintf(aa,"RUN %d",i);
pt= new TPaveText(x1, y1, x2, y2,"NDC");
pt->SetFillColor(0);
pt->AddText(aa);
pt->SetBorderSize(0);
pt->SetTextSize(0.09);
pt->SetTextColor(2);
pt->Draw();


 }
 
//#############################



 c11->Write();//c21->Write();c31->Write();c41->Write();

histfile->Write();
histfile->Close();
}



