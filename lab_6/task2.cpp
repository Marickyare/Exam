#include <locale.h>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	ifstream i_f;
	i_f.open("start_file.txt");

	if (i_f.fail()) {                                    //проверка открытия файла
		printf("К сожалению, файл открыть не удалось.");
	}

	int R;							//количество точек
	i_f >> R;

	int** arr = new int*[R];				//выделение памяти под массив
	for (int i = 0; i < R; i++) {				//выделение памяти под подмассив
		arr[i] = new int[2];
	}

	for (int l = 0; l < R; l++)					//заполнение массива
	{
		for (int k = 0; k < 2; k++)
		{
			i_f >> arr[l][k];
		} 
	}

	int min_dist = (sqrt(pow(abs(arr[1][0] - arr[0][0]), 2) + pow(abs(arr[1][1] - arr[0][1]), 2)));
	int min_x1, min_x2, min_y1, min_y2;
	min_x1= min_x2= min_y1= min_y2 = 0;

	for (int k = 0; k < R; k++)
	{
		for (int o = k+1; o < R; o++) {

			int dist = (sqrt(pow(abs(arr[o][0] - arr[k][0]), 2) + pow(abs(arr[o][1] - arr[k][1]), 2)));
			if (min_dist > dist) {
				min_dist = dist;
				min_x1 = arr[k][0];
				min_x2 = arr[o][0];
				min_y1 = arr[k][1];
				min_y2 = arr[o][1];
			}
		}
	}
	cout << "Минимальная расстояние между точками: " << min_dist << endl << "Координаты первой точки:  " << min_x1 << ", " << min_y1 << endl << "Координаты второй точки: " << min_x2 << ", "<<min_y2 << endl;
}
