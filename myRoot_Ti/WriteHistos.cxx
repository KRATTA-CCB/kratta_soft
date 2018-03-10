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

  c1=new TCanvas("KRa0a1","KRa0a1");
  c1->Divide(4,4);

  c1a=new TCanvas("KrCutsRCa","KrCutsRCa");
  c1a->Divide(4,4);

  c1b=new TCanvas("KRp14_p24","KRp14_p24");
  c1b->Divide(4,4);

  c1d=new TCanvas("KRa1a2","KRa1a2");
  c1d->Divide(4,4);
 
  c1c=new TCanvas("KRp12_p13","KRp12_p13");
  c1c->Divide(4,4);

  c20=new TCanvas("RC0","RC0");
  c20->Divide(4,4);

  c21=new TCanvas("RC1","RC1");
  c21->Divide(4,4);

  c22=new TCanvas("RC2","RC2");
  c22->Divide(4,4);

 c200=new TCanvas("RC00","RC00");
  c200->Divide(4,4);

  c210=new TCanvas("RC10","RC10");
  c210->Divide(4,4);
 char nmax[50];

 //********************************
   sprintf(nmax,"mod=12");
   t2=new TPaveText(x1,y1,x2,y2,"NDC");
   t2->AddText(nmax); 
   t2->SetFillColor(0);
   t2->SetBorderSize(0);
   t2->SetTextSize(0.09);

   for (int i=0;i<16;i++){
     int k=i+1;
   c1->cd(k);
   gPad->SetLogz();
   hamp01[i]->Draw("colz");
   //t2->Draw();   
   
   c1d->cd(k);
   gPad->SetLogz();
   hamp12[i]->Draw("colz");
   //t2->Draw();   
   

   c1a->cd(k);
   gPad->SetLogz();
   hamp01a[i]->Draw("colz");

   c1b->cd(k);
   gPad->SetLogz();
   hp14_p24[i]->Draw("colz");

   c1c->cd(k);
   gPad->SetLogz();
   hp12_p13[i]->Draw("colz");



   c20->cd(k);
   hrc0[i]->Draw();
   htls0[i]->SetLineColor(2);
   htls0[i]->Draw("same");
   
   c21->cd(k);
   htls1[i]->SetLineColor(2);
   htls1[i]->Draw();
   hrc1[i]->Draw("same");

   c22->cd(k);
   htls2[i]->SetLineColor(2);
   htls2[i]->Draw();
   hrc2[i]->Draw("same");

   c200->cd(k);
   hrc00[i]->Draw();
   htls00[i]->SetLineColor(2);
   htls00[i]->Draw("same");
   
   c210->cd(k);
   htls10[i]->SetLineColor(2);
   htls10[i]->Draw();
   hrc10[i]->Draw("same");


   }
   
   int modNb=15;
   
   
   c2b=new TCanvas("PD2","PD2");
   c2b->Divide(2,2);

   c2b->cd(1);
   htmaxt0_vs_tls2[modNb]->Draw("colz");
   c2b->cd(2);
   hrc_vs_chi2[modNb]->Draw("colz");
   c2b->cd(3);
   htls2_vs_chi2[modNb]->Draw("colz");
   c2b->cd(4);
   htmaxt0_vs_chi2[modNb]->Draw("colz");

   //***********************

   c2b1=new TCanvas("pdsr","pdsr");
   c2b1->Divide(2,3);

   c2b1->cd(1);
   hpds0[modNb]->Draw();
   c2b1->cd(2);
   hpdr0[modNb]->Draw();

   c2b1->cd(3);
   hpds1[modNb]->Draw();
   c2b1->cd(4);
   hpdr1[modNb]->Draw();

   c2b1->cd(5);
   hpds2[modNb]->Draw();
   c2b1->cd(6);
   hpdr2[modNb]->Draw();

   c2b1a=new TCanvas("pdsr2D","pdsr2D");
   c2b1a->Divide(2,2);

   c2b1a->cd(1);
   hpds0_vs_pdr0[modNb]->Draw("colz");
  
   c2b1a->cd(2);
   hpds1_vs_pdr1[modNb]->Draw("colz");

   c2b1a->cd(3);
   hpds2_vs_pdr2[modNb]->Draw("colz");
   

   //*********************************
   c2b2=new TCanvas("p12p13","p12p13");
   c2b2->Divide(2,3);

   c2b2->cd(1);
   hp12_p13[modNb]->Draw("colz");

   c2b2->cd(2);
   hp12_p13c12[modNb]->Draw("colz");
  
   c2b2->cd(3);
   hp12_p13a[modNb]->Draw("colz");
   
   c2b2->cd(4);
   hp12_p13ac12[modNb]->Draw("colz");

   c2b2->cd(5);
   hp12_p13b[modNb]->Draw("colz");
  
   c2b2->cd(6);
   hp12_p13bc12[modNb]->Draw("colz");


   c2b3=new TCanvas("p22p23","p22p23");
   c2b3->Divide(2,3);

   c2b3->cd(1);
   hp22_p23[modNb]->Draw("colz");

   c2b3->cd(2);
   hp22_p23c12[modNb]->Draw("colz");
  
   c2b3->cd(3);
   hp22_p23a[modNb]->Draw("colz");
   
   c2b3->cd(4);
   hp22_p23ac12[modNb]->Draw("colz");

   c2b3->cd(5);
   hp22_p23b[modNb]->Draw("colz");
  
   c2b3->cd(6);
   hp22_p23bc12[modNb]->Draw("colz");



   c2b4=new TCanvas("am1am2","am1am2");
   c2b4->Divide(2,1);

   c2b4->cd(1);
   hamp12[modNb]->Draw("colz");

   c2b4->cd(2);
   hamp12a[modNb]->Draw("colz");
  

   c2b5=new TCanvas("am0am1","am0am1");
   c2b5->Divide(2,1);

   c2b5->cd(1);
   hamp01[modNb]->Draw("colz");
   c2b5->cd(2);
   hamp01a[modNb]->Draw("colz");




   c2b6=new TCanvas("p10_p12p13","p10_p12p13");
   c2b6->Divide(2,1);

   c2b6->cd(1);
   hp10_p12p13[modNb]->Draw("colz");
   c2b6->cd(2);
   hp10_p12p13c[modNb]->Draw("colz");








   //c2b5->cd(2);
   //hamp01a[13]->Draw("colz");
  
   /*
   c1->cd(3);
   //gPad->SetLogz();
   hp12_p13[i]->Draw("colz");
   
   c1->cd(4);
   //gPad->SetLogz();
   hp22_p23[i]->Draw("colz");
   
   c1->cd(5);
   //gPad->SetLogz();
   hp12p13_p22p23[i]->Draw("colz");
   
   c1->cd(6);
   //gPad->SetLogz();
   hp00_p10p12p13[i]->Draw("colz");
   
   c1->cd(7);
   //gPad->SetLogz();
   hp10_p12p13[i]->Draw("colz");
      
   c1->cd(8);
   //gPad->SetLogz();
   hp10p10_p12p13p10[i]->Draw("colz");
   
   c1->cd(9);
   gPad->SetLogy();
   //gPad->SetLogz();
   hslowfast_1[i]->Draw("colz");
   
   c1->cd(10);
   gPad->SetLogy();
   //gPad->SetLogz();
   hslowfast_2[i]->Draw("colz");
   */
     
   
   //}


   c1->Write();c1a->Write();c1b->Write();c1c->Write();c1d->Write();
   c20->Write();c21->Write();c22->Write();
   c200->Write();c210->Write();
   c2b->Write();c2b1->Write();c2b1a->Write();c2b2->Write();c2b3->Write();c2b4->Write();c2b5->Write();
   c2b6->Write();

   f->Write();
}
