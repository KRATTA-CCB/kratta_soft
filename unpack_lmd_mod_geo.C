#ifndef __CINT__

// #include <math.h>
// 
// #include "TFile.h"
#include "TTimer.h"
#include "Getline.h"
#include "TSystem.h"
#include "TProfile.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH1.h"
#include "TH2F.h"
#include "TDirectory.h"
// #include "TRandom.h"
// #include "TNtuple.h"
#include "TCanvas.h"
// #include "TTree.h"
#include "TStyle.h"
// #include "TChain.h"
// #include "TF1.h"
// #include "TLatex.h"
// #include "TBranch.h"
// #include "TCutG.h"
// #include "TROOT.h"
// #include "TLine.h"
// #include "TLegend.h"
// #include "TChainElement.h"
// #include "TSpectrum.h"
// #include "TSystem.h"
// #include "TMarker.h"

#include "TAGroot.hxx"
#include "TAGmbsEvent.hxx"
#include "TAGactMbsReader.hxx"
#include "TAGaction.hxx"
#include "TAGmbsEventFilterType.hxx"

#include <stdlib.h>
#include <signal.h>

#include "TROOT.h"
#include "TControlBar.h"
#include "TApplication.h"
#include "TSystem.h"
#include "TString.h"


#endif
#include "mktreeraw.hxx"
#include "geo.hxx"


void  INThandler(int sig); //handling signal interruption


int ievt = 1;
int iauto = 0;


