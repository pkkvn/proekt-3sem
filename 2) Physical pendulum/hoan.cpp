#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;


void hoan(double phi, double ksi, double w, std::ostream& fout){
    double /*phi, ksi,*/ phin, ksin, phic, ksic, dt, /*w,*/ E_0;// phic, ksic фи, кси с чертой
    //cin >> phi >> ksi;

    ksin = ksi;
    phin = phi;
    dt = 1.e-4;
    //w = 1;
    //ofstream out_file;
    //out_file.open("data11.txt");
    E_0 = ksi*ksi/2 + w*w*(1-cos(phi));

    for (int t = 0; t < 80000; t++){
        phic = phi + ksi*dt;
        ksic = ksi - w*w*sin(phi)*dt;

        phin = phi + dt/2*(ksic + ksi);
        ksin = ksi - w*w/2*dt*(sin(phi) + sin(phic));

        phi = phin;
        ksi = ksin;

        if (t%10 ==0)
            fout << t << " " << phin << " " << ksin << " " << ksin*ksin/2 + w*w*(1-cos(phin))*(1-cos(phin))/2 << " " << ((ksin*ksin/2 + w*w*(1-cos(phin)))/E_0)-1 <<  endl;
    }
    //out_file.close();
    cout << "Completed" << endl;

}

int main(){
    /*double x, y, xn, yn, xc, yc, dt, w, E_0;
    cin >> xc >> yc;
    xn = xc;
    yn = yc;
    dt = 0.00001;
    w = 1;
    ofstream out_file;
    out_file.open("data_2.txt");
    E_0 = xc*xc/2 + w*w*yc*yc/2;
    for (int t = 0; t < 8000000; t++){
        xn = xc-w*w*yc*dt;
        yn = yc + xc*dt;
        xc = xn;
        yc = yn;
        if (t%10 ==0)
            out_file << t << " " << xn << " " << yn << " " << xn*xn/2 + w*w*yn*yn/2 << " " << ((xn*xn/2 + w*w*yn*yn/2)/E_0)-1 <<  endl;
    }*/

    /*double phi, ksi, phin, ksin, phic, ksic, dt, w, E_0;// phic, ksic фи, кси с чертой
    cin >> phi >> ksi;

    ksin = ksi;
    phin = phi;
    dt = 1.e-4;
    w = 1;
    ofstream out_file;
    out_file.open("data11.txt");
    E_0 = ksi*ksi/2 + w*w*(1-cos(phi));

    for (int t = 0; t < 8000000; t++){
        phic = phi + ksi*dt;
        ksic = ksi - w*w*sin(phi)*dt;

        phin = phi + dt/2*(ksic + ksi);
        ksin = ksi - w*w/2*dt*(sin(phi) + sin(phic));

        phi = phin;
        ksi = ksin;

        if (t%10 ==0)
            out_file << t << " " << phin << " " << ksin << " " << ksin*ksin/2 + w*w*(1-cos(phin))*(1-cos(phin))/2 << " " << ((ksin*ksin/2 + w*w*(1-cos(phin)))/E_0)-1 <<  endl;
    }
    out_file.close();
    cout << "Completed";*/

    ofstream out_file;
    out_file.open("data_hoan11.txt");
    hoan(1, 1, 1, out_file);
    out_file.close();

    out_file.open("data_hoan20.txt");
    hoan(0, 2, 0.1, out_file);
    out_file.close();

}
