#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:");

    int tam = 0;

    int tipo = 0;

    scanf("%d %d ", &tipo, &tam);

    tGeneric *gen = CriaGenerico(tipo, tam);

    LeGenerico(gen);

    ImprimeGenerico(gen);

    DestroiGenerico(gen);

    return 0;

}

