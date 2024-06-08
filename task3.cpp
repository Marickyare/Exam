#include <locale.h>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n = 1;
	float E;
	float summ = n / pow((n + 1), n);
	n++;
	cout << "Введите значение Е: "; cin >> E;
	while ((n / pow((n + 1), n)) - ((n - 1) / pow(((n - 1) + 1), n - 1)) > E) {
		if ((n / pow((n + 1), n) ) < E) {
			summ += (n / pow((n + 1), n));
			n++;
			cout << "Значение подходит.";
		}
	}
	cout << "Значение не подходит.";
}

