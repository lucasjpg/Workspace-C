/*
 ============================================================================
 Name        : Vetores e Matrizes
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 08. Jogo da velha.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

const int n = 3;
const char p1 = 'X';
const char p2 = 'O';

void escrevejogo(char velha[n][n]);
void perguntaposicao(char velha[n][n], char player);
int verifica(char velha[n][n]);
void verificaplayer(int res);

int main(void) {
	char velha[3][3] = {{'A', 'A', 'A'}, {'A', 'A', 'A'}, {'A', 'A', 'A'}};
	int resultado = 0, teste, modo = 0, lc, cc;

	setbuf(stdout, NULL);
	srand(time(0));

	system("@cls||clear");
	printf("\n\nJogo da velha. Voce eh 'X', o computador eh 'O'.");
	printf("\nPara jogar basta informar a linha e coluna que deseja inserir a pedra.");
	printf("\nO computador ira jogar de modo aleatorio.\n");
	do {
		printf("\nSelecione o modo de jogo:\n");
		printf("1 - Player vs Player\n");
		printf("2 - Player vs Computer\n");
		scanf("%d", &modo);
		if (modo > 2 || modo < 1) {
			printf("\nInforme corretamente o modo de jogo, 1 ou 2.\n");
		}
	} while (modo > 2 || modo < 1);

	escrevejogo(velha);
	if (modo == 1) {
		do {
			printf("\n *** Player 1 *** \n");
			perguntaposicao(velha, p1);
			escrevejogo(velha);
			resultado = verifica(velha);
			verificaplayer(resultado);
			printf("\n *** Player 2 *** \n");
			perguntaposicao(velha, p2);
			escrevejogo(velha);
			resultado = verifica(velha);
			verificaplayer(resultado);
		} while (resultado == 0);
	} else {
		do {
			perguntaposicao(velha, p1);
			do {
				teste = 1;
				lc = rand() % 3;
				cc = rand() % 3;
				if (velha[lc][cc] == 'A') {
					velha[lc][cc] = 'O';
					teste = 0;
				}
			} while (teste);
			escrevejogo(velha);
			resultado = verifica(velha);
			if (resultado == 1) {
				printf("\nPARABENS, VOCE GANHOU!\n");
			} else if (resultado == 2) {
				printf("\nLOOSER!\n");
			} else if (resultado == 3) {
				printf("\nEMPATE!\n");
			}
		} while (resultado == 0);
	}
    return EXIT_SUCCESS;
}

void verificaplayer(int res) {
	if (res == 1) {
		printf("\nPLAYER 1 VENCEU!\n");
	} else if (res == 2) {
		printf("\nPLAYER 2 VENCEU!\n");
	} else if (res == 3) {
		printf("\nEMPATE!\n");
	}
}

int verifica(char velha[n][n]) {
	int i, j, contx = 0, conto = 0, conta = 1;
	// Testa diagonal principal
	for (i = 0; i < 3; i++) {
		if (velha[i][i] == 'X') {
			contx++;
		} else if (velha[i][i] == 'O') {
			conto++;
		}
	}
	if (contx == 3) {
		return 1;
	} else if (conto == 3) {
		return 2;
	} else { // Testa diagonal inversa
		contx = 0;
		conto = 0;
		for (i = 0; i < 3; i++) {
			if (i == 0) {
				if (velha[i][2] == 'X') {
					contx++;
				} else if (velha[i][2] == 'O') {
					conto++;
				}
			} else if (i == 1) {
				if (velha[i][i] == 'X') {
					contx++;
				} else if (velha[i][i] == 'O') {
					conto++;
				}
			} else {
				if (velha[i][0] == 'X') {
					contx++;
				} else if (velha[i][0] == 'O') {
					conto++;
				}
			}
		}
	}
	if (contx == 3) {
		return 1;
	} else if (conto == 3) {
		return 2;
	} else { // Testa linhas
		for (i = 0; i < 3; i++) {
			contx = 0;
			conto = 0;
			for (j = 0; j < 3; j++) {
				if (velha[i][j] == 'X') {
					contx++;
				} else if (velha[i][j] == 'O') {
					conto++;
				}
			}
			if (contx == 3) {
				return 1;
			} else if (conto == 3) {
				return 2;
			}
		}
	}
	// Testa colunas
	for (i = 0; i < 3; i++) {
		contx = 0;
		conto = 0;
		for (j = 0; j < 3; j++) {
			if (velha[j][i] == 'X') {
				contx++;
			} else if (velha[j][i] == 'O') {
				conto++;
			}
		}
		if (contx == 3) {
			return 1;
		} else if (conto == 3) {
			return 2;
		}
	}
	// Testa empate
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (velha[i][j] != 'A') {
				conta++;
			}
		}
	}
	if (conta == 9) {
		return 3;
	} else {
		return 0;
	}
}

void perguntaposicao(char velha[n][n], char player) {
	int l, c, teste;
	do {
		do {
			printf("\nInforme a linha que deseja jogar: ");
			scanf(" %d", &c);
			if (c > 3 || c < 1) {
				printf("Valor inválido, informe 1, 2 ou 3. ");
			}
		} while (c > 4 || c < 1);
		do {
			printf("Informe a coluna que deseja jogar: ");
			scanf(" %d", &l);
			if (l > 3 || l < 1) {
				printf("Valor invalido, informe 1, 2 ou 3. ");
			}
		} while (l > 4 || l < 1);
		teste = 1;
		if (velha[l-1][c-1] == 'A') {
			velha[l-1][c-1] = player;
			teste = 0;
		} else {
			printf("\nLinha e coluna invalida.\n");
		}
	} while (teste);
}

void escrevejogo(char velha[n][n]) {
	int i, j, linha = 1, coluna = 1, cl = 0, cc = 0;
	system("@cls||clear");
	printf("\n\n");
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++) {
			if (i == 0) {
				if (j == 1) {
					printf(" ");
				} else if (j % 2 != 0 || j == 0) {
					printf(" ");
				} else {
					printf("%d", linha);
					linha++;
				}
			} else if (j == 0) {
				if (i % 2 == 0) {
					printf(" ");
				} else {
					printf("%d", coluna);
					coluna++;
				}
			} else if (j == 1) {
				printf(" ");
			} else {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						printf("-");
					} else {
						printf("|");
					}
				} else {
					if (j % 2 == 0) {
						if (velha[cl][cc] != 'A') {
							printf("%c", velha[cl][cc]);
						} else {
							printf(" ");
						}
						cl++;
						if (cl > 2) {
							cl = 0;
							cc++;
						}
					} else {
						printf("|");
					}
				}
			}
		}
		printf("\n");
	}
}
