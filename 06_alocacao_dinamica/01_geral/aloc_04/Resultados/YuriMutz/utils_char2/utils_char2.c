#include "utils_char2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *CriaVetorTamPadrao(){

    char *vetor = (char *)malloc((TAM_PADRAO + 1) * sizeof(char));

    for(int i=0; i<TAM_PADRAO; i++){
        *(vetor + i) = '_';
    }

    vetor[TAM_PADRAO] = '\0';

    return vetor;

}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){

    vetor = (char *)realloc(vetor, tamanhoantigo + 1);

    for(int i=tamanhoantigo-TAM_PADRAO+1; i<tamanhoantigo; i++){
        *(vetor + i) = '_';
    }

    vetor[tamanhoantigo] = '\0';

    return vetor;

}

char* LeVetor(char *vetor, int *tamanho){

    int i = 0, j = 1;

    while(scanf("%c", &*(vetor + i)) == 1){

        if(*(vetor + i) == '\n'){
            *(vetor + i) = '_';
            break;
        }

        if(i == TAM_PADRAO * j){
            if(*(vetor + i) != '\0'){
                j++;
                vetor = AumentaTamanhoVetor(vetor, (*tamanho) * j);
            } else {
                return vetor;
            }
            
        }        

        i++;

    }
    
    return vetor;

}

void ImprimeString(char *vetor){

    printf("%s\n", vetor);

}

void LiberaVetor(char *vetor){

    free(vetor);

}