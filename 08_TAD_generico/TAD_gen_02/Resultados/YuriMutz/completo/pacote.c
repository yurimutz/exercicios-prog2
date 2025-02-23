#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

// typedef enum {
//     INT = 1,
//     CHAR = 2
// } Type;

// typedef struct pacote tPacote;

struct pacote{

    void *vet;
    Type tipo;
    int numElem;
    int verificacao;

};

tPacote* CriaPacote(Type type, int numElem){

    tPacote *pac = malloc(sizeof(tPacote));

    if(type == CHAR){

        pac->vet = malloc(sizeof(char) * (numElem+1));

    } else {

        pac->vet = malloc(sizeof(int) * (numElem));

    }

    pac->numElem = numElem;

    pac->tipo = type;

    pac->verificacao = 0;

    printf("\n");
    printf("Digite o conteúdo do vetor/mensagem:");

    return pac;

}

void DestroiPacote(tPacote* pac){

    free(pac->vet);

    free(pac);

}

void LePacote(tPacote* pac){

    if(pac->tipo == CHAR){

        char *aux = (char*)pac->vet;

        scanf("%*[\n]");
        scanf("%[^\n]", aux);
        scanf("%*[\n]");


    } else {

        int *aux = (int*)pac->vet;

        for(int i = 0; i < pac->numElem; i++){

            scanf("%d ", &aux[i]);

        }

    }


}

void ImprimePacote(tPacote* pac){

    if(pac->vet != NULL){

        CalculaSomaVerificacaoPacote(pac);

        if(pac->tipo == CHAR){

            printf("%d ", pac->verificacao);

            char *aux = (char*)pac->vet;

            for(int i = 0; i < pac->numElem; i++){

                printf("%c", aux[i]);

            }

        } else {

            printf("%d ", pac->verificacao);

            int *aux = (int*)pac->vet;

            for(int i = 0; i < pac->numElem; i++){

                printf("%d ", aux[i]);

            }

        }

        printf("\n");

    }

}

void CalculaSomaVerificacaoPacote(tPacote* pac){

    if(pac->tipo == CHAR){

        char *aux = (char*)pac->vet;

        for(int i = 0; i < pac->numElem; i++){

            pac->verificacao += aux[i];

        }

    } else {

        int *aux = (int*)pac->vet;

        for(int i = 0; i < pac->numElem; i++){

            pac->verificacao += aux[i];

        }

    }

}