#pragma once

#include <vector>
#include <deque>



using namespace std;
class ModelARX; class RegulatorPID;

class ModelARX
{
    vector<double>A = {0.0,0.0,0.0};
    vector<double>B = {0.0,0.0,0.0};
	unsigned int K = 1;
	deque<double>kol_y = {};
	deque<double>kol_u = {};
	deque<double>buf_op = {};
	double Y = 0.0;
    double odch=0.0;
	RegulatorPID* PID = nullptr;
	bool Z = false;
	friend RegulatorPID;
public:
    void Set_A(vector<double>a);
    void Set_A1(double a);
    void Set_A2(double a);
    void Set_A3(double a);

    void Set_B1(double b);
    void Set_B2(double b);
    void Set_B3(double b);

    void Add_A(double a);
    void Set_B(vector<double>b);
    void Add_B(double b);
    void Set_Y(double y);
    void Set_K(unsigned int k);
    void Set_PID(RegulatorPID* pid);
    void Set_Z(bool z);
	void CheckSize();
    double Get_Y();
	double symuluj(double e);
	ModelARX(vector<double>, vector<double>, unsigned int, double);
    ModelARX(){};
    void change_Z();
    void clean();
    double Get_A(int numer);
    double Get_B(int numer);
    int Get_k(){return K;};
    bool Get_Z(){return Z;};
    void Set_Odchyl(double od){odch=od;};
    double Get_Odch(){return odch;}
};

void test_ModelARX_brakPobudzenia();
void test_ModelARX_skokJednostkowy_1();
void test_ModelARX_skokJednostkowy_2();
void test_ModelARX_skokJednostkowy_3();
