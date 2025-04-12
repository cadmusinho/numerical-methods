#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	string line; int pom = 0;
	double tab[8];
	double punkt[2];
	double poch_ksi[2][4]; 
	double poch_ni[2][4];
	double fun_detj[2][2];
	double dxdKSI, dydKSI, dxdNI, dydNI, powierzchnia = 0;

	ifstream myfile("file.txt");
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

	punkt[0] = 0.5773502692;
	punkt[1] = -0.5773502692;

	for (int i = 0; i <= 1; i++) {
			poch_ksi[i][0] = -0.25 * (1.0 - punkt[i]);
			poch_ksi[i][1] = 0.25 * (1.0 - punkt[i]);
			poch_ksi[i][2] = 0.25 * (1.0 + punkt[i]);
			poch_ksi[i][3] = -0.25 * (1.0 + punkt[i]);
			poch_ni[i][0] = -0.25 * (1.0 - punkt[i]);
			poch_ni[i][1] = -0.25 * (1.0 + punkt[i]);
			poch_ni[i][2] = 0.25 * (1.0 + punkt[i]);
			poch_ni[i][3] = 0.25 * (1.0 - punkt[i]);
	}

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			dxdKSI = poch_ksi[j][0] * tab[0] + poch_ksi[j][1] * tab[2] + poch_ksi[j][2] * tab[4] + poch_ksi[j][3] * tab[6];
			dydKSI = poch_ksi[j][0] * tab[1] + poch_ksi[j][1] * tab[3] + poch_ksi[j][2] * tab[5] + poch_ksi[j][3] * tab[7];
			dxdNI = poch_ni[i][0] * tab[0] + poch_ni[i][1] * tab[2] + poch_ni[i][2] * tab[4] + poch_ni[i][3] * tab[6];
			dydNI = poch_ni[i][0] * tab[1] + poch_ni[i][1] * tab[3] + poch_ni[i][2] * tab[5] + poch_ni[i][3] * tab[7];
			fun_detj[i][j] = dxdKSI * dydNI - dxdNI * dydKSI;
		}
	}

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			powierzchnia += fabs(fun_detj[i][j]);
		}
	}
	
	cout << "Powierzchnia wynosi: " << powierzchnia << endl;

	return 0;
}