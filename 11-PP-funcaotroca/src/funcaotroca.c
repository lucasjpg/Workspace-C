/*
 * funcaotroca.c
 *
 *  Created on: 26 de out. de 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>

void troca(int *x, int *y) {
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}

int main(void) {
	int a = 2, b = 7;
	printf("Antes da troca\n");
	printf("A = %d\nB = %d", a, b);
	troca(&a, &b);
	printf("\nDepois da troca\n");
	printf("A = %d\nB = %d", a, b);
	return EXIT_SUCCESS;
}
