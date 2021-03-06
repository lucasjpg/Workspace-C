/*
 * escrita.c
 *
 *  Created on: 23 de nov. de 2021
 *      Author: Lucas
 *
 *      Exemplo para rodar o programa: 13_Escrita-Arquivos.exe ..\src\escrita.c copia
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *p_file_origem, *p_file_destino;
	char ch;
	if (argc != 3) {
		puts("Informe os nomes dos arquivos (origem e destino)!");
		return EXIT_FAILURE;
	}

	p_file_origem = fopen(argv[1], "r");
	if (p_file_origem == NULL) {
		puts("Impossivel abrir o arquivo!");
		return EXIT_FAILURE;
	}
	puts("Arquivo aberto com sucesso!");

	p_file_destino = fopen(argv[2], "w");
	if (p_file_destino == NULL) {
		puts("Impossivel criar o arquivo!");
		fclose(p_file_origem);
		return EXIT_FAILURE;
	}
	puts("Arquivo criado com sucesso!");

	while ((ch = fgetc(p_file_origem)) != EOF) {
		fputc(ch, p_file_destino);
	}

	fclose(p_file_origem);
	fclose(p_file_destino);
	return EXIT_SUCCESS;
}
