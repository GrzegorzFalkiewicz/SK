#include "ModelARX.h"
#include "RegulatorPID.h"
#include <cassert>
#include <random>

void ModelARX::Set_A(vector<double> a) {A = a; }

void ModelARX::Set_A1(double a){A[0]=a;}

void ModelARX::Set_A2(double a){A[1]=a;}

void ModelARX::Set_A3(double a){A[2]=a;}

void ModelARX::Set_B1(double b){B[0]=b;}

void ModelARX::Set_B2(double b){B[1]=b;}

void ModelARX::Set_B3(double b){B[2]=b;}

void ModelARX::Add_A(double a){A.push_back(a);}

void ModelARX::Set_B(vector<double> b) {B = b; }

void ModelARX::Add_B(double b){B.push_back(b);}

void ModelARX::Set_Y(double y) { Y = y; }

void ModelARX::Set_K(unsigned int k) { K = k; }

void ModelARX::Set_PID(RegulatorPID *pid) { PID = pid; }

void ModelARX::Set_Z(bool z) { Z = z; }

void ModelARX::CheckSize() {

	if (A.size() > kol_y.size()) {
		do
		{
			kol_y.push_back(0.0);
		} while (A.size() > kol_y.size());


	}

	if (B.size() > kol_u.size()) {
		do
		{
			kol_u.push_back(0.0);
		} while (B.size() > kol_u.size());


	}

	if (buf_op.size() < K) {
		do
		{
			buf_op.push_back(0.0);
		} while (buf_op.size() < K);


	}

	if (A.size() < kol_y.size()) {
		do
		{
			kol_y.pop_back();
		} while (A.size() < kol_y.size());


	}

	if (B.size() < kol_u.size()) {
		do
		{
			kol_u.pop_back();
		} while (B.size() < kol_u.size());


	}

	if (buf_op.size() > K) {
		do
		{
			buf_op.pop_back();
		} while (buf_op.size() > K);


	}

}

double ModelARX::Get_Y() { return Y; }

double ModelARX::symuluj(double e)
{
	CheckSize();
    buf_op.push_back(e);
    kol_u.push_front(buf_op[0]);
	double y_s = 0;
	random_device srng; mt19937 rng;
	rng.seed(srng());


	for (size_t i = 0; i < B.size(); i++) {

		y_s += B[i] * kol_u[i];
	}

	for (size_t i = 0; i < A.size(); i++) {

		y_s -= A[i] * kol_y[i];
	}
    if(odch!=0.0)
    {
        normal_distribution<double> normal(0.0, odch);
        y_s += normal(rng);
    }
    //cerr<<y_s<<" ";
    //cerr<<normal(rng)<<" ";

    kol_y.push_front(y_s);
    kol_y.pop_back();

    //buf_op.push_back(e);
	buf_op.pop_front();
    //kol_u.push_front(buf_op[0]);

	kol_u.pop_back();

	Set_Y(y_s);

	return Get_Y();

}

ModelARX::ModelARX(vector<double> a, vector<double> b, unsigned int k, double y)
{
	A = a;
	B = b;
	K = k;
	Y = y;


}

void ModelARX::change_Z(){Z=!Z;}

void ModelARX::clean(){kol_y.clear();kol_u.clear();buf_op.clear();}


double ModelARX::Get_A(int numer)
{
    assert(numer>=0 && numer<A.size());
        return A[numer];
}

double ModelARX::Get_B(int numer)
{
    assert(numer>=0 && numer<B.size());
        return B[numer];
}



//Funkcje pomocnicze dla testów:



void test_ModelARX_brakPobudzenia()
{
	//Sygnatura testu:
	std::cerr << "ModelARX (-0.4 | 0.6 | 1 | 0 ) -> test zerowego pobudzenia: ";
	try
	{
		// Przygotowanie danych:
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 1, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
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

void test_ModelARX_skokJednostkowy_1()
{
	//Sygnatura testu:
	std::cerr << "ModelARX (-0.4 | 0.6 | 1 | 0 ) -> test skoku jednostkowego nr 1: ";

	try
	{
		// Przygotowanie danych:
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 1, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy 
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0.6, 0.84, 0.936, 0.9744, 0.98976, 0.995904, 0.998362, 0.999345, 0.999738, 0.999895, 0.999958, 0.999983, 0.999993, 0.999997, 0.999999, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
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

void test_ModelARX_skokJednostkowy_2()
{
	//Sygnatura testu:
	std::cerr << "ModelARX (-0.4 | 0.6 | 2 | 0 ) -> test skoku jednostkowego nr 2: ";

	try
	{
		// Przygotowanie danych:
		ModelARX instancjaTestowa({ -0.4 }, { 0.6 }, 2, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu, 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0, 0.6, 0.84, 0.936, 0.9744, 0.98976, 0.995904, 0.998362, 0.999345, 0.999738, 0.999895, 0.999958, 0.999983, 0.999993, 0.999997, 0.999999, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Walidacja poprawności i raport:
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

void test_ModelARX_skokJednostkowy_3()
{
	//Sygnatura testu:
	std::cerr << "ModelARX (-0.4, 0.2 | 0.6, 0.3 | 2 | 0 ) -> test skoku jednostkowego nr 3: ";
	try
	{
		// Przygotowanie danych:
		ModelARX instancjaTestowa({ -0.4,0.2 }, { 0.6, 0.3 }, 2, 0);
		constexpr size_t LICZ_ITER = 30;
		std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu, 
		std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
		std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

		// Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
		for (int i = 0; i < LICZ_ITER; i++)
			sygWe[i] = !!i;
		spodzSygWy = { 0, 0, 0, 0.6, 1.14, 1.236, 1.1664, 1.11936, 1.11446, 1.12191, 1.12587, 1.12597, 1.12521, 1.12489, 1.12491, 1.12499, 1.12501, 1.12501, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125, 1.125 };

		// Symulacja modelu:
		for (int i = 0; i < LICZ_ITER; i++)
			faktSygWy[i] = instancjaTestowa.symuluj(sygWe[i]);

		// Weryfikacja poprawności i raport:
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
