#include "symulator.h"

void Symulator::reset() { pid.reset(); }

void Symulator::StartStop() { sterowanie = !sterowanie; }

void Symulator::set_arx_a(std::vector<double> arx_a) { arx.Set_A(arx_a); }

void Symulator::set_arx_b(std::vector<double> arx_b) { arx.Set_A(arx_b); }

void Symulator::set_a1(double a){arx.Set_A1(a);}

void Symulator::set_a2(double a){arx.Set_A2(a);}

void Symulator::set_a3(double a){arx.Set_A3(a);}

void Symulator::set_b1(double b){arx.Set_B1(b);}

void Symulator::set_b2(double b){arx.Set_B2(b);}

void Symulator::set_b3(double b){arx.Set_B3(b);}

void Symulator::set_arx_k(unsigned int arx_k) { arx.Set_K(arx_k); }

void Symulator::set_pid_k(double pid_k) { pid.set_k(pid_k); }

void Symulator::set_pid_Ti(double pid_Ti) { pid.set_Ti(pid_Ti); }

void Symulator::set_pid_Td(double pid_Td) { pid.set_Td(pid_Td); }

void Symulator::set_syg(signal s) { syg = s; }

void Symulator::set_zad(double a) { gen3.set_A(a); gen2.set_A(a);  gen1.set_A(a);}

void Symulator::set_T(int t) { gen1.set_t(t); gen2.set_T(t); gen3.set_T(t); }

void Symulator::set_p(double p) { gen2.set_p(p); }

int Symulator::get_K_pid(){return pid.get_k();}

int Symulator::get_ite(){return ite;}

double Symulator::get_u(){return u;}

double Symulator::get_ster(){return y_pid;}

double Symulator::get_P(){return pid.P();}

double Symulator::get_D(){return pid.D();}

double Symulator::get_I(){return pid.I();}

double Symulator::get_Zad(){
    if(syg==signal::sk_jed)
        return gen1(ite);
    else if(syg==signal::syg_prost)
        return gen2(ite);
    else return gen3(ite);
}

void Symulator::add_A_arx(double a){arx.Add_A(a);}

void Symulator::add_B_arx(double b){arx.Add_B(b);}

bool Symulator::get_start(){return sterowanie;}

double Symulator::get_Y(){return arx.Get_Y();}

void Symulator::symulacja(){


        if(syg==signal::sk_jed)u = gen1(ite) - arx.Get_Y();
        else if (syg == signal::syg_prost) u = gen2(ite) - arx.Get_Y();
        else u = gen3(ite) - arx.Get_Y();
        y_pid = pid.symuluj(u);
        arx.symuluj(y_pid);
        ite++;

}

void Symulator::change_z(){arx.change_Z();}

void Symulator::Setup(){
    arx.clean();
    arx.Set_Y(0);
    pid.set_ei(0);
    pid.set_ei(0);
    ite = 0;
    u = 0;
    y_pid = 0;}

void Symulator::change_Z(){arx.change_Z();};

double Symulator::Get_A_ARX(int numer)
{
   return arx.Get_A(numer);
}

double Symulator::Get_B_ARX(int numer)
{
   return arx.Get_B(numer);
}

bool Symulator::Get_Z_ARX(){return arx.Get_Z();};
bool Symulator::Get_K_ARX(){return arx.Get_k();};
void Symulator::set_stala(double s){gen1.set_A(s);gen2.set_S(s);gen3.set_S(s);};
