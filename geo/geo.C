#ifndef __CINT__

#include <math.h>

#include "TBox.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TNtuple.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TSystem.h"
#include "TTree.h"
#include "TVector3.h"
#include "TClonesArray.h"
#include "TSystem.h"

#endif
#include "TBox.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TPaveLabel.h"
#include "TROOT.h"

#include "geo.hxx"

///////////////////////////////////////////////////////////////////////////////

ClassImp(ASYsignal)
ASYsignal::ASYsignal() 
{
  number=-1;
  module=-1;
  fadc_mod=-1;
  fadc_chn=-1;
  ok=0;
  theta=-1;
  phi=-1;
  thick=-1;
  tbin=-1;
  slab="";
}
ASYsignal::~ASYsignal(){}

///////////////////////////////////////////////////////////////////////////////

ClassImp(ASYgeo)
ASYgeo::ASYgeo() 
{
  tca_signal=0;      
  nfadc_mod=-1;
  min_fadc_mod=0;
  max_fadc_mod=0;
  nmodule=0;
  nsignal=-1;
  signalpermod=0;
  gain_fct=0;
}
ASYgeo::~ASYgeo(){
  delete tca_signal; 
  tca_signal = 0;
  delete[] signalpermod;
  delete[] gain_fct;
  signalpermod=0;
  gain_fct=0;
}


