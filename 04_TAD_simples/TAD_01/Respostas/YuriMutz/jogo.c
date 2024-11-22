#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"
#include <stdio.h>

tJogo CriaJogo(){
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}

void ComecaJogo(tJogo jogo){
    tJogador teste = jogo.jogador1;
    int flag = 0;

    
    while(!AcabouJogo(jogo)){
        jogo.tabuleiro = JogaJogador(teste, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if(VenceuJogador(teste, jogo.tabuleiro)==1){
            printf("JOGADOR %d Venceu!\n", teste.id);
            flag = 1;
            break;
        }

        if(teste.id == ID_JOGADOR_1){
            teste = jogo.jogador2;
        } else {
            teste = jogo.jogador1;
        }
            
    }
        
    if(flag == 0){
        if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)==1){
            printf("JOGADOR 1 Venceu!\n");
        } else if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)==1){
            printf("JOGADOR 2 Venceu!\n");
        } else {
            printf("Sem vencedor!\n");
        }
    }

        printf("Jogar novamente? (s,n)\n"); 

}

int AcabouJogo(tJogo jogo){
    if(TemPosicaoLivreTabuleiro(jogo.tabuleiro)){
        return 0;
    } else {
        return 1;
    }
}

int ContinuaJogo(){
    char mode=0;
    scanf("%*c");
    scanf("%c", &mode);
    scanf("%*c");
    if(mode == 's'){       
        return 1;
    } else if(mode == 'n'){
        return 0;
    }
}