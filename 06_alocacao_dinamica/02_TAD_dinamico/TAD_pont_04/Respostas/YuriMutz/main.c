#include "aluno.h"

int main(){

    //leitura dos alunos;

    int nAlunos = 0;
    scanf("%d", &nAlunos);
    scanf("%*c");

    tAluno **alunos = (tAluno **)malloc(nAlunos * sizeof(struct Aluno*));

    for(int i=0; i<nAlunos; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    //implementacao do cliente;

    tAluno **cliente = (tAluno **)malloc(nAlunos * sizeof(struct Aluno*));

    int j = 0;
    for(int i=0; i<nAlunos; i++){
        if(VerificaAprovacao(alunos[i])){
            cliente[j] = alunos[i];
            j++;
        }
    }

    tAluno *aux;
    for(int i=0; i<j-1; i++){
        for(int k=i+1; k<j; k++){
            if(ComparaMatricula(cliente[i], cliente[k]) == 1){
                aux = cliente[i];
                cliente[i] = cliente[k];
                cliente[k] = aux;
            }
        }
    }

    for(int i=0; i<j; i++){
        ImprimeAluno(cliente[i]);
        
    }

    //free de todos os ponteiros alocados dinamicamente;

    for(int i=0; i<nAlunos; i++){
        ApagaAluno(alunos[i]);   
    }

    free(cliente);

    free(alunos);

    return 0;

}
