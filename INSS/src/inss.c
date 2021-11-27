/*
 ============================================================================
 Name        : Prova bimestral
 Author      : Lucas Juliano Possa Gomes
 Version     : �nica
 Copyright   : Lucas Corp
 Description : Fa�a um programa que calcule o recolhimento de INSS sobre o sal�rio bruto de um funcion�rio.
 O programa l� o sal�rio bruto (SB), calcula o INSS e retorna na tela esse valor.

Tabela de al�quotas progressivas de recolhimento de INSS (tabela de 2021):
Sal�rio bruto (SB):
Faixa 1: R$ 0 at� R$ 1.100,00 - 7,5%
Faixa 2: R$ 1.100,01 at� R$ 2.203,48 - 9,0%
Faixa 3: R$ 2.203,49 at� R$ 3.305,22 - 12,0%
Faixa 4: R$ 3.305,23 at� R$ 6.433,57 - 14,0%
Acima da quarta faixa: recolhimento fixo de R$ 751,97
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float sb, inss;
	setbuf(stdout, NULL);
	printf("Informe o salario: ");
	scanf("%f", &sb);
	if (sb > 6433.57) {
		inss = 751.97;
	} else if (sb > 3305.22) {
		inss = 314.0199 + 0.14 * (sb - 3305.23);
	} else if (sb > 2203.48) {
		inss = 181.8123 + 0.12 * (sb - 2203.49);
	} else if (sb > 1100.0) {
		inss = 82.5 + 0.09 * (sb - 1100.01);
	} else {
		inss = 0.075 * sb;
	}
	printf("INSS = %f", inss);
	return EXIT_SUCCESS;
}
