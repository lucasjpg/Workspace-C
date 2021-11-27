/*
 ============================================================================
 Name        : Estruturas Abstratas
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 12.

 Faça um programa que leia um vetor com os dados de 5 carros: marca (máximo 15 letras), ano e preço.
 Leia um valor p e mostre as informações de todos os carros com preço menor que p.
 Repita este processo até que seja lido um valor p = 0.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 5

typedef struct {
	char marca[16];
	int ano;
	float preco;
} Carros;

void leitura(Carros *ptr);
void impressao(Carros carro);

int main(void) {
	int i;
	float p;
	Carros carro[NUM];
	setbuf(stdout, NULL);

	for (i = 0; i < NUM; i++) {
		leitura(&carro[i]);
	}

	printf("\nInforme o preco alvo: ");
	scanf("%f", &p);

	for (i = 0; i < NUM; i++) {
		if (carro[i].preco < p) {
			impressao(carro[i]);
		}
	}

	return EXIT_SUCCESS;
}

void impressao(Carros carro) {
	printf("Marca: %s\n", carro.marca);
	printf("Ano: %d\n", carro.ano);
	printf("Preco: %.2f\n\n", carro.preco);
}

void leitura(Carros *ptr) {
	printf("Informe a marca: ");
	scanf(" %s", ptr -> marca);
	printf("Informe o ano: ");
	scanf("%d", &ptr -> ano);
	printf("Informe o preco: ");
	scanf("%f", &ptr -> preco);
}
