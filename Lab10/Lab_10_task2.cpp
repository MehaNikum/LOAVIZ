#include "StdAfx.h"
#include <iostream>
#include <queue> 
#include <stack> 
#include "time.h"
using namespace std;
int** G;
int radius=INT_MAX;
int diametr = 0;
int* dist;
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
			if(G[i][j] == 1)
	   G[i][j] = rand()%100 +1;
   else
	   G[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            if ((G[i][j] > 0)&&(G[j][i] > 0)) {
                G[j][i] = 0;
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
  stack<int> Centr;
  stack<int> Diametr;
  Diametr.push(10);
  Centr.push(10);
   for (int i = 0; i < size; i++) {
  BFSD(size, i);
  cout <<"\nРасстояние от "<< i <<" вершины: ";
  cout << "\n";
  for (int j = 0; j < size; j++) {
            cout <<"\nДо "<< j <<" вершины " << dist[j] << "";
			if(diametr<=dist[j]&&(dist[j]>0)){
				diametr=dist[j];
				
					Diametr.pop();
				    Diametr.push(i);
			
		}
			if((radius>=dist[j])&&(dist[j]>0)){
				radius=dist[j];
				
					Centr.pop();
				    Centr.push(i);
			
			}
  }
  cout << "\n";
 }
    cout << "\n";
  cout << "Радиус графа: "<< radius<<"\n";
  cout << "Диаметр графа: "<< diametr<<"\n";
  cout << "\nПереферийные вершины графа: ";
  while(!Diametr.empty()){
	  int temp = Diametr.top();
	  Diametr.pop();
	  cout << temp << " ";
  }
  cout << "\nЦентральные вершины графа: ";
   while(!Centr.empty()){
	  int temp = Centr.top();
	  Centr.pop();
	  cout << temp << " ";
  }
  }
