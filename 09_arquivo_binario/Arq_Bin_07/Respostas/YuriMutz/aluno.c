#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Aluno tAluno;

struct Aluno{

    char nome[50];
    char data[50];
    char curso[50];
    float prct;
    float rend;

};

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe, a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento){

    tAluno *aluno = malloc(sizeof(tAluno));

    memset(aluno->nome, 0, 50);
    strcpy(aluno->nome, nome);

    memset(aluno->data, 0, 50);
    strcpy(aluno->data, dataNascimento);

    memset(aluno->curso, 0, 50);
    strcpy(aluno->curso, curso);

    aluno->prct = prctConclusao;

    aluno->rend = cfRendimento;

    return aluno;

}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno){

    free(aluno);

}

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno(){

    char nome[50];
    char data[50];
    char curso[50];
    float prct;
    float rend;

    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", nome);
    scanf("%*[\n]");

    scanf("%[^\n]", data);
    scanf("%*[\n]");

    scanf("%[^\n]", curso);
    scanf("%*[\n]");

    scanf("%f\n", &prct);

    scanf("%f\n", &rend);

    tAluno *aluno = CriaAluno(nome, data, curso, prct, rend);

    //printf("%s %s %s %f %f\n", aluno->nome, aluno->data, aluno->curso, aluno->prct ,aluno->rend);

    return aluno;

}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2){

    if(strcmp(aluno1->nome, aluno2->nome) == 0){

        return 1;

    } else {

        return 0;

    }

}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file){

    int bytes = 0;
    int aux = 0;

    aux = strlen(aluno->nome);
    bytes += sizeof(int)*fwrite(&aux,sizeof(int),1,file);
    bytes += sizeof(char)*fwrite(aluno->nome, sizeof(char), strlen(aluno->nome), file);

    aux = strlen(aluno->data);
    bytes += sizeof(int)*fwrite(&aux,sizeof(int),1,file);
    bytes += sizeof(char) * fwrite(aluno->data, sizeof(char), strlen(aluno->data), file);

    aux = strlen(aluno->curso);
    bytes += sizeof(int)*fwrite(&aux,sizeof(int),1,file);
    bytes += sizeof(char) * fwrite(aluno->curso, sizeof(char), strlen(aluno->curso), file);

    bytes += sizeof(float) * fwrite(&(aluno->prct), sizeof(float), 1, file);
    bytes += sizeof(float) * fwrite(&(aluno->rend), sizeof(float), 1, file);

    return bytes;

}

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file){

    int aux = 0;
    int bytes = 0;

    char nome[50];
    char data[50];
    char curso[50];
    float prct;
    float rend;

    bytes += sizeof(int) * fread(&aux, sizeof(int), 1, file);
    bytes += sizeof(char) * fread(nome, sizeof(char), aux, file);

    bytes += sizeof(int) * fread(&aux, sizeof(int), 1, file);
    bytes += sizeof(char) * fread(data, sizeof(char), aux, file);

    bytes += sizeof(int) * fread(&aux, sizeof(int), 1, file);
    bytes += sizeof(char) * fread(curso, sizeof(char), aux, file);

    bytes += sizeof(int) * fread(&prct, sizeof(float), 1, file);

    bytes += sizeof(int) * fread(&rend, sizeof(float), 1, file);

    return bytes;

}

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno){

    printf("oi%soi\n", aluno->nome);

}