{
TColor *color;
gROOT->SetStyle("Plain");
Int_t colors[]={51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76};
Int_t colory[26];
Float_t r[]={0.0,0.0,0.0,0.0,0.0,0.4,0.6,1.0,1.0,1.0,1.0,1.0,1.0,0.8,0.6,0.4};
Float_t g[]={0.4,0.6,0.8,1.0,1.0,1.0,1.0,1.0,1.0,0.8,0.6,0.4,0.2,0.0,0.0,0.0}; 
Float_t b[]={1.0,1.0,1.0,0.8,0.4,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

for(int i=0;i<16;i++){
  gROOT->GetListOfColors()->Remove(gROOT->GetColor(colors[i]));
  //gROOT->GetListOfColors()->Remove(gROOT->GetColor(colors[i]+100));
  //gROOT->GetListOfColors()->Remove(gROOT->GetColor(colors[i]+150));
  color = new TColor(colors[i],r[i],g[i],b[i]);
}
   
gStyle->SetPalette(16,colors);

gSystem->SetIncludePath(" -I$S394REF/src/TAGbase");
gSystem->AddIncludePath(" -I$S394REF/src/TAGmbs");
gSystem->AddIncludePath(" -I$S394WRK");
gSystem->AddIncludePath(" -I$S394WRK/geo");

 gSystem->Load("$S394REF/lib/libTAGbase.so");
 gSystem->Load("$S394REF/lib/libTAGmbs.so"); 
  gSystem->Load("$S394WRK/mktreeraw_C.so"); 
//    gSystem->Load("/u/lukasik/s394/unpack_fun_C.so"); 


gSystem->Load("$S394WRK/geo/geo_C.so");

gROOT->LoadMacro("ProcEvent.C");

}
