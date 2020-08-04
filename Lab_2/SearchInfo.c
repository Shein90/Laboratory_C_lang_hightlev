#include "MyHeader.h"

// ����� ��������� ����������������� ����������
int EmptyStructure(Pupil* PupilsPtr)
{
	for (int i = 0; i < numOfPupil; i++)
	{
		if ((PupilsPtr + i)->isFull == 0)
		{
			return i;
		}
	}
	return -1;
}

// ����� ������������ �������� ����� ����� ��������
int MinimumMiddleMark(Pupil* PupilsPtr)
{
	double min = (PupilsPtr + 0)->middleMark;
	int pos = 0;
	for (int i = 1; i < numOfPupil; i++)
	{
		if ((PupilsPtr + i)->middleMark < min)
		{
			min = (PupilsPtr + i)->middleMark;
			pos = i;
		}
	}
	return pos;
}