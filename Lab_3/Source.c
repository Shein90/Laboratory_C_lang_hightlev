/* Часть II. Лабораторная работа № 4. Задание № 3.
   Последовательность переменных различных типов.
   Перед каждой переменной находится целая переменная - идентификатор типа:
   1 - целое,
   2 - длинное целое,
   3 - вещественнное,
   0 - конец последовательности.
   Функция возвращает сумму значений параметров.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <conio.h>

double Summ(char* s, ...)
{
    double sum = 0;
    int* p = &s + 1;
    while (*s != '0')
    {
        switch (*s++)// Извлечение параметра и переход к следующему
        {
        case '1':
        {
            sum += *((int*)p)++;
            break;
        }
        case '2':
        {
            sum += *((double*)p)++;
            break;
        }
        case '3':
        {
            sum += *((long*)p)++;;
            break;
        }
        }
    }
    return sum;
}

// Второй вариант решения задачи.

//double Summ(char* s, ...)
//{
//    double sum = 0;
//    va_list ap;
//    va_start(ap, s);
//    while (*s != '0')
//    {
//        switch (*s++)// Извлечение параметра и переход к следующему
//        {
//            case '1':
//            {
//                sum += va_arg(ap, int);
//                break;
//            }
//            case '2':
//            {
//                sum += va_arg(ap, double);
//                break;
//            }
//            case '3':
//            {
//                sum += va_arg(ap, long);
//                break;
//            }        
//        }
//    }
//    va_end(ap);
//    return sum;
//}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Сумма аргументов равна: %.1f \n", Summ("113210", 5, 7, 4, 3.4, 2));
    _getche();
}


