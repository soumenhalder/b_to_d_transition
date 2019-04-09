void continuumvars(TString mode="piee") {
    bool do_mcmatch =  false; //true means do truth matching and false means don't do
    double no_of_generated_event=200000;
    
    TString fname="../input_rootfiles/rootfile_apr8/";
    fname+= mode;
    fname += ".root";
  
    
    TFile *f = new TFile(fname);
    TTree *tree = (TTree*) f->Get(mode);
    int nentries = tree->GetEntries();
    cout<<"Entries="<<nentries<<endl ; 
  

     /*truth matching*/  

        /* with bremrecovery*/
        Double_t B1_pi_mcPDG, B1_e0_mcPDG, B1_e1_mcPDG,B1_mcPDG,B1_pi_genMotherPDG,B1_e0_genMotherPDG,B1_e1_genMotherPDG;
        tree->SetBranchAddress("B_e0_mcPDG",&B1_e0_mcPDG);
        tree->SetBranchAddress("B_e1_mcPDG",&B1_e1_mcPDG);
        tree->SetBranchAddress("B_pi_mcPDG",&B1_pi_mcPDG);
        tree->SetBranchAddress("B_mcPDG",&B1_mcPDG);
        tree->SetBranchAddress("B_pi_genMotherPDG",&B1_pi_genMotherPDG);
        tree->SetBranchAddress("B_e0_genMotherPDG",&B1_e0_genMotherPDG);        
        tree->SetBranchAddress("B_e1_genMotherPDG",&B1_e1_genMotherPDG);
 
        
     /*Continuum suppression variable*/

    TH1F *h[25];
     
     h[1]=new TH1F("k0hso00","",150,0,3);
         h[1]->GetXaxis()->SetTitle("k0hso00");
     h[2]=new TH1F("k0hso01","",150,0-1.5,1.5);
         h[2]->GetXaxis()->SetTitle("k0hso01");
     h[3]=new TH1F("k0hso02","",150,-1.5,1.5);
          h[3]->GetXaxis()->SetTitle("k0hso02");
     h[4]=new TH1F("k0hso03","",150,-1,1);
          h[4]->GetXaxis()->SetTitle("k0hso03");
     h[5]=new TH1F("k0hso04","",150,-1,1);
           h[5]->GetXaxis()->SetTitle("k0hso04");
     h[6]=new TH1F("k0hso10","",150,0,2.5);
          h[6]->GetXaxis()->SetTitle("k0hso10");
     h[7]=new TH1F("k0hso12","",150,-1,1);
           h[7]->GetXaxis()->SetTitle("k0hso12");
     h[8]=new TH1F("k0hso14","",150,-0.6,0.6);
           h[8]->GetXaxis()->SetTitle("k0hso14");
     h[9]=new TH1F("k0hso20","",150,0,2);
           h[9]->GetXaxis()->SetTitle("k0hso20");
     h[10]=new TH1F("k0hso22","",150,-0.6,0.9);
           h[10]->GetXaxis()->SetTitle("k0hso22");
     h[11]=new TH1F("k0hso24","",150,-0.6,0.9);
           h[11]->GetXaxis()->SetTitle("k0hso24");
     h[12]=new TH1F("k0hoo0","",150,0,0.6);
           h[12]->GetXaxis()->SetTitle("k0hoo0");
     h[13]=new TH1F("k0hoo1","",150,-0.06,0.06);
           h[13]->GetXaxis()->SetTitle("k0hoo1");
     h[14]=new TH1F("k0hoo2","",150,-0.1,0.2);
          h[14]->GetXaxis()->SetTitle("k0hoo2");
     h[15]=new TH1F("k0hoo3","",150,-0.04,0.05);
           h[15]->GetXaxis()->SetTitle("k0hoo3");
     h[16]=new TH1F("k0hoo4","k0hoo4",150,-0.1,0.1);
           h[16]->GetXaxis()->SetTitle("k0hoo4");
     h[21]=new TH1F("k0et","",150,0,15);
        h[21]->GetXaxis()->SetTitle("k0et");
     h[22]=new TH1F("k0mm2","",150,0,12);   
        h[22]->GetXaxis()->SetTitle("k0mm2");  

     h[23]=new TH1F("thrustb","",150,0.6,1);
        h[23]->GetXaxis()->SetTitle("B_{thrust}");
     h[24]=new TH1F("thrusto","",150,0.5,1);
        h[24]->GetXaxis()->SetTitle("ROE_{thrust}");
 
     h[17]=new TH1F("|Cos(#theta_{B})|","",150,0,1.1);
        h[17]->GetXaxis()->SetTitle("|Cos(#theta_{B}^{ROE})|");
     h[18]=new TH1F("|Cos(#theta_{T})|","",150,0,1.1);
        h[18]->GetXaxis()->SetTitle("|Cos(#theta_{T})|");
     h[19]=new TH1F("R2","",150,0,1.1);
        h[19]->GetXaxis()->SetTitle("R2");
     h[20]=new TH1F("costhetab","",150,0,1.1);
        h[20]->GetXaxis()->SetTitle("|Cos(#theta_{B})|");
     
      TH1F *CC[9];
     for(int i=0;i<9;i++){
           TString name = "CC";
           name += (i+1);
           CC[i]=new TH1F(name,name,50,0,8);   
           }
     for(int i=1;i<25;i++) {h[i]->SetStats(0);h[i]->GetXaxis()->SetTitleSize(0.05);}
     for(int i=0;i<9;i++) {CC[i]->SetStats(0);CC[i]->GetXaxis()->SetTitleSize(0.05);}
     
     
     
     
     
     
     double k0hso00,k0hso01,k0hso02,k0hso03,k0hso04,k0hso10,k0hso12,k0hso14,
           k0hso20,k0hso22,k0hso24,k0hoo0,k0hoo1,k0hoo2,k0hoo3,k0hoo4,k0et,k0mm2;  
     double cosb,cost,r2,cosb1,thrustb, thrustroe;
     double cc[9];
     tree->SetBranchAddress("KSFWVariables__bohso00__bc",&k0hso00);
     tree->SetBranchAddress("KSFWVariables__bohso01__bc",&k0hso01);
     tree->SetBranchAddress("KSFWVariables__bohso02__bc",&k0hso02);
     tree->SetBranchAddress("KSFWVariables__bohso03__bc",&k0hso03);
     tree->SetBranchAddress("KSFWVariables__bohso04__bc",&k0hso04);
     tree->SetBranchAddress("KSFWVariables__bohso10__bc",&k0hso10);
     tree->SetBranchAddress("KSFWVariables__bohso12__bc",&k0hso12);
     tree->SetBranchAddress("KSFWVariables__bohso14__bc",&k0hso14);
     tree->SetBranchAddress("KSFWVariables__bohso20__bc",&k0hso20);
     tree->SetBranchAddress("KSFWVariables__bohso22__bc",&k0hso22);
     tree->SetBranchAddress("KSFWVariables__bohso24__bc",&k0hso24);
     tree->SetBranchAddress("KSFWVariables__bohoo0__bc",&k0hoo0);
     tree->SetBranchAddress("KSFWVariables__bohoo1__bc",&k0hoo1);
     tree->SetBranchAddress("KSFWVariables__bohoo2__bc",&k0hoo2);
     tree->SetBranchAddress("KSFWVariables__bohoo3__bc",&k0hoo3);
     tree->SetBranchAddress("KSFWVariables__bohoo4__bc",&k0hoo4);
     tree->SetBranchAddress("KSFWVariables__bomm2__bc",&k0mm2);
     tree->SetBranchAddress("KSFWVariables__boet__bc",&k0et);
     tree->SetBranchAddress("cosTBz",&cosb);
     tree->SetBranchAddress("cosTBTO",&cost);
     tree->SetBranchAddress("R2",&r2);
     tree->SetBranchAddress("CMScosTheta",&cosb1);
     tree->SetBranchAddress("CleoConeCS__bo1__bc",&cc[0]);
     tree->SetBranchAddress("CleoConeCS__bo2__bc",&cc[1]);
     tree->SetBranchAddress("CleoConeCS__bo3__bc",&cc[2]);
     tree->SetBranchAddress("CleoConeCS__bo4__bc",&cc[3]);
     tree->SetBranchAddress("CleoConeCS__bo5__bc",&cc[4]);
     tree->SetBranchAddress("CleoConeCS__bo6__bc",&cc[5]);
     tree->SetBranchAddress("CleoConeCS__bo7__bc",&cc[6]);
     tree->SetBranchAddress("CleoConeCS__bo8__bc",&cc[7]);
     tree->SetBranchAddress("CleoConeCS__bo9__bc",&cc[8]);
     tree->SetBranchAddress("thrustOm",&thrustroe);  
     tree->SetBranchAddress("thrustBm",&thrustb);
    
    int event1 = 0;
    for(int i=0;i<tree->GetEntries();i++){
         tree->GetEntry(i);
          /*Truth matching*/
         bool istruth = false;
         if(mode == "piee")  
               istruth = TMath::Abs(B1_e0_mcPDG)==11 && TMath::Abs(B1_pi_mcPDG)==211 
                        && TMath::Abs(B1_pi_mcPDG)==211 && TMath::Abs(B1_e1_mcPDG)==11 
                        && (B1_e0_mcPDG+B1_e1_mcPDG)==0  && TMath::Abs(B1_mcPDG) == 521;
         if(!istruth )  continue;
         /*Filling*/ 
          h[1]->Fill(k0hso00);
          h[2]->Fill(k0hso01);
          h[3]->Fill(k0hso02);
          h[4]->Fill(k0hso03); 
          h[5]->Fill(k0hso04);
          h[6]->Fill(k0hso10);
          h[7]->Fill(k0hso12);
          h[8]->Fill(k0hso14);
          h[9]->Fill(k0hso20);
          h[10]->Fill(k0hso22);
          h[11]->Fill(k0hso24);
          h[12]->Fill(k0hoo0);
          h[13]->Fill(k0hoo1);
          h[14]->Fill(k0hoo2);
          h[15]->Fill(k0hoo3);
          h[16]->Fill(k0hoo4);
          h[17]->Fill(cosb);
          h[18]->Fill(cost);
          h[19]->Fill(r2);
          h[20]->Fill(cosb1);
          h[21]->Fill(k0et);
          h[22]->Fill(k0mm2);     
          h[23]->Fill(thrustb);
          h[24]->Fill(thrustroe); 
          for(int j=0; j<9 ;j++)
            CC[j]->Fill(cc[j]);
           }
        
        
        
        
    TH1F *h1[25];
     
     h1[1]=new TH1F("1k0hso00","",150,0,3);
         h1[1]->GetXaxis()->SetTitle("k0hso00");
     h1[2]=new TH1F("1k0hso01","",150,0-1.5,1.5);
         h1[2]->GetXaxis()->SetTitle("k0hso01");
     h1[3]=new TH1F("1k0hso02","",150,-1.5,1.5);
          h1[3]->GetXaxis()->SetTitle("k0hso02");
     h1[4]=new TH1F("1k0hso03","",150,-1,1);
          h1[4]->GetXaxis()->SetTitle("k0hso03");
     h1[5]=new TH1F("1k0hso04","",150,-1,1);
           h1[5]->GetXaxis()->SetTitle("k0hso04");
     h1[6]=new TH1F("1k0hso10","",150,0,2.5);
          h1[6]->GetXaxis()->SetTitle("k0hso10");
     h1[7]=new TH1F("1k0hso12","",150,-1,1);
           h1[7]->GetXaxis()->SetTitle("k0hso12");
     h1[8]=new TH1F("1k0hso14","",150,-0.6,0.6);
           h1[8]->GetXaxis()->SetTitle("k0hso14");
     h1[9]=new TH1F("1k0hso20","",150,0,2);
           h1[9]->GetXaxis()->SetTitle("k0hso20");
     h1[10]=new TH1F("1k0hso22","",150,-0.6,0.9);
           h1[10]->GetXaxis()->SetTitle("k0hso22");
     h1[11]=new TH1F("1k0hso24","",150,-0.6,0.9);
           h1[11]->GetXaxis()->SetTitle("k0hso24");
     h1[12]=new TH1F("1k0hoo0","",150,0,0.6);
           h1[12]->GetXaxis()->SetTitle("k0hoo0");
     h1[13]=new TH1F("1k0hoo1","",150,-0.06,0.06);
           h1[13]->GetXaxis()->SetTitle("k0hoo1");
     h1[14]=new TH1F("1k0hoo2","",150,-0.1,0.2);
          h1[14]->GetXaxis()->SetTitle("k0hoo2");
     h1[15]=new TH1F("1k0hoo3","",150,-0.04,0.05);
           h1[15]->GetXaxis()->SetTitle("k0hoo3");
     h1[16]=new TH1F("1k0hoo4","k0hoo4",150,-0.1,0.1);
           h1[16]->GetXaxis()->SetTitle("k0hoo4");
     h1[21]=new TH1F("1k0et","",150,0,15);
        h1[21]->GetXaxis()->SetTitle("k0et");
     h1[22]=new TH1F("1k0mm2","",150,0,12);   
        h1[22]->GetXaxis()->SetTitle("k0mm2");  

     h1[23]=new TH1F("1thrustb","",150,0.6,1);
        h1[23]->GetXaxis()->SetTitle("B_{thrust}");
     h1[24]=new TH1F("1thrusto","",150,0.5,1);
        h1[24]->GetXaxis()->SetTitle("ROE_{thrust}");
 
     h1[17]=new TH1F("1|Cos(#theta_{B})|","",150,0,1.1);
        h1[17]->GetXaxis()->SetTitle("|Cos(#theta_{B}^{ROE})|");
     h1[18]=new TH1F("1|Cos(#theta_{T})|","",150,0,1.1);
        h1[18]->GetXaxis()->SetTitle("|Cos(#theta_{T})|");
     h1[19]=new TH1F("1R2","",150,0,1.1);
        h1[19]->GetXaxis()->SetTitle("R2");
     h1[20]=new TH1F("1costhetab","",150,0,1.1);
        h1[20]->GetXaxis()->SetTitle("|Cos(#theta_{B})|");
     
      TH1F *CC1[9];
     for(int i=0;i<9;i++){
           TString name = "1CC";
           name += (i+1);
           CC1[i]=new TH1F(name,name,50,0,8);   
           }
     for(int i=1;i<25;i++) {h1[i]->SetStats(0);h1[i]->GetXaxis()->SetTitleSize(0.05);h1[i]->SetLineColor(kRed);}
     for(int i=0;i<9;i++) {CC1[i]->SetStats(0);CC1[i]->GetXaxis()->SetTitleSize(0.05);CC1[i]->SetLineColor(kRed);}
     
     for(int i=0;i<tree->GetEntries();i++){
         tree->GetEntry(i);
         /*Filling*/ 
          h1[1]->Fill(k0hso00);
          h1[2]->Fill(k0hso01);
          h1[3]->Fill(k0hso02);
          h1[4]->Fill(k0hso03); 
          h1[5]->Fill(k0hso04);
          h1[6]->Fill(k0hso10);
          h1[7]->Fill(k0hso12);
          h1[8]->Fill(k0hso14);
          h1[9]->Fill(k0hso20);
          h1[10]->Fill(k0hso22);
          h1[11]->Fill(k0hso24);
          h1[12]->Fill(k0hoo0);
          h1[13]->Fill(k0hoo1);
          h1[14]->Fill(k0hoo2);
          h1[15]->Fill(k0hoo3);
          h1[16]->Fill(k0hoo4);
          h1[17]->Fill(cosb);
          h1[18]->Fill(cost);
          h1[19]->Fill(r2);
          h1[20]->Fill(cosb1);
          h1[21]->Fill(k0et);
          h1[22]->Fill(k0mm2);     
          h1[23]->Fill(thrustb);
          h1[24]->Fill(thrustroe); 
          for(int j=0; j<9 ;j++)
            CC1[j]->Fill(cc[j]);
           }
    
    for(int i=1;i<25;i++){
       double scale= 1/(h[i]->Integral());       
         h[i]->Scale(scale);
       double scale1= 1/(h1[i]->Integral());       
         h1[i]->Scale(scale1);
    }
      for(int i=0;i<9;i++){
       double scale= 1/(CC[i]->Integral());       
         CC[i]->Scale(scale);
       double scale1= 1/(CC1[i]->Integral());       
         CC1[i]->Scale(scale1);
    } 
        
        TCanvas *c1=new TCanvas("c5","c5",2000,2000);
        c1->Divide(4,4);
        for(int i=1; i<17;i++){
           c1->cd(i);
           h[i]->Draw();
           h1[i]->Draw("same");
         }
       // c1->SaveAs(cont_supp2);
      
        
        TCanvas *c2=new TCanvas("c2","c2",2000,2000);
        c2->Divide(3,3);
         for(int i=17; i<25;i++){
           c2->cd(i-16);
           h1[i]->Draw();
          h[i]->Draw("same");
         }

       // c2->SaveAs(cont_supp1);
       
        TCanvas *c3 = new TCanvas("c3","c3",2000,2000);
        c3->Divide(3,3);
        for(int i=0;i<9;i++) {
         c3->cd(i+1); 
         CC[i]->Draw();
         CC1[i]->Draw("same");
        } 
        
        

    
}
