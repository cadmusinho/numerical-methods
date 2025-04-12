#include<iostream>
using namespace std;

double najwiekszy_wiersze(double tab[][5], int kolumna, int rozmiar) {
	double max = tab[kolumna][kolumna];
	int indeks = kolumna;
	for (int i = kolumna; i < (rozmiar-1); i++) {
		if (fabs(tab[i][kolumna]) > fabs(max)) {
			max = tab[i][kolumna];
			indeks = i;
		}
	}
	return indeks;
}

double najwiekszy_kolumny(double tab[][5], int wiersz, int rozmiar) {
	double max = tab[wiersz][wiersz];
	int indeks = wiersz;
	for (int i = wiersz; i < rozmiar; i++) {
		if (fabs(tab[wiersz][i]) > fabs(max)) {
			max = tab[wiersz][i];
			indeks = i;
		}
	}
	return indeks;
}

int main() {
	int a = 0;
	int indeks = 0;
	double pom = 0;
	int rozmiar = 4;

	double tab[4][5] = { {1, -2, 0, -2, 8}, {1, 1, 0, 2, 0.33}, {1, 4, 0, 1, 0.75}, {1, -2, 0, 2, 2} };
	for (int z = 0; z < rozmiar; z++) {
		indeks = najwiekszy_wiersze(tab, z, rozmiar);
		for (int i = 0; i <= rozmiar; i++) {
			if (indeks == z) {}
			else {
				pom = tab[indeks][i];
				tab[indeks][i] = tab[z][i];
				tab[z][i] = pom;
			}
		}
		for (int i = z+1; i < rozmiar; i++) {
			pom = tab[i][z] / tab[z][z];
				for (int j = 0; j <= rozmiar; j++) {
				tab[i][j] -= tab[z][j] * pom;
			}
		}
	}

	double* x = new double[rozmiar];
	cout << "Zamiana wierszy" << endl;
	cout << "x = {";
	for (int i = rozmiar - 1; i >= 0; i--) {
		x[i] = tab[i][rozmiar];
		for (int j = i + 1; j < rozmiar; j++) {
			x[i] -= tab[i][j] * x[j];
		}
		x[i] /= tab[i][i];
		printf(" %0.10lf,", x[i]);
		a++;
		if (a % 5 == 0) cout << endl;
	}
	cout << '}';
	cout << endl;

	for (int z = 0; z < rozmiar; z++) {
		indeks = najwiekszy_kolumny(tab, z, rozmiar);
		for (int i = 0; i < rozmiar; i++) {
			if (indeks == z) {}
			else {
				pom = tab[i][indeks];
				tab[i][indeks] = tab[i][z];
				tab[i][z] = pom;
			}
		}
		for (int i = z + 1; i < rozmiar; i++) {
			pom = tab[i][z] / tab[z][z];
			for (int j = 0; j <= rozmiar; j++) {
				tab[i][j] -= tab[z][j] * pom;
			}
		}
	}

	a = 0;
	cout << "Zamiana kolumn" << endl;
	cout << "x = {";
	for (int i = rozmiar - 1; i >= 0; i--) {
		x[i] = tab[i][rozmiar];
		for (int j = i + 1; j < rozmiar; j++) {
			x[i] -= tab[i][j] * x[j];
		}
		x[i] /= tab[i][i];
		printf(" %0.10lf,", x[i]);
		a++;
		if (a % 5 == 0) cout << endl;
	}
	cout << '}';
	return 0;
}