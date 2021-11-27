/*
 ============================================================================
 Name        : Strings
 Author      : Lucas Juliano Possa Gomes
 Version     : Única
 Copyright   : Lucas Corp
 Description : Atividade 5. Jogo da Forca.
O programa guarda um vetor de 30 palavras com no máximo 20 letras e sorteia uma das palavras.
Ele imprime na tela a palavra usando o caracter '_' no lugar de cada letra.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void imprime(int vidas);
void iniciaposicao(int posi[20]) {
	for (int i = 0; i < 20; i++) {
		posi[i] = -1;
	}
}

int main(void) {
	setbuf(stdout, NULL);
	int i, cont = -1; // Variaveis auxiliares para laco de repeticao

	// Inicializacao de variavel com as palavras
	char palavras[30][21] = {"espinafre", "cereais", "vegetais", "morango", "caqui", "cereja", "abobrinha", "carne",
	"cogumelo", "laranja", "osso", "coxa", "quadril", "ombro", "ouvido", "calcanhar", "unha", "sangue", "mente",
	"cabeca", "cobra", "porco", "polvo", "veado", "arraia", "pomba", "papagaio", "chama", "baleia", "chita"};

	// Declaracao das variaveis para as palavras do jogo
	char forca[21], letra; // acerto[21],

	// Declaracao de variaveis contadoras do jogo
	int sorteio[30]; // Sorteia uma das possiveis palavras do jogo
	int n;           // Quantidade de letras da palavra sorteada
	int vidas;       // Contador de vidas (para o desenho do boneco na forca)
	int posicao[20]; // Posicao da letra recebida do usuario na palavra sorteada
	int n_posicao;   // Quantidade de posicoes onde existe a letra escolhida
	char op = 's';   // Opcao de jogar novamente

	do {
		if (op == 's' || op == 'S') {
			iniciaposicao(posicao);  // Inicia a variavel posicao default.
			vidas = 6;               // Inicia 6 vidas para o jogador
			cont++;                  // Contador de jogos.
			// Sorteia a palavra.
			srand(time(0));
			sorteio[cont] = rand() % 30;
			do {
				n_posicao = 0;
				for (i = 0; i < cont; i++) {
					if (sorteio[cont] == sorteio[i]) {
						n_posicao = 1;
						sorteio[cont] = rand() % 30;
						break;
					}
				}
			} while (n_posicao != 0);

			// Copia a palavra da matriz na variavel (char forca[21]) e verifica quantidade de letras em (n)
			strcpy(forca, palavras[sorteio[cont]]);
			n = strlen(forca);

			printf("Jogo da forca, voce tem 6 vidas para descobrir a palavra.\n");
			// Imprime a forca.
			imprime(vidas);
			for (i = 0; i < n; i++) {
				printf("_ ");
			}

			do {
				// Recebe letra do usuario.
				printf("Informe uma letra: ");
				scanf(" %c", &letra);
				strlwr(&letra);

				// Insere a quantidade de posicoes que a letra existe em (n_posi) e as posicoes em (posi).
				n_posicao = 0;
				for (i = 0; i < n; i++) {
					if (forca[i] == letra) {
						posicao[i] = i;
						n_posicao++;
					}
				}

				// Caso o jogador escolher uma letra que nao exista na palavra, perde uma vida.
				if (n_posicao == 0) {
					vidas--;
				}
				// Imprime a forca.
				imprime(vidas);
				// Imprime a palavra jogada.
				for (i = 0; i < n; i++) {
					if (posicao[i] != -1) {
						printf("%c ", forca[i]);
					} else {
						printf("_ ");
					}
				}

				// Verifica se ganhou ou perdeu
				n_posicao = 0;
				for (i = 0; i < n; i++) {
					if (posicao[i] != -1) {
						n_posicao++;
					}
				}
				if (n_posicao == n) {
					printf("\nParabens! Voce escapou com vida!\n");
				} else if (vidas == 0) {
					printf("\nVoce morreu!\n");
				}
			} while(vidas > 0 && n_posicao != n);
		}
		do {
			printf("Deseja jogar novamente? (S)im ou (N)ao: ");
			scanf(" %c", &op);
			if (!(op == 's' || op == 'S' || op == 'n' || op == 'N')) {
				printf("Digite S ou N, (S)im ou (N)ao!");
			}
		} while(!(op == 's' || op == 'S' || op == 'n' || op == 'N'));
	} while(op == 's' || op == 'S');
	return EXIT_SUCCESS;
}

void imprime(int vidas) {
	printf(" _____\n");
	printf(" |   |\n");
	switch (vidas) {
	case 0:
		printf(" |   O\n");
		printf(" |  -|-  \n");
		printf(" |  | |  \n");
		printf("_|_______\n");
		break;
	case 1:
		printf(" |   O\n");
		printf(" |  -|- \n");
		printf(" |  |   \n");
		printf("_|_______\n");
		break;
	case 2:
		printf(" |   O\n");
		printf(" |  -|- \n");
		printf(" |      \n");
		printf("_|_______\n");
		break;
	case 3:
		printf(" |   O\n");
		printf(" |  -| \n");
		printf(" |     \n");
		printf("_|_______\n");
		break;
	case 4:
		printf(" |   O\n");
		printf(" |  -  \n");
		printf(" |     \n");
		printf("_|_______\n");
		break;
	case 5:
		printf(" |   O\n");
		printf(" |     \n");
		printf(" |     \n");
		printf("_|_______\n");
		break;
	case 6:
		printf(" |    \n");
		printf(" |     \n");
		printf(" |     \n");
		printf("_|_______\n");
		break;
	}
}
