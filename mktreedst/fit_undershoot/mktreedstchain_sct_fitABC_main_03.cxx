#include "TTimer.h"
#include "Getline.h"
#include "TSystem.h"
#include "TFumili.h"

#include "TAGroot.hxx"
#include "TAGmbsEvent.hxx"
#include "TAGactMbsReader.hxx"
#include "TAGaction.hxx"
#include "TAGmbsEventFilterType.hxx"

#include "mktreeraw.hxx"
#include "mktreedstchain_sct_fitABC.hxx"
#include "geo.hxx"
//#include <gmp.h>

// jesli MOD<0  -> wszystkie moduly
// jesli MOD>=0 -> tylko dany modul
// wersja do prownania z wynikami Sebastiana - wszystkie moduly
// fit skladowej krzemowej jednym ksztaltem z EXP*EXP*(tz-t) <- undershoot !!!!!!!!!
// RC & P4 fixed
// fit skladowych CsI dwoma ksztaltami z EXP*EXP
// wspolny czas narastania

using namespace std;

extern void InitGui();
VoidFuncPtr_t initfuncs[] = { InitGui, 0 };
 
TROOT root("GUI", "GUI test environement", initfuncs);


void FCN(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag){

Double_t chi2=0.;

   Double_t cu,eu,fu,fsum;
   Double_t *zik=0;
   Double_t *pl0=0;
   Int_t i, bin,binx,biny,binz;
   Axis_t binlow, binup, binsize;

TFumili *fitter = (TFumili*)TVirtualFitter::GetFitter();

TH1D *hist = (TH1D*)fitter->GetObjectFit();
TF1 *f1 = (TF1*)fitter->GetUserFunc();
int nbx = hist->GetNbinsX();

Double_t x[3]={0.,0.,0.};
npar = f1->GetNpar();
fitter->SetParNumber(npar);
if(iflag == 9) return;
zik = fitter->GetZ();
pl0 = fitter->GetPL0();

//Double_t *df=new Double_t[npar];
Double_t df[12]={0.};
f1->InitArgs(x,par);
f = 0;

int np=0;
for(int ix=1;ix<=nbx;ix++){
  x[0]=hist->GetXaxis()->GetBinCenter(ix);
  cu=hist->GetBinContent(ix);
  eu=hist->GetBinError(ix);
//  eu=1;
//  eu=sqrt(fabs(cu));
//   if(cu>0 && eu>0){
  if(eu>0){
    fu=f1->EvalPar(x,par);
//     if(fu==-1.){
//       f=1.e9;
//       return;
//     }
    np++;
    fitter->Derivatives(df,x);
    Int_t N = 0;
    fsum = (fu-cu)/eu;
    if(iflag!=1){
      for(i=0;i<npar;i++) 
  	if(pl0[i]>0){
  	  df[N] = df[i]/eu; 
  	  // left only non-fixed param derivatives / by Sigma
  	  gin[i] += df[N]*fsum;
  	  N++;
  	}
      Int_t L = 0;
      for (i=0;i<N;i++)
  	for (Int_t j=0;j<=i;j++) 
  	  zik[L++] += df[i]*df[j];
    }
//     f += .5*fsum*fsum;
    f += fsum*fsum;
 }
}

f1->SetNumberFitPoints(np);
//delete[] df;

chi2=f;

// take care of the fixed parameters...
Int_t  ndof=np-1-(npar-1);
if(iflag==3){
  //printf("%c\n",7);
  //printf("%c\n",7);

//   double pr_chi2 = 1.-TMath::Gamma((Double_t)(0.5*ndof),(Double_t)(0.5*chi2));  
//   double ch2 = (ndof)? chi2/ndof : chi2;
//   pr_chi2 = 1.-TMath::Gamma((Double_t)(0.5*ndof),(Double_t)(0.5*chi2));  
//   ch2 = (ndof>0)? chi2/ndof : chi2;
  //printf("chi2=%f chi2/ndf=%f pr_chi2=%f\n",chi2,ch2,pr_chi2);

//   printf("%7.1f %5.3f %5.3f %7.1f %e\n",par[0],par[1],par[2],par[3],par[4]);
//   printf("%7.1f %5.3f %5.3f %7.1f %e\n",
//   fitter->fParamError[0],
//   fitter->fParamError[1],
//   fitter->fParamError[2],
//   fitter->fParamError[3],
//   fitter->fParamError[4]
//   );
  
// printf("%8.3f %8.3f  %7.3f %7.3f  %7.3f %7.3f  %8.3f %8.3f  %7.3f\n",
// par[0],fitter->fParamError[0],
// par[1],fitter->fParamError[1],
// par[2],fitter->fParamError[2],
// par[3],fitter->fParamError[3],ch2);
  
//  fitter->PrintResults(4,f);

//   for(int i=0;i<5;i++){
//     fitter->GetParameter(i, &name[0], value, verr, vlow, vhigh);
//     fitter->GetErrors(i, eplus, eminus, eparab, globcc);
//     ppar[i]=value;
//     epar[i]=eparab;
//     printf("%d %s %f %f %f %f %f\n",i,name,value,eplus, eminus, eparab, globcc);
//   } 
}
//printf("chi2/ndf=%f\n",chi2/ndof);
///home/lukasik/test-2014-10/mktreedst/fit/z4dexp2tr_new_last_last/mktreedstchain_sct_fitABC_main.cxx
}

