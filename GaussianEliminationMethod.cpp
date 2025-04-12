#include<iostream>
using namespace std;

int main() {
	
	double tab[7][8] = {  
		 {2.2134, 1.123, 0.1, 0.9, 0.1, 0.4, 0.5, 0.6},
		 {0.001, 1.123, 0.1, 213, 0.1, 11111, 0.5, 0.6},
		 {0.002, 0.71, 0.1, 0.9, 0.1, 0.4, 213, 213},
		 {0.003, 213, 0.001, 0.9, 0.1, 0.71, 0.5, 0.6},
		 {0.004, 1.123, 0.1, 11111, 0.71, 0.4, 0.5, 0.6},
		 {0.005, 11111, 0.1, 0.71, 0.1, 0.4, 0.71, 213},
		 {2.2134, 1.123, 0.1, 213, 11111, 0.4, 0.5, 11111}
	};

	int rozmiar = 7;

	double* x = new double[rozmiar];
	for (int z = 0; z < rozmiar; z++) {
		for (int i = z + 1; i < rozmiar; i++) {
			for (int j = rozmiar; j >= 0; j--) {
				tab[i][j] -= tab[z][j] * (tab[i][z] / tab[z][z]);
			}
		}
	}

	for (int i = rozmiar - 1; i >= 0; i--) {
		x[i] = tab[i][rozmiar];
		for (int j = i + 1; j < rozmiar; j++) {
			x[i] -= tab[i][j] * x[j];
		}
		x[i] /= tab[i][i];

	}

	for (int z = 0; z < rozmiar; z++) {
		printf("x%d = %0.10lf\n", z + 1 , x[z] );
	}

	return 0;
}