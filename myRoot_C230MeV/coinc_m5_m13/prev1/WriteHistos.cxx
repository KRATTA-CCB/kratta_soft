void KRAnal::WriteHistos(void)
{
  
  TCanvas *c1, *c1a, *c20,*c21,*c22,*c200,*c210;
  TCanvas *c1b,*c1c,*c1d;
  
  TCanvas *c2b,*c2b1,*c2b2,*c2b3,*c2b4,*c2b5,*c2b6,*c2c,*c2d;
  TCanvas *c2b1a;
  float x1,x2,y1,y2;
  x1=0.52; y1=0.8;x2=0.7;y2=0.87;

  char n1[50],n2[50];
  char n3[50],n4[50];
  char n1z[50],n2z[50];
  char m[50];
  
 

  TPaveText *t1,*t2; 

f = new TFile("KRATTA_histos.root","recreate");
  if (!f || !f->IsOpen()){
    f=new TFile("KRATTA_histos.root","recreate");
  }


 char nmax[50];

 //********************************
 htm1tm2_1->Write(); 
 htm1tm2_2->Write(); 
 htm1Ltm1R->Write(); 
 htm2Ltm2R->Write(); 
 henLenR->Write(); 

   f->Write();
}
