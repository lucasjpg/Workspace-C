/*
 ============================================================================
 Name        : La�os de repeti��o
 Author      : Lucas Juliano Possa Gomes
 Version     : �nica
 Copyright   : Lucas Corp
 Description : Exerc�cio da aula 04, funcao bi-variada  x2 + y2 com incrementos diferenciados.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x = 0;
	int y = -100;
	while (x < 100) {
		y = -100;
		while (y < 0) {
			y += 5;
			printf("f(%.2f, %d) = %.2f\n", x, y, x*x+y*y);
		}
		x += 2.5;
	}
    return EXIT_SUCCESS;
}
