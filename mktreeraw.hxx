#ifndef __UPS_EVT__
#define __UPS_EVT__

#include "TROOT.h"
#include "TObject.h"
#include "TClonesArray.h"
#include "TDirectory.h"
#include "TF1.h"
#include "TH1.h"
#include "TH1D.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TVector3.h"
#include "TMatrixD.h"
#include "TVectorD.h"

#include <iostream>
#include <vector>

class ASYrawEvent;
class ASYrawFadcSignal;
class ASYrawCamac;


//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXP(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2]; // 
double Q3     = par[3]; // 
double x0     = par[4]; // 
double t0     = par[5]; // decay si0
double t1     = par[6]; // decay si1
double t2     = par[7]; // decay csi0
double t3     = par[8]; // decay csi1
double tr     = par[9]; // common rise time
double rc     = par[10]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t0!=tr){
  fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t0)));
}
else{
  fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
if(t1!=tr){
  fun+=Q1*rc*(exp_rc*rc/((rc-t1)*(rc-tr))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t1)));
}
else{
  fun+=Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));
}
if(t2!=tr){
  fun+=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-tr))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t2)));
}
else{
  fun+=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
if(t3!=tr){
  fun+=Q3*rc*(exp_rc*rc/((rc-t3)*(rc-tr))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t3)));
}
else{
  fun+=Q3*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXP1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double tr     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t0!=tr){
  fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t0)));
}
else{
  fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
}

return fun;
}

//___________________________________________________________________
/////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXP2TR(Double_t *xx, Double_t *par){

//rozne czasy narastania dla si i csi

