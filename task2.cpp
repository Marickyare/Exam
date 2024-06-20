#include <fstream>
#include <iostream>
#include <locale>
#include <math.h>


using namespace std;

int calc(int *n) {
    if (*n> 99 && *n<1000) { return 3; }
    if (*n > 9 && *n <100) { return 2; }
    if (*n >= 0 && *n<10) { return 1; }
    return 0;
   }

int main()
{

    setlocale(LC_ALL, "Russian");

    fstream inp_stream;    
    inp_stream.open("start_file.txt", ios::in);                 //открытие файла для чтения

    if (inp_stream.fail()) {                                    //проверка открытия файла
        printf("К сожалению, файл открыть не удалось.");
    }
    int counter_f = 0;
    int counter_s = 0;
    int counter_t = 0;
    int n, x;
    while (!inp_stream.eof()) {
        inp_stream >> n;
        x = calc(&n);
        if (x == 1) { counter_f++; }
        if (x == 2) { counter_s++; }
        if (x == 3) { counter_t++; }
    }

    inp_stream.close();

    fstream out_stream;
    out_stream.open("start_file.txt", ios::app);

    out_stream << endl<< "Количество трехзначных чисел: " << counter_t <<endl;
    out_stream << "Количество двухзначных чисел: " << counter_s << endl;
    out_stream << "Количество однозначных чисел: " << counter_f << endl;

    out_stream.close();

}