#ifndef __CINT__

#include <math.h>

// #include "TBranch.h"
// #include "TCanvas.h"
// #include "TChain.h"
// #include "TChainElement.h"
// #include "TCutG.h"
// #include "TDirectory.h"
// #include "TF1.h"
// #include "TFile.h"
// #include "TH1.h"
// #include "TH1F.h"
// #include "TH2F.h"
// #include "TLatex.h"
// #include "TLegend.h"
// #include "TLine.h"
// #include "TMarker.h"
// #include "TNtuple.h"
// #include "TProfile.h"
// #include "TRandom.h"
// #include "TROOT.h"
// #include "TSpectrum.h"
// #include "TStyle.h"
// #include "TTree.h"

#endif

#include "mktreeraw.hxx"


//***********************************************************************
Double_t myatan(Double_t x, Double_t y){
  Double_t angle=10.;
  if(x > 0.){
    if(y >= 0.)   angle = atan(y/x);
    else          angle = atan(y/x)+2.*TMath::Pi();
  }
  else if(x < 0.){
                  angle = atan(y/x)+TMath::Pi();
  }		  
  else{
    if(y > 0.)      angle = 0.5*TMath::Pi();
    else if(y < 0.) angle = 1.5*TMath::Pi();
    else            angle = 10.;
  }
  //printf("%f %f %f\n",x,y,Double_t(angle*180./TMath::Pi()));
  return angle;
}
//___________________________________________________________________

///////////////////////////////////////////////////////////////////////////////
void indexx(int n, float y[], int indx[]){
//be careful: indx[] from 1 to n --> use y[indx[j]-1], j=0,n-1
int indxt;
float qq;
int i,j;
for(j=1;j<=n;j++) indx[j-1]=j;
if(n<=1) return;
int ll=n/2+1;
int ir=n;
for(;;){
  if(ll>1){
    ll--;
    indxt=indx[ll-1];
    qq=y[indxt-1];
  }
  else{
    indxt=indx[ir-1];
    qq=y[indxt-1];
    indx[ir-1]=indx[0];
    ir--;
    if(ir==1){
      indx[0]=indxt;
      break;
    }
  }
  i=ll;
  j=ll+ll;
  while(j<=ir){
    if(j<ir) if(y[indx[j-1]-1]<y[indx[j]-1]) j++;
    if(qq<y[indx[j-1]-1]){
      indx[i-1]=indx[j-1];
      i=j;
      j=j+j;
    }
    else{
      j=ir+1;
    }
  }
  indx[i-1]=indxt;
}
}
//______________________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

ClassImp(ASYrawFadcSignal)

ASYrawFadcSignal::ASYrawFadcSignal() 
  : module(-1), channel(-1)
{
  size = 0;
  data = 0;
  evt = 0;
  hraw = 0;
  hist = 0;
  haux = 0;
  G1 = 0;
  G2 = 0;
  G3 = 0;
 G4 = 0;
 G5 = 0;
 G6 = 0;
}

ASYrawFadcSignal::ASYrawFadcSignal(Int_t ssize) 
  : module(-1), channel(-1)
{
  size = ssize;
//  data = new Short_t[size];
  data = new Int_t[size];
  evt = 0;
  hraw = 0;
  hist = 0;
  haux = 0;
  G1 = 0;
  G2 = 0;
  G3 = 0;
 G4 = 0;
 G5 = 0;
 G6 = 0;
}

void ASYrawFadcSignal::Clear(Option_t *)
{
  if(data){
    delete[] data; 
    data = 0;
  }
//  idel++;
//  printf("<--- %d %d %d\n",icre,idel,icre-idel);
}

void ASYrawFadcSignal::SetHraw()
{
  if(data && size>0 && evt){
    if((hraw = (TH1D*)gDirectory->Get("_sign_hraw"))){// reuse hist
//      printf("sign_hraw reused evt %d %d %d\n",evt->number,module,channel);
      hraw->Reset();
    }
    else{// create hist
//      printf("sign_hraw created evt %d %d %d\n",evt->number,module,channel);
      hraw = new TH1D("_sign_hraw","_sign_hraw",size, 0., Double_t(size));
    }
    hraw->SetTitle(Form("ev %d mo %d ch %d",evt->number,module,channel));
    for(int it=0;it<size;it++){
      hraw->SetBinContent(it+1,Double_t(data[it]));
    }
  }
}


