#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>



template <typename T>
void data_t(float dt, int N, std::vector<T> &x, std::vector<T> &v, std::vector<T> &t, double gamma, double w0, double w, double F){

    T x_n = 0;
    T v_n = 0;
    T t_n = 0;

    x[0] = x_n;
    v[0] = v_n;
    t[0] = t_n;

    for (int i = 1; i < N; i++){

        x_n = x[i-1] + v[i-1] * dt;
        v_n = v[i-1] + (F * std::cos(w * t[i-1]) - (2 * gamma * v[i-1] + w0 * w0 * std::sin(x[i-1]))) * dt;
        t_n = t[i-1] + dt;

        x[i] = x_n;
        v[i] = v_n;
        t[i] = t_n;
    }

}


template <typename T>
void predict_correct_data_t(float dt, int N, std::vector<T> &x, std::vector<T> &v, std::vector<T> &t, double gamma, double w0, double w, double F){

    T x_n = 0;
    T v_n = 0;
    T t_n = 0;

    x[0] = x_n;
    v[0] = v_n;
    t[0] = t_n;

    for (int i = 1; i < N; i++){
        T x_pred = x[i-1] + v[i-1] * dt;
        T v_pred = v[i-1] + (F * std::cos(w * t[i-1]) - (2 * gamma * v[i-1] + w0 * w0 * std::sin(x[i-1]))) * dt;

        x_n = x[i-1] + dt * (v[i-1] + v_pred) / 2;
        v_n = v[i-1] + dt * (F * std::cos(w * t[i-1]) + F * std::cos(w * (t[i-1] + dt)) - (2 * gamma * v[i-1] + w0 * w0 * std::sin(x[i-1]) + 2 * gamma * v_pred + w0 * w0 * std::sin(x_pred))) / 2;
        t_n = t[i-1] + dt;

        x[i] = x_n;
        v[i] = v_n;
        t[i] = t_n;
    }

}


int main(int atgc, char *argv[]){

    std::string path1 = argv[1];

    long double dt = atof(argv[2]);
    double gamma = atof(argv[3]);
    double w0 = atof(argv[4]);
    double w = 0;
    double w_max = 2;
    int max_points = 1000;

    int T = 10000;
    int N = int(T/dt);

    std::vector<double> x = std::vector<double>(N);
	std::vector<double> v = std::vector<double>(N);
	std::vector<double> t = std::vector<double>(N);


	double F = 10;

	std::ofstream out1(path1);

        if (out1.is_open())
        {
            for (int i = 0; i < max_points; i++){
                data_t<double> (dt, N, t, x, v, gamma, w0, w, F);
                double A = *std::max_element(std::begin(x) + int(N * 0.95), std::end(x));

                out1 << A << " " << w << "\n";

                w = w + w_max/max_points;
            }
        }


}


