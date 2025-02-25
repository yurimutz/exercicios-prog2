#include "agendatarefas.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct agendatarefas tAgendaTarefas;

void (*auxD)(void*);
void (*auxE)(void*);

typedef void (*destroi)(void*);
typedef void(*exec)(void*);

struct agendatarefas{

    void **tarefa;
    int numTarefas;
    int qtdAtual;
    int *prioridade;
    int *indices;
    int numIndice;

    // void(**ptrfDestroi)(void*);
    destroi *funcDestroy;
    exec *funcExec;

};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem){

    tAgendaTarefas* agenda = malloc(sizeof(tAgendaTarefas));

    agenda->numTarefas = numElem;
    
    agenda->qtdAtual = 0;

    agenda->prioridade = malloc(numElem * sizeof(int));

    agenda->tarefa = malloc(numElem * sizeof(void*));

    agenda->funcDestroy = malloc(numElem * sizeof(void (*)(void*)));

    agenda->funcExec = malloc(numElem * sizeof(void (*)(void*)));

    agenda->indices = malloc(numElem * sizeof(int));

    agenda->numIndice = 0;

    return agenda;

}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){



}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){

    tar->prioridade[tar->qtdAtual] = prioridade;

    if(executa == ExecutaTarefaSoma){

        ((tSoma**)tar->tarefa)[tar->qtdAtual] = (tSoma*)tarefa;

        tar->funcDestroy[tar->qtdAtual] = destroi;

        tar->funcExec[tar->qtdAtual] = executa;

        tar->qtdAtual++;

        //printf("oi\n");

        

    } else if(executa == ExecutaTarefaMultiplicar){

        ((tMult**)tar->tarefa)[tar->qtdAtual] = (tMult*)tarefa;

        tar->funcDestroy[tar->qtdAtual] = destroi;

        tar->funcExec[tar->qtdAtual] = executa;

        tar->qtdAtual++;

        //printf("ola\n");

    } else {

        ((tImpr**)tar->tarefa)[tar->qtdAtual] = (tImpr*)tarefa;

        tar->funcDestroy[tar->qtdAtual] = destroi;

        tar->funcExec[tar->qtdAtual] = executa;

        tar->qtdAtual++;

        //printf("opa\n");


    }



}   

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){

    int aux;
    int flag = 0;
    int indAux = 0;

    void *tarefaAux;
    void(*destAux)(void*);
    void(*execAux)(void*);

    for(int i = 0; i < tar->qtdAtual-1; i++){

        for(int j = i+1; j < tar->qtdAtual; j++){

            if(tar->prioridade[i] < tar->prioridade[j]){

                tarefaAux = tar->tarefa[i];
                tar->tarefa[i] = tar->tarefa[j];
                tar->tarefa[j] = tarefaAux;

                destAux = tar->funcDestroy[i];
                tar->funcDestroy[i] = tar->funcDestroy[j];
                tar->funcDestroy[j] = destAux;

                execAux = tar->funcExec[i];
                tar->funcExec[i] = tar->funcExec[j];
                tar->funcExec[j] = execAux;



            } 

        }

    }
    

    for(int i = 0; i < tar->qtdAtual; i++){

        auxD = tar->funcExec[i];

        auxD(tar->tarefa[i]);


    }

}
