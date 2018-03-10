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
  //TFile* fi = TFile::Open("cuts_mod5.root");
  char cname1[100];
char cname2[100];

  //for (int i=70;i<160;i+=10){
    
//sprintf(cname1,"cutg_mod5_%d",Pen);
    //fcut_mod5[i/10]  = (TCutG*)fi->Get(cname)->Clone();
  
    //}

    //fcut1_mod5  = (TCutG*)fi->Get(cname1)->Clone();
 

//sprintf(cname2,"cutg2_mod5_%d",Pen);
//fcut2_mod5  = (TCutG*)fi->Get(cname2)->Clone();




//fi->Close();
// delete fi;
   
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
    TT.Branch("peak.mod",&peak_mod, "peak_mod/I");
    TT.Branch("peak.tls0",&peak_tls0, "peak_tls0/F");
    

	  
  if (fChain == 0) return;


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
	if(peak_mod[1]==1){ //&& peak_am2[1]==0){
 //cout<<peak_mod[1]<<" "<<peak_am1[1]<<endl;
	      //cout<<peak_mod[0]<<" "<<peak_am2[0]<<endl;
	      hamp01[0]->Fill(peak_am1[1],peak_am0[1]);
	      hamp12[0]->Fill(peak_am2[1],peak_am1[1]);
	      
	      if (peak_am2[1]==0)hp12_p13[0]->Fill(peak_p13[1],peak_p12[1]);
	      hp22_p23[0]->Fill(peak_p23[1],peak_p22[1]);
	      
	      hp12p13_p22p23[0]->Fill(peak_p23[1]+peak_p22[1],peak_p13[1]+peak_p12[1]);
	      hp00_p10p12p13[0]->Fill(peak_p10[1]+peak_p12[1]+peak_p13[1],peak_p00[1]);
	      hp10_p12p13[0]->Fill(peak_p12[1]+peak_p13[1],peak_p10[1]);
	      
	      
	     double x1=peak_p12[1]+peak_p13[1]-peak_p10[1]/33.5;
	     double y1=peak_p10[1]+peak_p10[1]/33.5;
	    
	     hp10p10_p12p13p10[0]->Fill(x1,y1);
	     
	     
	      double x2=peak_p12[1]/peak_p13[1];
	      double y2=log(peak_p12[1]+peak_p13[1]);
	      double x3=peak_p22[1]/peak_p23[1];
	      double y3=log(peak_p22[1]+peak_p23[1]);
	      
	      hslowfast_1[0]->Fill(x2,y2);
	      hslowfast_2[0]->Fill(x3,y3);
	      
	      
	      
	      
	     }
      //if (WriteTree) TT.Fill();
      }

		   
	
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