double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2]; // 
double Q3     = par[3]; // 
double x0     = par[4]; // 
double t0     = par[5]; // decay si0
double t1     = par[6]; // decay si1
double t2     = par[7]; // decay csi0
double t3     = par[8]; // decay csi1
double tr1    = par[9]; // common si rise time
double tr2    = par[10]; // common csi rise time
double rc     = par[11]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t0!=tr1){
  fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr1))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr1))+exp(-(x-x0)/tr1)*tr1/((tr1-rc)*(tr1-t0)));
}
else{
  fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
if(t1!=tr1){
  fun+=Q1*rc*(exp_rc*rc/((rc-t1)*(rc-tr1))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-tr1))+exp(-(x-x0)/tr1)*tr1/((tr1-rc)*(tr1-t1)));
}
else{
  fun+=Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));
}
if(t2!=tr2){
  fun+=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-tr2))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-tr2))+exp(-(x-x0)/tr2)*tr2/((tr2-rc)*(tr2-t2)));
}
else{
  fun+=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
if(t3!=tr2){
  fun+=Q3*rc*(exp_rc*rc/((rc-t3)*(rc-tr2))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-tr2))+exp(-(x-x0)/tr2)*tr2/((tr2-rc)*(tr2-t3)));
}
else{
  fun+=Q3*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXP2TR1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double tr     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t0!=tr){
  fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t0)));
}
else{
  fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RC4DEXPEXP(Double_t *xx, Double_t *par){

//rozne czasy narastania dla si i csi
// (1-exp)(exp)
// Q0*(t0 + t1)/(t1*t1)*(1 - exp(-t/t0))*exp(-t/t1)

//double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2]; // 
double Q3     = par[3]; // 
//double x0     = par[4]; // 
double dx     = xx[0]-par[4]; // 
double t0     = par[5]; // decay si0
double t1     = par[6]; // decay si1
double t2     = par[7]; // decay csi0
double t3     = par[8]; // decay csi1
double tr1    = par[9]; // common si rise time
double tr2    = par[10]; // common csi rise time
double rc     = par[11]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-dx/rc); // 
if(dx<=0) fun=0;
else {
if(t0!=rc){
  fun+=Q0*rc*(tr1+t0)*(exp_rc*rc/((rc-t0)*(rc*(tr1+t0)-tr1*t0))+exp(-dx/t0)/((t0-rc)*t0)+exp(-dx*(tr1+t0)/(tr1*t0))*tr1/(t0*(rc*(tr1+t0)-tr1*t0)));
}
else{
  fun+=Q0*exp(-dx/rc)*(rc+tr1)*(dx-tr1*(1-exp(-dx/tr1)))/(rc*rc); 
}
if(t1!=rc){
  fun+=Q1*rc*(tr1+t1)*(exp_rc*rc/((rc-t1)*(rc*(tr1+t1)-tr1*t1))+exp(-dx/t1)/((t1-rc)*t1)+exp(-dx*(tr1+t1)/(tr1*t1))*tr1/(t1*(rc*(tr1+t1)-tr1*t1)));
}
else{
  fun+=Q1*exp(-dx/rc)*(rc+tr1)*(dx-tr1*(1-exp(-dx/tr1)))/(rc*rc);  
}
if(t2!=rc){
  fun+=Q2*rc*(tr2+t2)*(exp_rc*rc/((rc-t2)*(rc*(tr2+t2)-tr2*t2))+exp(-dx/t2)/((t2-rc)*t2)+exp(-dx*(tr2+t2)/(tr2*t2))*tr2/(t2*(rc*(tr2+t2)-tr2*t2)));
}
else{
  fun+=Q2*exp(-dx/rc)*(rc+tr2)*(dx-tr2*(1-exp(-dx/tr2)))/(rc*rc);  
}
if(t3!=rc){
  fun+=Q3*rc*(tr2+t3)*(exp_rc*rc/((rc-t3)*(rc*(tr2+t3)-tr2*t3))+exp(-dx/t3)/((t3-rc)*t3)+exp(-dx*(tr2+t3)/(tr2*t3))*tr2/(t3*(rc*(tr2+t3)-tr2*t3)));
}
else{
  fun+=Q3*exp(-dx/rc)*(rc+tr2)*(dx-tr2*(1-exp(-dx/tr2)))/(rc*rc);  
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXPEXP1(Double_t *xx, Double_t *par){


//double x=xx[0];// 

double Q0     = par[0]; // 
//double x0     = par[1]; // 
double dx     = xx[0]-par[1]; // 
double t0     = par[2]; // 
double tr     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-dx/rc); // 
if(dx<=0) fun=0;
else {
if(t0!=rc){
  fun+=Q0*rc*(tr+t0)*(exp_rc*rc/((rc-t0)*(rc*(tr+t0)-tr*t0))+exp(-dx/t0)/((t0-rc)*t0)+exp(-dx*(tr+t0)/(tr*t0))*tr/(t0*(rc*(tr+t0)-tr*t0)));
}
else{
  fun+=Q0*exp(-dx/rc)*(rc+tr)*(dx-tr*(1-exp(-dx/tr)))/(rc*rc); 
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//undershoot for Si component

double RC4DEXPEXPUNDERSHOOT(Double_t *xx, Double_t *par){

//rozne czasy narastania dla si i csi
// (1-exp)(exp)
// Q0*(t0 + t1)/(t1*t1)*(1 - exp(-t/t0))*exp(-t/t1)

// dla si:
// (1-exp)(exp)*(tz-t)
// Q0/area_of_positive_peak*(1 - exp(-t/t0))*exp(-t/t1)*(tz-t)

//double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2]; // 
double Q3     = par[3]; // 
//double x0     = par[4]; // 
double dx     = xx[0]-par[4]; // 
double t0     = par[5]; // decay si0
double tz     = par[6]; // zero crossing time relative to dx
double t2     = par[7]; // decay csi0
double t3     = par[8]; // decay csi1
double tr1    = par[9]; // common si rise time
double tr2    = par[10]; // common csi rise time
double rc     = par[11]; // 

// !!!!  Q0 is in fact Q0/C
// lukasik@nz21-27:~/math/pulse_exp_x_1-exp.nb

//double dx = x-x0;
double fun = 0.; // 
double exp_rc = exp(-dx/rc); // 
if(dx<=0) fun=0;
else {
if(t0!=rc){
  fun+=
Q0*rc*pow(t0+tr1,2)*(
exp(-dx/rc)*(rc*t0*((rc-t0)*(rc*(t0+tr1)-(t0*tr1))*tz-(rc*t0*(-2*t0*tr1+rc*(t0+2*tr1)))))+
exp(-dx/t0)*(pow(t0*tr1-rc*(t0+tr1),2)*(rc*(dx+t0-tz)+t0*(tz-dx)))-
exp(-(dx*(t0+tr1))/(t0*tr1))*(pow(rc-t0,2)*tr1*(t0*tr1*(tz-dx)+rc*(t0*tr1+dx*(t0+tr1)-(t0+tr1)*tz))))/
(t0*pow((rc-t0)*(t0*tr1-rc*(t0+tr1)),2)*
((1-exp(-((t0+tr1)*tz)/(t0*tr1)))*pow(tr1,2)+(-1+exp(-tz/t0))*pow(t0+tr1,2)+(t0+tr1)*tz));
}
else{
  fun+=
Q0*pow(rc+tr1,2)*(-2.*tr1*(dx+tr1-tz)-exp(dx/tr1)*(pow(dx,2)-2.*dx*tz+2.*tr1*(tz-tr1)))/
(2.*exp(((rc+tr1)*(dx-tz))/(rc*tr1))*pow(rc,2)*
(exp(tz/tr1)*pow(rc+tr1,2)+exp((1./rc+1./tr1)*tz)*((rc+tr1)*tz-rc*(rc+2*tr1))-pow(tr1,2)));
}
if(t2!=rc){
  fun+=Q2*rc*(tr2+t2)*(exp_rc*rc/((rc-t2)*(rc*(tr2+t2)-tr2*t2))+exp(-dx/t2)/((t2-rc)*t2)+exp(-dx*(tr2+t2)/(tr2*t2))*tr2/(t2*(rc*(tr2+t2)-tr2*t2)));
}
else{
  fun+=Q2*exp(-dx/rc)*(rc+tr2)*(dx-tr2*(1-exp(-dx/tr2)))/(rc*rc);  
}
if(t3!=rc){
  fun+=Q3*rc*(tr2+t3)*(exp_rc*rc/((rc-t3)*(rc*(tr2+t3)-tr2*t3))+exp(-dx/t3)/((t3-rc)*t3)+exp(-dx*(tr2+t3)/(tr2*t3))*tr2/(t3*(rc*(tr2+t3)-tr2*t3)));
}
else{
  fun+=Q3*exp(-dx/rc)*(rc+tr2)*(dx-tr2*(1-exp(-dx/tr2)))/(rc*rc);  
}
}

return fun;
}
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXPEXPUNDERSHOOT1(Double_t *xx, Double_t *par){


//double x=xx[0];// 

double Q0     = par[0]; // 
//double x0     = par[1]; // 
double dx     = xx[0]-par[1]; // 
double t0     = par[2]; // decay si0
double tr     = par[3]; // common si rise time
double rc     = par[4]; // 
double tz     = par[5]; // zero crossing time relative to dx

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
if(dx<=0) fun=0;
else {
if(t0!=rc){
  fun+=
Q0*rc*pow(t0+tr,2)*(
exp(-dx/rc)*(rc*t0*((rc-t0)*(rc*(t0+tr)-(t0*tr))*tz-(rc*t0*(-2*t0*tr+rc*(t0+2*tr)))))+
exp(-dx/t0)*(pow(t0*tr-rc*(t0+tr),2)*(rc*(dx+t0-tz)+t0*(tz-dx)))-
exp(-(dx*(t0+tr))/(t0*tr))*(pow(rc-t0,2)*tr*(t0*tr*(tz-dx)+rc*(t0*tr+dx*(t0+tr)-(t0+tr)*tz))))/
(t0*pow((rc-t0)*(t0*tr-rc*(t0+tr)),2)*
((1-exp(-((t0+tr)*tz)/(t0*tr)))*pow(tr,2)+(-1+exp(-tz/t0))*pow(t0+tr,2)+(t0+tr)*tz));
}
else{
  fun+=
Q0*pow(rc+tr,2)*(-2.*tr*(dx+tr-tz)-exp(dx/tr)*(pow(dx,2)-2.*dx*tz+2.*tr*(tz-tr)))/
(2.*exp(((rc+tr)*(dx-tz))/(rc*tr))*pow(rc,2)*
(exp(tz/tr)*pow(rc+tr,2)+exp((1./rc+1./tr)*tz)*((rc+tr)*tz-rc*(rc+2*tr))-pow(tr,2)));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXPEXPUNDERSHOOT23(Double_t *xx, Double_t *par){

double Q0     = par[0]; // 
double dx     = xx[0]-par[1]; // 
double t0     = par[2]; // 
double tr     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-dx/rc); // 
if(dx<=0) fun=0;
else {
if(t0!=rc){
  fun+=Q0*rc*(tr+t0)*(exp_rc*rc/((rc-t0)*(rc*(tr+t0)-tr*t0))+exp(-dx/t0)/((t0-rc)*t0)+exp(-dx*(tr+t0)/(tr*t0))*tr/(t0*(rc*(tr+t0)-tr*t0)));
}
else{
  fun+=Q0*exp(-dx/rc)*(rc+tr)*(dx-tr*(1.-exp(-dx/tr)))/(rc*rc); 
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXP2TRCORR(Double_t *xx, Double_t *par){

//rozne czasy narastania dla si i csi

double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2]; // 
double Q3     = par[3]; // 
double x0     = par[4]; // 
double t0     = par[5]; // decay si0
double t1     = par[6]; // decay si1
double t2     = par[7]; // decay csi0
double t3     = par[8]*par[7]; // decay csi1
double tr1    = par[9]; // common si rise time
double tr2    = par[10]; // common csi rise time
double rc     = par[11]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t0!=tr1){
  fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr1))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr1))+exp(-(x-x0)/tr1)*tr1/((tr1-rc)*(tr1-t0)));
}
else{
  fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
if(t1!=tr1){
  fun+=Q1*rc*(exp_rc*rc/((rc-t1)*(rc-tr1))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-tr1))+exp(-(x-x0)/tr1)*tr1/((tr1-rc)*(tr1-t1)));
}
else{
  fun+=Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));
}
if(t2!=tr2){
  fun+=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-tr2))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-tr2))+exp(-(x-x0)/tr2)*tr2/((tr2-rc)*(tr2-t2)));
}
else{
  fun+=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
if(t3!=tr2){
  fun+=Q3*rc*(exp_rc*rc/((rc-t3)*(rc-tr2))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-tr2))+exp(-(x-x0)/tr2)*tr2/((tr2-rc)*(tr2-t3)));
}
else{
  fun+=Q3*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXP2TRCORR1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double tr     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t0!=tr){
  fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t0)));
}
else{
  fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
// //___________________________________________________________________
// ///////////////////////////////////////////////////////////////////////////////
// 
// double RC4DEXP2TR(Double_t *xx, Double_t *par){
// 
// //rozne czasy narastania dla si i csi
// 
// double x=xx[0];// 
// 
// double Q0     = par[0]; // 
// double Q1     = par[1]; // 
// double Q2     = par[2]; // 
// double Q3     = par[3]; // 
// double x0     = par[4]; // 
// double t0     = par[5]; // decay si0
// double t1     = par[6]; // decay si1
// double t2     = par[7]; // decay csi0
// double t3     = par[8]; // decay csi1
// double tr1    = par[9]; // common si rise time
// double tr2    = par[10]; // common csi rise time
// double rc     = par[11]; // 
// 
// // !!!!  Q0 is in fact Q0/C
// 
// zamienione t2 z tr2 !!!!!!!!!!!!!
// 
// 
// double fun = 0.; // 
// double exp_rc = exp(-(x-x0)/rc); // 
// if(x<=x0) fun=0;
// else {
// if(t0!=tr1){
//   fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr1))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr1))+exp(-(x-x0)/tr1)*tr1/((tr1-rc)*(tr1-t0)));
// }
// else{
//   fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
// }
// if(t1!=tr1){
//   fun+=Q1*rc*(exp_rc*rc/((rc-t1)*(rc-tr1))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-tr1))+exp(-(x-x0)/tr1)*tr1/((tr1-rc)*(tr1-t1)));
// }
// else{
//   fun+=Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));
// }
// if(t2!=tr2){
//   fun+=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-tr2))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-tr2))+exp(-(x-x0)/tr2)*tr2/((tr2-rc)*(tr2-t2)));
// }
// else{
//   fun+=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
// }
// if(t3!=t2){
//   fun+=Q3*rc*(exp_rc*rc/((rc-t3)*(rc-t2))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t2))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t3)));
// }
// else{
//   fun+=Q3*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
// }
// }
// 
// return fun;
// }
// 
// //___________________________________________________________________
// ///////////////////////////////////////////////////////////////////////////////
// 
// double RC4DEXP2TR1(Double_t *xx, Double_t *par){
// 
// 
// double x=xx[0];// 
// 
// double Q0     = par[0]; // 
// double x0     = par[1]; // 
// double t0     = par[2]; // 
// double tr     = par[3]; // 
// double rc     = par[4]; // 
// 
// // !!!!  Q0 is in fact Q0/C
// 
// double fun = 0.; // 
// double exp_rc = exp(-(x-x0)/rc); // 
// if(x<=x0) fun=0;
// else {
// if(t0!=tr){
//   fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t0)));
// }
// else{
//   fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
// }
// }
// 
// return fun;
// }
// 
// //___________________________________________________________________
// ///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXP3TR(Double_t *xx, Double_t *par){

//rozne czasy narastania dla si i csi

double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2]; // 
double Q3     = par[3]; // 
double x0     = par[4]; // 
double t0     = par[5]; // decay si0
double t1     = par[6]; // decay si1
double t2     = par[7]; // decay csi0
double t3     = par[8]; // decay csi1
double tr1    = par[9]; // common si rise time
double tr2    = par[10]; // common csi rise time
double tr3    = par[11]; // common csi rise time
double rc     = par[12]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t0!=tr1){
  fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr1))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr1))+exp(-(x-x0)/tr1)*tr1/((tr1-rc)*(tr1-t0)));
}
else{
  fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
if(t1!=tr1){
  fun+=Q1*rc*(exp_rc*rc/((rc-t1)*(rc-tr1))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-tr1))+exp(-(x-x0)/tr1)*tr1/((tr1-rc)*(tr1-t1)));
}
else{
  fun+=Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));
}
if(t2!=tr2){
  fun+=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-tr2))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-tr2))+exp(-(x-x0)/tr2)*tr2/((tr2-rc)*(tr2-t2)));
}
else{
  fun+=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
if(t3!=tr3){
  fun+=Q3*rc*(exp_rc*rc/((rc-t3)*(rc-tr3))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-tr3))+exp(-(x-x0)/tr3)*tr3/((tr3-rc)*(tr3-t3)));
}
else{
  fun+=Q3*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC4DEXP3TR1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double tr     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t0!=tr){
  fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-tr))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-tr))+exp(-(x-x0)/tr)*tr/((tr-rc)*(tr-t0)));
}
else{
  fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________

// see lukasik@nz21-27:~/math/burr/pa_pic_ok_novi.nb
double RCPULS(Double_t *xx, Double_t *par){
double x=xx[0]*10;// 10 ns

double Q0    = par[0]; // Q0 si
double x0    = par[1]*10; // t0
double cd    = par[2]; // detector C 200 pF
double rd    = par[3]; // detector R 17 kOhm
double c     = par[4]; // feedback C 1 pF
double r     = par[5]; // feedback R 10000 kOhm
double co    = par[6]; // output   C 5000 pF
double r2    = par[7]; // output   R 0.05 kOhm
double k     = par[8]; // volt. amplif. ~390
double tau   = par[9]; // input rise time 10-90%

double fun = 0.; // 
if(x<=x0) fun=0;
else{
double AA   = (cd*co+c*(cd+co))*r*r2*rd;
double BB   = cd*(r+r2)*rd+co*r2*(r+rd)+c*r*(r2+rd+k*rd);
double CC   = r+r2+rd+k*rd;
double DD   = c*r*r2*rd;
double EE   = (r2-k*r)*rd; 
double sig  = tau/2.1972245773362196;

double SDEL = sqrt(BB*BB-4.*AA*CC);

fun = Q0*(DD-EE*sig)/(2.*SDEL*sig*(AA+sig*(CC*sig-BB)))*(
exp(-(x-x0)/sig)*2.*SDEL*sig - 
exp(-(BB+SDEL)*(x-x0)/(2.*AA))*((SDEL-BB)*sig+2.*AA) - 
exp(-(BB-SDEL)*(x-x0)/(2.*AA))*((SDEL+BB)*sig-2.*AA));

}
return fun;
}



///////////////////////////////////////////////////////////////////////////////

// see lukasik@nz21-27:~/math/burr/pa_pic_ok_novi.nb
// output buffer added
double RCPULSWY(Double_t *xx, Double_t *par){
double x=xx[0]*10;// 10 ns

double Q0    = par[0]; // Q0 si
double x0    = par[1]*10; // t0
double cd    = par[2]; // detector C 200 pF
double rd    = par[3]; // detector R 17 kOhm
double c     = par[4]; // feedback C 1 pF
double r     = par[5]; // feedback R 10000 kOhm
double co    = par[6]; // output   C 5000 pF
double r2    = par[7]; // output   R 0.05 kOhm
double k     = par[8]; // volt. amplif. ~390
double tau   = par[9]; // input rise time 10-90% [ns]
double tau7  = par[10]; // output buffer time constant [ns]

double fun = 0.; // 
if(x<=x0) fun=0;
else{
double AA   = (cd*co+c*(cd+co))*r*r2*rd;
double BB   = cd*(r+r2)*rd+co*r2*(r+rd)+c*r*(r2+rd+k*rd);
double CC   = r+r2+rd+k*rd;
double DD   = c*r*r2*rd;
double EE   = (r2-k*r)*rd; 
double sig  = tau/2.1972245773362196;

double SDEL = sqrt(BB*BB-4.*AA*CC);

fun = -(Q0*(DD-EE*sig)*tau7/(2.*(AA+sig*(CC*sig-BB))))*
(2.*exp(-(x-x0)/sig)/(sig-2.*tau7)-
(exp(-((BB+SDEL)*(x-x0))/(2.*AA))*(BB+SDEL)*((SDEL-BB)*sig+2.*AA))/(2.*SDEL*sig*(AA-(BB+SDEL)*tau7))-
(exp(-((BB-SDEL)*(x-x0))/(2.*AA))*(BB-SDEL)*((SDEL+BB)*sig-2.*AA))/(2.*SDEL*sig*(AA-(BB-SDEL)*tau7))+
(exp(-((x-x0)/(2.*tau7)))*4.*AA*tau7*(AA-BB*sig+CC*sig*sig))/((2.*tau7-sig)*sig*(AA-(BB-SDEL)*tau7)*(AA-(BB+SDEL)*tau7))
);
}
return fun;
}

///////////////////////////////////////////////////////////////////////////////

// see lukasik@nz21-27:~/math/burr/pa_pic_ok_novi.nb
// output buffer added
double RCPULSERF(Double_t *xx, Double_t *par){
double x=xx[0]*10;// 10 ns

double Q0    = par[0]; // Q0 si
double x0    = par[1]*10; // t0
double cd    = par[2]; // detector C 200 pF
double rd    = par[3]; // detector R 17 kOhm
double c     = par[4]; // feedback C 1 pF
double r     = par[5]; // feedback R 10000 kOhm
double co    = par[6]; // output   C 5000 pF
double r2    = par[7]; // output   R 0.05 kOhm
double k     = par[8]; // volt. amplif. ~390
double tau   = par[9]; // input rise time 10-90% [ns]

double fun = 0.; // 
if(x<=x0) fun=0;
else{
double AA   = (cd*co+c*(cd+co))*r*r2*rd;
double BB   = cd*(r+r2)*rd+co*r2*(r+rd)+c*r*(r2+rd+k*rd);
double CC   = r+r2+rd+k*rd;
double DD   = c*r*r2*rd;
double EE   = (r2-k*r)*rd; 
double sig  = tau/2.1972245773362196;

double SDEL = sqrt(BB*BB-4.*AA*CC);

fun = 
(Q0*(exp((pow(BB,2)*pow(sig,2)-2*AA*CC*pow(sig,2)+BB*SDEL*pow(sig,2)-4*AA*BB*(x-x0)-
4*AA*SDEL*(x-x0))/(
8*pow(AA,2)))*(BB*pow(sig,2)-SDEL*pow(sig,2)-
4*AA*(x-x0))*((-BB*DD+2*AA*EE-DD*SDEL)*(BB*pow(sig,2)+
SDEL*pow(sig,2)-4*AA*(x-x0))+
2*(pow(BB,2)*DD*pow(sig,2)+
AA*(-2*CC*DD*pow(sig,2)-EE*SDEL*pow(sig,2)+4*AA*EE*(x-x0)-
2*DD*SDEL*(x-x0))+
BB*(DD*SDEL*pow(sig,2)-AA*(EE*pow(sig,2)+2*DD*(x-x0))))*TMath::Erf((
BB*pow(sig,2)+SDEL*pow(sig,2)-4*AA*(x-x0))/(4*AA*sig)))+
exp((pow(BB,2)*pow(sig,2)-2*AA*CC*pow(sig,2)-BB*SDEL*pow(sig,2)-4*AA*BB*(x-x0)+
4*AA*SDEL*(x-x0))/(
8*pow(AA,2)))*(BB*pow(sig,2)+SDEL*pow(sig,2)-
4*AA*(x-x0))*((BB*DD-2*AA*EE-DD*SDEL)*(BB*pow(sig,2)-SDEL*pow(sig,2)-
4*AA*(x-x0))+
2*(pow(BB,2)*DD*pow(sig,2)-
BB*(AA*EE*pow(sig,2)+DD*SDEL*pow(sig,2)+2*AA*DD*(x-x0))+
AA*(-2*CC*DD*pow(sig,2)+EE*SDEL*pow(sig,2)+4*AA*EE*(x-x0)+
2*DD*SDEL*(x-x0)))*TMath::Erf(((-BB+SDEL)*sig)/(4*AA)+(x-x0)/
sig))))/(16*pow(AA,2)*SDEL*(CC*pow(sig,4)-2*BB*pow(sig,2)*(x-x0)+4*AA*pow((x-x0),2)))
;
}
return fun;
}


///////////////////////////////////////////////////////////////////////////////

// see lukasik@nz21-27:~/math/burr/pa_pic_ok_novi_erf.nb
// output buffer added
double RCPULSERFWY(Double_t *xx, Double_t *par){
double x=xx[0]*10;// 10 ns

double Q0    = par[0]; // Q0 si
double x0    = par[1]*10; // t0
double cd    = par[2]; // detector C 200 pF
double rd    = par[3]; // detector R 17 kOhm
double c     = par[4]; // feedback C 1 pF
double r     = par[5]; // feedback R 10000 kOhm
double co    = par[6]; // output   C 5000 pF
double r2    = par[7]; // output   R 0.05 kOhm
double k     = par[8]; // volt. amplif. ~390
double tau   = par[9]; // input rise time 10-90% [ns]
double tau7  = par[10]; // output buffer time constant [ns]

double fun = 0.; // 
if(x<=x0) fun=0;
else{
double AA   = (cd*co+c*(cd+co))*r*r2*rd;
double BB   = cd*(r+r2)*rd+co*r2*(r+rd)+c*r*(r2+rd+k*rd);
double CC   = r+r2+rd+k*rd;
double DD   = c*r*r2*rd;
double EE   = (r2-k*r)*rd; 
double sig  = tau/2.1972245773362196;

double SDEL = sqrt(BB*BB-4.*AA*CC);

fun = 
Q0*(
(exp((pow(BB,2)*pow(sig,2)-2*AA*CC*pow(sig,2)+BB*SDEL*pow(sig,2)-4*AA*BB*(x-x0)-4*AA*SDEL*(x-x0))/(8*pow(AA,2)))*
tau7*(2*CC*DD*SDEL*tau7-pow(BB,2)*DD+AA*(EE*SDEL+2*CC*DD-4*CC*EE*tau7)+BB*(AA*EE-DD*(SDEL-2*CC*tau7)))*
(TMath::Erf((SDEL+BB)*sig/(4*AA)-(x-x0)/sig)-1))/(4*AA*SDEL*(AA-2*tau7*(BB-2*CC*tau7)))-
(exp((pow(BB,2)*pow(sig,2)-2*AA*CC*pow(sig,2)-BB*SDEL*pow(sig,2)-4*AA*BB*(x-x0)+4*AA*SDEL*(x-x0))/(8*pow(AA,2)))*
tau7*(2*CC*DD*SDEL*tau7+pow(BB,2)*DD+AA*(EE*SDEL-2*CC*DD+4*CC*EE*tau7)-BB*(AA*EE+DD*(SDEL+2*CC*tau7)))*
(TMath::Erf((SDEL-BB)*sig/(4*AA)+(x-x0)/sig)+1))/(4*AA*SDEL*(AA-2*tau7*(BB-2*CC*tau7)))-
(exp((pow(sig,2)-8*(x-x0)*tau7)/(16*pow(tau7,2)))*(DD-2*EE*tau7)*
(1+TMath::Erf((x-x0)/sig-sig/(4*tau7))))/(4*(AA-2*tau7*(BB-2*CC*tau7))))
;
}
return fun;
}

///////////////////////////////////////////////////////////////////////////////

// see lukasik@nz21-27:~/math/burr/pa_pic_ok_novi_dexp.nb
// output buffer added
// see RC4DEXP2TR

double RC4DEXP2TR_PAWY(Double_t *xx, Double_t *par){
double x=xx[0];// 10 ns

double Q0    = par[0]; // Q0 si
double Q1    = par[1]; // Q1 si
double Q2    = par[2]; // Q2 csi
double Q3    = par[3]; // Q3 csi
double x0    = par[4]; // t0
double t0    = par[5]; // decay si0
double t1    = par[6]; // decay si1
double t2    = par[7]; // decay csi0
double t3    = par[8]; // decay csi1
double tr1   = par[9]; // common si rise time
double tr2   = par[10]; // common csi rise time

double cd    = par[11]; // detector C 200 pF
double rd    = par[12]; // detector R 17 kOhm
double c     = par[13]; // feedback C 1 pF
double r     = par[14]; // feedback R 10000 kOhm
double co    = par[15]; // output   C 5000 pF
double r2    = par[16]; // output   R 0.05 kOhm
double k     = par[17]; // volt. amplif. ~390
double tau7  = par[18]; // output buffer time constant [ns]

double fun = 0.; // 
if(x<=x0) fun=0;
else{
double AA   = (cd*co+c*(cd+co))*r*r2*rd;
double BB   = cd*(r+r2)*rd+co*r2*(r+rd)+c*r*(r2+rd+k*rd);
double CC   = r+r2+rd+k*rd;
double DD   = c*r*r2*rd;
double EE   = (r2-k*r)*rd; 
double SDEL = sqrt(BB*BB-4.*AA*CC);

fun += 
0.5*Q0*tau7*(
 (exp((-x+x0)/t0)*t0*(DD-10*EE*t0))/((t0-tr1)*(AA+10*t0*(10*CC*t0-BB))*(5*t0-tau7))
-(exp((-x+x0)/tr1)*tr1*(DD-10*EE*tr1))/((t0-tr1)*(AA+10*tr1*(10*CC*tr1-BB))*(5*tr1-tau7))
+(AA*exp(-(5*(BB-SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t0*tr1+DD*(10*CC*(t0+tr1)+SDEL))+AA*(2*CC*(DD-10*EE*(t0+tr1))-EE*SDEL)-10*CC*(DD*(SDEL*(t0+tr1)+20*CC*t0*tr1)-10*EE*SDEL*t0*tr1)))
/((AA+10*t0*(10*CC*t0-BB))*(AA+10*tr1*(10*CC*tr1-BB))*(BB*(SDEL-BB)*tau7-AA*(SDEL-4*CC*tau7)))
-(AA*exp(-(5*(BB+SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t0*tr1+DD*(10*CC*(t0+tr1)-SDEL))+AA*(2*CC*(DD-10*EE*(t0+tr1))+EE*SDEL)+10*CC*(DD*(SDEL*(t0+tr1)-20*CC*t0*tr1)-10*EE*SDEL*t0*tr1)))
/((AA+10*t0*(10*CC*t0-BB))*(AA+10*tr1*(10*CC*tr1-BB))*(BB*(SDEL+BB)*tau7-AA*(SDEL+4*CC*tau7)))
+(exp(-((5*(x-x0))/tau7))*tau7*(DD-2*EE*tau7))/((tau7-5*t0)*(tau7-5*tr1)*(AA-2*tau7*(BB-2*CC*tau7))));

fun += 
0.5*Q1*tau7*(
 (exp((-x+x0)/t1)*t1*(DD-10*EE*t1))/((t1-tr1)*(AA+10*t1*(10*CC*t1-BB))*(5*t1-tau7))
-(exp((-x+x0)/tr1)*tr1*(DD-10*EE*tr1))/((t1-tr1)*(AA+10*tr1*(10*CC*tr1-BB))*(5*tr1-tau7))
+(AA*exp(-(5*(BB-SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t1*tr1+DD*(10*CC*(t1+tr1)+SDEL))+AA*(2*CC*(DD-10*EE*(t1+tr1))-EE*SDEL)-10*CC*(DD*(SDEL*(t1+tr1)+20*CC*t1*tr1)-10*EE*SDEL*t1*tr1)))
/((AA+10*t1*(10*CC*t1-BB))*(AA+10*tr1*(10*CC*tr1-BB))*(BB*(SDEL-BB)*tau7-AA*(SDEL-4*CC*tau7)))
-(AA*exp(-(5*(BB+SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t1*tr1+DD*(10*CC*(t1+tr1)-SDEL))+AA*(2*CC*(DD-10*EE*(t1+tr1))+EE*SDEL)+10*CC*(DD*(SDEL*(t1+tr1)-20*CC*t1*tr1)-10*EE*SDEL*t1*tr1)))
/((AA+10*t1*(10*CC*t1-BB))*(AA+10*tr1*(10*CC*tr1-BB))*(BB*(SDEL+BB)*tau7-AA*(SDEL+4*CC*tau7)))
+(exp(-((5*(x-x0))/tau7))*tau7*(DD-2*EE*tau7))/((tau7-5*t1)*(tau7-5*tr1)*(AA-2*tau7*(BB-2*CC*tau7))));

fun += 
0.5*Q2*tau7*(
 (exp((-x+x0)/t2)*t2*(DD-10*EE*t2))/((t2-tr2)*(AA+10*t2*(10*CC*t2-BB))*(5*t2-tau7))
-(exp((-x+x0)/tr2)*tr2*(DD-10*EE*tr2))/((t2-tr2)*(AA+10*tr2*(10*CC*tr2-BB))*(5*tr2-tau7))
+(AA*exp(-(5*(BB-SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t2*tr2+DD*(10*CC*(t2+tr2)+SDEL))+AA*(2*CC*(DD-10*EE*(t2+tr2))-EE*SDEL)-10*CC*(DD*(SDEL*(t2+tr2)+20*CC*t2*tr2)-10*EE*SDEL*t2*tr2)))
/((AA+10*t2*(10*CC*t2-BB))*(AA+10*tr2*(10*CC*tr2-BB))*(BB*(SDEL-BB)*tau7-AA*(SDEL-4*CC*tau7)))
-(AA*exp(-(5*(BB+SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t2*tr2+DD*(10*CC*(t2+tr2)-SDEL))+AA*(2*CC*(DD-10*EE*(t2+tr2))+EE*SDEL)+10*CC*(DD*(SDEL*(t2+tr2)-20*CC*t2*tr2)-10*EE*SDEL*t2*tr2)))
/((AA+10*t2*(10*CC*t2-BB))*(AA+10*tr2*(10*CC*tr2-BB))*(BB*(SDEL+BB)*tau7-AA*(SDEL+4*CC*tau7)))
+(exp(-((5*(x-x0))/tau7))*tau7*(DD-2*EE*tau7))/((tau7-5*t2)*(tau7-5*tr2)*(AA-2*tau7*(BB-2*CC*tau7))));

fun += 
0.5*Q3*tau7*(
 (exp((-x+x0)/t3)*t3*(DD-10*EE*t3))/((t3-tr2)*(AA+10*t3*(10*CC*t3-BB))*(5*t3-tau7))
-(exp((-x+x0)/tr2)*tr2*(DD-10*EE*tr2))/((t3-tr2)*(AA+10*tr2*(10*CC*tr2-BB))*(5*tr2-tau7))
+(AA*exp(-(5*(BB-SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t3*tr2+DD*(10*CC*(t3+tr2)+SDEL))+AA*(2*CC*(DD-10*EE*(t3+tr2))-EE*SDEL)-10*CC*(DD*(SDEL*(t3+tr2)+20*CC*t3*tr2)-10*EE*SDEL*t3*tr2)))
/((AA+10*t3*(10*CC*t3-BB))*(AA+10*tr2*(10*CC*tr2-BB))*(BB*(SDEL-BB)*tau7-AA*(SDEL-4*CC*tau7)))
-(AA*exp(-(5*(BB+SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t3*tr2+DD*(10*CC*(t3+tr2)-SDEL))+AA*(2*CC*(DD-10*EE*(t3+tr2))+EE*SDEL)+10*CC*(DD*(SDEL*(t3+tr2)-20*CC*t3*tr2)-10*EE*SDEL*t3*tr2)))
/((AA+10*t3*(10*CC*t3-BB))*(AA+10*tr2*(10*CC*tr2-BB))*(BB*(SDEL+BB)*tau7-AA*(SDEL+4*CC*tau7)))
+(exp(-((5*(x-x0))/tau7))*tau7*(DD-2*EE*tau7))/((tau7-5*t3)*(tau7-5*tr2)*(AA-2*tau7*(BB-2*CC*tau7))));



}

// 0.5*Q0*tau7*(
//  (2*exp(-((x-x0)/t0))*t0*(DD-EE*t0))/((t0-t1)*(AA+t0*(CC*t0-BB))*(t0-2*tau7))
// -(2*exp(-((x-x0)/t1))*t1*(DD-EE*t1))/((t0-t1)*(AA+t1*(CC*t1-BB))*(t1-2*tau7))
// +(AA*exp(-((BB-SDEL)*(x-x0))/(2*AA))*(-BB^2*DD+BB*(AA*EE+CC*EE*t0*t1+DD*(CC*(t0+t1)+SDEL))+AA*(2*CC*(DD-EE*(t0+t1))-EE*SDEL)-CC*(DD*(SDEL*(t0+t1)+2*CC*t0*t1)-EE*SDEL*t0*t1)))
// /((AA+t0*(CC*t0-BB))*(AA+t1*(CC*t1-BB))*(BB*(SDEL-BB)*tau7-AA*(SDEL-4*CC*tau7)))
// -(AA*exp(-((BB+SDEL)*(x-x0))/(2*AA))*(-BB^2*DD+BB*(AA*EE+CC*EE*t0*t1+DD*(CC*(t0+t1)-SDEL))+AA*(2*CC*(DD-EE*(t0+t1))+EE*SDEL)+CC*(DD*(SDEL*(t0+t1)-2*CC*t0*t1)-EE*SDEL*t0*t1)))
// /((AA+t0*(CC*t0-BB))*(AA+t1*(CC*t1-BB))*(BB*(SDEL+BB)*tau7-AA*(SDEL+4*CC*tau7)))
// +(4*exp(-((x-x0)/(2*tau7)))*tau7*(DD-2*EE*tau7))/((t0-2*tau7)*(t1-2*tau7)*(AA-2*tau7*(BB-2*CC*tau7))));

return -fun;
}



///////////////////////////////////////////////////////////////////////////////

// see lukasik@nz21-27:~/math/burr/pa_pic_ok_novi_dexp.nb
// output buffer added
// see RC4DEXP2TR

double RC4DEXP2TR_PAWY1(Double_t *xx, Double_t *par){
double x=xx[0];// 10 ns

double Q0    = par[0]; // Q0 si
double x0    = par[1]; // t0
double t0    = par[2]; // decay si0
double tr1   = par[3]; // common si rise time

double cd    = par[4]; // detector C 200 pF
double rd    = par[5]; // detector R 17 kOhm
double c     = par[6]; // feedback C 1 pF
double r     = par[7]; // feedback R 10000 kOhm
double co    = par[8]; // output   C 5000 pF
double r2    = par[9]; // output   R 0.05 kOhm
double k     = par[10]; // volt. amplif. ~390
double tau7  = par[11]; // output buffer time constant [ns]
		
double fun = 0.; // 
if(x<=x0) fun=0;
else{
double AA   = (cd*co+c*(cd+co))*r*r2*rd;
double BB   = cd*(r+r2)*rd+co*r2*(r+rd)+c*r*(r2+rd+k*rd);
double CC   = r+r2+rd+k*rd;
double DD   = c*r*r2*rd;
double EE   = (r2-k*r)*rd; 
double SDEL = sqrt(BB*BB-4.*AA*CC);

fun += 
0.5*Q0*tau7*(
 (exp((-x+x0)/t0)*t0*(DD-10*EE*t0))/((t0-tr1)*(AA+10*t0*(10*CC*t0-BB))*(5*t0-tau7))
-(exp((-x+x0)/tr1)*tr1*(DD-10*EE*tr1))/((t0-tr1)*(AA+10*tr1*(10*CC*tr1-BB))*(5*tr1-tau7))
+(AA*exp(-(5*(BB-SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t0*tr1+DD*(10*CC*(t0+tr1)+SDEL))+AA*(2*CC*(DD-10*EE*(t0+tr1))-EE*SDEL)-10*CC*(DD*(SDEL*(t0+tr1)+20*CC*t0*tr1)-10*EE*SDEL*t0*tr1)))
/((AA+10*t0*(10*CC*t0-BB))*(AA+10*tr1*(10*CC*tr1-BB))*(BB*(SDEL-BB)*tau7-AA*(SDEL-4*CC*tau7)))
-(AA*exp(-(5*(BB+SDEL)*(x-x0))/AA)*(-BB*BB*DD+BB*(AA*EE+100*CC*EE*t0*tr1+DD*(10*CC*(t0+tr1)-SDEL))+AA*(2*CC*(DD-10*EE*(t0+tr1))+EE*SDEL)+10*CC*(DD*(SDEL*(t0+tr1)-20*CC*t0*tr1)-10*EE*SDEL*t0*tr1)))
/((AA+10*t0*(10*CC*t0-BB))*(AA+10*tr1*(10*CC*tr1-BB))*(BB*(SDEL+BB)*tau7-AA*(SDEL+4*CC*tau7)))
+(exp(-((5*(x-x0))/tau7))*tau7*(DD-2*EE*tau7))/((tau7-5*t0)*(tau7-5*tr1)*(AA-2*tau7*(BB-2*CC*tau7))));


}

// 0.5*Q0*tau7*(
//  (2*exp(-((x-x0)/t0))*t0*(DD-EE*t0))/((t0-t1)*(AA+t0*(CC*t0-BB))*(t0-2*tau7))
// -(2*exp(-((x-x0)/t1))*t1*(DD-EE*t1))/((t0-t1)*(AA+t1*(CC*t1-BB))*(t1-2*tau7))
// +(AA*exp(-((BB-SDEL)*(x-x0))/(2*AA))*(-BB^2*DD+BB*(AA*EE+CC*EE*t0*t1+DD*(CC*(t0+t1)+SDEL))+AA*(2*CC*(DD-EE*(t0+t1))-EE*SDEL)-CC*(DD*(SDEL*(t0+t1)+2*CC*t0*t1)-EE*SDEL*t0*t1)))
// /((AA+t0*(CC*t0-BB))*(AA+t1*(CC*t1-BB))*(BB*(SDEL-BB)*tau7-AA*(SDEL-4*CC*tau7)))
// -(AA*exp(-((BB+SDEL)*(x-x0))/(2*AA))*(-BB^2*DD+BB*(AA*EE+CC*EE*t0*t1+DD*(CC*(t0+t1)-SDEL))+AA*(2*CC*(DD-EE*(t0+t1))+EE*SDEL)+CC*(DD*(SDEL*(t0+t1)-2*CC*t0*t1)-EE*SDEL*t0*t1)))
// /((AA+t0*(CC*t0-BB))*(AA+t1*(CC*t1-BB))*(BB*(SDEL+BB)*tau7-AA*(SDEL+4*CC*tau7)))
// +(4*exp(-((x-x0)/(2*tau7)))*tau7*(DD-2*EE*tau7))/((t0-2*tau7)*(t1-2*tau7)*(AA-2*tau7*(BB-2*CC*tau7))));

return -fun;
}



///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////

double RCRC1(Double_t *xx, Double_t *par){
double x=xx[0];// 

double Q0     = par[0]; // Q0 si
double x0     = par[1]; // t0
double rc1    = par[2]; // rc1 rise
double rc     = par[3]; // rc decay

double fun = 0.; // 
if(x<=x0) fun=0;
else{
fun = Q0*(exp(-(x-x0)/rc)-exp(-(x-x0)/rc1))/(rc-rc1);
}
return fun;
}

///////////////////////////////////////////////////////////////////////////////

double RC3GAM2DEXP13(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // Q0 si
double Q1     = par[1]; // Q1 si
double Q2     = par[2]; // Q2 si
double Q3     = par[3]; // Q csi fast
double Q4     = par[4]; // Q csi slow
double x0     = par[5]; // t0
double t0     = par[6]; // tau0 si
double t1     = par[7]; // tau1 si
double t2     = par[8]; // tau2 si
double t3     = par[9]; // common CSI rise time
double t4     = par[10]; // CSI fast
double t5     = par[11]; // CSI slow
double rc     = par[12]; // rc

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));

// Q0*rc*sqrt((x-x0)/t0)*(-((exp(-((x-x0)/(2.*t0)))*sqrt(0.636619772368))/(rc-2.*t0))+
// (exp(-((x-x0)/rc))*sqrt(rc*t0)*TMath::Erf(sqrt((x-x0)*(rc-2.*t0)/(2*rc*t0))))/
// (sqrt((x-x0))*pow(rc-2.*t0,1.5)))+
// Q1*rc*sqrt((x-x0)/t1)*(-((exp(-((x-x0)/(2.*t1)))*sqrt(0.636619772368))/(rc-2.*t1))+
// (exp(-((x-x0)/rc))*sqrt(rc*t1)*TMath::Erf(sqrt((x-x0)*(rc-2.*t1)/(2*rc*t1))))/
// (sqrt((x-x0))*pow(rc-2.*t1,1.5)))+
// Q2*rc*sqrt((x-x0)/t2)*(-((exp(-((x-x0)/(2.*t2)))*sqrt(0.636619772368))/(rc-2.*t2))+
// (exp(-((x-x0)/rc))*sqrt(rc*t2)*TMath::Erf(sqrt((x-x0)*(rc-2.*t2)/(2*rc*t2))))/
// (sqrt((x-x0))*pow(rc-2.*t2,1.5)));

if(t3!=t4){
fun+=Q3*rc*(exp_rc*rc/((rc-t3)*(rc-t4))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t4))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t3)));
}
else{
fun+=Q3*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
}
if(t3!=t5){
fun+=Q4*rc*(exp_rc*rc/((rc-t3)*(rc-t5))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t5))+exp(-(x-x0)/t5)*t5/((t5-rc)*(t5-t3)));
}
else{
fun+=Q4*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
}
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RC3GAM2DEXP130(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // Q0 si
double x0     = par[1]; // t0
double t0     = par[2]; // tau0 si
double rc     = par[3]; // rc

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
//Q0*rc*sqrt((x-x0)/t0)*(-((exp(-((x-x0)/(2.*t0)))*sqrt(0.636619772368))/(rc-2.*t0))+
//(exp(-((x-x0)/rc))*sqrt(rc*t0)*TMath::Erf(sqrt((x-x0)*(rc-2.*t0)/(2*rc*t0))))/
//(sqrt((x-x0))*pow(rc-2.*t0,1.5)));

//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RC3GAM2DEXP131(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // Q1 si
double x0     = par[1]; // t0
double t1     = par[2]; // tau1 si
double rc     = par[3]; //  rc

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
fun = 
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));

//Q1*rc*sqrt((x-x0)/t1)*(-((exp(-((x-x0)/(2.*t1)))*sqrt(0.636619772368))/(rc-2.*t1))+
//(exp(-((x-x0)/rc))*sqrt(rc*t1)*TMath::Erf(sqrt((x-x0)*(rc-2.*t1)/(2*rc*t1))))/
//(sqrt((x-x0))*pow(rc-2.*t1,1.5)));

//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RC3GAM2DEXP132(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0]; // Q2 si
double x0     = par[1]; // t0
double t2     = par[2]; // tau2 si
double rc     = par[3]; //  rc

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
fun = 
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));

