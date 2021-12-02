/*
===========================================================
Nome: Jodo_da_velha.c
Autor: Elton Ap. de Campos 
Autor: Felipe dos Santos Fabienski
Dt. Criacao: 19/09/2021
Versao: 1.0
Descricao: jogo da velha. O jogo permite jogar jogador vs jogador e computador vs jogador
===========================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 3

void mostrar_tabuleiro (char tabuleiro [DIM][DIM]){

    int i, j;

    for (i = 0; i < DIM; i++){
        for (j = i; j == i; j++){
            printf (" %c | %c | %C\n", tabuleiro [i][0],tabuleiro [i][1],tabuleiro [i][2]);
            if (i<2){
                printf ("-----------\n");
            }
        }
    }
}

void resultado_PvP (char tabuleiro [DIM][DIM]){
    int i;
    int contJ1, contJ2;

    contJ1 = 0;
    contJ2 = 0;

    //Verifica o (s) resultado (s) na (s) posicao (oes) horizontal do tabuleiro

    for (i = 0; i < DIM; i++){
        if(tabuleiro[i][0] == 'x' && tabuleiro[i][1] == 'x' && tabuleiro[i][2] == 'x'){
            contJ1++;
        }else if(tabuleiro[i][0] == 'o' && tabuleiro[i][1] == 'o' && tabuleiro[i][2] == 'o'){
            contJ2++;
        }
    }

    //Verifica o (s) resultado (s) na (s) posicao (oes) vertical do tabuleiro

    for (i = 0; i < DIM; i++){
        if(tabuleiro[0][i] == 'x' && tabuleiro[1][i] == 'x' && tabuleiro[2][i] == 'x'){
            contJ1++;
        }else if(tabuleiro[0][i] == 'o' && tabuleiro[1][i] == 'o' && tabuleiro[2][i] == 'o'){
            contJ2++;
        }
    }

    //Verifica o(s) resultado(s) na(s) posicao(oes) diagonal esquerda/direita (resultado do jogador 1)

    if (tabuleiro[0][0] == 'x' && tabuleiro [1][1] == 'x' && tabuleiro [2][2] == 'x'){
        contJ1++;
    }
    if (tabuleiro[0][2] == 'x' && tabuleiro [1][1] == 'x' && tabuleiro [2][0] == 'x'){
        contJ1++;
    }

    //Verifica o(s) resultado(s) na(s) posicao(ões) diagonal esquerda/direita (resultado do jogador 2)

    if (tabuleiro[0][0] == 'o' && tabuleiro [1][1] == 'o' && tabuleiro [2][2] == 'o'){
        contJ2++;
    }
    if (tabuleiro[0][2] == 'o' && tabuleiro [1][1] == 'o' && tabuleiro [2][0] == 'o'){
        contJ2++;
    }

    // mostra a quantidade de pontos que cada um fez e mostra quem ganhou

    printf ("\n");
    printf ("Jogador 1 fez %d ponto (s)\n", contJ1);
    printf ("Jogador 2 fez %d ponto (s)\n\n", contJ2);

    if (contJ1 > contJ2){
        printf ("Jogador 1 ganhou!\n");
    }else if (contJ1 < contJ2){
        printf ("Jogador 2 ganhou!\n");
    }else {
        printf ("Jogo empatou!!\n");
    }

}

void resultado_PvIA (char tabuleiro [DIM][DIM]){
    int i;
    int contJ1, contJ2;

    contJ1 = 0;
    contJ2 = 0;

    //Verifica o (s) resultado (s) na (s) posicao (oes) horizontal do tabuleiro

    for (i = 0; i < DIM; i++){
        if(tabuleiro[i][0] == 'x' && tabuleiro[i][1] == 'x' && tabuleiro[i][2] == 'x'){
            contJ1++;
        }else if(tabuleiro[i][0] == 'o' && tabuleiro[i][1] == 'o' && tabuleiro[i][2] == 'o'){
            contJ2++;
        }
    }

    //Verifica o (s) resultado (s) na (s) posicao (oes) vertical do tabuleiro

    for (i = 0; i < DIM; i++){
        if(tabuleiro[0][i] == 'x' && tabuleiro[1][i] == 'x' && tabuleiro[2][i] == 'x'){
            contJ1++;
        }else if(tabuleiro[0][i] == 'o' && tabuleiro[1][i] == 'o' && tabuleiro[2][i] == 'o'){
            contJ2++;
        }
    }

    //Verifica o(s) resultado(s) na(s) posicao(oes) diagonal esquerda/direita (resultado do jogador)

    if (tabuleiro[0][0] == 'x' && tabuleiro [1][1] == 'x' && tabuleiro [2][2] == 'x'){
        contJ1++;
    }
    if (tabuleiro[0][2] == 'x' && tabuleiro [1][1] == 'x' && tabuleiro [2][0] == 'x'){
        contJ1++;
    }

    //Verifica o(s) resultado(s) na(s) posicao(ões) diagonal esquerda/direita (resultado da maquina)

    if (tabuleiro[0][0] == 'o' && tabuleiro [1][1] == 'o' && tabuleiro [2][2] == 'o'){
        contJ2++;
    }
    if (tabuleiro[0][2] == 'o' && tabuleiro [1][1] == 'o' && tabuleiro [2][0] == 'o'){
        contJ2++;
    }

    // mostra a quantidade de pontos que cada um fez e mostra quem ganhou

    printf ("\n");
    printf ("Jogador fez %d ponto (s)\n", contJ1);
    printf ("O computador fez %d ponto (s)\n\n", contJ2);

    if (contJ1 > contJ2){
        printf ("Jogador ganhou!\n");
    }else if (contJ1 < contJ2){
        printf ("O computador ganhou!\n");
    }else {
        printf ("Jogo empatou!!\n");
    }

}

void jogador_vs_maquina (char tabuleiro [DIM][DIM]){
    int  i, j, aux;

    mostrar_tabuleiro (tabuleiro);
    aux = 0;

    do{
        do{

            // Nessa etapa o programa solicita a posicao da matriz que o jogador deseja atribuir um valor
            // Caso a posicao desejada possuir um valor que maquina ou proprio jogador atribuiu nas jogadas anteriores aparece uma mensagem de erro
            // Se isso acontecer, o programa solicita uma nova posicao na matriz.

            printf ("\nVez do jogador!\n");
            do{

                //A linha informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("\nEscolha uma linha do tabuleiro\n");
                scanf (" %d", &i);
                if (i<0 || i> 2){
                    printf ("\nLinha invalida na matriz!\n\n");
                }
            }while (i<0 || i>2);
            do{

                //A coluna informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("\nEscolha uma coluna do tabuleiro\n");
                scanf (" %d", &j);
                if (j<0 || j> 2){
                    printf ("\ncoluna invalida na matriz!\n\n");
                }
            }while (j<0 || j>2);
            if (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x'){
                printf ("\nPosicao invalida!!\n");
            }

            //Se houver disponibilidade e, ao mesmo tempo, atender os requisitos na condicao
            // o valor eh atribuido. Caso o contrario e feito uma nova leitura

        }while (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x');

        // Apos a verificacao o valor eh atribuido na posicao da matriz

        printf ("\n");
        tabuleiro [i][j] = 'x';
        aux++;
        mostrar_tabuleiro (tabuleiro);

        //Se o jogador comecar a rodada no inicio do jogo, ele possui cinco rodadas e maquina possui 4
        // Na ultima rodada so eh lido a posicao da matriz que jogador definir

        if (aux == 9){
            break;
        }

        //Nessa etapa a maquina vai solecionar uma posicao na matriz
        //Eh feito um teste antes de atribuir o valor para matriz
        //Assim garantimos que a jogada da maquina nao vai substituir a jogada anterior do jogador e nem atribuir um valor na jogada anterior dela

        printf ("\nVez da maquima!\n\n");
        do{

            //A posicao da matriz e definido nessa etapa do programa
            // Eh feito um sorteio entre os numeros 0 a 2

            i =  rand()%3;
            j =  rand()%3;
        }while (tabuleiro [i][j] == 'x' || tabuleiro [i][j] == 'o');

        // Apos a verificacao o valor eh atribuido na posicao da matriz

        tabuleiro [i][j] = 'o';
        aux++;
        mostrar_tabuleiro (tabuleiro);

    }while(aux<9);

    //verifica a pontuacao atual do jogador e da maquina

    resultado_PvIA (tabuleiro);

}

void maquina_vs_jogador (char tabuleiro [DIM][DIM]){
    int i, j, aux;

    aux = 0;

    printf ("\nVez da maquina!\n");
    do{
        do{
            //Nessa etapa a maquina vai solecionar uma posicao na matriz
            //Eh feito um teste antes de atribuir o valor para matriz
            //Assim garantimos que a jogada da maquina nao vai substituir a jogada anterior do jogador e nem atribuir um valor na jogada anterior dela

            //A posicao da matriz e definido nessa etapa do programa
            // Eh feito um sorteio entre os numeros 0 a 2

            i = rand()%3;
            j = rand()%3;

        }while (tabuleiro [i][j] == 'x' || tabuleiro [i][j] == 'o');

        // Apos a verificacao o valor eh atribuido na posicao da matriz

        tabuleiro [i][j] = 'o';
        printf("\n");
        mostrar_tabuleiro (tabuleiro);
        aux++;

        //Se a maquina comecar a rodada no inicio do jogo, ela possui cinco rodadas e o jogador 4
        // Na ultima rodada so eh lido a posicao da matriz que a maquina definir

        if (aux == 9){
            break;
        }
        do{

            // Nessa etapa o programa solicita a posicao da matriz que o jogador deseja atribuir um valor
            // Caso a posicao desejada possuir um valor que maquina ou proprio jogador atribuiu nas jogadas anteriores aparece uma mensagem de erro
            // Se isso acontecer, o programa solicita uma nova posicao na matriz.

            printf ("\nVez do jogador!\n");
            do{

                //A linha informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("\nEscolha uma linha do tabuleiro\n");
                scanf (" %d", &i);
                if (i<0 || i> 2){
                    printf ("\nLinha invalida na matriz!\n\n");
                }
            }while (i<0 || i>2);
            do{

                //A coluna informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("\nEscolha uma coluna do tabuleiro\n");
                scanf (" %d", &j);
                if (j<0 || j> 2){
                    printf ("\ncoluna invalida na matriz!\n\n");
                }
            }while (j<0 || j>2);
            if (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x'){
                printf ("\nPosicao invalida!!\n");
            }

            //Se houver disponibilidade e, ao mesmo tempo, atender os requisitos na condicao
            // o valor eh atribuido. Caso o contrario e feito uma nova leitura

        }while (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x');
        printf("\n");

        // Apos a verificacao o valor eh atribuido na posicao da matriz
        tabuleiro [i][j] = 'x';
        aux++;
        mostrar_tabuleiro (tabuleiro);
        printf ("\nVez da maquina!\n");

    }while (aux<9);

    //verifica a pontuacao atual do jogador e da maquina

    resultado_PvIA (tabuleiro);

}

void jogador1_vs_jogador2 (char tabuleiro [DIM][DIM]){
    int  i, j, aux;

    setbuf(stdout, NULL);
    printf("\n");
    mostrar_tabuleiro (tabuleiro);
    aux = 0;

    do{
        do{

            // Nessa etapa o programa solicita uma posicao valida na matriz que o jogador 1 deseja atribuir um valor
            // Caso a posicao desejada possuir um valor que o jogador 2 ou proprio jogador 1 atribuiu nas jogadas anteriores aparece uma mensagem de erro
            // Se isso acontecer, o programa solicita uma nova posicao na matriz.

            printf ("\nVez do jogador 1!\n\n");
            do{

                //A linha informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("Escolha uma linha do tabuleiro\n");
                scanf (" %d", &i);
                if (i<0 || i> 2){
                    printf ("\nLinha invalida na matriz!\n\n");
                }
            }while (i<0 || i>2);
            do{

                //A coluna informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("Escolha uma coluna do tabuleiro\n");
                scanf (" %d", &j);
                if (j<0 || j> 2){
                    printf ("\ncoluna invalida na matriz!\n\n");
                }
            }while (j<0 || j>2);
            if (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x'){
                printf ("\nPosicao invalida!!\n");
            }

            //Se houver disponibilidade e, ao mesmo tempo, atender os requisitos na condicao
            // o valor eh atribuido. Caso o contrario e feito uma nova leitura

        }while (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x');

        // Apos a verificacao o valor eh atribuido na posicao da matriz

        printf ("\n");
        tabuleiro [i][j] = 'x';
        aux++;
        mostrar_tabuleiro (tabuleiro);

        //Se o jogador 1 comecar a rodada no inicio do jogo, ele possui cinco rodadas e o jogador 2 possui 4
        // Na ultima rodada so eh lido a posicao da matriz que jogador 1 definir

        if (aux == 9){
            break;
        }

        do{

            // Nessa etapa o programa solicita uma posicao valida na matriz que o jogador 2 deseja atribuir um valor
            // Caso a posicao desejada possuir um valor que o jogador 1 ou proprio jogador 2 atribuiu nas jogadas anteriores aparece uma mensagem de erro
            // Se isso acontecer, o programa solicita uma nova posicao na matriz.

            printf ("\nVez do jogador 2!\n\n");
            do{

                //A linha informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("Escolha uma linha do tabuleiro\n");
                scanf (" %d", &i);
                if (i<0 || i> 2){
                    printf ("\nLinha invalida na matriz!\n\n");
                }
            }while (i<0 || i>2);
            do{

                //A coluna informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("Escolha uma coluna do tabuleiro\n");
                scanf (" %d", &j);
                if (j<0 || j> 2){
                    printf ("\ncoluna invalida na matriz!\n\n");
                }
            }while (j<0 || j>2);
            if (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x'){
                printf ("\nPosicao invalida!!\n");
            }

            //Se houver disponibilidade e, ao mesmo tempo, atender os requisitos na condicao
            // o valor eh atribuido. Caso o contrario e feito uma nova leitura

        }while (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x');

        // Apos a verificacao o valor eh atribuido na posicao da matriz

        printf ("\n");
        tabuleiro [i][j] = 'o';
        aux++;
        mostrar_tabuleiro (tabuleiro);

    }while (aux < 9);

    //mostra os resultados na tela

    resultado_PvP (tabuleiro);

}

void jogador2_vs_jogador1 (char tabuleiro [DIM][DIM]){
    int  i, j, aux;

    printf("\n");
    mostrar_tabuleiro (tabuleiro);
    aux = 0;

    do{
        do{

            // Nessa etapa o programa solicita uma posicao valida na matriz que o jogador 2 deseja atribuir um valor
            // Caso a posicao desejada possuir um valor que o jogador 1 ou proprio jogador 2 atribuiu nas jogadas anteriores aparece uma mensagem de erro
            // Se isso acontecer, o programa solicita uma nova posicao na matriz.

            printf ("\nVez do jogador 2!\n\n");
            do{

                //A linha informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("Escolha uma linha do tabuleiro\n");
                scanf (" %d", &i);
                if (i<0 || i> 2){
                    printf ("\nLinha invalida na matriz!\n\n");
                }
            }while (i<0 || i>2);
            do{

                //A coluna informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("Escolha uma coluna do tabuleiro\n");
                scanf (" %d", &j);
                if (j<0 || j> 2){
                    printf ("\ncoluna invalida na matriz!\n\n");
                }
            }while (j<0 || j>2);
            if (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x'){
                printf ("\nPosicao invalida!!\n");
            }

            //Se houver disponibilidade e, ao mesmo tempo, atender os requisitos na condicao
            // o valor eh atribuido. Caso o contrario e feito uma nova leitura

        }while (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x');

        // Apos a verificacao o valor eh atribuido na posicao da matriz

        printf ("\n");
        tabuleiro [i][j] = 'o';
        aux++;
        mostrar_tabuleiro (tabuleiro);

        //Se o jogador 2 comecar a rodada no inicio do jogo, ele possui cinco rodadas e o jogador 1 possui 4
        // Na ultima rodada so eh lido a posicao da matriz que jogador 2 definir

        if (aux == 9){
            break;
        }

        do{

            // Nessa etapa o programa solicita uma posicao valida na matriz que o jogador 1 deseja atribuir um valor
            // Caso a posicao desejada possuir um valor que o jogador 2 ou proprio jogador 1 atribuiu nas jogadas anteriores aparece uma mensagem de erro
            // Se isso acontecer, o programa solicita uma nova posicao na matriz.

            printf ("\nVez do jogador 1!\n\n");
            do{

                //A linha informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("Escolha uma linha do tabuleiro\n");
                scanf (" %d", &i);
                if (i<0 || i> 2){
                    printf ("\nLinha invalida na matriz!\n\n");
                }
            }while (i<0 || i>2);
            do{

                //A coluna informada eh verificada
                //Caso seja um valor invalido o programa solicita um novo valor

                printf ("Escolha uma coluna do tabuleiro\n");
                scanf (" %d", &j);
                if (j<0 || j> 2){
                    printf ("\ncoluna invalida na matriz!\n\n");
                }
            }while (j<0 || j>2);
            if (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x'){
                printf ("\nPosicao invalida!!\n");
            }

            //Se houver disponibilidade e, ao mesmo tempo, atender os requisitos na condicao
            // o valor eh atribuido. Caso o contrario e feito uma nova leitura

        }while (tabuleiro [i][j] == 'o' || tabuleiro [i][j] == 'x');

        // Apos a verificacao o valor eh atribuido na posicao da matriz

        printf ("\n");
        tabuleiro [i][j] = 'x';
        aux++;
        mostrar_tabuleiro (tabuleiro);

    }while (aux < 9);

    //mostra os resultados na tela

    resultado_PvP (tabuleiro);

}

int main (void){
    char tabuleiro [DIM][DIM] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    int op, y, x;

    setbuf(stdout, NULL);
    srand(time(0));

    //sorteio para definir que comeca primeiro

    y =  1 + rand()%2;
    
    printf ("JOGO DA VELHA - VERSAO 1.0\n\n");
    printf (" 1 - PLAYER VS I.A\n");
    printf (" 2 - PLAYER VS PLAYER\n\n");

    //leitura pra ver qual de jogo o (s) jogador (es) vai (ao) escolher

    printf("ESCOLHA UMA OPCAO:");
    scanf (" %d", &op);

    switch (op){
        case 1:

            //Essa parte do programa pergunta qual opcao o jogador quer
            // e dependendo do valor da variavel "Y" eh determinado quem comeca o jogo

            printf ("\nQual voce escolhe?\n\n");
            printf ("1 - Cara\n");
            printf ("2 - Coroa\n\n");
            scanf (" %d", &x);
            printf ("\n");

            if (x == y){
                jogador_vs_maquina (tabuleiro);
                break;
            }else{
                maquina_vs_jogador (tabuleiro);
                break;
            }
           
        case 2:

            //Essa parte do programa pergunta qual opcao o jogador quer
            // e dependendo do valor da variavel "Y" eh determinado quem comeca o jogo

            printf ("\nDefine quem vai escolher:\n\n");
            printf ("1 - Cara\n");
            printf ("2 - Coroa\n\n");
            scanf (" %d", &x);
            printf ("\n");

            if (x == y){
                jogador1_vs_jogador2 (tabuleiro);
                break;
            }else{
                jogador2_vs_jogador1 (tabuleiro);
                break;
            }

        default:
        
            printf("\n");
            printf("OPCAO INVALIDA!!\n");
            break;
    }

    return EXIT_SUCCESS;
}
