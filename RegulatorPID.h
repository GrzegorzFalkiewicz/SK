#pragma once

#include <iostream>
#include <math.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <iomanip>


#define DEBUG

using namespace std;

class RegulatorPID; class ModelARX;

class RegulatorPID {
private:
	double k;
	double ei;
	double Ti;
	double ej;
	double Td;
	double eip;
    double ej2;
    bool tryb;
	ModelARX* ARX = nullptr;
	friend ModelARX;
public:
    double get_k();
    double get_ei();
    double get_Ti();
    double get_ej();
    double get_Td();
    double get_eip();
    void set_k(double km);
    void set_ARX(ModelARX* ARXm);
    void set_Ti(double Tim);
    void set_ei(double eim);
    void dod_ej(double ejm);
    void set_ej2(double ejm);
    void set_Td(double Tdm);
    void set_eip(double eipm);
    double P();
    double I();
    double D();
    double PID();
    void reset();
    RegulatorPID(double km = 0, double Tim = 0, double Tdm = 0);
    double symuluj(double eim);
    void set_tryb(bool t);
};

void raportBleduSekwencji(std::vector<double>& spodz, std::vector<double>& fakt);
bool porownanieSekwencji(std::vector<double>& spodz, std::vector<double>& fakt);
void test_RegulatorP_brakPobudzenia();
void test_RegulatorP_skokJednostkowy();
void test_RegulatorPI_skokJednostkowy_1();
void test_RegulatorPI_skokJednostkowy_2();
void test_RegulatorPID_skokJednostkowy();

