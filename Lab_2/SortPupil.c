#include "MyHeader.h"

// ���������� ��������

void SortPupils(Pupil* PupilsPtr)
{
	int answ;
	printf("�������� ������� ����������: ");
	printf("\n1 - �� �������\n"
		"2 - �� �������� �����\n");
	scanf("%d", &answ);

	switch (answ)
	{
	case 1:
		qsort(PupilsPtr, numOfPupil, sizeof(Pupil), SortName); //��������� �� ������ �������, ������ �������, ������ ��������, � ������� ��� ����������
		system("cls");
		printf("������ ������� ��������������!\n");
		break;
	case 2:
		qsort(PupilsPtr, numOfPupil, sizeof(Pupil), SortMiddleMark);
		system("cls");
		printf("������ ������� ��������������!\n");
		break;
	default:
		printf("������ �� ������ �������\n");
		break;
	}
}

int SortName(const void* arg1, const void* arg2)
{
	Pupil* one = (Pupil*)arg1;
	Pupil* two = (Pupil*)arg2;
	return strcmp(one->surName, two->surName); //����� 0-�����, >0 - one > two, <0 - one < two
}

int SortMiddleMark(const void* arg1, const void* arg2)
{
	Pupil* one = (Pupil*)arg1;
	Pupil* two = (Pupil*)arg2;
	return strcmp(&one->middleMark, &two->middleMark); //����� 0-�����, >0 - one > two, <0 - one < two
}

