#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

// typedef struct Aluno tAluno;

struct Aluno{

    char nome[50];
    float nota;
    char gen;

};

tAluno *CriaAluno(){

    tAluno *aluno = malloc(sizeof(tAluno));

    aluno->nota = 0;

    return aluno;

}

void DestroiAluno(data_type aluno){

    free(aluno);

}

void LeAluno(tAluno *aluno){

    char str[100];

    scanf("%*[\n]");
    scanf("%[^\n]", str);
    scanf("%*[\n]");

    sscanf(str, "%[^;];%c;%f", aluno->nome, &aluno->gen, &aluno->nota);

}

char GetGeneroAluno(tAluno *aluno){

    return aluno->gen;

}

float GetNotaAluno(tAluno *aluno){

    return aluno->nota;

}