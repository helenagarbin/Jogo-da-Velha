#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char L1 = '1', L2 = '2', L3 = '3',
         L4 = '4', L5 = '5', L6 = '6',
         L7 = '7', L8 = '8', L9 = '9';
    //cada variável representando as posições do tabuleiro do jogo

    int jogador = 1, jogadas = 0;
    //variável é usada para controlar qual jogador está jogando
    // variável jogadas é usada para contar o número de jogadas feitas.

    char vencedor = ' ';
    //armazena o símbolo ( X ou )do jogador que venceu o jogo da velha

    while (jogadas < 9 && vencedor == ' ') //vai repetir até todas as posições do tabuleiro sejam utilizadas, ou seja menor que 9, e enquanto o vencedor for um espaço em branco, ninguem tiver vencido ou ocorrer o emapate.
    {
        int escolha;
        char simbolo = (jogador == 1) ? 'X' : 'O';
        //variável que define o simbolo de cada jogador

        printf("\n %c | %c | %c \n", L1, L2, L3);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", L4, L5, L6);
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", L7, L8, L9);
        //imprimir o tabuleiro


        printf("\nJogador %d, escolha uma posição para jogar (%c): ", jogador, simbolo);
        scanf("%d", &escolha);
        //Esta linha solicita ao jogador atual para escolher uma posição para jogar, mostrando o número do jogador e o símbolo que ele deve usar.


        if (escolha >= 1 && escolha <= 9)
        {
            char *posicao;

            switch (escolha)
            {
                case 1:
                    posicao = &L1;
                    break;
                case 2:
                    posicao = &L2;
                    break;
                case 3:
                    posicao = &L3;
                    break;
                case 4:
                    posicao = &L4;
                    break;
                case 5:
                    posicao = &L5;
                    break;
                case 6:
                    posicao = &L6;
                    break;
                case 7:
                    posicao = &L7;
                    break;
                case 8:
                    posicao = &L8;
                    break;
                case 9:
                    posicao = &L9;
                    break;
//Este bloco de código associa a escolha do jogador à variável correspondente ao local no tabuleiro do jogo da velha.
            }
            if (*posicao == 'X' || *posicao == 'O')
            {
                printf("Tente novamente jogador, está posição já esocupada\n");
                continue;
            }
//verificar se a posição escolhida já foi ocupada

            *posicao = simbolo;
            jogadas++;
//atualizaçao do tabuleiro com o símbolo do jogador na posição escolhida e incrementam o contador de jogadas.

            if ((L1 == L2 && L2 == L3) || (L4 == L5 && L5 == L6) || (L7 == L8 && L8 == L9) ||
                (L1 == L4 && L4 == L7) || (L2 == L5 && L5 == L8) || (L3 == L6 && L6 == L9) ||
                (L1 == L5 && L5 == L9) || (L3 == L5 && L5 == L7))
            {
                vencedor = simbolo;
            }
//Está linha verificar se houve algum vencedor, comparando as possíveis combinações
            jogador = (jogador == 1) ? 2 : 1;
//alternância do jogador
        }
        else
        {
            printf("Tente novamente, está posição está inválida\n");
        }
    }

    printf("\nFim do Jogo da Velha!\n");
    if (vencedor != ' ')
    {
        printf("Jogador %c venceu!\n", vencedor);
    }
    else
    {
        printf("Empate!\n");
    }

    return 0;
}
