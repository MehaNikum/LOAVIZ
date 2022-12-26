//#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include "Windows.h"
#include <fstream>
#include <random>
#include <time.h>
//FILE* READ;
using namespace std;

void single() {
	int n = 0;
	int vhod = 0;
	int vihod = 0;
	ifstream fin("gen.txt");
	fin >> n;
	fin >> vhod;
	fin >> vihod;
	int** maze = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		maze[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> maze[i][j];
		}
	}
	fin.close();
	int m = n;
    auto maze2 = vector <vector<char>>(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        vector<char> row;
        for (int j = 0; j < n; j++) {
            row.push_back(maze[i][j]);
        }
        maze2[i] = row;
    }
    int str = vhod;
    int stl = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maze2[i][j] == 1)
                maze2[i][j] = 254;
            if (maze2[i][j] == 0)
                maze2[i][j] = '  ';
            if (maze2[i][j] == 5)
                maze2[i][j] = '  ';
            if (maze2[i][j] == 6)
                maze2[i][j] = '  ';
            if (maze2[i][j] == 8)
                maze2[i][j] = '  ';
        }
    }

    maze2[str][stl] = 253;
	system("cls");
    for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < m; j++)
			cout << maze2[i][j] << " ";
		cout << endl;
    }
	int click = 0;
	int startTime = clock();
	while (TRUE)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (maze2[str - 1][stl] == 32) {
				maze2[str - 1][stl] = 253;
				maze2[str][stl] = '  ';
				str--;
				system("cls");
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
						cout << maze2[i][j] << " ";
					cout << endl;
				}
				click++;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (maze2[str + 1][stl] == 32) {
				maze2[str + 1][stl] = 253;
				maze2[str][stl] = '  ';
				str++;
				system("cls");
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
						cout << maze2[i][j] << " ";
					cout << endl;
				}
				click++;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (maze2[str][stl + 1] == 32) {
				maze2[str][stl + 1] = 253;
				maze2[str][stl] = '  ';
				stl++;
				system("cls");
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
						cout << maze2[i][j] << " ";
					cout << endl;
				}
				if (maze2[str][stl] == maze2[vihod][n-1]) {
					int endTime = clock();
					double time = (endTime - startTime) / 100000000;
					break;
				}
				click++;
			}
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (maze2[vhod][0] != maze2[str][stl]) {
				if (maze2[str][stl - 1] == 32) {
					maze2[str][stl - 1] = 253;
					maze2[str][stl] = '  ';
					stl--;
					system("cls");
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
							cout << maze2[i][j] << " ";
						cout << endl;
					}
					click++;
				}
			}
		}
	}
	click++;
	for (int i = 0; i < n; i++) {
		delete[] maze[i];  // удаляем массив
	}
	system("pause >> NUL");
	system("cls");
	cout << "---------------Statistic---------------\n" << "Time to comlete the maze: " << time << "\nSize maze: " << n << "\nNumber of clicks: " << click;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 2);
	int box = dist(gen);
	switch(box) {
	case 0:
		MessageBox(NULL, L"Ну ты и черепаха!", L"Лабиринт пройден!", MB_ICONASTERISK | MB_OK);
		break;
	case 1:
		MessageBox(NULL, L"А быстрее нельзя?!", L"Лабиринт пройден!", MB_ICONASTERISK | MB_OK);
		break;
	case 2:
		MessageBox(NULL, L"Черепаха и то быстрее!", L"Лабиринт пройден!", MB_ICONASTERISK | MB_OK);
		break;
	}
	system("pause >> NUL");
}