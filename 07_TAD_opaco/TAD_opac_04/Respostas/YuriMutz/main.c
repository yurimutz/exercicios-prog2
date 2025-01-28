#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int numAlunos = 0;
    scanf("%d", &numAlunos);
    scanf("%*c");

    tAluno **alunos = (tAluno **)malloc(numAlunos * sizeof(tAluno *));

    for(int i = 0; i < numAlunos; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    tAluno **cliente = (tAluno **)malloc(numAlunos * sizeof(tAluno *));

    int j = 0;
    for(int i = 0; i < numAlunos; i++){
        if(VerificaAprovacao(alunos[i])){
            cliente[j] = alunos[i];
            j++;
        }
    }

    tAluno *aux;
    for(int i = 0; i < j-1; i++){
        for(int k = i+1; k < j; k++){
            if(ComparaMatricula(cliente[i], cliente[k]) == 1){
                aux = cliente[i];
                cliente[i] = cliente[k];
                cliente[k] = aux;
            }
        }
    }

    

    for(int i = 0; i < j; i++){
        ImprimeAluno(cliente[i]);
    }

    

    for(int i=0; i<numAlunos; i++){
        ApagaAluno(alunos[i]);   
    }

    free(cliente);

    free(alunos);


    return 0;

}