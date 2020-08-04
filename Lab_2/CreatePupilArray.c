#include "MyHeader.h"

// Ввод массива учеников

Pupil* CreatePupilArray()
{
	printf("Введите количество учеников: ");
	scanf("%d", &numOfPupil);
	return (Pupil*)calloc(numOfPupil, sizeof(Pupil)); // Вернёт указатель на область памяти для numOfPupil элементов типи Pupil.
}