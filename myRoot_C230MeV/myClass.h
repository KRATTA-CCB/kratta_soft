//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 29 16:26:23 2017 by ROOT version 5.34/09
// from TChain ntuple/KRAnal
//////////////////////////////////////////////////////////

#ifndef myClass_h
#define myClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "./mktreedstchain_sct_fitABC.hxx"
#include <TObject.h>
#include "./mktreedstchain_sct_fitABC.hxx"

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxpeak = 1;

class myClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
 //ASYEvent        *eventdst;
   UInt_t          fUniqueID;
   UInt_t          fBits;
   Int_t           run;
   Int_t           evt;
   Int_t           npeak;
   Int_t           HADC[32];
   Int_t           HTDC[32];
   Int_t           PADC[32];
   Int_t           PTDC[32];
   Int_t           peak_;
   UInt_t          peak_fUniqueID[kMaxpeak];   //[peak_]
   UInt_t          peak_fBits[kMaxpeak];   //[peak_]
   Int_t           peak_mod[kMaxpeak];   //[peak_]
   Float_t         peak_pds0[kMaxpeak];   //[peak_]
   Float_t         peak_pdr0[kMaxpeak];   //[peak_]
   Float_t         peak_tls0[kMaxpeak];   //[peak_]
   Float_t         peak_tlo0[kMaxpeak];   //[peak_]
   Float_t         peak_tm0[kMaxpeak];   //[peak_]
   Float_t         peak_am0[kMaxpeak];   //[peak_]
   Float_t         peak_at0[kMaxpeak];   //[peak_]
   Float_t         peak_pds1[kMaxpeak];   //[peak_]
   Float_t         peak_pdr1[kMaxpeak];   //[peak_]
   Float_t         peak_tls1[kMaxpeak];   //[peak_]
   Float_t         peak_tlo1[kMaxpeak];   //[peak_]
   Float_t         peak_tm1[kMaxpeak];   //[peak_]
   Float_t         peak_am1[kMaxpeak];   //[peak_]
   Float_t         peak_at1[kMaxpeak];   //[peak_]
   Float_t         peak_pds2[kMaxpeak];   //[peak_]
   Float_t         peak_pdr2[kMaxpeak];   //[peak_]
   Float_t         peak_tls2[kMaxpeak];   //[peak_]
   Float_t         peak_tlo2[kMaxpeak];   //[peak_]
   Float_t         peak_tm2[kMaxpeak];   //[peak_]
   Float_t         peak_am2[kMaxpeak];   //[peak_]
   Float_t         peak_at2[kMaxpeak];   //[peak_]
   Float_t         peak_sam0[kMaxpeak];   //[peak_]
   Float_t         peak_sat0[kMaxpeak];   //[peak_]
   Float_t         peak_sam1[kMaxpeak];   //[peak_]
   Float_t         peak_sat1[kMaxpeak];   //[peak_]
   Float_t         peak_sam2[kMaxpeak];   //[peak_]
   Float_t         peak_sat2[kMaxpeak];   //[peak_]
   Float_t         peak_p00[kMaxpeak];   //[peak_]
   Float_t         peak_p04[kMaxpeak];   //[peak_]
   Float_t         peak_p05[kMaxpeak];   //[peak_]
   Float_t         peak_p06[kMaxpeak];   //[peak_]
   Float_t         peak_p09[kMaxpeak];   //[peak_]
   Float_t         peak_rc0[kMaxpeak];   //[peak_]
   Float_t         peak_p10[kMaxpeak];   //[peak_]
   Float_t         peak_p12[kMaxpeak];   //[peak_]
   Float_t         peak_p13[kMaxpeak];   //[peak_]
   Float_t         peak_p14[kMaxpeak];   //[peak_]
   Float_t         peak_p15[kMaxpeak];   //[peak_]
   Float_t         peak_p16[kMaxpeak];   //[peak_]
   Float_t         peak_p17[kMaxpeak];   //[peak_]
   Float_t         peak_p18[kMaxpeak];   //[peak_]
   Float_t         peak_p19[kMaxpeak];   //[peak_]
   Float_t         peak_p110[kMaxpeak];   //[peak_]
   Float_t         peak_rc1[kMaxpeak];   //[peak_]
   Float_t         peak_p20[kMaxpeak];   //[peak_]
   Float_t         peak_p22[kMaxpeak];   //[peak_]
   Float_t         peak_p23[kMaxpeak];   //[peak_]
   Float_t         peak_p24[kMaxpeak];   //[peak_]
   Float_t         peak_p25[kMaxpeak];   //[peak_]
   Float_t         peak_p26[kMaxpeak];   //[peak_]
   Float_t         peak_p27[kMaxpeak];   //[peak_]
   Float_t         peak_p28[kMaxpeak];   //[peak_]
   Float_t         peak_p29[kMaxpeak];   //[peak_]
   Float_t         peak_p210[kMaxpeak];   //[peak_]
   Float_t         peak_rc2[kMaxpeak];   //[peak_]
   Float_t         peak_chi20[kMaxpeak];   //[peak_]
   Float_t         peak_chi21[kMaxpeak];   //[peak_]
   Float_t         peak_chi22[kMaxpeak];   //[peak_]

   // List of branches
   TBranch        *b_eventdst_fUniqueID;   //!
   TBranch        *b_eventdst_fBits;   //!
   TBranch        *b_eventdst_run;   //!
   TBranch        *b_eventdst_evt;   //!
   TBranch        *b_eventdst_npeak;   //!
   TBranch        *b_eventdst_HADC;   //!
   TBranch        *b_eventdst_HTDC;   //!
   TBranch        *b_eventdst_PADC;   //!
   TBranch        *b_eventdst_PTDC;   //!
   TBranch        *b_eventdst_peak_;   //!
   TBranch        *b_peak_fUniqueID;   //!
   TBranch        *b_peak_fBits;   //!
   TBranch        *b_peak_mod;   //!
   TBranch        *b_peak_pds0;   //!
   TBranch        *b_peak_pdr0;   //!
   TBranch        *b_peak_tls0;   //!
   TBranch        *b_peak_tlo0;   //!
   TBranch        *b_peak_tm0;   //!
   TBranch        *b_peak_am0;   //!
   TBranch        *b_peak_at0;   //!
   TBranch        *b_peak_pds1;   //!
   TBranch        *b_peak_pdr1;   //!
   TBranch        *b_peak_tls1;   //!
   TBranch        *b_peak_tlo1;   //!
   TBranch        *b_peak_tm1;   //!
   TBranch        *b_peak_am1;   //!
   TBranch        *b_peak_at1;   //!
   TBranch        *b_peak_pds2;   //!
   TBranch        *b_peak_pdr2;   //!
   TBranch        *b_peak_tls2;   //!
   TBranch        *b_peak_tlo2;   //!
   TBranch        *b_peak_tm2;   //!
   TBranch        *b_peak_am2;   //!
   TBranch        *b_peak_at2;   //!
   TBranch        *b_peak_sam0;   //!
   TBranch        *b_peak_sat0;   //!
   TBranch        *b_peak_sam1;   //!
   TBranch        *b_peak_sat1;   //!
   TBranch        *b_peak_sam2;   //!
   TBranch        *b_peak_sat2;   //!
   TBranch        *b_peak_p00;   //!
   TBranch        *b_peak_p04;   //!
   TBranch        *b_peak_p05;   //!
   TBranch        *b_peak_p06;   //!
   TBranch        *b_peak_p09;   //!
   TBranch        *b_peak_rc0;   //!
   TBranch        *b_peak_p10;   //!
   TBranch        *b_peak_p12;   //!
   TBranch        *b_peak_p13;   //!
   TBranch        *b_peak_p14;   //!
   TBranch        *b_peak_p15;   //!
   TBranch        *b_peak_p16;   //!
   TBranch        *b_peak_p17;   //!
   TBranch        *b_peak_p18;   //!
   TBranch        *b_peak_p19;   //!
   TBranch        *b_peak_p110;   //!
   TBranch        *b_peak_rc1;   //!
   TBranch        *b_peak_p20;   //!
   TBranch        *b_peak_p22;   //!
   TBranch        *b_peak_p23;   //!
   TBranch        *b_peak_p24;   //!
   TBranch        *b_peak_p25;   //!
   TBranch        *b_peak_p26;   //!
   TBranch        *b_peak_p27;   //!
   TBranch        *b_peak_p28;   //!
   TBranch        *b_peak_p29;   //!
   TBranch        *b_peak_p210;   //!
   TBranch        *b_peak_rc2;   //!
   TBranch        *b_peak_chi20;   //!
   TBranch        *b_peak_chi21;   //!
   TBranch        *b_peak_chi22;   //!

   myClass(TTree *tree=0);
   virtual ~myClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef myClass_cxx
