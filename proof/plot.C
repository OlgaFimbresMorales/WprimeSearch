void plot(){
TFile *f = new TFile("wprime_mc.root");
TH1F *newh = new TH1F("A","",12,0.0,600.0);

//TH1F *originalHistogram = (TH1F*)f->Get("2018/HMetPt_SR1_A_NoSF");  // your original histogram
//TH1F *newh2 = (TH1F*)originalHistogram->Clone("newh2");

newh = (TH1F*)f->Get("2018/HMetPt_SR1_A_NoSF");
TCanvas *c = new TCanvas();
newh->SetFillColor(40);
newh->GetXaxis()->SetRangeUser(0.0,600.0);
newh->GetXaxis()->SetTitle("MET p_{T} [GeV]");
newh->GetXaxis()->SetLabelSize(0.045);
newh->GetXaxis()->SetTitleSize(0.045);
newh->GetYaxis()->SetLabelSize(0.045);
newh->GetYaxis()->SetTitleSize(0.045);
newh->GetYaxis()->SetTitle("Events"); 
newh->Draw("HIST");
c->Update();
c->SaveAs("METPt_SR1_A.pdf");


TH1F *newh2 = new TH1F("B","",12,0.0,600.0);
newh2 = (TH1F*)f->Get("2018/HZPt_SR1_A_NoSF");
TCanvas *c2 = new TCanvas();
newh2->SetFillColor(40);
newh2->GetXaxis()->SetRangeUser(100.0,600.0);
newh2->GetXaxis()->SetTitle("Z p_{T} [GeV]");
newh2->GetXaxis()->SetLabelSize(0.045);
newh2->GetXaxis()->SetTitleSize(0.045);
newh2->GetYaxis()->SetLabelSize(0.045);
newh2->GetYaxis()->SetTitleSize(0.045);
newh2->GetYaxis()->SetTitle("Events"); 
newh2->Draw("HIST");
c2->SaveAs("ZPt_SR1_A.pdf");

TH1F *newh3 = new TH1F("C","",12,0.0,600.0);
newh3 = (TH1F*)f->Get("2018/HWPt_SR1_A_NoSF");
TCanvas *c3 = new TCanvas();
newh3->SetFillColor(40);
newh3->GetXaxis()->SetLabelSize(0.045);
newh3->GetXaxis()->SetTitleSize(0.045);
newh3->GetYaxis()->SetLabelSize(0.045);
newh3->GetYaxis()->SetTitleSize(0.045);
newh3->GetXaxis()->SetRangeUser(100.0,800.0);
newh3->GetXaxis()->SetTitle("W p_{T} [GeV]");
newh3->GetYaxis()->SetTitle("Events"); 
newh3->Draw("HIST");
c3->SaveAs("WPt_SR1_A.pdf");

TH1F *newh4 = new TH1F("D","",12,0.0,600.0);
newh4 = (TH1F*)f->Get("2018/HWZPt_SR1_A_NoSF");
TCanvas *c4 = new TCanvas();
newh4->SetFillColor(40);
newh4->GetXaxis()->SetLabelSize(0.045);
newh4->GetXaxis()->SetTitleSize(0.045);
newh4->GetYaxis()->SetLabelSize(0.045);
newh4->GetYaxis()->SetTitleSize(0.045);
newh4->GetXaxis()->SetRangeUser(0.0,700.0);
newh4->GetXaxis()->SetTitle("WZ p_{T} [GeV]");
newh4->GetYaxis()->SetTitle("Events"); 
newh4->Draw("HIST");
c4->SaveAs("WZPt_SR1_A.pdf");

TH1F *newh10 = new TH1F("E","",12,0.0,600.0);
newh10 = (TH1F*)f->Get("2018/HMassW_SR1_A_NoSF");
TCanvas *c10 = new TCanvas();
newh10->SetFillColor(40);
newh10->GetXaxis()->SetLabelSize(0.045);
newh10->GetXaxis()->SetTitleSize(0.045);
newh10->GetYaxis()->SetLabelSize(0.045);
newh10->GetYaxis()->SetTitleSize(0.045);
newh10->GetXaxis()->SetRangeUser(50.0,200.0);
newh10->GetXaxis()->SetTitle("W Mass [GeV]");
newh10->GetYaxis()->SetTitle("Events"); 
newh10->Draw("HIST");
c10->SaveAs("MassW_SR1_A.pdf");

TH1F *newh5 = new TH1F("F","",12,0.0,600.0);
newh5 = (TH1F*)f->Get("2018/HMassZ_SR1_A_NoSF");
TCanvas *c5 = new TCanvas();
newh5->SetFillColor(40);
newh5->GetXaxis()->SetLabelSize(0.045);
newh5->GetXaxis()->SetTitleSize(0.045);
newh5->GetYaxis()->SetLabelSize(0.045);
newh5->GetYaxis()->SetTitleSize(0.045);
newh5->GetXaxis()->SetRangeUser(60.0,120.0);
newh5->GetXaxis()->SetTitle("Z Mass [GeV]");
newh5->GetYaxis()->SetTitle("Events"); 
newh5->Draw("HIST");
c5->SaveAs("MassZ_SR1_A.pdf");

TH1F *newh6 = new TH1F("G","",12,0.0,600.0);
newh6 = (TH1F*)f->Get("2018/HMassWZ_SR1_A_NoSF");
TCanvas *c6 = new TCanvas();
newh6->SetFillColor(40);
newh6->GetXaxis()->SetLabelSize(0.045);
newh6->GetXaxis()->SetTitleSize(0.045);
newh6->GetYaxis()->SetLabelSize(0.045);
newh6->GetYaxis()->SetTitleSize(0.045);
newh6->GetXaxis()->SetRangeUser(150.0,1500.0);
newh6->GetXaxis()->SetTitle("WZ Mass [GeV]");
newh6->GetYaxis()->SetTitle("Events"); 
newh6->Draw("HIST");
c6->SaveAs("MassWZ_SR1_A.pdf");

TH1F *newh7 = new TH1F("H","",12,0.0,600.0);
newh7 = (TH1F*)f->Get("2018/HPtl1_SR1_A_NoSF");
TCanvas *c7 = new TCanvas();
newh7->SetFillColor(40);
newh7->GetXaxis()->SetLabelSize(0.045);
newh7->GetXaxis()->SetTitleSize(0.045);
newh7->GetYaxis()->SetLabelSize(0.045);
newh7->GetYaxis()->SetTitleSize(0.045);
newh7->GetXaxis()->SetRangeUser(0.0,500.0);
newh7->GetXaxis()->SetTitle("l1 p_{T} [GeV]");
newh7->GetYaxis()->SetTitle("Events"); 
newh7->Draw("HIST");
c7->SaveAs("Ptl1_SR1_A.pdf");

TH1F *newh8 = new TH1F("I","",12,0.0,600.0);
newh8 = (TH1F*)f->Get("2018/HPtl2_SR1_A_NoSF");
TCanvas *c8 = new TCanvas();
newh8->SetFillColor(40);
newh8->GetXaxis()->SetLabelSize(0.045);
newh8->GetXaxis()->SetTitleSize(0.045);
newh8->GetYaxis()->SetLabelSize(0.045);
newh8->GetYaxis()->SetTitleSize(0.045);
newh8->GetXaxis()->SetRangeUser(0.0,300.0);
newh8->GetXaxis()->SetTitle("l2 p_{T} [GeV]");
newh8->GetYaxis()->SetTitle("Events"); 
newh8->Draw("HIST");
c8->SaveAs("Ptl2_SR1_A.pdf");

TH1F *newh9 = new TH1F("J","",12,0.0,600.0);
newh9 = (TH1F*)f->Get("2018/HPtl3_SR1_A_NoSF");
TCanvas *c9 = new TCanvas();
newh9->SetFillColor(40);
newh9->GetXaxis()->SetLabelSize(0.045);
newh9->GetXaxis()->SetTitleSize(0.045);
newh9->GetYaxis()->SetLabelSize(0.045);
newh9->GetYaxis()->SetTitleSize(0.045);
newh9->GetXaxis()->SetRangeUser(0.0,600.0);
newh9->GetXaxis()->SetTitle("l3 p_{T} [GeV]");
newh9->GetYaxis()->SetTitle("Events"); 
newh9->Draw("HIST");
c9->SaveAs("Ptl3_SR1_A.pdf");


}