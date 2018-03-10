
//#include "mktreeraw.hxx"
#include "mktreedstchain_sct_fitABC.hxx"

//------------------------------------------------------------------------------

ClassImp(ASYFadcPeak)
ASYFadcPeak::ASYFadcPeak(){

mod=-1;
pds0=pds1=pds2=pdr0=pdr1=pdr2=tls0=tls1=tls2=tlo0=tlo1=tlo2=tm0=tm1=tm2=am0=am1=am2=at0=at1=at2=0;

sam0=sam1=sam2=sat0=sat1=sat2=0;

p00=p04=p05=p06=p09=0;
p10=p12=p13=p14=p15=p16=p17=p18=p19=p110=0;
p20=p22=p23=p24=p25=p26=p27=p28=p29=p210=0;
rc0=rc1=rc2=0;
chi20=chi21=chi22=0;
}



void ASYFadcPeak::Clear(Option_t *)
{}
//______________________________________________________________________________

ClassImp(ASYEvent)


ASYEvent::ASYEvent()
  : run(0), evt(0), npeak(0)
{
  peak   = new TClonesArray("ASYFadcPeak",1000);
  for(int ih=0;ih<32;ih++){
    HADC[ih] = 0;
    HTDC[ih] = 0;
    PADC[ih] = 0;
    PTDC[ih] = 0;
  }
}

ASYEvent::~ASYEvent()
{
  Clear();
  delete peak; peak = 0;
}
void ASYEvent::Clear(Option_t* option)
{
  npeak = 0;
  if(peak) peak->Clear("C");
  for(int ih=0;ih<32;ih++){
    HADC[ih] = 0;
    HTDC[ih] = 0;
    PADC[ih] = 0;
    PTDC[ih] = 0;
  }
  
}

//______________________________________________________________________________

//___________________________________________________________________

Double_t Det2(Double_t A[2][2]){
Double_t det=0.;
det=A[0][0]*A[1][1]-A[1][0]*A[0][1];
return det;
}
//___________________________________________________________________

Double_t Det3(Double_t A[3][3]){
Double_t det=0.;
det=A[0][0]*A[1][1]*A[2][2]+A[1][0]*A[2][1]*A[0][2]+A[0][1]*A[1][2]*A[2][0]-
    A[2][0]*A[1][1]*A[0][2]-A[1][0]*A[0][1]*A[2][2]-A[2][1]*A[1][2]*A[0][0];
return det;
}
// //___________________________________________________________________
//___________________________________________________________________

Double_t Det4(Double_t A[4][4]){
Double_t det=0.;
det=
A[0][3]*A[1][2]*A[2][1]*A[3][0] - A[0][2]*A[1][3]*A[2][1]*A[3][0] - A[0][3]*A[1][1]*A[2][2]*A[3][0] + 
A[0][1]*A[1][3]*A[2][2]*A[3][0] + A[0][2]*A[1][1]*A[2][3]*A[3][0] - A[0][1]*A[1][2]*A[2][3]*A[3][0] - 
A[0][3]*A[1][2]*A[2][0]*A[3][1] + A[0][2]*A[1][3]*A[2][0]*A[3][1] + A[0][3]*A[1][0]*A[2][2]*A[3][1] - 
A[0][0]*A[1][3]*A[2][2]*A[3][1] - A[0][2]*A[1][0]*A[2][3]*A[3][1] + A[0][0]*A[1][2]*A[2][3]*A[3][1] + 
A[0][3]*A[1][1]*A[2][0]*A[3][2] - A[0][1]*A[1][3]*A[2][0]*A[3][2] - A[0][3]*A[1][0]*A[2][1]*A[3][2] + 
A[0][0]*A[1][3]*A[2][1]*A[3][2] + A[0][1]*A[1][0]*A[2][3]*A[3][2] - A[0][0]*A[1][1]*A[2][3]*A[3][2] - 
A[0][2]*A[1][1]*A[2][0]*A[3][3] + A[0][1]*A[1][2]*A[2][0]*A[3][3] + A[0][2]*A[1][0]*A[2][1]*A[3][3] - 
A[0][0]*A[1][2]*A[2][1]*A[3][3] - A[0][1]*A[1][0]*A[2][2]*A[3][3] + A[0][0]*A[1][1]*A[2][2]*A[3][3];

return det;
}
//___________________________________________________________________

// Double_t Det(const int n, Double_t **A){
Double_t Det(const int n, Double_t A[9][9]){
Double_t det=0.;

switch (n){
case 1 :
det=A[0][0];
break;
case 2 :
det=A[0][0]*A[1][1]-A[1][0]*A[0][1];
break;
case 3 :
det=A[0][0]*A[1][1]*A[2][2]+A[1][0]*A[2][1]*A[0][2]+A[0][1]*A[1][2]*A[2][0]-
    A[2][0]*A[1][1]*A[0][2]-A[1][0]*A[0][1]*A[2][2]-A[2][1]*A[1][2]*A[0][0];
break;

default :
  int i, j, k;
  det = 1;

static   double matrix[9][9];
//   double **matrix;
//   matrix = new double *[n];
//    
//   for ( i = 0; i < n; i++ )
//     matrix[i] = new double[n];
   
  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < n; j++ )
      matrix[i][j] = A[i][j];
  }
   
  for ( k = 0; k < n; k++ ) {
    if ( matrix[k][k] == 0 ) {
      bool ok = false;
       
      for ( j = k; j < n; j++ ) {
        if ( matrix[j][k] != 0 )
          ok = true;
      }
       
      if ( !ok )
        return 0;
       
      for ( i = k; i < n; i++ )
        std::swap ( matrix[i][j], matrix[i][k] );
       
      det = -det;
    }
     
    det *= matrix[k][k];
 
    if ( k + 1 < n ) {
      for ( i = k + 1; i < n; i++ ) {
        for ( j = k + 1; j < n; j++ )
          matrix[i][j] = matrix[i][j] - matrix[i][k] *
          matrix[k][j] / matrix[k][k];
      }
    }
  }
 
//   for ( i = 0; i < n; i++ )
//     delete [] matrix[i];
//  
//   delete [] matrix;
}
//printf("Det: %f\n",det);
return det;
}

// //___________________________________________________________________
// ///////////////////////////////////////////////////////////////////////////////
// 
// double RCGAM8PRIM(Double_t *xx, Double_t *par){
// 
// 
// double x=xx[0];// 
// double p=xx[1];// 
// 
// double Q0     = par[0]; // 
// double Q1     = par[1]; // 
// double Q2     = par[2];
// double x0     = par[3]; // 
// double t0     = par[4]; // 
// double t1     = par[5]; // 
// double t2     = par[6]; // 
// double rc     = par[7]; // 
// 
// // !!!!  Q0 is in fact Q0/C
// // here n=1 compared to RC11
// 
// double fun = 0.; // 
// double exp_rc = exp(-(x-x0)/rc); // 
// if(x<=x0) fun=0-p;
// else fun = 
// Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
// Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
// Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2))-p;
// return fun;
// }
// 
// //___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
