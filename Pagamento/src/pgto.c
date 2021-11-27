/*
 ============================================================================
 Name        : Prova bimestral
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Faça um programa que solicita o total gasto (R$) pelo cliente de uma loja,
 imprime as opções de pagamento, solicita a opção desejada e
 imprime o valor total das prestações (se houver).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float custo, carne;
	int op, parcelas;
	setbuf(stdout, NULL);

	printf("Informe o total gasto (R$): ");
	scanf("%f", &custo);
	do {
		printf("Opcao 1: a vista com dez por cento de desconto.\n");
		printf("Opcao 2: em duas vezes (preco da etiqueta).\n");
		printf("Opcao 3: de 3 ate 10 vezes com tres por cento de juros ao mes. (somente acima de R$ 100,00).\n");
		do {
			printf("Informe a forma de pagamento: \n");
			scanf("%d", &op);
		} while (op == 3 && custo < 100);
		if (op == 3) {
			do {
				printf("Informe em quantas vezes deseja parcelar: ");
				scanf("%d", &parcelas);
			} while (parcelas < 3 || parcelas > 10);
		}
	} while (op > 3 || op < 1);

	if (op == 1) {
		printf("Ficou R$%f, muito obrigado.", custo*0.9);
	} else if (op == 2) {
		printf("Ficou 2x de R$%f, muito obrigado.", custo/2);
	} else {
		carne = custo * (1 + 0.03 * parcelas);
		custo = carne / parcelas;
		printf("Ficou em %dx de R$%f, totalizando R$%f. Muito obrigado.", parcelas, custo, carne);
	}
	return EXIT_SUCCESS;
}