//Q2*rc*sqrt((x-x0)/t2)*(-((exp(-((x-x0)/(2.*t2)))*sqrt(0.636619772368))/(rc-2.*t2))+
//(exp(-((x-x0)/rc))*sqrt(rc*t2)*TMath::Erf(sqrt((x-x0)*(rc-2.*t2)/(2*rc*t2))))/
//(sqrt((x-x0))*pow(rc-2.*t2,1.5)));

//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RC3GAM2DEXP133(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q3     = par[0]; // Q csi fast
double x0     = par[1]; // t0
double t3     = par[2]; // common CSI rise time
double t4     = par[3]; // CSI fast
double rc     = par[4]; //  rc

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
if(t3!=t4){
fun=Q3*rc*(exp_rc*rc/((rc-t3)*(rc-t4))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t4))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t3)));
}
else{
fun=Q3*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
}
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RC3GAM2DEXP134(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q4     = par[0]; // Q csi slow
double x0     = par[1]; // t0
double t3     = par[2]; // common CSI rise time
double t5     = par[3]; // CSI slow
double rc     = par[4]; //  rc

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
if(t3!=t5){
fun=Q4*rc*(exp_rc*rc/((rc-t3)*(rc-t5))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t5))+exp(-(x-x0)/t5)*t5/((t5-rc)*(t5-t3)));
}
else{
fun=Q4*rc*(exp_rc*rc*t3-exp(-(x-x0)/t3)*(rc*(x-x0+t3)-(x-x0)*t3))/(t3*pow(rc-t3,2));
}
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

