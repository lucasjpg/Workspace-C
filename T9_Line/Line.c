/*
 ============================================================================
 Name        : Arquivos
 Author      : Lucas Juliano Possa Gomes
 Version     : ?nica
 Copyright   : Lucas Corp
 Description : Pergunta 1 do trabalho 9.

Implemente o utilit?rio Line.c que mostre o conte?do de um arquivo recebido na linha de comando,
mostrando cada linha o n?mero respectivo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *p_file;
	char ch;
	int cont = 1;

	if (argc != 2) {
		puts("Informe o nome do arquivo!");
		return EXIT_FAILURE;
	}
	p_file = fopen(argv[1], "r");

	printf("%d: ", cont);
	while ((ch = fgetc(p_file)) != EOF) {
		printf("%c", ch);
		if (ch == '\n') {
			cont++;
			printf("%d: ", cont);
		}
	}

	fclose(p_file);
	return EXIT_SUCCESS;
}
