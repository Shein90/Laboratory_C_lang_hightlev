/* Лабораторная работа № 2. Задание № 9.
   Фамилия И.О., количество оценок, оценки, средний балл.
*/
#include "MyHeader.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	int control;
	control = Application();
	return control;
}