double RC3GAM2DEXP13ISI1(Double_t *xx, Double_t *par){
//current pulse

double x=xx[0];// 

double Q0     = par[0]; // Q0 si
double t0     = par[1]; // tau0 si

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
if(x<=0) fun=0;
else{
fun = Q0*x*exp(-(x/t0))/(t0*t0);
}
return fun;
}

double RC3GAM2DEXP13ISI2(Double_t *xx, Double_t *par){
//current pulse

double x=xx[0];// 

double Q0     = par[0]; // Q0 si
double t0     = par[1]; // tau0 si
double Q1     = par[2]; // Q0 si
double t1     = par[3]; // tau0 si

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
if(x<=0) fun=0;
else{
fun = Q0*x*exp(-(x/t0))/(t0*t0)
    + Q1*x*exp(-(x/t1))/(t1*t1);
}
return fun;
}

double RC3GAM2DEXP13ISI3(Double_t *xx, Double_t *par){
//current pulse

double x=xx[0];// 

double Q0     = par[0]; // Q0 si
double t0     = par[1]; // tau0 si
double Q1     = par[2]; // Q0 si
double t1     = par[3]; // tau0 si
double Q2     = par[4]; // Q0 si
double t2     = par[5]; // tau0 si

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
if(x<=0) fun=0;
else{
fun = Q0*x*exp(-(x/t0))/(t0*t0)
    + Q1*x*exp(-(x/t1))/(t1*t1)
    + Q2*x*exp(-(x/t2))/(t2*t2);
}
return fun;
}


