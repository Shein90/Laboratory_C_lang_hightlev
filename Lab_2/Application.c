#include "MyHeader.h"

int Application()
{
	int article; // для выбора операций 
	int num; // хранит номер записи
	Pupil* Pupils;
	Pupil* find;

	Pupils = CreatePupilArray();
	system("cls"); // Очистить экран.
	do
	{
		printf("\nВведите номер операции:\n");
		printf(
			" 1  ввод записей учеников\n"
			" 2  отображение записей всех учеников\n"
			" 3  отображение записи отдельного ученика\n"
			" 4  изменение записи\n"
			" 5  очистка записи\n"
			" 6  удаление записи\n"
			" 7  поиск ученика по фамилии\n"
			" 8  сортировка учеников\n"
			" 9  поиск свободной для записи ячейки\n"
			"10  поиск минимального среднего балла среди учеников\n"

			" 0  ВЫХОД\n");
		printf("\n-> ");
		scanf("%d", &article);

		switch (article)
		{
		case 0:
			// Выход из программы
			article = 0;
			break;
		case 1:
			// Ввод записей учеников
			AddNewPupil(Pupils);
			break;
		case 2:
			// Для отображения записей всех учеников
			ShowPupils(Pupils);
			break;
		case 3:
			// Для отображения записи отдельного ученика
			printf("\nВведите номер элемента для отображения: ");
			scanf("%d", &num);
			ShowOnePupil(Pupils, num);
			break;
		case 4:
			// для изменения записи
			printf("\nВведите номер записи для изменения: ");
			scanf("%d", &num);
			EditPupil(Pupils, num);
			break;
		case 5:
			// для очистки записи
			printf("Введите номер записи для очистки: ");
			scanf("%d", &num);
			int res = CleanPupil(Pupils, num);
			if (res < 0)
			{
				system("cls");
				printf("Запись пуста!\n");
			}
			else
			{
				system("cls");
				printf("Запись обнулена!\n");
			}
			break;
		case 6:
			// для удаления записи
			printf("Введите номер записи для удаления: ");
			scanf("%d", &num);
			DeletePupil(Pupils, num);
			break;
		case 7:
			// для поиска
			find = PupilFind(Pupils);
			if (find)
			{
				printf("Результат поиска: \n");
				ShowOnePupil(Pupils, find - Pupils);
			}
			else
			{
				printf("Нет совпадений\n");
			}
			break;
		case 8:
			// для сортировки
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
				printf("Нет свободных записей");
			}
			break;
		case 10:
			num = MinimumMiddleMark(Pupils);
			ShowOnePupil(Pupils, num);
			break;
		default:
			printf("Неверный выбор\n");
			break;
		}

	} while (article != 0);

	free(Pupils);

	return 0;
}