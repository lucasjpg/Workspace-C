/*
 ============================================================================
 Name        : Laços de repetição​
 Author      : Lucas Juliano Possa Gomes
 Version     : Unica
 Copyright   : Lucas Corp
 Description : Faça um jogo de loteria! O programa sorteia 6 números (chamadas dezenas) de 1 a 60 e
               pede para o jogador escolher 6 números de 1 a 60. O programa compara os números escolhidos com os números sorteados,
               mostra as dezenas sorteadas, as dezenas escolhidas pelo jogador e mostra o prêmio conforme abaixo:
               	6 acertos: R$ 1.000.000,00
				5 acertos: R$ 250.000,00
				4 acertos: R$ 50.000,00
				3 acertos: nada.
				2 acertos: nada.
				1 acerto: nada.
               Obs.: validar os números digitados pelo jogador, ou seja, devem ser entre 1 e 60.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i, j, teste, rdn, n[6], usr[6], aux;
	setbuf(stdout, NULL);
	srand(time(0));
	// Cria vetor com 20 numeros aleatorios sem repeticao
	for (i = 0; i < 6; i++) {
		if (i == 0) {
			n[i] = 1 + rand() % 60;
		}
		else {
			teste = 0;
			while (teste == 0) {
				teste = 1;
				rdn = 1 + rand() % 60;
				for (j = 0; j < i; j++) {
					if (rdn == n[j]) {
						teste = 0;
						break;
					}
				}
			}
			n[i] = rdn;
		}
	}
	// Recebe o jogo do usuario
	for (i = 0; i < 6; i++) {
		if (i == 0) {
			do {
				printf("Informe o 1o numero do seu jogo (Entre 1 e 60): ");
				scanf(" %d", &usr[i]);
				if (usr[i] < 1 || usr[i] > 60) {
					printf("Numero invalido, deve estar entre 1 e 60.\n");
				}
			} while (usr[i] < 1 || usr[i] > 60);
		}
		else {
			teste = 0;
			while (teste == 0) {
				teste = 1;
				do {
					printf("Informe o %do numero do seu jogo (Entre 1 e 60): ", i+1);
					scanf(" %d", &rdn);
					if (rdn < 1 || rdn > 60) {
						printf("Numero invalido, deve estar entre 1 e 60.\n");
					}
				} while (rdn < 1 || rdn > 60);
				for (j = 0; j < i; j++) {
					if (rdn == usr[j]) {
						teste = 0;
						printf("Número repetido, informe um diferente.\n");
						break;
					}
				}
			}
			usr[i] = rdn;
		}
	}
	// Bubble Sort valores sorteados
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6 - i; j++) {
			if (n[j] > n[j+1]) {
				aux = n[j];
				n[j] = n[j+1];
				n[j+1] = aux;
			}
		}
	}
	// Bubble Sort valores informados pelo usuario
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6 - i; j++) {
			if (usr[j] > usr[j+1]) {
				aux = usr[j];
				usr[j] = usr[j+1];
				usr[j+1] = aux;
			}
		}
	}
	// Verifica a quantidade de numeros que o usuario acertou
	teste = 0;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (usr[i] == n[j]) {
				teste++;
			}
		}
	}
	printf("Numeros sorteados: \n");
	for (i = 0; i < 6; i++) {
		printf(" %d ", n[i]);
	}
	printf("\nNumeros jogados: \n");
	for (i = 0; i < 6; i++) {
		printf(" %d ", usr[i]);
	}
	printf("\n");
	switch (teste){
		case 0:
			printf("Nenhum acerto.");
			break;
		case 1:
			printf("Somente 1 acerto.");
			break;
		case 2:
			printf("Somente 2 acertos.");
			break;
		case 3:
			printf("Somente 3 acertos.");
			break;
		case 4:
			printf("4 acertos, levou R$50.000,00.");
			break;
		case 5:
			printf("5 acertos, levou R$250.000,00.");
			break;
		case 6:
			printf("6 acertos, levou R$1.000.000,00.");
			break;
	}
	return EXIT_SUCCESS;
}
