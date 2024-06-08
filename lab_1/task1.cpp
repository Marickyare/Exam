#define M_PI 3.14159265358979323846
#include <math.h>
#include <iostream>


using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	float a, b;
	cout << "Ввежите значение b: "; cin >> b;
		cout << "Ввежите значение a: "; cin >> a;
		float F = ((0.75 * sqrt(b) - 1 / 2 * pow(a, 1 / 3)) * sin(b * M_PI)) / cos(pow((a + b), 2) + exp(a));
		cout << F;

}
