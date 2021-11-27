/*
 ============================================================================
 Name        : Estruturas Abstratas
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 12.

Elabore um jogo de cartas em linguagem C que simule o jogo 21 de acordo com as especificações abaixo.

No jogo 21, o jogador solicita quantas cartas quiser ao computador na tentativa de somar 21 pontos.
Para as cartas abaixo do valete, soma-se o seu próprio valor. Para as cartas valete, dama, rei e ás, soma-se o valor 10.

No início do jogo o usuário deve informar o valor de uma aposta. Caso some os 21 pontos, ganha o dobro do valor apostado.
Caso some 19 ou 20 pontos, ganha o valor apostado. Caso contrário, perde o valor da aposta.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 52

// 2. Como variável global, declare o baralho com 52 cartas.
typedef struct {
	int carta;
	char naipe;
} Baralho;

Baralho baralho[DIM];
int indices[DIM];

void cria_baralho(); // 3. Elabore um procedimento para criar o baralho.
void embaralha();    // 4. Elabore um procedimento para embaralhar as cartas.
void apresenta();    // 5. Elabore um procedimento para mostrar o baralho na tela.
void mostra_carta(int cont);
void valor_carta(int *pontos, int cont);

int main(void) {
	char op;
	float aposta;
	int pontos = 0, cont = 0;
	setbuf(stdout, NULL);

	cria_baralho();
	embaralha();
	apresenta();
	printf("\n\nJogo de cartas 21, some 19, 20 ou 21 pontos para ganhar, se ultrapassar 21 perde tudo.\n");
	printf("Informe o valor que deseja apostar: ");
	scanf("%f", &aposta);

	// 6. A cada rodada deve-se apresentar na tela:
	do {
		printf("\nDeseja tirar uma carta do baralho (S)im? (N)ao para encerrar.");
		scanf(" %c", &op);
		if (op == 's' || op == 'S') {
			// a. O número da rodada.
			printf("Rodada numero %d\n", cont+1);
			// b. A carta dada ao usuário.
			mostra_carta(cont);
			// c. O valor da carta.
			valor_carta(&pontos, cont);
			// d. A soma de todas as cartas do usuário.
			printf("Voce esta com o total de %d pontos\n", pontos);

			if (pontos == 21) {
				printf("Parabens, voce venceu e recebe R$%.2f", aposta*2);
				op = 'x';
			} if (pontos > 21) {
				printf("Looser, perdeu tudo.");
				op = 'x';
			}

			cont++;
		} else {
			if (pontos == 20 || pontos == 19) {
				printf("Parabens, voce venceu e recebe R$%.2f", aposta);
				op = 'x';
			} else {
				printf("Desistiu, perdeu tudo.");
			}
		}
	} while (op == 's' || op == 'S');

	return EXIT_SUCCESS;
}

void valor_carta(int *pontos, int cont) {
	if (baralho[indices[cont]].carta >= 11) {
		printf("O valor da carta eh 10 pontos\n");
		*pontos += 10;
	} else {
		printf("O valor da carta eh %d pontos\n", baralho[indices[cont]].carta);
		*pontos += baralho[indices[cont]].carta;
	}
}

void mostra_carta(int cont) {
	if (baralho[indices[cont]].carta == 14) {
		printf("As de ");
	} else if (baralho[indices[cont]].carta == 13) {
		printf("Rei de ");
	} else if (baralho[indices[cont]].carta == 12) {
		printf("Dama de ");
	} else if (baralho[indices[cont]].carta == 11) {
		printf("Valete de ");
	} else {
		printf("%d de ", baralho[indices[cont]].carta);
	}
	if (baralho[indices[cont]].naipe == 'o') {
		printf("Ouro\n");
	}
	if (baralho[indices[cont]].naipe == 'p') {
		printf("Paus\n");
	}
	if (baralho[indices[cont]].naipe == 'c') {
		printf("Copas\n");
	}
	if (baralho[indices[cont]].naipe == 'e') {
		printf("Espada\n");
	}
}

void apresenta() {
	printf("Sequencia do embaralhamento: \n");
	for (int i = 0; i < DIM; i++) {
		printf("Carta: %d - Naipe: %c\n", baralho[indices[i]].carta, baralho[indices[i]].naipe);
	}
}

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

/* 1. Represente um baralho considerando o número da carta e o seu naipe.
 * Os naipes devem ser representados por um caracter (o – ouros, p – paus, c – copas, e – espadas).
 * Os números devem variar de 2 a 14, sendo 11 para o valete, 12 para a dama, 13 para o rei e 14 para o ás. */
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
