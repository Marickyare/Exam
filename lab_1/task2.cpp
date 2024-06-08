#include <locale.h>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	float x, y;
	cout << "Введите значение x: "; cin >> x;
	cout << "Введите значение y: "; cin >> y;

	if (x > -1 & x < 1 & y > -1 & y < 1) {
		if (((-1) * x - y) > 0){
			cout << "Точка подходит";
		}
		cout << "Точка не подходит";
	}
	cout << "Точка не подходит";
}
