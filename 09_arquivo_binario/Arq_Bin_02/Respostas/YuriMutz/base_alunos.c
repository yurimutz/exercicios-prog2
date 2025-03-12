#include "base_alunos.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct BaseAlunos tBaseAlunos;

struct BaseAlunos{

    tAluno **alunos;
    int tamAtual;
    int tamMax;

};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){

    tBaseAlunos *base = malloc(sizeof(tBaseAlunos));

    base->tamAtual = 0;

    base->tamMax = 10;

    base->alunos = malloc(base->tamMax * sizeof(tAluno*));

    return base;

}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){

    for(int i = 0; i < baseAlunos->tamAtual; i++){

        DestruirAluno(baseAlunos->alunos[i]);

    }

    free(baseAlunos->alunos);

    free(baseAlunos);

}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){

    FILE *fp;
    fp = fopen(nomeArquivo, "rb");

    int qtd = 0;
    
    fread(&qtd, sizeof(int), 1, fp);

    for(int i = 0; i < qtd; i++){

        baseAlunos->alunos[i] = LeAluno(fp);

    }

    baseAlunos->tamAtual = qtd;

    fclose(fp);

}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){

    float media = 0;

    for(int i = 0; i < baseAlunos->tamAtual; i++){

        media += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);

    }

    return media / (float)baseAlunos->tamAtual;

}