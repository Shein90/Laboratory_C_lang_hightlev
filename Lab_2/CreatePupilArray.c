#include "MyHeader.h"

// ���� ������� ��������

Pupil* CreatePupilArray()
{
	printf("������� ���������� ��������: ");
	scanf("%d", &numOfPupil);
	return (Pupil*)calloc(numOfPupil, sizeof(Pupil)); // ����� ��������� �� ������� ������ ��� numOfPupil ��������� ���� Pupil.
}