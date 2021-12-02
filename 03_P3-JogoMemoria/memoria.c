/*
 ============================================================================
 Name        : Laços de repetição​
 Author      : Lucas Juliano Possa Gomes
 Version     : Unica
 Copyright   : Lucas Corp
 Description : Faça um programa que simule um jogo da memória.
               O programa sorteia 10 números inteiros de 1 a 10, mostra a sequência sorteada para o jogador durante 3 segundos e apaga a tela.
               O jogador tenta escrever a sequência de números conforme foi mostrada.
               O programa compara as duas sequências e a cada acerto de um número da sequência, o jogador ganha um ponto.
               No final, o programa mostra a sequência sorteada, a sequência digitada pelo jogador e a pontuação final.
               Caso o jogador tenha feito 10 pontos, mostrar uma mensagem de parabéns!

               Obs.: validar os números digitados pelo jogador, ou seja, deve ser entre 1 e 10.

Dica. para fazer o computador esperar 3 segundos use a função sleep() presente na biblioteca <unistd.h>
(https://www.gnu.org/software/libc/manual/html_mono/libc.html#Sleeping).
Para apagar o shell, use a função system("@cls||clear").
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
	int i, j, teste, rdn, n[10], usr[10];
	setbuf(stdout, NULL);
	srand(time(0));
	printf("Jogo da memoria, sera sorteada uma sequencia aleatoria de 1 a 10.\n");
	sleep(1);
	printf("Voce deve observar, memorizar a sequencia e informar assim que solicitado.\n");
	sleep(1);
	printf("Boa sorte!\n");
	sleep(1);
	printf("O jogo comeca em ");
	for (i = 0; i < 5; i++) {
		printf("%d...\n", 5-i);
		sleep(1);
	}
	// system("@cls||clear");
	// Cria vetor com 10 numeros aleatorios sem repeticao
	for (i = 0; i < 10; i++) {
		if (i == 0) {
			n[i] = 1 + rand() % 10;
		}
		else {
			teste = 0;
			while (teste == 0) {
				teste = 1;
				rdn = 1 + rand() % 10;
				for (j = 0; j < i; j++) {
					if (rdn == n[j]) {
						teste = 0;
						break;
					}
				}
			}
			n[i] = rdn;
		}
	}
	printf("Memorize a sequencia: \n");
	for (i = 0; i < 10; i++) {
		printf(" %d ", n[i]);
	}
	sleep(3);
	system("@cls||clear");
	printf("Informe a sequencia apresentada\n");
	// Recebe o jogo do usuario
	for (i = 0; i < 10; i++) {
		if (i == 0) {
			do {
				printf("Informe o 1o numero da sequencia: ");
				scanf(" %d", &usr[i]);
				if (usr[i] < 1 || usr[i] > 10) {
					printf("Numero invalido, deve estar entre 1 e 10.\n");
				}
			} while (usr[i] < 1 || usr[i] > 10);
		}
		else {
			teste = 0;
			while (teste == 0) {
				teste = 1;
				do {
					printf("Informe o %do numero da sequencia: ", i+1);
					scanf(" %d", &rdn);
					if (rdn < 1 || rdn > 10) {
						printf("Numero invalido, deve estar entre 1 e 10.\n");
					}
				} while (rdn < 1 || rdn > 10);
				for (j = 0; j < i; j++) {
					if (rdn == usr[j]) {
						teste = 0;
						printf("Numero ja informado, informe outro.\n");
						break;
					}
				}
			}
			usr[i] = rdn;
		}
	}
	printf("Sequencia informada: \n");
	for (i = 0; i < 10; i++) {
		printf(" %d ", usr[i]);
	}
	printf("\nSequencia sorteada: \n");
	for (i = 0; i < 10; i++) {
		printf(" %d ", n[i]);
	}
	teste = 0;
	for (i = 0; i < 10; i++){
		if (n[i] == usr[i]) {
			teste++;
		}
	}
	printf("\nSua pontuacao foi: %d", teste);
	if (teste == 10) {
		printf("\nParabens sua memoria esta tinindo =)");
	}
	return EXIT_SUCCESS;
}
