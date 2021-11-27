/*
 ============================================================================
 Name        : Operadores relacionais e logicos, testes e condicoes​
 Author      : Lucas Juliano Possa Gomes
 Version     : Unica
 Copyright   : Lucas Corp
 Description : Faça um programa que leia 3 números inteiros A, B e C, com sinal,
               e mostre-os em ordem crescente ou decrescente, conforme a opção do usuário.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int v[3], op, i, j, aux;
	printf("Voce deverah informar tres valores inteiros quaisquer.\n");
	printf("Em seguida, este algoritmo ira retorna-los de forma crescente ou decrescente conforme solicitado.\n");
	for (i = 0; i < 3; i++) {
		printf("Informe o %do valor: ", i+1);
		scanf("%d", &v[i]);
	}
	printf("Voce deseja (1) Crescente ou (2) Decrescente: ");
	scanf("%d", &op);
	switch(op) {
		case 1:
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 2-i; j++) {
					if (v[j] > v[j+1]) {
						aux = v[j];
						v[j] = v[j+1];
						v[j+1] = aux;
					}
				}
			}
			printf("Ordem crescente: %d, %d, %d", v[0], v[1], v[2]);
			break;
		case 2:
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 2-i; j++) {
					if (v[j] < v[j+1]) {
						aux = v[j];
						v[j] = v[j+1];
						v[j+1] = aux;
					}
				}
			}
			printf("Ordem decrescente: %d, %d, %d", v[0], v[1], v[2]);
			break;
		default:
			printf("Opcao invalida.");
	}
	return EXIT_SUCCESS;
}
