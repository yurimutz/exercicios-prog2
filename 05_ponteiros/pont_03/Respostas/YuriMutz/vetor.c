#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam){
    int i=0;

    for(i=0; i<tam; i++){
        scanf("%d", &*(vet+i));
    }
    
}

void ImprimeDadosDoVetor(int * n, int tam){
    int i=0;

    for(i=0; i<tam; i++){
        printf("%d ", *(n+i));
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    int i = 0, j = 0, valor = 1000;

    for(i=0; i<tam; i++){
        if(*(vet+i) < valor){
            valor = *(vet+i);
            paraTrocar = &*(vet+i);
        }

    } 

    j = vet[0];
    vet[0] = *paraTrocar;
    *paraTrocar = j;
    
}

void OrdeneCrescente(int * vet, int tam){
    int i = 0;
    int *aux = NULL;

    for(i=0; i<tam; i++){       
        TrocaSeAcharMenor(vet+i, tam-i, aux);
    }
       
}