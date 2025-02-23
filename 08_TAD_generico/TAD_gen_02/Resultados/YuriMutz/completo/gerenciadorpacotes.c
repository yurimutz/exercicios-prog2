#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>

struct gerenciadorpacotes{

    tPacote **pacotes;
    int numPacotes;

};

tGerenciador* CriaGerenciador(){

    tGerenciador *gerenciador = malloc(sizeof(tGerenciador));

    gerenciador->numPacotes = 0;

    gerenciador->pacotes = NULL;

    return gerenciador;

}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){

    if(geren->numPacotes == 0){

        geren->pacotes = malloc(sizeof(tPacote*));

        geren->pacotes[geren->numPacotes] = pac;

        geren->numPacotes++;

    } else {

        geren->pacotes = realloc(geren->pacotes, sizeof(tPacote*) * (geren->numPacotes + 1));

        geren->pacotes[geren->numPacotes] = pac;

        geren->numPacotes++;

    }


}

void DestroiGerenciador(tGerenciador* geren){

    for(int i = 0; i < geren->numPacotes; i++){

        if(geren->pacotes[i] != NULL){

            DestroiPacote(geren->pacotes[i]);

        }

    }

    free(geren->pacotes);

    free(geren);

}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){

    ImprimePacote(geren->pacotes[idx - 1]);

}

void ImprimirTodosPacotes(tGerenciador* geren){

    for(int i = 0; i < geren->numPacotes; i++){

        if(geren->pacotes[i] != NULL){

            ImprimePacote(geren->pacotes[i]);

        }

    }

}