/*
 ============================================================================
 Name        : Laços de repetição
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 04, gerar 10 números aleatórios (0, 1000) e exibir a média, maior e menor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, c, menor, maior;
    float media;
    srand(10); // Inicializa o gerador de numeros aleatorios
    c = 1;
    media = 0;
    while (c <= 10) {
    	// Gera numero aleatorio entre 0 e 1000.
    	n = rand() % 1001; // Sorteia um numero aleatorio entre 0 e RAND_MAX (2^31) e pega o resto da divisao por 1001.
    	media += n;
    	if (c == 1) {
    		menor = n;
    		maior = n;
    	} else {
    		menor = ( (n<menor) ? n : menor );
    		maior = ( (n>maior) ? n : maior );
    	}
    	printf("n%d = %d\n", c, n);
    	c++;
    }
    media /= 10;
    printf("Menor = %d\nMedia = %f\nMaior = %d", menor, media, maior);
    return EXIT_SUCCESS;
}
