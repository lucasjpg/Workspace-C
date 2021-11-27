/*
 * desafio.c
 *
 *  Created on: 31 de ago. de 2021
 *      Author: Lucas
 *
 *      sorteie 20 numeros inteiros de 1 a 100 sem repeticao. Guarde em um vetor e pede ao usuario um inteiro entre 1 a 100
 *      procura o numero informado pelo usuario no vetor e se existir imprime a posicao, caso contrario informa que nao existe
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n[20], i, j, num, aux = 0, teste = 0, rdn;
	setbuf(stdout, NULL);
	srand(time(0));
	for (i = 0; i < 20; i++) {
		if (i == 0) {
			n[i] = rand() % 101;
		}
		else {
			teste = 0;
			while (teste == 0) {
				teste = 1;
				rdn = rand() % 101;
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
	for (i = 0; i < 20; i++) {
		printf(" %d ", n[i]);
	}
	do {
		printf("\nInforme um numero inteiro entre 1 e 100: ");
		scanf(" %d", &num);
		if (num < 0 || num > 100) {
			printf("Entre 1 a 100 nego veio!!");
		}
	} while (num < 0 && num > 100);
	for (i = 0; i < 20; i++) {
		if (num == n[i]) {
			printf("Posicao = %d", i);
			aux = 1;
			break;
		}
	}
	if (aux == 0) {
		printf("Valor nao existe no vetor");
	}
	return EXIT_SUCCESS;
}
