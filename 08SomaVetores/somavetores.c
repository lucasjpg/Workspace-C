/*
 ============================================================================
 Name        : Estruturas Abstratas
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 12.

Para representar um vetor no R3, escreva um programa que calcule a soma de dois vetores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Vetor {
	float x;
	float y;
	float z;
};

int main(void) {
	struct Vetor v[2];
	setbuf(stdout, NULL);

	for (int i = 0; i < 2; i++) {
		printf("Informe a posicao X do vetor %d: ", i+1);
		scanf("%f", &v[i].x);
		printf("Informe a posicao Y do vetor %d: ", i+1);
		scanf("%f", &v[i].y);
		printf("Informe a posicao Z do vetor %d: ", i+1);
		scanf("%f", &v[i].z);
	}

	printf("\nA posicao da soma dos vetores eh: \n");
	printf("X = %.2f\n", v[0].x + v[1].x);
	printf("Y = %.2f\n", v[0].y + v[1].y);
	printf("Z = %.2f\n", v[0].z + v[1].z);

	return EXIT_SUCCESS;
}
