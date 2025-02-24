#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct impr tImpr;

struct impr{

    char msg[50];

};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){

    tImpr *aux = malloc(sizeof(tImpr));

    strcpy(aux->msg, msg);

}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){

    tImpr *aux = (tImpr*)imp;

    printf("\n");
    printf("%s", aux->msg);

}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){

    tImpr *aux = (tImpr*)imp;

    free(aux);

}