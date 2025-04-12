#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void newton(long double* tab, int n) {
	long double** tab2 = new long double*[n - 1];
	for (int i = 0; i < (n - 1); ++i)
	{
		tab2[i] = new long double[n - (i+1)];
	}
	for (int i = 0; i < n - 1; i++) {
		tab2[0][i] = ((tab[(i * 2 + 3)] - tab[i * 2 + 1]) / (tab[i * 2 + 2] - tab[i * 2]));
	}
	int pom = n-2;
	for (int i = 1; i < (n - 1); i++) {
		for (int j = 0; j < pom; j++) {
			tab2[i][j] = (tab2[i - 1][j + 1] - tab2[i - 1][j]) / (tab[j * 2 + 2 * (i + 1)] - tab[j * 2]);
		}
		pom--;
	}
	long double wynik = tab[1];
	for (int i = 0; i < (n - 1); i++) {
		pom = tab2[i][0];
		for (int j = 0; j <= i; j++) {
			pom *= (tab[n * 2] - tab[j * 2]);
		}
		wynik += pom;
	}
	cout <<"Wynik: "<< wynik;
	for (int i = 0; i < (n - 1); ++i) {
		delete[] tab2[i];
	}
	delete[] tab2; 
}

int main() {
	string line; int pom = 0;
	ifstream myfile("file.txt");
	getline(myfile, line);
	int n = stoi(line);
	long double* tab = new long double[n * 2 + 1];

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			tab[pom] = stof(line);
			pom++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	newton(tab, n);

	delete[] tab;

	return 0;
}