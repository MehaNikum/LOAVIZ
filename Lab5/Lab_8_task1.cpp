#include "StdAfx.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "time.h"
#include "locale.h"
#include<conio.h>
#include "iostream"
using namespace std;
void main()
{
	setlocale(LC_ALL, "");
	const int size_y = 100;
	int i,j,v=0,k=0,m[size_y],m_i[size_y];
	int size;
	cout << "Введите количество вершин (больше 2): ";
	  cin >> size;
  char *in[size_y]; // Матрица инцендентности
  int **a = (int**)malloc(sizeof(int*)*size);
	for(int i=0;i<size;i++){
		a[i] = (int*)malloc(sizeof(int)*size);
	}
	srand(time(NULL));
	for(int i = 0; i < size; i++) {
 for (int j = 0; j < size; j++) {
   a[i][j] = rand()%2;
   if(a[i][j] == 1)
	   a[i][j] = rand()%100 +1;
   else
	   a[i][j] = 0;
}
}

for(int i = 0; i < size; i++) {
 for (int j = 0; j < size; j++) {
  if(i == j){
   a[i][j] = 0;

}
 if(a[i][j] = a[j][i]){
  a[i][j] = a[j][i];
}
}
}
  /*int a[size][size] = {
	  {0,6,10,0,0},
	  {6,0,16,4,12},
	  {10,16,0,0,7},
	  {0,4,0,0,0},
	  {0,12,7,0,0}
  };*/
  for(i=v=0; i<size; i++){
	  for(j=i+1; j<size; j++) {
		  if (a[i][j])
			  v++;  // Нашли v - число вершин
	  }
  }
  for(i=0; i<size; i++) { 
	  in[i] = (char *) malloc(v); 
	  memset(in[i], 0, v); 
  }
  for(i=k=0; i<size; i++){
	  for(j=i+1; j<size; j++){
		  if (a[i][j]) {
    in[i][k] = in[j][k] = a[i][j];
    k++; 
		  }
		 
			  
  }
  }
  cout<<"Исходная матрица смежности ";
 
  for (i=0;i<size;i++){ 
  m[i]=0; 
 
  }
  for (i=0;i<size;i++) 
    {
      printf("\n");
      m[i]=a[i][0];
	 // m_i[i]=in[i][0];
      for (j=0;j<size;j++)
       {
         if(a[i][j]>m[i])
		 m[i]=a[i][j];
         printf(" %3d ",a[i][j]);
       }
    }
  cout<<"\nИсходная матрица инцидентности ";
   printf("\n");
 for (i=0;i<size;i++) 
    {
      printf("\n");
      m_i[i]=in[i][0];
	 // m_i[i]=in[i][0];
      for (j=0;j<v;j++)
       {
         if(in[i][j]>m_i[i])
		 m_i[i]=in[i][j];
         printf(" %3d ",in[i][j]);
       }
    }
 for(int i=0;i<size;i++)
    {
		{

		}
    }
  cout<<"\nРазмер графа: "<< v;
 
  cout<<"\nИзолированные вершины: ";
  for(int i=0;i<size;i++)
    {
		int kol = 0;
         for (j=0;j<size;j++)
		 {
			 if(a[i][j]!=0) kol++;
		 }
		 if(kol==0) cout<<i+1<<" ";
    }
  cout<<"\nКонцевые вершины: ";
  for(int i=0;i<size;i++)
    {
		int kol = 0;
         for (j=0;j<size;j++)
		 {
			 if(a[i][j]!=0) kol++;
		 }
		 if(kol==1) cout<<i+1<<" ";
    }
  cout<<"\nДоминирующие вершины: ";
  for(int i=0;i<size;i++)
    {
		int kol = 0;
         for (j=0;j<size;j++)
		 {
			 if(a[i][j]!=0) kol++;
		 }
		 if(kol==size-1) cout<<i+1<<" ";
    }


  cout<<"\nИзолированные вершины c МИ: ";
  for(int i=0;i<size;i++)
    {
		int kol = 0;
         for (j=0;j<v;j++)
		 {
			 if(in[i][j]!=0) kol++;
		 }
		 if(kol==0) cout<<i+1<<" ";
    }
  cout<<"\nКонцевые вершины с МИ: ";
  for(int i=0;i<size;i++)
    {
		int kol = 0;
         for (j=0;j<v;j++)
		 {
			 if(in[i][j]!=0) kol++;
		 }
		 if(kol==1) cout<<i+1<<" ";
    }
  cout<<"\nДоминирующие вершины с МИ: ";
  for(int i=0;i<size;i++)
    {
		int kol = 0;
         for (j=0;j<v;j++)
		 {
			 if(in[i][j]!=0) kol++;
		 }
		 if(kol==size-1) cout<<i+1<<" ";
    }
  getch();
}