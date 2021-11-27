#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// setbuf(stdout,NULL);
	int repetir = 1, numeroSorteado, chute, continuar, ganhou, vidas;
	while(repetir){
		vidas = 10;
		chute = 150;
		continuar = 1;
		ganhou = 2;
		printf("Esse jogo funciona da seguinte forma: Vou sortear um numero entre 0 a 100 e voce tem que acertar! Vamos lah?\n");
		srand(time(0));
		numeroSorteado = rand() % 101;
		while( continuar ){
			printf("Voce tem %d vidas!, Qual numero quer tentar?\n", vidas);
			scanf("%d", &chute);
			while(chute < 0 || chute > 100 ){
				printf("Precisa ser um numero de 0 a 100");
				scanf("%d", &chute);
			}
			if( chute == numeroSorteado ){
				continuar = 0;
				ganhou = 1;
			}else{
				if( vidas > 0 ){
					vidas--;
					if(chute > numeroSorteado){
						printf("\nDica: o seu chute eh maior do que o numero!\n");
					}else{
						printf("\nDica: o seu chute eh menor do que o numero!\n");
					}
				}else{
					continuar = 0;
					ganhou = 0;
				}
			}
			if(ganhou == 1){
				printf("Parabens, voce acertou!!!\n");
			}else{
				if (ganhou == 0) {
					printf("Que pena, voce perdeu!\n");
				}
			}
		}
		printf("Vamos de novo? Se nao quiser pressione 0, ou para continuar digite qualquer numero: \n");
		scanf("%d", &repetir);
	}
	return EXIT_SUCCESS;
}
