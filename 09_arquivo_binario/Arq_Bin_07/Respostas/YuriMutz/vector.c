#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef void *DataType; // void pointer
// typedef struct Vector Vector;

struct Vector{

    DataType *dado;
    int tamAtual;
    int tamMax;

};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){

    Vector *vet = malloc(sizeof(Vector));

    vet->tamAtual = 0;

    vet->tamMax = 10;

    vet->dado = malloc(vet->tamMax * sizeof(DataType));

    return vet;

}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){

    if(v->tamAtual == v->tamMax){

        v->tamMax = v->tamMax * 2;

        v->dado = realloc(v->dado, v->tamMax * sizeof(DataType));

    }

    v->dado[v->tamAtual] = val;

    v->tamAtual++;

}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i){

    for(int j = i; j < v->tamAtual-1; j++){

        v->dado[i] = v->dado[i+1];

    }

    free(v->dado[v->tamAtual]);
    v->tamAtual--; 

}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){

    return v->dado[i];

}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){

    return v->tamAtual;

}


/**
 * @brief Troca os elementos i e j do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do primeiro elemento
 * @param j Índice do segundo elemento
*/
void VectorSwap(Vector *v, int i, int j){

    DataType *aux;

    aux = v->dado[i];
    v->dado[i] = v->dado[j];
    v->dado[j] = aux;

}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){

    for(int i = 0; i < v->tamAtual; i++){

        destroy(v->dado[i]);

    }

    free(v->dado);

    free(v);

}
