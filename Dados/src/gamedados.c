/*
 ============================================================================
 Name        : Prova bimestral
 Author      : Lucas Juliano Possa Gomes
 Version     : �nica
 Copyright   : Lucas Corp
 Description : Jodo de dados.

 O jogador come�a com um saldo de 100 reais e aposta um n�mero de 2 a 12.
 O computador lan�a 2 dados escolhendo 2 n�meros aleat�rio de 1 a 6.
 Se a soma dos dados for igual ao n�mero informado pelo usu�rio, o jogador vence ganhando 10 reais,
 sen�o ele perde 10 reais. O programa atualiza o saldo do jogador e
 pergunta se ele deseja continuar jogando ('S' para sim e 'N' para n�o).
 Caso o jogador responda n�o ou seu saldo seja 0, o programa encerra.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int saldo = 100, aposta, pc1, pc2;
	char op = 'N';
	setbuf(stdout, NULL);
	srand(time(0));

	printf("Funcionamento do jogo: \n");
	printf("O computador lanca 2 dados de 1 a 6 e voce deve adivinhar a soma do resultado.\n");
	printf("Voce inicia com 100 reais, cada acerto ganha 10 reais e se errar perde 10 reais.\n");

	do {
		do {
			printf("Aposte, qual sera a soma dos dados? Entre 2 a 12: ");
			scanf("%d", &aposta);
		} while (aposta < 2 || aposta > 12);
		pc1 = 1 + rand() % 6;
		pc2 = 1 + rand() % 6;
		if (pc1 + pc2 == aposta) {
			saldo += 10;
			printf("Voce acertou e esta com R$%d\n", saldo);
		} else {
			saldo -= 10;
			printf("Voce errou e esta com R$%d\n", saldo);
		}
		if (saldo > 0) {
			do {
				printf("Deseja jogar novamente? (S)im ou (N)ao: ");
				scanf(" %c", &op);
				if ((op != 'N' && op != 'n') && (op != 'S' && op != 's')) {
					printf("Escolha (S)im ou (N)ao!\n");
				}
			} while ((op != 'N' && op != 'n') && (op != 'S' && op != 's'));
		} else {
			printf("\nPerdeu!");
		}
	} while ((op == 'S' || op == 's') && saldo > 0);

	return EXIT_SUCCESS;
}
