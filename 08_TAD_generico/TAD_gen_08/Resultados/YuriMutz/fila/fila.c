#include "fila.h"
#include "movel.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//typedef struct Fila Fila;

struct Fila{

    Vector *moveis;

};

/**
 * @brief Cria uma fila vazia
 * 
 * @return A estrutura Fila inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Fila *FilaConstruct(){

    Fila *fila = malloc(sizeof(Fila));

    fila->moveis = VectorConstruct();

    return fila;

}

/**
 * @brief Desaloca a memória alocada para a fila
 * 
 * @param f Ponteiro para a fila
 * @param destroy Função que desaloca a memória alocada para cada elemento da fila
*/
void FilaDestroy(Fila *f, void (*destroy)(DataType)){

    VectorDestroy(f->moveis, DestroiMovel);

    free(f);

}

/**
 * @brief Retorna o tamanho da fila
 * 
 * @param f Ponteiro para a fila
 * @return int Tamanho da fila
*/
int FilaSize(Fila *f){

    return VectorSize(f->moveis);

}

/**
 * @brief Remove o primeiro elemento da fila
 * OBS: Note que a fila é uma estrutura FIFO (First In, First Out), ou seja, o primeiro elemento a ser adicionado é o primeiro a ser removido.
 * Portanto, apesar da fila estar implementada com um vector, ele não é adequado para implementar uma fila, pois a remoção de um elemento do início do vetor é uma operação custosa.
 * @param f Ponteiro para a fila
 * @return DataType Elemento removido
*/
DataType FilaPop(Fila *f){

    return VectorPopFront(f->moveis);

}

/**
 * @brief Adiciona um elemento no final da fila
 * 
 * @param f Ponteiro para a fila
 * @param val Valor a ser adicionado
*/
void FilaPush(Fila *f, DataType val){

    VectorPushBack(f->moveis, (tMovel*)val);

}