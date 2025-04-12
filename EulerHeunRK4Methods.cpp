#include<iostream>
using namespace std;

double funkcja(double x, double y) {
	return x / (y*y);
}

int main() {
	double 	x0 = 1, b = 3, y0 = 1, h = .5, n = (b - x0) / h;
	int pom = 0;

	cout << "Eulera\n";
	for (; x0 < b; x0 += h, pom++) {
		printf("y%d = %1.10lf\tx%d = %1.2lf\n", pom, y0, pom, x0);
		y0 = y0 + h * funkcja(x0, y0);
	}
	printf("y%d = %1.10lf\tx%d = %1.2lf\n", pom, y0, pom, x0);

	cout << "\nHeuna\n";
	x0 = 1, b = 3, y0 = 1, h = .5, n = (b - x0) / h; pom = 0;
	for (; x0 < b; x0 += h, pom++) {
		printf("y%d = %1.10lf\tx%d = %1.2lf\n", pom, y0, pom, x0);
		y0 = y0 + (h / 2) * (funkcja(x0, y0) + funkcja(x0 + h, y0 + h * funkcja(x0, y0)));
	}
	printf("y%d = %1.10lf\tx%d = %1.2lf\n", pom, y0, pom, x0);

	cout << "\nRK4\n";
	x0 = 1, b = 3, y0 = 1, h = .5, n = (b - x0) / h; pom = 0;
	for (; x0 < b; x0 += h, pom++) {
		printf("y%d = %1.10lf\tx%d = %1.2lf\n", pom, y0, pom, x0);
		double k1 = h * funkcja(x0, y0);
		double k2 = h * funkcja(x0 + 0.5 * h, y0 + 0.5 * k1);
		double k3 = h * funkcja(x0 + 0.5 * h, y0 + 0.5 * k2);
		double k4 = h * funkcja(x0 + h, y0 + k3);
		y0 = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	}
	printf("y%d = %1.10lf\tx%d = %1.2lf\n", pom, y0, pom, x0);
	double x = 1.5;
	cout << 1.5*log10(x)+1-1.5;
	return 0;
}