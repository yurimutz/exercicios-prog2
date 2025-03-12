#include "base_alunos.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    tBaseAlunos *base = CriarBaseAlunos();

    char arquivo[50];

    scanf("%[^\n]", arquivo);
    scanf("%*[\n]");

    LerBaseAlunos(base, arquivo);

    printf("Coeficiente de Rendimento Medio da base de alunos: %0.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);

    return 0;

}