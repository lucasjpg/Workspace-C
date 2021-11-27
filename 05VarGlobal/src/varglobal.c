/*
 ============================================================================
 Name        : Funcoes e procedimentos
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exemplo da aula 09. Variaveis globais
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int v[100];
int i, j, aux;

void sorteia();
void bubblesort();
void mostrar();
void mostrar_inverso();

int main(void) {
	sorteia();
	bubblesort();
	mostrar();
	printf("\n\n");
	mostrar_inverso();
	return EXIT_SUCCESS;
}

void mostrar_inverso() {
	for (i = 99; i >= 0; i--) {
		printf("%d ", v[i]);
	}
}

void mostrar() {
	for (i = 0; i < 100; i++) {
		printf("%d ", v[i]);
	}
}

void bubblesort() {
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100 - i - 1; j++) {
			if (v[j] > v[j+1]) {
				aux = v[j+1];
				v[j+1] = v[j];
				v[j] = aux;
			}
		}
	}
}

void sorteia() {
	srand(10);
	for (i = 0; i < 100; i++) {
		v[i] = 1 + rand() % 1000;
	}
}
