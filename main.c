#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int random_number(int min_num, int max_num);

void cenario(char *tipo); 
void floresta(char tela[][16], int x, int y);
void imprimir_cenario(char tela[][16], int x, int y);

int main() {
	char tipo[10];
	scanf("%c", &tipo);
	cenario("floresta");

	return  0;	
}

int random_number(int min_num, int max_num) {
	int result = 0, low_num = 0, hi_num = 0;

	if (min_num < max_num) {
		low_num = min_num;
		hi_num = max_num + 1; // include max_num in output
	} else {
		low_num = max_num + 1; // include max_num in output
		hi_num = min_num;
	}

	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}
 
void cenario(char tipo[]) {
	char cenario_atual[16][16];
	
	if (!strcmp(tipo, "floresta")) {
		int x = random_number(8, 16);
		int y = random_number(6, 8);

		floresta(cenario_atual, x, y);
		imprimir_cenario(cenario_atual, x, y);
	}
}

void floresta(char tela[16][16], int x, int y) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if ((i == 0) || (i == y - 1) || (j == 0) || (j == x - 1)) {
				tela[i][j] = '*';
			} else {
				tela[i][j] = '.';
			}
		}
	}	
}

void imprimir_cenario(char tela[16][16], int x, int y) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			printf("%c", tela[i][j]);
		}
		printf("\n");
	}
}
