#include "MyHeader.h"

// ���� ������� ��������
void AddNewPupil(Pupil* PupilsPtr)
{
	printf("\n");
	for (int i = 0; i < numOfPupil; i++)
	{
		(PupilsPtr + i)->id = i; // �������������� ����������� id �������

		printf("������� ������� �������: ");
		scanf("%s", (PupilsPtr + i)->surName);

		printf("������� ���������� ������ �������: ");
		scanf("%d", &(PupilsPtr + i)->numberMark);

		(PupilsPtr + i)->marks = (int*)calloc((PupilsPtr + i)->numberMark, sizeof(int));
		(PupilsPtr + i)->middleMark = 0;
		for (int j = 0; j < ((PupilsPtr + i)->numberMark); j++)
		{
			printf("������� ������ (�� ����� ����� Enter): ");
			scanf("%d", &(PupilsPtr + i)->marks[j]);
			(PupilsPtr + i)->middleMark += (PupilsPtr + i)->marks[j]; //����� ��������� ������� ����.
		}

		(PupilsPtr + i)->middleMark /= (PupilsPtr + i)->numberMark;

		(PupilsPtr + i)->isFull = 1; // ���� ����������

		printf("\n");
	}
	system("cls");
	printf("������ ������� ���������!\n");
}