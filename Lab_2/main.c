/* ������������ ������ � 2. ������� � 9.
   ������� �.�., ���������� ������, ������, ������� ����.
*/
#include "MyHeader.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

	int control;
	control = Application();
	return control;
}