void ASYrawFadcSignal::SetHist(float pds)
{
  if(data && size>0 && evt){
    if((hist = (TH1D*)gDirectory->Get("_sign_hist"))){// reuse hist
//      printf("sign_hist reused evt %d %d %d\n",evt->number,module,channel);
      hist->Reset();
//      haux->Reset();
    }
    else{// create hist
//      printf("sign_hist created evt %d %d %d\n",evt->number,module,channel);
      hist = new TH1D("_sign_hist","_sign_hist",size, 0., Double_t(size));
//      haux = new TH1D("_aux_haux","_aux_haux",size, 0., Double_t(size));
    }
//     hist->SetTitle(Form("e %d m %d c %d",evt->number,module,channel));
    hist->SetTitle(Form("e %d m %d",evt->number,channel));
//    haux->SetTitle(Form("e %d m %d",evt->number,channel));
    for(int it=0;it<size;it++){
      hist->SetBinContent(it+1,Double_t(data[it])-pds);
//      haux->SetBinContent(it+1,Double_t(data[it])-pds);
    }
//     if(fabs(hist->GetMaximum())<fabs(hist->GetMinimum())){//invert
//       for(int it=0;it<size;it++){
//         hist->SetBinContent(it+1,-hist->GetBinContent(it+1));
// //        haux->SetBinContent(it+1,Double_t(data[it])-pds);
//       }
//     }

//       //invert!!!!!!!!!!!!!!!!!
//       for(int it=0;it<size;it++){
//         hist->SetBinContent(it+1,-hist->GetBinContent(it+1));
//       }
  }
  
}

//______________________________________________________________________________
void ASYrawFadcSignal::SetHaux()
{
  if(data && size>0 && evt){
    if((haux = (TH1D*)gDirectory->Get("_aux_haux"))){// reuse haux
//      printf("sign_haux reused evt %d %d %d\n",evt->number,module,channel);
      haux->Reset();
//      haux->Reset();
//printf("SetHaux reuse haux\n");
    }
    else{// create haux
//      printf("sign_haux created evt %d %d %d\n",evt->number,module,channel);
      haux = new TH1D("_aux_haux","_aux_haux",size, 0., Double_t(size));
//      haux = new TH1D("_aux_haux","_aux_haux",size, 0., Double_t(size));
//printf("SetHaux create haux\n");
    }
//     haux->SetTitle(Form("e %d m %d c %d",evt->number,module,channel));
    haux->SetTitle(Form("e %d m %d",evt->number,channel));
//    haux->SetTitle(Form("e %d m %d",evt->number,channel));
    for(int it=0;it<size;it++){
      haux->SetBinContent(it+1,Double_t(data[it]));
    }
  }
  
}

//______________________________________________________________________________


void ASYrawFadcSignal::SmooGa(TH1D* hin, TH1D* hout, const char* thout,
const double sigma, const double nsig) //Gaussin smoothing
{
//printf("SmooGa: %f %f\n",sigma,nsig);
  if(hin){
    int   nb1  = hin->GetNbinsX();
    float xmin1= hin->GetBinLowEdge(1);
    float bx1  = hin->GetBinWidth(nb1);
    float xmax1= hin->GetBinLowEdge(nb1)+bx1;
    if((hout = (TH1D*)gDirectory->Get(thout))){
      int   nb2  = hout->GetNbinsX();
      float xmin2= hout->GetBinLowEdge(1);
      float bx2  = hout->GetBinWidth(nb2);
      float xmax2= hout->GetBinLowEdge(nb2)+bx2;
      if(nb1==nb2 && xmin1==xmin2 && xmax1==xmax2){// reuse hout
        hout->Reset();
      }
      else{// delete and create hout
        gDirectory->GetList()->Remove(hout);
        printf("hout deleted\n");
        delete hout;
        hout = new TH1D(thout,thout,nb1, xmin1, xmax1);
      }
    }
    else{// create hout
//      printf("sign_hout created evt %d %d %d\n",evt->number,module,channel);
      hout = new TH1D(thout,thout,nb1, xmin1, xmax1);
    }
//     hout->SetTitle(Form("e %d m %d c %d",evt->number,module,channel));
    hout->SetTitle(Form("%s_%s",thout,hin->GetTitle()));
    for(int it=0;it<size;it++){
      hout->SetBinContent(it+1,hin->GetBinContent(it+1));
    }
    
{//Gaussian smoothing      
   int nlr = int(nsig*sigma);
   double patt[2*nlr+1];
   double sum = 0.;
   for(int i=0; i<2*nlr+1; i++){ //edges
     double x = i-nlr;
     double y = exp(-x*x/(2.*sigma*sigma));
     patt[i]=y;
     sum += y;
   }
   for(int i=0; i<2*nlr+1; i++){
     patt[i]/=sum;
     //printf("%2d %f\n",i,patt[i]);
   }
    
    
    double sl =0.;  
    double sr =0.;  
    for(int i=0; i<nlr; i++){
      sl += hin->GetBinContent(i+1);
    }
    for(int i=hin->GetNbinsX()-nlr; i<hin->GetNbinsX(); i++){
      sr += hin->GetBinContent(i+1);
    }
    sl /= double(nlr);
    sr /= double(nlr);
    for(int i=0; i<hin->GetNbinsX(); i++){
//   for(int i=nlr; i<hin->GetNbinsX()-nlr; i++){
     double qq = 0.;
     for(int j=i-nlr;j<=i+nlr;j++){
       double binc=0.;
       if(j<0) binc=sl;
       else if(j>=hin->GetNbinsX()) binc=sr;
       else binc=hin->GetBinContent(j+1);
       qq += patt[j-i+nlr]*binc;
     }
     hout->SetBinContent(i+1,qq); //smoothed
   }
}//Gaussian smoothing    
  }
  else{
    printf("ASYrawFadcSignal::SmooGa: no hin\n");
    exit(1);
  }
  
}

