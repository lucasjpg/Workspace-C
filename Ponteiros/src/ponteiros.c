/*
 * ponteiros.c
 *
 *  Created on: 19 de out. de 2021
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int inteiro = 1;
	char caracter = 'A';
	float flutuante = 1.234;
	double longo = 1234.5678;

	int *ponteiro_int = &inteiro;
	char *pnt_char = &caracter;
	float *pnt_float = &flutuante;
	double *pnt_longo = &longo;

	printf("Quantidade de memoria ocupada pela variavel Inteiro (Bytes): %d\n", sizeof(inteiro));
	printf("Quantidade de memoria ocupada pela variavel Char: %d\n", sizeof(caracter));
	printf("Quantidade de memoria ocupada pela variavel Float: %d\n", sizeof(flutuante));
	printf("Quantidade de memoria ocupada pela variavel Double: %d\n", sizeof(longo));

	printf("Valor do ponteiro da variavel Inteiro: %p\n", ponteiro_int);
	printf("Valor do ponteiro da variavel Char: %p\n", pnt_char);
	printf("Valor do ponteiro da variavel Float: %p\n", pnt_float);
	printf("Valor do ponteiro da variavel Double: %p\n", pnt_longo);

	printf("Valor da variavel Inteiro: %d\n", *ponteiro_int);
	printf("Valor da variavel Char: %c\n", *pnt_char);
	printf("Valor da variavel Float: %f\n", *pnt_float);
	printf("Valor da variavel Double: %lf\n", *pnt_longo);

	printf("Valor do ponteiro da variavel ponteiro Inteiro: %p\n", &ponteiro_int);
	printf("Valor do ponteiro da variavel ponteiro Char: %p\n", &pnt_char);
	printf("Valor do ponteiro da variavel ponteiro Float: %p\n", &pnt_float);
	printf("Valor do ponteiro da variavel ponteiro Double: %p\n", &pnt_longo);

	printf("Quantidade de memoria da variavel ponteiro Inteiro (Bytes): %d\n", sizeof(&ponteiro_int));
	printf("Quantidade de memoria da variavel ponteiro Char: %d\n", sizeof(&pnt_char));
	printf("Quantidade de memoria da variavel ponteiro Float: %d\n", sizeof(&pnt_float));
	printf("Quantidade de memoria da variavel ponteiro Double: %d\n", sizeof(&pnt_longo));

	return EXIT_SUCCESS;
}
