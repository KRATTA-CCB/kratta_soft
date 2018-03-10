#include "KRAnal.h"
//#include "mktreedstchain_sct_fitABC.hxx"
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
  //gSystem->Load("libKRRun.so");
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

  cutg[5]=(TCutG*)fi->Get("cut_p10_vs_p12p13st_mod5")->Clone();
  cutg1[5]=(TCutG*)fi->Get("cut_am1_vs_am2_mod5")->Clone();

  cutg[7]=(TCutG*)fi->Get("cut_p10_vs_p12p13st_mod7")->Clone();
  cutg1[7]=(TCutG*)fi->Get("cut_am1_vs_am2_mod7")->Clone();

  cutg[11]=(TCutG*)fi->Get("cut_p10_vs_p12p13st_mod11")->Clone();
  cutg1[11]=(TCutG*)fi->Get("cut_am1_vs_am2_mod11")->Clone();
  cutg2[11]=(TCutG*)fi->Get("cut_p10_vs_enProt_mod11")->Clone();

  cutg[13]=(TCutG*)fi->Get("cut_p10_vs_p12p13st_mod13")->Clone();
  cutg1[13]=(TCutG*)fi->Get("cut_am1_vs_am2_mod13")->Clone();

  //fcut1_mod5  = (TCutG*)fi->Get(cname1)->Clone();
//sprintf(cname2,"cutg2_mod5_%d",Pen);
//fcut2_mod5  = (TCutG*)fi->Get(cname2)->Clone();


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


 //brak kalibracji dla mod 5, wspolczynniki sa jak dla mod 4
 p0_1[5]=16.299;
 p1_1[5]=0.0508;
 p2_1[5]=599.004;    

 p0_2[5]=89.735;
 p1_2[5]=0.06641;
 p2_2[5]=877.431; 


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


 p0_1[13]=16.3040;
 p1_1[13]=0.0422302;
 p2_1[13]=822.7445;    

 p0_2[13]=89.6153;
 p1_2[13]=0.0459601;
 p2_2[13]=393.5633;    



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

int nb1=0, nb2=0;
//TTree TT("TT","TreeKR");

// declare the tree structure
     



	  
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
      //LoadTree(event);

      fChain->GetEntry(event);

      //if(peak_){
	

  //cout<<evnb_1<<" "<<evnb_2<<endl;	

if (en_1)cout<<en_1<<endl;

 htm1tm2_1->Fill(tm2_1,tm1_1); 
 htm1tm2_2->Fill(tm2_1,tm1_1);
 htm1Ltm1R->Fill(tm1_1,tm1_2);
 htm2Ltm2R->Fill(tm2_1,tm2_2);
 henLenR->Fill(en_1,en_2);
 //henLenRcut;	  
	  
	  /*
	    mod_1;
	    tls0_1
	    tm1_1
	    tm2_1
	    a0_1
	    a1_1
	    a2_1
	    p04_1
	    p14_1
	    p24_1
	    p10_1
	    p12_1
	    p13_1
            p20_1
	    p22_1
	    p23_1
	    */
        


     
	      
	
      //}

		   
	
    }//end event loop 
  
   
  //TT.Write(); 
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
