/*
 ============================================================================
 Name        : Operadores matemáticos
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Exercício da aula 03, exibir parte inteira e decimal de uma variável tipo float.
               A saída dos dados é feita inteiramente com valores inteiros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float numero, aux_f;
    int inteiro, decimal, aux_i, n;
    printf("Informe um valor real qualquer: ");
    scanf("%f", &numero);
    aux_f = numero;
    aux_i = aux_f;
    n = 10;
    while ((aux_f - aux_i) != 0.0) {
        aux_f *= 10;
        aux_i = aux_f;
        n *= 10;
    }
    inteiro = numero;
    decimal = (numero - inteiro) * n;
    printf("Valor real = %f\nValor inteiro = %d\nValor decimal = %d", numero, inteiro, decimal);
    return EXIT_SUCCESS;
}
