#include "utils.h"
#include <stdio.h>


void LeNumeros(int *array, int tamanho){
    int i = 0;

    for(i=0; i<tamanho; i++){
        scanf("%d", &array[i]);
    }

}



void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int i = 0, menora = 1000, maiora = 0, soma = 0; 
    float mediaa = 0;

    for(i=0; i<tamanho; i++){
        if(array[i] < menora){
            menora = array[i];
            *menor = array[i];
        }
        if(array[i] > maiora){
            maiora = array[i];
            *maior = array[i];
        }
        soma += array[i]; 
    }

    mediaa = (float)(soma) / (float)tamanho;

    *media = mediaa;

}