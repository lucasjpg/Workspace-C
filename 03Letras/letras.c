/*
 * letras.c
 *
 *  Created on: 31 de ago. de 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i;
	char n[5];
	setbuf(stdout, NULL);
	for (i = 0; i < 5; i++) {
		printf("Informe uma letra: ");
		scanf(" %c", &n[i]);
	}
	for (i = 4; i >= 0; i--) {
		printf("%c\n", n[i]);
	}
	return EXIT_SUCCESS;
}
