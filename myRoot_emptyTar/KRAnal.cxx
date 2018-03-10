#include "KRAnal.h"
#include "mktreedstchain_sct_fitABC.hxx"
#include "TPaveText.h"
#include "TStyle.h"
#include "TH2F.h"
#include "TF1.h"
#include "TH2F.h"
#include "TText.h"
#include "TMath.h"
#include "TSystem.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "TCanvas.h"
#include "TPad.h"
#include "TCutG.h"


#define SQR(x) ((x)*(x))
using namespace std;

Int_t   nentries;

KRAnal *gKRA;  



//--------------------------------------------------------------------
KRAnal::KRAnal(TTree *tree):InheritClass(tree)
{
  gSystem->Load("libKRRun.so");
  gKRA = this;

  nentries = Int_t(fChain->GetEntries());
  printf("Entries in the tree: %d\n",nentries);
  
  strcpy(theOutFileName,"KRAnal.root");

  //!Open the nprun geometry
  if(!OpenGeometry())
    {
      printf("Error: The geometry can not be open!\n");
      return;
    }
 
  //CreateHistos();
}

//--------------------------------------------------------------------

#include "CreateHistos.cxx"
#include "WriteHistos.cxx"
//#include "WriteTGraphs.cxx"


void KRAnal::Init(void)
{
  CreateHistos();

 //Reading kinematic files
  TFile* fi = TFile::Open("myCuts.root");
  char cname1[100];
  char cname2[100];
  /*
  for (int i=0;i<16;i++){
    
    sprintf(cname1,"cut_m%d",i);
    cutg[i]=(TCutG*)fi->Get(cname1)->Clone();
  
    }
  */

  cutg[0]=(TCutG*)fi->Get("cut_p10_vs_p12p13st_mod0")->Clone();
  cutg1[0]=(TCutG*)fi->Get("cut_am1_vs_am2_mod0")->Clone();
  //cutg2[0]=(TCutG*)fi->Get("cut_p10_vs_enProt_mod4")->Clone();

  cutg[4]=(TCutG*)fi->Get("cut_p10_vs_p12p13st_mod4")->Clone();
  cutg1[4]=(TCutG*)fi->Get("cut_am1_vs_am2_mod4")->Clone();
  cutg2[4]=(TCutG*)fi->Get("cut_p10_vs_enProt_mod4")->Clone();

  cutg[7]=(TCutG*)fi->Get("cut_p10_vs_p12p13st_mod7")->Clone();
  cutg1[7]=(TCutG*)fi->Get("cut_am1_vs_am2_mod7")->Clone();

  cutg[11]=(TCutG*)fi->Get("cut_p10_vs_p12p13st_mod11")->Clone();
  cutg1[11]=(TCutG*)fi->Get("cut_am1_vs_am2_mod11")->Clone();
  cutg2[11]=(TCutG*)fi->Get("cut_p10_vs_enProt_mod11")->Clone();


  //fcut1_mod5  = (TCutG*)fi->Get(cname1)->Clone();
//sprintf(cname2,"cutg2_mod5_%d",Pen);
//fcut2_mod5  = (TCutG*)fi->Get(cname2)->Clone();

/*
 fcut1_mod14 = new TCutG("CUTG",6);
 fcut1_mod14->SetPoint(0,174.4628,1490.857);
 fcut1_mod14->SetPoint(1,2835.821,924.7094);
 fcut1_mod14->SetPoint(2,2068.121,755.3491);
 fcut1_mod14->SetPoint(3,225.6428,1132.781);
 fcut1_mod14->SetPoint(4,200.0528,1490.857);
 fcut1_mod14->SetPoint(5,174.4628,1490.857);
*/

 p0_1[0]=16.299;
 p1_1[0]=0.061035;
 p2_1[0]=883.279;    

 p0_2[0]=90.4732;
 p1_2[0]=0.081459;
 p2_2[0]=1283.3827;
     

 p0_1[4]=16.299;
 p1_1[4]=0.0508;
 p2_1[4]=599.004;    

 p0_2[4]=89.735;
 p1_2[4]=0.06641;
 p2_2[4]=877.431;    

 p0_1[7]=16.3033;
 p1_1[7]=0.067688;
 p2_1[7]=1789.1726;    

 p0_2[7]=90.6383;
 p1_2[7]=0.11219;
 p2_2[7]=1635.942;    


 p0_1[11]=16.298;
 p1_1[11]=0.0546;
 p2_1[11]=696.968;    

 p0_2[11]=89.68;
 p1_2[11]=0.06969;
 p2_2[11]=750.069;    




 fi->Close();
 delete fi;
   
}


