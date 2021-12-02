/*
 ============================================================================
 Name        : Laços de repetição​
 Author      : Lucas Juliano Possa Gomes
 Version     : Unica
 Copyright   : Lucas Corp
 Description : Faca um programa que sorteie 20 numeros inteiros de 1 a 100 e mostre-os em ordem crescente.
               Obs.: os numeros sorteados nao podem ter repeticao.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i, j, teste, rdn, n[20], aux;
	setbuf(stdout, NULL);
	srand(time(0));
	// Cria vetor com 20 numeros aleatorios sem repeticao
	for (i = 0; i < 20; i++) {
		if (i == 0) {
			n[i] = 1 + rand() % 100;
		}
		else {
			teste = 0;
			while (teste == 0) {
				teste = 1;
				rdn = 1 + rand() % 100;
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
	// Bubble Sort
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20 - i; j++) {
			if (n[j] > n[j+1]) {
				aux = n[j];
				n[j] = n[j+1];
				n[j+1] = aux;
			}
		}
	}
	for (i = 0; i < 20; i++) {
		printf(" %d ", n[i]);
	}
	return EXIT_SUCCESS;
}
