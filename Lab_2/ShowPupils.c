#include "MyHeader.h"

// Отображение записей всех учеников
void ShowPupils(Pupil* PupilsPtr)
{
	system("cls");
	for (int i = 0; i < numOfPupil; i++)
	{
		printf("\n");
		printf("ID = %d\n", (PupilsPtr + i)->id);
		printf("ФИО: %s\n", (PupilsPtr + i)->surName);
		printf("Оценки: ");
		for (int j = 0; j < (PupilsPtr + i)->numberMark; j++)
		{
			printf("%d ", (PupilsPtr + i)->marks[j]);
		}
		printf("Средний бал: %lf", (PupilsPtr + i)->middleMark);
		printf("\n");
	}
	printf("\n");
}

// отображение записи отдельного ученика
void ShowOnePupil(Pupil* PupilPtr, int numOfStr)
{
	system("cls");
	printf("\n");
	printf("ID = %d\n", (PupilPtr + numOfStr)->id);
	printf("ФИО: %s\n", (PupilPtr + numOfStr)->surName);
	printf("Оценки: ");
	for (int j = 0; j < (PupilPtr + numOfStr)->numberMark; j++)
	{
		printf("%d ", (PupilPtr + numOfStr)->marks[j]);
	}
	printf("Средний бал: %lf", (PupilPtr + numOfStr)->middleMark);
	printf("\n");
}