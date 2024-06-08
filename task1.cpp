#include <iostream>
#include <locale.h>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	ifstream Rf;
	Rf.open("R.txt");

	if (!Rf) {
		cout << "Не удалось открыть файл.";
		return 1;
	}

	int R;
	Rf >> R;
	Rf.close();
	int x = -999999;

	while (pow(3, x) <= R) {
		x++;
	}

	ofstream outp;
	outp.open("stepen.txt");
	outp << (x - 1);
	outp.close();
}