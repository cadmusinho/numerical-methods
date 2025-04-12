#include<iostream>
#include<string>
#include<cmath>
#include<random>
using namespace std;

float funkcja(float liczba) {
	return exp(liczba);
}

float losowa(float xp, float xk) {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dis(xp, xk);
	return dis(gen);
}


void prostokaty(float n, float xp, float xk) {
	float dx = (xk - xp) / n;
	float wynik = 0;
	xp++;
	for (int i = 0; i < n; i++, xp += dx) {
		wynik += funkcja(xp);
	}
	cout << "Prostokaty: " << dx * wynik << endl;
}

void trapezy(float n, float xp, float xk) {
	float dx = (xk - xp) / n;
	float wynik = 0;
	for (int i = 0; i < n; i++) {
		wynik += dx * (((funkcja(xp + dx*i) + funkcja(xp + dx + dx * i))) / 2);
	}
	cout << "Trapezy: " << wynik << endl;
}

void simpson(float xp, float xk) {
	float* pom = new float[5];
	float jeden = 0, dwa = 0;
	pom[0] = xp;
	pom[4] = xk;
	pom[2] = (xk + xp) / 2;
	pom[1] = (pom[2] + xp) / 2;
	pom[3] = (xk + pom[2]) / 2;
	float h = pom[1] - pom[0];
	for (int i = 0; i < 3; i++) {
		if (i == 1) {
			jeden += 4 * funkcja(pom[i]);
			dwa += 4 * funkcja(pom[4 - i]);
		}
		else {
			jeden += funkcja(pom[i]);
			dwa += funkcja(pom[4 - i]);
		}
	}
	cout << "Simpson: " << (jeden*(h/3) + dwa*(h/3)) << endl;
	delete[]pom;
}

void monteCarlo(float n, float xp, float xk) {
	float pom;
	float fsrednie = 0;
	for (int i = 0; i < n; i++) {
		pom= losowa(xp, xk);
		fsrednie += funkcja(pom) / n;
	}
	cout << "Monte Carlo: " << fsrednie * fabs(xk - xp) << endl;
}


int main() {

	prostokaty(500, -5, 5);
	trapezy(500, -5, 5);
	simpson(-5, 5);
	monteCarlo(500, -5, 5);

	return 0;
}