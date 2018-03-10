   #include "TCutG.h"

void cuts_root(void){
  TCutG *cutg[16];
  TCutG *cutg1[16];
  TCutG *cutg2[16];


cutg[0] = new TCutG("cut_p10_vs_p12p13st_mod0",15);
cutg[0]->SetPoint(0,23.3649,1408.346);
   cutg[0]->SetPoint(1,224.8172,866.2034);
   cutg[0]->SetPoint(2,379.264,640.3105);
   cutg[0]->SetPoint(3,708.3028,420.0649);
   cutg[0]->SetPoint(4,1514.112,233.7032);
   cutg[0]->SetPoint(5,2299.776,143.346);
   cutg[0]->SetPoint(6,2440.793,75.57812);
   cutg[0]->SetPoint(7,2326.636,36.04686);
   cutg[0]->SetPoint(8,1574.548,58.63615);
   cutg[0]->SetPoint(9,1091.062,143.346);
   cutg[0]->SetPoint(10,500.1354,318.413);
   cutg[0]->SetPoint(11,137.5212,668.5471);
   cutg[0]->SetPoint(12,16.64982,1137.275);
   cutg[0]->SetPoint(13,43.51013,1380.11);
   cutg[0]->SetPoint(14,23.3649,1408.346);


   cutg1[0] = new TCutG("cut_am1_vs_am2_mod0",20);
   cutg1[0]->SetPoint(0,226.0788,1346.401);
   cutg1[0]->SetPoint(1,401.55,1171.103);
   cutg1[0]->SetPoint(2,587.6558,1022.546);
   cutg1[0]->SetPoint(3,970.5019,832.3927);
   cutg1[0]->SetPoint(4,1326.762,698.6911);
   cutg1[0]->SetPoint(5,1778.733,609.5567);
   cutg1[0]->SetPoint(6,2081.819,541.2203);
   cutg1[0]->SetPoint(7,2180.189,567.9607);
   cutg1[0]->SetPoint(8,2265.266,478.8263);
   cutg1[0]->SetPoint(9,2233.363,392.663);
   cutg1[0]->SetPoint(10,2111.064,410.4899);
   cutg1[0]->SetPoint(11,1821.271,458.0283);
   cutg1[0]->SetPoint(12,1507.55,514.48);
   cutg1[0]->SetPoint(13,1281.564,579.8453);
   cutg1[0]->SetPoint(14,967.8433,680.8642);
   cutg1[0]->SetPoint(15,563.7279,888.8445);
   cutg1[0]->SetPoint(16,53.26633,1334.516);
   cutg1[0]->SetPoint(17,61.24229,1545.468);
   cutg1[0]->SetPoint(18,228.7375,1343.43);
   cutg1[0]->SetPoint(19,226.0788,1346.401);







   cutg1[3] = new TCutG("cut_am1_vs_am2_mod3",14);
   cutg1[3]->SetPoint(0,49.54562,1878.232);
   cutg1[3]->SetPoint(1,581.1599,1302.266);
   cutg1[3]->SetPoint(2,871.9574,1107.39);
   cutg1[3]->SetPoint(3,990.0939,1051.093);
   cutg1[3]->SetPoint(4,1078.696,1029.44);
   cutg1[3]->SetPoint(5,1155.939,908.184);
   cutg1[3]->SetPoint(6,1158.211,786.928);
   cutg1[3]->SetPoint(7,1087.784,765.2751);
   cutg1[3]->SetPoint(8,749.2772,986.1343);
   cutg1[3]->SetPoint(9,394.8677,1250.299);
   cutg1[3]->SetPoint(10,99.52645,1536.117);
   cutg1[3]->SetPoint(11,45.00191,1653.043);
   cutg1[3]->SetPoint(12,54.08933,1878.232);
   cutg1[3]->SetPoint(13,49.54562,1878.232);

   cutg[3] = new TCutG("cut_p10_vs_p12p13st_mod3",23);
   cutg[3]->SetPoint(0,38.87409,1594.606);
   cutg[3]->SetPoint(1,173.9808,1218.456);
   cutg[3]->SetPoint(2,382.2704,750.5626);
   cutg[3]->SetPoint(3,725.6667,498.2671);
   cutg[3]->SetPoint(4,1215.429,319.3666);
   cutg[3]->SetPoint(5,1733.338,227.6228);
   cutg[3]->SetPoint(6,2144.288,186.3381);
   cutg[3]->SetPoint(7,2386.354,167.9893);
   cutg[3]->SetPoint(8,2566.496,154.2277);
   cutg[3]->SetPoint(9,2707.232,131.2918);
   cutg[3]->SetPoint(10,2769.156,71.6583);
   cutg[3]->SetPoint(11,2724.121,39.54797);
   cutg[3]->SetPoint(12,2121.77,62.48392);
   cutg[3]->SetPoint(13,1862.815,80.83269);
   cutg[3]->SetPoint(14,1294.241,154.2277);
   cutg[3]->SetPoint(15,877.6618,259.7331);
   cutg[3]->SetPoint(16,658.1134,346.8898);
   cutg[3]->SetPoint(17,410.4177,525.7902);
   cutg[3]->SetPoint(18,207.7575,764.3242);
   cutg[3]->SetPoint(19,100.798,1039.556);
   cutg[3]->SetPoint(20,44.50354,1236.805);
   cutg[3]->SetPoint(21,50.13298,1590.019);
   cutg[3]->SetPoint(22,38.87409,1594.606);



   cutg[4] = new TCutG("cut_p10_vs_p12p13st_mod4",17);
   cutg[4]->SetPoint(0,37.05079,1469.653);
   cutg[4]->SetPoint(1,184.5103,1060.526);
   cutg[4]->SetPoint(2,449.9373,616.985);
   cutg[4]->SetPoint(3,962.3589,379.9203);
   cutg[4]->SetPoint(4,1460.035,288.1533);
   cutg[4]->SetPoint(5,1994.575,211.6808);
   cutg[4]->SetPoint(6,2451.699,165.7973);
   cutg[4]->SetPoint(7,2562.294,154.3264);
   cutg[4]->SetPoint(8,2562.294,43.44125);
   cutg[4]->SetPoint(9,1909.786,43.44125);
   cutg[4]->SetPoint(10,1117.191,188.739);
   cutg[4]->SetPoint(11,792.7805,276.6824);
   cutg[4]->SetPoint(12,390.9535,437.2747);
   cutg[4]->SetPoint(13,136.5859,792.8718);
   cutg[4]->SetPoint(14,25.99133,1251.707);
   cutg[4]->SetPoint(15,40.73728,1450.535);
   cutg[4]->SetPoint(16,37.05079,1469.653);


   cutg1[4] = new TCutG("cut_am1_vs_am2_mod4",11);
   cutg1[4]->SetPoint(0,57.17236,1859.145);
   cutg1[4]->SetPoint(1,539.0659,1357.199);
   cutg1[4]->SetPoint(2,996.3044,1034.897);
   cutg1[4]->SetPoint(3,1068.028,855.2534);
   cutg1[4]->SetPoint(4,1005.27,680.8933);
   cutg1[4]->SetPoint(5,792.3401,797.1333);
   cutg1[4]->SetPoint(6,395.6185,1077.166);
   cutg1[4]->SetPoint(7,166.9993,1267.377);
   cutg1[4]->SetPoint(8,50.44826,1452.305);
   cutg1[4]->SetPoint(9,63.89646,1853.861);
   cutg1[4]->SetPoint(10,57.17236,1859.145);

  

   cutg2[4] = new TCutG("cut_p10_vs_enProt_mod4",19);
   cutg2[4]->SetPoint(0,18.06027,1520.475);
   cutg2[4]->SetPoint(1,19.03125,927.8597);
   cutg2[4]->SetPoint(2,30.35937,475.4818);
   cutg2[4]->SetPoint(3,43.95312,330.7208);
   cutg2[4]->SetPoint(4,64.34375,249.2928);
   cutg2[4]->SetPoint(5,85.70536,195.0074);
   cutg2[4]->SetPoint(6,154.9688,163.341);
   cutg2[4]->SetPoint(7,204.8125,122.627);
   cutg2[4]->SetPoint(8,229.4107,122.627);
   cutg2[4]->SetPoint(9,229.7344,23.10383);
   cutg2[4]->SetPoint(10,66.60937,50.24651);
   cutg2[4]->SetPoint(11,47.51339,136.1983);
   cutg2[4]->SetPoint(12,30.03571,267.3879);
   cutg2[4]->SetPoint(13,21.62053,416.6726);
   cutg2[4]->SetPoint(14,16.76562,620.2427);
   cutg2[4]->SetPoint(15,15.14732,819.289);
   cutg2[4]->SetPoint(16,14.82366,1543.094);
   cutg2[4]->SetPoint(17,17.08928,1520.475);
   cutg2[4]->SetPoint(18,18.06027,1520.475);

   cutg[7] = new TCutG("cut_p10_vs_p12p13st_mod7",17);
   cutg[7]->SetPoint(0,30.18096,1524.735);
   cutg[7]->SetPoint(1,177.466,1147.39);
   cutg[7]->SetPoint(2,408.914,730.5556);
   cutg[7]->SetPoint(3,752.5792,519.9445);
   cutg[7]->SetPoint(4,1306.652,309.3335);
   cutg[7]->SetPoint(5,1839.683,252.293);
   cutg[7]->SetPoint(6,2765.475,164.5384);
   cutg[7]->SetPoint(7,2989.91,98.72244);
   cutg[7]->SetPoint(8,2646.244,41.68195);
   cutg[7]->SetPoint(9,2008.009,68.00833);
   cutg[7]->SetPoint(10,1418.869,160.1507);
   cutg[7]->SetPoint(11,829.7285,256.6807);
   cutg[7]->SetPoint(12,472.0362,440.9654);
   cutg[7]->SetPoint(13,114.3439,730.5556);
   cutg[7]->SetPoint(14,44.20811,954.3298);
   cutg[7]->SetPoint(15,37.19453,1494.021);
   cutg[7]->SetPoint(16,30.18096,1524.735);

   cutg1[7] = new TCutG("cut_am1_vs_am2_mod7",21);
   cutg1[7]->SetPoint(0,276.8459,1536.002);
   cutg1[7]->SetPoint(1,487.9483,1274.72);
   cutg1[7]->SetPoint(2,711.7169,1071.123);
   cutg1[7]->SetPoint(3,1013.593,901.4597);
   cutg1[7]->SetPoint(4,1311.248,786.0883);
   cutg1[7]->SetPoint(5,1562.46,704.6496);
   cutg1[7]->SetPoint(6,1716.564,640.1774);
   cutg1[7]->SetPoint(7,1815.783,660.537);
   cutg1[7]->SetPoint(8,1887.557,534.9858);
   cutg1[7]->SetPoint(9,1841.115,453.5472);
   cutg1[7]->SetPoint(10,1716.564,507.8396);
   cutg1[7]->SetPoint(11,1528.683,548.5589);
   cutg1[7]->SetPoint(12,1313.359,609.6379);
   cutg1[7]->SetPoint(13,1053.703,701.2564);
   cutg1[7]->SetPoint(14,886.9319,796.2681);
   cutg1[7]->SetPoint(15,726.494,877.7067);
   cutg1[7]->SetPoint(16,437.2837,1132.202);
   cutg1[7]->SetPoint(17,53.07731,1573.328);
   cutg1[7]->SetPoint(18,57.29936,1929.622);
   cutg1[7]->SetPoint(19,283.1789,1532.609);
   cutg1[7]->SetPoint(20,276.8459,1536.002);


   cutg[11] = new TCutG("cut_p10_vs_p12p13st_mod11",18);
   cutg[11]->SetPoint(0,35.43678,1477.392);
   cutg[11]->SetPoint(1,135.8272,1171.897);
   cutg[11]->SetPoint(2,245.344,890.2081);
   cutg[11]->SetPoint(3,450.688,596.6164);
   cutg[11]->SetPoint(4,975.456,358.569);
   cutg[11]->SetPoint(5,1559.546,255.4152);
   cutg[11]->SetPoint(6,2075.187,195.9034);
   cutg[11]->SetPoint(7,2408.301,160.1963);
   cutg[11]->SetPoint(8,2499.565,45.14005);
   cutg[11]->SetPoint(9,2011.302,45.14005);
   cutg[11]->SetPoint(10,1408.96,112.5868);
   cutg[11]->SetPoint(11,1016.525,199.8708);
   cutg[11]->SetPoint(12,587.584,342.6992);
   cutg[11]->SetPoint(13,295.5392,596.6164);
   cutg[11]->SetPoint(14,122.1376,882.2732);
   cutg[11]->SetPoint(15,35.43678,1215.539);
   cutg[11]->SetPoint(16,44.56318,1441.684);
   cutg[11]->SetPoint(17,35.43678,1477.392);

   cutg1[11] = new TCutG("cut_am1_vs_am2_mod11",10);
   cutg1[11]->SetPoint(0,48.40292,1717.988);
   cutg1[11]->SetPoint(1,475.0482,1316.841);
   cutg1[11]->SetPoint(2,947.324,978.7956);
   cutg1[11]->SetPoint(3,965.5762,726.3886);
   cutg1[11]->SetPoint(4,906.2566,681.316);
   cutg1[11]->SetPoint(5,504.708,933.723);
   cutg1[11]->SetPoint(6,94.03344,1307.826);
   cutg1[11]->SetPoint(7,50.68445,1384.45);
   cutg1[11]->SetPoint(8,57.52903,1717.988);
   cutg1[11]->SetPoint(9,48.40292,1717.988);


   cutg2[11] = new TCutG("cut_p10_vs_enProt_mod11",19);
   cutg2[11]->SetPoint(0,-18.5,1999.35);
   cutg2[11]->SetPoint(1,19.83333,1473.864);
   cutg2[11]->SetPoint(2,20.16667,920.4761);
   cutg2[11]->SetPoint(3,22.16667,650.7576);
   cutg2[11]->SetPoint(4,32.5,390.3398);
   cutg2[11]->SetPoint(5,62.5,236.8793);
   cutg2[11]->SetPoint(6,85.83333,176.4251);
   cutg2[11]->SetPoint(7,157.1667,162.4742);
   cutg2[11]->SetPoint(8,193.1667,134.5723);
   cutg2[11]->SetPoint(9,220.1667,111.3207);
   cutg2[11]->SetPoint(10,232.5,102.0201);
   cutg2[11]->SetPoint(11,231.5,27.61496);
   cutg2[11]->SetPoint(12,78.5,32.26527);
   cutg2[11]->SetPoint(13,56.16667,92.71941);
   cutg2[11]->SetPoint(14,36.16667,195.0264);
   cutg2[11]->SetPoint(15,24.83333,339.1863);
   cutg2[11]->SetPoint(16,16.16667,636.8067);
   cutg2[11]->SetPoint(17,12.5,1501.766);
   cutg2[11]->SetPoint(18,-18.5,1999.35);



  TFile* file = new TFile("myCuts.root","RECREATE");
  char n[100];  

  /*
  for (int i=0;i<16;i++){
    
    //if(!cutg[i])continue;
    cutg[i]->Write();
    cutg1[i]->Write();
    }*/

  cutg[0]->Write();
  cutg1[0]->Write();

  cutg[3]->Write();
  cutg1[3]->Write();

  cutg[4]->Write();
  cutg1[4]->Write();
  cutg2[4]->Write();
 
  cutg[7]->Write();
  cutg1[7]->Write();

  cutg[11]->Write();
  cutg1[11]->Write();
  cutg2[11]->Write();

  file->Write();
  file->Close();
  
  delete file;

}
