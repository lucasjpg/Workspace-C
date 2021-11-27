/*
 ============================================================================
 Name        : Laços de repetição​
 Author      : Lucas Juliano Possa Gomes
 Version     : Unica
 Copyright   : Lucas Corp
 Description : Faça um programa que jogue par ou ímpar com o usuário.
               O programa pede para o jogador escolher a opção "P - Par" ou "I - Impar" e digitar um número de 1 a 5.
               Depois, o programa sorteia um número de 1 a 5.
               Caso a soma dos números corresponda a opção selecionada, o jogador ganha, caso contrário, o jogador perde.
               Ao término de cada partida, o programa pergunta ao jogador "S-Sim" ou "N-Nao" se ele quer jogar outra vez e mostra um placar
               (Computador: N pontos x Humano: M pontos).
               Caso o jogador opte pela opção "N-Nao", o programa termina.

Obs.: validar o número digitados pelo jogador, ou seja, deve ser entre 1 e 5.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
	int usr, npc, p_usr = 0, p_npc = 0, res;
	char op, again;
	setbuf(stdout, NULL);
	srand(time(0));
	printf("Jogo do par ou impar.\n");
	do {
		do {
			printf("Escolha, (P)ar ou (I)mpar: ");
			scanf(" %c", &op);
			if (op != 'p' && op != 'i') {
				printf("Caracter invalido, informar (p) ou (i).");
			}
		} while (op != 'p' && op != 'i');
		do {
			printf("Escolha um numero de 1 a 5: ");
			scanf(" %d", &usr);
			if (usr < 1 || usr > 5) {
				printf("Valor invalido. ");
			}
		} while (usr < 1 || usr > 5);
		npc = 1 + rand() % 5;
		printf("Computador joga: %d\n", npc);
		if ((npc + usr) % 2 == 0) {
			res = 'p';
		} else {
			res = 'i';
		}
		switch (op) {
			case 'p':
				if (res == 'p') {
					p_usr++;
					printf("Parabens, voce venceu a rodada!\n");
				} else {
					p_npc++;
					printf("O computador venceu a rodada!\n");
				}
				break;
			case 'i':
				if (res == 'i') {
					p_usr++;
					printf("Parabens, voce venceu a rodada!\n");
				} else {
					p_npc++;
					printf("O computador venceu a rodada!\n");
				}
				break;
		}
		printf("Placar: Voce = %d x Computador = %d\n", p_usr, p_npc);
		printf("Jogar novamente? Qualquer tecla para Sim ou (N)ao: ");
		scanf(" %c", &again);
	} while (again != 'n');
	return EXIT_SUCCESS;
}
