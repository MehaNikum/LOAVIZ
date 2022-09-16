#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000
time_t start, end;


  
int main()
{
  int a[SIZE];
  
  for (int i = 0; i<SIZE; i++){
    if (i<=5000)
	a[i] = rand() % 201 - 100 + i;
	else
	a[i] = rand() % 201 - 100 - i;
   // printf(" %d ", a[i]);
  }
  start = clock();
  
  end = clock();
  double time = (end-start) / 1000.0;
  printf("Time: %lf", time);
            
  
  getchar();
  return 0;
}