void ASYgeo::ReadGeo(const char *dat_file){
if(!dat_file) dat_file = Form("%s/geo/geo_map.geo",gSystem->ExpandPathName("$S394WRK"));
printf("GEO using: %s\n",dat_file);

char CH;
string dummy;



ifstream par_file(dat_file);
if(par_file.bad()){
  printf("cannot open file %s\n",dat_file);
  return;
}

// first scan file.geo to get the number of modules

nfadc_mod=0;
min_fadc_mod =  10000;
max_fadc_mod = -10000;
Int_t ifadc_mod, ifadc_chn, imodule, isignal, iok;
Int_t ifadc_mod0=-1, ifadc_chn0;
Int_t imodule0=-1, isignal0=-1;
string slab;
const int maxmod = 100;
int amod[maxmod]={0};
while(par_file >> CH){
if(CH=='#' || CH=='>'){
  getline(par_file,dummy);
  //printf("%s\n",(char*)dummy.c_str());
  continue;
}
else{
  par_file.putback(CH);
}
par_file >> ifadc_mod >> ifadc_chn >> imodule >> isignal >> iok >> slab; 
getline(par_file,dummy);

if(ifadc_mod>max_fadc_mod) max_fadc_mod = ifadc_mod;
if(ifadc_mod<min_fadc_mod) min_fadc_mod = ifadc_mod;

if(imodule > -1 && imodule<maxmod){
  if(amod[imodule]==0) nmodule++;
  amod[imodule]++;
}
else if(imodule<-1 || imodule>=maxmod){
  printf("geo:: -> BAD MODULE NUMBER\n");
  exit(1);
}

if(ifadc_mod != ifadc_mod0){
  ifadc_mod0=ifadc_mod;
  nfadc_mod++;
}
printf("%2d %2d %2d %2d %2d >>%s<< %s\n",ifadc_mod, ifadc_chn, imodule, isignal, 
iok,(char*)slab.c_str(),(char*)dummy.c_str());
}

printf("nfadc_mod %d\n",nfadc_mod);
printf("nmodule   %d\n",nmodule);
printf("min_fadc_mod   %d\n",min_fadc_mod);
printf("max_fadc_mod   %d\n",max_fadc_mod);

signalpermod = new Int_t[nmodule];
for(int i=0;i<nmodule;i++){
  signalpermod[i]=0;
} 
par_file.clear(); // forget we hit the end of file
par_file.seekg(0, ios::beg); // rewind

// second scan to get the signalpermod
Int_t isigmod=-1;
imodule0=-1;
isignal0=-1;
nsignal=0;
while(par_file >> CH){
if(CH=='#' || CH=='>'){
  getline(par_file,dummy);
  //printf("%s\n",(char*)dummy.c_str());
  continue;
}
else{
  par_file.putback(CH);
}
par_file >> ifadc_mod >> ifadc_chn >> imodule >> isignal >> iok >> slab; 
getline(par_file,dummy);
if(imodule != -1){
signalpermod[imodule]++;
//printf("%2d %2d %2d %2d\n",ifadc_mod, ifadc_chn, imodule, isignal,iok);
nsignal++;

}
}

for(int i=0;i<nmodule;i++){
  printf(">> mod %2d sig %2d\n",i, signalpermod[i]);
}




printf("nsignal %d\n",nsignal);
tca_signal = new TClonesArray("ASYsignal",nsignal);

par_file.clear(); // forget we hit the end of file
par_file.seekg(0, ios::beg); // rewind
// third scan to get the data

imodule0=-1;
isignal0=-1;

ASYsignal *fsignal = 0;

Int_t smod;
Float_t stheta;
Float_t sphi;
Float_t slen;
Float_t sthick;
Float_t tbin;

//size_t ipos = string::npos;
Int_t isig=0;
while(par_file >> CH){
if(CH=='#' || CH=='>'){
  getline(par_file,dummy);
//  printf("%s\n",(char*)dummy.c_str());
  continue;
}
else{
  par_file.putback(CH);
}
par_file >> ifadc_mod >> ifadc_chn >> imodule >> isignal >> iok >> slab; 
getline(par_file,dummy);


if(imodule != -1){

bool nosignal=true;
for(int i=0;i<isig;i++){ // check whether signal already exists
  if(GetModuleNo(i)==imodule &&
     GetSignalNo(i)==isignal){
    nosignal=false;
    printf("!!!!!!! module/signal %d %d already exists\n",imodule,isignal);
    printf("!!!!!!! correct %s\n",dat_file);
    exit(1);
  }
}
for(int i=0;i<isig;i++){ // check whether signal already exists
  if(GetFadcModuleNo(i)==ifadc_mod &&
     GetFadcChannelNo(i)==ifadc_chn){
    nosignal=false;
    printf("!!!!!!! fadc channel %d %d already exists\n",ifadc_mod,ifadc_chn);
    printf("!!!!!!! correct %s\n",dat_file);
    exit(1);
  }
}


fsignal = NewSignal(isig);
fsignal->fadc_mod  = ifadc_mod;
fsignal->module    = imodule;
fsignal->fadc_chn  = ifadc_chn;
fsignal->number    = isignal;
fsignal->ok        = iok;
fsignal->slab      = slab;


fsignal->theta = 0; //theta
fsignal->phi   = 0; // phi
fsignal->thick = 0; // thick

fsignal->tbin      = 10;

isig++;


}
}
par_file.close();

printf("\n");
printf("MODULES %d | FADC MODULES %d | SIGNALS %d\n",nmodule,nfadc_mod,nsignal);
printf("\n");
//printf("%d\n",qq);


// test
// for(int i=0;i<nsignal;i++){
//   printf("indx %d chamb %d mod %d\n",i,GetModuleNo(i),GetFadcModuleNo(i));
//   int indx = GetIndexFromChannel(GetModuleNo(i),GetFadcModuleNo(i),GetFadcChannelNo(i));
//   printf("chan %d indx %d signal %d\n",GetModuleNo(i),
//   indx,GetSignalNo(indx));
// }

// for(int ic=0;ic<nfadc_mod;ic++){
// for(int i=0;i<nfadc_mod;i++){
//   for(int i1=0;i1<8;i1++){
//     printf("chamb %d mod %d chan %d signal %d\n",ic,i,i1,GetSignal(ic,i,i1));
//   }
// }
// }

ListChannels();

// test


}
///////////////////////////////////////////////////////////////////////////////

