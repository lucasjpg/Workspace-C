/*
 ============================================================================
 Name        : La�os de repeti��o
 Author      : Lucas Juliano Possa Gomes
 Version     : �nica
 Copyright   : Lucas Corp
 Description : Exerc�cio da aula 04, ler indefinidamente um caracter at� ser digitado "S" ou "s".
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char c = 'C';
    setbuf(stdout, NULL); // Resolve problemas de I/O.
    while (c != 'S' && c != 's') {
    	printf("Informe um caractere, ou (S)air: ");
    	scanf(" %c", &c);
    	if (c == 'S' || c == 's') {
    		printf("Saida do programa.");
    	} else {
    		printf("Caractere = %c\n", c);
    	}
    }
    return EXIT_SUCCESS;
}
