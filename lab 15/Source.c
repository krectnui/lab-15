#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	// 1
	int arr[100][100];
	int rows, columns, stroke, minValue = 100000;
	printf("Задайте кол-во строк двумерного массива: ");
	scanf("%d", &rows);
	printf("Задайте кол-во столбцов двумерного массива: ");
	scanf("%d", &columns);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = i + j;
			printf(" %2d ", arr[i][j]);
		}
		puts("\n");
	}

	printf("Правый верхний элемент таблицы равен %d", arr[0][columns - 1]);
	printf("\nВведите строку для поиска минимального элемента: ");
	scanf("%d", &stroke);
	for (int i = 0; i < columns; i++) {
		if (minValue > arr[stroke - 1][i]) {
			minValue = arr[stroke - 1][i];
		}
	}
	printf("\nМинимальное значение %d строки массива равен %d", stroke, minValue);

	int matrix[7][7];
	int transMatrix[7][7];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			matrix[i][j] = -10 + rand() % (10 - -10);
			printf(" %2d ", matrix[i][j]);
		}
		puts("\n");
	}
	puts("\n\n\n");
	int counter = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			transMatrix[i][j] = matrix[j][counter];
			printf(" %2d ", transMatrix[i][j]);
		}
		counter++;
		puts("\n");
	}
	int counterMean = 0;
	double mean = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			if (i == 3) {
				if (transMatrix[i][j] % 3 == 0) {
					counterMean++;
					mean += transMatrix[i][j];
				}
			}
		}
	}
	printf("Среднее арифметическое элементов четвёртой строки кратных трём рвавно %lf", mean / counterMean);

	int counterPair = 0;
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			if (transMatrix[i][j] == transMatrix[i][j - 1]) {
				counterPair++;
			}
			if (transMatrix[i][j] == transMatrix[i - 1][j]) {
				counterPair++;
			}
		}
	}
	printf("\n%d пар чисел найдено", counterPair);

	int maxElem = -1000000;
	int coordsMaxElemX, coordsMaxElemY;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (maxElem <= transMatrix[i][j]) {
				maxElem = transMatrix[i][j];
				coordsMaxElemX = i;
				coordsMaxElemY = j;
			}

		}
	}
	printf("\nМаксимальный элемент - %d. Расположен в точке с координатами (%d;%d)", maxElem, coordsMaxElemX, coordsMaxElemY);

	int shops[10][12];
	for (int i = 0; i < 10; i++) {
		printf("\nМагазин %d", i + 1);
		for (int j = 0; j < 12; j++) {
			shops[i][j] = 0 + rand() % (10000 - 0);
			printf("\n		Месяц %d - %2d ", j + 1, shops[i][j]);
		}
	}
	int shopId;
	printf("\nВведите номер магазина: ");
	scanf("%d", &shopId);
	double shopMean = 0;
	for (int i = 0; i < 12; i++) {
		shopMean += shops[shopId - 1][i];
	}
	shopMean /= 12;
	printf("\n\nСреднемесячный доход магазина %d составляет %lf", shopId, shopMean);
	return 0;
}