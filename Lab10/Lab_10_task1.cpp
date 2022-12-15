#include "StdAfx.h"
#include <iostream>
#include <queue> 
#include <stack>
#include "time.h"
using namespace std;
int** G;
int* dist;
int radius=INT_MAX;
int dia = 0;
int BFSD(int size,int v)
{
	dist = new int [size];
   for (int i = 0; i < size; i++)
    dist[i] = -1;
	//const int size = 7;
  queue<int> Queue;
 
  Queue.push(v); 
  dist[v]=0;
 
  while (!Queue.empty())
  { 
    int v = Queue.front(); 
    Queue.pop();
    //cout << v << " ";
    for (int i = 0; i < size; i++)
    { 
      if (G[v][i] != 0  && dist[i] == -1)
      { // если вершина смежная и не обнаружена
        Queue.push(i); 
        dist[i] = dist[v]+G[v][i]; 
      }
    }
   // cout << node + 1 << " "; 
  }
  return 0;
}
int main(){
	setlocale(LC_ALL, "Russian");
	int size;
  cout << "Введите размер матрицы: ";
  cin >> size;
   G = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(sizeof(int) * size);
    }
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            G[i][j] = rand() % 2;
			
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            if (G[i][j] = G[j][i]) {
                G[i][j] = G[j][i];
            }
        }
    }
	for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j){
                    printf("%3d", G[i][j]);
            }
				printf("\n");
	}
	 
   cout << "Расстояния в графе: ";
  vector<int> Ekstrin;
  int Eks_max=0;
  int vEks_max=0;
  int vEks_min=10e4;
   for (int i = 0; i < size; i++) {
  BFSD(size, i);
  cout <<"\nРасстояние от "<< i <<" вершины: ";
  cout << "\n";
  Eks_max=0;
  for (int j = 0; j < size; j++) {
            cout <<"\nДо "<< j <<" вершины " << dist[j] << "";
			if(dist[j]>Eks_max)
			   Eks_max=dist[j];
  }
  Ekstrin.push_back(Eks_max);
  cout <<"\nМаксимальное расстояние: "<< Eks_max << "\n";
  cout << "\n";
 }
    for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if(Ekstrin[j]>vEks_max)
			   vEks_max=Ekstrin[j];
			if(Ekstrin[j]<vEks_min)
			   vEks_min=Ekstrin[j];
		}
	}
    cout << "\n";
  cout << "Радиус графа: "<< vEks_min<<"\n";
  cout << "Диаметр графа: "<< vEks_max<<"\n";
  cout << "\nПереферийные вершины графа: ";
  int temp = Ekstrin.size();
  for(int i=0;i<temp;i++){
	 // cout << Ekstrin[i] << " ";
	  if(Ekstrin[i]==vEks_max)
		  cout << i << " ";
  }
   cout << "\nЦентральные вершины графа: ";
   for(int i=0;i<temp;i++){
	 // cout << Ekstrin[i] << " ";
	  if(Ekstrin[i]==vEks_min)
		  cout << i << " ";
  }
   cout << "\n";
}