//
//________________________________________________________________________
Int_t KRAnal::ReadLine(FILE *fID, char *line)
{
  char buff[128];
  char ch;

  while (  fgets(buff, 127, fID) != NULL) 
    {
      ch = buff[0];
      if (ch != '!' && ch != '*' && ch != '#') // some comment characters 
	{
	  strcpy(line, buff);
	  return 1;
	}
    }
  return EOF;
}

//--------------------------------------------------------------------
KRAnal::~KRAnal()
{
  WriteHistos();

  //for (int i=70;i<160;i+=10){
   
  //if(fcut_mod5[i/10]) delete fcut_mod5[i/10];
  
  //}

  //if(fcut1_mod5) delete fcut1_mod5;
 }

//--------------------------------------------------------------------
void KRAnal::Loop(Char_t * file)
{
 
	    
	    if(file == NULL)
	      {
		theOut=new TFile(theOutFileName,"recreate");
	      }


TTree TT("TT","TreeKR");

// declare the tree structure
     
//  TT.Branch("EventQuality",&EventQuality, "EventQuality/I" );
    TT.Branch("evnb",&evnb, "evnb/I");
    TT.Branch("mod_1",&mod_1, "mod_1/I");
    TT.Branch("tls0_1",&tls0_1, "tls0_1/F");
    TT.Branch("a0_1",&a0_1, "a0_1/F");
    TT.Branch("a1_1",&a1_1, "a1_1/F");
    TT.Branch("a2_1",&a2_1, "a2_1/F");
    TT.Branch("p04_1",&p04_1, "p04_1/F");
    TT.Branch("p14_1",&p14_1, "p14_1/F");
    TT.Branch("p24_1",&p24_1, "p24_1/F");
    TT.Branch("p10_1",&p10_1, "p10_1/F");
    TT.Branch("p12_1",&p12_1, "p12_1/F");
    TT.Branch("p13_1",&p13_1, "p13_1/F");
    TT.Branch("p20_1",&p20_1, "p20_1/F");
    TT.Branch("p22_1",&p22_1, "p22_1/F");
    TT.Branch("p23_1",&p23_1, "p23_1/F");




	  
  if (fChain == 0) return;

  //int tt= fChain->GetNtrees();
  //cout <<"  bbbbb "<<tt<<endl;


  for (Long_t event=0; event<nentries; event++) 
    {
      if(!(event%100000))  
	{
	  printf("Event: %ld\r",event);
	  fflush(stdout);
	}
      LoadTree(event);

      fChain->GetEntry(event);

      if(peak_){
	
	      
	      //cout<<peak_mod[1]<<" "<<peak_am0[1]<<" "<<peak_am1[1]<<" "<<peak_am2[1]<<endl;
	      //cout<<peak_mod[0]<<" "<<peak_am2[0]<<endl;
	      //if(peak_mod[1]==12 && peak_am0[1] && peak_am1[1] && peak_am2[1]==0){

	if(peak_mod[0]==0 || peak_mod[0]==4 || peak_mod[0]==7|| peak_mod[0]==11){

	  htm1[peak_mod[0]]->Fill(peak_tm1[0]);
	  hpdr1[peak_mod[0]]->Fill(peak_pdr1[0]);
	      
	  hchi21[peak_mod[0]]->Fill(peak_chi21[0]);
	  hpds1[peak_mod[0]]->Fill(peak_pds1[0]);	  

	  hamp01[peak_mod[0]]->Fill(peak_am1[0],peak_am0[0]);
          hamp12[peak_mod[0]]->Fill(peak_am2[0],peak_am1[0]);

	  hp12_p13[peak_mod[0]]->Fill(peak_p13[0],peak_p12[0]);
	  hp22_p23[peak_mod[0]]->Fill(peak_p23[0],peak_p22[0]);
	  
	  hp10_p12p13[peak_mod[0]]->Fill(peak_p12[0]+peak_p13[0],peak_p10[0]);
	  int fl1=0;

	  if (peak_p22[0]==0 && peak_p23[0]==0 && peak_am2[0]<10)fl1=1;
	  if (fl1)hp10_p12p13st[peak_mod[0]]->Fill(peak_p12[0]+peak_p13[0],peak_p10[0]);

          //hp20_p22p23[peak_mod[0]]->Fill(peak_p22[0]+peak_p23[0],peak_p20[0]);
	  //cout<<peak_mod[0]<<endl;
  if (cutg[peak_mod[0]]->IsInside(peak_p12[0]+peak_p13[0],peak_p10[0]) && fl1){
 //if ( fl1){
  hp10_p12p13stCut[peak_mod[0]]->Fill(peak_p12[0]+peak_p13[0],peak_p10[0]);
 float x1=peak_p12[0]+peak_p13[0];
 //float x2=peak_p22[0]+peak_p23[0];

 
   enCsI1= p0_1[peak_mod[0]] + p1_1[peak_mod[0]]*(x1 - p2_1[peak_mod[0]]*log(1+x1/p2_1[peak_mod[0]]));
   //enCsI2= p0_2[peak_mod[0]] + p1_2[peak_mod[0]]*(x2 - p2_2[peak_mod[0]]*log(1+x2/p2_2[peak_mod[0]]));

   if (peak_pdr1[0]<5. && peak_pds1[0]>0 && peak_tm1[0]>140 && peak_tm1[0]<300 && peak_chi21[0]<1.){

  if(peak_mod[0]==4 || peak_mod[0]==11 ){
     if(cutg2[peak_mod[0]]->IsInside(enCsI1,peak_p10[0])){
//if(cutg2[4]->IsInside(enCsI1,peak_p10[0]))

       hen_prot[peak_mod[0]]->Fill(enCsI1);
       hp10_enProt[peak_mod[0]]->Fill(enCsI1,peak_p10[0]);
     }
     }else {
     hen_prot[peak_mod[0]]->Fill(enCsI1);
       hp10_enProt[peak_mod[0]]->Fill(enCsI1,peak_p10[0]);
     
     }
     
     hp12p13c[peak_mod[0]]->Fill(enCsI1);
     hp12p13[peak_mod[0]]->Fill(x1);
   }
    
 }
	 
 if (cutg1[peak_mod[0]]->IsInside(peak_am2[0],peak_am1[0])){
 //if (cutg1[4]->IsInside(peak_am2[0],peak_am1[0])){
 hamp12Cut[peak_mod[0]]->Fill(peak_am2[0],peak_am1[0]);
  
 
   float x2=peak_p22[0]+peak_p23[0];

 
   //enCsI1= p0_1[peak_mod[0]] + p1_1[peak_mod[0]]*(x1 - p2_1[peak_mod[0]]*log(1+x1/p2_1[peak_mod[0]]));
   enCsI2= p0_2[peak_mod[0]] + p1_2[peak_mod[0]]*(x2 - p2_2[peak_mod[0]]*log(1+x2/p2_2[peak_mod[0]]));

   if (peak_pdr1[0]<5. && peak_pds1[0]>0 && peak_tm1[0]>140 && peak_tm1[0]<300 && peak_chi21[0]<1.){
   
     if (peak_mod[0]==4 || peak_mod[0]==11){
       if(cutg2[peak_mod[0]]->IsInside(enCsI2,peak_p10[0])){
	 //if(cutg2[4]->IsInside(enCsI2,peak_p10[0])){
    
	 hen_prot[peak_mod[0]]->Fill(enCsI2);
	 hp10_enProt[peak_mod[0]]->Fill(enCsI2,peak_p10[0]);
       }
     }else{
 
       hen_prot[peak_mod[0]]->Fill(enCsI2);
       hp10_enProt[peak_mod[0]]->Fill(enCsI2,peak_p10[0]);
   
     }

 
     hp22p23c[peak_mod[0]]->Fill(enCsI2);
     hp22p23[peak_mod[0]]->Fill(x2);
   }

 }
	 



	    //********************************
   
	    //******************************************
	  /*
	    mod_1=peak_mod[1];
	    tls0_1=peak_tls0[1];
	    a0_1=peak_am0[1];
	    a1_1=peak_am1[1];
	    a2_1=peak_am2[1];
	    p04_1=peak_p04[1];
	    p14_1=peak_p14[1];
	    p24_1=peak_p24[1];
	    p10_1=peak_p10[1];
	    p12_1=peak_p12[1];
	    p13_1=peak_p13[1];
            p20_1=peak_p20[1];
	    p22_1=peak_p22[1];
	    p23_1=peak_p23[1];
            

           TT.Fill();
	  */

     
	      
	}
      //if (WriteTree) 
      //TT.Fill();
      }

		   
	
    }//end event loop 
  
 
  
  TT.Write(); 
}

//------------------------------------------------------------------
Int_t KRAnal::OpenGeometry()
{
    return 1;//OK
}

//void KRAnal::CreateHistos(void){
//}

//void KRAnal::WriteHistos(void){
//}