double RC3GAM2DEXP13ICSI(Double_t *xx, Double_t *par){
//current pulse

double x=xx[0];// 

double Q3     = par[0]; // Q csi fast
double Q4     = par[1]; // Q csi slow
double t3     = par[2]; // common CSI rise time
double t4     = par[3]; // CSI fast
double t5     = par[4]; // CSI slow

// !!!!  Q0 is in fact Q0/C
double fun = 0.; // 
if(x<=0) fun=0;
else{
fun = Q3/(t4-t3)*(exp(-x/t4)-exp(-x/t3))+Q4/(t5-t3)*(exp(-x/t5)-exp(-x/t3));
}
return fun;
}

//___________________________________________________________________

double RC3GAM2DEXP13ISIDIFF(Double_t *xx, Double_t *par){
//a part of current pulse 1st derivative for finding the mode
//in RC3GAM2DEXP13ISIDIFF(mode)=0

double x=xx[0];// 

double Q0     = par[0]; // Q0 si
double Q1     = par[1]; // Q1 si
double Q2     = par[2]; // Q2 si
double t0     = par[3]; // tau0 si
double t1     = par[4]; // tau1 si
double t2     = par[5]; // tau2 si

// !!!!  Q0 is in fact Q0/C
double fun = 0.; // 
if(x<=0) fun=0;
else{
fun = 
exp(-(x/t0))*Q0*pow(t1*t2,3)*(x-t0)+ 
exp(-(x/t1))*Q1*pow(t0*t2,3)*(x-t1)+ 
exp(-(x/t2))*Q2*pow(t0*t1,3)*(x-t2);
}
return fun;
}
//___________________________________________________________________
//___________________________________________________________________

