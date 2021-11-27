/*
 ============================================================================
 Name        : Laços de repetição
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 04, calculo fatorial.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, total, i = 1;
	printf("Calculo do fatorial de um numero n >= 0.\n");
	do {
		printf("Informe um numero inteiro positivo: ");
		scanf("%d", &n);
		if (n < 0) {
			printf("Este numero eh negativo, portanto invalido.\n");
		}
	} while (n < 0);
	if (n == 0) {
		printf("0! = 1");
	} else {
		total = n;
		while (i < n) {
			total *= (n - i);
			i++;
		}
		printf("%d! = %d", n, total);
	}
    return EXIT_SUCCESS;
}
