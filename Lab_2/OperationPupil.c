#include "MyHeader.h"

// ��������� ������� �������
void EditPupil(Pupil* PupilPtr, int numOfStr)
{
	printf("\n");
	printf("������� �������: ");
	scanf("%s", &(PupilPtr + numOfStr)->surName);
	printf("������� ���������� ������: ");
	scanf("%d", &(PupilPtr + numOfStr)->numberMark);
	(PupilPtr + numOfStr)->marks = (int*)malloc((PupilPtr + numOfStr)->numberMark);
	(PupilPtr + numOfStr)->middleMark = 0;
	for (int j = 0; j < (PupilPtr + numOfStr)->numberMark; j++)
	{
		printf("������� ������: ");
		scanf("%d", &(PupilPtr + numOfStr)->marks[j]);
		(PupilPtr + numOfStr)->middleMark += (PupilPtr + numOfStr)->marks[j];
	}
	(PupilPtr + numOfStr)->middleMark /= (PupilPtr + numOfStr)->numberMark;
	(PupilPtr + numOfStr)->isFull = 1;
	printf("\n");
	system("cls");
	printf("������ ������� ��������!\n");
}

// ������� ������ �������
int CleanPupil(Pupil* PupilPtr, int numOfStr)
{
	if ((PupilPtr + numOfStr)->isFull == 0)
	{
		return -1;
	}
	memset((PupilPtr + numOfStr), 0, sizeof(Pupil));//��������� ��������� ������� ������
	return 1;
}

//�������� ������ �������
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
	printf("������ ������� �������!\n");
}