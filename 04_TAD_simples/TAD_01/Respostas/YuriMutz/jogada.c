#include "jogada.h"
#include <stdio.h>

tJogada LeJogada(){
    tJogada jogada;
    jogada.x = 1001, jogada.y = 1001; 
    printf("Digite uma posicao (x e y):\n");
    scanf("%d%d", &jogada.x, &jogada.y);

    if(jogada.x != 1001 && jogada.y != 1001){
        jogada.sucesso = 1;
    } else {
        jogada.sucesso = 0;
    }
    return jogada;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    if(jogada.sucesso == 1){
        return 1;
    } else {
        return 0;
    }
}