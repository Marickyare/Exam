#include <locale.h>
#include <iostream>
#include <algorithm>

using namespace std;

int NOD(int m, int n) {
	while (n != m) {
		if (m > n) { m = m - n; }
		else { n = n - m; }
	}
	return m;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "Введите количество значений (N): "; cin >> N;
	int* arr = new int[N];														//объявляем и выделяем память под массив
	for (int i = 0; i < N; i++)
	{
		cout << "Введите значение " << i << "-го элемента:"; cin >> arr[i];		//заполняем масссив
	}
	int max = *max_element(arr, arr + 1);
	int* arr_delit = new int[max] {};												//объявляем массив для хранения всех найденных делителей

	int ind_for_del_arr = 0;

	for (int j = 0; j < N; j++)													//запускам перебор для поиска всех делителей пар
	{
		for (int k = j+1; k < N; k++)
		{
			arr_delit[ind_for_del_arr] = NOD(arr[j], arr[k]);					//добавляем в массив найденный делитель
			ind_for_del_arr++;
		}
	}

	int ind_chek = 0;


	int max_delit = 0;

	for (int c1 = 0; c1 < N; c1++)
	{
		for (int c2 = 0; c2 < max; c2++)
		{
			if (arr_delit[c2] == 0) { continue; }
			if (arr[c1] % arr_delit[c2] == 0) {
				if (arr_delit[c2] > max_delit) 
				{ 
					max_delit = arr_delit[c2]; 
				}
			}
		}
	}
	cout << max_delit;

	delete[] arr;
	delete[] arr_delit;
}