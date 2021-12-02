/*
 ============================================================================
 Name        : Operadores relacionais e logicos, testes e condicoes​
 Author      : Lucas Juliano Possa Gomes
 Version     : Unica
 Copyright   : Lucas Corp
 Description : Faca um programa que leia os lados de um triangulo e informe qual o seu tipo:
               equilatero, isoceles ou escaleno. Os lados devem ser numeros inteiros, sem sinal.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a, b, c;
	printf("Voce deverah informar o comprimento de tres lados de um triangulo qualquer.\n");
	printf("Em seguida, este algoritmo ira retornar o tipo, equilatero, isoceles ou escaleno.\n");
	printf("Informe o lado A: ");
	scanf("%d", &a);
	printf("Informe o lado B: ");
	scanf("%d", &b);
	printf("Informe o lado C: ");
	scanf("%d", &c);
	if (a == b == c) {
		printf("Triangulo equilatero");
	} else if ((a != b) && (b != c)) {
		printf("Triangulo escaleno");
	} else {
		printf("Triangulo isoceles");
	}
	return EXIT_SUCCESS;
}
