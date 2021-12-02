/*
 ============================================================================
 Name        : Prova bimestral
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Faça um programa que controle o estoque de 3 produtos em 4 armazéns de um supermercado.
 O programa deverá ler o número da linha e da coluna, correspondente ao produto no armazém,
 e a quantidade a ser retirada do estoque. Caso a quantidade solicitada for menor ou igual
 a quantidade em estoque, o programa deverá emitir uma mensagem de atendimento e dar baixa no estoque.
 Do contrário, emitir mensagem, "Estoque com quantidade insuficiente para atender ao pedido".
 O programa termina quando o número da linha for igual a -1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int estoque[4][3]= {{150, 0, 200}, {250, 300, 150}, {300, 0, 90}, {350, 300, 200}};
	int linha, coluna, i, j, n;
	setbuf(stdout, NULL);
	do {
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 4; j++) {
				if (i == 0) {
					switch (j) {
					case 0:
						printf("ESTOQUE    ");
						break;
					case 1:
						printf("Produto 0  ");
						break;
					case 2:
						printf("Produto 1  ");
						break;
					case 3:
						printf("Produto 2\n");
						break;
					}
				}
				if (i == 1) {
					switch (j) {
					case 0:
						printf("Armazem 0     ");
						break;
					case 1:
						printf("%d         ", estoque[0][0]);
						break;
					case 2:
						printf("%d       ", estoque[0][1]);
						break;
					case 3:
						printf("%d\n", estoque[0][2]);
						break;
					}
				}
				if (i == 2) {
					switch (j) {
					case 0:
						printf("Armazem 1     ");
						break;
					case 1:
						printf("%d       ", estoque[1][0]);
						break;
					case 2:
						printf("%d       ", estoque[1][1]);
						break;
					case 3:
						printf("%d\n", estoque[1][2]);
						break;
					}
				}
				if (i == 3) {
					switch (j) {
					case 0:
						printf("Armazem 2     ");
						break;
					case 1:
						printf("%d         ", estoque[2][0]);
						break;
					case 2:
						printf("%d       ", estoque[2][1]);
						break;
					case 3:
						printf("%d\n", estoque[2][2]);
						break;
					}
				}
				if (i == 4) {
					switch (j) {
					case 0:
						printf("Armazem 3     ");
						break;
					case 1:
						printf("%d       ", estoque[3][0]);
						break;
					case 2:
						printf("%d       ", estoque[3][1]);
						break;
					case 3:
						printf("%d\n", estoque[3][2]);
						break;
					}
				}
			}
		}
		do {
			printf("Informe o numero do produto a ser retirado: ");
			scanf("%d", &coluna);
		} while (coluna < 0 || coluna > 3);
		do {
			printf("Informe o numero do armazem (-1 para sair): ");
			scanf("%d", &linha);
		} while (linha != -1 && (linha < 0 || linha > 4));
		if (linha != -1) {
			do {
				printf("Informe a quantidade a ser retirada (insira 0 para desistir): ");
				scanf("%d", &n);
				if (n > estoque[linha][coluna]) {
					printf("Estoque com quantidade insuficiente para atender ao pedido.\n");
				} else {
					printf("Tudo certo, foi dado baixa no sistema.\n");
					estoque[linha][coluna] -= n;
					n = 0;
				}
			} while (n > estoque[linha][coluna]);
		}
	} while (linha != -1);

	return EXIT_SUCCESS;
}
