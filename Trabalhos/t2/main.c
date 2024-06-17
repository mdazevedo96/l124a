#include<stdio.h>
#include<stdlib.h>
#include "tela.h"
#include "tecla.h"

// define valores constantes para os limites utilizáveis da tela
// (a janela do terminal deve ter pelo menos esse tamanho)
#define LIN_MAX 24
#define COL_MAX 79

void desenha_contorno(void)
{
  // limpa a tela com a cor default
  tela_cor_normal();
  tela_limpa();
  // seleciona uma cor para a borda
  tela_cor_fundo(30, 70, 22);
  // desenha uma linha no topo da tela
  tela_lincol(1, 1);
  for (int i = 1; i <= COL_MAX; i++) {
    putchar(' ');
  }
  // desenha uma linha embaixo da tela
  tela_lincol(LIN_MAX, 1);
  for (int i = 1; i <= COL_MAX; i++) {
    putchar(' ');
  }
  // desenha uma linha em cada lado da tela
  for (int i = 2; i < LIN_MAX; i++) {
    tela_lincol(i, 1);
    putchar(' ');
    tela_lincol(i, COL_MAX);
    putchar(' ');
  }
  tela_cor_normal();
}

void desenha_jogador(int lin, int col)
{
  tela_cor_fundo(20, 50, 90);
  tela_lincol(lin, col);
  puts("¤");
}

void anima_final(int pontos)
{
  for (int i = 1; i <= LIN_MAX; i++) {
    desenha_contorno();
    tela_lincol(LIN_MAX / 2 - 2, COL_MAX / 2 - 6);
    printf("PONTOS: %04d", pontos);
    if (tecla_le_char() == '\n') {
      break;
    }
    for (int j = i; j <= LIN_MAX; j++) {
      tela_cor_fundo(200 - 150 * i / LIN_MAX - 50 * j / LIN_MAX, 90, 30);
      tela_lincol(j, 1);
      for (int k = 1; k <= COL_MAX; k++) {
        putchar(' ');
      }
    }
    tela_atualiza();
  }
}

int main(){

  //inicialização de variáveis que representam o estado do jogo
  int lin_jogador = 10;
  int col_jogador = 30;
  int tempo_de_jogo = 0;
  bool fim = false;
  Tabuleiro* mat;

  //inicialização do programa
  tela_ini();
  tecla_ini();
  tela_mostra_cursor(false);

  //laço principal, onde uma partida é jogada
     while (!fim) {
    // altera o estado do jogo de acordo com a entrada
    char c = tecla_le_char();
    if (c == 's') lin_jogador++;
    if (c == 'w') lin_jogador--;
    if (c == 'a') col_jogador--;
    if (c == 'd') col_jogador++;
    if (c == '\n') fim = true;

    // verifica de atingiu condição de término do jogo
    if (tempo_de_jogo > 1000) {
      fim = true;
    }
    // desenha a tela de acordo com o estado do jogo
    desenha_contorno();
    desenha_jogador(lin_jogador, col_jogador);

   imprimirJogo(mat);

    tela_atualiza();
  }



   //finalização do programa
   anima_final(tempo_de_jogo);
   // volta a tela e teclas para o estado normal
   tecla_fim();
   tela_fim();
}