double RC3GAM2DEXP13ICSIDIFF(Double_t *xx, Double_t *par){
//a part of current pulse 1st derivative for fast+slow 
//csi for finding the mode of current pulse 
//using RC3GAM2DEXP13ICSIDIFF(mode)=0

double x=xx[0];// 

double Q3     = par[0]; // Q csi fast
double Q4     = par[1]; // Q csi slow
double t3     = par[2]; // common CSI rise time
double t4     = par[3]; // CSI fast
double t5     = par[4]; // CSI slow

// !!!!  Q0 is in fact Q0/C
double fun = 0.; // 
if(x<=0) fun=0;
else{
fun = 
exp(-x/t5)*Q4*t3*(t3-t4)*t4+
exp(-x/t4)*Q3*t3*(t3-t5)*t5+
exp(-x/t3)*t4*t5*(Q4*(t4-t3)+Q3*(t5-t3));
}
return fun;
}
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCDEXP10(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // common CSI rise time
double t3     = par[7]; // CSI fast
double t4     = par[8]; // CSI slow
double rc     = par[9]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
if(t0!=t1){
fun+=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-t1))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-t1))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-t0)));
}
else{
fun+=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
if(t2!=t3){
fun+=Q1*rc*(exp_rc*rc/((rc-t2)*(rc-t3))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t3))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t2)));
}
else{
fun+=Q1*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
if(t2!=t4){
fun+=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-t4))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t4))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t2)));
}
else{
fun+=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCDEXP100(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double t1     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
if(t0!=t1){
fun=Q0*rc*(exp_rc*rc/((rc-t0)*(rc-t1))+exp(-(x-x0)/t0)*t0/((t0-rc)*(t0-t1))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-t0)));
}
else{
fun=Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
}
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCDEXP101(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t2     = par[2]; // common CSI rise time
double t3     = par[3]; // CSI fast
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
if(t2!=t3){
fun=Q1*rc*(exp_rc*rc/((rc-t2)*(rc-t3))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t3))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t2)));
}
else{
fun=Q1*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCDEXP102(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // common CSI rise time
double t4     = par[3]; // CSI slow
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
if(t2!=t4){
fun=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-t4))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t4))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t2)));
}
else{
fun=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////





// ///////////////////////////////////////////////////////////////////////////////
// 
// double gamma2(Double_t *xx, Double_t *par){
// 
// 
// double x=xx[0];// 
// double x1     = par[0]; // 
// double x2     = par[1]; // 
// double tau    = par[2]; // 
// double sqr    = sqrt(tau*tau+x2*x2);
// double norm   = 2./(exp(-((tau+x2-sqr)/tau))*(tau-sqr));
// double amp    = par[3]*norm; // 
// 
// double fun = 0.; // 
// if(x<=x1) return fun;
// fun = amp*((x-x1)*(x-x1-x2)/tau)*exp(-2.*(x-x1)/tau);
// 
// return fun;
// }
// //___________________________________________________________________
// ///////////////////////////////////////////////////////////////////////////////

double gamma2(Double_t *xx, Double_t *par){


double x=xx[0];// 
double x1     = par[0]; // 
double tau    = par[1]; // 
double amp    = par[2];

double fun = 0.; // 
if(x<=x1) return fun;
// fun = amp*pow((x-x1)/(n*tau),n)*exp(n*(1-(x-x1)/(n*tau)));
fun = amp*pow((x-x1)/tau,2.)*exp(2.*(1.-(x-x1)/tau));

return fun;
}

///////////////////////////////////////////////////////////////////////////////

double gamman(Double_t *xx, Double_t *par){


double x=xx[0];// 
double x1     = par[0]; // 
double tau    = par[1]; // 
double n      = par[2];
double amp    = par[3]; // 

double fun = 0.; // 
if(x<=x1) return fun;
// fun = amp*pow((x-x1)/(n*tau),n)*exp(n*(1-(x-x1)/(n*tau)));
// fun = amp*pow((x-x1)/tau,n)*exp(n*(1-(x-x1)/tau));
fun = amp/tau*pow(n*(x-x1)/tau,n)*exp((-n*(x-x1)/tau))/TMath::Gamma(n);

return fun;
}

///////////////////////////////////////////////////////////////////////////////

double Burr(Double_t *xx, Double_t *par){


double x=xx[0];// 
double x1     = par[0]; // 
double tau    = par[1]; // 
double c      = par[2];
double k      = par[3];
double amp    = par[4]; // 

double fun = 0.; // 
if(x<=x1) return fun;
fun = amp*c*k*pow((x-x1)/tau,c-1)/(tau*pow(1+pow((x-x1)/tau,c),k+1));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////

double GNB(Double_t *xx, Double_t *par){


double x=xx[0];// 

double x1     = par[0]; // 
double tau1   = par[1]; // 
double n      = par[2];
double amp    = par[3]; // 

double fun = 0.; // 
double fun1 = 0.; // 
if(x<=x1) fun1=0;
else fun1 = amp*pow((x-x1)/tau1,n)*exp(n*(1-(x-x1)/tau1));

double x2     = par[4]; // 
double tau2   = par[5]; // 
double c      = par[6];
double k      = par[7];
double surf   = par[8]; // 

double fun2 = 0.; // 
if(x<=x2) fun2=0;
else fun2 = surf*c*k*pow((x-x2)/tau2,c-1)/(tau2*pow(1+pow((x-x2)/tau2,c),k+1));

fun = fun1+fun2;
return fun;
}


///////////////////////////////////////////////////////////////////////////////

double RC8INT(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 

double fun = 0.; // 
if(x<=x0) fun=0;
else fun = ((1-exp(-((x-x0)/t0)))*Q0*t0*(t0-2*rc))/pow(t0-rc,2) +  
(1-exp(-((x-x0)/t1)))*Q1*t1/(t1-rc) + 
(1-exp(-((x-x0)/t2)))*Q2*t2/(t2-rc) + 
(1-exp(-((x-x0)/rc)))*rc*((Q0*rc)/pow(t0-rc,2) - Q1/(t1-rc) - Q2/(t2-rc)) -  
(exp(-((x-x0)/t0))*Q0*(x-x0))/(t0-rc);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RC10(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double rc1    = par[8]; // 
double rc2    = par[9]; // 

// !!!!  Q0 is in fact Q0/C
// here n=1 compared to RC11

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
Q1*rc*( rc*exp_rc/((rc - rc1)*(rc - t1)) + 
       rc1*exp(-(x-x0)/rc1)/((rc1 - rc)*(rc1 - t1)) + 
        t1*exp(-(x-x0)/t1)/((t1 - rc)*(t1 - rc1))) + 
Q2*rc*( rc*exp_rc/((rc - rc2)*(rc - t2)) + 
       rc2*exp(-(x-x0)/rc2)/((rc2 - rc)*(rc2 - t2)) + 
        t2*exp(-(x-x0)/t2)/((t2 - rc)*(t2 - rc2)));
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC100(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC101(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 
double rc1    = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q1*rc*( rc*exp_rc/((rc - rc1)*(rc - t1)) + 
       rc1*exp(-(x-x0)/rc1)/((rc1 - rc)*(rc1 - t1)) + 
        t1*exp(-(x-x0)/t1)/((t1 - rc)*(t1 - rc1)));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC102(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 
double rc2    = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q2*rc*( rc*exp_rc/((rc - rc2)*(rc - t2)) + 
       rc2*exp(-(x-x0)/rc2)/((rc2 - rc)*(rc2 - t2)) + 
        t2*exp(-(x-x0)/t2)/((t2 - rc)*(t2 - rc2)));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8D1_BL(Double_t *xx, Double_t *par){

//first derivative of RCGAM8
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8D2_BL(Double_t *xx, Double_t *par){

//second derivative of RCGAM8
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*t2/rc+exp(-(x-x0)/t2)*(t2*(x-x0-2*t2)-rc*(x-x0-t2))/pow(t2,2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8_BL(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8D1(Double_t *xx, Double_t *par){

//first derivative of RCGAM8
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2));
//printf("RCGAM8D1 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8D2(Double_t *xx, Double_t *par){

//second derivative of RCGAM8
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*t2/rc+exp(-(x-x0)/t2)*(t2*(x-x0-2*t2)-rc*(x-x0-t2))/pow(t2,2))/(t2*pow(rc-t2,2));
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM80(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM81(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM82(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));

return fun;
}

//__RCGAM8SI_________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SID1_BL(Double_t *xx, Double_t *par){

//first derivative of RCGAM8SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0
// //                -.2418620*t0*t0*t0*t0*t0*t0
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;
// // 0       5.053447e+00    1.292347e+00
// // 1       8.682840e-01    4.197623e-01

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
QS*rc*(-exp_rc*tS+exp(-(x-x0)/tS)*(tS-x+x0+rc*(x-x0)/tS))/(tS*pow(rc-tS,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SID2_BL(Double_t *xx, Double_t *par){

//second derivative of RCGAM8SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*tS/rc+exp(-(x-x0)/tS)*(tS*(x-x0-2*tS)-rc*(x-x0-tS))/pow(tS,2))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*t2/rc+exp(-(x-x0)/t2)*(t2*(x-x0-2*t2)-rc*(x-x0-t2))/pow(t2,2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SI_BL(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SID1(Double_t *xx, Double_t *par){

//first derivative of RCGAM8SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;
// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
QS*rc*(-exp_rc*tS+exp(-(x-x0)/tS)*(tS-x+x0+rc*(x-x0)/tS))/(tS*pow(rc-tS,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2));
//printf("RCGAM8SID1 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SID2(Double_t *xx, Double_t *par){

//second derivative of RCGAM8SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*tS/rc+exp(-(x-x0)/tS)*(tS*(x-x0-2*tS)-rc*(x-x0-tS))/pow(tS,2))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*t2/rc+exp(-(x-x0)/t2)*(t2*(x-x0-2*t2)-rc*(x-x0-t2))/pow(t2,2))/(t2*pow(rc-t2,2));
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SI(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SI0(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SI1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SI2(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//__RCGAM8SI_________________________________________________________________



//__RCGAM8SICSI_________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSID1_BL(Double_t *xx, Double_t *par){

//first derivative of RCGAM8SICSI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
double QS1     = Q1*1.00; // 
double tS1     = t1*2.46; // 
double QS2     = Q2*1.00; // 
double tS2     = t2*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0
// //                -.2418620*t0*t0*t0*t0*t0*t0
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;
// // 0       5.053447e+00    1.292347e+00
// // 1       8.682840e-01    4.197623e-01

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
QS*rc*(-exp_rc*tS+exp(-(x-x0)/tS)*(tS-x+x0+rc*(x-x0)/tS))/(tS*pow(rc-tS,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
QS1*rc*(-exp_rc*tS1+exp(-(x-x0)/tS1)*(tS1-x+x0+rc*(x-x0)/tS1))/(tS1*pow(rc-tS1,2))+
Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2))+
QS2*rc*(-exp_rc*tS2+exp(-(x-x0)/tS2)*(tS2-x+x0+rc*(x-x0)/tS2))/(tS2*pow(rc-tS2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSID2_BL(Double_t *xx, Double_t *par){

//second derivative of RCGAM8SICSI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
double QS1     = Q1*1.00; // 
double tS1     = t1*2.46; // 
double QS2     = Q2*1.00; // 
double tS2     = t2*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*tS/rc+exp(-(x-x0)/tS)*(tS*(x-x0-2*tS)-rc*(x-x0-tS))/pow(tS,2))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
QS1*rc*(exp_rc*tS1/rc+exp(-(x-x0)/tS1)*(tS1*(x-x0-2*tS1)-rc*(x-x0-tS1))/pow(tS1,2))/(tS1*pow(rc-tS1,2))+
Q2*rc*(exp_rc*t2/rc+exp(-(x-x0)/t2)*(t2*(x-x0-2*t2)-rc*(x-x0-t2))/pow(t2,2))/(t2*pow(rc-t2,2))+
QS2*rc*(exp_rc*tS2/rc+exp(-(x-x0)/tS2)*(tS2*(x-x0-2*tS2)-rc*(x-x0-tS2))/pow(tS2,2))/(tS2*pow(rc-tS2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSI_BL(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
double QS1     = Q1*1.00; // 
double tS1     = t1*2.46; // 
double QS2     = Q2*1.00; // 
double tS2     = t2*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
QS1*rc*(exp_rc*rc*tS1-exp(-(x-x0)/tS1)*(rc*(x-x0+tS1)-(x-x0)*tS1))/(tS1*pow(rc-tS1,2))+
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2))+
QS2*rc*(exp_rc*rc*tS2-exp(-(x-x0)/tS2)*(rc*(x-x0+tS2)-(x-x0)*tS2))/(tS2*pow(rc-tS2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSID1(Double_t *xx, Double_t *par){

//first derivative of RCGAM8SICSI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
double QS1     = Q1*1.00; // 
double tS1     = t1*2.46; // 
double QS2     = Q2*1.00; // 
double tS2     = t2*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;
// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
QS*rc*(-exp_rc*tS+exp(-(x-x0)/tS)*(tS-x+x0+rc*(x-x0)/tS))/(tS*pow(rc-tS,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
QS1*rc*(-exp_rc*tS1+exp(-(x-x0)/tS1)*(tS1-x+x0+rc*(x-x0)/tS1))/(tS1*pow(rc-tS1,2))+
Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2))+
QS2*rc*(-exp_rc*tS2+exp(-(x-x0)/tS2)*(tS2-x+x0+rc*(x-x0)/tS2))/(tS2*pow(rc-tS2,2));
//printf("RCGAM8SICSID1 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSID2(Double_t *xx, Double_t *par){

//second derivative of RCGAM8SICSI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
double QS1     = Q1*1.00; // 
double tS1     = t1*2.46; // 
double QS2     = Q2*1.00; // 
double tS2     = t2*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*tS/rc+exp(-(x-x0)/tS)*(tS*(x-x0-2*tS)-rc*(x-x0-tS))/pow(tS,2))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
QS1*rc*(exp_rc*tS1/rc+exp(-(x-x0)/tS1)*(tS1*(x-x0-2*tS1)-rc*(x-x0-tS1))/pow(tS1,2))/(tS1*pow(rc-tS1,2))+
Q2*rc*(exp_rc*t2/rc+exp(-(x-x0)/t2)*(t2*(x-x0-2*t2)-rc*(x-x0-t2))/pow(t2,2))/(t2*pow(rc-t2,2))+
QS2*rc*(exp_rc*tS2/rc+exp(-(x-x0)/tS2)*(tS2*(x-x0-2*tS2)-rc*(x-x0-tS2))/pow(tS2,2))/(tS2*pow(rc-tS2,2));
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSI(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
double QS1     = Q1*1.00; // 
double tS1     = t1*2.46; // 
double QS2     = Q2*1.00; // 
double tS2     = t2*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
QS1*rc*(exp_rc*rc*tS1-exp(-(x-x0)/tS1)*(rc*(x-x0+tS1)-(x-x0)*tS1))/(tS1*pow(rc-tS1,2))+
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2))+
QS2*rc*(exp_rc*rc*tS2-exp(-(x-x0)/tS2)*(rc*(x-x0+tS2)-(x-x0)*tS2))/(tS2*pow(rc-tS2,2));
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSI0(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSI1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 
double QS1     = Q1*1.00; // 
double tS1     = t1*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
QS1*rc*(exp_rc*rc*tS1-exp(-(x-x0)/tS1)*(rc*(x-x0+tS1)-(x-x0)*tS1))/(tS1*pow(rc-tS1,2));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM8SICSI2(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 
double QS2     = Q2*1.00; // 
double tS2     = t2*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2))+
QS2*rc*(exp_rc*rc*tS2-exp(-(x-x0)/tS2)*(rc*(x-x0+tS2)-(x-x0)*tS2))/(tS2*pow(rc-tS2,2));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//__RCGAM8SICSI_________________________________________________________________



// EXP-EXP
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SID1_BL(Double_t *xx, Double_t *par){

//first derivative of RCGAM10SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double bl     = par[10]; // -base line
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
QS*rc*(-exp_rc*tS+exp(-(x-x0)/tS)*(tS-x+x0+rc*(x-x0)/tS))/(tS*pow(rc-tS,2))-
Q1*rc*(exp_rc/((rc-t1)*(rc-t2))+exp(-(x-x0)/t1)/((t1-rc)*(t1-t2))+exp(-(x-x0)/t2)/((t2-rc)*(t2-t1)))-
Q2*rc*(exp_rc/((rc-t3)*(rc-t4))+exp(-(x-x0)/t3)/((t3-rc)*(t3-t4))+exp(-(x-x0)/t4)/((t4-rc)*(t4-t3)))-bl;
return fun;
}


//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SID2_BL(Double_t *xx, Double_t *par){

//second derivative of RCGAM10SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double bl     = par[10]; // -base line
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*tS/rc+exp(-(x-x0)/tS)*(tS*(x-x0-2*tS)-rc*(x-x0-tS))/pow(tS,2))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc/(rc*(rc-t1)*(rc-t2))+exp(-(x-x0)/t1)/(t1*(t1-rc)*(t1-t2))+exp(-(x-x0)/t2)/(t2*(t2-rc)*(t2-t1)))+
Q2*rc*(exp_rc/(rc*(rc-t3)*(rc-t4))+exp(-(x-x0)/t3)/(t3*(t3-rc)*(t3-t4))+exp(-(x-x0)/t4)/(t4*(t4-rc)*(t4-t3)))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SI_BL(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double bl     = par[10]; // -base line
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*rc/((rc-t1)*(rc-t2))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-t2))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t1)))+
Q2*rc*(exp_rc*rc/((rc-t3)*(rc-t4))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t4))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t3)))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SID1(Double_t *xx, Double_t *par){

//first derivative of RCGAM10SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
QS*rc*(-exp_rc*tS+exp(-(x-x0)/tS)*(tS-x+x0+rc*(x-x0)/tS))/(tS*pow(rc-tS,2))-
Q1*rc*(exp_rc/((rc-t1)*(rc-t2))+exp(-(x-x0)/t1)/((t1-rc)*(t1-t2))+exp(-(x-x0)/t2)/((t2-rc)*(t2-t1)))-
Q2*rc*(exp_rc/((rc-t3)*(rc-t4))+exp(-(x-x0)/t3)/((t3-rc)*(t3-t4))+exp(-(x-x0)/t4)/((t4-rc)*(t4-t3)));
//printf("RCGAM10SID1 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SID2(Double_t *xx, Double_t *par){

//second derivative of RCGAM10SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*tS/rc+exp(-(x-x0)/tS)*(tS*(x-x0-2*tS)-rc*(x-x0-tS))/pow(tS,2))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc/(rc*(rc-t1)*(rc-t2))+exp(-(x-x0)/t1)/(t1*(t1-rc)*(t1-t2))+exp(-(x-x0)/t2)/(t2*(t2-rc)*(t2-t1)))+
Q2*rc*(exp_rc/(rc*(rc-t3)*(rc-t4))+exp(-(x-x0)/t3)/(t3*(t3-rc)*(t3-t4))+exp(-(x-x0)/t4)/(t4*(t4-rc)*(t4-t3)));
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SI(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*rc/((rc-t1)*(rc-t2))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-t2))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t1)))+
Q2*rc*(exp_rc*rc/((rc-t3)*(rc-t4))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t4))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t3)));
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SI0(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SI1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double t2     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q1*rc*(exp_rc*rc/((rc-t1)*(rc-t2))+exp(-(x-x0)/t1)*t1/((t1-rc)*(t1-t2))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t1)));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM10SI2(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t3     = par[2]; // 
double t4     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q2*rc*(exp_rc*rc/((rc-t3)*(rc-t4))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t4))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t3)));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// EXP-EXP


