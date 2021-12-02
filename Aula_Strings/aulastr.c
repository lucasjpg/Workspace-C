/*
 * aulastr.c
 *
 *  Created on: 5 de out. de 2021
 *      Author: Lucas
 *      Le curso, nome, notas e imprime tudo com a media.
 */

#include <stdio.h>
#include <stdlib.h>

void passagem_ponteiro(char *nome, char *curso);

int main(void) {
	setbuf(stdout, NULL);
	char nome[20], curso[20];
	float n1, n2, n3, media;

	printf("Informe o curso: ");
	gets(curso); // Idem scanf.
	printf("Informe o nome: ");
	scanf("%s", nome);
	printf("Informe a nota 1: ");
	scanf("%f", &n1);
	printf("Informe a nota 2: ");
	scanf("%f", &n2);
	printf("Informe a nota 3: ");
	scanf("%f", &n3);

	media = n1+n2+n3;
	media /= 3;

	printf("Nome: %s\nCurso: %s\nMedia: %f", nome, curso, media);
	puts(" ");
	passagem_ponteiro(nome, curso); // Exemplo de passagem com ponteiro.

	return EXIT_SUCCESS;
}

void passagem_ponteiro(char *nome, char *curso) {
	printf("%s ", curso);
	printf("%s", nome);
}
