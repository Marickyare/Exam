#include <locale.h>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введит размер массива: "; cin >> n;
	
	int* arrX = new int[n];					//формируем исходный массив
	for (int i = 0; i < n; i++)
	{
		int ind;
		cout << "Введите число для индекса " << i << ": "; cin >> ind;			//заполняем массив
		arrX[i] = ind;
	}

	int* arrY = new int[n];					//формируем новый массив


    for (int i = 0; i <= n / 2; i++)
    {
        arrY[2 * i] = arrX[i];                     //перебираем все четные индексы массива
        arrY[2 * i + 1] = arrX[n - 1 - i];         //перебираем все нечетные индексы массива 
    }

	delete[] arrX;								//чистим память от первоначального массива

	ofstream out_f;								//создание файла для записи
	out_f.open("final_file.txt");

	if (out_f.fail()) {                                    //проверка открытия файла
		printf("К сожалению, файл открыть не удалось.");
	}

	for (int k = 0; k < n; k++)
	{
		out_f << arrY[k] << "\t";
	}

	out_f.close();
	delete[] arrY;								//чистим память от конечного массива
}
