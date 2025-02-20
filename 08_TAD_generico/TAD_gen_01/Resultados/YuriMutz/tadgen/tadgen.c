#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

// typedef enum {
//     FLOAT = 0,
//     INT = 1
// } Type;

// typedef struct generic tGeneric;

struct generic{

    void *vet;

    int numElem;

    Type tipo;

};

tGeneric* CriaGenerico(Type type, int numElem){

    tGeneric *generic = malloc(sizeof(tGeneric));

    if(type == FLOAT){

        generic->vet = malloc(numElem * sizeof(float));


    } else {

        generic->vet = malloc(numElem * sizeof(int));    

    }

    generic->numElem = numElem;

    generic->tipo = type;

    return generic;

}

void DestroiGenerico(tGeneric* gen){

    free(gen->vet);

    free(gen);

}

void LeGenerico(tGeneric* gen){

    printf("\n");
    printf("Digite o vetor:\n");

    if(gen->tipo == FLOAT){

        float *aux = (float*)gen->vet;

        for(int i = 0; i < gen->numElem; i++){

            scanf("%f ", &aux[i]);

        }

    } else {

        int *aux = (int*)gen->vet;

        for(int i = 0; i < gen->numElem; i++){

            scanf("%d ", &aux[i]);

        }    

    }

    

}

void ImprimeGenerico(tGeneric* gen){

    if(gen->tipo == FLOAT){

        float *aux = (float*)gen->vet;

        for(int i = 0; i < gen->numElem; i++){

            printf("%0.2f ", aux[i]);

        }

    } else {

        int *aux = (int*)gen->vet;

        for(int i = 0; i < gen->numElem; i++){

            printf("%d ", aux[i]);

        }    

    }    

    printf("\n");

}