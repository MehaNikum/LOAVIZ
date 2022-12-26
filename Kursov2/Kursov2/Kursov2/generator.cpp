#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TIME.H"
#include "windows.h"
#include <random>
#include <fstream>
FILE* WRITE;

using namespace std;
int vhod;
int vihod;
int** genVhod(int** maze, int n, int m) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, n - 2);
    vhod = dist(gen);
    if (vhod % 2 == 0) { vhod++; }
    maze[vhod][0] = 0;
    return maze;
}
int** genVihod(int** maze, int n, int m) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, m - 2);
    vihod = dist(gen);
    if (vihod % 2 == 0) { vihod++; }
    maze[vihod][m - 1] = 0;
    return maze;
}
void generator() {
    int n, m;
    hello:
    system("cls");
    cout << "Enter the size of the maze (from 3 to 117; odd): ";
    cin >> n;
    if ((n % 2 == 0) || (n <= 2) || (n >= 118)) { goto hello; }
    m = n;
    int** maze = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        maze[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i % 2 == 0) || (j % 2 == 0)) {
                maze[i][j] = 1;
            }
            if ((i % 2 != 0) && (j % 2 != 0)) {
                maze[i][j] = 0;
            }
        }
    }
    genVhod(maze, n, m);
    float x = (n / 2) * (n / 2); //кол-во нечетных 0 в псевдографе
    int* random = new int[x];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 3);
    for (int y = 0; y < x; y++) {
        int choice = dist(gen);
        random[y] = choice;
    }
    cout << endl;
    int y = 0;
    int str = vhod;
    int stl = 1;
    maze[str][stl - 1] = 8;//vhod 8
    maze[str][stl] = 6;
    while (y < x) {
        switch (random[y]) {
        case 0:
            if (str - 2 >= 0) {//vverh
                if (maze[str - 2][stl] == 0) {
                    maze[str - 1][stl] = 6;
                    maze[str - 2][stl] = 6;
                    str = str - 2;
                    y++;
                    break;
                }
            }
        case 1:
            if (str + 2 <= n - 2) {//vniz
                if (maze[str + 2][stl] == 0) {
                    maze[str + 1][stl] = 6;
                    maze[str + 2][stl] = 6;
                    str = str + 2;
                    y++;
                    break;
                }
            }
        case 2:
            if (stl - 2 >= 0) {//vlevo
                if (maze[str][stl - 2] == 0) {
                    maze[str][stl - 1] = 6;
                    maze[str][stl - 2] = 6;
                    stl = stl - 2;
                    y++;
                    break;
                }
            }
        case 3:
            if (stl + 2 <= n - 2) {//vpravo
                if (maze[str][stl + 2] == 0) {
                    maze[str][stl + 1] = 6;
                    maze[str][stl + 2] = 6;
                    stl = stl + 2;
                    y++;
                    break;
                }
            }
        case 4:
            if (str - 2 >= 0) {//vverh
                if (maze[str - 2][stl] == 0) {
                    maze[str - 1][stl] = 6;
                    maze[str - 2][stl] = 6;
                    str = str - 2;
                    y++;
                    break;
                }
            }
        case 5:
            if (str + 2 <= n - 2) {//vniz
                if (maze[str + 2][stl] == 0) {
                    maze[str + 1][stl] = 6;
                    maze[str + 2][stl] = 6;
                    str = str + 2;
                    y++;
                    break;
                }
            }
        case 6:
            if (stl - 2 >= 0) {//vlevo
                if (maze[str][stl - 2] == 0) {
                    maze[str][stl - 1] = 6;
                    maze[str][stl - 2] = 6;
                    stl = stl - 2;
                    y++;
                    break;
                }
            }
        case 7:
            while (TRUE) {
                if (maze[str][stl - 1] == 8) { break; }

                if (str - 2 >= 0) {
                    if (maze[str - 2][stl] == 0) { break; }
                }
                if (str + 2 <= n - 2) {
                    if (maze[str + 2][stl] == 0) { break; }
                }
                if (stl - 2 >= 0) {
                    if (maze[str][stl - 2] == 0) { break; }
                }
                if (stl + 2 <= n - 2) {
                    if (maze[str][stl + 2] == 0) { break; }
                }
                if (maze[str - 1][stl] == 6) {//vverh
                    maze[str][stl] = 5;
                    maze[str - 1][stl] = 5;
                    str = str - 2;
                }
                if (str - 2 >= 0) {
                    if (maze[str - 2][stl] == 0) { break; }
                }
                if (str + 2 <= n - 2) {
                    if (maze[str + 2][stl] == 0) { break; }
                }
                if (stl - 2 >= 0) {
                    if (maze[str][stl - 2] == 0) { break; }
                }
                if (stl + 2 <= n - 2) {
                    if (maze[str][stl + 2] == 0) { break; }
                }
                if (maze[str + 1][stl] == 6) {//vniz
                    maze[str][stl] = 5;
                    maze[str + 1][stl] = 5;
                    str = str + 2;
                }
                if (str - 2 >= 0) {
                    if (maze[str - 2][stl] == 0) { break; }
                }
                if (str + 2 <= n - 2) {
                    if (maze[str + 2][stl] == 0) { break; }
                }
                if (stl - 2 >= 0) {
                    if (maze[str][stl - 2] == 0) { break; }
                }
                if (stl + 2 <= n - 2) {
                    if (maze[str][stl + 2] == 0) { break; }
                }
                if (maze[str][stl - 1] == 6) {//vlevo
                    maze[str][stl] = 5;
                    maze[str][stl - 1] = 5;
                    stl = stl - 2;
                }
                if (str - 2 >= 0) {
                    if (maze[str - 2][stl] == 0) { break; }
                }
                if (str + 2 <= n - 2) {
                    if (maze[str + 2][stl] == 0) { break; }
                }
                if (stl - 2 >= 0) {
                    if (maze[str][stl - 2] == 0) { break; }
                }
                if (stl + 2 <= n - 2) {
                    if (maze[str][stl + 2] == 0) { break; }
                }
                if (maze[str][stl + 1] == 6) {//vpravo
                    maze[str][stl] = 5;
                    maze[str][stl + 1] = 5;
                    stl = stl + 2;
                }
            }
        }
        if (maze[str][stl - 1] == 8) { break; }
    }
    genVihod(maze, n, m);
    cout << endl;
    WRITE = fopen("gen.txt", "w");
    fprintf(WRITE, "%3d ", n);
    fprintf(WRITE, "%3d ", vhod);
    fprintf(WRITE, "%3d ", vihod);
    fprintf(WRITE, "\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(WRITE, "%3d ",maze[i][j]);
        }
        fprintf(WRITE, "\n");
    }
    fclose(WRITE);
    for (int i = 0; i < n; i++) {
        delete[] maze[i];  // удаляем массив
    }
}