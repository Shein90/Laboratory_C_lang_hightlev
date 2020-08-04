/*Часть II. Лабораторная работа № 1. Задание № 7.
  Функция находит в строке десятичные константы и заменяет их на шестнадцатеричные
  с тем же значением, например "aaaaa258xxx" на "aaaaa0x102xxx".*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>

char* DigitSearch(char* p);
int ToNumber(char* p);
void Reverse(char str[]);
char* ToHex(int number, char* pos);

char digits[] = "0123456789ABCDEF";

char* DigitSearch(char* p) // Находим первую цифру в строке и возвращаем указатель на неё.
{
	for (; *p != '\0'; p++)
	{
		if (*p >= '0' && *p <= '9')
		{
			return p;
		}
	}
	return NULL;
}

int ToNumber(char* p) // Движемся дальше от позиции вхождения                   
{                     // пока цифры идут подряд и переводим из строки в целоечисленное значение. 
	int sum = 0;

	for (; *p >= '0' && *p <= '9'; p++)
	{
		sum += (*p & 0x0f); // '1' == 49 == 0011 0001 & 0000 1111 == 0000 0001 == 1.
		sum *= 10;
	}
	sum /= 10;

	return sum;
}

char* ToHex(int number, char* pos)
{
	int i, j, len, hex = 16;
	char str[10]; // вспомогательный контейнер
	char* posStart = pos;//сохраняем начало числа

	for (i = 0; number != 0; number /= hex) // перевод в 16-ричную.
	{
		str[i++] = digits[number % hex];
	}
	str[i] = '\0';
	Reverse(str);

	len = i + 2; // длина hex значения в строке (c учетом добавления 0x).

	for (j = 0; *pos >= '0' && *pos <= '9'; pos++) // измеряем размер заменямого числа.
	{
		j++;
	}

	len -= j; // на сколько элементов произвести раздвижку в строке (разность между hex и заменяемым числом).


	for (; *pos != '\0'; pos++); // ушли в конец строки
	pos--;                       // для проведения раздвижки.

	for (pos += len, *pos = '\0'; pos != posStart; pos--)
	{
		*pos = *(pos - len);
	}

	*pos = '0';   // Прописываем "0x"
	pos++;
	*pos = 'x';

	for (pos++, i = 0; str[i] != '\0'; pos++, i++) // начинается запись hex-числа.
	{
		*pos = str[i];
	}
	return pos;
}

void Reverse(char str[])
{
	int i, j;
	char tmp;
	for (j = 0; str[j] != '\0'; j++);//уходим в конец строки
	j--;

	for (i = 0; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");

	char myStr[50] = "ap139xx425dsd5пп78к896fgf";
	//  char myStr[50] = "apxxsdппкfgf";
	int number;
	char* pos;

	printf("%s\n", myStr);

	pos = DigitSearch(myStr); // проверяем есть ли в строке хоть одно число.

	if (pos != NULL) // если есть, запускаем основной механизм.
	{
		do
		{
			number = ToNumber(pos);	// переводим строку в число 0d.
			pos = ToHex(number, pos); // переводим число 0d в число 0х, записываем его в строку и 
									  //возвращаем указатель на продолжение строки после числа.
			pos = DigitSearch(pos); // продолжаем поиск новых чисел в строке, пока они есть.

		} while (pos != NULL);

		printf("%s\n", myStr);
	}
	else
	{
		printf("Числа в строке не найдены!");
	}
	getchar();
}