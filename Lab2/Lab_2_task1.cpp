// Lab_2_task1.cpp: определяет точку входа для консольного приложения.
//

#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "iostream"
#pragma comment(linker, "/STACK:1468006400")
using namespace std;
int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	time_t start, end; // объявляем переменные для определения времени выполнения

	int i=0, j=0, r;
	int a[4000][4000], b[4000][4000], c[4000][4000], elem_c;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	
	while(i<4000)
	{
		while(j<4000)
		{
			a[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i=0; j=0;
	while(i<4000)
	{
		while(j<4000)
		{
			b[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	start = clock();
	
	for(i=0;i<4000;i++)
	{
		for(j=0;j<4000;j++)
		{
			elem_c=0;
			for(r=0;r<4000;r++)
			{
				elem_c=elem_c+a[i][r]*b[r][j];
				c[i][j]=elem_c;
			}
		}
	}
	end = clock();
	double time = (end-start) / 1000.0;
	printf("Time: %lf", time);
}

