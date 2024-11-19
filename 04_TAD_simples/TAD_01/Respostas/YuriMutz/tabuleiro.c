#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabuleiro;
    int i=0, j=0;

    for(i=0; i < TAM_TABULEIRO; i++){
        for(j=0; j < TAM_TABULEIRO; j++){
            tabuleiro.posicoes[i][j] = '-';
        }
    }

    tabuleiro.peca1 = 'X';
    tabuleiro.peca2 = '0';
    tabuleiro.pecaVazio = '-';

    return tabuleiro;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    if(peca == 1){
        tabuleiro.posicoes[x][y] = tabuleiro.peca1;
    } else {
        tabuleiro.posicoes[x][y] = tabuleiro.peca2;
    }
    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i=0, j=0;

    for(i=0; i < TAM_TABULEIRO; i++){
        for(j=0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == '-'){
                return 1;
            }
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    if(peca == 1){
        if(tabuleiro.posicoes[x][y] == tabuleiro.peca1){
            return 1;
        } else {
            return 0;
        }
    } else {
        if(tabuleiro.posicoes[x][y] == tabuleiro.peca2){
            return 1;
        } else {
            return 0;
        }    
    }
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    if(tabuleiro.posicoes[x][y] == '-'){
        return 1;
    } else {
        return 0;
    }
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if((x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO)){
        return 1;
    } else {
        return 0;
    }
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i=0, j=0;

    for(i=0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(j=0; j < TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[j][i]);
        }
        printf("\n");
    }    
}