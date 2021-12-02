/*
 ============================================================================
 Name        : Operadores matem�ticos
 Author      : Lucas Juliano Possa Gomes
 Version     : �nica
 Copyright   : Lucas Corp
 Description : Exerc�cio da aula 03, exibir parte inteira e decimal de uma vari�vel tipo float.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int inteiro;
	float numero, decimal;
	printf("Informe um valor real qualquer: ");
	scanf("%f", &numero);
	inteiro = numero;
	decimal = numero - inteiro;
	printf("Valor real = %f\nValor inteiro = %d\nValor decimal = %f", numero, inteiro, decimal);
	return EXIT_SUCCESS;
}
