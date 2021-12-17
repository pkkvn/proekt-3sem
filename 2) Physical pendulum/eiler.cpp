#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

    //метод Хойна
    /*double phi, ksi, phin, ksin, phic, ksic, dt, w, E_0;// phic, ksic фи, кси с чертой
    cin >> phi >> ksi;

    ksin = ksi;
    phin = phi;
    dt = 1.e-4;
    w = 1;
    ofstream out_file;
    out_file.open("data.txt");
    E_0 = ksi*ksi/2 + w*w*(1-cos(phi))*(1-cos(phi))/2;

    for (int t = 0; t < 8000000; t++){
        phic = phi + ksi*dt;
        ksic = ksi - w*w*sin(phi)*dt;

        phin = phi + dt/2*(ksic + ksi);
        ksin = ksi - w*w/2*dt*(sin(phi) + sin(phic));

        phi = phin;
        ksi = ksin;

        if (t%10 ==0)
            out_file << t << " " << phin << " " << ksin << " " << ksin*ksin/2 + w*w*(1-cos(phin))*(1-cos(phin))/2 << " " << ((ksin*ksin/2 + w*w*(1-cos(phin))*(1-cos(phin))/2)/E_0)-1 <<  endl;
    }*/

    void eiler(double ksic, double phic, double w, std::ostream& fout){
        double phi, ksi, phin, ksin,/*phic, ksic,*/ dt, /*w,*/ E_0;
        //cin >> ksic >> phic;
        ksin = ksic;
        phin = phic;
        dt = 0.00001;
        //w = 1;
        //out_file.open("data_2.txt");
        E_0 = ksic*ksic/2 + w*w*(1-cos(phic));
        for (int t = 0; t < 8000000; t++){
            ksin = ksic - w*w*phic*dt;
            phin = phic + ksic*dt;
            ksic = ksin;
            phic = phin;
            if (t%10 ==0)
                fout << t << " " << ksin << " " << phin << " " << ksin*ksin/2 + w*w*phin*phin/2 << " " << (ksin*ksin/2 + w*w*(1-cos(phin))/E_0)- 1 << endl;
        }
        //out_file.close();
        cout << "Completed" << endl;
    }

    // Eiler method
    int main(){
    /*void func(double ksic, double phic){
        double phi, ksi, phin, ksin, phic, ksic, dt, w, E_0;
        //cin >> ksic >> phic;
        ksin = ksic;
        phin = phic;
        dt = 0.00001;
        w = 1;
        ofstream out_file;
        out_file.open("data_2.txt");
        E_0 = ksic*ksic/2 + w*w*(1-cos(phic));
        for (int t = 0; t < 8000000; t++){
            ksin = ksic - w*w*phic*dt;
            phin = phic + ksic*dt;
            ksic = ksin;
            phic = phin;
            if (t%10 ==0)
                out_file << t << " " << ksin << " " << phin << " " << ksin*ksin/2 + w*w*phin*phin/2 << " " << (ksin*ksin/2 + w*w*(1-cos(phin))/E_0)- 1 << endl;
        }
        out_file.close();
        cout << "Completed";
    }*/
    ofstream out_file;
    out_file.open("data_eiler11.txt");
    eiler(1, 1, 1, out_file);
    out_file.close();

    out_file.open("data_eiler20.txt");
    eiler(0, 2, 0.1, out_file);
    out_file.close();

}
