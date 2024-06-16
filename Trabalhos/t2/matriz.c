#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"

#define TAM 3


Tabuleiro* criaMatriz(){
    char** mat = (char*) malloc(TAM*sizeof(char*));
    for(int i=0; i<TAM; i++){
        mat[i] = (char*) malloc(TAM* sizeof(char));
    }
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            mat[i][j] = NULL;
        }
    }

    return mat;
}

bool testaJogada(Tabuleiro* mat){
    bool valida = false;

    return valida;
}

void insereJogada(Tabuleiro* mat, int jogador, char peca){
    bool valida = testaJogada(mat);
    if(valida == true){
        mat->livre = false;
    }

}




