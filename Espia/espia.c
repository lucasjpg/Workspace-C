/*
 * espia.c
 *
 *  Created on: 13 de out. de 2021
 *      Author: Lucas
 *
 * Uma espi� precisa gerar um algoritmo de criptografia para se comunicar com seus superiores:
 * dada uma mensagem (apenas em letras mai�sculas e sem acento) e um n�mero inteiro n positivo,
 * trocar cada letra da mensagem pela letra que est� n posi��es a sua frente.
 * Trate isso de forma circular: se tivermos a letra 'Z' e n = 1, a letra de troca
 * deveria ser 'A' e , caso n = 2,  'B'.
 *
 * Formato de entrada
 * 2 linhas: a primeira cont�m o n�mero n e a segunda, a mensagem a ser criptografada.
 * A mensagem deve conter no m�ximo 1000 caracteres, todos em mai�sculas e sem acentos.
 * Obs: Eventualmente a entrada pode conter erros.
 *
 * Formato de sa�da
 * Escrever a mensagem de sa�da criptografada, de acordo com a entrada.
 * No caso de algum erro no arquivo de entrada, a sa�da deve ser a string "ERRO"
 * (sem aspas). A sa�da n�o deve conter espa�os antes ou depois do valor da resposta!
 *
 * Restri��es
 * O n�mero n deve ser um inteiro positivo at� o tamanho do alfabeto (0 <= n <= 26).
 * O tamanho da mensagem de entrada �, no m�ximo, 1000 caracteres.
 *
 * Exemplo de Entrada 1
 * 2
 * ABAZ
 * Exemplo de Sa�da 1
 * CDCB
 *
 * Exemplo de Entrada 2
 * 4
 * CESAR
 * Exemplo de Sa�da 2
 * GIWEV
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int posicao(char letra, char alfabeto[27]) {
	int posi;
	for (int i = 0; i < 26; i++) {
		if (letra == alfabeto[i]) {
			posi = i;
		}
	}
	return posi;
}

int main(void) {
	setbuf(stdout, NULL);
	char alfabeto[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char mensagem[1001], cri[1001];
	int n, i, aux;

	do {
		printf("Informe a senha de criptografia (entre 0 e 26): ");
		scanf("%d", &n);
		fflush(stdin);
	} while(n < 0 || n > 26);

	do {
		aux = 0;
		printf("Informe a frase criptografada (somente maiusculo sem numeros e caracteres especiais): ");
		gets(mensagem);
		for (i = 0; mensagem[i] != '\0'; i++) {
			if (mensagem[i] < 'A' || mensagem[i] > 'Z') {
				if (mensagem[i] != ' ') {
					aux = 1;
					printf("\nERRO!\n");
					break;
				}
			}
		}
	} while(aux);

	for (i = 0; i < strlen(mensagem); i++) {
		if (mensagem[i] != ' ') {
			aux = posicao(mensagem[i], alfabeto);
			if (aux + n > 25) {
				aux = n - (26 - aux);
			} else {
				aux += n;
			}
			cri[i] = alfabeto[aux];
		} else {
			cri[i] = ' ';
		}
		if (i == strlen(mensagem)-1) {
			cri[i+1] = '\0';
		}
	}

	printf("%s", cri);

	return EXIT_SUCCESS;
}
