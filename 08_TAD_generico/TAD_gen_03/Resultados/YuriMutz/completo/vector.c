#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// typedef void *data_type; // void pointer
// typedef struct Vector Vector;

struct Vector{

    void **vet;
    int tam;
    int tamAtual;

};

Vector *VectorConstruct(){

    Vector *vet = malloc(sizeof(Vector));

    vet->tam = 0;

    vet->tamAtual = 0;

    return vet;

}

void VectorPushBack(Vector *v, data_type val){

    // if(v->tamAtual == 0){

    //     v->vet = malloc(sizeof(void *));

    // } else {

    //     v->vet = realloc(v->vet, sizeof(void *) * (v->tamAtual + 1));

    // }

    // data_type *vet = (data_type*)v->vet;

    // vet[v->tamAtual] = val;

    // v->tamAtual++;

    if (v->tamAtual >= v->tam) { // Se atingir a capacidade, dobramos o tamanho
        v->tam *= 2;
        void **temp = realloc(v->vet, v->tam * sizeof(void *));
        if (!temp) {
            fprintf(stderr, "Erro: Falha na realocação de memória.\n");
            exit(EXIT_FAILURE);
        }
        v->vet = temp;
    }

    v->vet[v->tamAtual] = val;
    v->tamAtual++;

}

data_type VectorGet(Vector *v, int i){

    data_type *vet = (data_type*)v->vet;

    return vet[i];

    
}

int VectorSize(Vector *v){

    return v->tam;

}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){

    data_type *vet = (data_type*)v->vet;

    for(int i = 0; i < v->tamAtual; i++){

        if(vet[i] != NULL){

            destroy(vet[i]);

        }

    }

    free(v->vet);

    free(v);

}