#include "MyHeader.h"

// ����������� ������� ���� ��������
void ShowPupils(Pupil* PupilsPtr)
{
	system("cls");
	for (int i = 0; i < numOfPupil; i++)
	{
		printf("\n");
		printf("ID = %d\n", (PupilsPtr + i)->id);
		printf("���: %s\n", (PupilsPtr + i)->surName);
		printf("������: ");
		for (int j = 0; j < (PupilsPtr + i)->numberMark; j++)
		{
			printf("%d ", (PupilsPtr + i)->marks[j]);
		}
		printf("������� ���: %lf", (PupilsPtr + i)->middleMark);
		printf("\n");
	}
	printf("\n");
}

// ����������� ������ ���������� �������
void ShowOnePupil(Pupil* PupilPtr, int numOfStr)
{
	system("cls");
	printf("\n");
	printf("ID = %d\n", (PupilPtr + numOfStr)->id);
	printf("���: %s\n", (PupilPtr + numOfStr)->surName);
	printf("������: ");
	for (int j = 0; j < (PupilPtr + numOfStr)->numberMark; j++)
	{
		printf("%d ", (PupilPtr + numOfStr)->marks[j]);
	}
	printf("������� ���: %lf", (PupilPtr + numOfStr)->middleMark);
	printf("\n");
}