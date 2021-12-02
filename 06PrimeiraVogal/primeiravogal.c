/*
 ============================================================================
 Name        : Ponteiros
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Implemente uma função char *First_Vogal(char *s)
               que retorna o endereço da primeira vogal da string s. Caso não exista, retorna NULL.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *First_Vogal(char *s) {
	char *pnt = s;
	char vogais[6] = {"aeiou"};
	char *teste;
	int i, n = -1, aux = -1;

	strlwr(s);

	for (i = 0; i < 5; i++) {
		teste = strchr(s, vogais[i]);
		if (teste != NULL) {
			n = strlen(teste);
		}
		if (n > aux) {
			aux = n;
		}
	}
	aux = strlen(s) - aux;

	if (aux == -1) {
		return NULL;
	} else {
		return pnt+aux;
	}
}

int main(void) {
	setbuf(stdout, NULL);
	char palavra[101];

	printf("Informe uma palavra (Max 100 caracteres): ");
	gets(palavra);

	printf("Endereco de memoria da ultima ocorrencia da variavel palavra: %p", First_Vogal(palavra));

	return EXIT_SUCCESS;
}