void ASYgeo::LoadParRCGAM8SI(const int irun, const char *dat_file){
if(!dat_file) dat_file = Form("%s/geo/parRCGAM8SI.dat",gSystem->ExpandPathName("$S394WRK"));
printf("GEO using: %s\n",dat_file);

char CH;
string dummy;



ifstream par_file(dat_file);
if(par_file.bad()){
  printf("cannot open file %s\n",dat_file);
  return;
}


Int_t run_min, run_max;

int lp;
while(par_file >> CH){
if(CH=='#' || CH=='>'){
  getline(par_file,dummy);
  //printf("%s\n",(char*)dummy.c_str());
  continue;
}
else{
  par_file.putback(CH);
  break;
}
}
while(par_file >> run_min >> run_max){
for(int i=0;i<35;i++){
  par_file >> lp
           >> P4[i][0] >> P4[i][1] >> P4[i][2]
           >> P5[i][0] >> P5[i][1] >> P5[i][2]
           >> P6[i][0] >> P6[i][1] >> P6[i][2]
           >> P7[i][0] >> P7[i][1] >> P7[i][2];
}
if(irun==0 || (irun>=run_min && irun<=run_max)){
  par_file.close();
  return;
}
}


}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void ASYgeo::LoadParRCGAM10SI(const int irun, const char *dat_file){
if(!dat_file) dat_file = Form("%s/geo/parRCGAM10SI.dat",gSystem->ExpandPathName("$S394WRK"));
printf("GEO using: %s\n",dat_file);

char CH;
string dummy;



ifstream par_file(dat_file);
if(par_file.bad()){
  printf("cannot open file %s\n",dat_file);
  return;
}


Int_t run_min, run_max;

int lp;
while(par_file >> CH){
if(CH=='#' || CH=='>'){
  getline(par_file,dummy);
  //printf("%s\n",(char*)dummy.c_str());
  continue;
}
else{
  par_file.putback(CH);
  break;
}
}
while(par_file >> run_min >> run_max){
for(int i=0;i<35;i++){
  par_file >> lp
           >> P4[i][0] >> P4[i][1] >> P4[i][2]
           >> P5[i][0] >> P5[i][1] >> P5[i][2]
           >> P6[i][0] >> P6[i][1] >> P6[i][2]
           >> P7[i][0] >> P7[i][1] >> P7[i][2]
           >> P8[i][0] >> P8[i][1] >> P8[i][2]
           >> P9[i][0] >> P9[i][1] >> P9[i][2];
}
if(irun==0 || (irun>=run_min && irun<=run_max)){
  par_file.close();
  return;
}
}


}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void ASYgeo::LoadParRC3GAM2DEXP13(const int irun, const char *dat_file){
if(!dat_file) dat_file = Form("%s/geo/parRC3GAM2DEXP13.dat",gSystem->ExpandPathName("$S394WRK"));
printf("GEO using: %s\n",dat_file);

char CH;
string dummy;



ifstream par_file(dat_file);
if(par_file.bad()){
  printf("cannot open file %s\n",dat_file);
  return;
}


Int_t run_min, run_max;

int lp;
while(par_file >> CH){
if(CH=='#' || CH=='>'){
  getline(par_file,dummy);
  //printf("%s\n",(char*)dummy.c_str());
  continue;
}
else{
  par_file.putback(CH);
  break;
}
}
while(par_file >> run_min >> run_max){
for(int i=0;i<35;i++){
  par_file >> lp
           >> P4[i][0] >> P4[i][1] >> P4[i][2]  //tau Si
           >> P5[i][0] >> P5[i][1] >> P5[i][2]
           >> P6[i][0] >> P6[i][1] >> P6[i][2]
           >> P7[i][0] >> P7[i][1] >> P7[i][2]  //RC
           >> P8[i][0] >> P8[i][1] >> P8[i][2]  //CsI  fast decay
           >> P9[i][0] >> P9[i][1] >> P9[i][2] //CsI slow decay
           >> P10[i][0] >> P10[i][1] >> P10[i][2]; //CsI risetime
}
if(irun==0 || (irun>=run_min && irun<=run_max)){
  par_file.close();
  return;
}
}


}

///////////////////////////////////////////////////////////////////////////////

