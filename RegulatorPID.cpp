#include "RegulatorPID.h"
#include "ModelARX.h"
#include "WartoscZadana.h"

void raportBleduSekwencji(std::vector<double>& spodz, std::vector<double>& fakt)
{
	constexpr size_t PREC = 3;
	std::cerr << std::fixed << std::setprecision(PREC);
	std::cerr << "  Spodziewany:\t";
	for (auto& el : spodz)
		std::cerr << el << ", ";
	std::cerr << "\n  Faktyczny:\t";
	for (auto& el : fakt)
		std::cerr << el << ", ";
	std::cerr << std::endl << std::endl;
}

bool porownanieSekwencji(std::vector<double>& spodz, std::vector<double>& fakt)
{
    constexpr double TOL = 1e-3;
	bool result = fakt.size() == spodz.size();
	for (int i = 0; result && i < fakt.size(); i++)
		result = fabs(fakt[i] - spodz[i]) < TOL;
	return result;
}

void test_RegulatorP_brakPobudzenia()
{
	std::cerr << "RegP (k = 0.5) -> test zerowego pobudzenia: ";
	try
	{
		RegulatorPID instancjaTestowa(0.5);
		constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);
        std::vector<double> spodzSygWy(LICZ_ITER);
        std::vector<double> faktSygWy(LICZ_ITER);
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_RegulatorP_skokJednostkowy()
{
	std::cerr << "RegP (k = 0.5) -> test skoku jednostkowego: ";

	try
	{
		RegulatorPID instancjaTestowa(0.5);
		constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);
        std::vector<double> spodzSygWy(LICZ_ITER);
        std::vector<double> faktSygWy(LICZ_ITER);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5 };
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_RegulatorPI_skokJednostkowy_1()
{
	std::cerr << "RegPI (k = 0.5, TI = 1.0) -> test skoku jednostkowego nr 1: ";
	try
	{
		RegulatorPID instancjaTestowa(0.5, 1.0);
		constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);
        std::vector<double> spodzSygWy(LICZ_ITER);
        std::vector<double> faktSygWy(LICZ_ITER);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 19.5, 20.5, 21.5, 22.5, 23.5, 24.5, 25.5, 26.5, 27.5, 28.5, 29.5 };
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_RegulatorPI_skokJednostkowy_2()
{
	std::cerr << "RegPI (k = 0.5, TI = 10.0) -> test skoku jednostkowego nr 2: ";
	try
	{

		RegulatorPID instancjaTestowa(0.5, 10.0);
		constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);
        std::vector<double> spodzSygWy(LICZ_ITER);
        std::vector<double> faktSygWy(LICZ_ITER);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0.6, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3, 3.1, 3.2, 3.3, 3.4 };
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

void test_RegulatorPID_skokJednostkowy()
{
	std::cerr << "RegPID (k = 0.5, TI = 10.0, TD = 0.2) -> test skoku jednostkowego: ";
	try
	{
		RegulatorPID instancjaTestowa(0.5, 10.0, 0.2);
		constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);
        std::vector<double> spodzSygWy(LICZ_ITER);
        std::vector<double> faktSygWy(LICZ_ITER);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0.8, 0.7, 0.8, 0.9, 1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3, 3.1, 3.2, 3.3, 3.4 };
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);
		if (porownanieSekwencji(spodzSygWy, faktSygWy))
			std::cerr << "OK!\n";
		else
		{
			std::cerr << "FAIL!\n";
			raportBleduSekwencji(spodzSygWy, faktSygWy);
		}
	}
	catch (...)
	{
		std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
	}
}

double RegulatorPID::get_k() { return k; }

double RegulatorPID::get_ei() { return ei; }

double RegulatorPID::get_Ti() { return Ti; }

double RegulatorPID::get_ej() { return ej; }

double RegulatorPID::get_Td() { return Td; }

double RegulatorPID::get_eip() { return eip; }

void RegulatorPID::set_k(double km) { k = km; }

void RegulatorPID::set_ARX(ModelARX *ARXm) { ARX = ARXm; }

void RegulatorPID::set_Ti(double Tim) { Ti = Tim; }

void RegulatorPID::set_ei(double eim) { set_eip(ei); dod_ej(eim);set_ej2(eim) ;ei = eim;}

void RegulatorPID::dod_ej(double ejm) { ej += ejm; }

void RegulatorPID::set_Td(double Tdm) { Td = Tdm; }

void RegulatorPID::set_eip(double eipm) { eip = eipm; }

double RegulatorPID::P() { return (k * ei); }

double RegulatorPID::I() { if (Ti == 0) return 0; else if(tryb==true)return ((1 / Ti) * ej); else return ej2; }

double RegulatorPID::D() { return Td * (ei - eip); }

double RegulatorPID::PID() { return P() + I() + D(); }

void RegulatorPID::reset() { ej = 0; eip = 0; ej2=0;}

RegulatorPID::RegulatorPID(double km, double Tim, double Tdm) { ei = 0; ej = 0; eip = 0; k = km; Ti = Tim; Td = Tdm; ej2=0; tryb=true;}

double RegulatorPID::symuluj(double eim) { set_ei(eim); return PID(); }

void RegulatorPID::set_ej2(double ej) {if(Ti!=0) ej2+= ej*1/Ti;}

void RegulatorPID::set_tryb(bool t){tryb=t;}


