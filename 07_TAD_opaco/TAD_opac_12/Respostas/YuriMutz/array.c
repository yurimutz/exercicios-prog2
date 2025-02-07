#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct Array{

    int *vetor;
    int tamVet;

};

Array *CriarArray(){

    Array *vet = (Array *)malloc(sizeof(Array));

    vet->vetor = NULL;

    vet->tamVet = 0;

    return vet;

}

void DestruirArray(Array *array){

    free(array->vetor);

    free(array);

}

void LerArray(Array *array){

    int aux = 0;
    char auxC;

    while(1){

        scanf("%d%c", &aux, &auxC);

        if(array->tamVet == 0){

            array->vetor = (int*)malloc(sizeof(int));

            array->vetor[array->tamVet] = aux;

            array->tamVet++;

        } else {

            array->vetor = realloc(array->vetor, (array->tamVet + 1) * sizeof(Array*));

            array->vetor[array->tamVet] = aux;

            array->tamVet++;

        }

        if(auxC == '.'){

            break;

        }

    }

}

void OrdenarArray(Array *array){

    int aux;

    for(int i = 0; i < array->tamVet-1; i++){

        for(int j = i+1; j < array->tamVet; j++){

            if(array->vetor[i] > array->vetor[j]){

                aux = array->vetor[i];

                array->vetor[i] = array->vetor[j];

                array->vetor[j] = aux;

            }


        }

    }


}

int BuscaBinariaArray(Array *array, int elementoBuscado){

    int aux = 0;

    int posInicial = 0;
    int posFinal = array->tamVet-1;

    while(1){

        aux = (posFinal + posInicial) / 2;

        if(aux < 0 || aux > (array->tamVet - 1)){

            return -1;

        }

        if(posFinal == posInicial){

            if(array->vetor[aux] == elementoBuscado){

                return aux;
    
            } else {

                return -1;

            break;

            }

        }

        if(array->vetor[aux] == elementoBuscado){

            return aux;

        } else if(array->vetor[aux] < elementoBuscado){
            
            posInicial = aux + 1;


        } else if(array->vetor[aux] > elementoBuscado){

            posFinal = aux - 1;

        } 


    }


}