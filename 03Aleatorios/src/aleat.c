/*
 * aleat.c
 *
 *  Created on: 31 de ago. de 2021
 *      Author: Lucas
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int n[10], i;
	srand(time(0));
	for (i = 0; i < 10; i++) {
		n[i] = rand() % 101;
	}
	for (i = 0; i < 10; i++) {
		printf("%d\n", n[i]);
	}
	return EXIT_SUCCESS;
}
