#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char * nome;
    int matricula;
    int n1;
    int n2;
    int n3;
};


tAluno* CriaAluno(){

    tAluno * aluno = malloc(sizeof(tAluno));
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;
    aluno->nome = NULL;

    return aluno;

}

void ApagaAluno(tAluno *aluno){

    free(aluno->nome);
    aluno->nome = NULL;

    free(aluno);
    aluno = NULL;

}

void LeAluno(tAluno *aluno){

    aluno->nome = (char *)malloc(10 * sizeof(char));

    scanf("%s", aluno->nome);
    scanf("%*c");

    scanf("%d", &aluno->matricula);
    scanf("%*c");

    scanf("%d%d%d", &aluno->n1, &aluno->n2, &aluno->n3);
    scanf("%*c");

    

}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){

    if(aluno1->matricula == aluno2->matricula){
        return 0;
    } else if(aluno1->matricula > aluno2->matricula){
        return 1;
    } else {
        return -1;
    }

}

int CalculaMediaAluno(tAluno* aluno){

    int media = 0;

    media = (aluno->n1 + aluno->n2 + aluno->n3) / 3;

    return media;

}

int VerificaAprovacao(tAluno* aluno){

    int media = CalculaMediaAluno(aluno);

    if(media >= 7){
        return 1;
    } else {
        return 0;
    }

}

void ImprimeAluno(tAluno* aluno){

    printf("%s\n", aluno->nome);

}