// //______________________________________________________________________________


void ASYrawFadcSignal::SmooSinc() //Sinc smoothing (antialias)
{
  if(data && size>0 && evt){
    if((haux = (TH1D*)gDirectory->Get("_aux_haux"))){// reuse haux
//      printf("sign_haux reused evt %d %d %d\n",evt->number,module,channel);
      haux->Reset();
    }
    else{// create haux
//      printf("sign_haux created evt %d %d %d\n",evt->number,module,channel);
      haux = new TH1D("_aux_haux","_aux_haux",size, 0., Double_t(size));
    }
//     haux->SetTitle(Form("e %d m %d c %d",evt->number,module,channel));
    haux->SetTitle(Form("e %d m %d",evt->number,channel));
    for(int it=0;it<size;it++){
      haux->SetBinContent(it+1,hist->GetBinContent(it+1));
    }
    
  }
{//Sinc smoothing     
//    const double B2pi = 0.1*6.283185307179586477; //2pi*cutoff freq in time bin units
//     const double B2pi = 0.025*6.283185307179586477; //2pi*cutoff freq in time bin units
     const double B2pi = 0.005*6.283185307179586477; //2pi*cutoff freq in time bin units
//   const double B2pi = 1*6.283185307179586477; //2pi*cutoff freq in time bin units
   int nlr = 200;
   double patt[2*nlr+1];
   double sum = 0.;
   for(int i=0; i<2*nlr+1; i++){ //edges
//      double x = double(i-nlr)+0.5;
     double x = double(i-nlr);
     double y = 1;
     if(x!=0) y= sin(B2pi*x)/(B2pi*x);
     patt[i]=y;
     sum += y;
   }
   for(int i=0; i<2*nlr+1; i++){
     patt[i]/=sum;
     //printf("%2d %f %f %f\n",i,patt[i],x,y);
   }
    
    
    double sl =0.;  
    double sr =0.;  
    for(int i=0; i<nlr; i++){
      sl += hist->GetBinContent(i+1);
    }
    for(int i=hist->GetNbinsX()-nlr; i<hist->GetNbinsX(); i++){
      sr += hist->GetBinContent(i+1);
    }
    sl /= double(nlr);
    sr /= double(nlr);
    for(int i=0; i<hist->GetNbinsX(); i++){
//   for(int i=nlr; i<hist->GetNbinsX()-nlr; i++){
     double qq = 0.;
     for(int j=i-nlr;j<=i+nlr;j++){
       double binc=0.;
       if(j<0) binc=sl;
       else if(j>=hist->GetNbinsX()) binc=sr;
       else binc=hist->GetBinContent(j+1);
       qq += patt[j-i+nlr]*binc;
     }
     haux->SetBinContent(i+1,qq); //smoothed
   }
}//Gaussian smoothing    
  
}
//___________________________________________________________________

