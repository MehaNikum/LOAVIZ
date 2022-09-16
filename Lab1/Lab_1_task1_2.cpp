// Lab_1_task1.cpp: определяет точку входа для консольного приложения.
//
#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int main()
{
	srand(time(NULL));
	int Arr[15];
	
	for (int i = 0; i < 15; i++){
         Arr[i] = rand() % 100;
		 printf(" %d ",Arr[i]);
	}
	int max=Arr[0];
	int min=Arr[0];
	for (int i = 0; i < 15; i++){
         if(max<Arr[i])
			 max=Arr[i];
		 if(min>Arr[i])
			 min=Arr[i];

	}

	printf("\nAmmount: %d ",max - min);
	return 0;
}

