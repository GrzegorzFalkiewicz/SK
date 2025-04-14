#pragma once
#include <math.h>
const double PI = 3.14;

class sk_jed {
	double A;
	int t;
public:
	void set_A(double Am) { A = Am; }
	void set_t(int im) { t = im; }
	double operator()(int im) { if (im >= t) return A; else return 0; }
};

class syg_prost {
    double A;
    int T;
    double p;
    double S;
public:
    void set_A(double Am) { A = Am; }
    void set_T(int Tm) { if (Tm > 0) T = Tm; }
    void set_p(double pm) { p = fabs(pm); }
    void set_S(double Sm) {S=Sm;}
    double operator()(int im) { if ((im % T) < p * T) return A+S; else return S; }
};

class syg_sin {
    double A;
    int T;
    double S;
public:
    void set_S(double Sm) {S=Sm;}
    void set_A(double Am) { A = Am; }
    void set_T(int Tm) { if (Tm > 0) T = Tm; }
    double operator()(int im) { double sina = (double)(im % T) / T * 2 * PI; return A * sin(sina)+S; }
};
