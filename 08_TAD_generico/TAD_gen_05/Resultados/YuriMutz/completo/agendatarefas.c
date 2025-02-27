#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct agendatarefas tAgendaTarefas;

typedef void(*destroy)(void*);

typedef void(*exec)(void*);

struct agendatarefas{

    void **tarefa;
    int tamAtual;
    int tamMax;

    int *prioridade;

    destroy *des;
    exec *executa;

};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem){

    tAgendaTarefas *agenda = malloc(sizeof(tAgendaTarefas));

    agenda->tamAtual = 0;

    agenda->tamMax = numElem;

    agenda->prioridade = malloc(numElem * sizeof(int));

    agenda->tarefa = malloc(numElem * sizeof(void*));

    agenda->des = malloc(numElem * sizeof(destroy*));

    agenda->executa = malloc(numElem * sizeof(exec*));

    return agenda;

}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){

    for(int i = 0; i < tar->tamAtual; i++){

        tar->des[i](tar->tarefa[i]);

    }

    free(tar->tarefa);

    free(tar->executa);

    free(tar->des);

    free(tar->prioridade);

    free(tar);

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

    tar->prioridade[tar->tamAtual] = prioridade;

    tar->tarefa[tar->tamAtual] = tarefa;

    tar->executa[tar->tamAtual] = executa;

    tar->des[tar->tamAtual] = destroi;

    tar->tamAtual++;

}   

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){

    for(int j = 0; j < tar->tamAtual; j++){

        for(int i = 0; i < tar->tamAtual-1; i++){

            if(tar->prioridade[i] < tar->prioridade[i+1]){

                int aux;
                aux = tar->prioridade[i];
                tar->prioridade[i] = tar->prioridade[i+1];
                tar->prioridade[i+1] = aux;

                void *ptr;
                ptr = tar->tarefa[i];
                tar->tarefa[i] = tar->tarefa[i+1];
                tar->tarefa[i+1] = ptr;

                void (*dAux)(void*);
                dAux = tar->des[i];
                tar->des[i] = tar->des[i+1];
                tar->des[i+1] = dAux;

                void (*eAux)(void*);
                eAux = tar->executa[i];
                tar->executa[i] = tar->executa[i+1];
                tar->executa[i+1] = eAux;

            }

        }

    }

    for(int i = 0; i < tar->tamAtual; i++){

        tar->executa[i](tar->tarefa[i]);

    }

}


// #include "agendatarefas.h"
// #include "tarefasoma.h"
// #include "tarefamultiplica.h"
// #include "tarefaimprime.h"
// #include <stdio.h>
// #include <stdlib.h>

// //typedef struct agendatarefas tAgendaTarefas;

// void (*auxD)(void*);
// void (*auxE)(void*);

// typedef void (*destroi)(void*);
// typedef void(*exec)(void*);

// struct agendatarefas{

//     void **tarefa;
//     int numTarefas;
//     int qtdAtual;
//     int *prioridade;

//     // void(**ptrfDestroi)(void*);
//     destroi *funcDestroy;
//     exec *funcExec;

// };

// /**
//  * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
//  *
//  * @param numElem A quantidade de tarefas que serão armazenadas no agendador
//  *
//  * @return Um ponteiro para a agenda de tarefas
//  */
// tAgendaTarefas* CriaAgendaDeTarefas(int numElem){

//     tAgendaTarefas* agenda = malloc(sizeof(tAgendaTarefas));

//     agenda->numTarefas = numElem;
    
//     agenda->qtdAtual = 0;

//     agenda->prioridade = malloc(numElem * sizeof(int));

//     agenda->tarefa = malloc(numElem * sizeof(void*));

//     agenda->funcDestroy = malloc(numElem * sizeof(void (*)(void*)));

//     agenda->funcExec = malloc(numElem * sizeof(void (*)(void*)));

//     return agenda;

// }

// /**
//  * @brief Destroi a agenda de tarefas (libera a memória)
//  *
//  * @param tar - A agenda que terá seu conteúdo liberado/destruído
//  */
// void DestroiAgendaDeTarefas(tAgendaTarefas* tar){

//     for(int i = 0; i < tar->qtdAtual; i++){   

//         tar->funcDestroy[i](tar->tarefa[i]);

//     }

//     free(tar->prioridade);

//     free(tar->funcDestroy);

//     free(tar->funcExec);

//     free(tar->tarefa);


//     free(tar);


// }

// /**
//  * @brief Cadastra uma tarefa em um agendador de tarefas
//  *
//  * @param tar - Pointeiro para a agenda de tarefas
//  * @param prioridade - Prioridade de execução da nova tarefa
//  * @param tarefa - Ponteiro para nova tarefa a ser executada
//  * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
//  * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
//  *
//  */
// void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){

//     tar->prioridade[tar->qtdAtual] = prioridade;

//     if(executa == ExecutaTarefaSoma){

//         ((tSoma**)tar->tarefa)[tar->qtdAtual] = (tSoma*)tarefa;

//         tar->funcDestroy[tar->qtdAtual] = destroi;

//         tar->funcExec[tar->qtdAtual] = executa;

//         tar->qtdAtual++;

//         //printf("oi\n");

//     } else if(executa == ExecutaTarefaMultiplicar){

//         ((tMult**)tar->tarefa)[tar->qtdAtual] = (tMult*)tarefa;

//         tar->funcDestroy[tar->qtdAtual] = destroi;

//         tar->funcExec[tar->qtdAtual] = executa;

//         tar->qtdAtual++;

//         //printf("ola\n");

//     } else {

//         ((tImpr**)tar->tarefa)[tar->qtdAtual] = (tImpr*)tarefa;

//         tar->funcDestroy[tar->qtdAtual] = destroi;

//         tar->funcExec[tar->qtdAtual] = executa;

//         tar->qtdAtual++;

//         //printf("opa\n");


//     }

// }   

// /**
//  * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
//  *
//  * @param tar Agenda de tarefas
//  *
//  */
// void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){

//     for(int i = 0; i < (tar->qtdAtual); i++){

//         for(int j = 0; j < tar->qtdAtual-1; j++){

//             if(tar->prioridade[j] < tar->prioridade[j+1]){

//                 int aux;
//                 aux = tar->prioridade[j];
//                 tar->prioridade[j] = tar->prioridade[j+1];
//                 tar->prioridade[j+1] = aux;

//                 void *tarefaAux;
//                 tarefaAux = tar->tarefa[j];
//                 tar->tarefa[j] = tar->tarefa[j+1];
//                 tar->tarefa[j+1] = tarefaAux;

//                 void(*destAux)(void*);
//                 destAux = tar->funcDestroy[j];
//                 tar->funcDestroy[j] = tar->funcDestroy[j+1];
//                 tar->funcDestroy[j+1] = destAux;

//                 void(*execAux)(void*);
//                 execAux = tar->funcExec[j];
//                 tar->funcExec[j] = tar->funcExec[j+1];
//                 tar->funcExec[j+1] = execAux;

//             } 

//         }

//     }
    

//     for(int i = 0; i < tar->qtdAtual; i++){

//         tar->funcExec[i](tar->tarefa[i]);

//     }

// }
