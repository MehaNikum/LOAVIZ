#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	srand(time(NULL));
    int mass[6][5];
	int summa[6],s;
	for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            mass[i][j] = rand() % 100;
        }
    }
	for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%4d", mass[i][j]);
        }
        printf("\n");
    }
	printf("\n");
    // Сумма баллов--------------------------------------------------------
    printf("Amount: \n");
    for (int i = 0; i < 6; ++i) {
        s = 0;
        for (int j = 0; j < 5; ++j)
            s += mass[i][j];
        summa[i] = s;
        printf("%5d\n", summa[i]);
    }
	return 0;
}

