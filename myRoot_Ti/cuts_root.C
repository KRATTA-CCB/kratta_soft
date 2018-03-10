#include "TCutG.h"

void cuts_root(void){
  TCutG *cutg[16];


  cutg[0] = new TCutG("cut_m0",6);
  cutg[0]->SetPoint(0,72.5395,537.2707);
  cutg[0]->SetPoint(1,937.4025,368.8681);
  cutg[0]->SetPoint(2,2936.512,773.0343);
  cutg[0]->SetPoint(3,44.18333,1130.048);
  cutg[0]->SetPoint(4,58.36141,530.5346);
  cutg[0]->SetPoint(5,72.5395,537.2707);
   

   cutg[1] = new TCutG("cut_m1",7);
   cutg[1]->SetPoint(0,36.22922,477.2171);
   cutg[1]->SetPoint(1,961.9142,342.5752);
   cutg[1]->SetPoint(2,2708.49,693.8149);
   cutg[1]->SetPoint(3,403.01,1027.493);
   cutg[1]->SetPoint(4,88.62648,834.3107);
   cutg[1]->SetPoint(5,88.62648,477.2171);
   cutg[1]->SetPoint(6,36.22922,477.2171);

   cutg[2] = new TCutG("cut_m2",6);
   cutg[2]->SetPoint(0,117.6368,418.8356);
   cutg[2]->SetPoint(1,2414.383,292.5336);
   cutg[2]->SetPoint(2,5602.808,570.3979);
   cutg[2]->SetPoint(3,333.8012,868.4705);
   cutg[2]->SetPoint(4,144.6573,423.8877);
   cutg[2]->SetPoint(5,117.6368,418.8356);

   cutg[3] = new TCutG("cut_m3",6);
   cutg[3]->SetPoint(0,61.90593,588.3211);
   cutg[3]->SetPoint(1,1139.44,402.0357);
   cutg[3]->SetPoint(2,2968.413,758.4077);
   cutg[3]->SetPoint(3,90.2621,1398.257);
   cutg[3]->SetPoint(4,47.72785,588.3211);
   cutg[3]->SetPoint(5,61.90593,588.3211);

   cutg[4] = new TCutG("cut_m4",6);
   cutg[4]->SetPoint(0,143.4608,550.7429);
   cutg[4]->SetPoint(1,939.0773,389.0764);
   cutg[4]->SetPoint(2,2542.742,678.7289);
   cutg[4]->SetPoint(3,255.3444,1183.937);
   cutg[4]->SetPoint(4,155.8923,550.7429);
   cutg[4]->SetPoint(5,143.4608,550.7429);

   cutg[5] = new TCutG("cut_m5",6);
   cutg[5]->SetPoint(0,0,0);

   cutg[6] = new TCutG("cut_m6",7);
   cutg[6]->SetPoint(0,56.65019,570.481);
   cutg[6]->SetPoint(1,1018.294,386.3608);
   cutg[6]->SetPoint(2,2488.5,767.7526);
   cutg[6]->SetPoint(3,537.4721,1155.72);
   cutg[6]->SetPoint(4,93.63649,1129.417);
   cutg[6]->SetPoint(5,84.38992,570.481);
   cutg[6]->SetPoint(6,56.65019,570.481);


   cutg[7] = new TCutG("cut_m7",6);
   cutg[7]->SetPoint(0,264.7072,526.135);
   cutg[7]->SetPoint(1,953.0633,397.8282);
   cutg[7]->SetPoint(2,2646.42,673.6877);
   cutg[7]->SetPoint(3,319.7757,1116.346);
   cutg[7]->SetPoint(4,264.7072,519.7196);
   cutg[7]->SetPoint(5,264.7072,526.135);

   cutg[8] = new TCutG("cut_m8",6);
   cutg[8]->SetPoint(0,0,0);


   cutg[9] = new TCutG("cut_m9",6);
   cutg[9]->SetPoint(0,94.38042,1670.07);
   cutg[9]->SetPoint(1,1268.079,1114.261);
   cutg[9]->SetPoint(2,3150.887,2225.879);
   cutg[9]->SetPoint(3,131.0585,3299.165);
   cutg[9]->SetPoint(4,106.6065,1650.904);
   cutg[9]->SetPoint(5,94.38042,1670.07);
   
   cutg[10] = new TCutG("cut_m10",6);
   cutg[10]->SetPoint(0,0,0);


   cutg[11] = new TCutG("cut_m11",6);
   cutg[11]->SetPoint(0,267.4416,1374.113);
   cutg[11]->SetPoint(1,1084.633,1022.874);
   cutg[11]->SetPoint(2,2549.599,2076.593);
   cutg[11]->SetPoint(3,297.3389,3060.064);
   cutg[11]->SetPoint(4,307.3046,1338.989);
   cutg[11]->SetPoint(5,267.4416,1374.113);

   cutg[12] = new TCutG("cut_m12",7);
   cutg[12]->SetPoint(0,101.0121,1056.221);
   cutg[12]->SetPoint(1,2443.478,691.3485);
   cutg[12]->SetPoint(2,5605.807,1223.02);
   cutg[12]->SetPoint(3,1178.546,1848.515);
   cutg[12]->SetPoint(4,194.7108,1712.991);
   cutg[12]->SetPoint(5,147.8615,1035.371);
   cutg[12]->SetPoint(6,101.0121,1056.221);

   cutg[13] = new TCutG("cut_m13",6);
   cutg[13]->SetPoint(0,107.9747,581.5721);
   cutg[13]->SetPoint(1,1429.413,391.1168);
   cutg[13]->SetPoint(2,2997.221,756.791);
   cutg[13]->SetPoint(3,107.9747,1290.066);
   cutg[13]->SetPoint(4,107.9747,581.5721);
   cutg[13]->SetPoint(5,107.9747,581.5721);
   
   cutg[14] = new TCutG("cut_m14",7);
   cutg[14]->SetPoint(0,143.6432,1150.919);
   cutg[14]->SetPoint(1,2254.945,785.8063);
   cutg[14]->SetPoint(2,4304.602,1302);
   cutg[14]->SetPoint(3,2254.945,2032.226);
   cutg[14]->SetPoint(4,143.6432,2195.897);
   cutg[14]->SetPoint(5,112.8213,1163.509);
   cutg[14]->SetPoint(6,143.6432,1150.919);

   cutg[15] = new TCutG("cut_m15",6);
   cutg[15]->SetPoint(0,75.84074,490.118);
   cutg[15]->SetPoint(1,1233.717,335.1876);
   cutg[15]->SetPoint(2,2532.553,685.465);
   cutg[15]->SetPoint(3,75.84074,1049.215);
   cutg[15]->SetPoint(4,65.77224,503.5902);
   cutg[15]->SetPoint(5,75.84074,490.118);


  TFile* file = new TFile("myCuts.root","RECREATE");
  char n[100];  

  for (int i=0;i<16;i++){
    
    //if(!cutg[i])continue;
    cutg[i]->Write();
  }

  file->Write();
  file->Close();
  
  delete file;

}
