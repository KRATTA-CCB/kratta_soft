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

  for (int i=0;i<16;i++){
    
    sprintf(cname1,"cut_m%d",i);
    cutg[i]=(TCutG*)fi->Get(cname1)->Clone();
  
    }

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

  p14min[0]=150;p14max[0]=170;
  p24min[0]=150;p24max[0]=175;

  p14min[1]=154;p14max[1]=166;
  p24min[1]=153;p24max[1]=173;

  p14min[2]=164;p14max[2]=178;
  p24min[2]=150;p24max[2]=172;

  p14min[3]=140;p14max[3]=190;
  p24min[3]=140;p24max[3]=190;

  p14min[4]=150;p14max[4]=170;
  p24min[4]=160;p24max[4]=170;

  p14min[5]=156;p14max[5]=166;
  p24min[5]=154;p24max[5]=172;

  p14min[6]=154;p14max[6]=166;
  p24min[6]=158;p24max[6]=172;

  p14min[7]=152;p14max[7]=166;
  p24min[7]=160;p24max[7]=172;
 
  //??
  p14min[9]=172;p14max[9]=186;
  p24min[9]=178;p24max[9]=194;

  p14min[11]=176;p14max[11]=190;
  p24min[11]=180;p24max[11]=196;

  //??
  p14min[12]=156;p14max[12]=166;
  p24min[12]=162;p24max[12]=174;

  p14min[13]=170;p14max[13]=194;
  p24min[13]=170;p24max[13]=194;

  //p14min[13]=150;p14max[13]=194;
  //p24min[13]=150;p24max[13]=194;



  p14min[15]=136;p14max[15]=195;
  p24min[15]=136;p24max[15]=195;

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
	if(peak_mod[1]>-1){

	  hrc00[peak_mod[1]]->Fill(peak_rc0[1]);
	  htls00[peak_mod[1]]->Fill(peak_tls0[1]);
	      
	  hrc10[peak_mod[1]]->Fill(peak_rc1[1]);
	  htls10[peak_mod[1]]->Fill(peak_tls1[1]);	  
	  
	  hamp01[peak_mod[1]]->Fill(peak_am1[1],peak_am0[1]);
          hamp12[peak_mod[1]]->Fill(peak_am2[1],peak_am1[1]);

	  hp14_p24[peak_mod[1]]->Fill(peak_p24[1],peak_p14[1]);
	  hp12_p13[peak_mod[1]]->Fill(peak_p13[1],peak_p12[1]);
	  hp22_p23[peak_mod[1]]->Fill(peak_p23[1],peak_p22[1]);

	  if (cutg[peak_mod[1]]->IsInside(peak_am1[1],peak_am0[1])){
	    //RC
	    hamp01a[peak_mod[1]]->Fill(peak_am1[1],peak_am0[1]);
	    hrc0[peak_mod[1]]->Fill(peak_rc0[1]);
	    htls0[peak_mod[1]]->Fill(peak_tls0[1]);
	    
	    hrc1[peak_mod[1]]->Fill(peak_rc1[1]);
	    htls1[peak_mod[1]]->Fill(peak_tls1[1]);	      
	    //if(peak_am1[1]==0)cout<<peak_tls1[1]<<endl;
	  }
	  
	  if (peak_am0[1]<=0. && peak_am1[1]<=0.){
	    //RC2
	    //cout<<peak_tls2[1]<<endl;
	    hrc2[peak_mod[1]]->Fill(peak_rc2[1]);
	    htls2[peak_mod[1]]->Fill(peak_tls2[1]);
		    
                          }	    
	    
	  //********************************
	  //15;7- moduly satelitarne
 
	  if(peak_mod[1]==15){ 
	    evnb=event;
	 
	    //PD2 checking
	    float tdiff=peak_at2[1]-peak_tm2[1];
	    htmaxt0_vs_tls2[peak_mod[1]]->Fill(peak_tls2[1],tdiff);
	    hrc_vs_chi2[peak_mod[1]]->Fill(peak_chi22[1],peak_rc2[1]);
	    htls2_vs_chi2[peak_mod[1]]->Fill(peak_chi22[1],peak_tls2[1]);
	    htmaxt0_vs_chi2[peak_mod[1]]->Fill(peak_chi22[1],tdiff);


	    //******************************
	    int flag=0;
	    //koincydencje cienki-gruby krysztal
	    if(peak_p14[1]>p14min[peak_mod[1]] && peak_p14[1]<p14max[peak_mod[1]] && peak_p24[1]>p24min[peak_mod[1]] && peak_p24[1]<p24max[peak_mod[1]])flag=1;

	    hpds0[peak_mod[1]]->Fill(peak_pds0[1]);
	    hpds1[peak_mod[1]]->Fill(peak_pds1[1]);
	    hpds2[peak_mod[1]]->Fill(peak_pds2[1]);

	    hpdr0[peak_mod[1]]->Fill(peak_pdr0[1]);
	    hpdr1[peak_mod[1]]->Fill(peak_pdr1[1]);
	    hpdr2[peak_mod[1]]->Fill(peak_pdr2[1]);
	    hp10_p12p13[peak_mod[1]]->Fill(peak_p13[1]+peak_p12[1],peak_p10[1]);

	    if (peak_pds1[1]<500){
	    hp12_p13a[peak_mod[1]]->Fill(peak_p13[1],peak_p12[1]);
	    hp22_p23a[peak_mod[1]]->Fill(peak_p23[1],peak_p22[1]);

	    if(flag){
	      hp12_p13ac12[peak_mod[1]]->Fill(peak_p13[1],peak_p12[1]);
	      hp22_p23ac12[peak_mod[1]]->Fill(peak_p23[1],peak_p22[1]);
	    }
	    }
	    if (peak_pds1[1]>500){
	    hp12_p13b[peak_mod[1]]->Fill(peak_p13[1],peak_p12[1]);
	    hp22_p23b[peak_mod[1]]->Fill(peak_p23[1],peak_p22[1]);

	    if(flag){
	      hp12_p13bc12[peak_mod[1]]->Fill(peak_p13[1],peak_p12[1]);
	      hp22_p23bc12[peak_mod[1]]->Fill(peak_p23[1],peak_p22[1]);
	    }
	    
	    }

	    if(flag){
	      hp12_p13c12[peak_mod[1]]->Fill(peak_p13[1],peak_p12[1]);
	      hp22_p23c12[peak_mod[1]]->Fill(peak_p23[1],peak_p22[1]);
	      hamp12a[peak_mod[1]]->Fill(peak_am2[1],peak_am1[1]);
	      hp10_p12p13c[peak_mod[1]]->Fill(peak_p13[1]+peak_p12[1],peak_p10[1]);
    hamp01a[peak_mod[1]]->Fill(peak_am1[1],peak_am0[1]);
	      
	    }

	    //********************************
	    hpds0_vs_pdr0[peak_mod[1]]->Fill(peak_pdr0[1],peak_pds0[1]);
	    hpds1_vs_pdr1[peak_mod[1]]->Fill(peak_pdr1[1],peak_pds1[1]);
	    hpds2_vs_pdr2[peak_mod[1]]->Fill(peak_pdr2[1],peak_pds2[1]);

	   
	    //******************************************
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
	  }


	  
	  //****************************************
	      //a0=peak_am0[1];
	      //a1=peak_am1[1];
	      //a2=peak_am2[1];
		//TT.Fill();
	      /*
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