void ASYrawFadcSignal::SavGol()
{
  const int flag  = 0;// [0,1] - smoothed or first derivative
  const int M_SG  = 4;  // poly order in Sav-Gol
  const int nl_SG = 10;  // # of left points in Sav-Gol
  const int nr_SG = 10;  // # of right points in Sav-Gol

  static TMatrixD *A=0;
  static TMatrixD *AT;
  static TMatrixD *ATA;
  static TMatrixD *AI;
  static TMatrixD *L;
  static TMatrixDRow *SG0;
  static TMatrixDRow *SG1;
  if(!A){
    A = new TMatrixD(-nl_SG,nr_SG,0,M_SG);
    for(int i=-nl_SG;i<=nr_SG;i++) 
      for(int j=0;j<=M_SG;j++) (*A)(i,j) = pow(double(i),double(j));

    AT = new TMatrixD(TMatrixD::kTransposed,*A);
    ATA = new TMatrixD(*AT,TMatrixD::kMult,*A);
    AI = new TMatrixD(TMatrixD::kInverted,*ATA);
    L = new TMatrixD(*AI,TMatrixD::kMult,*AT);
    //printf("L  %2d %2d\n",L.GetNrows(),L.GetNcols());
    //L.Print();

    SG0 = new TMatrixDRow(*L,0);
    SG1 = new TMatrixDRow(*L,1);

//     printf("poly order: %d | nl_SG: %d | nr_SG: %d\n",M_SG,nl_SG,nr_SG);
//     for(int i=-nl_SG;i<=nr_SG;i++){
//       printf("%3d %7.4f %7.4f\n",i,(*SG0)(i),(*SG1)(i));
//     }
  }
         
  if(data && size>0 && evt){
    if((haux = (TH1D*)gDirectory->Get("_aux_haux"))){// reuse haux
//      printf("sign_haux reused evt %d %d %d\n",evt->number,module,channel);
      haux->Reset();
    }
    else{// create haux
//      printf("sign_haux created evt %d %d %d\n",evt->number,module,channel);
      haux = new TH1D("_aux_haux","_aux_haux",size, 0., Double_t(size));
    }
//     haux->SetTitle(Form("e %d m %d c %d",evt->number,module,channel));
    haux->SetTitle(Form("e %d m %d",evt->number,channel));
    for(int it=0;it<size;it++){
      haux->SetBinContent(it+1,hist->GetBinContent(it+1));
    }
    
  }

  int   nb1  = hist->GetNbinsX();
  float xmin1= hist->GetBinLowEdge(1);
  float bx1  = hist->GetBinWidth(nb1);
  float xmax1= hist->GetBinLowEdge(nb1)+bx1;
  static int   nb   = nb1;
  static float xmin = xmin1;
  static float bx   = bx1;
  static float xmax = xmax1;
  //printf("%f %f\n",xmin,xmin1);


   // Savitzky-Golay
//    for(int i=0; i<nl_SG; i++){
//      hisg->SetBinContent(i+1,hist->GetBinContent(i+1));
//    }
//    for(int i=nb-nr_SG; i<nb; i++){
//      hisg->SetBinContent(i+1,hist->GetBinContent(i+1));
//    }
   for(int i=0; i<nb; i++){
     double qq = 0.;
     double qr = 0.;
     for(int j=i-nl_SG;j<=i+nr_SG;j++){
       double binc=0.;
       if(j<0) binc=hist->GetBinContent(0+1);
       else if(j>=nb) binc=hist->GetBinContent(nb);
// 	  if(j<0) binc=0;
// 	  else if(j>=nb) binc=0;
       else binc=hist->GetBinContent(j+1);
       qq += (*SG0)(j-i)*binc;
       qr += (*SG1)(j-i)*binc;
     }
     if(flag==0) haux->SetBinContent(i+1,qq); //smoothed
     else        haux->SetBinContent(i+1,qr); //derivative
   }
     	 
}
//______________________________________________________________________________

void ASYrawFadcSignal::SmooMed1(TH1D* hin, TH1D* hout, const char* thout) 
//Median smoothing

