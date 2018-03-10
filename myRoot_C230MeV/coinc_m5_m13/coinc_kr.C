{

  //gStyle->SetOptStat("");
gStyle->SetPalette(1);

char rootfile[300];

 TCutG *cutg1 = new TCutG("tm1Ltm1R",7);
 cutg1->SetPoint(0,213.113,257.6601);
 cutg1->SetPoint(1,258.2236,258.9472);
 cutg1->SetPoint(2,262.2039,242.6436);
 cutg1->SetPoint(3,255.57,225.9109);
 cutg1->SetPoint(4,209.1327,243.0726);
 cutg1->SetPoint(5,215.1032,258.0891);
 cutg1->SetPoint(6,213.113,257.6601);

 TCutG *cutg2 = new TCutG("tm2Ltm2",6);
 cutg2->SetPoint(0,218.2287,264.9569);
 cutg2->SetPoint(1,273.9051,264.9569);
 cutg2->SetPoint(2,273.9051,210.9616);
 cutg2->SetPoint(3,222.7737,214.0767);
 cutg2->SetPoint(4,223.91,265.9953);
 cutg2->SetPoint(5,218.2287,264.9569);


 TCutG *cutg3 = new TCutG("tm1Ltm2R",7);
 cutg3->SetPoint(0,203.8117,261.3795);
   cutg3->SetPoint(1,265.8326,261.3795);
   cutg3->SetPoint(2,266.9812,221.4105);
   cutg3->SetPoint(3,255.4958,204.6235);
   cutg3->SetPoint(4,206.1088,221.4105);
   cutg3->SetPoint(5,206.1088,263.7777);
   cutg3->SetPoint(6,203.8117,261.3795);

   TCutG *cutg4 = new TCutG("tm2Ltm1R",6);
   cutg4->SetPoint(0,203.8834,259.2964);
   cutg4->SetPoint(1,274.8592,258.9668);
   cutg4->SetPoint(2,270.9161,228.9694);
   cutg4->SetPoint(3,220.9701,232.5955);
   cutg4->SetPoint(4,214.3983,259.2964);
   cutg4->SetPoint(5,203.8834,259.2964);


TH2F *htm1tm2_1, *htm1tm2_2;
 TH2F *htm1Ltm1R, *htm2Ltm2R;
 TH2F *henLenR, *henLenRcut,*hp14Lp14R;
 TH1F *henL, *henR;


htm1tm2_1 = new TH2F("tm1tm2_1","tm1tm2_1",100,100,300,100,100,300);
htm1tm2_2 = new TH2F("tm1tm2_2","tm1tm2_2",100,100,300,100,100,300);

htm1Ltm1R = new TH2F("tm1Ltm1R","tm1Ltm1R",250,0,500,250,0,500);
htm2Ltm2R = new TH2F("tm2Ltm2R","tm2Ltm2R",250,0,500,250,0,500);
htm1Ltm2R = new TH2F("tm1Ltm2R","tm1Ltm2R",250,0,500,250,0,500);
htm2Ltm1R = new TH2F("tm2Ltm1R","tm2Ltm1R",250,0,500,250,0,500);


hp14Lp14R = new TH2F("p14Lp14R","p14Lp14R",100,0,300,100,0,300);

henLenR = new TH2F("enLenR","enLenR",100,0,300,100,0,300);
henLenRcut = new TH2F("enLenRcut","enLenRcut",100,0,300,100,0,300);

henL = new TH1F("enL","enL",100,0,300);
henR = new TH1F("enR","enR",100,0,300);






 TFile *fc=TFile::Open("/home/ciepal/Main/KRATTA/spall-2017-06/myRoot_C230MeV/myCuts.root");

 //########## a1 vs a2 ############

 TCutG *cut_pm5=(TCutG*)fc->Get("cut_am1_vs_am2_mod5")->Clone();
 TCutG *cut_pm13=(TCutG*)fc->Get("cut_am1_vs_am2_mod13")->Clone();
 
 

  //########## p10 vs p12+p13 ############
  
 TCutG *cutg_p1m5p=(TCutG*)fc->Get("cut_p10_vs_p12p13st_mod5")->Clone();
 TCutG *cutg_p1m13p=(TCutG*)fc->Get("cut_p10_vs_p12p13st_mod13")->Clone();

 fc->Close();
 delete fc;

 //***********************************

 TFile f1("/home/ciepal/Main/KRATTA/spall-2017-06/myRoot_C230MeV/KRAnal_mod4.root");
 if (f1.IsZombie()) cout<<"no file"<<endl;
 TTree *t1=(TTree*)f1.Get("TT");

  TFile f2("/home/ciepal/Main/KRATTA/spall-2017-06/myRoot_C230MeV/KRAnal_mod13.root");
 if (f2.IsZombie()) cout<<"no file"<<endl;
 TTree *t2=(TTree*)f2.Get("TT");



 int fev1, fev2,fm1, fm2;
 float ftls0,fa0,fa2,fa1, fp04,fp14,fp24,ftls01, ftls02; 
 float fp10_1,fp12_1,fp13_1,fp10_2,fp12_2,fp13_2;
 float fen_1,fen_2, ftm11, ftm21,ftm12, ftm22, fa01, fa11, fa21;
 float fa02, fa12, fa22,fp041,fp141,fp241, fp042,fp142,fp242;
float fcsi1_1, fcsi2_1, fcsi1_2,fcsi2_2;

 //TBranch *bEvent = t1->GetBranch("Event");
 //bEvent->SetAddress(&Event);
//Event

//mod 5
TBranch *bev1 = t1->GetBranch("evnb_1");
bev1->SetAddress(&fev1);
TBranch *bm1 = t1->GetBranch("mod_1");
bm1->SetAddress(&fm1);
TBranch *btls01 = t1->GetBranch("tls0_1");
btls01->SetAddress(&ftls01);
TBranch *btm11 = t1->GetBranch("tm1_1");
btm11->SetAddress(&ftm11);
TBranch *btm21 = t1->GetBranch("tm2_1");
btm21->SetAddress(&ftm21);

TBranch *ba01 = t1->GetBranch("a0_1");
ba01->SetAddress(&fa01);
TBranch *ba11 = t1->GetBranch("a1_1");
ba11->SetAddress(&fa11);
TBranch *ba21 = t1->GetBranch("a2_1");
ba21->SetAddress(&fa21);
TBranch *bp041 = t1->GetBranch("p04_1");
bp041->SetAddress(&fp041);
TBranch *bp141 = t1->GetBranch("p14_1");
bp141->SetAddress(&fp141);
TBranch *bp241 = t1->GetBranch("p24_1");
bp241->SetAddress(&fp241);

TBranch *bp10_1 = t1->GetBranch("p10_1");
bp10_1->SetAddress(&fp10_1);
TBranch *bp12_1 = t1->GetBranch("p12_1");
bp12_1->SetAddress(&fp12_1);
TBranch *bp13_1 = t1->GetBranch("p13_1");
bp13_1->SetAddress(&fp13_1);

TBranch *ben_1 = t1->GetBranch("en_1");
ben_1->SetAddress(&fen_1);

TBranch *bcsi1_1 = t1->GetBranch("enCsI1_1");
bcsi1_1->SetAddress(&fcsi1_1);
TBranch *bcsi2_1 = t1->GetBranch("enCsI2_1");
bcsi2_1->SetAddress(&fcsi2_1);





//mod 13
TBranch *bev2 = t2->GetBranch("evnb_2");
bev2->SetAddress(&fev2);
TBranch *bm2 = t2->GetBranch("mod_2");
bm2->SetAddress(&fm2);
TBranch *btls02 = t2->GetBranch("tls0_2");
btls02->SetAddress(&ftls02);
TBranch *btm12 = t2->GetBranch("tm1_2");
btm12->SetAddress(&ftm12);
TBranch *btm22 = t2->GetBranch("tm2_2");
btm22->SetAddress(&ftm22);

TBranch *ba02 = t2->GetBranch("a0_2");
ba02->SetAddress(&fa02);
TBranch *ba12 = t2->GetBranch("a1_2");
ba12->SetAddress(&fa12);
TBranch *ba22 = t2->GetBranch("a2_2");
ba22->SetAddress(&fa22);
TBranch *bp042 = t2->GetBranch("p04_2");
bp042->SetAddress(&fp042);
TBranch *bp142 = t2->GetBranch("p14_2");
bp142->SetAddress(&fp142);
TBranch *bp242 = t2->GetBranch("p24_2");
bp242->SetAddress(&fp242);
TBranch *bp10_2 = t2->GetBranch("p10_2");
bp10_2->SetAddress(&fp10_2);
TBranch *bp12_2 = t2->GetBranch("p12_2");
bp12_2->SetAddress(&fp12_2);
TBranch *bp13_2 = t2->GetBranch("p13_2");
bp13_2->SetAddress(&fp13_2);
TBranch *ben_2 = t2->GetBranch("en_2");
ben_2->SetAddress(&fen_2);
TBranch *bcsi1_2 = t2->GetBranch("enCsI1_2");
bcsi1_2->SetAddress(&fcsi1_2);
TBranch *bcsi2_2 = t2->GetBranch("enCsI2_2");
bcsi2_2->SetAddress(&fcsi2_2);


 Long64_t nevent1 = t1->GetEntries();
  cout<< nevent1<<endl;

for( Long64_t i=1; i<nevent1;i++)
{
  
  t1->GetEntry(i);
  t2->GetEntry(i);
  

  //cout<<fev1<<" "<<fev2<<" "<<ftm12<<endl;
 
 if(i%100000==0) cout<<i<<endl;

 //1-->5
 //2-->13
 //cout<<ftm22

       if (ftm11)htm1tm2_1->Fill(ftm21,ftm11); 
       if (ftm12)htm1tm2_2->Fill(ftm22,ftm12);
       henLenR->Fill(fen_1,fen_2);
       //henR->Fill(fen_2);
       //henL->Fill(fen_1);
       henR->Fill(fcsi1_1);henR->Fill(fcsi2_1);
       henL->Fill(fcsi1_2);henL->Fill(fcsi2_2);

       htm1Ltm1R->Fill(ftm11,ftm12);
       htm2Ltm2R->Fill(ftm21,ftm22);

       htm1Ltm2R->Fill(ftm11,ftm22);
       htm2Ltm1R->Fill(ftm21,ftm12);
//for mod 5 & 13
       //if ((ftm11>230 && ftm11<260 && ftm22>230 && ftm22<260)|| (ftm22>230 && ftm22<260 && ftm21>230 && ftm21<260 ) || (ftm12>230 && ftm12<260 && ftm21>230 && ftm21<260)||(ftm12>230 && ftm12<260 &&ftm11>230 && ftm11<260) )henLenRcut->Fill(fen_1,fen_2);
//for mod 4 & 13
if ((ftm11>150 && ftm11<270 && ftm22>150 && ftm22<270)|| (ftm22>150 && ftm22<270 && ftm21>150 && ftm21<270 ) || (ftm12>150 && ftm12<270 && ftm21>150 && ftm21<270)||(ftm12>150 && ftm12<270 &&ftm11>150 && ftm11<270) )henLenRcut->Fill(fen_1,fen_2);


       //hp14Lp14R->Fill(p14_1,p14_2);
//htm2Ltm2R->Fill(tm2_1,tm2_2);
     

 }
//###########################################

float x1=0.55, y1=0.71, x2=0.85, y2=0.82;
TPaveText *pt;
char aa[200], ab[200], ac[200];

TFile *fc1=new TFile("coinc_kr.root","recreate");

//************************

   TCanvas *c1 = new TCanvas("h","h");
   c1->Divide(2,2);

   c1->cd(1);
   htm1tm2_1->Draw("col");

   c1->cd(2);
   htm1tm2_2->Draw("col");
 

   c1->cd(3);
   henL->Draw();
  
   c1->cd(4);
   henR->Draw();
  
   

   //*******************
   TCanvas *c2 = new TCanvas("timeCorel5_13","timeCorel5_13");
   c2->Divide(2,2);

   c2->cd(1);
   htm1Ltm1R->Draw("col");

   c2->cd(2);
   htm2Ltm2R->Draw("col");

   c2->cd(3);
   htm1Ltm2R->Draw("col");
  
   c2->cd(4);
   htm2Ltm1R->Draw("col");
   
   TCanvas *c3 = new TCanvas("energyCorel5_13","energyCorel5_13");
   c3->Divide(2,1);

   c3->cd(1);
   henLenR->Draw("col");

   c3->cd(2);
   henLenRcut->Draw("col");


fc1->Write();
fc1->Close();;


}