myClass::myClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/mnt/disk3/spall_2017_06/root/dst3_m04_7167-7167.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/mnt/disk3/spall_2017_06/root/dst3_m04_7167-7167.root");
      }
      f->GetObject("ntuple",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("ntuple","KRAnal");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7062-7062.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7063-7063.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7064-7064.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7065-7065.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7066-7066.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7067-7067.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7068-7068.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7069-7069.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7070-7070.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7071-7071.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7073-7073.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7074-7074.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7075-7075.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7076-7076.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7077-7077.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7078-7078.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7079-7079.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7080-7080.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7081-7081.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7082-7082.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7083-7083.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7084-7084.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7085-7085.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7086-7086.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7087-7087.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7088-7088.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7089-7089.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7090-7090.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7091-7091.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7092-7092.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7093-7093.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7094-7094.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7095-7095.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7096-7096.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7097-7097.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7098-7098.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7099-7099.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7100-7100.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7101-7101.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7102-7102.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7103-7103.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7104-7104.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7105-7105.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7106-7106.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7107-7107.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7108-7108.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7109-7109.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7110-7110.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7111-7111.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7112-7112.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7113-7113.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7114-7114.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7115-7115.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7116-7116.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7117-7117.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7118-7118.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7119-7119.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7120-7120.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7121-7121.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7122-7122.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7123-7123.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7124-7124.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7125-7125.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7126-7126.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7127-7127.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7128-7128.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7129-7129.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7130-7130.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7131-7131.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7132-7132.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7133-7133.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7134-7134.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7135-7135.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7136-7136.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7137-7137.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7138-7138.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7139-7139.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7140-7140.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7141-7141.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7142-7142.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7143-7143.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7144-7144.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7145-7145.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7146-7146.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7147-7147.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7148-7148.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7149-7149.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7150-7150.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7151-7151.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7152-7152.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7153-7153.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7154-7154.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7155-7155.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7156-7156.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7157-7157.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7158-7158.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7159-7159.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7160-7160.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7161-7161.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7162-7162.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7163-7163.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7164-7164.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7165-7165.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7166-7166.root/ntuple");
      chain->Add("/mnt/disk3/spall_2017_06/root/dst3_m04_7167-7167.root/ntuple");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

myClass::~myClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t myClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void myClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("fUniqueID", &fUniqueID, &b_eventdst_fUniqueID);
   fChain->SetBranchAddress("fBits", &fBits, &b_eventdst_fBits);
   fChain->SetBranchAddress("run", &run, &b_eventdst_run);
   fChain->SetBranchAddress("evt", &evt, &b_eventdst_evt);
   fChain->SetBranchAddress("npeak", &npeak, &b_eventdst_npeak);
   fChain->SetBranchAddress("HADC[32]", HADC, &b_eventdst_HADC);
   fChain->SetBranchAddress("HTDC[32]", HTDC, &b_eventdst_HTDC);
   fChain->SetBranchAddress("PADC[32]", PADC, &b_eventdst_PADC);
   fChain->SetBranchAddress("PTDC[32]", PTDC, &b_eventdst_PTDC);
   fChain->SetBranchAddress("peak", &peak_, &b_eventdst_peak_);
   fChain->SetBranchAddress("peak.fUniqueID", peak_fUniqueID, &b_peak_fUniqueID);
   fChain->SetBranchAddress("peak.fBits", peak_fBits, &b_peak_fBits);
   fChain->SetBranchAddress("peak.mod", peak_mod, &b_peak_mod);
   fChain->SetBranchAddress("peak.pds0", peak_pds0, &b_peak_pds0);
   fChain->SetBranchAddress("peak.pdr0", peak_pdr0, &b_peak_pdr0);
   fChain->SetBranchAddress("peak.tls0", peak_tls0, &b_peak_tls0);
   fChain->SetBranchAddress("peak.tlo0", peak_tlo0, &b_peak_tlo0);
   fChain->SetBranchAddress("peak.tm0", peak_tm0, &b_peak_tm0);
   fChain->SetBranchAddress("peak.am0", peak_am0, &b_peak_am0);
   fChain->SetBranchAddress("peak.at0", peak_at0, &b_peak_at0);
   fChain->SetBranchAddress("peak.pds1", peak_pds1, &b_peak_pds1);
   fChain->SetBranchAddress("peak.pdr1", peak_pdr1, &b_peak_pdr1);
   fChain->SetBranchAddress("peak.tls1", peak_tls1, &b_peak_tls1);
   fChain->SetBranchAddress("peak.tlo1", peak_tlo1, &b_peak_tlo1);
   fChain->SetBranchAddress("peak.tm1", peak_tm1, &b_peak_tm1);
   fChain->SetBranchAddress("peak.am1", peak_am1, &b_peak_am1);
   fChain->SetBranchAddress("peak.at1", peak_at1, &b_peak_at1);
   fChain->SetBranchAddress("peak.pds2", peak_pds2, &b_peak_pds2);
   fChain->SetBranchAddress("peak.pdr2", peak_pdr2, &b_peak_pdr2);
   fChain->SetBranchAddress("peak.tls2", peak_tls2, &b_peak_tls2);
   fChain->SetBranchAddress("peak.tlo2", peak_tlo2, &b_peak_tlo2);
   fChain->SetBranchAddress("peak.tm2", peak_tm2, &b_peak_tm2);
   fChain->SetBranchAddress("peak.am2", peak_am2, &b_peak_am2);
   fChain->SetBranchAddress("peak.at2", peak_at2, &b_peak_at2);
   fChain->SetBranchAddress("peak.sam0", peak_sam0, &b_peak_sam0);
   fChain->SetBranchAddress("peak.sat0", peak_sat0, &b_peak_sat0);
   fChain->SetBranchAddress("peak.sam1", peak_sam1, &b_peak_sam1);
   fChain->SetBranchAddress("peak.sat1", peak_sat1, &b_peak_sat1);
   fChain->SetBranchAddress("peak.sam2", peak_sam2, &b_peak_sam2);
   fChain->SetBranchAddress("peak.sat2", peak_sat2, &b_peak_sat2);
   fChain->SetBranchAddress("peak.p00", peak_p00, &b_peak_p00);
   fChain->SetBranchAddress("peak.p04", peak_p04, &b_peak_p04);
   fChain->SetBranchAddress("peak.p05", peak_p05, &b_peak_p05);
   fChain->SetBranchAddress("peak.p06", peak_p06, &b_peak_p06);
   fChain->SetBranchAddress("peak.p09", peak_p09, &b_peak_p09);
   fChain->SetBranchAddress("peak.rc0", peak_rc0, &b_peak_rc0);
   fChain->SetBranchAddress("peak.p10", peak_p10, &b_peak_p10);
   fChain->SetBranchAddress("peak.p12", peak_p12, &b_peak_p12);
   fChain->SetBranchAddress("peak.p13", peak_p13, &b_peak_p13);
   fChain->SetBranchAddress("peak.p14", peak_p14, &b_peak_p14);
   fChain->SetBranchAddress("peak.p15", peak_p15, &b_peak_p15);
   fChain->SetBranchAddress("peak.p16", peak_p16, &b_peak_p16);
   fChain->SetBranchAddress("peak.p17", peak_p17, &b_peak_p17);
   fChain->SetBranchAddress("peak.p18", peak_p18, &b_peak_p18);
   fChain->SetBranchAddress("peak.p19", peak_p19, &b_peak_p19);
   fChain->SetBranchAddress("peak.p110", peak_p110, &b_peak_p110);
   fChain->SetBranchAddress("peak.rc1", peak_rc1, &b_peak_rc1);
   fChain->SetBranchAddress("peak.p20", peak_p20, &b_peak_p20);
   fChain->SetBranchAddress("peak.p22", peak_p22, &b_peak_p22);
   fChain->SetBranchAddress("peak.p23", peak_p23, &b_peak_p23);
   fChain->SetBranchAddress("peak.p24", peak_p24, &b_peak_p24);
   fChain->SetBranchAddress("peak.p25", peak_p25, &b_peak_p25);
   fChain->SetBranchAddress("peak.p26", peak_p26, &b_peak_p26);
   fChain->SetBranchAddress("peak.p27", peak_p27, &b_peak_p27);
   fChain->SetBranchAddress("peak.p28", peak_p28, &b_peak_p28);
   fChain->SetBranchAddress("peak.p29", peak_p29, &b_peak_p29);
   fChain->SetBranchAddress("peak.p210", peak_p210, &b_peak_p210);
   fChain->SetBranchAddress("peak.rc2", peak_rc2, &b_peak_rc2);
   fChain->SetBranchAddress("peak.chi20", peak_chi20, &b_peak_chi20);
   fChain->SetBranchAddress("peak.chi21", peak_chi21, &b_peak_chi21);
   fChain->SetBranchAddress("peak.chi22", peak_chi22, &b_peak_chi22);
   Notify();
}

Bool_t myClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myClass_cxx