// GAM-GAM-EXP-EXP
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SID1_BL(Double_t *xx, Double_t *par){

//first derivative of RCGAM12SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double Q3     = par[3];
double x0     = par[4]; // 
double t0     = par[5]; // 
double t1     = par[6]; // 
double t2     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double t5     = par[10]; // 
double rc     = par[11]; // 
double bl     = par[12]; // -base line
//double QS     = Q0*1.00; // 
//double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))-
Q2*rc*(exp_rc/((rc-t2)*(rc-t3))+exp(-(x-x0)/t2)/((t2-rc)*(t2-t3))+exp(-(x-x0)/t3)/((t3-rc)*(t3-t2)))-
Q3*rc*(exp_rc/((rc-t4)*(rc-t5))+exp(-(x-x0)/t4)/((t4-rc)*(t4-t5))+exp(-(x-x0)/t5)/((t5-rc)*(t5-t4)))-bl;
return fun;
}


//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SID2_BL(Double_t *xx, Double_t *par){

//second derivative of RCGAM12SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double Q3     = par[3];
double x0     = par[4]; // 
double t0     = par[5]; // 
double t1     = par[6]; // 
double t2     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double t5     = par[10]; // 
double rc     = par[11]; // 
double bl     = par[12]; // -base line
//double QS     = Q0*1.00; // 
//double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc/(rc*(rc-t2)*(rc-t3))+exp(-(x-x0)/t2)/(t2*(t2-rc)*(t2-t3))+exp(-(x-x0)/t3)/(t3*(t3-rc)*(t3-t2)))+
Q3*rc*(exp_rc/(rc*(rc-t4)*(rc-t5))+exp(-(x-x0)/t4)/(t4*(t4-rc)*(t4-t5))+exp(-(x-x0)/t5)/(t5*(t5-rc)*(t5-t4)))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SI_BL(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double Q3     = par[3];
double x0     = par[4]; // 
double t0     = par[5]; // 
double t1     = par[6]; // 
double t2     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double t5     = par[10]; // 
double rc     = par[11]; // 
double bl     = par[12]; // -base line
//double QS     = Q0*1.00; // 
//double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*rc/((rc-t2)*(rc-t3))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t3))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t2)))+
Q3*rc*(exp_rc*rc/((rc-t4)*(rc-t5))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t5))+exp(-(x-x0)/t5)*t5/((t5-rc)*(t5-t4)))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SID1(Double_t *xx, Double_t *par){

//first derivative of RCGAM12SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double Q3     = par[3];
double x0     = par[4]; // 
double t0     = par[5]; // 
double t1     = par[6]; // 
double t2     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double t5     = par[10]; // 
double rc     = par[11]; // 
//double QS     = Q0*1.00; // 
//double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))-
Q2*rc*(exp_rc/((rc-t2)*(rc-t3))+exp(-(x-x0)/t2)/((t2-rc)*(t2-t3))+exp(-(x-x0)/t3)/((t3-rc)*(t3-t2)))-
Q3*rc*(exp_rc/((rc-t4)*(rc-t5))+exp(-(x-x0)/t4)/((t4-rc)*(t4-t5))+exp(-(x-x0)/t5)/((t5-rc)*(t5-t4)));
//printf("RCGAM12SID1 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SID10(Double_t *xx, Double_t *par){

//first derivative of RCGAM12SI
double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2));
//printf("RCGAM12SID1 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}


//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SID12(Double_t *xx, Double_t *par){

//first derivative of RCGAM12SI
double x=xx[0];// 

double Q2     = par[0]; // 
double x0     = par[1]; // 
double t2     = par[2]; // 
double t3     = par[3]; // 
double rc     = par[4]; // 
//double QS     = Q0*1.00; // 
//double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
-Q2*rc*(exp_rc/((rc-t2)*(rc-t3))+exp(-(x-x0)/t2)/((t2-rc)*(t2-t3))+exp(-(x-x0)/t3)/((t3-rc)*(t3-t2)));
//printf("RCGAM12SID1 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SID2(Double_t *xx, Double_t *par){

