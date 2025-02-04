#include "paciente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct paciente{

    char *nome;
    tData *nascimento;
    char *cartaoSUS;
    char genero;
    tLesao **lesao;
    int numLesoes;

};

char* GetCartaoSusPaciente(tPaciente* p){

    return p->cartaoSUS;

}

int GetQtdLesoesPaciente(tPaciente* p){

    return p->numLesoes;

}

int GetQtdCirurgiasPaciente(tPaciente* p){

    int aux = 0;

    for(int i = 0; i < p->numLesoes; i++){

        if(GetIdLesao(p->lesao[i]) != NULL){

            if(PrecisaCirurgiaLesao(p->lesao[i])){

                aux++;

            }

        }

    }

    return aux;

}

tData* GetNascimentoPaciente(tPaciente* p){

    return p->nascimento;

}

tPaciente* CriaPaciente(){

    tPaciente *paciente = malloc(sizeof(tPaciente));

    paciente->nome = malloc(TAM_NOME * sizeof(char));

    paciente->nascimento = NULL;

    paciente->cartaoSUS = malloc(TAM_CSUS * sizeof(char));

    paciente->lesao = malloc(10 * sizeof(tLesao*));

    for(int i = 0; i < 10; i++){

        paciente->lesao[i] = NULL;

    }

    paciente->numLesoes = 0;

    return paciente;

}

void LePaciente(tPaciente* p){

    scanf("%[^\n]", p->nome);
    scanf("%*[\n]");

    p->nascimento = LeData();

    scanf("%[^\n]", p->cartaoSUS);
    scanf("%*[\n]");

    scanf("%c ", &p->genero);

}

void ImprimePaciente(tPaciente* p){

    if(p->numLesoes > 0){

        printf("- %s - ", p->nome);

        for(int i = 0; i < p->numLesoes; i ++){

            if(GetIdLesao(p->lesao[i]) != NULL){

                printf("%s", GetIdLesao(p->lesao[i]));

            }

        }

        printf("\n");

    }

}

void LiberaPaciente(tPaciente* p){

    free(p->nome);

    free(p->cartaoSUS);

    LiberaData(p->nascimento);

    for(int i = 0; i < p->numLesoes; i++){

        LiberaLesao(p->lesao[i]);

    }

    free(p->lesao);

    free(p);

}

void AdicionaLesaoPaciente(tPaciente* p, tLesao* l){

    p->lesao[p->numLesoes] = l;

    p->numLesoes++;

}