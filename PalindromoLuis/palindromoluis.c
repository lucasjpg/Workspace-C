/*
 * palindromoluis.c
 *
 *  Created on: 14 de out. de 2021
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 101

int verificaPalindromo(char *frase);

int main(void) {
    char frase[MAX];
    setbuf(stdout,NULL);

    //le a char sequence
    puts("Insira abaixo a frase que gostaria de conferir se é um palindromo");
    gets(frase);
    fflush(stdin);

    //envia para análise, que retorna 0 para nao palindromo e 1 para palindromo
    int ehPalindromo = verificaPalindromo(frase);

    //mostra uma mensagem dependendo do resultado da analise
    if(ehPalindromo){
        puts("Esta frase eh um palindromo");
    }else{
        puts("Esta frase ou palavra nao eh um palindromo");
    }

    return EXIT_SUCCESS;
}

int verificaPalindromo(char *frase){
	int i;
	strupr(frase); // Aquele laço de cima pode ser substituido por apenas isso aqui.

	int j = (strlen(frase))+1;
    char contrario[j];

    for(i = 0; (frase[i] != '\0') ; i++ ){
        contrario[j-2] = frase[i]; // Aqui vc deve usar j-2, pois trata-se da posicao.
        j--;
    }
    contrario[i] = '\0'; // Deve inserir isso na última posição do vetor

    if(!stricmp(frase, contrario)) // Coloca a exclamacao nesse if pra ver se funciona
        return 1;
    else
    	return 0;
}
