#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int *CriaVetor(int tamanho){

    int *p = NULL;

    p = (int *)malloc(tamanho * sizeof(int));

    return p;

}

void LeVetor(int *vetor, int tamanho){

    for(int i=0; i<tamanho; i++){
        scanf("%d", &*(vetor + i));
    }

}

float CalculaMedia(int *vetor, int tamanho){
    
    float media = 0;
    int soma = 0;

    for(int i=0; i<tamanho; i++){
        soma += *(vetor + i);
    }

    media = (float)soma / (float)tamanho;

    return media;

}

void LiberaVetor(int *vetor){

    free(vetor);

}