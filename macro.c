// what problem?
// hello
Bool_t ratiodiv = true;
void macro()
{
    if (ratiodiv)
    {
        auto c1 = new TCanvas("c1", "macro_ex", 400, 600);
        
        auto p1 = new TPad("p1", "up Pad", 0, 0.35, 1, 1);
        auto p2 = new TPad("p2", "down Pad", 0, 0, 1, 0.35);
        auto h1 = new TH1D("h1", "Gaus1", 50, 0, 100);
        auto h2 = new TH1D("h2", "Gaus2", 50, 0, 100);
        auto rng = new TRandom3();
        // pad setting **************************************/
        p1 -> SetMargin(0.18, 0.1, 0, 0.1);
        p2 -> SetMargin(0.18, 0.1, 0.1, 0);
        /****************************************************/
        p1 -> Draw();
        p2 -> Draw();
        // Fill histogram ***********************************/
        for (auto i = 0; i < 100000; i++)
        {
            double ranvalueU = rng -> Gaus(50, 16);
            double ranvalueD = rng -> Gaus(50, 20);
            h1 -> Fill(ranvalueU);
            if (i%2 == 0)
            {
                h2 -> Fill(ranvalueD);
            }
        }
        // above histogram setting **************************/
        p1 -> cd();
        // h1 -> SetStats(0);
        auto xaxis1 = (TAxis*) h1 -> GetXaxis();
        auto yaxis1 = (TAxis*) h1 -> GetYaxis();
        yaxis1 -> SetTitle("Gaus");
        gPad -> SetLogy();
        yaxis1 -> SetTitleSize(0.06);
        yaxis1 -> CenterTitle();
        yaxis1 -> SetLabelSize(0.05);
        h1 -> SetTitle("");
        h1 -> SetMarkerStyle(20);
        h1 -> SetMarkerSize(0.7);
        h1 -> SetMarkerColor(2);
        h2 -> SetMarkerStyle(26);
        h2 -> SetMarkerSize(0.7);
        h2 -> SetMarkerColor(4);
        h1 -> Draw("P");
        h2 -> Draw("same P");
        // below histogram setting **************************/
        TLegend *leg = new TLegend(0.663317,0.662876,0.864322,0.863545,NULL,"brNDC");
        leg->SetBorderSize(1);
        leg->SetLineColor(1);
        leg->SetLineStyle(1);
        leg->SetLineWidth(1);
        leg->SetFillColor(0);
        leg->SetFillStyle(1001);
        TLegendEntry *entry=leg->AddEntry("","data set1","p");
        Int_t ci;      // for color index setting
        TColor *color; // for color definition with alpha
        ci = TColor::GetColor("#FF0000");
        // entry->SetLineColor(ci);
        // entry->SetLineStyle(2);
        // entry->SetLineWidth(1);
        entry->SetMarkerColor(ci);
        entry->SetMarkerStyle(20);
        entry->SetMarkerSize(1);
        entry->SetTextFont(42);
        entry=leg->AddEntry("","data set2","p");
        ci = TColor::GetColor("#0000FF");
        // entry->SetLineColor(ci);
        // entry->SetLineStyle(4);
        // entry->SetLineWidth(1);
        entry->SetMarkerColor(ci);
        entry->SetMarkerStyle(26);
        entry->SetMarkerSize(1);
        entry->SetTextFont(42);
        leg->Draw();
        // below histogram setting **************************/
        p2 -> cd();
        gPad -> SetGrid(0, 1);
        auto h3 = (TH1D*) h1 -> Clone("h3");
        h3 -> Divide(h2);
        auto xaxis3 = (TAxis*) h3 -> GetXaxis();
        auto yaxis3 = (TAxis*) h3 -> GetYaxis();
        xaxis3 -> SetLabelSize(0.08);
        yaxis3 -> SetTitle("ratio");
        yaxis3 -> SetTitleSize(0.09);
        yaxis3 -> CenterTitle();
        yaxis3 -> SetRangeUser(0, 4);
        yaxis3 -> SetLabelSize(0.08);
        h3 -> SetTitle("");
        h3 -> Draw("L");
        /****************************************************/
        gStyle -> SetOptStat(0);
    }
}