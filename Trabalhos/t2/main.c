#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "tela.h"
#include "tecla.h"
#define TAM 3
// Define valores constantes para os limites da tela
#define LIN_MAX 24
#define COL_MAX 79

// Estrutura para o tabuleiro
typedef struct {
    char mat[TAM][TAM];
    char letra;
} Tabuleiro;

// Função para inicializar o tabuleiro
void inicializaMatriz(Tabuleiro* mat) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            mat->mat[i][j] = ' ';
        }
    }
}

// Função para desenhar o contorno da tela
void desenha_contorno(void) {
    tela_cor_normal();
    tela_limpa();
    tela_cor_fundo(30, 70, 22);

    // Desenhar linha superior
    tela_lincol(1, 1);
    for (int i = 1; i <= COL_MAX; i++) {
        putchar(' ');
    }

    // Desenhar linha inferior
    tela_lincol(LIN_MAX, 1);
    for (int i = 1; i <= COL_MAX; i++) {
        putchar(' ');
    }

    // Desenhar linhas laterais
    for (int i = 2; i < LIN_MAX; i++) {
        tela_lincol(i, 1);
        putchar(' ');
        tela_lincol(i, COL_MAX);
        putchar(' ');
    }
    tela_cor_normal();
}

// Função para desenhar o jogador
void desenha_jogador(int lin, int col) {
    tela_cor_fundo(20, 50, 90);
    tela_lincol(lin, col);
    puts("¤");
}

// Função para animação de fim de jogo
void anima_final(int pontos) {
    for (int i = 1; i <= LIN_MAX; i++) {
        desenha_contorno();
        tela_lincol(LIN_MAX / 2 - 2, COL_MAX / 2 - 6);
        printf("PONTOS: %04d", pontos);
        if (tecla_le_char() == '\n') break;
        for (int j = i; j <= LIN_MAX; j++) {
            tela_cor_fundo(200 - 150 * i / LIN_MAX - 50 * j / LIN_MAX, 90, 30);
            tela_lincol(j, 1);
            for (int k = 1; k <= COL_MAX; k++) putchar(' ');
        }
        tela_atualiza();
    }
}

void imprimirJogo(Tabuleiro* mat) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c", mat->mat[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        if (i < 2) {
            printf("\n-------------");
        }
        printf("\n");
    }
}


int main() {
    // Inicialização das variáveis que representam o estado do jogo
    int lin_jogador = 10;
    int col_jogador = 30;
    int tempo_de_jogo = 0;
    bool fim = false;
    Tabuleiro* mat = (Tabuleiro*) malloc(sizeof(Tabuleiro));

    if (mat == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return EXIT_FAILURE;
    }

    // Inicialização do programa
    tela_ini();
    tecla_ini();
    inicializaMatriz(mat);
    tela_mostra_cursor(false);

    // Laço principal onde uma partida é jogada
    while (!fim) {
        // Captura entrada do jogador
        char c = tecla_le_char();
        if (c == 's' && lin_jogador < LIN_MAX - 1) lin_jogador++;
        if (c == 'w' && lin_jogador > 2) lin_jogador--;
        if (c == 'a' && col_jogador > 2) col_jogador--;
        if (c == 'd' && col_jogador < COL_MAX - 1) col_jogador++;
        if (c == '\n') fim = true;

        // Verifica condição de término do jogo
        if (tempo_de_jogo > 1000) fim = true;

        // Atualiza a tela
        desenha_contorno();
        desenha_jogador(lin_jogador, col_jogador);
        imprimirJogo(mat);
        tela_atualiza();

        tempo_de_jogo++;
    }

    // Finalização do programa
    anima_final(tempo_de_jogo);
    tecla_fim();
    tela_fim();
    free(mat);

    return 0;
}
