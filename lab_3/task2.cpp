#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	FILE* f_input, * f_output;
	f_input = fopen("pohod.txt", "r");

	if (f_input == 0) {
		printf("Не удалось открыть файл.");
		return 1;
	}
	int s, step;
	int days = 1;

	fscanf(f_input, "%d%d", &s, &step);
	fclose(f_input);

	s = s - step;

	while (s>0) {
		step = step * 0.15+step;
		s = s - step;
		days++;
	}
	printf("%d", days);

	f_output = fopen("dni.txt", "w");
	fprintf(f_output, "Количество дней, необходимых путешественнику для преодоления маршрута: %d", days);
	fclose(f_output);
}

