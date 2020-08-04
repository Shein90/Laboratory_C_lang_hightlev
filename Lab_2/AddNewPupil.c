#include "MyHeader.h"

// ввод записей учеников
void AddNewPupil(Pupil* PupilsPtr)
{
	printf("\n");
	for (int i = 0; i < numOfPupil; i++)
	{
		(PupilsPtr + i)->id = i; // автоматическое определение id ученика

		printf("Введите фамилию ученика: ");
		scanf("%s", (PupilsPtr + i)->surName);

		printf("Введите количество оценок ученика: ");
		scanf("%d", &(PupilsPtr + i)->numberMark);

		(PupilsPtr + i)->marks = (int*)calloc((PupilsPtr + i)->numberMark, sizeof(int));
		(PupilsPtr + i)->middleMark = 0;
		for (int j = 0; j < ((PupilsPtr + i)->numberMark); j++)
		{
			printf("Введите оценки (по одной через Enter): ");
			scanf("%d", &(PupilsPtr + i)->marks[j]);
			(PupilsPtr + i)->middleMark += (PupilsPtr + i)->marks[j]; //сразу формируем средний балл.
		}

		(PupilsPtr + i)->middleMark /= (PupilsPtr + i)->numberMark;

		(PupilsPtr + i)->isFull = 1; // флаг заполнения

		printf("\n");
	}
	system("cls");
	printf("Записи успешно добавлены!\n");
}