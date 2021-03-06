/*
 * leitura.c
 *
 *  Created on: 23 de nov. de 2021
 *      Author: Lucas
 *
 *      Exemplo para rodar o programa: cmd... 13_Leitura-Arquivos.exe ..\src\leitura.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *p_file;
	char ch;
	if (argc != 2) {
		puts("Informe o nome do arquivo!");
		return EXIT_FAILURE;
	}
	p_file = fopen(argv[1], "r");
	if (p_file == NULL) {
		puts("Impossivel abrir o arquivo!");
		return EXIT_FAILURE;
	}
	puts("Arquivo aberto com sucesso!");

	while ((ch = fgetc(p_file)) != EOF) {
		putchar(ch);
	}

	fclose(p_file);
	return EXIT_SUCCESS;
}
