#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, b, c;
    double Xnach, Xkon, dX;

    cout << "Введите a: ";
    cin >> a;

    cout << "Введите b: ";
    cin >> b;

    cout << "Введите c: ";
    cin >> c;

    cout << "Введите Xнач: ";
    cin >> Xnach;

    cout << "Введите Xкон: ";
    cin >> Xkon;

    cout << "Введите dX: ";
    cin >> dX;

    // Проверка шага
    if (dX <= 0)
    {
        cout << "Ошибка: dX должен быть больше нуля." << endl;
        return 1;
    }

    // Целые части a, b и c
    int A = static_cast<int>(a);
    int B = static_cast<int>(b);
    int C = static_cast<int>(c);

    // Определяем, как выводить F:
    // (A ИЛИ B) И НЕ(A ИЛИ C)
    int check = (A | B) & ~(A | C);

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << setw(12) << "x"
         << setw(15) << "F(x)" << endl;
    cout << "----------------------------------------" << endl;

    for (double x = Xnach; x <= Xkon; x += dX)
    {
        double F;

        // Первый случай
        if (x + 10 < 0 && b != 0)
        {
            F = a * x * x - c * x + b;
        }

        // Второй случай
        else if (x + 10 > 0 && b == 0)
        {
            // Проверяем знаменатель
            if (x == c)
            {
                cout << setw(12) << x
                     << setw(15) << "нет значения" << endl;
                continue;
            }

            F = (x - a) / (x - c);
        }

        // Остальные случаи
        else
        {
            // Проверяем знаменатель
            if (a == c)
            {
                cout << setw(12) << x
                     << setw(15) << "нет значения" << endl;
                continue;
            }

            F = -x / (a - c);
        }

        // Вывод в зависимости от условия задания
        cout << fixed << setprecision(3);
        cout << setw(12) << x;

        if (check != 0)
        {
            // Вещественное значение
            cout << setw(15) << F;
        }
        else
        {
            // Целое значение
            cout << setw(15) << static_cast<int>(F);
        }

        cout << endl;
    }

    cout << "----------------------------------------" << endl;

    return 0;
}