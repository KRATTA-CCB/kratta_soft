//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug 28 19:52:53 2017 by ROOT version 5.34/09
// from TChain TT/TreeKR
//////////////////////////////////////////////////////////

#ifndef myClass_h
#define myClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class myClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           evnb_1;
   Int_t           mod_1;
   Float_t         tls0_1;
   Float_t         tm1_1;
   Float_t         tm2_1;
   Float_t         a0_1;
   Float_t         a1_1;
   Float_t         a2_1;
   Float_t         p04_1;
   Float_t         p14_1;
   Float_t         p24_1;
   Float_t         p10_1;
   Float_t         p12_1;
   Float_t         p13_1;
   Float_t         p20_1;
   Float_t         p22_1;
   Float_t         p23_1;
   Float_t         enCsI1_1;
   Float_t         enCsI2_1;
   Float_t         en_1;
   Int_t           evnb_2;
   Int_t           mod_2;
   Float_t         tls0_2;
   Float_t         tm1_2;
   Float_t         tm2_2;
   Float_t         a0_2;
   Float_t         a1_2;
   Float_t         a2_2;
   Float_t         p04_2;
   Float_t         p14_2;
   Float_t         p24_2;
   Float_t         p10_2;
   Float_t         p12_2;
   Float_t         p13_2;
   Float_t         p20_2;
   Float_t         p22_2;
   Float_t         p23_2;
   Float_t         enCsI1_2;
   Float_t         enCsI2_2;
   Float_t         en_2;

   // List of branches
   TBranch        *b_evnb_1;   //!
   TBranch        *b_mod_1;   //!
   TBranch        *b_tls0_1;   //!
   TBranch        *b_tm1_1;   //!
   TBranch        *b_tm2_1;   //!
   TBranch        *b_a0_1;   //!
   TBranch        *b_a1_1;   //!
   TBranch        *b_a2_1;   //!
   TBranch        *b_p04_1;   //!
   TBranch        *b_p14_1;   //!
   TBranch        *b_p24_1;   //!
   TBranch        *b_p10_1;   //!
   TBranch        *b_p12_1;   //!
   TBranch        *b_p13_1;   //!
   TBranch        *b_p20_1;   //!
   TBranch        *b_p22_1;   //!
   TBranch        *b_p23_1;   //!
   TBranch        *b_enCsI1_1;   //!
   TBranch        *b_enCsI2_1;   //!
   TBranch        *b_en_1;   //!
   TBranch        *b_evnb_2;   //!
   TBranch        *b_mod_2;   //!
   TBranch        *b_tls0_2;   //!
   TBranch        *b_tm1_2;   //!
   TBranch        *b_tm2_2;   //!
   TBranch        *b_a0_2;   //!
   TBranch        *b_a1_2;   //!
   TBranch        *b_a2_2;   //!
   TBranch        *b_p04_2;   //!
   TBranch        *b_p14_2;   //!
   TBranch        *b_p24_2;   //!
   TBranch        *b_p10_2;   //!
   TBranch        *b_p12_2;   //!
   TBranch        *b_p13_2;   //!
   TBranch        *b_p20_2;   //!
   TBranch        *b_p22_2;   //!
   TBranch        *b_p23_2;   //!
   TBranch        *b_enCsI1_2;   //!
   TBranch        *b_enCsI2_2;   //!
   TBranch        *b_en_2;   //!

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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/ciepal/Main/KRATTA/spall-2017-06/myRoot_C230MeV/KRAnal.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/home/ciepal/Main/KRATTA/spall-2017-06/myRoot_C230MeV/KRAnal.root");
      }
      f->GetObject("TT",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("TT","TreeKR");
      chain->Add("/home/ciepal/Main/KRATTA/spall-2017-06/myRoot_C230MeV/KRAnal.root/TT");
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

   fChain->SetBranchAddress("evnb_1", &evnb_1, &b_evnb_1);
   fChain->SetBranchAddress("mod_1", &mod_1, &b_mod_1);
   fChain->SetBranchAddress("tls0_1", &tls0_1, &b_tls0_1);
   fChain->SetBranchAddress("tm1_1", &tm1_1, &b_tm1_1);
   fChain->SetBranchAddress("tm2_1", &tm2_1, &b_tm2_1);
   fChain->SetBranchAddress("a0_1", &a0_1, &b_a0_1);
   fChain->SetBranchAddress("a1_1", &a1_1, &b_a1_1);
   fChain->SetBranchAddress("a2_1", &a2_1, &b_a2_1);
   fChain->SetBranchAddress("p04_1", &p04_1, &b_p04_1);
   fChain->SetBranchAddress("p14_1", &p14_1, &b_p14_1);
   fChain->SetBranchAddress("p24_1", &p24_1, &b_p24_1);
   fChain->SetBranchAddress("p10_1", &p10_1, &b_p10_1);
   fChain->SetBranchAddress("p12_1", &p12_1, &b_p12_1);
   fChain->SetBranchAddress("p13_1", &p13_1, &b_p13_1);
   fChain->SetBranchAddress("p20_1", &p20_1, &b_p20_1);
   fChain->SetBranchAddress("p22_1", &p22_1, &b_p22_1);
   fChain->SetBranchAddress("p23_1", &p23_1, &b_p23_1);
   fChain->SetBranchAddress("enCsI1_1", &enCsI1_1, &b_enCsI1_1);
   fChain->SetBranchAddress("enCsI2_1", &enCsI2_1, &b_enCsI2_1);
   fChain->SetBranchAddress("en_1", &en_1, &b_en_1);
   fChain->SetBranchAddress("evnb_2", &evnb_2, &b_evnb_2);
   fChain->SetBranchAddress("mod_2", &mod_2, &b_mod_2);
   fChain->SetBranchAddress("tls0_2", &tls0_2, &b_tls0_2);
   fChain->SetBranchAddress("tm1_2", &tm1_2, &b_tm1_2);
   fChain->SetBranchAddress("tm2_2", &tm2_2, &b_tm2_2);
   fChain->SetBranchAddress("a0_2", &a0_2, &b_a0_2);
   fChain->SetBranchAddress("a1_2", &a1_2, &b_a1_2);
   fChain->SetBranchAddress("a2_2", &a2_2, &b_a2_2);
   fChain->SetBranchAddress("p04_2", &p04_2, &b_p04_2);
   fChain->SetBranchAddress("p14_2", &p14_2, &b_p14_2);
   fChain->SetBranchAddress("p24_2", &p24_2, &b_p24_2);
   fChain->SetBranchAddress("p10_2", &p10_2, &b_p10_2);
   fChain->SetBranchAddress("p12_2", &p12_2, &b_p12_2);
   fChain->SetBranchAddress("p13_2", &p13_2, &b_p13_2);
   fChain->SetBranchAddress("p20_2", &p20_2, &b_p20_2);
   fChain->SetBranchAddress("p22_2", &p22_2, &b_p22_2);
   fChain->SetBranchAddress("p23_2", &p23_2, &b_p23_2);
   fChain->SetBranchAddress("enCsI1_2", &enCsI1_2, &b_enCsI1_2);
   fChain->SetBranchAddress("enCsI2_2", &enCsI2_2, &b_enCsI2_2);
   fChain->SetBranchAddress("en_2", &en_2, &b_en_2);
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
