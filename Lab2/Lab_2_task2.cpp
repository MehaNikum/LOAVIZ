#define _CRT_SECURE_NO_WARNINGS 
#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Windows.h"
#include "iostream"

clock_t start, end;
void shellSort(int *num, int size)
{
	start = clock();
  int increment = 3;    
  while (increment > 0)  
  {
    for (int i = 0; i < size; i++)  
    {
      int j = i;          
      int temp = num[i];
      
      while ((j >= increment) && (num[j - increment] > temp))
      {  
        num[j] = num[j - increment]; 
        j = j - increment;       
      }
      num[j] = temp; 
    }
    if (increment > 1)      
      increment = increment / 2;
    else if (increment == 1)   
      break;  
  }
  
  end = clock();
}
int main()
{
  int m[10000];
  
  for (int i = 0; i<10000; i++) 
  {
	if (i<=5000)
    m[i]=rand()%100+1000 + i;
	else
    m[i]=rand()%100+1000 - i;
	
  }
  
  shellSort(m, 10000); 
 
  
  double time = (end-start) / 1000.0;
	printf("\nTime: %.5lf", time);

  getchar(); 
  return 0;
}


