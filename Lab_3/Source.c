/* ����� II. ������������ ������ � 4. ������� � 3.
   ������������������ ���������� ��������� �����.
   ����� ������ ���������� ��������� ����� ���������� - ������������� ����:
   1 - �����,
   2 - ������� �����,
   3 - �������������,
   0 - ����� ������������������.
   ������� ���������� ����� �������� ����������.
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
        switch (*s++)// ���������� ��������� � ������� � ����������
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

// ������ ������� ������� ������.

//double Summ(char* s, ...)
//{
//    double sum = 0;
//    va_list ap;
//    va_start(ap, s);
//    while (*s != '0')
//    {
//        switch (*s++)// ���������� ��������� � ������� � ����������
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

    printf("����� ���������� �����: %.1f \n", Summ("113210", 5, 7, 4, 3.4, 2));
    _getche();
}


