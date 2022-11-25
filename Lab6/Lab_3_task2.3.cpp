#include "StdAfx.h"
#include <iostream>
#include <stdlib.h>
#include "Time.h"
using namespace std;
const int n = 6;
const int m = 6;
int x;
int y;
int main()
{
srand(time(NULL));
int adj_matrixONE[n][m];
int adj_matrixTWO[n][m];
int z[n];
for(int i = 1; i < n; i++) {
 for (int j = 1; j < n; j++) {
   adj_matrixONE[i][j] = rand()%2;

}
}

for(int i = 1; i < n; i++) {
 for (int j = 1; j < n; j++) {
  if(i == j){
   adj_matrixONE[i][j] = 0;

}
 if(adj_matrixONE[i][j] = adj_matrixONE[j][i]){
  adj_matrixONE[i][j] = adj_matrixONE[j][i];
}
 printf(" %d ", adj_matrixONE[i][j]);
}
	printf("\n");
}
printf("Add 1 verchiny: ");

scanf("%d",&x);

for(int i = 1; i < n; i++) {
 for (int j = 1; j < n; j++) {
   printf(" %d ", adj_matrixONE[i][j]);

}
 printf("\n");
}

for(int i = 1; i < n; i++) {
	if(x==i){
 for (int j = 1; j < n+1; j++) {
	 if(j==6){
		 adj_matrixONE[x][j]=1;
	 }
	printf(" %d ", adj_matrixONE[x][j]);

}
}
}
printf("\n\n");
for(int i = 1; i < n; i++) {
	if(x==i){
 for (int j = 1; j < n+1; j++) {
	 if(j==6){
		 adj_matrixONE[x][j]=1;
	 }
	printf(" %d \n", adj_matrixONE[x][j]);

}
}
}

return 0;
}