#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"
#include <stdio.h>

// typedef struct{
//     tTabuleiro tabuleiro;
//     tJogador jogador1;
//     tJogador jogador2;
    
// } tJogo;

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}

void ComecaJogo(tJogo jogo){
    tJogador teste = jogo.jogador1;
   
    while(1){
        while(!AcabouJogo(jogo)){
            jogo.tabuleiro = JogaJogador(teste, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
            if(teste.id == ID_JOGADOR_1){
                teste = jogo.jogador2;
            } else {
                teste = jogo.jogador1;
            }
        }
        if(ContinuaJogo()){
            jogo = CriaJogo();
            continue;
        } else {
            break;
        }
    }
        
}

int AcabouJogo(tJogo jogo){
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        return 0;
    } else {
        return 1;
    }
}

int ContinuaJogo(){
    char modo[3];
    int i = 0;
    
}