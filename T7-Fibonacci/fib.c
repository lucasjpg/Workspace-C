/*
 * fib.c
 *
 *  Created on: 29 de out. de 2021
 *      Author: Lucas
 *
 *      Faça um programa que implementa a versão recursiva da sequência de Fibonacci.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
	if (n <= 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	}
	return fib(n-1) + fib(n-2);
}

int main(void) {
	int n;

	printf("Calculo do numero de Fibonacci (n >= 0).\n");
	do {
		printf("Informe o n-esimo termo desejado: ");
		scanf("%d", &n);
		if (n < 0) {
			printf("Este numero eh negativo, portanto invalido.\n");
		}
	} while (n < 0);

	printf("f(%d) = %d", n, fib(n));

	return EXIT_SUCCESS;
}
