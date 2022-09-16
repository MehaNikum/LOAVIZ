#include "stdafx.h"
#include <locale.h>

#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int sizeX,sizeY;
	cout <<"¬ведите размер массива: ";
	cin >> sizeX;
	cin >> sizeY;
	int **n = (int**)malloc(sizeof(int*)*sizeX);
	for(int i=0;i<sizeX;i++){
		n[i] = (int*)malloc(sizeof(int)*sizeY);
	}
	
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			n[i][j] = rand() % 100;

		}
	}
	cout << "¬ведЄнный массив: ";
	cout << "\n";
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++){
        printf(" %4d ",n[i][j]);
    }
		cout << "\n";
	}
	free(n);
	return 0;
}


