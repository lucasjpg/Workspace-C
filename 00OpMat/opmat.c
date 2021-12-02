/*
 ============================================================================
 Name        : Operadores matem�ticos
 Author      : Lucas Juliano Possa Gomes
 Version     : �nica
 Copyright   : Lucas Corp
 Description : Exerc�cio da aula 03, utilizar dois valores inteiros para realizar as opera��es b�sicas da matem�tica.
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