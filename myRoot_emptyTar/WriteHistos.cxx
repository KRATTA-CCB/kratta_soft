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


   for (int i=0;i<16;i++){
 
     htm1[i]->Write();
     hpdr1[i]->Write();
     hpds1[i]->Write();
     
     hchi21[i]->Write();
	 
 
     hamp01[i]->Write();
     hamp12[i]->Write(); 
     hamp12Cut[i]->Write(); 

     hp12_p13[i]->Write();
     hp22_p23[i]->Write();
     hp10_p12p13[i]->Write();
     hp10_enProt[i]->Write();
     
     hp10_p12p13st[i]->Write();
     hp10_p12p13stCut[i]->Write();
     //hp20_p22p23[i]->Write();

     hp22p23[i]->Write();
     hp22p23c[i]->Write();

     hp12p13[i]->Write();
     hp12p13c[i]->Write();

     hen_prot[i]->Write();



   }
 
   f->Write();
}
