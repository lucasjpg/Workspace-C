/*
 ============================================================================
 Name        : Operadores relacionais e logicos, testes e condicoes​
 Author      : Lucas Juliano Possa Gomes
 Version     : Unica
 Copyright   : Lucas Corp
 Description : Implemente bhaskara.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float a, b, c, D, x1, x2;
	printf("Informe os coeficientes a, b e c de uma funcao de segundo grau.\n");
	printf("Em seguida, este algoritmo ira retornar as duas raizes da equacao, utilizando a formula de Bhaskara.\n");
	printf("Coeficiente A: ");
	scanf("%f", &a);
	printf("Coeficiente B: ");
	scanf("%f", &b);
	printf("Coeficiente C: ");
	scanf("%f", &c);
	D = pow(b,2)-4*a*c;
	if (D < 0) {
		printf("Raizes imaginarias");
	} else if (D > 0) {
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		printf("Raiz x1 = %.3f\n", x1);
		printf("Raiz x2 = %.3f", x2);
	} else {
		x1 = -b + sqrt(D) / (2 * a);
		printf("Raiz x1 = x2 = %.3f", x1);
	}
	return EXIT_SUCCESS;
}
