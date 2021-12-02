/*
 * pares.c
 *
 *  Created on: 31 de ago. de 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	for (int i = 0; i < 256; i++){
		printf("%d -> %c\n", i, (char) i);
	}
	return EXIT_SUCCESS;
}
