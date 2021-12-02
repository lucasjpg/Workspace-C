/*
 * valida.c
 *
 *  Created on: 31 de ago. de 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n[500], i, j, rdn, aux, teste;
	setbuf(stdout, NULL);
	srand(time(0));
	for (int k = 0; k < 40; k++) {
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
		printf("\n");
	}
	return EXIT_SUCCESS;
}
