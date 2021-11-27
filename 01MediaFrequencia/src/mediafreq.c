/*
 ============================================================================
 Name        : Operadores relacionais e logicos, testes e condicoes​
 Author      : Lucas Juliano Possa Gomes
 Version     : Unica
 Copyright   : Lucas Corp
 Description : Faça um programa que leia as notas N1, N2 e N3 de um aluno e calcule a média M.
               As notas são números de 0 a 10. O programa também deve ler a frequência F do estudante,
               que pode ser de 0 a 100. Nesse exercício, os números podem ser decimais.
               No final, o programa deve mostrar a média, a frequência e a situação do estudante,
               conforme a regra abaixo:

				M maior que 7 e frequencia maior que 75: APROVADO.
				M menor que 7 e maior que 4 e frequência maior que 75: RECUPERAÇÃO.
				M menor que 4 ou frequência menor que 75: REPROVADO.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a, b, c, freq, media;
	printf("Voce deverah informar tres notas bimestrais de um aluno e sua frequencia nas aulas.\n");
	printf("Em seguida, este algoritmo ira retornar a media, a frequencia e situacao no curso.\n");
	printf("Informe a nota 1 (0.0 a 10.0): ");
	scanf("%f", &a);
	printf("Informe a nota 2 (0.0 a 10.0): ");
	scanf("%f", &b);
	printf("Informe a nota 3 (0.0 a 10.0): ");
	scanf("%f", &c);
	printf("Informe a frequencia (0.0 a 100.0): ");
	scanf("%f", &freq);
	media = (a+b+c)/3;
	if ((media >= 7) && (freq >= 75)) {
		printf("Aprovado, Media = %.1f, Frequencia = %.1f", media, freq);
	} else if ((media >= 4) && (freq >= 75)) {
		printf("Recuperacao, Media = %.1f, Frequencia = %.1f", media, freq);
	} else {
		printf("Reprovado, Media = %.1f, Frequencia = %.1f", media, freq);
	}
	return EXIT_SUCCESS;
}