{

//Median smoothing x1 K=1
//http://www.desy.de/~blobel/statistics.html    
// lecture on data smoothing    

hout=0;

if(!hin){
printf("no hin: TMMmedianSmootherK1::Smooth()\n");
return;
}

if((hout = (TH1D*)gDirectory->Get(thout))){// reuse hist
  if(int(hout->GetBinLowEdge(1)) ==  int(hin->GetBinLowEdge(1)) &&
     int(hout->GetBinLowEdge(hout->GetNbinsX())) == 
     int(hin->GetBinLowEdge(hin->GetNbinsX())) &&
     hout->GetNbinsX()==hin->GetNbinsX()){ //ok
//    printf("_smo_hout reused\n");
    hout->Reset();
  }
  else{ // heve to resize
    printf("had to resize _smo_hout\n");
    gROOT->GetList()->Remove(hout);
    delete hout;
    printf("_smo_hout cloned\n");
    hout = (TH1D*)hin->Clone();
    hout->Reset();
    hout->SetName(thout);
  }
}
else{// create hist
  printf("_smo_hout created\n");
  hout = (TH1D*)hin->Clone();
  hout->Reset();
  hout->SetName(thout);
}
hout->SetTitle(Form("%s_%s",thout,hin->GetTitle()));
 


    double ymed =0.;  
    double yi1 = 0.;  
    double yi2 = 0.;  
    double yi3 = 0.;  
    double yi0 = 0;

    for(int i=2; i<=hin->GetNbinsX()-1; i++){
     yi1 = TMath::Max(hin->GetBinContent(i-1),hin->GetBinContent(i));
     yi2 = TMath::Max(hin->GetBinContent(i+1),hin->GetBinContent(i));
     yi3 = TMath::Max(hin->GetBinContent(i-1),hin->GetBinContent(i+1));
     ymed = TMath::Min(yi1,yi2);
     ymed = TMath::Min(ymed,yi3);
     hout->SetBinContent(i,ymed); //smoothed
   }
   yi0 = 3.*hin->GetBinContent(2)-2.*hin->GetBinContent(3);
   yi1 = TMath::Max(hin->GetBinContent(2),hin->GetBinContent(3));
   yi2 = TMath::Max(yi0,hin->GetBinContent(2));
   yi3 = TMath::Max(yi0,hin->GetBinContent(3));
   ymed = TMath::Min(yi1,yi2);
   ymed = TMath::Min(ymed,yi3);
   hout->SetBinContent(1,ymed); //smoothed
   yi0 = 3.*hin->GetBinContent(hin->GetNbinsX()-1)-2.*hin->GetBinContent(hin->GetNbinsX());
   yi1 = TMath::Max(hin->GetBinContent(hin->GetNbinsX()-1),hin->GetBinContent(hin->GetNbinsX()));
   yi2 = TMath::Max(yi0,hin->GetBinContent(hin->GetNbinsX()-1));
   yi3 = TMath::Max(yi0,hin->GetBinContent(hin->GetNbinsX()));
   ymed = TMath::Min(yi1,yi2);
   ymed = TMath::Min(ymed,yi3);
   hout->SetBinContent(hin->GetNbinsX(),ymed); //smoothed
   
}


//______________________________________________________________________________

void ASYrawFadcSignal::SmooMed(TH1D* hin, TH1D* hout, const char* thout,
const int K) //Median smoothing

