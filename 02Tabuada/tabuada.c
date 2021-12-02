/*
 ============================================================================
 Name        : La�os de repeti��o
 Author      : Lucas Juliano Possa Gomes
 Version     : �nica
 Copyright   : Lucas Corp
 Description : Exerc�cio da aula 04, tabuada do 5 com do...while.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 0, j = 1;
    do {
    	i = 0;
    	do {
    		printf("%d x %d = %d\n", j, i, i*j);
        	i++;
    	} while (i <= 10);
    	j++;
    } while (j <= 10);
    return EXIT_SUCCESS;
}
