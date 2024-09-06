<<<<<<< HEAD
void candledecay()
{
    auto c1 = new TCanvas("c1", "Candle Decay", 800, 600);
    auto p1 = new TPad("p1", "Pad", 0, 0, 1, 1);
    p1 -> Draw();
    p1 -> Divide(2,1);
    p1->cd(1);             // 첫 번째 하위 패드로 이동
    gPad->SetFillColor(3); // 흰색 (0번 색상)
    gPad->Modified();      // 패드 수정 사항 적용
    gPad->Update(); 
    p1 -> cd(2);
    gPad->SetFillColor(5); // 흰색 (0번 색상)
    gPad->Modified();      // 패드 수정 사항 적용
    gPad->Update(); 
    
    auto rng = new TRandom();
    auto h1 = new TH2I("h1", "Decay", 1000, 0, 1000, 20, 0, 20);

    float myRand;
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 1000000; j++)
        {
            myRand = rng -> Gaus(350+i*8, 20+2*i);
            h1 -> Fill(myRand, i);
        }
    }

    h1 -> SetBarWidth(3);
    h1 -> SetFillStyle(0);
    h1 -> SetFillColor(kGray);
    h1 -> SetLineColor(kBlue);
    h1 -> GetYaxis() -> SetTitle("time");
    h1 -> GetXaxis() -> SetTitle("probability density");

    p1 -> cd(1);
    h1 -> Draw("violiny(112000000)");

    p1-> cd(2);
    auto h2 = (TH2I*) h1 -> Clone("h2");
    h2 -> SetBarWidth(0.9);
    h2 -> DrawCopy("candley2");
}
=======
hello
bye
hello
>>>>>>> 7da739dc4d42c021b4e0cadfc82b699002c0c8d2
