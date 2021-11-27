/*
 ============================================================================
 Name        : Prova bimestral
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Faça um programa que indique o tipo de combustível
 (álcool, gasolina comum ou gasolina aditivada)
 mais barato para realizar uma determinada viagem.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Autonomia (R$ / km)
	float km, etanol, comum, aditivada;
	//  R$/litro  /  km/litro  =  R$/km
	etanol = 0.581875;    // R$/km
	comum = 0.5655;       // R$/km
	aditivada = 0.572381; // R$/km

	setbuf(stdout, NULL);
	printf("Informe a distancia da viagem (km): ");
	scanf("%f", &km);

	printf("Viajar com alcool, R$%f, %f litros\n", etanol*km, km/8);
	printf("Viajar com gasolina comum, R$%f, %f litros\n", comum*km, km/10);
	printf("Viajar com gasolina aditivada, R$%f, %f litros\n", aditivada*km, km/10.5);

	printf("\n\n Sempre melhor viajar com a comum.");
	return EXIT_SUCCESS;
}
