#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct mult tMult;

struct mult{

    float n1;
    float n2;

};

/**
 * @brief Cria uma tarefa do tipo multiplicação de dois números
 * 
 * @param n1 - Primeiro número que será multiplicado quando a tarefa for executada
 * @param n2 - Segundo número que será multiplicado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2){

    tMult *mult = malloc(sizeof(tMult*));

    mult->n1 = n1;

    mult->n2 = n2;

    return mult;

}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult){

    tMult *aux = (tMult*)mult;

    printf("\n");
    printf("O resultado da multiplicacao de %0.2f com %0.2f eh: %0.2f", aux->n1, aux->n2, aux->n1 * aux->n2);

}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult){

    tMult *aux = (tMult*)mult;

    free(aux);

}