{

//Median smoothing x1 K=1
//http://www.desy.de/~blobel/statistics.html    
// lecture on data smoothing    

hout=0;

if(!hin){
printf("no hin: TMMmedianSmootherK1::Smooth()\n");
return;
}

if((hout = (TH1D*)gDirectory->Get(thout))){// reuse hist
  if(int(hout->GetBinLowEdge(1)) ==  int(hin->GetBinLowEdge(1)) &&
     int(hout->GetBinLowEdge(hout->GetNbinsX())) == 
     int(hin->GetBinLowEdge(hin->GetNbinsX())) &&
     hout->GetNbinsX()==hin->GetNbinsX()){ //ok
//    printf("_smo_hout reused\n");
    hout->Reset();
  }
  else{ // heve to resize
    printf("had to resize _smo_hout\n");
    gROOT->GetList()->Remove(hout);
    delete hout;
    printf("_smo_hout cloned\n");
    hout = (TH1D*)hin->Clone();
    hout->Reset();
    hout->SetName(thout);
  }
}
else{// create hist
  printf("_smo_hout created\n");
  hout = (TH1D*)hin->Clone();
  hout->Reset();
  hout->SetName(thout);
}
hout->SetTitle(Form("%s_%s",thout,hin->GetTitle()));
 

    double ymed =0.;  
    const Long64_t n_med = 2*K+1;
    Double_t a_med[n_med];

    for(int i=K+1; i<=hin->GetNbinsX()-K; i++){
      for(int im=0;im<n_med;im++){
        a_med[im]=hin->GetBinContent(i-K+im); 
      }
      ymed = TMath::Median(n_med, a_med);
      hout->SetBinContent(i,ymed); //smoothed
   }
//    ymed =0.;  
//    for(int i=1; i<=K; i++){
//      ymed += hin->GetBinContent(i); 
//      //printf("%d\n",i);
//    }
//    ymed /= double(K);
//    for(int i=1; i<=K; i++){
//      hout->SetBinContent(i,ymed); //smoothed
//    }
//    ymed =0.;  
//    for(int i=hin->GetNbinsX()-K+1; i<=hin->GetNbinsX(); i++){
//      ymed += hin->GetBinContent(i); 
//      //printf("# %d\n",i);
//    }
//    ymed /= double(K);
//    for(int i=hin->GetNbinsX()-K+1; i<=hin->GetNbinsX(); i++){
//      hout->SetBinContent(i,ymed); //smoothed
//    }

   for(int i=1; i<=K; i++){
     hout->SetBinContent(i,hin->GetBinContent(i)); //original
   }
   for(int i=hin->GetNbinsX()-K+1; i<=hin->GetNbinsX(); i++){
     hout->SetBinContent(i,hin->GetBinContent(i)); //original
   }
   
}


//______________________________________________________________________________

// //______________________________________________________________________________
// 
// 
// float ASYrawFadcSignal::FindPds() 
// {
// double pds1m = 0.;
// double pds1r = 0.;
// 
// pds = 0;
// pdsrms = 0;
// 
// 
// if(!hraw){
// printf("no hraw: ASYpds16::FindPds()\n");
// return pds;
// 
// }
// 
// for(int i=1; i<=116; i++){
//   pds1m += hraw->GetBinContent(i); 
//   pds1r += pow(hraw->GetBinContent(i),2); 
// }
// pds1m/=116.;
// //  printf("# pds16 %f %f\n",pds1m,pds1r);
// pds1r=sqrt(fabs(pds1r/116.-pds1m*pds1m));
// //  printf("# pds16 %f %d %d\n",pds1m,module,channel);
// 
// 
// pds = (float)pds1m;
// pdsrms = (float)pds1r;
// //printf("pds :: %d %d  %f %f\n",module,channel,pds1m,pdsrms);
// return pds;
// }
// 
// 
//______________________________________________________________________________


float ASYrawFadcSignal::FindPds16() 
{
double pds1m = 0.;
double pds1r = 0.;

pds = 0;
pdsrms = 0;


if(!hraw){
printf("no hraw: ASYpds16::FindPds()\n");
return pds;

}

for(int i=1; i<=80; i++){
  pds1m += hraw->GetBinContent(i); 
  pds1r += pow(hraw->GetBinContent(i),2); 
}
pds1m/=80.;
//  printf("# pds16 %f %f\n",pds1m,pds1r);
pds1r=sqrt(fabs(pds1r/80.-pds1m*pds1m));
//  printf("# pds16 %f %d %d\n",pds1m,module,channel);


pds = (float)pds1m;
pdsrms = (float)pds1r;
//printf("pds :: %d %d  %f %f\n",module,channel,pds1m,pdsrms);
return pds;
}


