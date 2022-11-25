#include "StdAfx.h"
#include <iostream>
#include <stdlib.h>
#include "Time.h"
using namespace std;
const int n = 6;
const int m = 6;
int main()
{
srand(time(NULL));
int adj_matrixONE[n][m];
int adj_matrixTWO[n][m];
int adj_matrixRES[n][m];
for(int i = 0; i < n; i++) {
  for (int j = 0; j < n; j++) {
   adj_matrixONE[i][j] = rand()%2;
   adj_matrixTWO[i][j] = rand()%2;
}
}

for(int i = 1; i < n; i++) {
  for (int j = 1; j < n; j++) {
   if(i == j){
    adj_matrixONE[i][j] = 0;
    adj_matrixTWO[i][j] = 0;
}
   if(adj_matrixONE[i][j] = adj_matrixONE[j][i]){
    adj_matrixONE[i][j] = adj_matrixONE[j][i];
}
  if(adj_matrixTWO[i][j] = adj_matrixTWO[j][i]){
	adj_matrixTWO[i][j] = adj_matrixTWO[j][i];
}
 printf(" %d ", adj_matrixONE[i][j]);
}
	printf("\n");
}
printf("\n");
for(int i = 1; i < n; i++) {
 for (int j = 1; j < n; j++) {
  printf(" %d ", adj_matrixTWO[i][j]);
}
 printf("\n");
}
printf("\n");
printf("Result: \n");
for(int i = 1; i < n; i++) {
  for (int j = 1; j < n; j++) {
   if((adj_matrixONE[i][j]==1)&&(adj_matrixTWO[i][j]==1))
	   adj_matrixRES[i][j]=1;
   else
	   adj_matrixRES[i][j]=0;
   printf(" %d ", adj_matrixRES[i][j]);
}
  printf("\n");
}
return 0;
}