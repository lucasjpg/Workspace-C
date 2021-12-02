/*
 ============================================================================
 Name        : Operadores matemáticos
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 03, utilizar dois valores inteiros para realizar as operações básicas da matemática.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a, b;
	printf("Informe valor inteiro para A: ");
	scanf("%d", &a);
	printf("Informe valor inteiro para B: ");
	scanf("%d", &b);
	printf("Soma: %d + %d = %d\n", a, b, a+b);
	printf("Subtracao: %d - %d = %d\n", a, b, a-b);
	printf("Multiplicacao: %d * %d = %d\n", a, b, a*b);
	printf("Divisao: %d / %d = %d\n", a, b, a/b);
	return EXIT_SUCCESS;
}