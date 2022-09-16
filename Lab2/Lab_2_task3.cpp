#include "StdAfx.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int num[100000];
#pragma comment(linker, "/STACK:1468006400")
int comp(const void *, const void *);
time_t start, end;
int main(void)
{
  int i;

  
  for(i=0; i<100000; i++) {
	  if(i<=50000)
	  num[i]=rand()% 1000 + 1 + i; 
	  else
      num[i]=rand()% 1000 + 1 - i; 
  }
  start = clock();
  qsort(num, 100000, sizeof(int), comp);
  end = clock();
  double time = (end-start) / 1000.0;
	printf("Time: %lf", time);
  

  return 0;
}

/* сравнение целых */
int comp(const void *i, const void *j)
{
  return *(int *)i - *(int *)j;
}