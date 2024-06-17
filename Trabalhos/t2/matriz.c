#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"



void inicializaMatriz(Tabuleiro* mat){
    for(int i=0; i<TAM; i++){
        for(int j=0; J<TAM; j++){
            mat[i][j] = ' ';
        }
    }
}

void imprimirJogo(Tabuleiro* mat){
    for(int i=0; i< TAM; i++){
        for(int j=0; j<TAM; j++){
            printf("%c", mat[i][j]);
                if(j < 2){
                    printf("|");
                }
        }
        if(i < 2){
            printf("\n-------------");
        }
        printf("\n");
    }

}

int letraValida(Tabuleiro* mat){
    if(mat->letra == 'x' || letra == 'o'){
        return 1;
    }else{
        return 0;
    }
}

int coordenadaValida(int x, int y){
    if(x >=0 && x < 3){
        if(y >=0 && y < 3){
            return 1;
        }
    }
    return 0;
}

int posicaoVazia(Tabuleiro* mat, int x, int y){
    if(mat[x][y] != 'x' && mat[x][y] != '0'){
        return 1;
    }
    return 0;
}


