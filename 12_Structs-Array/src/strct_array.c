/*
 * strcts.c
 *
 *  Created on: 8 de nov. de 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>

#define NUM 3

struct Aluno {
	int RA;
	char nome[50];
	float media;
};

int main(void) {
	setbuf(stdout, NULL);
	int i;
	struct Aluno *ptr;
	struct Aluno alunos[NUM];

	for (i = 0; i < NUM; i++) {
		printf("Informe o RA: ");
		scanf("%d", &alunos[i].RA);
		printf("Informe nome: ");
		scanf(" %s", alunos[i].nome);
		printf("Informe a media: ");
		scanf("%f", &alunos[i].media);
	}

	ptr = &alunos[0];
	for (i = 1; i < NUM; i++) {
		if (alunos[i].media > ptr -> media) {
			ptr = &alunos[i];
		}
	}

	printf("A maior media eh: %s", ptr -> nome);

	return EXIT_SUCCESS;
}
