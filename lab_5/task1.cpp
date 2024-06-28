#include <iostream>
#include <locale.h>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const int N  = 10;
	const int M = 2;
	int R;
	int arr[N];

	cout << "Введите число R: "; cin >> R;

	for (int i = 0; i < N; i++)
	{
		cout << "Введите "<< i<< "-й элемент массива: "; cin >> arr[i];
	}

	int max = 0;
	int x, y;

	for (int j1 = 0; j1 < N; j1++)
	{
		for (int j2 = j1+1; j2 < N; j2++)
		{
			if (abs(abs(arr[j1] - arr[j2]) - R) > max) { x = arr[j1]; y = arr[j2]; max = (abs(abs(arr[j1] - arr[j2]) - R)); }
		}
	}

	cout << x << "\t" << y;
}
