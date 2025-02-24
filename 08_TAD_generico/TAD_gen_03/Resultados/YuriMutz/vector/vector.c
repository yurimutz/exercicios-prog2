#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "aluno.h"

// typedef void *data_type; // void pointer
// typedef struct Vector Vector;

struct Vector{

    data_type *vet;
    int tam;
    int tamAtual;

};

Vector *VectorConstruct(){

    Vector *vet = malloc(sizeof(Vector));

    vet->tam = 10;

    vet->vet = malloc(sizeof(data_type) * vet->tam);

    vet->tamAtual = 0;

    return vet;

}

void VectorPushBack(Vector *v, data_type val){

    if(v->tamAtual == v->tam){

        v->tam = v->tam * 2;

        v->vet = realloc(v->vet, (v->tam) * sizeof(data_type));

    }

    ((data_type*)v->vet)[v->tamAtual] = val;

    v->tamAtual++;

}

data_type VectorGet(Vector *v, int i){

    return v->vet[i];
    
}

int VectorSize(Vector *v){

    return v->tamAtual;

}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){

    for(int i = 0; i < v->tamAtual; i++){

        if(v->vet[i] != NULL){

            destroy((tAluno*)v->vet[i]);

        }

    }

    free(v->vet);

    free(v);

}