void unpack_lmd_mod_geo(int irun=2){


signal(SIGINT, INThandler);
gStyle->SetOptStat(0);
gStyle->SetOptFit(1111);
//gStyle->SetOptDate();
gStyle->SetOptTitle(1);

  ASYgeo *gg = new ASYgeo();
  gg->ReadGeo(Form("%s/geo/geo_map.geo",gSystem->ExpandPathName("$S394WRK")));



  TAGroot tagroot;
  TAGmbsEvent *mbs_sevt = new TAGmbsEvent();
  TAGmbsIStream *a_in = new TAGmbsIStream();


//a_in->Open("/data/run2969.lmd");
//a_in->Open("/data/run2972.lmd");
//a_in->Open("/data/run2979.lmd");
//a_in->Open("/data/run2980.lmd");
//a_in->Open("/data/run2981.lmd");
//a_in->Open("/data/run3016.lmd");
//a_in->Open("/data/run3018.lmd");
//a_in->Open("/data/run3023.lmd");
// a_in->Open("/data/run3030.lmd");
//a_in->Open("/data/run3056.lmd");
//a_in->Open("/data/run3061.lmd"); //80 nA
//a_in->Open("/data/run3063.lmd"); //160 nA

//a_in->Open("/data/run3285.lmd"); //100 nA
//a_in->Open("/data/run3290.lmd"); //100 nA
//a_in->Open("/data/sample2.lmd"); //100 nA
//a_in->Open("/data/run3291.lmd"); //100 nA
//a_in->Open("/data/run3291.lmd"); //100 nA
//a_in->Open("/data/run3294.lmd"); //100 nA

//a_in->Open("/data/run3202.lmd"); //100 nA
//a_in->Open("/data/run3484.lmd"); //100 nA
//a_in->Open("/data/run3653.lmd"); //85 MeV p+Pb 70 nA
//a_in->Open("/data/run3654.lmd"); //85 MeV p+Pb 150 nA ~20% pileups
//a_in->Open("/data/run3748.lmd"); //85 MeV p+Pb 150 nA ~20% pileups
//a_in->Open("/data/run3761.lmd"); //180 MeV p+Pb 
//a_in->Open("/data/run3766.lmd"); //200 MeV p+Pb 
//a_in->Open("/data/run3772.lmd"); //200 MeV p+Pb 

//a_in->Open("/data/run3896.lmd"); //200 MeV p+Pb 
//a_in->Open("/data/run3898.lmd"); //200 MeV p+Pb x4 na FADC0

//a_in->Open("/data/run3987.lmd"); //230 MeV p+Pb
//a_in->Open("/data/run3987.lmd"); //230 MeV p+Pb

//a_in->Open("/data/run4101.lmd"); //230 MeV p+Pb
// a_in->Open("/data/run4145.lmd"); //230 MeV p+Pb
//a_in->Open("/data/run4278.lmd"); //230 MeV p+Pb

//a_in->Open("/data/cosmics4286.lmd"); //szumi PD1 3/0
//a_in->Open("/data/cosmics4287.lmd"); 

//a_in->Open("/data/run4304.lmd"); 

// 26.09.2016
//a_in->Open("/data/09_2016/run4474.lmd"); 
//a_in->Open("/data/09_2016/run4475.lmd"); 
//a_in->Open("/data/09_2016/run4476.lmd"); 
//a_in->Open("/data/09_2016/run4481.lmd"); 
// a_in->Open("/data/09_2016/run4482.lmd"); 
// a_in->Open("/data/01_2017/run4722.lmd"); 
//a_in->Open("/data/01_2017/run4726.lmd"); //KRATTA + HECTOR bez plastiku
//a_in->Open("/data/01_2017/run4759.lmd"); //KRATTA + HECTOR bez plastiku

//a_in->Open("/data/01_2017/run4759.lmd"); 
// a_in->Open("/data/01_2017/run4720.lmd"); 

//a_in->Open("/data/01_2017/run4879.lmd");
//a_in->Open("/data/01_2017/run4924.lmd");
//a_in->Open("/data/01_2017/run4929.lmd");
// a_in->Open("/data/01_2017/run4989.lmd");
//a_in->Open("/data/01_2017/run5030.lmd");
//a_in->Open("/data/01_2017/run5062.lmd");
//a_in->Open("/data/01_2017/run5302.lmd");
//a_in->Open("/data/01_2017/run5819.lmd");
//a_in->Open("/data/spall_2017_06/run6801.lmd");
//a_in->Open("/data/spall_2017_06/run6846.lmd");
//a_in->Open("/data/spall_2017_06/run7062.lmd");
//a_in->Open("/data/spall_2017_06/run7065.lmd");
//a_in->Open("/data/spall_2017_06/run7079.lmd");
//a_in->Open("/data/spall_2017_06/run7086.lmd");
//a_in->Open("/data/spall_2017_06/run7259.lmd");
//a_in->Open("/data/spall_2017_06/run7368.lmd");
a_in->Open("/data/spall_2017_06/cosmic7406.lmd");

  TAGmbsEventFilterType* mbs_filt = new TAGmbsEventFilterType(36,10);

  Int_t i_nevent = 0;
  const int NROW = 4;
  const int NCOL = 8;

  TTimer  *timer = new TTimer("gSystem->ProcessEvents();", 50, kFALSE);

  TCanvas* cf = new TCanvas("cf","FADC",0,0,900,900);
  cf->Divide(NCOL,3*NROW,0.001,0.001,10);
  cf->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", 0,0, "ProcEvent(Int_t,Int_t,Int_t,TObject*)");

    TH1F *hraw[NCOL*NROW][3]={{0,0,0}};
    bool fired[NCOL*NROW][3]={{0,0,0}};
    TH1F *hinteg =0;
  


int empty_evt=0; 
int evtcount=0; 
int big_count=0;
int big_count8[8]={0}; 
lab:
cf->Clear();
cf->Divide(NCOL,3*NROW,0.001,0.001,10);
bool big_found=false;
        int maxch = -1;
        float dchmax=0;
//  while(!big_found){
  for(int ievt0=0;ievt0<ievt;ievt0++){
    for(int im=0;im<NCOL*NROW;im++){
      for(int is=0;is<3;is++){
        fired[im][is]=false;
      }
    }
  if(!a_in->Eof()) {
    a_in->ReadEvent(mbs_sevt, mbs_filt);
    Int_t i_nse = mbs_sevt->NSubEvent();
    Int_t e_rawid = mbs_sevt->EventRawId();
    Int_t e_trigg = mbs_sevt->EventTrigger();
    printf("-------> Event %9d EventV1724 %9d NSubEvent %3d\n",evtcount,i_nevent,i_nse);
    printf("EventRawId: %d Trigger: %d\n",e_rawid,e_trigg);
    //Short_t ccn = gTAGroot->CurrentCampaignNumber(); 
    //Short_t crn = gTAGroot->CurrentRunNumber();
    //Int_t   cen = gTAGroot->CurrentEventNumber();
    //printf("-------> %3d %3d %9d\n",ccn,crn,cen);
    //TAGeventId cei = gTAGroot->CurrentEventId();
    //printf("-------> %9d \n",cei.EventNumber());
//    if(e_trigg!=3) continue;


  for (Int_t i_se = 0; i_se < i_nse; i_se++) {
      Int_t i_nw         = mbs_sevt->SubEventSize(i_se);
      Int_t i_setyp      = mbs_sevt->SubEventType(i_se);
      Int_t i_sestyp     = mbs_sevt->SubEventSubType(i_se);
      Int_t i_procid     = mbs_sevt->SubEventProcId(i_se);
      Int_t i_proctyp    = mbs_sevt->SubEventProcType(i_se);
      Int_t i_crate      = mbs_sevt->SubEventCrate(i_se);
      const UInt_t* p_se = mbs_sevt->SubEventData(i_se);

      empty_evt=1; 

	//Extract trigger pattern
	if ( ( i_setyp==36 ) && ( i_sestyp == 2800 ) ){
		int Trig_Patt=-10;
		Trig_Patt = p_se[0] ;//-> Data(0);
		cout << "Trigger pattern: "<< Trig_Patt << endl;
		//cout << "Trigger pattern(oct): " << oct << Trig_Patt << ")" << endl;
		cout << "Trigger pattern (bin): ";
		if(Trig_Patt & 0x0001) cout << "1"; else cout << "0";//1
		if(Trig_Patt & 0x0002) cout << "1"; else cout << "0";//2
		if(Trig_Patt & 0x0004) cout << "1"; else cout << "0";//4
		if(Trig_Patt & 0x0008) cout << "1"; else cout << "0";//8
		if(Trig_Patt & 0x0010) cout << "1"; else cout << "0";//16
		if(Trig_Patt & 0x0020) cout << "1"; else cout << "0";//32
		if(Trig_Patt & 0x0040) cout << "1"; else cout << "0";//64
		if(Trig_Patt & 0x0080) cout << "1"; else cout << "0";//128
		if(Trig_Patt & 0x0100) cout << "1"; else cout << "0";//256
		if(Trig_Patt & 0x0200) cout << "1"; else cout << "0";//512 	<-
		if(Trig_Patt & 0x0400) cout << "1"; else cout << "0";//1024	<-
		if(Trig_Patt & 0x0800) cout << "1"; else cout << "0";//2048
		if(Trig_Patt & 0x1000) cout << "1"; else cout << "0";
		if(Trig_Patt & 0x2000) cout << "1"; else cout << "0";
		if(Trig_Patt & 0x4000) cout << "1"; else cout << "0";
		if(Trig_Patt & 0x8000) cout << "1"; else cout << "0";
		cout << endl;
	} 

//    if(i_setyp == 36 && i_sestyp!=2800){//V1724
    if(i_setyp == 36 && i_sestyp==1){//V1724
      empty_evt=0; 
    
      printf("V1724\n");
      printf("SubEventType:     %d\n",i_setyp);
      printf("SubEventSize:     %d\n",i_nw);
      printf("SubEventSubType:  %d\n",i_sestyp);
      printf("SubEventProcId:   %d\n",i_procid);
      printf("SubEventProcType: %d\n",i_proctyp);
      printf("SubEventCrate:    %d\n",i_crate);
      if(i_nw>0){
        Int_t i_EVENT_SIZE0   = i_nw;
        Int_t addr_mod=2;
        do{
        Int_t i_EVENT_SIZE    = (p_se[addr_mod+0]) & 0xfffffff;
        Char_t i_1010         = Char_t((p_se[addr_mod+0]>>28) & 0xf);
        Int_t i_CHANNEL_MASK  = (p_se[addr_mod+1]) & 0xff;
        Int_t i_PATTERN       = (p_se[addr_mod+1]>>8) & 0xffff;
        Int_t i_RES           = (p_se[addr_mod+1]>>25) & 0x3;
        Int_t i_BOARD_ID      = (p_se[addr_mod+1]>>27) & 0x1f;
        Int_t i_EVENT_COUNTER = (p_se[addr_mod+2]) & 0xffffff;
        Int_t i_TRIG_TIME_TAG = (p_se[addr_mod+3]);
         printf("%d %d\n",i_1010,i_EVENT_SIZE);
         printf("BOARD_ID %d %d %d %d\n",i_BOARD_ID,i_RES,i_PATTERN,i_CHANNEL_MASK);
         printf("%d\n",i_EVENT_COUNTER);
         printf("%d\n",i_TRIG_TIME_TAG);
        int ich_indx=0;
        for(int ich = 0;ich<8;ich++){  
          if(i_CHANNEL_MASK & (1 << ich)){ //fired channel
            ich_indx++;
          }
        }
        // printf("No. fired channels %d\n",ich_indx);
        Int_t n_sample = 0;
        if(ich_indx>0) n_sample = 2*(i_EVENT_SIZE-4)/ich_indx;
         printf("SAMPLE %d\n",n_sample);
        float chmin =  1.e9;
        float chmax = -1.e9;
        ich_indx=0;
        for(int ich = 0;ich<8;ich++){  

	  int ggi  = gg->GetIndexFromFadc(i_BOARD_ID, ich);
	  int mod  = gg->GetModuleNo(ggi);
	  int isig = gg->GetSignalNo(ggi);
	  //printf("%8d %2d %d %2d %2d\n",ievt,i_BOARD_ID, ich,mod,isig);
          if(mod<0 || mod>=NCOL*NROW){
            printf("bad MOD %d\n",mod);
            continue;
          }
        
          if(!hraw[mod][isig]){// create hist
            hraw[mod][isig] = new TH1F(Form("_sign_hraw[%d][%d]",mod,isig),
            Form("_sign_hraw[%d][%d]",mod,isig),n_sample, 0., float(n_sample));
            if(isig==0) hraw[mod][isig]->SetLineColor(2);
            if(isig==1) hraw[mod][isig]->SetLineColor(4);
            if(isig==2) hraw[mod][isig]->SetLineColor(1);
          }
          hraw[mod][isig]->SetTitle(Form("r_%04d_e_%d_m_%02d_s_%d_%s",irun,i_nevent,mod,isig,(char*)gg->GetLabel(ggi).c_str()));

          if(i_CHANNEL_MASK & (1 << ich)){ //fired channel
            fired[mod][isig]=true;
            int ii=1;
            float pds=0;
            for(int is = 0;is<n_sample/2;is++){
             Int_t i_data_lsb  = (p_se[addr_mod+4+ich_indx*n_sample/2+is])& 0x3fff;
             hraw[mod][isig]->SetBinContent(ii,Float_t(i_data_lsb));
             if(ii<=50) pds+=Float_t(i_data_lsb);
             if(Float_t(i_data_lsb)<chmin) chmin=Float_t(i_data_lsb);
             if(Float_t(i_data_lsb)>chmax) chmax=Float_t(i_data_lsb);
             ii++;
             Int_t i_data_msb  = (p_se[addr_mod+4+ich_indx*n_sample/2+is]>>16)& 0x3fff;
             hraw[mod][isig]->SetBinContent(ii,Float_t(i_data_msb));
             if(ii<=50) pds+=Float_t(i_data_lsb);
             if(Float_t(i_data_lsb)<chmin) chmin=Float_t(i_data_lsb);
             if(Float_t(i_data_lsb)>chmax) chmax=Float_t(i_data_lsb);
             ii++;
             //if(ich==2)printf("ch %1d is %4d %6d %6d\n",ich,is,i_data_msb,i_data_lsb);
            }
            ich_indx++;

            pds /= 50.;
            //printf("%d %d %f\n",i_nevent,ich,pds);
            for(int ib=1; ib<=hraw[mod][isig]->GetNbinsX(); ib++){
              hraw[mod][isig]->SetBinContent(ib,hraw[mod][isig]->GetBinContent(ib)-pds);
//               hraw[mod][isig]->SetBinContent(ib,hraw[mod][isig]->GetBinContent(ib));
//              hraw[mod][isig]->SetBinContent(ib,-(hraw[mod][isig]->GetBinContent(ib)-pds));
            }
//            if(hraw[16][0]){
//              if(hraw[16][0]->GetMaximum()<50) goto lab;
//            }
//           if(hraw[17][0]){
//             if(hraw[17][0]->GetMaximum()<50) goto lab;
//           }
//           if(hraw[18][0]){
//             if(hraw[18][0]->GetMaximum()<50) goto lab;
//           }
// 	  if(hraw[16][0]&&hraw[17][0]){
// 	    if(hraw[16][0]->GetMaximum()<50 && hraw[17][0]->GetMaximum()<50) goto lab;
// 	  }
            
//             if(ich==4 || ich==6){// phoswich
//               double sum =0.;  
//               //hinteg = (TH1F*)hraw[mod][isig]->Clone();
//               for(int ib=1; ib<=hraw[mod][isig]->GetNbinsX(); ib++){
//                 sum += hraw[mod][isig]->GetBinContent(ib);
//                 hraw[mod][isig]->SetBinContent(ib,sum);
//               }
//             }
          }
          
        }//for(int ich = 0;ich<8;ich++)

        
    addr_mod += i_EVENT_SIZE;
    //printf("addr_mod %d\n",addr_mod);
    }
    while(addr_mod<i_EVENT_SIZE0-1);


    for(int im=0;im<NCOL*NROW;im++){
      for(int is=0;is<3;is++){
        int icol = (im)%8+1;
        int irow = ((im)/8)*3+is+1;
        int ipad = icol+(irow-1)*8;
        cf->cd(ipad);
        if(irow%2) gPad->SetFillColor(kYellow-9);
        else gPad->SetFillColor(kGreen-10);
        if(fired[im][is]) hraw[im][is]->Draw();
        else gPad->Paint();
	
	if(im==12 && is==0 && fired[im][is]){
//// fit tail ////

double sxi=0;
double syi=0;
double sxxi=0;
double sxyi=0;
double si=0;
int n_sample=hraw[im][is]->GetNbinsX();
int ibeg=hraw[im][is]->GetMaximumBin()+150;
if(n_sample>512) ibeg+=150;
if(n_sample-ibeg<10) ibeg=n_sample-100;
//printf("ibeg %d\n",ibeg);
for(int i=ibeg; i<n_sample; i++){
  double xi = hraw[im][is]->GetBinCenter(i+1);
  double yi = hraw[im][is]->GetBinContent(i+1);
  if(yi>0){
    yi=log(yi);
    sxi+=xi;
    syi+=yi;
    sxxi+=xi*xi;
    sxyi+=xi*yi;
    si+=1;
  }
}
double den = si*sxyi-sxi*syi;
double tail = 0.1;
if(den!=0) tail = -(si*sxxi-sxi*sxi)/den;
double btail = (syi+sxi/tail)/si;
printf("mod %d sig %d tail %f btail %f\n",im,is,tail,btail);
//// fit tail ////
	
	}
	
//        fired[im][is]=false;
      }
    }
      cf->Modified();
      cf->Update();
      

 const char *input;   
 Bool_t done = kFALSE;
    do {
       timer->TurnOn();
       timer->Reset();
       // Now let's read the input, we can use here any
       // stdio or iostream reading methods. like std::cin >> myinputl;
       input = Getline("Type <return> to exit: "); 
       timer->TurnOff();
       // Now usefull stuff with the input!
       // ....
	 // here were are always done as soon as we get some input!
	 if (input) done = kTRUE;
    } while (!done);
      

    //if(i_nevent>5) break;
	//r_fadc->Object()->Print("all");
    //if(iauto==1) goto lab;
    ievt=1;
    //gApplication->Run(kTRUE);
    mbs_sevt->Clear();
    
    goto lab;
      i_nevent += 1;

      }
      else{//empty evt
        empty_evt=1;
        printf("Empty Event:    %d\n",empty_evt);
	continue;
      }
    }
  }
    
    evtcount++;
    if (i_nse == 0) continue; // skip empty online dummy evts
  }
  else{
    break;
  }
//    if(dchmax>500){
//     big_count++;
//     big_count8[maxch]++;
//     printf("chmax-chmin %6d %6d %f %d\n",i_nevent,big_count,dchmax,maxch);
//     printf("%3d %3d %3d %3d %3d %3d %3d %3d\n",
//     big_count8[0],
//     big_count8[1],
//     big_count8[2],
//     big_count8[3],
//     big_count8[4],
//     big_count8[5],
//     big_count8[6],
//     big_count8[7]);
//     break;
//   }


  }
  if(empty_evt>0){
    mbs_sevt->Clear();
    goto lab;
  }

    

  a_in->Close();
}

void  INThandler(int sig)
{
     char  c;

     signal(sig, SIG_IGN);
     cout << "You hit Ctrl-C? Select option:" << endl;
     cout << "1) Quit root [q]" << endl;
     cout << "2) Stop Auto viewing [s]" << endl;
     cout << "3) Continue Auto viewing - any other button" << endl;

     c = getchar();
     if (c == 'q' || c == 'Q'){
	  cout << "Bye" << endl;
          exit(0);
     }else{
	if (c == 's' || c == 'S'){
		iauto = 0;
	}	
      	signal(SIGINT, INThandler);
    }
}

