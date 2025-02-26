#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

//typedef void *DataType; // void pointer
//typedef struct Vector Vector;

struct Vector{

    DataType *vet;
    int tamMax;
    int tamAtual;

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

    vet->vet = malloc(vet->tamMax * sizeof(DataType*));

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

        v->vet = realloc(v->vet, v->tamMax);

        ((DataType*)v->vet)[v->tamAtual] = val;

        v->tamAtual++;

    } else {

        ((DataType*)v->vet)[v->tamAtual] = val;

        v->tamAtual++;

    }

}

/**
 * @brief Remove o primeiro elemento do vetor e organiza os demais elementos, ou seja, 
 * o segundo elemento passa a ser o primeiro, o terceiro passa a ser o segundo, e assim por diante.
 * 
 * @param v Ponteiro para o vetor
 * @return DataType Elemento removido
*/
DataType VectorPopFront(Vector *v){

    DataType aux;

    aux = ((DataType*)v->vet)[0];

    for(int i = 0; i < v->tamAtual-1; i++){

        ((DataType*)v->vet)[i] = ((DataType*)v->vet)[i+1];

    }
    
    v->tamAtual--;

    return aux;

}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){

    return v->vet[i];

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
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){

    destroy(v->vet);

    destroy(v);

}