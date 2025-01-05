#include "evento.h"
#include <stdio.h>

void cadastrarEvento(Evento* eventos, int* numEventos){
    if(*numEventos < 10){
        scanf("%s", eventos[*numEventos].nome);
        scanf("%*c");
        scanf("%02d %02d %04d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
        (*numEventos)++;
        scanf("%*c");
        printf("Evento cadastrado com sucesso!\n");
    } else {
        printf("Limite de eventos atingido!\n");
    }
}

void exibirEventos(Evento* eventos, int* numEventos){
    if(*numEventos == 0){
        printf("Nenhum evento cadastrado\n");
    } else {
        printf("Eventos cadastrados:\n");
        for(int i=0; i<*numEventos; i++){
            printf("%d - %s - %d/%d/%d\n", i, (eventos[i].nome), eventos[i].dia, eventos[i].mes, eventos[i].ano);
        }
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int indice = 0, flag = 0;
    scanf("%d", &indice);
    if(* numEventos == 0){
        printf("Indice invalido\n");
    } else {
        for(int i=0; i<=*numEventos; i++){
            if(indice == i){
                flag = 1;
            }
        }
        if(flag == 1){
            scanf("%d %d %d", &eventos[indice].dia, &eventos[indice].mes, &eventos[indice].ano);
            printf("Data modificada com sucesso!\n");
        } else {
            printf("Indice invalido!\n");
        }
    }


}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    int flag1 = 0, flag2 = 0, aux;
    for(int i=0; i<*numEventos; i++){
        if(*indiceA == i){
            flag1 = 1;
        } 
        if(*indiceB == i){
            flag2 = 1;
        }
    }

    if(flag1 == 0 || flag2 == 0){
        printf("Indices invalidos!\n");
    } else {
        aux = *indiceA;
        *indiceA = *indiceB;
        *indiceB = aux;
        printf("Eventos trocados com sucesso!\n");
    }

}