//second derivative of RCGAM12SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double Q3     = par[3];
double x0     = par[4]; // 
double t0     = par[5]; // 
double t1     = par[6]; // 
double t2     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double t5     = par[10]; // 
double rc     = par[11]; // 
//double QS     = Q0*1.00; // 
//double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc/(rc*(rc-t2)*(rc-t3))+exp(-(x-x0)/t2)/(t2*(t2-rc)*(t2-t3))+exp(-(x-x0)/t3)/(t3*(t3-rc)*(t3-t2)))+
Q3*rc*(exp_rc/(rc*(rc-t4)*(rc-t5))+exp(-(x-x0)/t4)/(t4*(t4-rc)*(t4-t5))+exp(-(x-x0)/t5)/(t5*(t5-rc)*(t5-t4)));
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SI(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double Q3     = par[3];
double x0     = par[4]; // 
double t0     = par[5]; // 
double t1     = par[6]; // 
double t2     = par[7]; // 
double t3     = par[8]; // 
double t4     = par[9]; // 
double t5     = par[10]; // 
double rc     = par[11]; // 
//double QS     = Q0*1.00; // 
//double tS     = t0*2.46; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else{
fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));
if(t2!=t3){
fun+=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-t3))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t3))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t2)));
}
else{
fun+=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
if(t4!=t5){
fun+=Q3*rc*(exp_rc*rc/((rc-t4)*(rc-t5))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t5))+exp(-(x-x0)/t5)*t5/((t5-rc)*(t5-t4)));
}
else{
fun+=Q3*rc*(exp_rc*rc*t4-exp(-(x-x0)/t4)*(rc*(x-x0+t4)-(x-x0)*t4))/(t4*pow(rc-t4,2));
}
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
}
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SI0(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SI0DT(Double_t *xx, Double_t *par){

//pochodna po t0
double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
//Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
Q0*rc*(2.*exp_rc*rc*pow(t0,3)-exp(-(x-x0)/t0)*
(pow(rc*(x-x0),2)+(x-x0)*((x-x0)-2.*t0)*t0*t0+2.*rc*t0*((x-x0)*t0+t0*t0-pow(x-x0,2))))/pow((rc-t0)*t0,3);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SI0DTD1(Double_t *xx, Double_t *par){

//pochodna po t0
double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
//Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));
// Q0*rc*(2*exp_rc*rc*pow(t0,3)-exp(-(x-x0)/t0)*
// (pow(rc*(x-x0),2)+(x-x0)*((x-x0)-2.*t0)*t0*t0+2.*rc*t0*((x-x0)*t0+t0*t0-pow(x-x0,2))))/pow((rc-t0)*t0,3);
Q0*rc*(-2.*exp_rc*pow(t0,4)+exp(-(x-x0)/t0)*
(rc*rc*(x-x0)*((x-x0)-2.*t0)-2.*rc*(x-x0)*((x-x0)-3.*t0)*t0+t0*t0*(pow(x-x0,2)-
4.*(x-x0)*t0+2.*t0*t0)))/(pow(t0,4)*pow(rc-t0,3));

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SI1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SI2(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0]; // 
double x0     = par[1]; // 
double t2     = par[2]; // 
double t3     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t2!=t3){
fun+=Q2*rc*(exp_rc*rc/((rc-t2)*(rc-t3))+exp(-(x-x0)/t2)*t2/((t2-rc)*(t2-t3))+exp(-(x-x0)/t3)*t3/((t3-rc)*(t3-t2)));
}
else{
fun+=Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SI3(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q3     = par[0];
double x0     = par[1]; // 
double t4     = par[2]; // 
double t5     = par[3]; // 
double rc     = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else {
if(t4!=t5){
fun+=Q3*rc*(exp_rc*rc/((rc-t4)*(rc-t5))+exp(-(x-x0)/t4)*t4/((t4-rc)*(t4-t5))+exp(-(x-x0)/t5)*t5/((t5-rc)*(t5-t4)));
}
else{
fun+=Q3*rc*(exp_rc*rc*t4-exp(-(x-x0)/t4)*(rc*(x-x0+t4)-(x-x0)*t4))/(t4*pow(rc-t4,2));
}
}

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SIPDS(Double_t *xx, Double_t *par){


double x=xx[0];// 


// !!!!  Q0 is in fact Q0/C

double fun = par[0]; // 


return fun;
}
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM12SIPDSD1(Double_t *xx, Double_t *par){


double x=xx[0];// 


// !!!!  Q0 is in fact Q0/C

double fun = 0; // 


return fun;
}
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// GAM-GAM-EXP-EXP



//GAMMA2
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SID1_BL(Double_t *xx, Double_t *par){

//first derivative of RCGAM28SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0
// //                -.2418620*t0*t0*t0*t0*t0*t0
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;
// // 0       5.053447e+00    1.292347e+00
// // 1       8.682840e-01    4.197623e-01

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = //zla
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
QS*rc*(-exp_rc*tS+exp(-(x-x0)/tS)*(tS-x+x0+rc*(x-x0)/tS))/(tS*pow(rc-tS,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SID2_BL(Double_t *xx, Double_t *par){

//second derivative of RCGAM28SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun =  //zla
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*tS/rc+exp(-(x-x0)/tS)*(tS*(x-x0-2*tS)-rc*(x-x0-tS))/pow(tS,2))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*t2/rc+exp(-(x-x0)/t2)*(t2*(x-x0-2*t2)-rc*(x-x0-t2))/pow(t2,2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SI_BL(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double bl     = par[8]; // -base line
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0.-bl;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*rc*t1-exp(-(x-x0)/t1)*(rc*(x-x0+t1)-(x-x0)*t1))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*rc*t2-exp(-(x-x0)/t2)*(rc*(x-x0+t2)-(x-x0)*t2))/(t2*pow(rc-t2,2))-bl;
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SID1(Double_t *xx, Double_t *par){

//first derivative of RCGAM28SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;
// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(-exp_rc*t0+exp(-(x-x0)/t0)*(t0-x+x0+rc*(x-x0)/t0))/(t0*pow(rc-t0,2))+
QS*rc*(-exp_rc*tS+exp(-(x-x0)/tS)*(tS-x+x0+rc*(x-x0)/tS))/(tS*pow(rc-tS,2))+
Q1*rc*(-exp_rc*t1+exp(-(x-x0)/t1)*(t1-x+x0+rc*(x-x0)/t1))/(t1*pow(rc-t1,2))+
Q2*rc*(-exp_rc*t2+exp(-(x-x0)/t2)*(t2-x+x0+rc*(x-x0)/t2))/(t2*pow(rc-t2,2));
//printf("RCGAM28SID1 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SID2(Double_t *xx, Double_t *par){

//second derivative of RCGAM28SI
double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*t0/rc+exp(-(x-x0)/t0)*(t0*(x-x0-2*t0)-rc*(x-x0-t0))/pow(t0,2))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*tS/rc+exp(-(x-x0)/tS)*(tS*(x-x0-2*tS)-rc*(x-x0-tS))/pow(tS,2))/(tS*pow(rc-tS,2))+
Q1*rc*(exp_rc*t1/rc+exp(-(x-x0)/t1)*(t1*(x-x0-2*t1)-rc*(x-x0-t1))/pow(t1,2))/(t1*pow(rc-t1,2))+
Q2*rc*(exp_rc*t2/rc+exp(-(x-x0)/t2)*(t2*(x-x0-2*t2)-rc*(x-x0-t2))/pow(t2,2))/(t2*pow(rc-t2,2));
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SI(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2))+
4*Q1*rc*(2*exp_rc*pow(rc*t1,2)-exp(-2*(x-x0)/t1)*(pow((x-x0)*t1,2)-2*rc*(x-x0)*t1*(2*(x-x0)+t1)+ 
2*rc*rc*(2*pow((x-x0),2)+2*(x-x0)*t1+t1*t1)))/(pow(2*rc-t1,3)*t1*t1)+
4*Q2*rc*(2*exp_rc*pow(rc*t2,2)-exp(-2*(x-x0)/t2)*(pow((x-x0)*t2,2)-2*rc*(x-x0)*t2*(2*(x-x0)+t2)+ 
2*rc*rc*(2*pow((x-x0),2)+2*(x-x0)*t2+t2*t2)))/(pow(2*rc-t2,3)*t2*t2);
//printf("RCGAM8 %f %f %f %f %f %f %f %f %f %f\n",x,fun,Q0,Q1,Q2,x0,t0,t1,t2,rc);
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SI0(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 
// double QS     = Q0*1.16; // 
// double tS     = t0*2.54; // 
double QS     = Q0*1.00; // 
double tS     = t0*2.46; // 
// double QS     = Q0*exp(-5.90210e-02*t0*t0-4.05702e-01*t0+1.96267); // 
// // double tS     = 4.573433
// //                +4.523224*t0
// //                -8.207632*t0*t0
// //                +8.866372*t0*t0*t0
// //                -5.068739*t0*t0*t0*t0
// //                +1.556074*t0*t0*t0*t0*t0 
// //                -.2418620*t0*t0*t0*t0*t0*t0 
// //                +.01503517*t0*t0*t0*t0*t0*t0*t0;
// double tS     = 5.053447+8.682840e-01*t0;

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
QS*rc*(exp_rc*rc*tS-exp(-(x-x0)/tS)*(rc*(x-x0+tS)-(x-x0)*tS))/(tS*pow(rc-tS,2));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SI1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
4*Q1*rc*(2*exp_rc*pow(rc*t1,2)-exp(-2*(x-x0)/t1)*(pow((x-x0)*t1,2)-2*rc*(x-x0)*t1*(2*(x-x0)+t1)+ 
2*rc*rc*(2*pow((x-x0),2)+2*(x-x0)*t1+t1*t1)))/(pow(2*rc-t1,3)*t1*t1);

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RCGAM28SI2(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
4*Q2*rc*(2*exp_rc*pow(rc*t2,2)-exp(-2*(x-x0)/t2)*(pow((x-x0)*t2,2)-2*rc*(x-x0)*t2*(2*(x-x0)+t2)+ 
2*rc*rc*(2*pow((x-x0),2)+2*(x-x0)*t2+t2*t2)))/(pow(2*rc-t2,3)*t2*t2);

return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//GAMMA2




double RC11(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double n      = par[8]; // 
double rc1    = par[9]; // 
double rc2    = par[10]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
double nrc = n*rc; // 
double arg_gam = (x-x0)*(nrc-t0)/(rc*t0); // 
if(x<=x0) fun=0;
else fun = 
Q0*exp_rc*pow(nrc/(nrc-t0),n+1)*TMath::Gamma(n+1,arg_gam) + 
Q1*rc*( rc*exp_rc/((rc - rc1)*(rc - t1)) + 
       rc1*exp(-(x-x0)/rc1)/((rc1 - rc)*(rc1 - t1)) + 
        t1*exp(-(x-x0)/t1)/((t1 - rc)*(t1 - rc1))) + 
Q2*rc*( rc*exp_rc/((rc - rc2)*(rc - t2)) + 
       rc2*exp(-(x-x0)/rc2)/((rc2 - rc)*(rc2 - t2)) + 
        t2*exp(-(x-x0)/t2)/((t2 - rc)*(t2 - rc2)));
return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC110(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 
double n      = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
double nrc = n*rc; // 
double arg_gam = (x-x0)*(nrc-t0)/(rc*t0); // 
if(x<=x0) fun=0;
else fun = Q0*exp_rc*pow(nrc/(nrc-t0),n+1)*TMath::Gamma(n+1,arg_gam);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC111(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 
double rc1    = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q1*rc*( rc*exp_rc/((rc - rc1)*(rc - t1)) + 
       rc1*exp(-(x-x0)/rc1)/((rc1 - rc)*(rc1 - t1)) + 
        t1*exp(-(x-x0)/t1)/((t1 - rc)*(t1 - rc1)));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC112(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 
double rc2    = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q2*rc*( rc*exp_rc/((rc - rc2)*(rc - t2)) + 
       rc2*exp(-(x-x0)/rc2)/((rc2 - rc)*(rc2 - t2)) + 
        t2*exp(-(x-x0)/t2)/((t2 - rc)*(t2 - rc2)));


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////



//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC9(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 
double n      = par[8]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
double nrc = n*rc; // 
double arg_gam = (x-x0)*(nrc-t0)/(rc*t0); // 
if(x<=x0) fun=0;
else fun = Q0*exp_rc*pow(nrc/(nrc-t0),n+1)*TMath::Gamma(n+1,arg_gam) + 
Q1*rc*(exp_rc - exp(-(x-x0)/t1))/(rc - t1) + 
Q2*rc*(exp_rc - exp(-(x-x0)/t2))/(rc - t2);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC90(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 
double n      = par[4]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
double nrc = n*rc; // 
double arg_gam = (x-x0)*(nrc-t0)/(rc*t0); // 
if(x<=x0) fun=0;
else fun = Q0*exp_rc*pow(nrc/(nrc-t0),n+1)*TMath::Gamma(n+1,arg_gam);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC91(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = Q1*rc*(exp_rc - exp(-(x-x0)/t1))/(rc - t1);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC92(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 

// !!!!  Q0 is in fact Q0/C

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = Q2*rc*(exp_rc - exp(-(x-x0)/t2))/(rc - t2);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC8(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 

// !!!!  Q0 is in fact Q0/C


double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2))+
Q1*rc*(exp_rc-exp(-(x-x0)/t1))/(rc - t1) + 
Q2*rc*(exp_rc-exp(-(x-x0)/t2))/(rc - t2);


return fun;
}

//___________________________________________________________________
double RC80(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc*rc*t0-exp(-(x-x0)/t0)*(rc*(x-x0+t0)-(x-x0)*t0))/(t0*pow(rc-t0,2));


return fun;
}

//___________________________________________________________________
double RC81(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = Q1*rc*(exp_rc-exp(-(x-x0)/t1))/(rc - t1);


return fun;
}

//___________________________________________________________________
double RC82(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = Q2*rc*(exp_rc-exp(-(x-x0)/t2))/(rc - t2);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////

double RC8exp(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 
double rc     = par[7]; // 

// !!!!  Q0 is in fact Q0/C


double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc-exp(-(x-x0)/t0))/(rc - t0)+
Q1*rc*(exp_rc-exp(-(x-x0)/t1))/(rc - t1)+ 
Q2*rc*(exp_rc-exp(-(x-x0)/t2))/(rc - t2);


return fun;
}

//___________________________________________________________________
double RC8exp0(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double x0     = par[1]; // 
double t0     = par[2]; // 
double rc     = par[3]; // 

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q0*rc*(exp_rc-exp(-(x-x0)/t0))/(rc - t0);


return fun;
}

//___________________________________________________________________
double RC8exp1(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q1     = par[0]; // 
double x0     = par[1]; // 
double t1     = par[2]; // 
double rc     = par[3]; // 

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = 
Q1*rc*(exp_rc-exp(-(x-x0)/t1))/(rc - t1);


return fun;
}

//___________________________________________________________________
double RC8exp2(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q2     = par[0];
double x0     = par[1]; // 
double t2     = par[2]; // 
double rc     = par[3]; // 

double fun = 0.; // 
double exp_rc = exp(-(x-x0)/rc); // 
if(x<=x0) fun=0;
else fun = Q2*rc*(exp_rc-exp(-(x-x0)/t2))/(rc - t2);


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

double CASSINI(Double_t *xx, Double_t *par){


double x=xx[0];// 

double Q0     = par[0]; // 
double Q1     = par[1]; // 
double Q2     = par[2];
double x0     = par[3]; // 
double t0     = par[4]; // 
double t1     = par[5]; // 
double t2     = par[6]; // 

double fun = 0.; // 
//if(t0<=0) return fun;
if(x<=x0) fun=0;
else fun = (1-(1+(x-x0)/t0)*exp(-((x-x0)/t0)))*Q0 +  
(1-exp(-((x-x0)/t1)))*Q1 + 
(1-exp(-((x-x0)/t2)))*Q2;


return fun;
}

//___________________________________________________________________
///////////////////////////////////////////////////////////////////////////////


class ASYrawFadcSignal : public TObject{
public:
  Short_t module;   // FADC module
  Short_t channel;  // FADC channel
  Int_t   size;     // number of channels in time spectrum 
  Int_t *data;    //[size] raw time spectrum 
  //Short_t *data;    //[size] raw time spectrum 

  Float_t G1;// gates
  Float_t G2;
  Float_t G3;
 Float_t G4;
 Float_t G5;
 Float_t G6;

  ASYrawFadcSignal();
  ASYrawFadcSignal(Int_t ssize);
  virtual ~ASYrawFadcSignal(){Clear();}
  void     SetEvent(ASYrawEvent *evt0){evt = evt0;}
  ASYrawEvent *GetEvent() const {return evt;}
  void     Clear(Option_t *option="");
  
  TH1D *GetHraw(){return hraw;}
  TH1D *GetHist(){return hist;}
  TH1D *GetHaux(){return haux;}
    
  void SetHraw(); //put raw data Int_to histogram
  void SetHist(Float_t pds);
  void SetHaux();
  float FindPds16();
  float FindPds();
  float FindT0();
  void SmooGa(TH1D* hin, TH1D* hout, const char* hout_title,
       const double sigma, const double nsig); //Gaussin smoothing
  void SmooSinc(); //Sinc smoothing (antialias)
  void SmooMed1(TH1D* hin, TH1D* hout, const char* hout_title); //Median smoothing K=1
  void SmooMed(TH1D* hin, TH1D* hout, const char* hout_title, const int K); //Median smoothing
  void SavGol(); //SavGol smoothing
  TH1D *hraw;//! //raw data put Int_to histogram
  TH1D *hist;//! //raw data with subtracted pedestal
  TH1D *haux;//! //aux histogram (e.g. smoothed data, derivative etc)
  Float_t pds;//!  // pedestal
  Float_t pdsrms;//!  // sigma
  Float_t t0;//!  // t0

  ASYrawEvent *evt; //! 

private:

 ClassDef(ASYrawFadcSignal,1)  //A raw signal segment
};

///////////////////////////////////////////////////////////////////////////////

// 
// class ASYrawCamac : public TObject{
// public:
//   Int_t   size;     // number of channels in time spectrum 
//   Short_t *data;    //[size] raw time spectrum 
// 
// 
//   ASYrawCamac();
//   ASYrawCamac(Int_t ssize);
//   virtual ~ASYrawCamac(){Clear();}
//   void     SetEvent(ASYrawEvent *evt0){evt = evt0;}
//   ASYrawEvent *GetEvent() const {return evt;}
//   void     Clear(Option_t *option="");
//   
// 
//   ASYrawEvent *evt; //! 
// 
// private:
// 
//  ClassDef(ASYrawCamac,1)  //A raw signal segment
// };

///////////////////////////////////////////////////////////////////////////////

class ASYrawEvent : public TObject{
public:
  Int_t   number;        // event number
  Int_t   nsignal;       // total number of FADC channels
//  Int_t   ncamac;       // total number of camac channels
  Short_t camac[56];    //
    
  TClonesArray  *signal;  //->
//  TClonesArray  *camac;  //->

  ASYrawEvent();
  virtual ~ASYrawEvent();
  void     Clear(Option_t *opt="");
  ASYrawFadcSignal* AddSignal(Int_t ssize){return new((*signal)[nsignal++]) ASYrawFadcSignal(ssize);} // Setup signal
  ASYrawFadcSignal* Signal(Int_t n){
    ASYrawFadcSignal *sig = (ASYrawFadcSignal*)((*signal)[n]);
    sig->hraw=0;
    sig->hist=0;
    sig->haux=0;
    sig->SetEvent(this);
    sig->SetHraw();
    return sig;
  } // Get signal
  
  ASYrawFadcSignal* ProcessedSignal(Int_t n); // Get signal

//   ASYrawCamac* AddCamac(Int_t ssize){return new((*camac)[ncamac++]) ASYrawCamac(ssize);} // Setup signal
//   ASYrawCamac* Camac(Int_t n){
//     ASYrawCamac *cam = (ASYrawCamac*)((*camac)[n]);
//     cam->SetEvent(this);
//     return cam;
//   } // Get camac[n]
  
  

private:

  ClassDef(ASYrawEvent,1)  //Event structure
};
#endif



///////////////////////////////////////////////////////////////////////////////
