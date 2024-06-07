#include <locale.h>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int x, y;
	cout << "Введите значение x: "; cin >> x;
	cout << "Введите значение y: "; cin >> y;

	if (sqrt(x*x + y*y) >= 1 & sqrt(x*x + y*y) <= 2) {
		if (x >= 0 & x <= 2) {
			cout << "Точка подходит";
		}
		cout << "Точка не подходит";
	}
	cout << "Точка не подходит";
}