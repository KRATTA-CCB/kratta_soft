
void KRAnal::CreateHistos(void)
{
  char d0[100],d1[100],d2[100];
  char m[100], m1[100];



  for (int i=0;i<16;i++){
    
sprintf(m,"am0_vs_am1_mod%d",i);
sprintf(m1,"am1_vs_am2_mod%d",i);

//hamp01[i]=new TH2F(m, m, 600, 10, 7500, 600, 6, 3000);
//12
hamp01[i]=new TH2F(m, m, 500, 10, 2500, 500, 40, 1000);

//hamp12[i]=new TH2F(m1, m1, 500, 10, 14500, 500, 6, 7000);

hamp01a[i]=new TH2F(m, m, 500, 10, 2500, 500, 40, 1000);



 sprintf(m,"p14_vs_p24_mod%d",i);
 hp14_p24[i]=new TH2F(m, m, 200, 50, 250, 200, 50, 250);

 sprintf(m,"p12_vs_p13_mod%d",i);
 hp12_p13[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);
 hp12_p13a[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);
 hp12_p13b[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);

 sprintf(m,"p12_vs_p13coinc12_mod%d",i);
 hp12_p13c12[i]=new TH2F(m, m, 200, 40, 3000, 200, 40, 3500);
 hp12_p13ac12[i]=new TH2F(m, m, 200, 40, 3000, 200, 40, 3500);
 hp12_p13bc12[i]=new TH2F(m, m, 200, 40, 3000, 200, 40, 3500);


 sprintf(m,"p22_vs_p23_mod%d",i);
 hp22_p23[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);
 hp22_p23a[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);
 hp22_p23b[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);

 sprintf(m,"p22_vs_p23coinc12_mod%d",i);
 hp22_p23c12[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);
 hp22_p23ac12[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);
 hp22_p23bc12[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);


 sprintf(m,"p10_vs_p12p13_mod%d",i);
 hp10_p12p13[i]=new TH2F(m, m, 500, 40, 5000, 500, 40, 4000);
 hp10_p12p13c[i]=new TH2F(m, m, 500, 40, 5000, 500, 40, 4000);


 //*******************************

 sprintf(m1,"am1_vs_am2_mod%d",i);
 hamp12[i]=new TH2F(m1, m1, 500, 10, 4000, 500, 10, 3500);
 sprintf(m1,"am1_vs_am2coinc12_mod%d",i);
 hamp12a[i]=new TH2F(m1, m1, 500, 10, 4000, 500, 10, 3500);

 sprintf(m,"rc0_tls0red_mod%d",i);
 hrc0[i]=new TH1F(m,m,200,100,1500);
 htls0[i]=new TH1F(m,m,200,100,1500);

 sprintf(m,"rc1_tls1red_mod%d",i);
 hrc1[i]=new TH1F(m,m,200,100,1000);
 htls1[i]=new TH1F(m,m,200,100,1000);

 sprintf(m,"rc2_tls2red_mod%d",i);
 hrc2[i]=new TH1F(m,m,200,10,1500);
 htls2[i]=new TH1F(m,m,200,10,1500);

 sprintf(m,"rc0_tls0red_mod%d",i);
 hrc00[i]=new TH1F(m,m,200,100,1500);
 htls00[i]=new TH1F(m,m,200,100,1500);

 sprintf(m,"rc1_tls1red_mod%d",i);
 hrc10[i]=new TH1F(m,m,200,100,1000);
 htls10[i]=new TH1F(m,m,200,100,1000);

 
  //*********************************
  //PD2
sprintf(m1,"tmaxt0_vs_tls2_mod%d",i);
htmaxt0_vs_tls2[i]=new TH2F(m1, m1, 100, 10, 3000, 100, 10, 500);

sprintf(m1,"rc2_vs_chi2_mod%d",i);
hrc_vs_chi2[i]=new TH2F(m1, m1, 100, 0, 10, 100, 200, 800);

sprintf(m1,"tls2_vs_chi2_mod%d",i);
htls2_vs_chi2[i]=new TH2F(m1, m1, 100, 0, 10, 100, 10, 3000);

sprintf(m1,"tmaxt0_vs_chi2_mod%d",i);
htmaxt0_vs_chi2[i]=new TH2F(m1, m1, 100, 0, 10, 100, 10, 500);

//*******************

sprintf(m1,"pds0_mod%d",i);
hpds0[i]=new TH1F(m1,m1,200,100,1500);

sprintf(m1,"pds1_mod%d",i);
hpds1[i]=new TH1F(m1,m1,200,100,1500);

sprintf(m1,"pds2_mod%d",i);
hpds2[i]=new TH1F(m1,m1,200,100,1500);

sprintf(m1,"pdrms0_mod%d",i);
hpdr0[i]=new TH1F(m1,m1,100,10,1500);

sprintf(m1,"pdrms1_mod%d",i);
hpdr1[i]=new TH1F(m1,m1,100,10,1500);

sprintf(m1,"pdrms2_mod%d",i);
hpdr2[i]=new TH1F(m1,m1,100,10,1500);

//******************
sprintf(m1,"pds0_vs_pdrms0_mod%d",i);
hpds0_vs_pdr0[i]=new TH2F(m1, m1, 100, 0, 10, 1500, 100, 1500);

sprintf(m1,"pds1_vs_pdrms1_mod%d",i);
hpds1_vs_pdr1[i]=new TH2F(m1, m1, 100, 0, 10, 1500, 100, 1500);

sprintf(m1,"pds2_vs_pdrms2_mod%d",i);
hpds2_vs_pdr2[i]=new TH2F(m1, m1, 100, 0, 10, 1500, 100, 1500);



  }
//hpar4=new TH2F("hpar4", "p04_vs_p14", 400, 0, 400, 400, 0, 400);
//hp13_mod5=new TH1F("p13_mod5","p13_mod5",200, 10, 3000);
//hp23_mod5=new TH1F("p23_mod5","p23_mod5",200, 10, 3000); 
	

}
