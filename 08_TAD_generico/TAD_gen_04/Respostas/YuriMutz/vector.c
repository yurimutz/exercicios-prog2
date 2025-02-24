#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// typedef void *data_type; // void pointer
// typedef struct Vector Vector;

struct Vector{

    DataType *vet;
    int tam;
    int tamAtual;

};

Vector *VectorConstruct(){

    Vector *vet = malloc(sizeof(Vector));

    vet->tam = 10;

    vet->vet = malloc(sizeof(DataType) * vet->tam);

    vet->tamAtual = 0;

    return vet;

}

void VectorPushBack(Vector *v, DataType val){

    if(v->tamAtual == v->tam){

        v->tam = v->tam * 2;

        v->vet = realloc(v->vet, (v->tam) * sizeof(DataType));

    }

    ((DataType*)v->vet)[v->tamAtual] = val;

    v->tamAtual++;

}

DataType VectorGet(Vector *v, int i){

    return v->vet[i];
    
}

int VectorSize(Vector *v){

    return v->tamAtual;

}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){

    for(int i = 0; i < v->tamAtual; i++){

        if(v->vet[i] != NULL){

            destroy(v->vet[i]);

        }

    }

    free(v->vet);

    free(v);

}