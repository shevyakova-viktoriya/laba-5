#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0));

	int i, j, m = 5, Gsize = 0;
	int** G, *deg;

	printf("1 задание -> \n");

	deg = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		deg[i] = 0;
	}

	G = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++){
		G[i] = (int*)malloc(m * sizeof(int));
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			G[i][j] = 0;
		}
	}

	srand(12345678);
	for (i = 0; i < m; i++) {
		for (j = i+1; j < m; j++) {
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

	printf(" \n2 задание ->");

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				Gsize++;
			}
	    }
	}

	printf("\nРазмер графа = %d \n", Gsize / 2);

	cout << " \n3 задание ->";

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				deg[i]++;
			}
		}
		printf("\nСтепень вершины %d = %d", i, deg[i]);
	}

	printf("\n");

	for (i = 0; i < m; i++) {
		if (deg[i] == 0) printf("\nВершина %d изолированная", i);
		if (deg[i] == 1) printf("\nВершина %d концевая", i);
		if (deg[i] == m-1) printf("\nВершина %d доминирующая", i);
	}

	printf("\n");

	system("pause");
	return 1;
}