/*
 ============================================================================
 Name        : Ponteiros
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Implemente a função char *strrchar(char *s, char ch)
               que retorna o endereço da última ocorrência de ch em s. Caso não exista, retorna NULL.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *strrchar(char *s, char ch) {
	char *pnt = s;
	int i, n, aux = -1;

	n = strlen(s);
	strlwr(s);
	ch = tolower(ch);

	for (i = 0; i < n; i++) {
		if (s[i] == ch)
			aux = i;
	}
	if (aux == -1) {
		return NULL;
	} else {
		return pnt+aux;
	}
}

int main(void) {
	setbuf(stdout, NULL);
	char palavra[101], caracter;

	printf("Informe uma palavra (Max 100 caracteres): ");
	gets(palavra);
	printf("Informe uma letra para verificar o endereco da memoria: ");
	scanf(" %c", &caracter);

	printf("Endereco de memoria da ultima ocorrencia da variavel palavra: %p", strrchar(palavra, caracter));

	return EXIT_SUCCESS;
}
