#include "MyHeader.h"

//����� ������� �� �������

Pupil* PupilFind(Pupil* PupilPtr)
{
	Pupil* pupilRes = NULL;
	char surnamePupil[30];
	printf("������� ������� �������: ");
	scanf("%s", surnamePupil);
	pupilRes = Search(PupilPtr, surnamePupil);
	return pupilRes;
}

Pupil* Search(Pupil* PupilPtr, char* surnamePupil)
{
	Pupil* ptr = PupilPtr;
	for (; ptr < PupilPtr + numOfPupil; ptr++)
	{
		if (ptr->isFull)
		{
			if (strcmp(ptr->surName, surnamePupil) == 0)
			{
				return ptr;
			}
		}
	}
	return NULL;
}