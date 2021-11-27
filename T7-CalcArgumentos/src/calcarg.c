/*
 * calcarg.c
 *
 *  Created on: 29 de out. de 2021
 *      Author: Lucas
 *
 *      Escreva um programa que receba como argumentos 3 parâmetros correspondendo aos operadores e a operação
 *      (soma, subtração, multiplicação e divisão) de uma calculadora simples.
 *      Exemplo:
 *      calculadora.exe 5.5 9 -
 *		O resultado de 5.5 - 9 é -3.5
 *
 *		Para efetuar a multiplicacao eh necessario informar "x" como operador.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	double n1, n2;
	n1 = atof(argv[1]);
	n2 = atof(argv[2]);

	switch(argv[3][0]) {
		case '+':
			printf("%.2lf + %.2lf = %.2lf", n1, n2, n1+n2);
			break;
		case '-':
			printf("%.2lf - %.2lf = %.2lf", n1, n2, n1-n2);
			break;
		case 'x': // Necessario operador "x".
			printf("%.2lf * %.2lf = %.2lf", n1, n2, n1*n2);
			break;
		case '/':
			printf("%.2lf / %.2lf = %.2lf", n1, n2, n1/n2);
			break;
	}
	return EXIT_SUCCESS;
}
