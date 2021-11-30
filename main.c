
/*
 ============================================================================
 Name        : Vetores e Matrizes
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 08.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	setbuf(stdout, NULL);
	srand(time(0));
	int aleatorio = 1 + rand() % 10;

	printf(" %d", aleatorio);

    return EXIT_SUCCESS;
}
