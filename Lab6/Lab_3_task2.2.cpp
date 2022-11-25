#include "StdAfx.h"
#include <iostream>
#include <stdlib.h>
#include "Time.h"
using namespace std;
const int n = 5;
const int m = 5;
int x;
int y;
int main()
{
srand(time(NULL));
int adj_matrixONE[n][m];
int adj_matrixTWO[n][m];
int z[n];
for(int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
   adj_matrixONE[i][j] = rand()%2;
}
}

for(int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
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
printf("Add 2 verchiny: ");

scanf("%d",&x);
scanf("%d",&y);
if (adj_matrixONE[x][y] == 1){
for(int i = 0; i < n; i++) {
	if (i!=x){
 for (int j = 0; j < n; j++) {
   if (j!=y){
	 adj_matrixTWO[i][j]=adj_matrixONE[i][j];
      }
    }
  }
}
for (int j = 0; j < n-1; j++){
	   
		if((adj_matrixTWO[j][x]!=1)&&(adj_matrixTWO[y][j]!=1))
	    z[j]=0;
   else
	    z[j]=1;
		
}
int adj_matrixRES[m-1][n-1];

printf("\n\n");
for(int j = 0; j < n-1; j++) {
	if (j==3)
    z[j]=0;
	//printf(" %d \n", z[j]);
}
for(int i = 0; i < n; i++) {
	if(i==n-1)
	{
		for(int j=0;j<n-1;j++)
			printf(" %d ", z[j]);
	}
	else
	if((x!=i)&&(y!=i)){
 for (int j = 0; j < n; j++) {
	 if((j==n-1))
		 printf(" %d ", z[i]);
	 if((x!=j)&&(y!=j)){
   printf(" %d ", adj_matrixTWO[i][j]);
	 }
}
 
 printf("\n");
}
}
}
else
printf("Verchiny ne svyazany\n");
printf("\n");
return 0;
}