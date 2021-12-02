/*
 ============================================================================
 Name        : Operadores matemáticos
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 03, exibir parte inteira e decimal de uma variável tipo float.
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
