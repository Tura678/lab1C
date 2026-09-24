#include <stdio.h> 
#include <math.h>
#include <windows.h> 
int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	double F; // Объявляем переменную
	double a, b, c;// Ещё объявляем переменные
	double StartX, EndX, dX;// Ещё объявляем переменные

	printf("Введите: \n"); // Выводим сообщение
	printf("\ta = "); scanf_s("%lf", &a); // Выводим больше сообщений и считываем значения переменных
	printf("\tb = "); scanf_s("%lf", &b); // Используем scanf_s для безопасного считывания значений 
	printf("\tc = "); scanf_s("%lf", &c); // другими словами Visual Studio ругается на scanf и не даёт нормально скомпилировать код
	printf("\tX нач. = "); scanf_s("%lf", &StartX);
	printf("\tX кон. = "); scanf_s("%lf", &EndX);
	printf("\tdX = "); scanf_s("%lf", &dX);
	if (dX <= 0)
{
    printf("Ошибка: dX должен быть больше нуля.\n"); // защита от "обезьяны с гранатой"
    return 1;
}
if (StartX > EndX)
    {
        printf("Ошибка: X нач. должен быть меньше или равен X кон.\n"); // защита от "обезьяны с гранатой"
        return 1;
    }
if (a == c)
    {
        printf("Ошибка: a и c не должны быть равны.\n"); // защита от "обезьяны с гранатой"
        return 1;
    }	

    long A = (long)a;
    long B = (long)b; // объявляем ещё переменные и присваиваем им значения, приведённые к типу long
    long C = (long)c;

    long result = (A | B) & ~(A | C); // добавляем побитовые операции для проверки целочисленности значений a, b и c

	for (double x = StartX; x <= EndX; x += dX)
	{
		if (x + 10 < 0 && b != 0)           // Вычисляем значение функции F, исходя из заданных условий
			F = a * (double)pow(x, 2) - c * x + b;
		else if (x + 10 > 0 && b == 0)
		{
            if (x == c)
            {
                printf("x = %.2f\tF не определена\n", x); // защита от "обезьяны с гранатой" чтобы не было деления на ноль
                continue;
            }
			F = (x - a) / (x - c);
		}
		else
		{
			F = -x / (a - c);
	    }
		 if (result != 0)
            printf("x = %.2f\tF = %.2f\n", x, F); // Выводим округленное значение с двумя знаками после запятой
        else
            printf("x = %.2f\tF = %.0f\n", x, F); // Выводим вещественное значение
	}
	return 0;    // Конец
}