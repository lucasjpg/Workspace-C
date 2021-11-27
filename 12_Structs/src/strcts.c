/*
 * strcts.c
 *
 *  Created on: 8 de nov. de 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
	int RA;
	char nome[50];
	float media;
};

int main(void) {
	setbuf(stdout, NULL);

	struct Aluno *ptr;

	struct Aluno lucas = {
		82650290,
		"Lucas Juliano Possa Gomes",
		10.0
	};

	struct Aluno pedro;
	pedro.RA = 8888888;
	strcpy(pedro.nome, "Pedrinho da Silva");
	pedro.media = 5.5;

	if (lucas.media > pedro.media) {
		ptr = &lucas;
	} else {
		ptr = &pedro;
	}

	printf("%f", ptr -> media);

	return EXIT_SUCCESS;
}
