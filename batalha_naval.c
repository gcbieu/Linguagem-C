#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define NUMERO_TENTATIVAS 5

int main (void) {
setlocale(LC_ALL, "portuguese");
srand(time(NULL));

char tabuleiro [5][5];

printf("#### Bem-Vindo a batalha naval:) ####");

printf("\n\n");

 for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
        tabuleiro[i][j] = '~';
    }
   }
    int acertos = 0, erros = 0;
    int linha_jogador, colunajogador;
    char mostrar;
    int linha = rand () %5;
    int coluna = rand () %5;
    tabuleiro [linha][coluna] = 'N';

do{
    printf("LINHA\n");
    scanf ("%d", &linha_jogador);

    printf("COLUNA\n");
    scanf ("%d", &colunajogador);

    if (linha_jogador < 0 || linha_jogador > 4 || colunajogador < 0 || colunajogador > 4) {
    printf("Posição inválida! Digite números entre 0 e 4.\n");
    continue;
}

    if (tabuleiro[linha_jogador][colunajogador] == 'N') {
        printf("ACERTOU!\n");
        acertos = 1;
        tabuleiro[linha_jogador][colunajogador] = '#';
    } else {
        printf("ERROU!\n");
        tabuleiro[linha_jogador][colunajogador] = 'X';
        erros ++;
    }
 for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        mostrar = tabuleiro[i][j]; 
        if (mostrar == 'N'){
            mostrar = '~';
        }
        printf("%c", mostrar);
    }
    printf("\n");
}
    printf("Tentativas restantes: %d\n", NUMERO_TENTATIVAS - erros);
  
 } while (erros < NUMERO_TENTATIVAS && !acertos);

   if (acertos == 1){
        printf("Parabéns, você afundou o navio!\n");
    } else {
        printf("Fim de jogo! O navio estava na posição [%d][%d]\n", linha, coluna);
    }

 return 0;
}