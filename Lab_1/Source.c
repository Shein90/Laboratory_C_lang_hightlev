/*����� II. ������������ ������ � 1. ������� � 7.
  ������� ������� � ������ ���������� ��������� � �������� �� �� �����������������
  � ��� �� ���������, �������� "aaaaa258xxx" �� "aaaaa0x102xxx".*/

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>

char* DigitSearch(char* p);
int ToNumber(char* p);
void Reverse(char str[]);
char* ToHex(int number, char* pos);

char digits[] = "0123456789ABCDEF";

char* DigitSearch(char* p) // ������� ������ ����� � ������ � ���������� ��������� �� ��.
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

int ToNumber(char* p) // �������� ������ �� ������� ���������                   
{                     // ���� ����� ���� ������ � ��������� �� ������ � �������������� ��������. 
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
	char str[10]; // ��������������� ���������
	char* posStart = pos;//��������� ������ �����

	for (i = 0; number != 0; number /= hex) // ������� � 16-������.
	{
		str[i++] = digits[number % hex];
	}
	str[i] = '\0';
	Reverse(str);

	len = i + 2; // ����� hex �������� � ������ (c ������ ���������� 0x).

	for (j = 0; *pos >= '0' && *pos <= '9'; pos++) // �������� ������ ���������� �����.
	{
		j++;
	}

	len -= j; // �� ������� ��������� ���������� ��������� � ������ (�������� ����� hex � ���������� ������).


	for (; *pos != '\0'; pos++); // ���� � ����� ������
	pos--;                       // ��� ���������� ���������.

	for (pos += len, *pos = '\0'; pos != posStart; pos--)
	{
		*pos = *(pos - len);
	}

	*pos = '0';   // ����������� "0x"
	pos++;
	*pos = 'x';

	for (pos++, i = 0; str[i] != '\0'; pos++, i++) // ���������� ������ hex-�����.
	{
		*pos = str[i];
	}
	return pos;
}

void Reverse(char str[])
{
	int i, j;
	char tmp;
	for (j = 0; str[j] != '\0'; j++);//������ � ����� ������
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

	char myStr[50] = "ap139xx425dsd5��78�896fgf";
	//  char myStr[50] = "apxxsd���fgf";
	int number;
	char* pos;

	printf("%s\n", myStr);

	pos = DigitSearch(myStr); // ��������� ���� �� � ������ ���� ���� �����.

	if (pos != NULL) // ���� ����, ��������� �������� ��������.
	{
		do
		{
			number = ToNumber(pos);	// ��������� ������ � ����� 0d.
			pos = ToHex(number, pos); // ��������� ����� 0d � ����� 0�, ���������� ��� � ������ � 
									  //���������� ��������� �� ����������� ������ ����� �����.
			pos = DigitSearch(pos); // ���������� ����� ����� ����� � ������, ���� ��� ����.

		} while (pos != NULL);

		printf("%s\n", myStr);
	}
	else
	{
		printf("����� � ������ �� �������!");
	}
	getchar();
}