#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

void aproksymacja(long double* tab, int n) {
	long double a1 = 0, a0 = 0, r = 0;
	long double sumy = 0, sumyx = 0, sumyy = 0, kwadratx = 0, kwadraty = 0;
	for (int i = 0; i < n; i++) {
		sumy += tab[i * 2] * tab[i * 2 + 1];
		sumyx += tab[i * 2];
		sumyy += tab[i * 2 + 1];
		kwadratx += tab[i * 2] * tab[i * 2];
		kwadraty += tab[i * 2 + 1] * tab[i * 2 + 1];
	}
	a1 = (n * sumy - sumyx * sumyy) / (n * kwadratx - sumyx * sumyx);
	a0 = (sumyy * kwadratx - sumyx * sumy) / (n * kwadratx - sumyx * sumyx);
	r = (n * sumy - sumyx * sumyy) / (sqrt(n * kwadratx - sumyx * sumyx) * sqrt(n * kwadraty - sumyy * sumyy));
	cout << "a1 = " << a1 << "\na0 = " << a0 << "\nr = " << r << endl;
}

int main() {
	string line; int pom = 0;
	ifstream myfile("file.txt");
	getline(myfile, line);
	int n = stoi(line);
	long double* tab = new long double[n * 2];

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

	aproksymacja(tab, n);

	delete[] tab;

	return 0;
}