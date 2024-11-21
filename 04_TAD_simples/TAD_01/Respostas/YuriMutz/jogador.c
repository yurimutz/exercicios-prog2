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
    jogada = LeJogada();
    MarcaPosicaoTabuleiro(tabuleiro, jogador.id, jogada.x, jogada.y);
    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro);