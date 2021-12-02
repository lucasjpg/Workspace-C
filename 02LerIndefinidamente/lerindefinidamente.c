/*
 ============================================================================
 Name        : Laços de repetição
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 04, ler indefinidamente um caracter até ser digitado "S" ou "s".
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
