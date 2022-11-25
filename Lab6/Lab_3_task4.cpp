// Lab_3_task4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

const int n = 7;
const int m = 7;
#pragma comment(linker, "/STACK:1468006400")
int main()
{
	int adj_matrixTWO[2][2]={{0,1},
	                         {1,0}};
	int adj_matrixONE[3][3]={{0,1,1},
	                         {1,0,1},
	                         {1,1,0}};
	int adj_matrixRES[7][7];
	int  sizeMatrixOne = 3;
	for(int i = 0; i < 6; i++) {
 for (int j = 0; j < 6; j++) {
	 if((i/sizeMatrixOne==j/sizeMatrixOne)){
		 adj_matrixRES[i][j]=adj_matrixONE[i%sizeMatrixOne][j%sizeMatrixOne]; 
	 }
	 else{
		 if(adj_matrixTWO[i/sizeMatrixOne][j/sizeMatrixOne]==1){
           if((i%sizeMatrixOne)==(j%sizeMatrixOne)){
              adj_matrixRES[i][j]=1;
		   }
		   else
			   adj_matrixRES[i][j]=0;
		 }
		 else
			 adj_matrixRES[i][j]=0;
}
}
}
  for(int i = 0; i < 6; i++) {
   for (int j = 0; j < 6; j++) {
   printf(" %d ", adj_matrixRES[i][j]);
}
   printf("\n");
}


	return 0;
}

