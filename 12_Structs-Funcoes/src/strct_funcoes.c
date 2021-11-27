/*
 * strcts.c
 *
 *  Created on: 8 de nov. de 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>

#define NUM 3

typedef struct {
	int RA;
	char nome[20];
	float media;
} ALUNO;

void ler_aluno(ALUNO *ponteiro) {
	printf("Informe o RA: ");
	scanf("%d", &ponteiro -> RA);
	printf("Informe nome: ");
	scanf(" %s", ponteiro -> nome);
	printf("Informe a media: ");
	scanf("%f", &ponteiro -> media);
}

void mostrar_aluno(ALUNO aluno) {
	printf("RA: %d\n", aluno.RA);
	printf("Nome: %s\n", aluno.nome);
	printf("RA: %.2f\n", aluno.media);
}

int main(void) {
	setbuf(stdout, NULL);
	int i;
	ALUNO *ptr;
	ALUNO alunos[NUM];

	for (i = 0; i < NUM; i++) {
		ler_aluno(&alunos[i]);
	}

	ptr = &alunos[0];
	for (i = 1; i < NUM; i++) {
		if (alunos[i].media > ptr -> media) {
			ptr = &alunos[i];
		}
	}

	mostrar_aluno(*ptr);

	return EXIT_SUCCESS;
}
