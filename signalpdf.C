void signalpdf(TString mode="piee") {
    bool do_mcmatch =  false; //true means do truth matching and false means don't do
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

    /*Histogram Definition and assigning with tree*/
    
    Int_t ncandidates , candidate, event;
    tree->SetBranchAddress("__candidate__",&candidate);
    tree->SetBranchAddress("__ncandidates__",&ncandidates); 
    tree->SetBranchAddress("__event__",&event);
    TH1F *multiplicity = new TH1F("Multiplicity","",8,0,8);
       multiplicity->GetXaxis()->SetTitle("# of B candidate");
       multiplicity->SetLineColor(kRed);
       multiplicity->SetLineWidth(0.5);
       multiplicity->SetFillColor(kRed);
       multiplicity->SetFillStyle(3005);

        TGaxis *myX = (TGaxis*)multiplicity->GetXaxis();
        myX->SetMaxDigits(4);

        multiplicity->GetXaxis()->SetTitleOffset(1.0);
        multiplicity->GetXaxis()->SetTitleSize(0.04);
        multiplicity->GetYaxis()->SetTitleOffset(1.3);
        multiplicity->GetYaxis()->SetTitleSize(0.04);
        //mbc->SetStats(0);


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
           

     TH1F *delE_wobrem=new TH1F("wo brem recovery","",300,-0.3,0.3);
        delE_wobrem->GetXaxis()->SetTitle("#DeltaE (GeV)");
        //delE_wobrem->GetYaxis()->SetTitle("Entries/ 0.002 GeV");
          
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

      /*Multiplicity*/        
          
     /*truth matching*/  
        /* wo bremrecovery*/
        Double_t B_pi_mcPDG, B_e0_mcPDG, B_e1_mcPDG,B_mcPDG,B_pi_genMotherPDG, B_e0_genMotherPDG, B_e1_genMotherPDG;
        tr->SetBranchAddress("B_e0_mcPDG",&B_e0_mcPDG);
        tr->SetBranchAddress("B_e1_mcPDG",&B_e1_mcPDG);
        tr->SetBranchAddress("B_pi_mcPDG",&B_pi_mcPDG);
        tr->SetBranchAddress("B_mcPDG",&B_mcPDG);
        tr->SetBranchAddress("B_pi_genMotherPDG",&B_pi_genMotherPDG);
        tr->SetBranchAddress("B_e0_genMotherPDG",&B_e0_genMotherPDG);        
        tr->SetBranchAddress("B_e1_genMotherPDG",&B_e1_genMotherPDG);
 
        /* with bremrecovery*/
        Double_t B1_pi_mcPDG, B1_e0_mcPDG, B1_e1_mcPDG,B1_mcPDG;
        tree->SetBranchAddress("B_e0_mcPDG",&B1_e0_mcPDG);
        tree->SetBranchAddress("B_e1_mcPDG",&B1_e1_mcPDG);
        tree->SetBranchAddress("B_pi_mcPDG",&B1_pi_mcPDG);
        tree->SetBranchAddress("B_mcPDG",&B1_mcPDG);
 
        
     /*Continuum suppression variable*/



    double no_of_reconstructed_B_wobrem = 0;
    /*Histogram Filling*/
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
          if(mbC_wobrem > 5.26){
              delE_wobrem->Fill(de_wobrem);
               no_of_reconstructed_B_wobrem ++;
               }
          }
    cout<<"efficiency before brem recovery = "<<(no_of_reconstructed_B_wobrem)/(no_of_generated_event)<<endl; 
     double no_of_reconstructed_B_withbrem = 0; 
 
     
    int event1 = 0;
    for(int i=0;i<tree->GetEntries();i++){
         tree->GetEntry(i);
        
           
         //cout<<"candidate:ncandidates" <<event<<"  "<< candidate<<" "<<ncandidates<<endl;
         //cout<<B1_e0_mcPDG<<" "<<B1_e1_mcPDG<<"  "<<B1_pi_mcPDG<<" "<<B1_mcPDG<<endl;
         int skip = (event - event1);
         if(event != event1) multiplicity->Fill(ncandidates);
         if(event != event1) multiplicity->Fill(0,skip);
         event1 = event;
         /*Truth matching*/
         bool istruth = false;
         if(mode == "piee")  
               istruth = TMath::Abs(B1_e0_mcPDG)==11 && TMath::Abs(B1_pi_mcPDG)==211 
                        && TMath::Abs(B1_pi_mcPDG)==211 && TMath::Abs(B1_e1_mcPDG)==11 
                        && (B1_e0_mcPDG+B1_e1_mcPDG)==0  && TMath::Abs(B1_mcPDG) == 521;

         bool pass = (istruth && do_mcmatch) || (!do_mcmatch) ;
         if(!pass )  continue;
      
          
         /*Filling*/ 
         if( de > -0.2 && de <  0.1)
            mbc->Fill(mbC);
         if(mbC > 5.26){
            delE->Fill(de);
            no_of_reconstructed_B_withbrem++;
            }
        
      }
        
         double scale= 1/(mbc->Integral());       
         mbc->Scale(scale);
         scale = 1/(mbc_wobrem->Integral());
         mbc_wobrem->Scale(scale);
         scale = 1/(delE->Integral());
         delE->Scale(scale);
         scale = 1/(delE_wobrem->Integral());
         delE_wobrem->Scale(scale);
         
   
       cout<<"efficiency after brem recovery = "<<(no_of_reconstructed_B_withbrem)/(no_of_generated_event)<<endl;

       /*Saving plots*/
       multiplicity->Draw(); 
      TCanvas *De = new TCanvas("De","De",1000,1000);
        De->cd();
        delE->Draw();
        De->Update();
        TPaveStats *q =(TPaveStats*)delE->GetListOfFunctions()->FindObject("stats");
        q->SetX1NDC(0.1);
        q->SetX2NDC(0.3);
        q->SetY1NDC(0.6);
        q->SetY2NDC(0.7);
        
        delE_wobrem->Draw("sames");
        De->Update();
        TPaveStats *q =(TPaveStats*)delE_wobrem->GetListOfFunctions()->FindObject("stats");
        q->SetX1NDC(0.7);
        q->SetX2NDC(0.9);
        q->SetY1NDC(0.6);
        q->SetY2NDC(0.7);
        
        De->Draw();
        De->BuildLegend();
        
        TString de_canvas = "../../../plots/EWP/DeltaE_";
        de_canvas += mode;
        if(do_mcmatch) de_canvas += "_T_matched_";
        de_canvas += ".eps";
       // De->SaveAs(de_canvas); 
   
        TCanvas *Mbc = new TCanvas("Mbc","Mbc",1000,1000);
        Mbc->cd();
         mbc->Draw();
        Mbc->Update();
        TPaveStats *q =(TPaveStats*) mbc->GetListOfFunctions()->FindObject("stats");
        q->SetX1NDC(0.1);
        q->SetX2NDC(0.3);
        q->SetY1NDC(0.6);
        q->SetY2NDC(0.7);
        
        mbc_wobrem->Draw("sames");
        Mbc->Update();
        TPaveStats *r =(TPaveStats*) mbc_wobrem->GetListOfFunctions()->FindObject("stats");
        r->SetX1NDC(0.7);
        r->SetX2NDC(0.9);
        r->SetY1NDC(0.6);
        r->SetY2NDC(0.7);
        
       
        
        Mbc->Draw();
        Mbc->BuildLegend();
        
        TString mbc_canvas = "../plots/EWP/Mbc_";
        mbc_canvas += mode;
        if(do_mcmatch) mbc_canvas += "_T_matched_";
        mbc_canvas += ".eps";
   
}
