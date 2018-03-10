#include "TCutG.h"

void mod5_cuts(void){

   TFile* file = new TFile("cuts_mod5.root","RECREATE");

  TCutG *cutg_mod5_70 = new TCutG("cutg_mod5_70",6);
  //cutg->SetVarX("p12_vs_p13_mod5");
  //cutg->SetVarY("");
  //cutg->SetTitle("Graph");
  //cutg_mod5_70->SetFillColor(1);
   cutg_mod5_70->SetPoint(0,1136.093,1301.364);
   cutg_mod5_70->SetPoint(1,1068.207,1207.605);
   cutg_mod5_70->SetPoint(2,1318.027,1100.977);
   cutg_mod5_70->SetPoint(3,1429.359,1200.251);
   cutg_mod5_70->SetPoint(4,1127.946,1299.525);
   cutg_mod5_70->SetPoint(5,1136.093,1301.364);
   cutg_mod5_70->Write();
 


   TCutG *cutg_mod5_80 = new TCutG("cutg_mod5_80",6);
   cutg_mod5_80->SetPoint(0,1384.429,1434.095);
   cutg_mod5_80->SetPoint(1,1296.003,1344.043);
   cutg_mod5_80->SetPoint(2,1530.072,1243.185);
   cutg_mod5_80->SetPoint(3,1621.099,1349.446);
   cutg_mod5_80->SetPoint(4,1376.627,1432.294);
   cutg_mod5_80->SetPoint(5,1384.429,1434.095);
   cutg_mod5_80->Write();

   TCutG *cutg_mod5_90 = new TCutG("cutg_mod5_90",6);
   cutg_mod5_90->SetPoint(0,1591.59,1580.962);
   cutg_mod5_90->SetPoint(1,1469.497,1513.054);
   cutg_mod5_90->SetPoint(2,1750.311,1406.476);
   cutg_mod5_90->SetPoint(3,1874.439,1507.395);
   cutg_mod5_90->SetPoint(4,1585.486,1580.962);
   cutg_mod5_90->SetPoint(5,1591.59,1580.962);
   cutg_mod5_90->Write();


   TCutG *cutg_mod5_100 = new TCutG("cutg_mod5_100",6);
   cutg_mod5_100->SetPoint(0,1119.668,981.735);
   cutg_mod5_100->SetPoint(1,1340.225,847.609);
   cutg_mod5_100->SetPoint(2,1617.963,1145.667);
   cutg_mod5_100->SetPoint(3,1381.069,1186.65);
   cutg_mod5_100->SetPoint(4,1136.006,974.2835);
   cutg_mod5_100->SetPoint(5,1119.668,981.735);
   cutg_mod5_100->Write();

   TCutG *cutg_mod5_110 = new TCutG("cutg_mod5_110",6);
   cutg_mod5_110->SetPoint(0,929.6312,802.0456);
   cutg_mod5_110->SetPoint(1,1150.358,748.4421);
   cutg_mod5_110->SetPoint(2,1355.595,939.8832);
   cutg_mod5_110->SetPoint(3,1069.038,978.1715);
   cutg_mod5_110->SetPoint(4,937.376,802.0456);
   cutg_mod5_110->SetPoint(5,929.6312,802.0456);
   cutg_mod5_110->Write();

   TCutG *cutg_mod5_120 = new TCutG("cutg_mod5_120",6);
   cutg_mod5_120->SetPoint(0,936.7261,844.8539);
   cutg_mod5_120->SetPoint(1,1252.179,802.1406);
   cutg_mod5_120->SetPoint(2,1036.343,651.1185);
   cutg_mod5_120->SetPoint(3,774.8487,731.9687);
   cutg_mod5_120->SetPoint(4,961.6303,841.803);
   cutg_mod5_120->SetPoint(5,936.7261,844.8539);
   cutg_mod5_120->Write();


   TCutG *cutg_mod5_130 = new TCutG("cutg_mod5_130",6);
   cutg_mod5_130->SetPoint(0,904.4142,804.8678);
   cutg_mod5_130->SetPoint(1,1105.699,700.9095);
   cutg_mod5_130->SetPoint(2,912.0579,575.8346);
   cutg_mod5_130->SetPoint(3,743.8959,670.0468);
   cutg_mod5_130->SetPoint(4,914.6058,806.4922);
   cutg_mod5_130->SetPoint(5,904.4142,804.8678);
   cutg_mod5_130->Write();
 

   TCutG *cutg_mod5_140 = new TCutG("cutg_mod5_140",6);
   cutg_mod5_140->SetPoint(0,761.4925,716.2758);
   cutg_mod5_140->SetPoint(1,1012.483,669.5103);
   cutg_mod5_140->SetPoint(2,851.4306,545.7192);
   cutg_mod5_140->SetPoint(3,659.0049,597.0696);
   cutg_mod5_140->SetPoint(4,765.6757,719.0267);
   cutg_mod5_140->SetPoint(5,761.4925,716.2758);
   cutg_mod5_140->Write();
   
   TCutG *cutg_mod5_150 = new TCutG("cutg_mod5_150",6);
   cutg_mod5_150->SetPoint(0,723.9857,673.0214);
   cutg_mod5_150->SetPoint(1,964.1664,619.9212);
   cutg_mod5_150->SetPoint(2,820.9007,502.1052);
   cutg_mod5_150->SetPoint(3,559.6515,548.5678);
   cutg_mod5_150->SetPoint(4,736.6268,671.362);
   cutg_mod5_150->SetPoint(5,723.9857,673.0214);
   cutg_mod5_150->Write();

   //###############################


   TCutG *cutg2_mod5_100 = new TCutG("cutg2_mod5_100",6);
   cutg2_mod5_100->SetPoint(0,206.4813,384.8706);
   cutg2_mod5_100->SetPoint(1,355.2543,520.2094);
   cutg2_mod5_100->SetPoint(2,414.0288,378.8555);
   cutg2_mod5_100->SetPoint(3,261.5824,252.5393);
   cutg2_mod5_100->SetPoint(4,204.6445,390.8856);
   cutg2_mod5_100->SetPoint(5,206.4813,384.8706);
   cutg2_mod5_100->Write();


   TCutG *cutg2_mod5_110 = new TCutG("cutg2_mod5_110",6);
   cutg2_mod5_110->SetPoint(0,552.1361,698.0256);
   cutg2_mod5_110->SetPoint(1,679.1453,581.6992);
   cutg2_mod5_110->SetPoint(2,536.26,475.401);
   cutg2_mod5_110->SetPoint(3,409.2508,601.7555);
   cutg2_mod5_110->SetPoint(4,556.6722,692.0087);
   cutg2_mod5_110->SetPoint(5,552.1361,698.0256);
   cutg2_mod5_110->Write();

   TCutG *cutg2_mod5_120 = new TCutG("cutg2_mod5_120",6);
   cutg2_mod5_120->SetPoint(0,782.125,876.273);
   cutg2_mod5_120->SetPoint(1,861.2917,723.889);
   cutg2_mod5_120->SetPoint(2,709.2083,599.7243);
   cutg2_mod5_120->SetPoint(3,636.2917,780.3275);
   cutg2_mod5_120->SetPoint(4,784.2083,873.451);
   cutg2_mod5_120->SetPoint(5,782.125,876.273);
   cutg2_mod5_120->Write();

   TCutG *cutg2_mod5_130 = new TCutG("cutg2_mod5_130",6);
   cutg2_mod5_130->SetPoint(0,808.3718,878.7048);
   cutg2_mod5_130->SetPoint(1,942.3573,986.4662);
   cutg2_mod5_130->SetPoint(2,1024.914,850.9481);
   cutg2_mod5_130->SetPoint(3,869.2743,756.2487);
   cutg2_mod5_130->SetPoint(4,809.7252,883.6031);
   cutg2_mod5_130->SetPoint(5,808.3718,878.7048);
   cutg2_mod5_130->Write();

   TCutG *cutg2_mod5_140 = new TCutG("cutg2_mod5_140",6);
   cutg2_mod5_140->SetPoint(0,941.7005,988.1134);
   cutg2_mod5_140->SetPoint(1,1109.629,1127.219);
   cutg2_mod5_140->SetPoint(2,1190.794,963.1988);
   cutg2_mod5_140->SetPoint(3,1001.875,869.7694);
   cutg2_mod5_140->SetPoint(4,950.0969,998.4944);
   cutg2_mod5_140->SetPoint(5,941.7005,988.1134);
   cutg2_mod5_140->Write();

   TCutG *cutg2_mod5_150 = new TCutG("cutg2_mod5_150",6);
   cutg2_mod5_150->SetPoint(0,1259.205,1249.539);
   cutg2_mod5_150->SetPoint(1,1319.188,1053.125);
   cutg2_mod5_150->SetPoint(2,1152.405,973.6248);
   cutg2_mod5_150->SetPoint(3,1095.348,1167.7);
   cutg2_mod5_150->SetPoint(4,1260.668,1244.862);
   cutg2_mod5_150->SetPoint(5,1259.205,1249.539);
   cutg2_mod5_150->Write();


  file->Write();
  file->Close();
  
  delete file;
  

}
