#include <vector>
#include "Windows.h"
#include <fstream>
#include <time.h>
#include <iostream>
using namespace std;

void bot() {
	int zader;
	system("cls");
	cout << "Agent speed(optimal 300): ";
	cin >> zader;

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

	maze2[str][stl] = 4;
	maze2[str][stl + 1] = 253;
	stl++;
	system("cls");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << maze2[i][j] << " ";
		cout << endl;
	}

	int startTime = clock();
	while (TRUE)
	{
			while ((maze2[str - 1][stl] == 32) || (maze2[str + 1][stl] == 32) || (maze2[str][stl - 1] == 32) || (maze2[str][stl + 1] == 32))
			{
				if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
				if (maze2[str][stl + 1] == 32) {//vpravo
					maze2[str][stl + 1] = 253;
					maze2[str][stl] = 4;
					stl++;
					system("cls");
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
							cout << maze2[i][j] << " ";
						cout << endl;
					}
					Sleep(zader);
				}
				if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
				if (maze2[str - 1][stl] == 32) {//vverh
					maze2[str - 1][stl] = 253;
					maze2[str][stl] = 4;
					str--;
					system("cls");
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
							cout << maze2[i][j] << " ";
						cout << endl;

					}
					Sleep(zader);
				}
				if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
				if (maze2[str + 1][stl] == 32) {//vniz
					maze2[str + 1][stl] = 253;
					maze2[str][stl] = 4;
					str++;
					system("cls");
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
							cout << maze2[i][j] << " ";
						cout << endl;
					}
					Sleep(zader);
				}
				if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
				if (maze2[vhod][0] != maze2[str][stl]) {//vlevo
					if (maze2[str][stl - 1] == 32) {
						maze2[str][stl - 1] = 253;
						maze2[str][stl] = 4;
						stl--;
						system("cls");
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
								cout << maze2[i][j] << " ";
							cout << endl;
						}
					}
					Sleep(zader);
				}
		}
			if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
			if ((maze2[str - 1][stl] != 32) && (maze2[str + 1][stl] != 32) && (maze2[str][stl - 1] != 32) && (maze2[str][stl + 1] != 32)) {
				while (TRUE) {
					if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
					if ((maze2[str - 1][stl] == 32) || (maze2[str + 1][stl] == 32) || (maze2[str][stl - 1] == 32) || (maze2[str][stl + 1] == 32)) { break; }
					if (maze2[str][stl + 1] == 4) {//vpravo
						maze2[str][stl + 1] = 253;
						maze2[str][stl] = 3;
						stl++;
						system("cls");
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
								cout << maze2[i][j] << " ";
							cout << endl;
						}
						Sleep(zader);
					}
					if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
					if ((maze2[str - 1][stl] == 32) || (maze2[str + 1][stl] == 32) || (maze2[str][stl - 1] == 32) || (maze2[str][stl + 1] == 32)) { break; }
					if (maze2[str - 1][stl] == 4) {//vverh
						maze2[str - 1][stl] = 253;
						maze2[str][stl] = 3;
						str--;
						system("cls");
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
								cout << maze2[i][j] << " ";
							cout << endl;
						}
						Sleep(zader);
					}
					if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
					if ((maze2[str - 1][stl] == 32) || (maze2[str + 1][stl] == 32) || (maze2[str][stl - 1] == 32) || (maze2[str][stl + 1] == 32)) { break; }
					if (maze2[str + 1][stl] == 4) {//vniz
						maze2[str + 1][stl] = 253;
						maze2[str][stl] = 3;
						str++;
						system("cls");
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
								cout << maze2[i][j] << " ";
							cout << endl;
						}
						Sleep(zader);
					}
					if (maze2[str][stl] == maze2[vihod][n - 1]) { break; }
					if ((maze2[str - 1][stl] == 32) || (maze2[str + 1][stl] == 32) || (maze2[str][stl - 1] == 32) || (maze2[str][stl + 1] == 32)) { break; }
					if (maze2[str][stl - 1] == 4) {//vlevo
						maze2[str][stl - 1] = 253;
						maze2[str][stl] = 3;
						stl--;
						system("cls");
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
								cout << maze2[i][j] << " ";
							cout << endl;
						}
						Sleep(zader);
					}
					if ((maze2[str - 1][stl] == 32) || (maze2[str + 1][stl] == 32) || (maze2[str][stl - 1] == 32) || (maze2[str][stl + 1] == 32)) { break; }
				}
			}
		if (maze2[str][stl] == maze2[vihod][n - 1]) {
			int endTime = clock();
			double time = (endTime - startTime) / 1000;
			break;
		}
	}
	system("pause >> NUL");
	system("cls");
	cout << "---------------Statistic---------------\n" << "Time to comlete the maze: " << time << "\nSize maze: " << n;
	system("pause >> NUL");
}