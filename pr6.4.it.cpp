#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int Minimum(int* mas, const int size) {
    int min = 101;
    for (int i = 0; i < size; i++) {
        if (min > abs(mas[i]))
            min = abs(mas[i]);
    }
    return min;
}

void Create(int* mas, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        mas[i] = Low + rand() % (High - Low + 1);
}

void Print(int* mas, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << mas[i];
}

void Print_changed(int* mas, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << mas[i];
    }
}

void Add_even(int* npmas, int* mas, int np, const int size)
{
    int k = 2;
    for (int i = 0; i < size - np - 1; i++)
    {
        mas[i + 1] = mas[i + k]; k++;
    }
}

void Add_odd(int* mas, int* npmas, const int size, int np)
{
    int j = 0;
    if (size % 2 == 0) {
        for (int i = np; i < size - 1; i++)
        {
            mas[i] = npmas[j++];
        }
    }
    else
    {
        for (int i = np + 1; i < size; i++)
        {
            mas[i] = npmas[j++];
        }
    }
}

int Sum(int* mas, const int size) {
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        if (mas[i] == 0) {
            for (int j = i + 1; j < size; j++)
            {
                s += abs(mas[j]);
            }
            break;
        }
    }
    return s;
}

void Create_odd(int* mas, int* npmas, const int size, int& np) {
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 1) {
            npmas[np] = mas[i]; np++;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    int k = 2, s = 0, min = 0, n, np = 0;
    cout << "n = ";
    cin >> n;
    int* mas;
    int* npmas;
    npmas = new int[n / 2];
    mas = new int[n];
    int Low = -100;
    int High = 100;
    Create(mas, n, Low, High);
    Print(mas, n);
    cout << endl;
    min = Minimum(mas, n);
    cout << "Min = " << min << endl;
    int sum = Sum(mas, n);
    cout << "Sum = ";
    cout << sum << endl;
    Create_odd(mas, npmas, n, np);
    Add_even(npmas, mas, np, n);
    Add_odd(mas, npmas, n, np);
    Print_changed(mas, n);


    delete[]npmas;
    delete[]mas;

    return 0;

}