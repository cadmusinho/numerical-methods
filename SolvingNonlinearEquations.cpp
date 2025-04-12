#include<iostream>
#include<cmath>
using namespace std;

double funkcja(double x) {
	return 1.234*pow(x,4)-5.678*pow(x,3)+9.123*pow(x,2)-4.567891*x;
}

double pochodna(double x) {
	return 4.936*pow(x,3)-17.034*pow(x,2)+19.246*x-456789;
}

double bisekcja(double a, double b, double precyzja) {
	double x = (a + b) / 2;
	while (fabs(funkcja(x)) > precyzja) {
		if (funkcja(x) * funkcja(a) < 0) {
			b = x;
		}
		else {
			a = x;
		}
		x = (a + b) / 2;
	}
	return x;
}

double newton_raphson(double x, double precyzja) {
	double x_next = x - funkcja(x) / pochodna(x);
	while ((fabs(funkcja(x)) > precyzja) && (fabs(x_next - x) > precyzja)) {
		x = x_next;
		x_next = x_next - funkcja(x_next) / pochodna(x);
	}
	return x_next;
}

int main() {
	printf("Bisekcja: %1.10lf\n", bisekcja(0.5, 2, 0.000001));
	printf("Newton_Raphson: %1.10lf\n", newton_raphson(0.8, 0.000001));
	return 0;
}