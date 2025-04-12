#include<iostream>
#include <cmath>
using namespace std;

const int rozmiar =5;

int main() {
	//choleskeigo
	double A[rozmiar][rozmiar] = {
{ 5, 0, 3, 3, 7 },
{ 9, 3, 5, 2, 4 },
{ 7, 6, 8, 8, 1 },
{ 6, 7, 7, 8, 1 },
{ 5, 9, 8, 9, 4 },
	};

	double tab[rozmiar] = { 3, 0, 3, 5, 0 };
	double L[rozmiar][rozmiar] = { 0 };
	double U[rozmiar][rozmiar] = { 0 };
	double pom[rozmiar][rozmiar] = { 0 };
	int pom2 = 0;
	cout << "Metoda CHoleskiego:\n";
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j <= i; j++) {
			double sum = 0;
			if (j == i) {
				for (int k = 0; k < j; k++) {
					sum += pow(L[j][k], 2);
				}
				L[j][j] = sqrt(A[j][j] - sum);
			}
			else {
				for (int k = 0; k < j; k++) {
					sum += (L[i][k] * L[j][k]);
				}
				L[i][j] = (A[i][j] - sum) / L[j][j];
			}
		}
	}

	double* y = new double[rozmiar];
	for (int i = 0; i < rozmiar; i++) {
		y[i] = tab[i];
		for (int j = i; j > 0; j--) {
			y[i] -= L[i][j-1] * y[j-1];
		}
		y[i] /= L[i][i];
	}

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			pom[j][i] = L[i][j];
		}
	}

	double* x = new double[rozmiar];
	for (int i = rozmiar - 1; i >= 0; i--) {
		x[i] = y[i];
		for (int j = i + 1; j < rozmiar; j++) {
			x[i] -= pom[i][j] * x[j];
		}
		x[i] /= pom[i][i];
		printf("x[%d] = %0.10lf, ", i + 1, x[i]);
		pom2++;
		if (pom2 == 5) cout << endl;
	}
	cout << endl;

	//lu
	cout << "\nMetoda LU:\n";
	for (int i = 0; i < rozmiar; i++) {
		for (int k = i; k < rozmiar; k++) {
			int sum = 0;
			for (int j = 0; j < i; j++)
				sum += (L[i][j] * U[j][k]);
			U[i][k] = A[i][k] - sum;
		}

		for (int k = i; k < rozmiar; k++) {
			if (i == k)
				L[i][i] = 1;
			else {
				int sum = 0;
				for (int j = 0; j < i; j++)
					sum += (L[k][j] * U[j][i]);
				L[k][i] = (A[k][i] - sum) /U[i][i];
			}
		}
	}

	for (int i = 0; i < rozmiar; i++) {
		y[i] = tab[i];
		for (int j = i; j > 0; j--) {
			y[i] -= L[i][j - 1] * y[j - 1];
		}
		y[i] /= L[i][i];
	}
	pom2 = 0;
	for (int i = rozmiar - 1; i >= 0; i--) {
		x[i] = y[i];
		for (int j = i + 1; j < rozmiar; j++) {
			x[i] -= U[i][j] * x[j];
		}
		x[i] /= U[i][i];
		printf("x[%d] = %0.10lf, ",i+1, x[i]);
		pom2++;
		if (pom2 == 5) cout << endl;
	}
	cout << endl;


	return 0;
}