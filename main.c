#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number(int min_num, int max_num);
void tutorial(), 
	 mudar_cenario(char jogada, char tela[4][4], int conexoes[4]),
	 npc(char jogada, char tela[4][4]),
	 imprimir_cenario(char tela[4][4]);

char mundo[][4][4] = {
	{
		{'*', '*', '*', '*'},
		{'F', ' ', 'i', '*'},
		{'*', ' ', ' ', 'C'},
		{'*', '*', '*', '*'},
	},
	{
		{'*', '*', '*', '*'},
		{'*', ' ', ' ', '*'},
		{'C', ' ', ' ', 'F'},
		{'*', '*', 'z', '*'},
	},
	{
		{'*', '*', '*', '*'},
		{' ', ' ', ' ', 'C'},
		{'F', ' ', 'g', ' '},
		{'*', '*', '*', '*'},
	}
};

int conexoes_mundo[][4] = {
	{0, 1, 0, 2},
	{1, 1, 1, 0},
	{2, 0, 2, 2}
};

int main() {
	tutorial();

	int jogo = 1;
	char jogada;
	char cenario_atual[4][4] = {
		{'*', '*', '*', '*'},
		{'F', ' ', 'i', '*'},
		{'*', ' ', ' ', 'C'},
		{'*', '*', '*', '*'},
	};
	int conexoes_atual[4] = {0, 1, 0, 2};

	while (jogo == 1) {
		imprimir_cenario(cenario_atual);

		char jogada = 0;

		printf("Onde quer ir? ");
		scanf(" %c", &jogada);

		if ((jogada >= 'A') && (jogada <= 'Z')) {
			mudar_cenario(jogada, cenario_atual, conexoes_atual);
		} else if ((jogada >= 'a') && (jogada <= 'z')) {
			npc(jogada, cenario_atual);
		}
	}
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

void mudar_cenario(char jogada, char tela[4][4], int conexoes[4]) {
	int x, y;
	//Checando onde está a escolha no mapa
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (jogada == tela[i][j]) {
				x = i;
				y = j;
			}		
		}
	}
	//Atualizando o cenário e depois as conexões
	if (x == 0) {		//Se o caminho for na parte de cima do mapa
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) 
				tela[i][j] = mundo[conexoes[0]][i][j];
		}
		for (int i = 0; i < 4; i++) conexoes[i] = conexoes_mundo[conexoes[0]][i];
	} else if (y == 3) {//Se o caminho for na parte direita do mapa
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				tela[i][j] = mundo[conexoes[1]][i][j];
		}
		for (int i = 0; i < 4; i++) conexoes[i] = conexoes_mundo[conexoes[1]][i];
	} else if (x == 3) {//Se o caminho for na parte de baixo do mapa
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				tela[i][j] = mundo[conexoes[2]][i][j];
		}
		for (int i = 0; i < 4; i++) conexoes[i] = conexoes_mundo[conexoes[2]][i];
	} else if (y == 0) {//Se o caminho for na parte esquerda do mapa
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				tela[i][j] = mundo[conexoes[3]][i][j];
		}
		for (int i = 0; i < 4; i++) conexoes[i] = conexoes_mundo[conexoes[3]][i];
	}
}

void npc(char jogada, char tela[4][4]) {
	int ok = 0;
	for (int i = 0; i < 4; i++) {//Checa se o npc existe na tela atual
		for (int j = 0; j < 4; j++) {
			if (jogada == tela[i][j]) {
				ok = 1;
				break;
			}	
		}
	}

	if (ok == 1) {
		int escolha = 0;
		do {
			if (jogada == 'i') {
				printf("===============================\n");
				printf("O que deseja aventureiro?\n");
				printf("1)Curar-se \n2)Benção\n0)Sair\n");
				scanf("%d", &escolha);
				printf("===============================\n");

				if (escolha == 1) {
					//cura();
				} else if (escolha == 2) {
					//buff();			
				} else if (escolha == 0) {
					break;
				} else {
					printf("Escolha inválida.\n");
				}
			} else if (jogada == 'z') {
				printf("=========================================\n");
				printf("O que deseja aventureiro?\n");
				printf("1)Reparar itens\n2)Melhorar itens\n0)Sair\n");
				scanf("%d", &escolha);
				printf("=========================================\n");

				if (escolha == 1) {
					//reparar_itens();
				} else if (escolha == 2) {
					//melhorar_itens();
				} else if (escolha == 0) {
					break;
				} else {
					printf("Escolha inválida");
				}
			}
		} while (escolha != 0);
	} else {
		printf("Não tem esse personagem aqui.");
	}
}

void imprimir_cenario(char tela[4][4]) {
	printf("\n------\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j==0) {
				printf("|%c", tela[i][j]);
			} else if (j == 3) {
				printf("%c|", tela[i][j]);
			} else {
				printf("%c", tela[i][j]);
			}
		}
		printf("\n");
	}
	printf("------\n");
}

void tutorial() {
	printf("==================TUTORIAL======================\n");
	printf("Letras maiúsculas são saídas para uma nova tela.\nC = Cidade, F = Floresta, D = Dungeon\n");
	printf("Construções interagíveis são ilustradas por letras minúsculas.\nz = ferreiro, i = igreja\n");
	printf("Asterisco são construções sem importância, em cidades são casas, florestas podem ser árvores e arbustos, por exemplo.\n");
	printf("================================================\n\n");
};
