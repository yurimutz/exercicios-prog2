#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tAluno* CriaAluno(){

    tAluno *aluno = (tAluno *)malloc(sizeof(struct Aluno));

    aluno->nome = NULL;

    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;

}

void ApagaAluno(tAluno *aluno){

    free(aluno->nome);

    free(aluno);

}

void LeAluno(tAluno *aluno){

    aluno->nome = (char *)malloc(10 * sizeof(char));

    scanf("%s", aluno->nome);
    scanf("%*c");

    scanf("%d", &aluno->matricula);
    scanf("%*c");

    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
    scanf("%*c");

}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){

    if(aluno1->matricula > aluno2->matricula){
        return 1;
    } else if(aluno1->matricula < aluno2->matricula){
        return -1;
    } else {
        return 0;
    }

}

int CalculaMediaAluno(tAluno* aluno){

    int media = 0;

    media = (aluno->n1 + aluno->n2 + aluno->n3) / 3;

    return media;

}

int VerificaAprovacao(tAluno* aluno){

    int media = 0;

    media = CalculaMediaAluno(aluno);

    if(media >= 7){
        return 1;
    } else {
        return 0;
    }

}

void ImprimeAluno(tAluno* aluno){

    printf("%s\n", aluno->nome);

}