//______________________________________________________________________________
// 
// 
// float ASYrawFadcSignal::FindPds() 
// {
// 
// // running average and rms
// 
// pds = 0;
// pdsrms = 0;
// 
// 
// if(!hraw){
// printf("no hraw: ASYpdsAVG::FindPds()\n");
// return pds;
// 
// }
// double pds1m = 0;
// double pds1r = 0; 
// double rpds1m = 0; 
// double rpds1r = 0;
// double pds1m2 = 0; 
// 
// int np = hraw->GetNbinsX();
// // float sum=hraw->GetBinContent(1);
// // float mean=hraw->GetBinContent(1);
// float fnp = 0;
// int np0 = 10;
// for(int i=1; i<=np0; i++){
//   fnp   +=1;
//   pds1m += hraw->GetBinContent(i); 
//   pds1r += pow(hraw->GetBinContent(i),2); 
// }
// //printf("fnp %f\n",fnp);
// for(int i=np0+1; i<np-np0; i++){
//   fnp   +=1;
//   pds1m += hraw->GetBinContent(i); 
//   pds1r += pow(hraw->GetBinContent(i),2); 
//   rpds1m = pds1m/fnp; 
//   rpds1r = sqrt(fabs(pds1r/fnp-rpds1m*rpds1m));
//   pds1m2 = (hraw->GetBinContent(i+10)+hraw->GetBinContent(i+11))/2.;
// //   if(fabs(rpds1m-pds1m2)>3.*rpds1r) break;
// //   if(fabs(rpds1m-pds1m2)>20) break;
//   if(fabs(rpds1m-pds1m2)>0.05*fabs((hraw->GetMaximum()-rpds1m))) break;
// //  if(i<50)printf("%f %f %f %f %f\n",fnp,rpds1m,rpds1r,pds1m2,fabs(rpds1m-pds1m2));
// }
// // pds1m/=116.;
// // //  printf("# pds16 %f %f\n",pds1m,pds1r);
// // pds1r=sqrt(fabs(pds1r/116.-pds1m*pds1m));
// // //  printf("# pds16 %f %d %d\n",pds1m,module,channel);
// 
// 
// pds = (float)rpds1m;
// pdsrms = (float)rpds1r;
// //printf("pds :: %d %d  %f %f %f\n",module,channel,pds,pdsrms,fnp);
// return pds;
// }
// //______________________________________________________________________________



