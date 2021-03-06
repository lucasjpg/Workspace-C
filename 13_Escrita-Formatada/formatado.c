/*
 * formatado.c
 *
 *  Created on: 23 de nov. de 2021
 *      Author: Lucas
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	FILE *p_file_append, *p_file_read;
	char nome[50];
	int nota;

	p_file_append = fopen("lista.txt", "a");
	p_file_read = fopen("lista.txt", "r");

	if (p_file_append == NULL || p_file_read == NULL) {
		puts("Nao foi possivel abrir os arquivos!");
		return EXIT_FAILURE;
	}

	while (fscanf(p_file_read, "%s %d", nome, &nota) != EOF) {
		printf("%s\t%d\n", nome, nota);
	}

	do {
		printf("Digite o nome: ");
		scanf(" %s", nome);
		fflush(stdin);
		if (!strcasecmp(nome, "sair")) {
			break;
		}
		printf("Digite a nota: ");
		scanf("%d", &nota);
		fprintf(p_file_append, "%s\t%d\n", nome, nota);
	} while (1);

	fclose(p_file_append);
	fclose(p_file_read);
	return EXIT_SUCCESS;
}
