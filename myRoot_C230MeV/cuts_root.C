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


   cutg1[4] = new TCutG("cut_am1_vs_am2_mod4",14);
   cutg1[4]->SetPoint(0,49.99998,1831.572);
   cutg1[4]->SetPoint(1,647.1457,1213.414);
   cutg1[4]->SetPoint(2,973.7614,990.1908);
   cutg1[4]->SetPoint(3,1590.702,766.9671);
   cutg1[4]->SetPoint(4,2102.07,635.3223);
   cutg1[4]->SetPoint(5,2230.737,606.7039);
   cutg1[4]->SetPoint(6,2243.933,412.0986);
   cutg1[4]->SetPoint(7,2022.89,446.4407);
   cutg1[4]->SetPoint(8,1313.574,629.5986);
   cutg1[4]->SetPoint(9,660.3423,898.6118);
   cutg1[4]->SetPoint(10,264.4446,1173.349);
   cutg1[4]->SetPoint(11,46.70083,1430.915);
   cutg1[4]->SetPoint(12,49.99998,1837.296);
   cutg1[4]->SetPoint(13,49.99998,1831.572);
  

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


   cutg[5] = new TCutG("cut_p10_vs_p12p13st_mod5",19);
   cutg[5]->SetPoint(0,67.62491,1363.921);
   cutg[5]->SetPoint(1,222.4168,947.7127);
   cutg[5]->SetPoint(2,403.8969,716.9062);
   cutg[5]->SetPoint(3,660.1041,508.802);
   cutg[5]->SetPoint(4,1161.843,342.3186);
   cutg[5]->SetPoint(5,1861.075,213.6724);
   cutg[5]->SetPoint(6,2304.1,183.4027);
   cutg[5]->SetPoint(7,2688.411,164.4841);
   cutg[5]->SetPoint(8,2885.904,137.9981);
   cutg[5]->SetPoint(9,2933.943,50.97275);
   cutg[5]->SetPoint(10,2314.776,35.8379);
   cutg[5]->SetPoint(11,1626.219,100.161);
   cutg[5]->SetPoint(12,798.883,274.2118);
   cutg[5]->SetPoint(13,532.0005,414.2092);
   cutg[5]->SetPoint(14,270.4556,622.3134);
   cutg[5]->SetPoint(15,115.6638,947.7127);
   cutg[5]->SetPoint(16,78.30021,1099.061);
   cutg[5]->SetPoint(17,78.30021,1345.003);
   cutg[5]->SetPoint(18,67.62491,1363.921);

   cutg1[5] = new TCutG("cut_am1_vs_am2_mod5",16);
   cutg1[5]->SetPoint(0,71.31292,1880.314);
   cutg1[5]->SetPoint(1,355.4856,1566.687);
   cutg1[5]->SetPoint(2,687.0204,1253.06);
   cutg1[5]->SetPoint(3,1077.758,1050.125);
   cutg1[5]->SetPoint(4,1586.9,839.8104);
   cutg1[5]->SetPoint(5,2096.043,736.498);
   cutg1[5]->SetPoint(6,2386.136,681.1521);
   cutg1[5]->SetPoint(7,2457.179,522.4938);
   cutg1[5]->SetPoint(8,1865.153,588.9089);
   cutg1[5]->SetPoint(9,1065.917,839.8104);
   cutg1[5]->SetPoint(10,669.2596,1061.194);
   cutg1[5]->SetPoint(11,278.5222,1337.924);
   cutg1[5]->SetPoint(12,83.15345,1633.102);
   cutg1[5]->SetPoint(13,47.63187,1780.691);
   cutg1[5]->SetPoint(14,71.31292,1891.383);
   cutg1[5]->SetPoint(15,71.31292,1880.314);



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


   cutg1[11] = new TCutG("cut_am1_vs_am2_mod11",18);
   cutg1[11]->SetPoint(0,59.3415,1768.463);
   cutg1[11]->SetPoint(1,50.84921,1829.678);
   cutg1[11]->SetPoint(2,370.7252,1383.167);
   cutg1[11]->SetPoint(3,789.6778,1062.688);
   cutg1[11]->SetPoint(4,1143.523,807.025);
   cutg1[11]->SetPoint(5,1514.353,655.7876);
   cutg1[11]->SetPoint(6,1885.182,569.3663);
   cutg1[11]->SetPoint(7,1987.09,565.7654);
   cutg1[11]->SetPoint(8,2043.705,497.3485);
   cutg1[11]->SetPoint(9,2012.566,400.1244);
   cutg1[11]->SetPoint(10,1817.244,454.1378);
   cutg1[11]->SetPoint(11,1358.661,562.1645);
   cutg1[11]->SetPoint(12,939.7081,706.2001);
   cutg1[11]->SetPoint(13,636.8167,850.2357);
   cutg1[11]->SetPoint(14,220.6949,1210.325);
   cutg1[11]->SetPoint(15,48.01845,1422.777);
   cutg1[11]->SetPoint(16,50.84921,1829.678);
   cutg1[11]->SetPoint(17,59.3415,1768.463);

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


   cutg[13] = new TCutG("cut_p10_vs_p12p13st_mod13",22);
   cutg[13]->SetPoint(0,28.14712,1625.524);
   cutg[13]->SetPoint(1,187.6076,1121.769);
   cutg[13]->SetPoint(2,332.5716,882.9512);
   cutg[13]->SetPoint(3,617.6675,599.3554);
   cutg[13]->SetPoint(4,960.7491,423.9738);
   cutg[13]->SetPoint(5,1308.663,341.8803);
   cutg[13]->SetPoint(6,1849.862,259.7867);
   cutg[13]->SetPoint(7,2250.929,226.203);
   cutg[13]->SetPoint(8,2444.214,188.8878);
   cutg[13]->SetPoint(9,2980.581,147.841);
   cutg[13]->SetPoint(10,3149.706,95.59969);
   cutg[13]->SetPoint(11,3144.874,28.43226);
   cutg[13]->SetPoint(12,2183.279,54.55293);
   cutg[13]->SetPoint(13,1685.569,117.9888);
   cutg[13]->SetPoint(14,1236.181,211.2769);
   cutg[13]->SetPoint(15,994.574,267.2498);
   cutg[13]->SetPoint(16,496.8642,461.289);
   cutg[13]->SetPoint(17,279.4181,733.6902);
   cutg[13]->SetPoint(18,100.6291,1062.064);
   cutg[13]->SetPoint(19,32.97926,1334.466);
   cutg[13]->SetPoint(20,23.31499,1614.33);
   cutg[13]->SetPoint(21,28.14712,1625.524);


   cutg1[13] = new TCutG("cut_am1_vs_am2_mod13",19);
   cutg1[13]->SetPoint(0,-443.75,2341.492);
   cutg1[13]->SetPoint(1,319.964,1744.07);
   cutg1[13]->SetPoint(2,615.9772,1441.53);
   cutg1[13]->SetPoint(3,911.9904,1253.878);
   cutg1[13]->SetPoint(4,1166.562,1112.182);
   cutg1[13]->SetPoint(5,1367.851,1016.442);
   cutg1[13]->SetPoint(6,1752.668,870.9161);
   cutg1[13]->SetPoint(7,2125.644,775.1755);
   cutg1[13]->SetPoint(8,2392.056,687.0942);
   cutg1[13]->SetPoint(9,2551.903,664.1164);
   cutg1[13]->SetPoint(10,2445.339,545.3981);
   cutg1[13]->SetPoint(11,1527.698,736.8793);
   cutg1[13]->SetPoint(12,1107.359,913.0419);
   cutg1[13]->SetPoint(13,586.3759,1200.264);
   cutg1[13]->SetPoint(14,272.6019,1495.145);
   cutg1[13]->SetPoint(15,106.8345,1701.944);
   cutg1[13]->SetPoint(16,65.39266,1747.9);
   cutg1[13]->SetPoint(17,65.39266,2015.974);
   cutg1[13]->SetPoint(18,-443.75,2341.492);


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

  cutg[4]->Write();
  cutg1[4]->Write();
  cutg2[4]->Write();
 

  cutg[5]->Write();
  cutg1[5]->Write();

  cutg[7]->Write();
  cutg1[7]->Write();

  cutg[11]->Write();
  cutg1[11]->Write();
  cutg2[11]->Write();

  cutg[13]->Write();
  cutg1[13]->Write();


  file->Write();
  file->Close();
  
  delete file;

}
