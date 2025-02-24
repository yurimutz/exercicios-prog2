#include "relatorio.h"
#include "vector.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    Vector *vet = VectorConstruct();

    int numAlunos = 0;

    scanf("%d\n", &numAlunos);

    for(int i = 0; i < numAlunos; i++){

        tAluno *alunoAux = CriaAluno();

        LeAluno(alunoAux);

        VectorPushBack(vet, (tAluno*)alunoAux);


    }

    ImprimeRelatorio(vet);

    VectorDestroy(vet, DestroiAluno);

    return 0;

}