// what problem?
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
        auto h3 = new TH1D("h3", "ratio1", 50, 0, 100);
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
        yaxis1 -> SetLabelSize(0.05);
        h1 -> SetTitle("");
        h1 -> Draw();
        // below histogram setting **************************/
        p2 -> cd();
        auto xaxis3 = (TAxis*) h3 -> GetXaxis();
        auto yaxis3 = (TAxis*) h3 -> GetYaxis();
        xaxis3 -> SetLabelSize(0.08);
        yaxis3 -> SetTitle("ratio");
        yaxis3 -> SetTitleSize(0.08);
        yaxis3 -> CenterTitle();
        yaxis3 -> SetRangeUser(0, 1.5);
        yaxis3 -> SetLabelSize(0.08);
        h3 -> SetTitle("");
        h3 -> Draw();
        /****************************************************/
        gStyle -> SetOptStat(0);
    }
}