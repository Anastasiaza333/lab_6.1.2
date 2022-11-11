#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void create(int* b, const int SIZE, const int i, const int HIGH, const int LOW);
void print(int* b, const int SIZE, const int i);
int sum(int* b, int suma, const int i, const int SIZE);
int Count(int* b, int count, const int i, const int SIZE);
void replace(int* b, const int i, const int SIZE);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));
    const int SIZE = 24;
    int b[SIZE];
    const int HIGH = 75;
    const int LOW = -15;
    int count = 0;
    int suma = 0;
    const int i = 0;

    create(b, SIZE, i, HIGH, LOW);
    cout << "b[24] = { ";
    print(b, SIZE, i);
    cout << "Сума елементів масиву, які задовольняють умову = "
        << sum(b, suma, i, SIZE) << endl;
    cout << "Кількість елементів у масиві, які задовольнять умову = "
        << Count(b, count, i, SIZE) << endl;
    cout << "Заміна елементів, які задовольняють умову, нулями: " << endl
        << "b[24] = { ";
    replace(b, i, SIZE);
    cout << " }" << endl;

    return 0;
}
void create(int* b, const int SIZE, const int i, const int HIGH, const int LOW)
{
    b[i] = LOW + rand() % (HIGH - LOW + 1);
    if (i < SIZE - 1)
        create(b, SIZE, i + 1, HIGH, LOW);

}
void print(int* b, const int SIZE, const int i)
{
    cout << b[i] << " ";
    if (i < SIZE - 1)
        print(b, SIZE, i + 1);
    else
        cout << " }" << endl;
    return;
}
int sum(int* b,int suma, const int i, const int SIZE)
{
    if (b[i] % 2 != 1 && b[i] < 0)
        suma += b[i];
    if (i < SIZE - 1)
        return sum(b,suma, i + 1, SIZE);
    else
        return suma;
}
int Count(int* b, int count, const int i, const int SIZE)
{
    if (i < SIZE)
    {
        if (b[i] % 2 != 1 && b[i] < 0)
        {
            count++;
            Count(b, count, i + 1, SIZE);
        }
        else
            Count(b, count, i + 1, SIZE);
    }
    else
        return count;
}
void replace(int* b, const int i, const int SIZE)
{
    if (i < SIZE)
    {
        if (b[i] % 2 != 1 && b[i] < 0)
        {
            b[i]= 0;
            cout << b[1]<< " ";
            replace(b,i + 1, SIZE);
        }
        else
        {
            cout << b[i] << " ";
            replace(b,i + 1, SIZE);
        }
    }
    else
        return;
}