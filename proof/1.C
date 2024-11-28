void plot(){
TFile *f = new TFile("wprime_mc.root");
TH1F *newh = new TH1F("HMetPt_SR1_A_NoSF","HMetPt_SR1_A",12,0.0,600.0);
newh = (TH1F*)f->Get("2018/HMetPt_SR1_A_NoSF");
TCanvas *c = new TCanvas();
newh->SetFillColor(2);
newh->GetXaxis()->SetRangeUser(0.0,600.0);
newh->GetXaxis()->SetTitle("eje X");
newh->GetYaxis()->SetTitle("Events"); 
newh->Draw("ALP");
c->SaveAs("A.pdf");
}