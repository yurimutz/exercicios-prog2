#include "utils_char.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *CriaVetor(int tamanho){

    char *vetor = NULL;

    vetor = (char *)malloc((tamanho + 1) * sizeof(char));

    for(int i=0; i<tamanho; i++){
        *(vetor + i) = '_';
    }

    vetor[tamanho] = '\0';

    return vetor;

}

void LeVetor(char *vetor, int tamanho){

    for(int i=0; i<tamanho; i++){
        scanf("%c", &*(vetor + i));

        if(*(vetor + i) == '\n'){
            *(vetor + i) = '_';
            break;
        }

    }    

}

void ImprimeString(char *vetor, int tamanho){

    if(vetor == NULL){

        printf("Erro na LeVetor\n");

    } else {

        for(int i=0; i<tamanho; i++){
            printf("%c", *(vetor + i));
        } 

        printf("\n");

    }

}

void LiberaVetor(char *vetor){

    free(vetor);

}