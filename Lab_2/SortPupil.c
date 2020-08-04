#include "MyHeader.h"

// сортировка учеников

void SortPupils(Pupil* PupilsPtr)
{
	int answ;
	printf("Выберите вариант сортировки: ");
	printf("\n1 - по фамилии\n"
		"2 - по среднему баллу\n");
	scanf("%d", &answ);

	switch (answ)
	{
	case 1:
		qsort(PupilsPtr, numOfPupil, sizeof(Pupil), SortName); //указатель на начало массива, размер массива, размер элемента, и функция для сортировки
		system("cls");
		printf("Записи успешно отсортированны!\n");
		break;
	case 2:
		qsort(PupilsPtr, numOfPupil, sizeof(Pupil), SortMiddleMark);
		system("cls");
		printf("Записи успешно отсортированны!\n");
		break;
	default:
		printf("Выбран не верный вариант\n");
		break;
	}
}

int SortName(const void* arg1, const void* arg2)
{
	Pupil* one = (Pupil*)arg1;
	Pupil* two = (Pupil*)arg2;
	return strcmp(one->surName, two->surName); //вернёт 0-равны, >0 - one > two, <0 - one < two
}

int SortMiddleMark(const void* arg1, const void* arg2)
{
	Pupil* one = (Pupil*)arg1;
	Pupil* two = (Pupil*)arg2;
	return strcmp(&one->middleMark, &two->middleMark); //вернёт 0-равны, >0 - one > two, <0 - one < two
}

