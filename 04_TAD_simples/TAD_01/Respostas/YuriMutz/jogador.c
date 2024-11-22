#include "jogador.h"
#include <stdio.h>
#include "jogada.h"

tJogador CriaJogador(int idJogador){
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada;
    
    while(1){
        printf("Jogador %d\n", jogador.id);
        jogada = LeJogada();
        if(jogada.x < 0 || jogada.x > 2 || jogada.y < 0 || jogada.y>2){
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", jogada.x, jogada.y);               
        } else if(!EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y)){         
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y); 
        } else {
            printf("Jogada [%d,%d]!\n", jogada.x, jogada.y);
            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, jogada.x, jogada.y);
            break;   
        }     
    }
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    int i=0, j=0, numIguais=0;

    //linhas
    for(i=0; i<3; i++){
        numIguais = 0;
        for(j=0; j<3; j++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id)){
                numIguais++;
            }
        }
        if(numIguais == 3){
            return 1;
        }
    }

    //colunas
    for(i=0; i<3; i++){
        numIguais = 0;
        for(j=0; j<3; j++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador.id)){
                numIguais++;
            }
        }
        if(numIguais == 3){
            return 1;
        }
    }

    numIguais = 0;
    //diagonal
    for(i=0; i<3; i++){
        j = i;
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id)){
            numIguais++;
        }
        if(numIguais == 3){
            return 1;
        }
    }

    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id)){
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id)){         
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id)){
                return 1;
            } 
        }
    }

    return 0;
}