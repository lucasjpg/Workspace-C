/*
 ============================================================================
 Name        : Laços de repetição
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 04, n-esimo numero de Fibonacci.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, n0, n1, i = 0;
	printf("Calculo do numero de Fibonacci (n >= 0).\n");
	do {
		printf("Informe o n-esimo termo desejado: ");
		scanf("%d", &n);
		if (n < 0) {
			printf("Este numero eh negativo, portanto invalido.\n");
		}
	} while (n < 0);
	while (i <= n) {
		if (i == 0) {
			n1 = 0;
		} else if (i == 1){
			n0 = n1;
			n1 = 1;
		} else {
			n1 = n1 + n0;
			n0 = n1 - n0;
		}
		i++;
	}
	printf("f(%d) = %d", n, n1);
    return EXIT_SUCCESS;
}