float ASYrawFadcSignal::FindPds() 
{


pds = 0;
pdsrms = 0;

//find max/min
int chmin = 0;
int chmax = 0;
int vmin =  1.e9;
int vmax = -1.e9;
for(int is = 0;is<hraw->GetNbinsX();is++){
  if(hraw->GetBinContent(is+1)<vmin){
    vmin=hraw->GetBinContent(is+1);
    chmin = is;
  }
  if(hraw->GetBinContent(is+1)>vmax){
    vmax=hraw->GetBinContent(is+1);
    chmax = is;
  }
}
//find max/min

//pds 0-approx  	
double pds00   = 0;
double pdsrms00 = 0;
double pds0   = 0;
double pdsrms0 = 0;
double pds1m  = 0;
double pds1r  = 0; 
double rpds1m = 0; 
double rpds1r = 0;
double pds1m2 = 0; 

int np = hraw->GetNbinsX();
double fnp = 0;
int np0 = 10;
for(int i=0; i<np0; i++){
  fnp	+=1;
  pds1m += double(hraw->GetBinContent(i+1)); 
  pds1r += pow(double(hraw->GetBinContent(i+1)),2); 
}

pds0	= pds1m/fnp;
pdsrms0 = sqrt(fabs(pds1r/fnp-pow(pds0,2)));
for(int i=np0; i<np; i++){
  fnp	+=1;
  pds1m += double(hraw->GetBinContent(i+1)); 
  pds1r += pow(double(hraw->GetBinContent(i+1)),2); 
}
pds00	 = pds1m/fnp;
pdsrms00 = sqrt(fabs(pds1r/fnp-pow(pds00,2)));
	    
if(pds00<pds0){
  pds0=pds00;
  pdsrms0=pdsrms00;
}
//pds 0-approx  	


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
int imin = (chmax>50) ? chmax-50 : 1;
int imax = (chmax<np-50) ? chmax+50 : np;
for(int i=imin; i<=imax; i++){
  hmaxi += double(hraw->GetBinContent(i+1));
  icount++;
}
hmaxi /= float(icount);
for(int i=chmax; i>=1; i--){
  if((double(hraw->GetBinContent(i+1))-pds0)<0.35*(hmaxi-pds0) && i<400){
    t035 = double(i);
    y035 = double(hraw->GetBinContent(i+1));
    break;
  }
}
for(int i=int(t035); i>=1; i--){
  if((double(hraw->GetBinContent(i+1))-pds0)<=0.25*(hmaxi-pds0)){
    t025 = double(i);
    y025 = double(hraw->GetBinContent(i+1));
    break;
  }
}
for(int i=int(t025); i>=1; i--){
  if((double(hraw->GetBinContent(i+1))-pds0)<0.05*(hmaxi-pds0)){
    t005 = double(i);
    y005 = double(hraw->GetBinContent(i+1));
    break;
  }
}


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
  yi=double(hraw->GetBinContent(T1));
  sw1	+= 1.;
  swy1  += yi;
  iii1++;
}
for(int T1=Tmin;T1<=Tmax;T1++){
  xi=double(T1)-0.5;
  yi=double(hraw->GetBinContent(T1));
  sw2	+= 1.;
  swx2  += xi;
  swy2  += yi;
  swxx2 += xi*xi;
  swxy2 += xi*yi;
  iii2++;
}
for(int T1=Tmin;T1<=Tmax-3;T1++){
  xi=double(T1)-0.5;
  yi=double(hraw->GetBinContent(T1));
  sw1	+= 1.;
  swy1  += yi;
  iii1++;
  
  sw2	-= 1.;
  swx2  -= xi;
  swy2  -= yi;
  swxx2 -= xi*xi;
  swxy2 -= xi*yi;
  iii2--;
 
  if(sw1==0){printf("!!!!! sw1==0\n");}
  As0 = 0;
  Bs0 = swy1/sw1;

  if(sw2==0){printf("!!!!! sw2==0\n");}
  double deno = sw2*swxx2-swx2*swx2;
  if(deno==0){printf("!!!!! sw2*swxx2-swx2*swx2==0\n");exit(1);}
  As2 = (sw2*swxy2-swx2*swy2)/(sw2*swxx2-swx2*swx2);
  Bs2 = (swy2-As2*swx2)/sw2;
  
  double Dmin12=0;
  for(int it=1;it<=T1;it++){
    xi=double(it)-0.5;
    yi=double(hraw->GetBinContent(it));
    Dmin12 += pow(As0*xi+Bs0-yi,2);
  }
  for(int it=T1+1;it<=Tmax;it++){
    xi=double(it)-0.5;
    yi=double(hraw->GetBinContent(it));
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

t0=(float)fT10;
pds=(float)Bs00;


pdsrms = (float)pdsrms0;
//printf("pds :: %d %d  %f %f %f\n",module,channel,pds,pdsrms,fnp);
return pds;
}

//______________________________________________________________________________


float ASYrawFadcSignal::FindT0() 
{

// FindPds() should be run first
t0 = 0;

if(!hraw){
printf("no hraw: ASYpds15::FindT0()\n");
return pds;

}

for(int i=1; i<=hraw->GetNbinsX(); i++){
//   if(fabs(hist->GetBinContent(i))>3.*pdsrms){
   if(fabs(hist->GetBinContent(i))>30){
   t0 = float(i);
    break;
  }
}
//printf("pds t0:: %d %d  %f %f\n",module,channel,pds,t0);
return t0;
}


//______________________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

// ClassImp(ASYrawCamac)
// 
// ASYrawCamac::ASYrawCamac() 
// {
//   size = 0;
//   data = 0;
//   evt = 0;
// }
// 
// ASYrawCamac::ASYrawCamac(Int_t ssize) 
// {
//   size = ssize;
//   data = new Short_t[size];
//   evt = 0;
// }
// 
// void ASYrawCamac::Clear(Option_t *)
// {
//   if(data){
//     delete[] data; 
//     data = 0;
//   }
// }


//______________________________________________________________________________

ClassImp(ASYrawEvent)


ASYrawEvent::ASYrawEvent()
  : nsignal(0)
{
  signal = new TClonesArray("ASYrawFadcSignal",1000);
//  camac = new TClonesArray("ASYrawCamac",1000);
//  for(int i=0;i<56;i++) camac[i]=0;
}


ASYrawEvent::~ASYrawEvent()
{
  Clear();
  delete signal; signal = 0;
//  delete camac; camac = 0;
}
void ASYrawEvent::Clear(Option_t* option)
{
  nsignal = 0;
//  ncamac = 0;
  if(signal) signal->Clear("C");
//  for(int i=0;i<56;i++) camac[i]=0;
//  if(camac) camac->Clear("C");
}

//______________________________________________________________________________

ASYrawFadcSignal* ASYrawEvent::ProcessedSignal(Int_t n){
    ASYrawFadcSignal *sig = (ASYrawFadcSignal*)((*signal)[n]);
    
    sig->SetEvent(this);
    
    sig->SetHraw();
    sig->SetHist(sig->FindPds()); //sets hist
    //sig->FindT0(); //sets hist
    
    return sig;
} // Get signal


//______________________________________________________________________________


