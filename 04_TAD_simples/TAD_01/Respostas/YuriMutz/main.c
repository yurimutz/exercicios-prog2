#include <stdio.h>
#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogada.h"

int main(){

    tJogo jogo;
    jogo = CriaJogo();

    while(1){
        ComecaJogo(jogo);
        //printf("Jogar novamente? (s,n)\n");
        if(ContinuaJogo()){
            jogo = CriaJogo();
            continue;
        } else {
            break;
        }
    }


return 0;
}
