#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
int main()
{
	setlocale(LC_ALL, "ru");

	double min, max, summ=0;
	int n;
	double Arr[10000];
	int Arr1[10000];
	printf("¬ведите массив из: ");
	scanf_s("%d", &n);
	printf("¬ведите минимальный диапазон дл€ значений массива: ");
	scanf_s("%lf", &min);
	printf("¬ведите максимальный диапазон дл€ значений массива:");
	scanf_s("%lf", &max);

	for (int i = 0; i < n; i++) 
	{
		double randx = min + (rand() * (double)(max - min) / RAND_MAX);
		Arr[i] = randx; // присваиваем к i-му массиву рандомное число в диапазоне от min до max
	}

	for (int i = 0; i < n; i++)
	{
		printf("Arr[%d] = %.3lf\n", i, Arr[i]); // выводим получившийс€ массив из n
	}

	for (int i = 0; i < n; i++) 
	{
		summ = summ + Arr[i];
	}
	printf("\n —умма всех чисел массива равна: %.3lf\n", summ);

	for (int i = 0; i < n; i++) 
	{
		int a; // a - дл€ нахождени€ остатка, summ - сумма всех чисел массива
		a = (Arr[i] - (int)(Arr[i]))*1000;
		Arr1[i] = a;
		while (Arr1[i] % 10 == 0)
			Arr1[i] = Arr1[i] / 10;
		
		for (int j = 0; j < n; j++) 
		{
			if (i == abs(Arr1[j]))
			{
				summ = summ - fabs(Arr[i]);
			}
		}
		
	}
	printf("\n —умма чисел массива с учетом вычета: %.3lf\n", summ);

	return 0;
}