
void KRAnal::CreateHistos(void)
{
  char d0[100],d1[100],d2[100];
  char m[100], m1[100], m2[100], m2a[100];



  for (int i=0;i<16;i++){
    
    sprintf(m,"am0_vs_am1_mod%d",i);
    sprintf(m1,"am1_vs_am2_mod%d",i);

    hamp01[i]=new TH2F(m, m, 500, 10, 6000, 500, 40, 5000);
    hamp12[i]=new TH2F(m1, m1, 500, 50, 4000, 500, 6, 4000);


    sprintf(m2,"am0_vs_am1_Cut_mod%d",i);
    sprintf(m2a,"am1_vs_am2_Cut_mod%d",i);

    hamp01Cut[i]=new TH2F(m2, m2, 500, 10, 6000, 500, 40, 5000);
    hamp12Cut[i]=new TH2F(m2a, m2a, 500, 50, 4000, 500, 6, 4000);

 
    sprintf(m,"p12_vs_p13_mod%d",i);
    hp12_p13[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);
 

    sprintf(m,"p22_vs_p23_mod%d",i);
    hp22_p23[i]=new TH2F(m, m, 200, 10, 3000, 200, 10, 3500);


    sprintf(m,"p10_vs_p12p13_mod%d",i);
    hp10_p12p13[i]=new TH2F(m, m, 500, 40, 5000, 500, 40, 6000);

    sprintf(m,"p10_vs_p12p13st_mod%d",i);
    hp10_p12p13st[i]=new TH2F(m, m, 500, 40, 5000, 500, 40, 6000);

    sprintf(m,"p10_vs_p12p13stCut_mod%d",i);
    hp10_p12p13stCut[i]=new TH2F(m, m, 500, 40, 5000, 500, 40, 6000);


    sprintf(m,"p10_vs_enProt_mod%d",i);
    hp10_enProt[i]=new TH2F(m, m, 500, 0, 250, 500, 40, 2000);



    sprintf(m,"p22p23_mod%d",i);
    hp22p23[i]=new TH1F(m, m, 500, 40, 5000);
    
    sprintf(m,"p12p13_mod%d",i);
    hp12p13[i]=new TH1F(m, m, 500, 40, 5000);


    sprintf(m,"p22p23c_mod%d",i);
    hp22p23c[i]=new TH1F(m, m, 500, 0, 250);
    
    sprintf(m,"p12p13c_mod%d",i);
    hp12p13c[i]=new TH1F(m, m, 500, 0, 250);

    sprintf(m,"en_prot_mod%d",i);
    hen_prot[i]=new TH1F(m, m, 1000, 0, 250);


 //*******************************


 sprintf(m,"tm1_mod%d",i);
 htm1[i]=new TH1F(m,m,200,0,1000);

 sprintf(m,"pdr1_mod%d",i);
 hpdr1[i]=new TH1F(m,m,200,0,600);

 sprintf(m,"chi21_mod%d",i);
 hchi21[i]=new TH1F(m,m,200,0,600);
 

 sprintf(m,"pds1_mod%d",i);
 hpds1[i]=new TH1F(m,m,1000,0,6000);





  }
//hpar4=new TH2F("hpar4", "p04_vs_p14", 400, 0, 400, 400, 0, 400);
//hp13_mod5=new TH1F("p13_mod5","p13_mod5",200, 10, 3000);
//hp23_mod5=new TH1F("p23_mod5","p23_mod5",200, 10, 3000); 
	

}
