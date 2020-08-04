#include "MyHeader.h"

int Application()
{
	int article; // ��� ������ �������� 
	int num; // ������ ����� ������
	Pupil* Pupils;
	Pupil* find;

	Pupils = CreatePupilArray();
	system("cls"); // �������� �����.
	do
	{
		printf("\n������� ����� ��������:\n");
		printf(
			" 1  ���� ������� ��������\n"
			" 2  ����������� ������� ���� ��������\n"
			" 3  ����������� ������ ���������� �������\n"
			" 4  ��������� ������\n"
			" 5  ������� ������\n"
			" 6  �������� ������\n"
			" 7  ����� ������� �� �������\n"
			" 8  ���������� ��������\n"
			" 9  ����� ��������� ��� ������ ������\n"
			"10  ����� ������������ �������� ����� ����� ��������\n"

			" 0  �����\n");
		printf("\n-> ");
		scanf("%d", &article);

		switch (article)
		{
		case 0:
			// ����� �� ���������
			article = 0;
			break;
		case 1:
			// ���� ������� ��������
			AddNewPupil(Pupils);
			break;
		case 2:
			// ��� ����������� ������� ���� ��������
			ShowPupils(Pupils);
			break;
		case 3:
			// ��� ����������� ������ ���������� �������
			printf("\n������� ����� �������� ��� �����������: ");
			scanf("%d", &num);
			ShowOnePupil(Pupils, num);
			break;
		case 4:
			// ��� ��������� ������
			printf("\n������� ����� ������ ��� ���������: ");
			scanf("%d", &num);
			EditPupil(Pupils, num);
			break;
		case 5:
			// ��� ������� ������
			printf("������� ����� ������ ��� �������: ");
			scanf("%d", &num);
			int res = CleanPupil(Pupils, num);
			if (res < 0)
			{
				system("cls");
				printf("������ �����!\n");
			}
			else
			{
				system("cls");
				printf("������ ��������!\n");
			}
			break;
		case 6:
			// ��� �������� ������
			printf("������� ����� ������ ��� ��������: ");
			scanf("%d", &num);
			DeletePupil(Pupils, num);
			break;
		case 7:
			// ��� ������
			find = PupilFind(Pupils);
			if (find)
			{
				printf("��������� ������: \n");
				ShowOnePupil(Pupils, find - Pupils);
			}
			else
			{
				printf("��� ����������\n");
			}
			break;
		case 8:
			// ��� ����������
			SortPupils(Pupils);
			break;
		case 9:
			num = EmptyStructure(Pupils);
			if (num != -1)
			{
				ShowOnePupil(Pupils, num);
			}
			else
			{
				printf("��� ��������� �������");
			}
			break;
		case 10:
			num = MinimumMiddleMark(Pupils);
			ShowOnePupil(Pupils, num);
			break;
		default:
			printf("�������� �����\n");
			break;
		}

	} while (article != 0);

	free(Pupils);

	return 0;
}