#pragma once

#include "WartoscZadana.h"
#include "RegulatorPID.h"
#include "ModelARX.h"
#include <cassert>


enum class signal {
    sk_jed=0,
    syg_prost=1,
    syg_sin=2,
};

class Symulator
{
protected:
    int ite;
    double zad;
    sk_jed gen1;
    syg_prost gen2;
    syg_sin gen3;
    double u;
    double y_pid ;
    bool sterowanie = false;
    RegulatorPID pid;
    ModelARX arx;
    signal syg=signal::sk_jed;
public:
    void reset();
    void StartStop();
    void set_arx_a(std::vector<double> arx_a);
    void set_arx_b(std::vector<double> arx_b);
    void set_a1(double a);
    void set_a2(double a);
    void set_a3(double a);
    void set_b1(double b);
    void set_b2(double b);
    void set_b3(double b);
    void set_arx_k(unsigned int arx_k);
    void set_pid_k(double pid_k);
    void set_pid_Ti(double pid_Ti);
    void set_pid_Td(double pid_Td);
    void set_syg(signal s);
    void set_zad(double a);
    void set_stala(double s);
    void set_T(int t);
    void set_p(double p);
    int get_K_pid();
    int get_ite();
    double get_u();
    double get_ster();
    double get_P();
    double get_D();
    double get_I();
    double get_Zad();
    void add_A_arx(double a);
    void add_B_arx(double b);
    bool get_start();
    double get_Y();

    void symulacja();
    void change_z();
    void Setup();
    void change_Z();
    double Get_A_ARX(int numer);
    double Get_B_ARX(int numer);
    bool Get_Z_ARX();
    bool Get_K_ARX();
    void Set_Z_ARX(bool z){arx.Set_Z(z);};
    void Set_Odch(double odch){arx.Set_Odchyl(odch);}
    void set_tryb(bool t){pid.set_tryb(t);}
    double Get_odchyl_Arx(){return arx.Get_Odch();}
};