int main(int argc, char **argv)
{
   TApplication theApp("App", &argc, argv);

if(argc<5){
  printf("usage: mktreedstchain_sct_fitABC MOD SIG RUN FIRST_EVT\n");
  printf("usage: if MOD<0 -> all modules\n");
  printf("usage: if SIG<0 -> all signals\n");
  printf("usage: if RUN>=0 -> specified run\n");
  printf("usage: if FIRST>0 -> specified evt\n");
  return 1;
}

int MOD = atoi(theApp.Argv(1));
int SIG = atoi(theApp.Argv(2));
int RUN = atoi(theApp.Argv(3));
int FIRST = atoi(theApp.Argv(4));

printf("MOD=%d  SIG=%d  RUN=%d FIRST=%d\n",MOD,SIG,RUN,FIRST);



bool plot=0;
bool fit=1;

// //gROOT->Reset();
 gStyle->SetOptStat(0);
   gStyle->SetStatH(0.1);
// gStyle->SetOptFit(1111);
 gStyle->SetOptFit();
// //gStyle->SetOptDate();
// gStyle->SetOptTitle(1);
// //gSystem->ResetSignal(kSigInterrupt);

//  TVirtualFitter::SetDefaultFitter("Minuit2");
    TVirtualFitter::SetDefaultFitter("Fumili");
//   TVirtualFitter::SetDefaultFitter("Minuit");
TVirtualFitter *fitter=TVirtualFitter::Fitter(0,12);


//TFumili *fum = new TFumili();

int runs[]={
//6953
//7082

//7255,
//7256

// 7252,
// 7253,
// 7254,
// 7255,
// 7256


// 230 MeV, 0.2 nA (current source 8.01), Trigg: PD0, 48 Ti pretrigger PD0=200 ch

// 7252,
// 7253,
// 7254,
// 7255,
// 7256,
// 7257,
// 7258,
// 7259,
// 7260,
// 7261,
// 7262,
// 7263,
// 7264,
// 7265

// kalibracja
// 200 MeV, 1 nA (current source 8.01), Trigg: PD0, 48 Ti pretrigger PD0=200 ch
7266,
7267,
7268,
7269,
7270,

// 170 MeV, 5 nA (current source 8.01), Trigg: PD0, 48 Ti pretrigger PD0=200 ch
7271,
7272,
7273,
7274,
7275,

// 140 MeV, 10 nA (current source 8.01), Trigg: PD0, 48 Ti pretrigger PD0=200 ch
7276,
7277,
7278,
7279,
7280,
7281,

// 110 MeV, 5 nA (current source 8.01), Trigg: PD0, 48 Ti pretrigger PD0=200 ch
7282,
7283,
7284,
7285,
7286,

// 85 MeV, 25 nA (current source 8.01), Trigg: PD0, 48 Ti pretrigger PD0=200 ch
7287,
7288,
7289,
7290,
7291,
7292,

// 80 MeV, 25 nA (current source 8.01), Trigg: PD0, 48 Ti pretrigger PD0=200 ch
7293,
7294,
7295,
7296,
7297,
7298,

// 70 MeV, 25 nA (current source 8.01), Trigg: PD0, 48 Ti pretrigger PD0=200 ch
7299,
7300,
7301,
7302,
7303

};



  TAGroot tagroot;
  TAGmbsEvent *mbs_sevt = new TAGmbsEvent();
  TAGmbsIStream *a_in = new TAGmbsIStream();


int ind_rmin = 0;
int ind_rmax = sizeof(runs)/sizeof(int)-1;
int nruns=ind_rmax+1;

if(RUN>0) {
  runs[0]=RUN;
  ind_rmin = 0;
  ind_rmax = 0;
  nruns=1;
}

printf("nruns: %d\n",nruns);

  ASYgeo *gg = new ASYgeo();
  gg->ReadGeo(Form("%s/geo/geo_map.geo",gSystem->ExpandPathName("$S394WRK")));
  gg->LoadParRC3GAM2DEXP13(0,Form("%s/geo/parRC3GAM2DEXP13_UNDERSHOOT.dat",gSystem->ExpandPathName("$S394WRK")));
//  gg->LoadParRCGAM10SI(0,"parRCGAM10SI.dat");
for(int i=0;i<35;i++){
  printf("%2d %4.2f %4.2f %4.2f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n",
i,
gg->P4[i][0],gg->P4[i][1],gg->P4[i][2],
gg->P5[i][0],gg->P5[i][1],gg->P5[i][2],
gg->P6[i][0],gg->P6[i][1],gg->P6[i][2],
gg->P7[i][0],gg->P7[i][1],gg->P7[i][2],
gg->P8[i][0],gg->P8[i][1],gg->P8[i][2],
gg->P9[i][0],gg->P9[i][1],gg->P9[i][2],
gg->P10[i][0]/gg->P4[i][0],gg->P10[i][1]/gg->P4[i][1],gg->P10[i][2]/gg->P4[i][2]);
}
  

//exit(1);

//const char *fname_form="/data/01_2017/run%04d.lmd";
//const char *fname_form="/data/spall_2017_06/run%04d.lmd";
//const char *fname_form="/media/SG141/spall-2017-06-lmd/run%04d.lmd";
const char *fname_form="/data/spall_2017_06/run%04d.lmd";
//const char *fname_form="/data/run%04d.lmd";

// char *qq = gSystem->ExpandPathName("/media/d01/test-2014.10-data/*run1444*");
// printf(">>>>>>>>>>  %s\n",qq);
// exit(1);

//   const char *fname_form="/d0/s394_2010.04/run%04d.root";
//   const char *fname_form="/home/lukasik/s394/mktreedst/root/run%04d.root";
//  const char *fname_form="/media/TREKSTOR/asyeos_10.04/run%04d.root";
  Long_t id, size, flags, modtime;
  for(int ir=ind_rmin;ir<=ind_rmax;ir++){
    int fret = 0;
//     if(runs[ir]<=1833){//auau
//       fret = gSystem->GetPathInfo(Form(fname_form,"au",runs[ir]), &id, &size, &flags, &modtime);
//     }
//     if(runs[ir]>=1834 && runs[ir]<=1974){//ruru
//       fret = gSystem->GetPathInfo(Form(fname_form,"ru",runs[ir]), &id, &size, &flags, &modtime);
//     }
//     if(runs[ir]>=1975){//zrzr
//       fret = gSystem->GetPathInfo(Form(fname_form,"zr",runs[ir]), &id, &size, &flags, &modtime);
//     }
fret = gSystem->GetPathInfo(Form(fname_form,runs[ir]), &id, &size, &flags, &modtime);
    if(!fret){
      printf("run %d OK\n",runs[ir]);
    }
    else{
      printf("run %d not found\n",runs[ir]);
    }
  }
  
// output tree
  TFile *f_out=0;
  Int_t split = 99;  
//   Int_t autosave = 2000000;
  Int_t autosave = 10000;
  Int_t bufsize  = 25600;
  if(split) bufsize /= 4;
   
  Char_t s_out[260];
//   sprintf(s_out,"/d/aladin02/asyeos/dst_%04d-%04d.root",runs[ind_rmin],runs[ind_rmax]);
//  sprintf(s_out,"/media/TREKSTOR/s394_2010.11/dst/dst_fit_%04d-%04d.root",runs[ind_rmin],runs[ind_rmax]);
//  sprintf(s_out,"~/s394/dst/dst_fit_z4dexp2tr_new_last_m%02d_%04d-%04d.root",MOD,runs[ind_rmin],runs[ind_rmax]);
// if(MOD<0){
//  sprintf(s_out,"~/s394/dst/dst1_%04d-%04d.root",runs[ind_rmin],runs[ind_rmax]);
// }
// else{
//  sprintf(s_out,"~/s394/dst/dst1_m%02d_%04d-%04d.root",MOD,runs[ind_rmin],runs[ind_rmax]);
// }
if(plot==1){
 sprintf(s_out,"dst_fit.root");
}
else{
if(MOD<0){
// sprintf(s_out,"dst/dst6_%04d-%04d.root",runs[ind_rmin],runs[ind_rmax]);
// sprintf(s_out,"dst9_%04d-%04d.root",runs[ind_rmin],runs[ind_rmax]);
  if(runs[ind_rmin]==runs[ind_rmax]){
    sprintf(s_out,"dst/dst_%04d.root",runs[ind_rmin]);
  }
  else{
    sprintf(s_out,"dst_%04d-%04d.root",runs[ind_rmin],runs[ind_rmax]);
  }
}
else{
 sprintf(s_out,"dst3_m%02d_%04d-%04d.root",MOD,runs[ind_rmin],runs[ind_rmax]);
}
}
  f_out   = new TFile(s_out,"RECREATE");
  TTree *ntuple  = new TTree("ntuple","data");

  ASYEvent *eventdst = new ASYEvent();
  ASYFadcPeak *peak = 0;
  ntuple->Branch("eventdst","ASYEvent",&eventdst,bufsize,split);
  ntuple->SetAutoSave(autosave);
  ntuple->SetMaxTreeSize(4000000000); //4GB
  

    TTimer  *timer = new TTimer("gSystem->ProcessEvents();", 50, kFALSE);

  TCanvas *cf = 0;
  if(plot){
//     cf = new TCanvas("cf","FADC",0,0,1200,900);
    cf = new TCanvas("cf","FADC",0,0,800,600);
    cf->Draw();
  }
  Int_t i_nevent      = 0;
  Int_t i_nevent_empty      = 0;
  Int_t i_nevent_v1724      = 0;

  Int_t ievt_tot = 0;
  Int_t ievt_tot_good = 0;

  Int_t mod = 0;
  

  Float_t tls=2000;
  Float_t tlo=2000;
  Float_t tm=0;
  Float_t am=0;
  Float_t at=0;

  Float_t p0=0;
  Float_t p1=0;
  Float_t p2=0;
  Float_t p3=0;
  Float_t p4=0;
  Float_t p5=0;
  Float_t p6=0;
  Float_t p7=0;
  Float_t p8=0;
  Float_t p9=0;
  Float_t p10=0;
  Float_t p11=0;
  Float_t chi2=0;
  

TAGmbsEventFilterType* mbs_filt = new TAGmbsEventFilterType(36,10);


//    TF1 *funnABC  = 0;
//    TF1 *funn0ABC = 0;
//    TF1 *funn1ABC = 0;
//    TF1 *funn2ABC = 0;
     TH1D *hfit = 0;
      TF1 *funn = 0;
      TF1 *funn0 = 0;
      TF1 *funn1 = 0;
      TF1 *funn2 = 0;
      TF1 *funn3 = 0;
     TH1D *hfit_512 = 0;
      TF1 *funn_512 = 0;
      TF1 *funn0_512 = 0;
      TF1 *funn1_512 = 0;
      TF1 *funn2_512 = 0;
      TF1 *funn3_512 = 0;
     TH1D *hfit_1024 = 0;
      TF1 *funn_1024 = 0;
      TF1 *funn0_1024 = 0;
      TF1 *funn1_1024 = 0;
      TF1 *funn2_1024 = 0;
      TF1 *funn3_1024 = 0;
     TH1D *hfit_640 = 0;
      TF1 *funn_640 = 0;
      TF1 *funn0_640 = 0;
      TF1 *funn1_640 = 0;
      TF1 *funn2_640 = 0;
      TF1 *funn3_640 = 0;
      
// 	  hfit_512 = new TH1D("hfit_512","hfit_512",512,0.,512.);
//           funn_512  = new TF1("funn_512",RC4DEXP2TR,0.,512.,12);
//           funn0_512 = new TF1("funn0_512",RC4DEXP2TR1,0,512.,5);
//           funn1_512 = new TF1("funn1_512",RC4DEXP2TR1,0,512.,5);
//           funn2_512 = new TF1("funn2_512",RC4DEXP2TR1,0,512.,5);
//           funn3_512 = new TF1("funn3_512",RC4DEXP2TR1,0,512.,5);
//       
// 	  hfit_1024 = new TH1D("hfit_1024","hfit_1024",1024,0.,1024.);
//           funn_1024  = new TF1("funn_1024",RC4DEXP2TR,0.,1024.,12);
//           funn0_1024 = new TF1("funn0_1024",RC4DEXP2TR1,0,1024.,5);
//           funn1_1024 = new TF1("funn1_1024",RC4DEXP2TR1,0,1024.,5);
//           funn2_1024 = new TF1("funn2_1024",RC4DEXP2TR1,0,1024.,5);
//           funn3_1024 = new TF1("funn3_1024",RC4DEXP2TR1,0,1024.,5);
//       
// 	  hfit_640 = new TH1D("hfit_640","hfit_640",640,0.,640.);
//           funn_640  = new TF1("funn_640",RC4DEXP2TR,0.,640.,12);
//           funn0_640 = new TF1("funn0_640",RC4DEXP2TR1,0,640.,5);
//           funn1_640 = new TF1("funn1_640",RC4DEXP2TR1,0,640.,5);
//           funn2_640 = new TF1("funn2_640",RC4DEXP2TR1,0,640.,5);
//           funn3_640 = new TF1("funn3_640",RC4DEXP2TR1,0,640.,5);
      
	  hfit_512 = new TH1D("hfit_512","hfit_512",512,0.,512.);
          funn_512  = new TF1("funn_512",RC4DEXPEXPUNDERSHOOT,0.,512.,12);
          funn0_512 = new TF1("funn0_512",RC4DEXPEXPUNDERSHOOT1,0,512.,6);
          funn1_512 = new TF1("funn1_512",RC4DEXPEXPUNDERSHOOT1,0,512.,6);
          funn2_512 = new TF1("funn2_512",RC4DEXPEXPUNDERSHOOT23,0,512.,5);
          funn3_512 = new TF1("funn3_512",RC4DEXPEXPUNDERSHOOT23,0,512.,5);
      
	  hfit_1024 = new TH1D("hfit_1024","hfit_1024",1024,0.,1024.);
          funn_1024  = new TF1("funn_1024",RC4DEXPEXPUNDERSHOOT,0.,1024.,12);
          funn0_1024 = new TF1("funn0_1024",RC4DEXPEXPUNDERSHOOT1,0,1024.,6);
          funn1_1024 = new TF1("funn1_1024",RC4DEXPEXPUNDERSHOOT1,0,1024.,6);
          funn2_1024 = new TF1("funn2_1024",RC4DEXPEXPUNDERSHOOT23,0,1024.,5);
          funn3_1024 = new TF1("funn3_1024",RC4DEXPEXPUNDERSHOOT23,0,1024.,5);
      
	  hfit_640 = new TH1D("hfit_640","hfit_640",640,0.,640.);
          funn_640  = new TF1("funn_640",RC4DEXPEXPUNDERSHOOT,0.,640.,12);
          funn0_640 = new TF1("funn0_640",RC4DEXPEXPUNDERSHOOT1,0,640.,6);
          funn1_640 = new TF1("funn1_640",RC4DEXPEXPUNDERSHOOT1,0,640.,6);
          funn2_640 = new TF1("funn2_640",RC4DEXPEXPUNDERSHOOT23,0,640.,5);
          funn3_640 = new TF1("funn3_640",RC4DEXPEXPUNDERSHOOT23,0,640.,5);
      
//       TF1 *fexp = 0;
//       TF1 *fexp_512 = 0;
//       TF1 *fexp_1024 = 0;
//       
//           fexp_512 = new TF1("fexp_512","expo",380.,512.);
//           fexp_1024 = new TF1("fexp_1024","expo",700.,1024.);


 TF1 *fp2 = new TF1("fp2","pol3",0.,1024.);
 TMarker *mrk = new TMarker(0,1,29);
 TMarker *mrk0 = new TMarker(0,1,29);
 TMarker *marker = new TMarker(0,1,29);
 TLine *li1e = new TLine(0,0,0,16000);
 TF1 *fexp = new TF1("fexp","exp(-x/[0]+[1])",0,1024);
 TGraph *gr = new TGraph();
 TMarker *mrkp = new TMarker(0,1,29);
 TF1 *fp21 = new TF1("fp21","pol2",0,1);
 TF1 *fp23 = new TF1("fp23","[0]*x+[1]*x*x+[2]*x*x*x",0,1);

    list<PeakData*> peak_pool;
    list<PeakData*>::iterator iter;
 
for(Int_t irun=0; irun<nruns; irun++){

// if(runs[irun]<=1833){//auau
//   a_in->Open(Form(fname_form,"au",runs[irun]));
// }
// if(runs[irun]>=1834 && runs[irun]<=1974){//ruru
//   a_in->Open(Form(fname_form,"ru",runs[irun]));
// }
// if(runs[irun]>=1975){//zrzr
//   a_in->Open(Form(fname_form,"zr",runs[irun]));
// }

a_in->Open(Form(fname_form,runs[irun]));

  printf("run %04d\n",runs[irun]);

  int ievt=0;
  int empty_evt=0; 
while(!a_in->Eof()){
lab:
    a_in->ReadEvent(mbs_sevt, mbs_filt);
    Int_t i_nse = mbs_sevt->NSubEvent();
  if(i_nse == 0) continue; // skip empty online dummy evts
  if(FIRST>=0 && ievt<FIRST){
    ievt++;
    continue; // skip to FIRST evt
  }
    Int_t e_rawid = mbs_sevt->EventRawId();
    Int_t e_trigg = mbs_sevt->EventTrigger();
//  if(FIRST>=0 && e_rawid<FIRST){
//    continue; // skip to FIRST evt
//  }
    //printf("-------> Event %9d NSubEvent %3d\n",i_nevent,i_nse);
//    if((i_nevent+1)%10000==0) printf("-------> Event %9d\n",i_nevent+1);
    //printf("EventRawId: %d Trigger: %d\n",e_rawid,e_trigg);
    //Short_t ccn = gTAGroot->CurrentCampaignNumber(); 
    //Short_t crn = gTAGroot->CurrentRunNumber();
    //Int_t   cen = gTAGroot->CurrentEventNumber();
    //printf("-------> %3d %3d %9d\n",ccn,crn,cen);
    //TAGeventId cei = gTAGroot->CurrentEventId();
    //printf("-------> %9d \n",cei.EventNumber());

//    printf("-------> Event %9d NSubEvent %3d trig %d\n",e_rawid,i_nse,e_trigg);

      
  for (Int_t i_se = 0; i_se < i_nse; i_se++) {
      Int_t i_nw         = mbs_sevt->SubEventSize(i_se);
      Int_t i_setyp      = mbs_sevt->SubEventType(i_se);
      Int_t i_sestyp     = mbs_sevt->SubEventSubType(i_se);
      Int_t i_procid     = mbs_sevt->SubEventProcId(i_se);
      Int_t i_proctyp    = mbs_sevt->SubEventProcType(i_se);
      Int_t i_crate      = mbs_sevt->SubEventCrate(i_se);
      const UInt_t* p_se = mbs_sevt->SubEventData(i_se);
    
//    printf("-------> i_setyp %d\n",i_setyp);
    if(i_setyp == 36 && i_sestyp==1){//V1724
//       printf("V1724\n");
//      printf("SubEventType:     %d\n",i_setyp);
//      printf("SubEventSize:     %d\n",i_nw);
//       printf("SubEventSubType:  %d\n",i_sestyp);
//       printf("SubEventProcId:   %d\n",i_procid);
//       printf("SubEventProcType: %d\n",i_proctyp);
//       printf("SubEventCrate:    %d\n",i_crate);
//       printf("i_nw:    %d\n",i_nw);
      
      //if(0){
      if(i_nw>0){
        Int_t i_EVENT_SIZE0   = i_nw;
        Int_t addr_mod=2;


        eventdst->run = runs[irun];
      eventdst->evt = e_rawid; // uncomment this normally
//        eventdst->evt = ievt; // only for comparison with previous version


      do{
        Int_t i_EVENT_SIZE    = (p_se[addr_mod+0]) & 0xfffffff;
        Char_t i_1010         = Char_t((p_se[addr_mod+0]>>28) & 0xf);
        Int_t i_CHANNEL_MASK  = (p_se[addr_mod+1]) & 0xff;
        Int_t i_PATTERN       = (p_se[addr_mod+1]>>8) & 0xffff;
        Int_t i_RES           = (p_se[addr_mod+1]>>25) & 0x3;
        Int_t i_BOARD_ID      = (p_se[addr_mod+1]>>27) & 0x1f;
        Int_t i_EVENT_COUNTER = (p_se[addr_mod+2]) & 0xffffff;
        Int_t i_TRIG_TIME_TAG = (p_se[addr_mod+3]);
        if(i_EVENT_SIZE>81){
        int ich_indx=0;
        for(int ich = 0;ich<8;ich++){  
          if(i_CHANNEL_MASK & (1 << ich)){ //fired channel
            ich_indx++;
          }
        }
        Int_t n_sample = 0;
        if(ich_indx>0) n_sample = 2*(i_EVENT_SIZE-4)/ich_indx;
        ich_indx=0;
        for(int ich = 0;ich<8;ich++){  
          int ifadc[n_sample];
          double dfadc[n_sample];
          double dfadc0[n_sample];
          double dfadc1[n_sample];

          if(i_CHANNEL_MASK & (1 << ich)){ //fired channel
	  int ggi  = gg->GetIndexFromFadc(i_BOARD_ID, ich);
	  mod  = gg->GetModuleNo(ggi);
	  int isig = gg->GetSignalNo(ggi);
          if(mod <0 || isig<0) continue;
//          if(isig>1) continue;

            int ii=0;
	    int chrawmax=-10;
            for(int is = 0;is<n_sample/2;is++){
             ifadc[ii++] = (p_se[addr_mod+4+ich_indx*n_sample/2+is])    & 0x3fff; //LSB
             ifadc[ii++] = (p_se[addr_mod+4+ich_indx*n_sample/2+is]>>16)& 0x3fff; //MSB
             if(ifadc[ii-1]>chrawmax) chrawmax=ifadc[ii-1];
	     //printf("ch %1d is %4d %6d %6d\n",ich,is,i_data_msb,i_data_lsb);
            }
            ich_indx++;


// 	  if(isig==0 && mod==0 && chrawmax>4000 && ievt >=17092){
// 	  if(mod>-1&& chrawmax-pds>150){
//  	  if(mod>-1){
//  	  if(mod==0&& isig==1 && chrawmax-pds>2500){//
//!!!!
// 	  if(mod==MOD){
 	  if((MOD<0 || (MOD>=0&&mod==MOD)) && (SIG<0 || (SIG>=0&&isig==SIG))){
//!!!!
//	  if(mod==26 &&isig==2&& chrawmax-pds>500){



	    
	    //find max/min
            int chmin = 0;
            int chmax = 0;
            int vmin =  1.e9;
            int vmax = -1.e9;
            for(int is = 0;is<n_sample;is++){
              if(ifadc[is]<vmin){
	        vmin=ifadc[is];
		chmin = is;
              }
              if(ifadc[is]>vmax){
	        vmax=ifadc[is];
		chmax = is;
              }
	    }
	    //find max/min

            //pds 0-approx	    
            double pds0   = 0;
            double pds00   = 0;
            double pds    = 0;
            double pdsrms = 0;
            double pdsrms00 = 0;
            double pds1m  = 0;
            double pds1r  = 0; 
            double rpds1m = 0; 
            double rpds1r = 0;
            double pds1m2 = 0; 

            int np = n_sample;
            double fnp = 0;
            int np0 = 50;
            for(int i=0; i<np0; i++){
              fnp   +=1;
              pds1m += double(ifadc[i]); 
              pds1r += pow(double(ifadc[i]),2); 
            }

            pds0    = pds1m/fnp;
            pdsrms = sqrt(fabs(pds1r/fnp-pow(pds0,2)));
	    
            for(int i=np0; i<n_sample; i++){
              fnp   +=1;
              pds1m += double(ifadc[i]); 
              pds1r += pow(double(ifadc[i]),2); 
            }
            pds00    = pds1m/fnp;
            pdsrms00 = sqrt(fabs(pds1r/fnp-pow(pds00,2)));
            //pds 0-approx	    

// printf("#     %9d %d   -------------------------------------\n",ievt,ich);

if(pds00<pds0) pds0=pds00;
// treat events without flat part at the beginning
if(ifadc[n_sample-1]<ifadc[0]-10) pds0=double(ifadc[n_sample-1]);//!!!!!?????
//if(ifadc[n_sample-1]<ifadc[0]-20) pds0=double(ifadc[n_sample-1]);//!!!!!?????

//printf("# %d %d pds0 %9.2f %9.2f\n", mod,isig,pds0,pdsrms);

//!!!!!!!!!!!!!!
// printf("# %d %d pds0 %9.2f %9.2f %9.2f\n", mod,isig,pds0,pdsrms,gg->P5[mod][isig]);
// pds0=gg->P5[mod][isig];

double t00=0;
double t000=0;
double a000=0;
double b000=0;
double t035=0;
double t025=0;
double t005=0;
double y035=0;
double y025=0;
double y005=0;
double dnpt=0;
double hmaxi = 0;
int icount=0;
int imin = (chmax>=50) ? chmax-50 : 0;
int imax = (chmax<np-50) ? chmax+50 : np-1;
for(int i=imin; i<=imax; i++){
  hmaxi += double(ifadc[i]);
  icount++;
}
hmaxi /= float(icount);
for(int i=chmax; i>=1; i--){
//   if((double(ifadc[i])-pds0)<0.35*(hmaxi-pds0) && i<400){
  if((double(ifadc[i])-pds0)<0.35*(hmaxi-pds0)){
    t035 = double(i);
    y035 = double(ifadc[i]);
    break;
  }
}
for(int i=int(t035); i>=1; i--){
  if((double(ifadc[i])-pds0)<=0.25*(hmaxi-pds0)){
    t025 = double(i);
    y025 = double(ifadc[i]);
    break;
  }
}
for(int i=int(t025); i>=1; i--){
  if((double(ifadc[i])-pds0)<0.05*(hmaxi-pds0)){
    t005 = double(i);
    y005 = double(ifadc[i]);
    break;
  }
}

//printf("\n xxx %f %f %f %f %d %d %d %d\n",t005,t025,t035,hmaxi,chmax,imin,imax,np);

// 2 lines
Double_t As00=0.,Bs00=0.;
Double_t As20=0.,Bs20=0.;
Double_t fT10 = 0;
int T10 = 0;
int Tmin =int(t005)-20;
if(Tmin<1) Tmin=1;
//Tmin = 1; //!!!!!!!!!!!!1
int Tmax =int(t035);
{

double Dmin=1.e10;

Double_t As0=0.,Bs0=0.;
Double_t As2=0.,Bs2=0.;
Double_t sw1, swy1;
Double_t sw2, swx2, swy2, swxx2, swxy2;
Double_t xi,yi;
int iii1 = 0;
int iii2 = 0;

sw1=swy1=0.;
sw2=swxy2=swx2=swy2=swxx2=0.;
for(int T1=1;T1<Tmin;T1++){
  xi=double(T1)-0.5;
  yi=double(ifadc[T1-1]);
  sw1	+= 1.;
  swy1  += yi;
  iii1++;
}
for(int T1=Tmin;T1<=Tmax;T1++){
  xi=double(T1)-0.5;
  yi=double(ifadc[T1-1]);
  sw2	+= 1.;
  swx2  += xi;
  swy2  += yi;
  swxx2 += xi*xi;
  swxy2 += xi*yi;
  iii2++;
}
for(int T1=Tmin;T1<=Tmax-3;T1++){
  xi=double(T1)-0.5;
  yi=double(ifadc[T1-1]);
  sw1	+= 1.;
  swy1  += yi;
  iii1++;
  
  sw2	-= 1.;
  swx2  -= xi;
  swy2  -= yi;
  swxx2 -= xi*xi;
  swxy2 -= xi*yi;
  iii2--;
 
  if(sw1==0){printf("!!!!! sw1==0\n");exit(1);}
  As0 = 0;
  Bs0 = swy1/sw1;

  if(sw2==0){printf("!!!!! sw2==0\n");exit(1);}
  double deno = sw2*swxx2-swx2*swx2;
  if(deno==0){printf("!!!!! sw2*swxx2-swx2*swx2==0\n");exit(1);}
  As2 = (sw2*swxy2-swx2*swy2)/(sw2*swxx2-swx2*swx2);
  Bs2 = (swy2-As2*swx2)/sw2;
  
  double Dmin12=0;
  for(int it=1;it<=T1;it++){
    xi=double(it)-0.5;
    yi=double(ifadc[it-1]);
    Dmin12 += pow(As0*xi+Bs0-yi,2);
  }
  for(int it=T1+1;it<=Tmax;it++){
    xi=double(it)-0.5;
    yi=double(ifadc[it-1]);
    Dmin12 += pow(As2*xi+Bs2-yi,2);
  }
  

//   printf("--> %d %f %f | %f %f %f %f %d\n",
//   T1,Dmin12,Dmin,(Bs0-Bs2)/As2,fabs((Bs0-Bs2)/As2-T1-1),Bs0,As2,iii2);
  if(Dmin12<Dmin && As2>0 && fabs((Bs0-Bs2)/As2-T1-1)<10){// 
    As00=As0;Bs00=Bs0;
    As20=As2;Bs20=Bs2;
    Dmin=Dmin12;
    T10 = T1;
  }
}
if(As20!=0){
  fT10 = (Bs00-Bs20)/As20;
}
else{
  fT10 = T10;
  Bs00 = pds0;
  //printf("!!!!!!!!!!!!As20==0\n");
}
//fT10 -=1;
//printf("T10 %3d %f |  %f %f %f\n",T10,fT10,Bs00,As20,Bs20);
}
// double tt00 = t005-2.*(As20*t005+Bs20-Bs00)/As20; //styczna w t005 i min w tt00
// printf("tt00 %f\n",tt00);
// 2 lines

t00=fT10;
if(t00<0) t00=0; // bez tego segm.viol.

//!!!!!!!!!!!!!
pds=Bs00;
//pds=gg->P5[mod][isig];
//!!!!!!!!!!!!!

double fnp1 = 0;
int np01 = 0;
double pds1m1 = 0.; 
double pds1r1 = 0.; 
while(np01<int(t00)){
  fnp1	+=1;
  pds1m1 += double(ifadc[np01]); 
  pds1r1 += pow(double(ifadc[np01]),2); 
  np01++;
}
if(fnp1==0) fnp1=1.;
double pds01	= pds1m1/fnp1;
double pdsrms1  = sqrt(fabs(pds1r1/fnp1-pow(pds01,2)));


//printf("# %d %d pds1 %9.2f %9.2f\n", mod,isig,pds01,pdsrms1);
//  printf("# pds1 %f %f %f\n", pds,t00,fT10);

// if(n_sample!=640){
// if(mod==0){
//   if(t00<120 || t00>200) goto lab;
//   //printf("# goto lab %d %f %f %f\n", mod,pds,t00,fT10);
// }
// else{
//   if(t00<160 || t00>210) goto lab;
//   //printf("# goto lab %d %f %f %f\n", mod,pds,t00,fT10);
// }
// }


	  PeakData *ppd=0;
          for(iter=peak_pool.begin(); iter!=peak_pool.end(); iter++){ 
            if((*iter)->mod==mod){
               ppd = (*iter);
               //printf("    peak\n");
               break;
            }
          }
// 	  if(!ppd){
// 	    ppd = new PeakData();
// 	    ppd->mod = mod; 
// 	    peak_pool.push_back(ppd); 
//             printf("new peak\n");
// 	  }
	  if(!ppd){
	    peak_pool.push_back(new PeakData());
	    //peak_pool.back().mod = mod;
	    ppd = peak_pool.back();
	    ppd->mod = mod; 
            //printf("new peak\n");
	  }
	  

ppd->n_sample[isig]  = n_sample;
ppd->pds[isig]  = pds;
// ppd->pdr[isig]  = pdsrms;
ppd->pdr[isig]  = pdsrms1;
ppd->tm[isig]   = t00;
ppd->evt[isig]  = ievt;

// if(t00>50){//fit exp to pretrigger
if(0){//fit exp to pretrigger
// fit pretrigger ////
int itmax = t00>0 ? int(t00+0.5): n_sample;
double sxi=0;
double syi=0;
double sxxi=0;
double sxyi=0;
double si=0;
for(int i=0; i<itmax; i++){
  double xi = double(i)+0.5;
  double yi = double(ifadc[i]);
  if(yi>0){
    yi=log(yi);
    sxi+=xi;
    syi+=yi;
    sxxi+=xi*xi;
    sxyi+=xi*yi;
    si+=1;
  }
}
double den = si*sxyi-sxi*syi;
double tail = 0.1;
if(den!=0) tail = -(si*sxxi-sxi*sxi)/den;
double btail = (syi+sxi/tail)/si;
// fit pretrigger ////

am=-1.e10;
for(int i=0; i<n_sample; i++){
  ppd->dfadc[isig][i] = double(ifadc[i])-exp(btail-(double(i)+0.5)/tail);
  if(ppd->dfadc[isig][i]>am) am=ppd->dfadc[isig][i];
}
ppd->am[isig]  = am;
printf("# pret %.1f %.1f\n", tail,btail);

}
else{	  
am=-1.e10;
for(int i=0; i<n_sample; i++){
  ppd->dfadc[isig][i] = double(ifadc[i])-pds;
  if(ppd->dfadc[isig][i]>am) am=ppd->dfadc[isig][i];
}
ppd->am[isig]  = am;
}



	    
	  }//if(i_BOARD_ID<=20)
	  }
        }//for(int ich = 0;ich<8;ich++)


        }//i_EVENT_SIZE>81

    addr_mod += i_EVENT_SIZE;
    //printf("addr_mod %d\n",addr_mod);
    
    }//do
    while(addr_mod<i_EVENT_SIZE0-1);

        
      i_nevent_v1724 += 1;
      }//if(i_nw>0)
    }//V1724
  }






if(peak_pool.size()){

for(iter=peak_pool.begin(); iter!=peak_pool.end(); iter++){ 
  int ntr=0;
  mod=(*iter)->mod;
  //int isig=1;
  for(int isig=0;isig<3;isig++){
//   for(int isig=0;isig<2;isig++){
  double t00 = (*iter)->tm[isig];
  am = (*iter)->am[isig];
  Int_t n_sample = (*iter)->n_sample[isig];
//  if(mod==0 && n_sample>0 && (*iter)->am[2]==0&& (*iter)->am[1]>3000){//  
//  if(mod==0 && n_sample>0 && (*iter)->am[2]==0&& (*iter)->am[1]>2000&& (*iter)->am[0]<1000){//  
//  if(mod==0 && n_sample>0 && (*iter)->am[2]==0&& (*iter)->am[1]>8500&& (*iter)->am[0]<1000){//  
//  if(mod==0 && n_sample>0 && (*iter)->am[2]==0&& (*iter)->am[0]>1000&& (*iter)->am[1]<4000){//  
//   if(mod==MOD && n_sample>0 && (*iter)->am[2]==0){//  
//   if(mod==MOD && n_sample>0 && (*iter)->am[2]==0 && (*iter)->am[1]>400){//  
//!!!  if(mod==MOD && n_sample>0){//  
//printf("# %d %d %9.2f pds1 %9.2f %9.2f\n", mod,isig,t00,(*iter)->pds[isig],(*iter)->pdr[isig]);

// bool tm0ok = false;
// bool pdsok = false;
// if(isig==0 && t00>82 && t00<95) tm0ok = true;
// if(isig==1 && t00>145 && t00<170) tm0ok = true;
// if((*iter)->pdr[isig]<4.5) pdsok = true;
//   if(n_sample>0 && (MOD<0 || (MOD>=0&&mod==MOD)) && mod<24  && tm0ok && pdsok){// 
  if(n_sample>0 && (MOD<0 || (MOD>=0&&mod==MOD)) && mod<24){// 
   
//  if(mod==MOD && n_sample>0 && (*iter)->am[1]>800 && (*iter)->am[1]<2000 && (*iter)->am[2]>2000){//  

//  printf("# pds1 %f %f\n", (*iter)->pds[isig],(*iter)->tm[isig]);


// if(mod==0 && n_sample>0 && (*iter)->am[2]==0 &&
// (*iter)->am[0]>1900 && (*iter)->am[0]<2400&&
// (*iter)->am[1]>400 && (*iter)->am[1]<1500){//  

    ntr++;
//printf("n_sample %8d\n",n_sample);

          if(n_sample==512){
	    hfit = hfit_512;
            funn = funn_512;
            funn0 = funn0_512;
            funn1 = funn1_512;
            funn2 = funn2_512;
            funn3 = funn3_512;
	    //fexp = fexp_512;
          }
          else if(n_sample==1024){
	    hfit = hfit_1024;
            funn = funn_1024;
            funn0 = funn0_1024;
            funn1 = funn1_1024;
            funn2 = funn2_1024;
            funn3 = funn3_1024;
	    //fexp = fexp_1024;
          }
          else if(n_sample==640){
	    hfit = hfit_640;
            funn = funn_640;
            funn0 = funn0_640;
            funn1 = funn1_640;
            funn2 = funn2_640;
            funn3 = funn3_640;
	    //fexp = fexp_640;
          }
	  else{
	    printf("odd n_sample: %d\n", n_sample);
	    exit(1);
	  }

//// fit tail ////
hfit->Reset();
for(int i=0; i<n_sample; i++){
  hfit->SetBinContent(i+1,(*iter)->dfadc[isig][i]);
  hfit->SetBinError(i+1,sqrt(fabs((*iter)->dfadc[isig][i])));
}

double sxi=0;
double syi=0;
double sxxi=0;
double sxyi=0;
double si=0;
int ibeg=hfit->GetMaximumBin()+150;
if(n_sample>512) ibeg+=150;
if(n_sample-ibeg<10) ibeg=n_sample-100;
//printf("ibeg %d\n",ibeg);
for(int i=ibeg; i<n_sample; i++){
  double xi = hfit->GetBinCenter(i+1);
  double yi = hfit->GetBinContent(i+1);
  if(yi>0){
    yi=log(yi);
    sxi+=xi;
    syi+=yi;
    sxxi+=xi*xi;
    sxyi+=xi*yi;
    si+=1;
  }
}
double den = si*sxyi-sxi*syi;
double tail = 0.1;
if(den!=0) tail = -(si*sxxi-sxi*sxi)/den;
double btail = (syi+sxi/tail)/si;
//// fit tail ////

// const double TLS1[15]={
// 994.10, 1245.78, 961.00, 1071.19, 1015.79, 1068.03, 980.49, 976.26, 906.09, 1032.98, 793.99, 917.51, 1011.43,
// 988.02, 1000.00};
// 
// //if(tail<TLS1[mod]-15. || tail > TLS1[mod]+15.) continue; //mod 3 take stopped in PD1 only
// //printf("ibeg %d %f %f\n",ibeg,tail,TLS1[mod]);

tls = tail;
tlo = btail;

if(fit){

double Q0     = 1;
double Q1     = 1;
double Q2     = 1;
double x0     = 0;
//double t0     = 6.7;
//double t0     = gg->P4[mod][isig];
double t1     = 43;
double t5     = gg->P6[mod][isig];
double t9     = gg->P4[mod][isig];//Si risetime (9.2)

double t2     = gg->P8[mod][isig]; //CsI  fast decay
double t3     = gg->P9[mod][isig];//CsI slow decay

double t10    = gg->P10[mod][isig];//CsI risetime (14)

double rc     = gg->P7[mod][isig];


double rat = (tail-rc)/rc;

// for(int i=0; i<n_sample; i++){
// //   double yi = exp(-(double(i)+0.5)/tail+btail); // extrapolate using exp fit
//   double yi = exp(-(double(i)+0.5-t00)/rc); // extrapolate using exp fit
//    hfit->SetBinContent(i+1,(*iter)->dfadc[isig][i]/yi);
// 
//   //hfit->SetBinError(i+1,sqrt(fabs((*iter)->dfadc[isig][i])));
// }


double parRCGAM12SI[20];
double parRCGAM12SI0[20];
double parRCGAM12SI1[20];
double parRCGAM12SI2[20];
double parRCGAM12SI3[20];
double xx[2];

double PARPD1[5]={0};


double tx0=1;
double tx1=2;
double ty0=1;
double ty1=2;
double Qy0=0;
double Qy1=0;
double Qx0=0;
double Qx1=0;
double tz0=1.5;
double tz1=10.4;
double Qz0=am;
double Qz1=am;
double xi0=0;
double xi00=t00;
double DIFF0=1.e10;
int    dzi=0;

//double rc1 = tail;
double rc1 = rc;
// //!!!!!!!!!!!!!! rc from tls see lukasik@nz21-27:~/spall-2017-06/mktreedst/fit/NOTES_spall.odt
// if(isig>0){
//   rc1 = 0.850154*rc1+73.03965;
// }
// else{
//   rc1 = 0.941141*rc1-62.98995;
// }
// //!!!!!!!!!!!!!!

double ts0=1.5;
double ts1=t9;
double Qs0=am;

// if(isig<0){//!!!! isig<3
// double xpar[5]={0};
// double ypar[5]={0};
// int    ipar=0;
// int    icount =0;
// //bool Done=false;
// bool Done=true;
// double xdif[5]={0,-0.2,0.2,0,0};
// //do{
// 
// int it01 = 0;
// int it010 = int(t00-0.5);
// //int it01 = 188;
// for(int j=it010-10;j<=it010+5;j++){
//   it01 = j;
// //int nbins = hfit->GetMaximumBin()-it01;
// //int nbins = n_sample-it01-1;
// // int nbins = (n_sample-it01)/3;
// // int nbins = (hfit->GetMaximumBin()-it01)/2;
// //int nbins = 15;
// int nbins = 18;
// if(isig==0) nbins = (n_sample-it01)/2;
// xi0 = hfit->GetBinCenter(it01+1);
// // if(ipar==0) xi0 = hfit->GetBinCenter(it01+1)+xdif[ipar];
// // else        xi0 = xpar[0]+xdif[ipar];
//   
// double M0=0;
// double M1=0;
// double M2=0;
// for(int i=it01; i<it01+nbins; i++){
//   double xi = double(i-it01);
//   double yi = hfit->GetBinContent(i+1);
//   M0+=yi;
//   M1+=xi*yi;
//   M2+=xi*xi*yi;
// }
// // double TMAX=hfit->GetBinCenter(it01+nbins)-xi0;
// double TMAX=hfit->GetBinCenter(it01+nbins+1)-xi0;
// // printf("OO %d %d\n",it01,n_sample);
// // printf("OOO %f %f %f %f\n",xi0,TMAX,hfit->GetBinCenter(it01),am);
// 
// double ERC = (1.-exp(-TMAX/rc1))*rc1*rc1;
// 
// 
// double e1 = ((1.-exp(-(TMAX/ts1)))*pow(ts1,2))/(rc1-ts1);
// 
// ts0=(ERC*(M2-2*M1*(rc1+TMAX)+M0*TMAX*(2*rc1+TMAX))-(rc1-ts1)*
// (e1*(M2-2*M1*(ts1+TMAX)+M0*TMAX*(2*ts1+TMAX))+
// TMAX*(M2+2*M0*(rc1+ts1)*TMAX-M1*(2*(rc1+ts1)+TMAX))))/
// (2*ERC*(M1-M0*(rc1+TMAX))+(rc1-ts1)*(2*e1*(-M1+M0*(ts1+TMAX))+
// TMAX*(-2*M1+M0*(2*(rc1+ts1)+TMAX))));
// 
// Qs0=((rc1-ts1)*(2*pow(M1,2)-2*M0*M1*TMAX+M0*(-M2+M0*pow(TMAX,2))))/
// (rc1*(2*ERC*(M1-M0*(rc1+TMAX))+(rc1-ts1)*(2*e1*(-M1+M0*(ts1+TMAX))+
// TMAX*(-2*M1+M0*(2*(rc1+ts1)+TMAX)))));
// 
// 
// //if(ty0<0 || ty1<0) continue;
// 
// // printf("M0 -> %f,\n",M0);
// // printf("M1 -> %f,\n",M1);
// // printf("M2 -> %f,\n",M2);
// // printf("M3 -> %f,\n",M3);
// // printf("M4 -> %f,\n",M4);
// // printf("rc -> %f,\n",rc1);
// // printf("ERC -> %f,\n",ERC);
// // printf("TMAX -> %f,\n",TMAX);
// // printf("Q0 -> %f\n",Qy0);
// 
// //printf("MM %g %g\n",tx0,tx1);
// //printf("Mx %7.4f %7.4f %7.4f\n",tx0,tx1,Qy0);
// // printf("MM %7.4f %7.4f %7.4f\n",ty0,ty1,Qy0);
//  printf("Ms %7.4f         %7.4f\n",ts0,Qs0);
// 
// 
// Qy0=Qs0;
// ty0=ts0;
// ty1=ts1;
// 
// funn1->SetParameter(0,Qy0);
// funn1->SetParameter(1,xi0);
// funn1->SetParameter(2,ty0);
// funn1->SetParameter(3,ty1);
// funn1->SetParameter(4,rc1);
// 
// //     double DIFF2=0;
// //     double DIFF =0;
// //     for(int i=0; i<n_sample; i++){
// //       double xi = double(i)+0.5;
// //       double yhi = hfit->GetBinContent(i+1);
// //       double yfi = funn1->Eval(xi);
// //       DIFF = yhi-yfi;
// //       DIFF2 += DIFF*DIFF;
// //     }
// // 
// // DIFF2/=(n_sample-5);
// // printf("DIFF2 %f %f\n",xi0,DIFF2);
// 
//     double DIFF2=0;
//     double DIFF =0;
//     for(int i=it01; i<it01+nbins; i++){
//       double xi  = hfit->GetBinCenter(i+1);
//       double yhi = hfit->GetBinContent(i+1);
//       double yfi = funn1->Eval(xi);
//       DIFF = yhi-yfi;
//       DIFF2 += DIFF*DIFF;
//     }
// 
// DIFF2/=(n_sample-5);
// //printf("DIFF2 %f %f\n",xi0,DIFF2);
// 
// //printf("MM %3d %7.4f %7.4f %7.4f %10.4f\n",it01,ty0,ty1,Qy0,DIFF2);
// 
// 
// 
// if(isig>=1){
// if(ty0>0 && Qy0<DIFF0){
//   DIFF0=Qy0;
//   tz0=ty0;
//   tz1=ty1;
//   Qz0=Qy0;
//   xi00=xi0;
//   //printf("MIN\n");
// }
// }
// else{
//  if(ty0>0 && DIFF2<DIFF0){
//   DIFF0=DIFF2;
//   tz0=ty0;
//   tz1=ty1;
//   Qz0=Qy0;
//   xi00=xi0;
//   //printf("MIN\n");
// }
// }
// 
// 
// }
// if(icount>10) Done=true;
// //}
// //while (!Done);
// 
// 
// }//if(isig<3)

  ty0=tz0;
  ty1=tz1;
  Qy0=Qz0;
  xi0=xi00;
//  printf("MM0 %7.4f %7.4f %7.4f %g %g\n",ty0,ty1,Qy0,xi0,DIFF0);


//printf("#### T0 tail %f %f\n",t00,tail);

hfit->SetTitle(Form("ev %d %d mod %2d sig %d",ievt,e_rawid,mod,isig));
bool samogon = true;
//if(0){
// if(isig>0){
// if(1){
if(t00>10 && tail>0){
samogon = false;
fitter->Clear(); //!!!!! this is it !!!!!
fitter->SetObjectFit(hfit);
fitter->SetUserFunc(funn);
fitter->SetFitMethod("chisquare");
fitter->SetFCN(FCN);
for(int ip=0;ip<12;ip++){ fitter->ReleaseParameter(ip);}

  Double_t arglist[100];
  arglist[0] = 2;
  fitter->ExecuteCommand("SET PRINT", arglist, 1); // no print
//  arglist[0] = 0;
//  fitter->ExecuteCommand("SET NOWAR", arglist, 1); // no warnings


   double q0st = 1-2*rat;
   if(q0st<0.05) q0st=0.05;
   if(q0st>1)    q0st=1.;
   fitter->SetParameter(0,"Q0",am*q0st,.1,0.,2.*am);//Q0
//  fitter->SetParameter(0,"Q0",Qy0,.1,0.,2.*am);//Q0
   if(isig==2){
     fitter->SetParameter(0,"Q0",0.     ,.1,0.,2.*am);//Q1
     fitter->FixParameter(0);//Q0
   }
//    fitter->SetParameter(1,"Q1",0.04*am*q0st     ,.1,0.,2.*am);//Q1
   fitter->SetParameter(1,"Q1",0.     ,.1,0.,2.*am);//Q1
   fitter->FixParameter(1);//Q1

   double q2st = 1.6*rat;
   if(q2st<0.05) q2st=0.01;
   if(q2st>0.9)  q2st=0.9;
   fitter->SetParameter(2,"Q2",am*q2st,.1,0.,2.*am);//Q2
   double q3st = 1.9*rat;
   if(q3st<0.05) q3st=0.01;
   if(q3st>0.9)  q3st=0.9;
   fitter->SetParameter(3,"Q3",am*q3st,.1,0.,2.*am);//Q3
   
//!!!!!!!!!
//    fitter->SetParameter(2,"Q2",0,.1,0.,2.*am);//Q2
//    fitter->SetParameter(3,"Q3",0,.1,0.,2.*am);//Q3
//    fitter->FixParameter(2);//Q1
//    fitter->FixParameter(3);//Q1

//printf(" start Q %f %f %f |  %f %f %f | rat %f tail %f\n",am*q0st,am*q2st,am*q3st,q0st,q2st,q3st,rat,tail);
   
//   fitter->SetParameter(2,"Q2",0.5*am,.1,0.,2.*am);//Q2
//   fitter->SetParameter(3,"Q3",0.25*am,.1,0.,2.*am);//Q3
//   if(fabs(tail-rc)<30){
//   printf("...........fabs(tail-rc)<30\n");
//   fitter->SetParameter(2,"Q2",0.05*am,.1,0.,2.*am);//Q2
//   fitter->SetParameter(3,"Q3",0.,.1,0.,2.*am);//Q3
//   fitter->FixParameter(3);//Q3
//   }
  

  fitter->SetParameter(4,"x0",t00,.1,-n_sample/10, n_sample);//x0

  //fitter->SetParameter(5,"t0",t5,.001,.01,50);//T0
  //fitter->FixParameter(5);//T0

//  fitter->SetParameter(6,"tz",80,.1,50.,10000);//Tz zero crossing time relative to dx
//  fitter->FixParameter(6);///Tz zero crossing time relative to dx

  fitter->SetParameter(7,"t2",t2,.01,30, 100);//T1 -> decay1
//if(mod==30&& isig==1)fitter->SetParameter(7,"t2",t2/2.,.01,20, 100);//T1 -> decay1
  
  
  fitter->SetParameter(8,"t3",t3,.01,120, 800);//T3 -> decay2
  fitter->FixParameter(8);//T3 -> decay2

  fitter->SetParameter(9,"t9",t9,.01,.1, 50);//tr -> common si rise time
//if(mod==30&& isig==1)fitter->SetParameter(9,"t9",t9/2.,.01,.1, 30);//tr -> common si rise time
  //fitter->FixParameter(9);//tr -> common si rise time

  fitter->SetParameter(10,"t10",t10,0.01,0.1,70);//tr -> common csi rise time
  fitter->FixParameter(10);//tr -> common csi rise time

  fitter->SetParameter(11,"rc",rc1,0.1,0.1,3000);//RC
  fitter->FixParameter(11);//rc

if(isig==0){
//   fitter->SetParameter(5,"t0",t5,.001,.01,70);//T0
  fitter->SetParameter(5,"t0",t5,.001,t5-10,t5+20);//T0
//  fitter->FixParameter(5);
  fitter->SetParameter(6,"tz",gg->P8[mod][0],.001,.01,10000);//Tz zero crossing time relative to dx
//  fitter->FixParameter(6);

  fitter->SetParameter(2,"Q2",0.,.1,0.,2.*am);//Q2
  fitter->FixParameter(2);
  fitter->SetParameter(3,"Q3",0.,.1,0.,2.*am);//Q3
  fitter->FixParameter(3);
  fitter->SetParameter(7,"t2",10,.01,40, 250);//T1 -> decay1
  fitter->FixParameter(7);
  fitter->SetParameter(8,"t3",11,.01,250, 2000);//T3 -> decay2
  fitter->FixParameter(8);//T3 -> decay2
  fitter->SetParameter(10,"t10",10.,0.01,0.1,70);//tr -> common csi rise time
  fitter->FixParameter(10);
//  fitter->SetParameter(11,"rc",tail,0.1,0.1,3000);//rc
//  fitter->FixParameter(11);//rc
}
else{
  fitter->SetParameter(1,"Q1",0.     ,.1,0.,2.*am);//Q1
  fitter->FixParameter(1);//Q1
//  fitter->SetParameter(5,"t0",t5,.001,.01,70);//T0
  fitter->SetParameter(5,"t0",t5,.001,t5-10,t5+20);//T0
  fitter->FixParameter(5);
  fitter->SetParameter(6,"tz",gg->P9[mod][0],.001,.01,10000);//Tz zero crossing time relative to dx
  fitter->FixParameter(6);
//  fitter->SetParameter(9,"t9",t9,.001,.1, 30);//tr -> common si rise time
//   fitter->FixParameter(9);//Q0
//   if(rat>0.05){
//     fitter->FixParameter(5);//T0
//   }
  
//   if(mod==30 || mod==3 || mod==9 || mod==26) fitter->FixParameter(5);//T0
//  if(mod==30) fitter->FixParameter(5);//T0
  

//   else{
//     printf("rat %f\n",rat);
//     //plot=1;
//   }

//   if(ratexp<rat){
//     printf("rat>ratexp %f %f\n",rat,ratexp);
//     fitter->FixParameter(5);//T0
//   }
//   else{
//     printf("rat<ratexp %f %f\n",rat,ratexp);
//     //plot=1;
//   }
}


  arglist[0] = 100;
  arglist[1] = 0.001;

// for(int ix=1;ix<=hfit->GetNbinsX();ix+=2){
// printf("%.12f %.12f %.12f    %.12f %.12f %.12f\n",
// hfit->GetXaxis()->GetBinCenter(ix),
// hfit->GetBinContent(ix),
// hfit->GetBinError(ix),
// hfit->GetXaxis()->GetBinCenter(ix+1),
// hfit->GetBinContent(ix+1),hfit->GetBinError(ix+1));
// }
    fitter->ExecuteCommand("MIGRAD", arglist, 2);
  //fitter->Minimize();

  //fitter->PrintResults(4, 0);

  Double_t eplus, eminus, eparab, globcc;
  Double_t value, verr, vlow, vhigh;
  Double_t ppar[12], epar[12];
  char name[80];
  for(int i=0;i<12;i++){
    fitter->GetParameter(i, &name[0], value, verr, vlow, vhigh);
    fitter->GetErrors(i, eplus, eminus, eparab, globcc);
    ppar[i]=value;
    epar[i]=eparab;
//     printf("%d %s %f %f %f %f %f\n",i,name,value,eplus, eminus, eparab, globcc);
    funn->SetParameter(i,value);
  } 

//       //invert par[5] par[6]
//       if(funn->GetParameter(5)>funn->GetParameter(6)){
//         double ddum = funn->GetParameter(6);
// 	funn->SetParameter(6,funn->GetParameter(5));
// 	funn->SetParameter(5,ddum);
//         ddum = funn->GetParameter(1);
// 	funn->SetParameter(1,funn->GetParameter(0));
// 	funn->SetParameter(0,ddum);
//         funn->Update();
//       }

}
else{
  for(int i=0;i<12;i++){
    funn->SetParameter(i,-1.);
  }
}

      
      funn0->SetParameter(0,funn->GetParameter(0));
      funn0->SetParameter(1,funn->GetParameter(4));
      funn0->SetParameter(2,funn->GetParameter(5));
      funn0->SetParameter(3,funn->GetParameter(9));
      funn0->SetParameter(4,funn->GetParameter(11));
      funn0->SetParameter(5,funn->GetParameter(6));
      funn1->SetParameter(0,funn->GetParameter(1));
      funn1->SetParameter(1,funn->GetParameter(4));
      funn1->SetParameter(2,funn->GetParameter(6));
      funn1->SetParameter(3,funn->GetParameter(9));
      funn1->SetParameter(4,funn->GetParameter(11));
      funn1->SetParameter(5,funn->GetParameter(6));
      funn2->SetParameter(0,funn->GetParameter(2));
      funn2->SetParameter(1,funn->GetParameter(4));
      funn2->SetParameter(2,funn->GetParameter(7));
      funn2->SetParameter(3,funn->GetParameter(10));
      funn2->SetParameter(4,funn->GetParameter(11));
      funn3->SetParameter(0,funn->GetParameter(3));
      funn3->SetParameter(1,funn->GetParameter(4));
      funn3->SetParameter(2,funn->GetParameter(8));
      funn3->SetParameter(3,funn->GetParameter(10));
      funn3->SetParameter(4,funn->GetParameter(11));
     
//printf("XX %7.4f %7.4f %7.4f\n",funn->GetParameter(5),funn->GetParameter(9),funn->GetParameter(0));


    int npt = 0;
    double DIFF2=0;
    double DIFF =0;
    for(int i=0; i<n_sample; i++){
      double xi = double(i)+0.5;
      double yhi = hfit->GetBinContent(i+1);
      double yfi = funn->Eval(xi);
      double ei  = fabs(yhi);
      if(ei){
        DIFF += pow(yhi-yfi,2)/ei;
        npt++;
      }
    }
    DIFF2 = DIFF/(npt-5);

//DIFF2/=(n_sample-8);
//printf("DIFF3 %f %f\n",funn->GetParameter(4),DIFF2);


if(plot){
//printf("%8d %8d %2d %d\n",ievt,e_rawid,mod, isig);
printf("%8d %2d %d |",ievt,mod, isig);
//printf("%7.1f %7.1f %7.1f %7.1f %7.1f | %7.1f %7.1f | %7.1f %7.1f | %7.1f  %7.1f %7.1f | %7.3f\n", 
//printf("%.3f %.3f %.3f %.3f<%.3f>%.3f %.3f|%.3f %.3f|%.3f^%.3f|%.3f|%.3f %.3f\n", 
printf("%8.3f %8.3f %8.3f|%8.3f|%8.3f %8.3f %8.3f|%6.3f^%8.3f|%8.3f|%8.3f %6.3f | %8.3f %5.2f\n", 
funn->GetParameter(0),
//funn->GetParameter(1),
funn->GetParameter(2),
funn->GetParameter(3),
funn->GetParameter(4),
funn->GetParameter(5),
//funn->GetParameter(6),
funn->GetParameter(7),
funn->GetParameter(8),
funn->GetParameter(9),
funn->GetParameter(10),
funn->GetParameter(11),
tail,
// funn->GetChisquare()/funn->GetNDF()
//sqrt(DIFF2)
DIFF2,
funn->GetParameter(6),
funn->GetParameter(6)/funn->GetParameter(5)
);
}

//printf("%d %d %d\n",indx[0],indx[1],indx[2]);
//funn->Update();
//funn->EvalPar(xx);


      parRCGAM12SI0[0]=-1;
      parRCGAM12SI0[1]=-1;
      parRCGAM12SI0[2]=-1;
      parRCGAM12SI0[3]=-1;
      parRCGAM12SI0[4]=-1;
      parRCGAM12SI1[0]=-1;
      parRCGAM12SI1[1]=-1;
      parRCGAM12SI1[2]=-1;
      parRCGAM12SI1[3]=-1;
      parRCGAM12SI1[4]=-1;
      parRCGAM12SI2[0]=-1;
      parRCGAM12SI2[1]=-1;
      parRCGAM12SI2[2]=-1;
      parRCGAM12SI2[3]=-1;
      parRCGAM12SI2[4]=-1;
      parRCGAM12SI3[0]=-1;
      parRCGAM12SI3[1]=-1;
      parRCGAM12SI3[2]=-1;
      parRCGAM12SI3[3]=-1;
      parRCGAM12SI3[4]=-1;
      

int it00=int(t00);


parRCGAM12SI[0]=funn->GetParameter(0);
parRCGAM12SI[1]=funn->GetParameter(1);
parRCGAM12SI[2]=funn->GetParameter(2);
parRCGAM12SI[3]=funn->GetParameter(3);
parRCGAM12SI[4]=funn->GetParameter(4);
parRCGAM12SI[5]=funn->GetParameter(5);
parRCGAM12SI[6]=funn->GetParameter(6);
parRCGAM12SI[7]=funn->GetParameter(7);
parRCGAM12SI[8]=funn->GetParameter(8);
parRCGAM12SI[9]=funn->GetParameter(9);
parRCGAM12SI[10]=funn->GetParameter(10);
parRCGAM12SI[11]=funn->GetParameter(11);
parRCGAM12SI0[0]=funn->GetParameter(0);
parRCGAM12SI1[0]=funn->GetParameter(1);
parRCGAM12SI2[0]=funn->GetParameter(2);
parRCGAM12SI3[0]=funn->GetParameter(3);
parRCGAM12SI0[1]=funn->GetParameter(4);
parRCGAM12SI1[1]=funn->GetParameter(4);
parRCGAM12SI2[1]=funn->GetParameter(4);
parRCGAM12SI3[1]=funn->GetParameter(4);

p0=funn->GetParameter(0);
p1=funn->GetParameter(1);
p2=funn->GetParameter(2);
p3=funn->GetParameter(3);
p4=funn->GetParameter(4);
p5=funn->GetParameter(5);
p6=funn->GetParameter(6);
p7=funn->GetParameter(7);
p8=funn->GetParameter(8);
p9=funn->GetParameter(9);
p10=funn->GetParameter(10);
p11=funn->GetParameter(11);
//chi2=funn->GetChisquare()/funn->GetNDF();
chi2=DIFF2;



//interpolation and moments
// POL3
int bmax = hfit->GetMaximumBin();

// int bl  = (bmax-p4)/4.; //bins left
// int br  = (bmax-p4)/2.; //bins right
int bl  = (bmax-(int)p4)/3.; //bins left
int br  = (bmax-(int)p4)/1.; //bins right
if(bmax-(int)p4<150) {bl*=2;br*=0.75;}
// int bl  =  50; //bins left
// int br  =  70; //bins right
double  SX6,SX5,SX4,SX3,SX2,SX1,SX0,SYX3,SYX2,SYX1,SYX0;
double  XI,YI,X0,X1,X2,X3,X4,X5,X6;
double  a,b,c,d,xmax,ymax;
SX6=SX5=SX4=SX3=SX2=SX1=SX0=SYX3=SYX2=SYX1=SYX0=0;
int bl0 = bmax-bl;
if(bl0<1) bl0=1;
int br0 = bmax+br;
if(br0>hfit->GetNbinsX()) br0=hfit->GetNbinsX();
 for(int i=bl0;i<br0;i++){
   XI=hfit->GetBinCenter(i);
   YI=hfit->GetBinContent(i);
   X0=1.;
   X1=XI;
   X2=X1*XI;
   X3=X2*XI;
   X4=X3*XI;
   X5=X4*XI;
   X6=X5*XI;
   
   SX6+=X6;
   SX5+=X5;
   SX4+=X4;
   SX3+=X3;
   SX2+=X2;
   SX1+=X1;
   SX0+=X0;
   SYX3+=YI*X3;
   SYX2+=YI*X2;
   SYX1+=YI*X1;
   SYX0+=YI;
 }
 const int npar = 4;
 double DF[npar+1][npar];
 DF[0][0]=SX6; DF[1][0]=SX5; DF[2][0]=SX4; DF[3][0]=SX3; DF[4][0]=-SYX3;
 DF[0][1]=SX5; DF[1][1]=SX4; DF[2][1]=SX3; DF[3][1]=SX2; DF[4][1]=-SYX2;
 DF[0][2]=SX4; DF[1][2]=SX3; DF[2][2]=SX2; DF[3][2]=SX1; DF[4][2]=-SYX1;
 DF[0][3]=SX3; DF[1][3]=SX2; DF[2][3]=SX1; DF[3][3]=SX0; DF[4][3]=-SYX0;
 
//GAUSS ELIMINATION
double ROW[npar+1];
for(int iy0=1;iy0<npar;iy0++){
  for(int iy=iy0;iy<npar;iy++){
    for(int ix=iy0-1;ix<npar+1;ix++) ROW[ix] = DF[ix][iy0-1]*DF[iy0-1][iy]/DF[iy0-1][iy0-1];
    for(int ix=iy0-1;ix<npar+1;ix++){
      DF[ix][iy] -= ROW[ix];
    }	   
  }	   
}	 


//BACK SUBSTITUTION
double dx[npar]={0};
for(int iy=npar-1;iy>=0;iy--){
  dx[iy] = -DF[npar][iy];
  for(int ix=iy+1;ix<npar;ix++){
    dx[iy] -= dx[ix]*DF[ix][iy];
  }
  dx[iy]/=DF[iy][iy];
}

 a  = dx[0];
 b  = dx[1];
 c  = dx[2];
 d  = dx[3];
 
 double del = 4.*b*b-12.*a*c;
 xmax = bmax;
 ymax = hfit->GetMaximum();
 if(del>=0 && a!=0){
   double sdel = sqrt(del);
   double x1 = (-2.*b-sdel)/(6.*a);
   double x2 = (-2.*b+sdel)/(6.*a);
   //printf("x1 x2  %f %f \n",x1,x2);
   xmax = (fabs(x1-bmax)<fabs(x2-bmax)) ? x1 : x2;
   ymax = a*xmax*xmax*xmax+b*xmax*xmax+c*xmax+d;
 }
 //printf("max %f %f %f %f\n",a,b,c,d);
 //printf("max %f %f\n",xmax,ymax);

(*iter)->sam[isig]  = ymax;
(*iter)->sat[isig]  = xmax;
 
 
   



 const char *input;   
 Bool_t done = kFALSE;
  if(plot){
//  if(plot &&!samogon){
// if(plot && tail<300){
      cf->cd();
      funn->SetLineColor(6);
      funn->SetNpx(2000);
      funn0->SetNpx(2000);
      funn1->SetNpx(2000);
      funn2->SetNpx(2000);
      funn3->SetNpx(2000);

//      hfit->SetMaximum(hfit->GetMaximum()*1.3);
      hfit->Draw("hist");
      funn->Draw("same");
      funn0->SetLineColor(kGreen);
      funn0->Draw("same");
      //funn1->SetLineColor(kGreen+1);
      //funn1->Draw("same");
      funn1->SetLineColor(kRed);
      funn1->SetLineWidth(2);
      funn2->SetLineColor(kCyan);
      funn2->Draw("same");
      funn3->SetLineColor(kBlue);
      funn3->Draw("same");
//         funn1->SetParameter(0,Qy0);
//         funn1->SetParameter(1,xi0);
//         funn1->SetParameter(2,ty0);
//         funn1->SetParameter(3,ty1);
//         funn1->SetParameter(4,rc1);
// 	funn1->Draw("same");
      
//       funn->Update();
//       funn0->Update();
//       funn1->Update();
//       funn2->Update();


//  fp2->SetRange(bmax-bl,bmax+br);
//  fp2->SetParameter(0,d);
//  fp2->SetParameter(1,c);
//  fp2->SetParameter(2,b);
//  fp2->SetParameter(3,a);
//  fp2->SetLineColor(4);
//  fp2->SetLineWidth(2);
//  fp2->Draw("same");
// 
//  mrk->SetMarkerSize(2);
//  mrk->SetMarkerColor(4);
//  mrk->SetX(xmax);
//  mrk->SetY(ymax);
//  mrk->Draw();
// 
//  mrk0->SetX(hfit->GetMaximumBin());
//  mrk0->SetY(hfit->GetMaximum());
//  mrk0->SetMarkerSize(2);
//  mrk0->SetMarkerColor(2);
//  mrk0->Draw();


// //draw tail & range
// //    li1e->SetLineColor(2);
// //    li1e->DrawLine(hfit->GetBinCenter(ibeg+1),0,hfit->GetBinCenter(ibeg+1),16000);
//     fexp->SetLineWidth(2);
//     fexp->SetLineColor(2);
//     fexp->SetParameter(0,tail);
//     fexp->SetParameter(1,btail);
//     fexp->SetRange(hfit->GetBinCenter(ibeg+1),n_sample);
//     fexp->Draw("same");
// //draw tail & range

// 
//http://www.holoborodko.com/pavel/numerical-methods/numerical-derivative/smooth-low-noise-differentiators/      
// I[t]/C = V'[t] + V[t]/RC
       TH1D *hdiff1 = new TH1D("hdiff1","hdiff1",n_sample,0,n_sample);
      hdiff1->Reset();
//       for(int i=5; i<n_sample-5; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
// 	(((*iter)->dfadc[isig][i+5]-(*iter)->dfadc[isig][i-5])+
//       8.*((*iter)->dfadc[isig][i+4]-(*iter)->dfadc[isig][i-4])+
//      27.*((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
//      48.*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//      42.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/512.);
//       }

//       for(int i=4; i<n_sample-4; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
// 	(((*iter)->dfadc[isig][i+4]-(*iter)->dfadc[isig][i-4])+
//       6.*((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
//      14.*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//      14.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/128.);
//       }

//       for(int i=3; i<n_sample-3; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
// 	(((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
//       4.*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//       5.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/32.);
//       }

//       for(int i=3; i<n_sample-3; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
//      (2.60499*((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
//       7.52553*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//       8.27808*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/64.);
//       }

//       for(int i=2; i<n_sample-2; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
// 	(((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//       2.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/8.);
//       }

//       for(int i=9; i<n_sample-9; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
// 	  (((*iter)->dfadc[isig][i+9]-(*iter)->dfadc[isig][i-9])+
//        16.*((*iter)->dfadc[isig][i+8]-(*iter)->dfadc[isig][i-8])+
//       119.*((*iter)->dfadc[isig][i+7]-(*iter)->dfadc[isig][i-7])+
//       544.*((*iter)->dfadc[isig][i+6]-(*iter)->dfadc[isig][i-6])+
//      1700.*((*iter)->dfadc[isig][i+5]-(*iter)->dfadc[isig][i-5])+
//      3808.*((*iter)->dfadc[isig][i+4]-(*iter)->dfadc[isig][i-4])+
//      6188.*((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
//      7072.*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//      4862.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/131072.);
//       }

      for(int i=14; i<n_sample-14; i++){
	hdiff1->SetBinContent(i+1,
     ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
	     (((*iter)->dfadc[isig][i+14]-(*iter)->dfadc[isig][i-14])+
          26.*((*iter)->dfadc[isig][i+13]-(*iter)->dfadc[isig][i-13])+
         324.*((*iter)->dfadc[isig][i+12]-(*iter)->dfadc[isig][i-12])+
        2574.*((*iter)->dfadc[isig][i+11]-(*iter)->dfadc[isig][i-11])+
       14625.*((*iter)->dfadc[isig][i+10]-(*iter)->dfadc[isig][i-10])+
       63180.*((*iter)->dfadc[isig][i+9]-(*iter)->dfadc[isig][i-9])+
      215280.*((*iter)->dfadc[isig][i+8]-(*iter)->dfadc[isig][i-8])+
      592020.*((*iter)->dfadc[isig][i+7]-(*iter)->dfadc[isig][i-7])+
     1332045.*((*iter)->dfadc[isig][i+6]-(*iter)->dfadc[isig][i-6])+
     2466750.*((*iter)->dfadc[isig][i+5]-(*iter)->dfadc[isig][i-5])+
     3749460.*((*iter)->dfadc[isig][i+4]-(*iter)->dfadc[isig][i-4])+
     4601610.*((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
     4345965.*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
     2674440.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/134217728.);
      }

//       const int NN=14; //N=29
//       const double Ck[NN]={2674440.,4345965.,4601610.,3749460.,2466750.,1332045.,592020.,
//       215280.,63180.,14625.,2574.,324.,26.,1.};
//       for(int i=NN; i<n_sample-NN; i++){
//         double val = 0.;
//         for(int k=1;k<=NN;k++){
//           val += Ck[k-1]*((*iter)->dfadc[isig][i+k]-(*iter)->dfadc[isig][i-k]);
//         }
// 	val /= 134217728.;
// 	val += ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11);
//         hdiff1->SetBinContent(i+1,val);
//       }


//       const int NN=29; //N=59
//       const double Ck[NN]={
// 1002242216651368.,1810502068789568.,2291416680811797.,2407144796004312.,2212449261033375.,
// 1820529677650320.,1356968880100470.,922110127018080.,573285572389530.,326658445806000.,
// 170679037933635.,81744284243160.,35844219876465.,14363336766240.,5246348656500.,
// 1741010517120.,522776255820.,141326246880.,34186557405.,7344051000.,1388025639.,
// 228097584.,32101146.,3792096.,365750.,27664.,1539.,56.,1.};
//       
//       for(int i=NN; i<n_sample-NN; i++){
//         double val = 0.;
//         for(int k=1;k<=NN;k++){
//           val += Ck[k-1]*((*iter)->dfadc[isig][i+k]-(*iter)->dfadc[isig][i-k]);
//         }
// 	val /= 144115188075855872.;
// 	val += ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11);
//         hdiff1->SetBinContent(i+1,val);
//       }

//       const int NN=49; //N=99
//       const double Ck[NN]={
// 5.09552e26,9.59157e26,1.3004e27,1.50486e27,1.56756e27,1.50486e27,1.3481e27,1.13525e27,9.02814e26,
// 6.80086e26,4.86261e26,3.30455e26,2.13641e26,1.31471e26,7.70339e25,4.2981e25,2.28337e25,1.15471e25,
// 5.55659e24,2.54306e24,1.10623e24,4.57034e23,1.79178e23,6.65916e22,2.34345e22,7.79901e21,2.45101e21,
// 7.26224e20,2.02505e20,5.30348e19,1.30156e19,2.98567e18,6.38322e17,1.26779e17,2.33049e16,3.94813e15,
// 6.13389e14,8.6892e13,1.11473e13,1.28462e12,1.31674e11,1.18581e10,9.23726e8,6.09812e7,3.3174e6,142784.,
// 4559.,96.,1.};
//       
//       for(int i=NN; i<n_sample-NN; i++){
//         double val = 0.;
//         for(int k=1;k<=NN;k++){
//           val += Ck[k-1]*((*iter)->dfadc[isig][i+k]-(*iter)->dfadc[isig][i-k]);
//         }
// 	val /= 1.58456e29;
// 	val += ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11);
//         hdiff1->SetBinContent(i+1,val);
//       }

//       const int NN=99; //N=199
//       const double Ck[NN]={
// 2.27509e56,4.41502e56,6.2979e56,7.82652e56,8.93653e56,9.60038e56,9.82681e56,9.65625e56,9.15332e56,
// 8.39754e56,7.47381e56,6.46384e56,5.43943e56,4.45819e56,3.56152e56,2.77489e56,2.10957e56,1.56548e56,
// 1.13431e56,8.02694e55,5.54862e55,3.74712e55,2.47249e55,1.59414e55,1.00437e55,6.18371e54,3.72042e54,
// 2.18733e54,1.25662e54,7.05399e53,3.86884e53,2.07304e53,1.0851e53,5.5479e52,2.7703e52,1.35085e52,
// 6.43144e51,2.98924e51,1.3561e51,6.00378e50,2.59342e50,1.09282e50,4.4911e49,1.79965e49,7.0299e48,
// 2.67621e48,9.9262e47,3.58602e47,1.26147e47,4.3195e46,1.43926e46,4.66483e45,1.47015e45,4.50347e44,
// 1.34032e44,3.87395e43,1.08689e43,2.95861e42,7.80977e41,1.99802e41,4.95135e40,1.1878e40,2.75663e39,
// 6.1849e38,1.34057e38,2.80489e37,5.66047e36,1.10083e36,2.06117e35,3.7119e34,6.42253e33,1.06645e33,
// 1.69734e32,2.58585e31,3.76551e30,5.23299e29,6.92854e28,8.72359e27,1.04238e27,1.17942e26,1.2605e25,
// 1.26901e24,1.1998e23,1.06164e22,8.75771e20,6.70543e19,4.74108e18,3.07738e17,1.82105e16,9.74347e14,
// 4.66661e13,1.97608e12,7.28277e10,2.28842e9,5.96073e7,1.23558e6,19109.,196.,1.};
//       
//       for(int i=NN; i<n_sample-NN; i++){
//         double val = 0.;
//         for(int k=1;k<=NN;k++){
//           val += Ck[k-1]*((*iter)->dfadc[isig][i+k]-(*iter)->dfadc[isig][i-k]);
//         }
// 	val /= 2.00867e59;
// 	val += ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11);
//         hdiff1->SetBinContent(i+1,val);
//       }





//       for(int i=5; i<n_sample-5; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
//     (-11.*((*iter)->dfadc[isig][i+5]-(*iter)->dfadc[isig][i-5])-
//       32.*((*iter)->dfadc[isig][i+4]-(*iter)->dfadc[isig][i-4])+
//       39.*((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
//      256.*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//      322.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/1536.);
//       }

//       for(int i=4; i<n_sample-4; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
//     (-2.*((*iter)->dfadc[isig][i+4]-(*iter)->dfadc[isig][i-4])-
//       1.*((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
//      16.*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//      27.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/96.);
//       }

//       for(int i=3; i<n_sample-3; i++){
// 	hdiff1->SetBinContent(i+1,
//      ((*iter)->dfadc[isig][i-1]+2.*(*iter)->dfadc[isig][i]+(*iter)->dfadc[isig][i+1])/(4.*p11)+
//     (-5.*((*iter)->dfadc[isig][i+3]-(*iter)->dfadc[isig][i-3])+
//      12.*((*iter)->dfadc[isig][i+2]-(*iter)->dfadc[isig][i-2])+
//      39.*((*iter)->dfadc[isig][i+1]-(*iter)->dfadc[isig][i-1]))/96.);
//       }

hdiff1->SetLineColor(2);
//hdiff1->SetLineWidth(2);


TH1D *hint1 = new TH1D("hint1","hint1",n_sample,0,n_sample);
hint1->Reset();
double hsum =0;
      for(int i=5; i<n_sample-5; i++){
        hsum += hdiff1->GetBinContent(i+1);
	hint1->SetBinContent(i+1,hsum);
      }
hdiff1->Scale(hfit->GetMaximum()/hdiff1->GetMaximum());
hdiff1->DrawCopy("samehist");
//hint1->Scale(5.);
hint1->SetLineColor(4);
//hint1->SetLineWidth(2);
if(hfit->GetMaximum()<hint1->GetMaximum()){
  //hfit->GetYaxis()->SetRangeUser(0,1.05*hint1->GetMaximum());
  Double_t xmin, ymin, xmax, ymax;
  gPad->GetRangeAxis(xmin, ymin, xmax, ymax);
  gPad->RangeAxis(xmin, ymin, xmax, 1.05*hint1->GetMaximum());
  //gPad->RangeAxisChanged();
}
  
hint1->DrawCopy("same");

//hfit->SetMaximum(-1111);
//hint1->DrawCopy();
//hfit->Draw("histsame");
//hdiff1->DrawCopy("same");



// //if((*iter)->tm[isig]>120){//fit exp to pretrigger
// // //// fit pretrigger ////
// // 
// // hfit->Reset();
// int itmax = (*iter)->tm[isig]>0 ? int((*iter)->tm[isig]+0.5): n_sample;
// double sxi=0;
// double syi=0;
// double sxxi=0;
// double sxyi=0;
// double si=0;
// for(int i=0; i<itmax; i++){
//   double xi = double(i)+0.5;
// //   double yi = (*iter)->dfadc[isig][i]+(*iter)->pds[isig];
//   double yi = (*iter)->dfadc[isig][i];
//   if(yi>0){
//     yi=log(yi);
//     sxi+=xi;
//     syi+=yi;
//     sxxi+=xi*xi;
//     sxyi+=xi*yi;
//     si+=1;
//   }
// }
// double den = si*sxyi-sxi*syi;
// double tail = 0.1;
// if(den!=0) tail = -(si*sxxi-sxi*sxi)/den;
// double btail = (syi+sxi/tail)/si;
// // //// fit pretrigger ////
// // am=-1.e10;
// // for(int i=0; i<n_sample; i++){
// //   hfit->SetBinContent(i+1,(*iter)->dfadc[isig][i]+(*iter)->pds[isig]-exp(btail+(double(i)+0.5)/tail));
// // }
// //   printf("# pret %f %f\n", tail,btail);
// 
// //TVirtualFitter::SetDefaultFitter("Minuit");
// 
//    printf("################# %f %f %f %f\n",(*iter)->pds[isig],(*iter)->tm[isig],tail,btail);
// //   TF1 *fexp = new TF1("fexp","[0]+exp(-x/[1]+[2])",0.,1024.);
//   TF1 *fexp = new TF1("fexp","exp(-x/[0]+[1])",0.,1024.);
// // TF1 *fexp = new TF1("fexp","[0]+x/[1]",0.,1024.);
//  fexp->SetRange(0.,(*iter)->tm[isig]>0 ? (*iter)->tm[isig]: double(n_sample));
// fitter->Clear(); //!!!!! this is it !!!!!
// fitter->SetObjectFit(hfit);
// fitter->SetUserFunc(fexp);
// fitter->SetFitMethod("chisquare");
// fitter->SetFCN(FCN);
// 
// // fexp->SetParameter(0,(*iter)->pds[isig]);
// // fexp->SetParameter(1,p11);
// // fexp->SetParameter(2,0.);
// //hfit->Fit(fexp,"R","same",0,(*iter)->tm[isig]);
// fexp->SetParameter(0,tail);
// fexp->SetParameter(1,btail);
// 
// //   Double_t arglist[100];
// // //  arglist[0] = 2;
// //   arglist[0] = 0;
// //   fitter->ExecuteCommand("SET PRINT", arglist, 1); // no print
// // //     fitter->SetParameter(0,"p0",442	,1.,0.,3000);//Q1
// // //     fitter->SetParameter(1,"p1",-0.07678070	,1.,-10,10);//Q1
// // //     fitter->SetParameter(2,"p2",-37.80960     ,1.,-100,100);//Q1
// // //    fitter->FixParameter(0);//Q1
// // //    fitter->FixParameter(1);//Q1
// // //    fitter->FixParameter(2);//Q1
// // //   fitter->SetParameter(0,"p0",(*iter)->pds[isig],1.,0.,3000.);//Q1
// // //   fitter->SetParameter(1,"p1",p11     ,1.,0.0001,30000.);//Q1
// // //   fitter->SetParameter(2,"p2",0.1     ,1.,-100.,100.);//Q1
// //   fitter->SetParameter(1,"p1",p11     ,1.,0.0001,30000.);//Q1
// //   fitter->SetParameter(2,"p2",0.1     ,1.,-100.,100.);//Q1
// // //    fitter->FixParameter(1);//Q1
// // //    fitter->FixParameter(2);//Q1
// //   arglist[0] = 1000;
// //   arglist[1] = 0.0001;
// //     fitter->ExecuteCommand("MIGRAD", arglist, 2);
// // 
// // 
// //   Double_t eplus, eminus, eparab, globcc;
// //   Double_t value, verr, vlow, vhigh;
// //   Double_t ppar[12], epar[12];
// //   char name[80];
// //   for(int i=0;i<3;i++){
// //     fitter->GetParameter(i, &name[0], value, verr, vlow, vhigh);
// //     fitter->GetErrors(i, eplus, eminus, eparab, globcc);
// //     ppar[i]=value;
// //     epar[i]=eparab;
// //      printf("%d %s %f %f %f %f %f\n",i,name,value,eplus, eminus, eparab, globcc);
// //     fexp->SetParameter(i,value);
// //   } 
// 
// 
// //  hfit->SetLineColor(2);
// //   hfit->DrawCopy("same");
//  fexp->SetRange(0.,double(n_sample));
//    fexp->Draw("same");
// //  fexp->Draw();
// //}
// 
// //TVirtualFitter *fitter=TVirtualFitter::Fitter(0,12);

      cf->cd();
      cf->Modified();
      cf->Update();
    do {
       timer->TurnOn();
       timer->Reset();
       // Now let's read the input, we can use here any
       // stdio or iostream reading methods. like std::cin >> myinputl;
       input = Getline("Type <return> to exit: "); 
       timer->TurnOff();
       // Now usefull stuff with the input!
       // ....
	 // here were are always done as soon as we get some input!
	 if (input) done = kTRUE;
    } while (!done);
}//if(plot)

}//if(fit)

(*iter)->tls[isig] = tls;
(*iter)->tlo[isig] = tlo;
(*iter)->at[isig]  = hfit->GetMaximumBin();

(*iter)->p0[isig]  = p0;
(*iter)->p1[isig]  = p1;
(*iter)->p2[isig]  = p2;
(*iter)->p3[isig]  = p3;
(*iter)->p4[isig]  = p4;
(*iter)->p5[isig]  = p5;
(*iter)->p6[isig]  = p6;
(*iter)->p7[isig]  = p7;
(*iter)->p8[isig]  = p8;
(*iter)->p9[isig]  = p9;
(*iter)->p10[isig] = p10;
(*iter)->rc[isig]  = p11;
(*iter)->chi2[isig]  = chi2;

//printf("%3d %2d %d              %f\n",isig,mod,isig,ppd->a[isig]);




    }//for(int isig=0
    }
      if(ntr>0){
        peak = eventdst->AddPeak();
        peak->mod=(*iter)->mod;

        peak->pds0 =(*iter)->pds[0];
        peak->pds1 =(*iter)->pds[1];
        peak->pds2 =(*iter)->pds[2];

        peak->pdr0 =(*iter)->pdr[0];
        peak->pdr1 =(*iter)->pdr[1];
        peak->pdr2 =(*iter)->pdr[2];
	
        peak->tls0  =(*iter)->tls[0];
        peak->tls1  =(*iter)->tls[1];
        peak->tls2  =(*iter)->tls[2];

        peak->tlo0  =(*iter)->tlo[0];
        peak->tlo1  =(*iter)->tlo[1];
        peak->tlo2  =(*iter)->tlo[2];
	
        peak->tm0  =(*iter)->tm[0];
        peak->tm1  =(*iter)->tm[1];
        peak->tm2  =(*iter)->tm[2];
	
        peak->am0  =(*iter)->am[0];
        peak->am1  =(*iter)->am[1];
        peak->am2  =(*iter)->am[2];

        peak->at0  =(*iter)->at[0];
        peak->at1  =(*iter)->at[1];
        peak->at2  =(*iter)->at[2];
	
        peak->sam0  =(*iter)->sam[0];
        peak->sam1  =(*iter)->sam[1];
        peak->sam2  =(*iter)->sam[2];

        peak->sat0  =(*iter)->sat[0];
        peak->sat1  =(*iter)->sat[1];
        peak->sat2  =(*iter)->sat[2];
	
	
        peak->p00  =(*iter)->p0[0];
        peak->p04  =(*iter)->p4[0];
        peak->p05  =(*iter)->p5[0];
        peak->p06  =(*iter)->p6[0];
        peak->p09  =(*iter)->p9[0];
        peak->rc0  =(*iter)->rc[0];
        peak->chi20  =(*iter)->chi2[0];

        peak->p10  =(*iter)->p0[1];
        peak->p12  =(*iter)->p2[1];
        peak->p13  =(*iter)->p3[1];
        peak->p14  =(*iter)->p4[1];
        peak->p15  =(*iter)->p5[1];
        peak->p16  =(*iter)->p6[1];
        peak->p17  =(*iter)->p7[1];
        peak->p18  =(*iter)->p8[1];
        peak->p19  =(*iter)->p9[1];
        peak->p110 =(*iter)->p10[1];
        peak->rc1  =(*iter)->rc[1];
        peak->chi21  =(*iter)->chi2[1];

        peak->p20  =(*iter)->p0[2];
        peak->p22  =(*iter)->p2[2];
        peak->p23  =(*iter)->p3[2];
        peak->p24  =(*iter)->p4[2];
        peak->p25  =(*iter)->p5[2];
        peak->p26  =(*iter)->p6[2];
        peak->p27  =(*iter)->p7[2];
        peak->p28  =(*iter)->p8[2];
        peak->p29  =(*iter)->p9[2];
        peak->p210 =(*iter)->p10[2];
        peak->rc2  =(*iter)->rc[2];
        peak->chi22  =(*iter)->chi2[2];

//	printf("%6d %2d     %8.2f %8.2f %d\n",ievt,peak->mod,peak->am0,peak->am1,ntr);
    }//if(ntr>0){
    }//for(iter=peak_pool.begin()
    ievt_tot_good++;
    ntuple->Fill();
    eventdst->Clear();
}

//delete objects
for(iter=peak_pool.begin(); iter!=peak_pool.end(); iter++){ 
  delete *iter;
}
peak_pool.clear();
//delete objects


    
    ievt++;
    ievt_tot++;
    if(ievt_tot%1000==0)printf("%8d / %8d\n",ievt_tot,ievt_tot_good);
//     if(ievt_tot%100==0)printf("%8d / %8d\n",ievt_tot,ievt_tot_good);
//     if(ievt_tot_good>=340) break;
  }// while(GetEvent
  printf("run %04d nentries %8d Empty %8d\n",runs[irun],ievt,empty_evt);
  ievt=0;
  a_in->Close();
}
  printf("%8d\n",ievt_tot);
  f_out->cd();
  ntuple->Write();
  f_out->Close();

  if(plot){
   theApp.Run();
  }
 
  return 0;
}

//______________________________________________________________________________

// see evt 362
//___________________________________________________________________


double zbr(double eps,int nsig,double &a,double &b,int &maxfn,int &ier,
double *xx,double *par){

int    ic;
double t,fa,fb,c,fc,d,e,tol,rm,s,p,q,r,rone,temp;

// printf("%f %f %f %f %f %f %f %f %f %f %f\n",xx[1],
// par[0],par[1],par[2],par[3],par[4],par[5],par[6],par[7],par[8],par[9]);


ier = 0;
t = pow(10.0f,-nsig);
ic = 2;
xx[0] = a;
fa = RCGAM12SI_BL(xx,par);
xx[0] = b;
fb = RCGAM12SI_BL(xx,par);
//                                 test for same sign                   
if(fa*fb>0.f){//terminal error - f(a) and f(b) have the same sign 
  ier = 130;
  maxfn = ic;
  return b;
}
lab5: c = a;
      fc = fa;
      d = b-c;
      e = d;
lab10: if(fabs(fc)>=fabs(fb)) goto lab15;
      a = b;
      b = c;
      c = a;
      fa = fb;
      fb = fc;
      fc = fa;
lab15: tol = (fabs(b)>=0.1) ? t*fabs(b) : 0.1*t;
       rm = (c-b)*0.5f;
//                                  test for convergence criteria  
      if(fabs(fb)<=eps || fabs(c-b)<=tol){//convergence of b 
        a = c;
        maxfn = ic;
        //printf("a,b %f  %f\n",a,b);
        return b;
      }
//                                  check evaluation counter             
      if(ic>=maxfn){// maxfn evaluations                    
        ier = 129;
        a = c;
        maxfn = ic;
        return b;
      }
//                                  is bisection forced                  
      if(fabs(e)<tol)        goto lab30;
      if(fabs(fa)<=fabs(fb)) goto lab30;
      s = fb/fa;
      if(a!=c){// inverse quadratic interpolation 
        q = fa/fc;
        r = fb/fc;
        rone = r-1.0f;
        p = s*((c-b)*q*(q-r)-(b-a)*rone);
        q = (q-1.0f)*rone*(s-1.0f);
      }
      else{// linear interpolation 
        p = (c-b)*s;
        q = 1.0f-s;
      }
      if(p>0.f) q = -q;
      if(p<0.f) p = -p;
      s = e;
      e = d;
//                                  if abs(p/q).ge.75*abs(c-b) then      
//                                     force bisection                   
      if(p+p>=3.0f*rm*q) goto lab30;
//                                  if abs(p/q).ge..5*abs(s) then force  
//                                     bisection. s = the value of p/q   
//                                     on the step before the last one   
      if(p+p>=fabs(s*q)) goto lab30;
      d = p/q;
      goto lab35;
//                                  bisection                            
lab30: e = rm;
      d = e;
//                                  increment b                          
lab35: a = b;
      fa = fb;
      temp = d;
      if(fabs(temp)<=0.5f*tol){
        temp = 0.f;
        if(rm!=0.f) temp = 0.5f*tol*rm/fabs(rm);
      }
      b = b+temp;
      xx[0] = b;
      fb = RCGAM12SI_BL(xx,par);
      ic = ic+1;
      if(fb*fc<=0.f) goto lab10;
      goto lab5;


}
//************************************************************************

double zbrprim(double eps,int nsig,double &a,double &b,int &maxfn,int &ier,
double *xx,double *par){

int    ic;
double t,fa,fb,c,fc,d,e,tol,rm,s,p,q,r,rone,temp;

// printf("%f %f %f %f %f %f %f %f %f %f %f\n",xx[1],
// par[0],par[1],par[2],par[3],par[4],par[5],par[6],par[7],par[8],par[9]);


ier = 0;
t = pow(10.0f,-nsig);
ic = 2;
xx[0] = a;
fa = RCGAM12SID1_BL(xx,par);
xx[0] = b;
fb = RCGAM12SID1_BL(xx,par);
//                                 test for same sign                   
if(fa*fb>0.f){//terminal error - f(a) and f(b) have the same sign 
  ier = 130;
  maxfn = ic;
  return b;
}
lab5: c = a;
      fc = fa;
      d = b-c;
      e = d;
lab10: if(fabs(fc)>=fabs(fb)) goto lab15;
      a = b;
      b = c;
      c = a;
      fa = fb;
      fb = fc;
      fc = fa;
lab15: tol = (fabs(b)>=0.1) ? t*fabs(b) : 0.1*t;
       rm = (c-b)*0.5f;
//                                  test for convergence criteria  
      if(fabs(fb)<=eps || fabs(c-b)<=tol){//convergence of b 
        a = c;
        maxfn = ic;
        //printf("a,b %f  %f\n",a,b);
        return b;
      }
//                                  check evaluation counter             
      if(ic>=maxfn){// maxfn evaluations                    
        ier = 129;
        a = c;
        maxfn = ic;
        return b;
      }
//                                  is bisection forced                  
      if(fabs(e)<tol)        goto lab30;
      if(fabs(fa)<=fabs(fb)) goto lab30;
      s = fb/fa;
      if(a!=c){// inverse quadratic interpolation 
        q = fa/fc;
        r = fb/fc;
        rone = r-1.0f;
        p = s*((c-b)*q*(q-r)-(b-a)*rone);
        q = (q-1.0f)*rone*(s-1.0f);
      }
      else{// linear interpolation 
        p = (c-b)*s;
        q = 1.0f-s;
      }
      if(p>0.f) q = -q;
      if(p<0.f) p = -p;
      s = e;
      e = d;
//                                  if abs(p/q).ge.75*abs(c-b) then      
//                                     force bisection                   
      if(p+p>=3.0f*rm*q) goto lab30;
//                                  if abs(p/q).ge..5*abs(s) then force  
//                                     bisection. s = the value of p/q   
//                                     on the step before the last one   
      if(p+p>=fabs(s*q)) goto lab30;
      d = p/q;
      goto lab35;
//                                  bisection                            
lab30: e = rm;
      d = e;
//                                  increment b                          
lab35: a = b;
      fa = fb;
      temp = d;
      if(fabs(temp)<=0.5f*tol){
        temp = 0.f;
        if(rm!=0.f) temp = 0.5f*tol*rm/fabs(rm);
      }
      b = b+temp;
      xx[0] = b;
      fb = RCGAM12SID1_BL(xx,par);
      ic = ic+1;
      if(fb*fc<=0.f) goto lab10;
      goto lab5;


}
//************************************************************************
