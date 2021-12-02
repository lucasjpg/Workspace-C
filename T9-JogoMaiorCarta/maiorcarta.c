/*
 ============================================================================
 Name        : Estruturas Abstratas
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 12.

Elabore em linguagem C um jogo de cartas onde o usuário deve jogar contra o computador
e o objetivo é que, a cada rodada, um jogador ganhe pontos ao jogar a maior carta.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DIM 52
#define MAO 5

typedef struct {
	int carta;
	char naipe;
} Baralho;

Baralho baralho[DIM];
Baralho mao_pc[MAO];
Baralho mao_pl[MAO];
int indices[DIM], pontos_pc, pontos_pl, jogadas_pl[MAO], jogadas_pc[MAO];

void cria_baralho();
void embaralha();
void apresenta();
void distribui_cartas();
void inicia_jogadas();
int retorna_indice_pl();
int retorna_indice_pc();
void carta(Baralho item);
void jogo();

int main(void) {
	char op;
	setbuf(stdout, NULL);

	cria_baralho();
	embaralha();
	apresenta();

	do {
		pontos_pc = 0; pontos_pl = 0;
		embaralha();
		distribui_cartas();
		inicia_jogadas();
		jogo();
		printf("\nDeseja jogar novamente? (S)im ou (N)ao: ");
		scanf(" %c", &op);
	} while (op == 's' || op == 'S');

	return EXIT_SUCCESS;
}

void jogo() {
	int i, jogada_pl, jogada_pc, valor_pl, valor_pc;
	for (i = 0; i < MAO; i++) {
		if (i % 2 == 0) {
			jogada_pc = retorna_indice_pc();
			printf("\nComputador jogou: ");
			carta(mao_pc[jogada_pc]);
			jogada_pl = retorna_indice_pl();
			printf("\nPlayer jogou: ");
			carta(mao_pl[jogada_pl]);
		} else {
			jogada_pl = retorna_indice_pl();
			printf("\nPlayer jogou: ");
			carta(mao_pl[jogada_pl]);
			jogada_pc = retorna_indice_pc();
			printf("\nComputador jogou: ");
			carta(mao_pc[jogada_pc]);
		}

		if (mao_pc[jogada_pc].carta == 14) {
			valor_pc = 1;
		} else {
			valor_pc = mao_pc[jogada_pc].carta;
		}
		if (mao_pl[jogada_pl].carta == 14) {
			valor_pl = 1;
		} else {
			valor_pl = mao_pl[jogada_pl].carta;
		}

		if (!(valor_pl == valor_pc)) {
			if (valor_pl > valor_pc) {
				pontos_pl += 1;
				if (mao_pc[jogada_pc].naipe == mao_pl[jogada_pl].naipe) {
					pontos_pl += 1;
				}
			} else {
				pontos_pc += 1;
				if (mao_pc[jogada_pc].naipe == mao_pl[jogada_pl].naipe) {
					pontos_pc += 1;
				}
			}
		}

		printf("\nPontuacao - PC: %d --- PL: %d", pontos_pc, pontos_pl);

		if (i < 4) {
			printf("\nProxima jogada em...");
			for (int j = 10; j > 0; j--) {
				if (j == 1) {
					printf(" %d...", j);
				} else {
					printf(" %d,", j);
				}
				sleep(1);
			}
			system("@cls||clear");
		} else {
			if (pontos_pl == pontos_pc) {
				printf("\nO jogo empatou\n");
			} else if (pontos_pl > pontos_pc) {
				printf("\nParabens, voce venceu!!\n");
			} else {
				printf("\nLooser, perdedoor.\n");
			}
		}
	}
}

void carta(Baralho item) {
	if (item.carta == 14) {
		printf("As de ");
	} else if (item.carta == 13) {
		printf("Rei de ");
	} else if (item.carta == 12) {
		printf("Dama de ");
	} else if (item.carta == 11) {
		printf("Valete de ");
	} else {
		printf("%d de ", item.carta);
	}
	if (item.naipe == 'o') {
		printf("Ouro\n");
	}
	if (item.naipe == 'p') {
		printf("Paus\n");
	}
	if (item.naipe == 'c') {
		printf("Copas\n");
	}
	if (item.naipe == 'e') {
		printf("Espada\n");
	}
}

// 8. Elabore uma função que escolhe aleatoriamente uma carta do computador a ser jogada e retorna o índice desta carta.
int retorna_indice_pc() {
	int indice;
	srand(time(0));
	do {
		indice = rand() % 5;
		if (!(jogadas_pc[indice] == indice)) {
			jogadas_pc[indice] = 10;
		}
	} while (jogadas_pc[indice] == indice);
	jogadas_pc[indice] = indice;

	return indice;
}

// 7. Elabore uma função para apresentar ao usuário quais são as suas cartas e retornar o índice da carta selecionada.
int retorna_indice_pl() {
	int indice, i;
	printf("\n\nSelecione uma das cartas: \n");
	for (i = 0; i < MAO; i++) {
		if (jogadas_pl[i] == -1) {
			if (mao_pl[i].carta == 14) {
				printf("[%d] - Carta: As de ", i+1);
			} else if (mao_pl[i].carta == 13) {
				printf("[%d] - Carta: Rei de ", i+1);
			} else if (mao_pl[i].carta == 12) {
				printf("[%d] - Carta: Dama de ", i+1);
			} else if (mao_pl[i].carta == 11) {
				printf("[%d] - Carta: Valete de ", i+1);
			} else {
				printf("[%d] - Carta: %d de ", i+1, mao_pl[i].carta);
			}
			if (mao_pl[i].naipe == 'o') {
				printf("Ouro\n");
			}
			if (mao_pl[i].naipe == 'p') {
				printf("Paus\n");
			}
			if (mao_pl[i].naipe == 'c') {
				printf("Copas\n");
			}
			if (mao_pl[i].naipe == 'e') {
				printf("Espada\n");
			}
		}
	}

	do {
		printf("Informe o indice [x] da carta a ser jogada: ");
		scanf("%d", &indice); indice--;
		if (indice < 0 || indice > 4) {
			printf("Carta invalida, informe uma carta entre 1 e 5 daquelas apresentadas acima.\n");
		} else if (jogadas_pl[indice] == indice) {
			printf("A carta ja foi utilizada, necessario informar uma das cartas apresentadas acima.\n");
		} else {
			jogadas_pl[indice] = 10;
		}
	} while (jogadas_pl[indice] == indice || indice < 0 || indice > 4);

	jogadas_pl[indice] = indice;

	return indice;
}

void inicia_jogadas() {
	int i;
	for (i = 0; i < MAO; i++) {
		jogadas_pl[i] = -1;
		jogadas_pc[i] = -1;
	}
}

// 6. Elabore um procedimento para distribuir 5 cartas para cada um dos jogadores.
void distribui_cartas() {
	int corta, i;
	srand(time(0));
	corta = 10 + rand() % DIM/3;
	for (i = 0; i < MAO; i++) {
		mao_pc[i].carta = baralho[indices[corta]].carta;
		mao_pc[i].naipe = baralho[indices[corta]].naipe;
		corta--;
		mao_pl[i].carta = baralho[indices[corta]].carta;
		mao_pl[i].naipe = baralho[indices[corta]].naipe;
		corta--;
	}
}

// 5. Elabore um procedimento para mostrar todo o baralho na tela.
void apresenta() {
	int i;
	printf("Sequencia do embaralhamento: \n");
	for (i = 0; i < DIM; i++) {
		printf("Carta: %d - Naipe: %c\n", baralho[indices[i]].carta, baralho[indices[i]].naipe);
	}
	for (i = 5; i > 0; i--) {
		printf("O jogo vai comecar em %d...\n", i);
		sleep(1);
	}
	system("@cls||clear");
}

// 4. Elabore um procedimento para embaralhar as cartas.
void embaralha() {
	int i, j, teste, rdn;
	srand(time(0));
	for (i = 0; i < DIM; i++) {
		if (i == 0) {
			indices[i] = rand() % DIM;
		}
		else {
			teste = 0;
			while (teste == 0) {
				teste = 1;
				rdn = rand() % DIM;
				for (j = 0; j < i; j++) {
					if (rdn == indices[j]) {
						teste = 0;
						break;
					}
				}
			}
			indices[i] = rdn;
		}
	}
}

// 3. Elabore um procedimento para criar o baralho
void cria_baralho() {
	int i, cont = 0;
	for (i = 2; i <= 14; i++) {
		baralho[cont].carta = i;
		baralho[cont].naipe = 'o';
		cont++;
		baralho[cont].carta = i;
		baralho[cont].naipe = 'p';
		cont++;
		baralho[cont].carta = i;
		baralho[cont].naipe = 'c';
		cont++;
		baralho[cont].carta = i;
		baralho[cont].naipe = 'e';
		cont++;
	}
}
