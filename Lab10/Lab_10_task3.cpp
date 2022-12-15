// Lab_10_task3.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <queue> 
#include <stack> 
#include "time.h"
using namespace std;
int** G;
int One,Two;
int size;
int* dist;
int radius=10e5;
int diametr = 0;
bool orien = false;
bool vzvesh = false;
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

int** generate(int size, int** G, bool vzvesh, bool orien){
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            G[i][j] = rand() % 2;
			if((G[i][j] == 1)&&(vzvesh==true))
	   G[i][j] = rand()%100 +1;
   else if(vzvesh==false)
	   G[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
			if(orien == true){
            if ((G[i][j] > 0)&&(G[j][i] > 0)) {
                G[j][i] = 0;
            }
			}
			else if(orien == false){
				if (G[i][j] = G[j][i]) {
                G[i][j] = G[j][i];
			}
			}
        }
    }
	for (size_t i = 0; i < size; ++i) {
                for (size_t j = 0; j < size; ++j){
                    printf("%3d", G[i][j]);
            }
				printf("\n");
	}
	return G;
}
int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "rus");
	cout << "Введите размер матрицы: ";
    cin >> size;
   G = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(sizeof(int) * size);
    }
	
	if(argc > 1)
	{

				if(strcmp(argv[1], "1") == 0){
		          cout << "Взвешенный граф\n";
				  vzvesh = true;
				 
				}
				else if(strcmp(argv[1], "0") == 0){
		          cout << "Невзвешенный граф\n";
				  vzvesh = false;
				  
				}
				if(strcmp(argv[2], "1") == 0){
		        cout << "Ориентированный граф\n\n";
				orien = true;
				  
				}
				else if(strcmp(argv[2], "0") == 0){
		          cout << "Неориентированный граф\n\n";
				 orien = false;
				}
				generate(size,G,vzvesh,orien);
	}
	else
	{
		cout << "Укажите аргументы. ";
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
	cout << '\n';
	getchar();
	return 0;
}