// 
// void ASYgeo::ReadGainFactors(Int_t irun, const char *dat_file){
// char CH;
// string dummy;
// Int_t irun0=0;
// 
// if(nfadc_mod<1){
//   printf("Call ReadGeo first (no nfadc_mod)\n");
//   return;
// }
// 
// gain_fct = new Float_t[nsignal];
// for(int i=0;i<nsignal;i++) gain_fct[i]=1.f;
// 
// ifstream par_file(dat_file);
// if(par_file.bad()){
//   printf("cannot open file %s\n",dat_file);
//   printf("gain factors = 1\n");
//   return;
// }
// 
// bool run_found=false;
// 
// while(par_file >> CH){
// if(CH=='#' || CH=='>'){
//   getline(par_file,dummy);
//   //printf("%s\n",(char*)dummy.c_str());
//   continue;
// }
// else{
//   par_file.putback(CH);
// }
// par_file >> irun0; 
// for(int i=0;i<nfadc_mod;i++){
//   par_file >> gain_fct[i];
// }
// if(irun0==irun){
//   run_found=true;
//   break;
// }
// }
// 
// if(!run_found){
//   printf("NO GainFactors for run %d\n",irun);
//   for(int i=0;i<nfadc_mod;i++) gain_fct[i]=1.f;
// } 
// 
// printf("ReadGainFactors: run %d",irun);
// for(int i=0;i<nfadc_mod;i++){
//   printf(" %6.3f ",gain_fct[i]);
// }
// printf("\n");
// 
// par_file.close();
// 
// 
// }

///////////////////////////////////////////////////////////////////////////////

// Int_t ASYgeo::GetSignal(Int_t indx, Int_t imodule){
// int signal = -1;
// if(indx>=0 && indx<nfadc_mod && imodule>=0 && imodule<8){
//   signal = fadc_mod(indx)->signal[imodule];
// }
// return signal;
// }



///////////////////////////////////////////////////////////////////////////////

Int_t ASYgeo::GetIndexFromFadc(Int_t ifadcmod, Int_t ifadcchan){
Int_t index = -1;
for(int i=0;i<nsignal;i++){
  Int_t ifadc_mod1  = GetFadcModuleNo(i);
  Int_t ifadc_chn1  = GetFadcChannelNo(i);
  if(ifadc_chn1==ifadcchan && ifadc_mod1==ifadcmod){
    index = i;
    break;
  }
}
return index;
}

///////////////////////////////////////////////////////////////////////////////

Int_t ASYgeo::GetIndexFromSignal(Int_t imodule,Int_t isignal){
Int_t index = -1;
for(int i=0;i<nsignal;i++){
  Int_t imodule1  = GetModuleNo(i);
  Int_t isignal1  = GetSignalNo(i);
  if(isignal1==isignal && imodule1==imodule){
    index = i;
    break;
  }
}
return index;
}

///////////////////////////////////////////////////////////////////////////////

void ASYgeo::ListChannels(){
for(int i=0;i<nsignal;i++){
  int indx = GetIndexFromFadc(GetFadcModuleNo(i),GetFadcChannelNo(i));
  ASYsignal*  signal = Signal(indx);
  printf("indx %3d %3d fm %2d fc %2d mo %2d si %1d %1d %s %6.3f %6.3f %4.1f %7.1f\n",
  i,indx,
  GetFadcModuleNo(i),
  GetFadcChannelNo(i),
  GetModuleNo(i),
  GetSignalNo(i),
  GetSignalOK(i),
  (char*)signal->slab.c_str(),
  signal->theta,
  signal->phi,
  signal->thick,
  signal->tbin
  );
}
return;
}

