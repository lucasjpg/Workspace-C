/*
 * lotofacil.c
 *
 *  Created on: 2 de set. de 2021
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n[15], i, j, k, aux, rdn, teste;
	setbuf(stdout, NULL);
	srand(time(0));
	for (k = 0; k < 40; k++) {
		// Cria vetor com 15 numeros aleatorios
		for (i = 0; i < 15; i++) {
			if (i == 0) {
				n[i] = 1 + rand() % 25;
			}
			else {
				teste = 0;
				while (teste == 0) {
					teste = 1;
					rdn = 1 + rand() % 25;
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
		for (i = 0; i < 15; i++) {
			for (j = 0; j < 15 - i; j++) {
				if (n[j] > n[j+1]) {
					aux = n[j];
					n[j] = n[j+1];
					n[j+1] = aux;
				}
			}
		}
		// Print vetor
		for (i = 0; i < 15; i++) {
			printf(" %d ", n[i]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
