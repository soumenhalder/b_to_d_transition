void signalMC_1(TString mode="piee") {
    bool do_mcmatch = true; //true means do truth matching and false means don't do
    double no_of_generated_event=200000;
    
    TString fname="../input_rootfiles/rootfile_apr8/";
    fname+= mode;
    fname += ".root";
    
    TString fname1="../input_rootfiles/rootfile_apr8/";
    fname1+= mode;
    fname1 += "_wo_brem.root";
    
    TFile *f = new TFile(fname);
    TTree *tree = (TTree*) f->Get(mode);
    int nentries = tree->GetEntries();
    cout<<"Entries="<<nentries<<endl ; 
   
   /*for case of brem recovery and wo brem recovery*/ 
    TFile *f2 = new TFile(fname1);   
    TTree *tr = (TTree*) f2->Get(mode);

     TH1F *A=new TH1F("with brem recovery","",100,5.2,5.3);    
    /*Histogram Definition and assigning with tree*/
    
//    Int_t ncandidates , candidate;
//    tree->SetBranchAddress("__candidate__",&candidate);
//    tree->SetBranchAddress("__ncandidates__",&ncandidates); 
   
    /*DeltaE and Mbc*/
    TH1F *mbc=new TH1F("with brem recovery","",100,5.2,5.3);
        mbc->GetXaxis()->SetTitle("M_{bc} (GeV/c^{2})");
       // mbc->GetYaxis()->SetTitle("Entries/ 0.001 GeV/c^{2}");
        
        mbc->SetLineColor(kRed);
        mbc->SetLineWidth(0.5);
        mbc->SetFillColor(kRed);
        mbc->SetFillStyle(3005);
        
        TGaxis *myX = (TGaxis*)mbc->GetXaxis();
        myX->SetMaxDigits(4);       
        
        mbc->GetXaxis()->SetTitleOffset(1.0);
        mbc->GetXaxis()->SetTitleSize(0.04); 
        mbc->GetYaxis()->SetTitleOffset(1.3);
        mbc->GetYaxis()->SetTitleSize(0.04); 
        //mbc->SetStats(0);
       
        Double_t mbC;
        tree->SetBranchAddress("Mbc",&mbC);
        
      TH1F *mbc_wobrem=new TH1F("without brem recovery","",100,5.2,5.3);
        mbc_wobrem->GetXaxis()->SetTitle("M_{bc} (GeV/c^{2})");
      //  mbc_wobrem->GetYaxis()->SetTitle("Entries/ 0.001 GeV/c^{2}");
        mbc_wobrem->SetLineColor(kBlue);
        mbc_wobrem->SetLineWidth(0.5);
        mbc_wobrem->SetFillColor(kBlue);
        mbc_wobrem->SetFillStyle(3006);
        
        TGaxis *mX = (TGaxis*)mbc_wobrem->GetXaxis();
        mX->SetMaxDigits(4);       
        
        mbc_wobrem->GetXaxis()->SetTitleOffset(1.0);
        mbc_wobrem->GetXaxis()->SetTitleSize(0.04); 
        mbc_wobrem->GetYaxis()->SetTitleOffset(1.3);
        mbc_wobrem->GetYaxis()->SetTitleSize(0.04); 
 
        //mbc_wobrem->SetStats(0);
       
        Double_t mbC_wobrem;
        tr->SetBranchAddress("Mbc",&mbC_wobrem);
        
    TH1F *delE=new TH1F("with brem recovery  ","",300,-0.3,0.3);
        delE->GetXaxis()->SetTitle("#DeltaE (GeV)");
       // delE->GetYaxis()->SetTitle("Entries/ 0.002 GeV");
        
        delE->SetLineColor(kRed);
        delE->SetLineWidth(0.5);
        delE->SetFillColor(kRed);
        delE->SetFillStyle(3005);
        
        delE->GetXaxis()->SetTitleOffset(1.0);
        delE->GetXaxis()->SetTitleSize(0.04); 
        delE->GetYaxis()->SetTitleOffset(1.3);
        delE->GetYaxis()->SetTitleSize(0.04); 
        //delE->SetStats(0);
        Double_t de;
        tree->SetBranchAddress("deltaE",&de);
           

     TH1F *delE_wobrem=new TH1F("wo brem recovery  ","",300,-0.3,0.3);
        delE_wobrem->GetXaxis()->SetTitle("#DeltaE (GeV)");
       // delE_wobrem->GetYaxis()->SetTitle("Entries/ 0.002 GeV");
        
        delE_wobrem->SetLineColor(kBlue);
        delE_wobrem->SetLineWidth(0.5);
        delE_wobrem->SetFillColor(kBlue);
        delE_wobrem->SetFillStyle(3006);
        
        delE_wobrem->GetXaxis()->SetTitleOffset(1.0);
        delE_wobrem->GetXaxis()->SetTitleSize(0.04); 
        delE_wobrem->GetYaxis()->SetTitleOffset(1.3);
        delE_wobrem->GetYaxis()->SetTitleSize(0.04); 
        //delE_wobrem->SetStats(0);
        Double_t de_wobrem;
        tr->SetBranchAddress("deltaE",&de_wobrem);

        
     /*truth matching*/  
        /* wo bremrecovery*/
        Double_t B_pi_mcPDG, B_e0_mcPDG, B_e1_mcPDG,B_mcPDG,;
        tr->SetBranchAddress("B_e0_mcPDG",&B_e0_mcPDG);
        tr->SetBranchAddress("B_e1_mcPDG",&B_e1_mcPDG);
        tr->SetBranchAddress("B_pi_mcPDG",&B_pi_mcPDG);
        tr->SetBranchAddress("B_mcPDG",&B_mcPDG);
        
        /* with bremrecovery*/
        Double_t B1_pi_mcPDG, B1_e0_mcPDG, B1_e1_mcPDG,B1_mcPDG;
        tree->SetBranchAddress("B_e0_mcPDG",&B1_e0_mcPDG);
        tree->SetBranchAddress("B_e1_mcPDG",&B1_e1_mcPDG);
        tree->SetBranchAddress("B_pi_mcPDG",&B1_pi_mcPDG);
        tr->SetBranchAddress("B_mcPDG",&B1_mcPDG);
     /*Continuum suppression variable*/

    TH1F *h[20];
     
     h[1]=new TH1F("k0hso00","k0hso00",150,0,3);
     h[2]=new TH1F("k0hso01","k0hso01",150,0-1.5,1.5);
     h[3]=new TH1F("k0hso02","k0hso02",150,-1.5,1.5);
     h[4]=new TH1F("k0hso03","k0hso03",150,-1,1);
     h[5]=new TH1F("k0hso04","k0hso04",150,-1,1);
     h[6]=new TH1F("k0hso10","k0hso10",150,0,2.5);
     h[7]=new TH1F("k0hso12","k0hso12",150,-1,1);
     h[8]=new TH1F("k0hso14","k0hso14",150,-0.6,0.6);
     h[9]=new TH1F("k0hso20","k0hso20",150,0,2);
     h[10]=new TH1F("k0hso22","k0hso22",150,-0.6,0.9);
     h[11]=new TH1F("k0hso24","k0hso24",150,-0.6,0.9);
     h[12]=new TH1F("k0hoo0","k0hoo0",150,0,0.6);
     h[13]=new TH1F("k0hoo1","k0hoo1",150,-0.06,0.06);
     h[14]=new TH1F("k0hoo2","k0hoo2",150,-0.1,0.2);
     h[15]=new TH1F("k0hoo3","k0hoo3",150,-0.04,0.05);
     h[16]=new TH1F("k0hoo4","k0hoo4",150,-0.1,0.1);
     
     h[17]=new TH1F("|Cos(#theta_{B})|","|Cos(#theta_{B})|",150,0,1.1);
        h[17]->GetXaxis()->SetTitle("|Cos(#theta_{B})|");
     h[18]=new TH1F("|Cos(#theta_{T})|","|Cos(#theta_{T})|",150,0,1.1);
        h[18]->GetXaxis()->SetTitle("|Cos(#theta_{T})|");
     h[19]=new TH1F("R2","R2",150,0,1.1);
        h[19]->GetXaxis()->SetTitle("R2");
    
     for(int i=1;i<20;i++) h[i]->SetStats(0);
     float k0hso00,k0hso01,k0hso02,k0hso03,k0hso04,k0hso10,k0hso12,k0hso14,
           k0hso20,k0hso22,k0hso24,k0hoo0,k0hoo1,k0hoo2,k0hoo3,k0hoo4;  
     double cosb,cost,r2;
//     tree->SetBranchAddress("KSFWVariables_bohso00_bc",&k0hso00);
//     tree->SetBranchAddress("KSFWVariables_bohso01_bc",&k0hso01);
//     tree->SetBranchAddress("KSFWVariables_bohso02_bc",&k0hso02);
//     tree->SetBranchAddress("KSFWVariables_bohso03_bc",&k0hso03);
//     tree->SetBranchAddress("KSFWVariables_bohso04_bc",&k0hso04);
//     tree->SetBranchAddress("KSFWVariables_bohso10_bc",&k0hso10);
//     tree->SetBranchAddress("KSFWVariables_bohso12_bc",&k0hso12);
//     tree->SetBranchAddress("KSFWVariables_bohso14_bc",&k0hso14);
//     tree->SetBranchAddress("KSFWVariables_bohso20_bc",&k0hso20);
//     tree->SetBranchAddress("KSFWVariables_bohso22_bc",&k0hso22);
//     tree->SetBranchAddress("KSFWVariables_bohso24_bc",&k0hso24);
//     tree->SetBranchAddress("KSFWVariables_bohoo0_bc",&k0hoo0);
//     tree->SetBranchAddress("KSFWVariables_bohoo1_bc",&k0hoo1);
//     tree->SetBranchAddress("KSFWVariables_bohoo2_bc",&k0hoo2);
//     tree->SetBranchAddress("KSFWVariables_bohoo3_bc",&k0hoo3);
//     tree->SetBranchAddress("KSFWVariables_bohoo4_bc",&k0hoo4);
//     tree->SetBranchAddress("cosTBz",&cosb);
//     tree->SetBranchAddress("cosTBTO",&cost);
//     tree->SetBranchAddress("R2",&r2);
//


    double no_of_reconstructed_B_wobrem = tr->GetEntries();
    /*Histogram Filling*/
    cout<<"efficiency before brem recovery = "<<(no_of_reconstructed_B_wobrem)/(no_of_generated_event)<<endl;
    for(int i=0;i<tr->GetEntries();i++){
         tr->GetEntry(i);
         /*Truth matching*/
          bool istruth = false;
          if(mode == "piee")
               istruth = TMath::Abs(B_e0_mcPDG)==11 && TMath::Abs(B_pi_mcPDG)==211 
                       && TMath::Abs(B_pi_mcPDG)==211 && TMath::Abs(B_e1_mcPDG)==11 
                       && (B_e0_mcPDG+B_e1_mcPDG)==0 && TMath::Abs(B_mcPDG) == 521;
         bool pass = (istruth && do_mcmatch) || (!do_mcmatch) ;
         if(!pass )  continue;
          
          /*Filling*/
          if( de_wobrem > -0.2 && de_wobrem <  0.1)
              mbc_wobrem->Fill(mbC_wobrem);
          if(mbC_wobrem > 5.26)
              delE_wobrem->Fill(de_wobrem);
          }
     double no_of_reconstructed_B_withbrem = tree->GetEntries(); 
     cout<<"efficiency after brem recovery = "<<(no_of_reconstructed_B_withbrem)/(no_of_generated_event)<<endl;
  
    for(int i=0;i<nentries;i++){
         tree->GetEntry(i);
         //cout<<"candidate:ncandidates" << candidate<<" "<<ncandidates<<endl;
           
         /*Truth matching*/
         bool istruth = false;
         if(mode == "piee")  
               istruth = TMath::Abs(B1_e0_mcPDG)==11 && TMath::Abs(B1_pi_mcPDG)==211 
                        && TMath::Abs(B1_pi_mcPDG)==211 && TMath::Abs(B1_e1_mcPDG)==11 
                        && (B1_e0_mcPDG+B1_e1_mcPDG)==0  && TMath::Abs(B_mcPDG) == 521;

         bool pass = (istruth && do_mcmatch) || (!do_mcmatch) ;
         if(!pass )  continue;
       
         /*Filling*/ 
         if( de > -0.2 && de <  0.1)
            mbc->Fill(mbC);
         if(mbC > 5.26)
            delE->Fill(de);
         
//          h[1]->Fill(k0hso00);
//          h[2]->Fill(k0hso01);
//          h[3]->Fill(k0hso02);
//          h[4]->Fill(k0hso03); 
//          h[5]->Fill(k0hso04);
//          h[6]->Fill(k0hso10);
//          h[7]->Fill(k0hso12);
//          h[8]->Fill(k0hso14);
//          h[9]->Fill(k0hso20);
//          h[10]->Fill(k0hso22);
//          h[11]->Fill(k0hso24);
//          h[12]->Fill(k0hoo0);
//          h[13]->Fill(k0hoo1);
//          h[14]->Fill(k0hoo2);
//          h[15]->Fill(k0hoo3);
//          h[16]->Fill(k0hoo4);
//          h[17]->Fill(cosb);
//          h[18]->Fill(cost);
//          h[19]->Fill(r2);
//         
      }
        
         double scale= 1/(mbc->Integral());       
         mbc->Scale(scale);
         scale = 1/(mbc_wobrem->Integral());
         mbc_wobrem->Scale(scale);
         scale = 1/(delE->Integral());
         delE->Scale(scale);
         scale = 1/(delE_wobrem->Integral());
         delE_wobrem->Scale(scale);
         
   
        A->Draw();
        delE->Draw();


       /*Saving plots*/
    
//       TCanvas *De = new TCanvas("De","De",1000,1000);
//        De->cd();
//        delE->Draw();
//        De->Update();
//        TPaveStats *q =(TPaveStats*)delE->GetListOfFunctions()->FindObject("stats");
//        q->SetX1NDC(0.1);
//        q->SetX2NDC(0.3);
//        q->SetY1NDC(0.6);
//        q->SetY2NDC(0.7);
//        
//        delE_wobrem->Draw("sames");
//        De->Update();
//        TPaveStats *q =(TPaveStats*)delE_wobrem->GetListOfFunctions()->FindObject("stats");
//        q->SetX1NDC(0.7);
//        q->SetX2NDC(0.9);
//        q->SetY1NDC(0.6);
//        q->SetY2NDC(0.7);
//        
//        De->Draw();
//        De->BuildLegend();
//        
//        TString de_canvas = "../../../plots/EWP/DeltaE_";
//        de_canvas += mode;
//        if(do_mcmatch) de_canvas += "_T_matched_";
//        de_canvas += ".eps";
//       // De->SaveAs(de_canvas); 
     
//        TCanvas *Mbc = new TCanvas("Mbc","Mbc",1000,1000);
//        Mbc->cd();
//         mbc->Draw();
//        Mbc->Update();
//        TPaveStats *q =(TPaveStats*) mbc->GetListOfFunctions()->FindObject("stats");
//        q->SetX1NDC(0.1);
//        q->SetX2NDC(0.3);
//        q->SetY1NDC(0.6);
//        q->SetY2NDC(0.7);
//        
//        mbc_wobrem->Draw("sames");
//        Mbc->Update();
//        TPaveStats *r =(TPaveStats*) mbc_wobrem->GetListOfFunctions()->FindObject("stats");
//        r->SetX1NDC(0.7);
//        r->SetX2NDC(0.9);
//        r->SetY1NDC(0.6);
//        r->SetY2NDC(0.7);
//        
//       
//        
//        Mbc->Draw();
//        Mbc->BuildLegend();
//        
//        TString mbc_canvas = "../plots/EWP/Mbc_";
//        mbc_canvas += mode;
//        if(do_mcmatch) mbc_canvas += "_T_matched_";
//        mbc_canvas += ".eps";
       // Mbc->SaveAs(mbc_canvas);          
//      
//        
//        TString cont_supp2 = "../plots/EWP/continuumSuppression2_";
//        cont_supp2 += mode;
//        if(do_mcmatch) cont_supp2 += "_T_matched_";
//        cont_supp2 += ".eps";
//        
//        TCanvas *c1=new TCanvas("c5","c5",2000,2000);
//        c1->Divide(4,4);
//        for(int i=1; i<17;i++){
//           c1->cd(i);
//           h[i]->Draw();
//         }
//       // c1->SaveAs(cont_supp2);
//        
//        TString cont_supp1 = "../plots/EWP/continuumSuppression1_";
//         cont_supp1 += mode;
//        if(do_mcmatch) cont_supp1 += "_T_matched_";
//        cont_supp1 += ".eps";
//        
//        TCanvas *c2=new TCanvas("c2","c2",2000,2000);
//        c2->Divide(2,2);
//        c2->cd(1);
//        h[17]->Draw();
//        c2->cd(2);
//        h[18]->Draw();
//        c2->cd(3);
//        h[19]->Draw();
//       // c2->SaveAs(cont_supp1);
    
    
}
