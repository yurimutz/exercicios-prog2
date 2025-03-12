#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Aluno tAluno;

struct Aluno{

    char nome[100];
    char data[11];
    char curso[50];
    float rend;
    int periodo;

};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){

    tAluno *aluno = malloc(sizeof(tAluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->data, dataNascimento);
    strcpy(aluno->curso, curso);

    aluno->periodo = periodo;

    aluno->rend = coeficienteRendimento;

    return aluno;

}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){

    free(aluno);

}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){

    char nome[100];
    char data[11];
    char curso[50];
    float rend = 0;
    int periodo = 0;

    fread(nome, sizeof(char), 100, arquivo_binario);

    fread(data, sizeof(char), 11, arquivo_binario);

    fread(curso, sizeof(char), 50, arquivo_binario);

    fread(&periodo, sizeof(int), 1, arquivo_binario);

    fread(&rend, sizeof(float), 1, arquivo_binario);

    tAluno *aluno = CriarAluno(nome, data, curso, periodo, rend);

    return aluno;

}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){

    return aluno->rend;

}