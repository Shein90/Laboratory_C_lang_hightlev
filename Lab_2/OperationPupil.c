#include "MyHeader.h"

// изменение запсиси ученика
void EditPupil(Pupil* PupilPtr, int numOfStr)
{
	printf("\n");
	printf("Введите фамилию: ");
	scanf("%s", &(PupilPtr + numOfStr)->surName);
	printf("Введите количество оценок: ");
	scanf("%d", &(PupilPtr + numOfStr)->numberMark);
	(PupilPtr + numOfStr)->marks = (int*)malloc((PupilPtr + numOfStr)->numberMark);
	(PupilPtr + numOfStr)->middleMark = 0;
	for (int j = 0; j < (PupilPtr + numOfStr)->numberMark; j++)
	{
		printf("Введите оценку: ");
		scanf("%d", &(PupilPtr + numOfStr)->marks[j]);
		(PupilPtr + numOfStr)->middleMark += (PupilPtr + numOfStr)->marks[j];
	}
	(PupilPtr + numOfStr)->middleMark /= (PupilPtr + numOfStr)->numberMark;
	(PupilPtr + numOfStr)->isFull = 1;
	printf("\n");
	system("cls");
	printf("Запись успешно изменена!\n");
}

// очистка записи ученика
int CleanPupil(Pupil* PupilPtr, int numOfStr)
{
	if ((PupilPtr + numOfStr)->isFull == 0)
	{
		return -1;
	}
	memset((PupilPtr + numOfStr), 0, sizeof(Pupil));//заполняет указанный элемент нулями
	return 1;
}

//удаление записи ученика
void DeletePupil(Pupil* PupilPtr, int numOfStr)
{
	int i = numOfStr;
	for (; i < numOfPupil - 1; i++)
	{
		*(PupilPtr + i) = *(PupilPtr + i + 1);
	}
	numOfPupil--;
	CleanPupil(PupilPtr, i);
	system("cls");
	printf("Запись успешно удалена!\n");
}