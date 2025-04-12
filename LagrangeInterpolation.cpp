#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	string line; int pom = 0;
	ifstream myfile("file.txt");
	getline(myfile, line);
	int n = stoi(line) * 2 + 1; 
	float* tab = new float[n];
	float* tabl = new float[n];
	float wynik = 0;

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

	for (int i = 0; i < (n-1); i += 2) {	
									
		tabl[i] = 1;
		for (int j = 0; j < (n-1); j += 2) {
			if (j != i) {
				tabl[i] *= (tab[n-1] - tab[j]) / (tab[i] - tab[j]);
			}
		}
	}
	pom = 0;
	for (int i = 1; i < n; i += 2) {		
		wynik += tab[i] * tabl[pom];
		pom+=2;						
	}
	cout << "Wynik: " << wynik << endl;
	
	delete[] tab;
	delete[] tabl;

	return 0;
}