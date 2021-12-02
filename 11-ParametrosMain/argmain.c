/*
 * argmain.c
 *
 *  Created on: 26 de out. de 2021
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		printf("Parametro %d = \" %s \" \n", i+1, argv[i]);
	}
	return EXIT_SUCCESS;
}
