#include <stdbool.h>

struct tabuleiro{
    char** mat;
    bool livre;

};
typedef struct tabuleiro Tabuleiro;

Tabuleiro* criaMatriz();

bool testaJogada(Tabuleiro* mat);

void insereJogada(Tabuleiro* mat, int jogador, char peca);
