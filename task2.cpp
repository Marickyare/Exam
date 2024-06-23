#include <iostream>
#include <locale.h>
using namespace std;

int uniq(int* arr, int N) {
	int co = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j=0; j < N; j++)
		{
			if (arr[i] == arr[j] && i != j) { 
				break; 
			}
			if (j == N-1) 
			{ co++; cout << "Уникальное число " << arr[i]<<endl; 
			}
		}
	}
	return co;
}


int main() {
	setlocale(LC_ALL, "Russian");

	const int N = 10;
	int arr[N];

	for (int i = 0; i < N; i++)
	{
		cout << "Введите " << i << "-й элемент массива: "; cin >> arr[i];
	}
	//uniq(arr, N);
	cout << "Количество уникальных чисел: " << uniq(arr, N);

}