/*
 ============================================================================
 Name        : Strings
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Atividade 5.
Faca um programa que analise uma frase ou palavra com ate 100 caracteres e informe se ela e um palindromo.
Palindromo e uma frase ou palavra que lida da esquerda pra direita ou da direita para esquerda sao iguais!

Caso a frase seja um palindromo, o sistema deve apresentar na tela a mensagem "Esta frase eh um palindromo".
Caso contrario, deve apresentar a mensagem "Esta frase ou palavra nao eh um palindromo".
Esta frase deve ser apresentada na tela apenas uma vez.

As comparacoes entre as palavras devem ser "case insensitive", ou seja, nao deve diferenciar maisculas ou minusculas.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	char s[101], frase[101], inv[101];
	int i, n, aux;

	printf("O codigo desconsidera espacos, entao frases podem ser verificadas somente pelas palavras.\n");
	printf("Conforme o exemplo classico 'Socorram me subi no onibus em Marrocos'.\n");
	printf("Informe uma palavra ou frase com no maximo 100 caracteres para verificar se eh um palindromo: \n");
	gets(s);

	n = strlen(s);
	aux = 0;
	for (i = 0; i < n; i++) {
		if (s[i] != ' ') {
			frase[aux] = s[i];
			aux++;
		}
	}
	frase[aux] = '\0';

	n = strlen(frase);
	for (i = 0; i < n; i++) {
		inv[n-i-1] = frase[i];
	}
	inv[n] = '\0';

	if (!stricmp(frase, inv)) {
		printf("Esta frase eh um palindromo.");
	} else {
		printf("Esta frase ou palavra nao eh um palindromo.");
	}

	return EXIT_SUCCESS;
}
