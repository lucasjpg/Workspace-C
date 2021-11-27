/*
 ============================================================================
 Name        : Operadores matemáticos
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 03, transformar segundos para hora, minuto e segundo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int s, min, hora;
	printf("Informe a quantidade de segundos: ");
	scanf("%d", &s);
	hora = s/3600;
	min = s/60-hora*60;
	printf("%d horas %d minutos %d segundos", hora, min-, s-min*60-hora*3600);
	return EXIT_SUCCESS;
}
