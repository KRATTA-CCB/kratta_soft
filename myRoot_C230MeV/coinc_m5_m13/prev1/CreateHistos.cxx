
void KRAnal::CreateHistos(void)
{
  char d0[100],d1[100],d2[100];
  char m[100], m1[100], m2[100], m2a[100];


htm1tm2_1 = new TH2F("tm1tm2_1","tm1tm2_1",100,100,300,100,100,300);
htm1tm2_2 = new TH2F("tm1tm2_2","tm1tm2_2",100,100,300,100,100,300);

htm1Ltm1R = new TH2F("tm1Ltm1R","tm1Ltm1R",100,100,300,100,100,300);
htm2Ltm2R = new TH2F("tm1Ltm1R","tm1Ltm1R",100,100,300,100,100,300);
henLenR = new TH2F("enLenR","enLenR",100,0,300,100,0,300);
henLenRcut = new TH2F("enLenRcut","enLenRcut",100,0,300,100,0,300);




}
