#include <locale.h>
#include <iostream>
#include <fstream>

using namespace std;

int dell(int* n) {
	int counter = 1;
	int delitel = 0;
	while (counter <= *n) {
		if ((*n) % counter == 0) {
			delitel++;
			counter++;
		}
		else {
			counter++;
		}
	}
	return delitel;
}

	int simp(int* n){
		int i;          // счетчик цикла
		int s = 1;      // является ли простым (0 - нет, 1 - да)

		if (*n > 10000) { return -1; }			//установим ограничение

		if (*n < 2) { s = 0; }					// не берём в расчёт
		
		else
		{
			for (i = 2; i * i <= *n; i++)
			{
				if (*n % i == 0)
				{
					s = 0;  // если разделилось нацело, то составное
					break;
				}
			}
		}
		return s;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Программа определения делителей и простых чисел.\n";
	int n = 1; 
	int counter_simp = 0; //счётчик для простых чисел

	cout << "Программа прекратит принимать значения, после введения числа \"0\"\n";

	ofstream f_out;
	f_out.open("end_file.txt");

	while (n != 0) {
		cout << "Введите число: "; cin >> n;
		f_out << "Количество делителей числа " << n << ": " << dell(&n) << endl;
		if (simp(&n) > 0) { counter_simp++; }
	}
	f_out << "Количество простых чисел: " << counter_simp << endl;

	f_out.close();
}