#include "StdAfx.h"
#include <iostream>
#include <stack> 
#include "time.h"
using namespace std;
int** G;
int* dist;
int BFSD(int size,int v)
{
	
	//const int size = 7;
  stack<int> Stack;
 
  Stack.push(v); 
  dist[0]=0;
 
  while (!Stack.empty())
  { 
    int v = Stack.top(); 
    Stack.pop();
    //cout << v << " ";
    for (int i = 0; i < size; i++)
    { 
      if (G[v][i] == 1 && dist[i] == -1)
      { // если вершина смежная и не обнаружена
        Stack.push(i); 
        dist[i] = dist[v]+1; 
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
	/*for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j)
                    cout << G[i][j] << ' ';
                cout << endl;
            }*/
	 dist = new int [size];
  for (int i = 0; i < size; i++)
    dist[i] = -1;
   cout << "Расстояния в графе: ";
  int start = clock();
  BFSD(size, 0);
   int end = clock();
  
  for (int i = 0; i < size; i++) {
            cout <<"\nРасстояние до "<< i <<" вершины " << dist[i] << "";
        }
  double time = (end-start) / 1000.0;
	printf("Time: %lf", time);
}
