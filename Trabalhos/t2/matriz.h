#include <stdbool.h>
#define TAM 3

struct tabuleiro{
    char mat [TAM][TAM];
    bool livre;
    char letra;

};
typedef struct tabuleiro Tabuleiro;

void inicializaMatriz();

int letraValida(Tabuleiro* mat);

void imprimirJogo(Tabuleiro* mat);

int posicaoVazia(Tabuleiro* mat, int x, int y);