///////////////////////////////////////////////////////////////////////////////
// 
// void ASYgeo::DrawSetup(){
// float xmin = 1.e10;
// float xmax = -1.e10;
// float zmin = 1.e10;
// float zmax = -1.e10;
// for(int i=0;i<nsignal;i++){
//   int indx = GetIndexFromChannel(GetFadcModuleNo(i),GetFadcChannelNo(i));
//   ASYsignal*  signal = Signal(indx);
//   if(signal->ok){
//     if(signal->x-0.5*signal->width<xmin)  xmin=signal->x-0.5*signal->width;
//     if(signal->x+0.5*signal->width>xmax)  xmax=signal->x+0.5*signal->width;
//     if(signal->z-0.5*signal->thick<zmin) zmin=signal->z-0.5*signal->thick;
//     if(signal->z+0.5*signal->thick>zmax) zmax=signal->z+0.5*signal->thick;
//   }
// }
// 
// float dx = xmax-xmin;
// float dz = zmax-zmin;
// //printf("%f %f %f %f    %f %f\n",xmin,xmax,zmin,zmax,dx,dz);
// xmin = xmin-0.05*dx;
// xmax = xmax+0.05*dx;
// zmin = zmin-0.05*dz;
// zmax = zmax+0.15*dz;
// //printf("%f %f %f %f\n",xmin,xmax,zmin,zmax);
// 
// 
// if ((TCanvas*)gROOT->GetListOfCanvases()->FindObject("csignals")){
//   csignals->cd();
//   csignals->Clear();
// }
// else {
//   csignals = new TCanvas("csignals","csignals",0,600,600,500);
//   csignals->SetRightMargin(0.05);
//   csignals->SetLeftMargin(0.12);
// }
// csignals->Draw();
// snullx = new TH1F("snullx","snullx",100,xmin,xmax);
// snullx->SetMinimum(zmin);
// snullx->SetMaximum(zmax);
// snullx->GetXaxis()->SetTitle("x [mm]");
// snullx->GetYaxis()->SetTitle("z [mm]");
// snullx->GetYaxis()->SetTitleOffset(1.4);
// snullx->GetYaxis()->CenterTitle();
// snullx->GetXaxis()->CenterTitle();
// snullx->Draw();
// //TBox *tbox = new TBox();
// for(int i=0;i<nsignal;i++){
//   int indx = GetIndexFromChannel(GetFadcModuleNo(i),GetFadcChannelNo(i));
//   ASYsignal*  signal = Signal(indx);
//   if(signal->ok){
//     Double_t x1 = signal->x-0.5*signal->width;
//     Double_t x2 = signal->x+0.5*signal->width;
//     Double_t y1 = signal->z-0.5*signal->thick;
//     Double_t y2 = signal->z+0.5*signal->thick;
// //    tbox->DrawBox(x1,y1,x2,y2);
// // TPaveLabel *tbox = new TPaveLabel(x1,y1,x2,y2,Form("#splitline{%d}{%d-%d}",
// // signal->number,signal->fadc_mod,signal->fadc_chn),"");
// // TPaveLabel *tbox = new TPaveLabel(x1,y1,x2,y2,Form("%d/%d-%d",
// // signal->number,signal->fadc_mod,signal->fadc_chn),"");
// TPaveLabel *tbox = new TPaveLabel(x1,y1,x2,y2,"","");
//     tbox->SetBorderSize(1);
//     tbox->Draw();
// //    tbox->DrawPaveLabel(x1,y1,x2,y2,Form("%d/%d",signal->number,signal->fadc_mod),"");
//   }
// }
// csignals->Modified();
// csignals->Update();
// 
// // float ymin = 0;
// // float ymax = 512.f;
// float ymin = -5.f;
// float ymax = 704.f; //[mm]
// //float dy = 512.f;
// 
// if ((TCanvas*)gROOT->GetListOfCanvases()->FindObject("ctime")){
//   ctime->cd();
//   ctime->Clear();
// }
// else {
//   ctime = new TCanvas("ctime","ctime",600,600,600,500);
//   ctime->SetRightMargin(0.05);
//   ctime->SetLeftMargin(0.08);
// }
// ctime->Draw();
// snully = new TH1F("snully","snully",100,ymin,ymax);
// snully->SetMinimum(zmin);
// snully->SetMaximum(zmax);
// snully->Draw();
// 
// ctime->Modified();
// ctime->Update();
// return;
// }
// 
///////////////////////////////////////////////////////////////////////////////

