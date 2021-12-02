/*
 ============================================================================
 Name        : Laços de repetição
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 04, jogo da adivinhacao.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num, usr, i = 0;
	srand(time(0)); // Inicializa o gerador de numeros aleatorios.
	num = rand() % 101; // Gera numeros aleatorios de 0 a 100.
	printf("Jogo de adivinhacao.\n");
	printf("Um numero entre 0 a 100 foi sorteado, adivinhe qual foi em 10 tentativas.\n");
	while (i < 10) {
		printf("Tentativa %d, qual o numero: ", i+1);
		scanf("%d", &usr);
		if (num > usr) {
			printf("O numero eh maior!!\n");
		} else if (num < usr) {
			printf("O numero eh menor!!\n");
		} else {
			printf("Parabens, voce eh o cara!!");
			break;
		}
		i++;
		if (i == 10) {
			printf("Voce perdeu!!");
		}
	}
    return EXIT_SUCCESS;
}
