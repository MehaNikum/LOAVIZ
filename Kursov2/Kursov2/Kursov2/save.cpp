#include <fstream>
using namespace std;
void save() {
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



	ofstream fout("save.txt");
	fout << n << " " << vhod << " " << vihod << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fout << maze[i][j] << " ";
		}
		fout << "\n";
	}
	fout.close();

}