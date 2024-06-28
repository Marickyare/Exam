#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int matr(int **arr, int k) {
	int max_el = 0;
	int min_el = 10000;
		for (int i = 1; i < k; i++) {
			for (int j = (k-i); j < k; j++) {
				if (j > (k - i - 1)) {

					if (max_el <= arr[i][j]) {
						max_el = arr[i][j];
					}
					if (min_el >= arr[i][j]) {
						min_el = arr[i][j];
					};
				}
			}
		}
		cout << "Минимальный элемент массива по побочной диагональню: " << min_el << endl << "Максимальный элемент массива по побочной диагональню: " << max_el;
	
	return 1;
}

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream f1;
	f1.open("start_file.txt");									//открытие файла

	if (!f1) { cout << "Не удалось открыть файл."; }			//проверка на корректность открытия файла
	
	const int k = 5;
	int arr[k][k];

	for (int i = 0; i < k; i++)									//перепись данных из файла в массив
	{
		for (int j = 0; j < k; j++)
		{
			f1 >> arr[i][j];
		}
	}
	f1.close();													//закрытие файла

	int* pm[k];													//создание прототипа массива

	for (int i = 0; i < k; i++)									//заполнение прототипа массива
	{
		pm[i] = arr[i];
	}


matr(pm, k);

}