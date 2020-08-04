#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct Pupil
{
	unsigned int id;		
	char surName[30];		
	int numberMark;			
	int* marks;				
	double middleMark;		
	int isFull;				
};
typedef struct Pupil Pupil;

int numOfPupil;

// Прототипы функций
int Application(void);
Pupil* CreatePupilArray();
void AddNewPupil(Pupil* PupilsPtr);
void ShowPupils(Pupil* PupilsPtr);
void ShowOnePupil(Pupil* PupilPtr, int numOfStr);
void EditPupil(Pupil* PupilPtr, int numOfStr);
int CleanPupil(Pupil* PupilPtr, int numOfStr);
void DeletePupil(Pupil* PupilPtr, int numOfStr);
Pupil* PupilFind(Pupil* PupilPtr);
Pupil* Search(Pupil* PupilPtr, char* surnamePupil);
void SortPupils(Pupil* PupilsPtr);
int SortName(const void* arg1, const void* arg2);
int SortMiddleMark(const void* arg1, const void* arg2);
int EmptyStructure(Pupil* PupilsPtr);
int MinimumMiddleMark(Pupil* PupilsPtr);
