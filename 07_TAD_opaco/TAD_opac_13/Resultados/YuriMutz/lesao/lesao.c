#include "lesao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lesao {

    char *id;
    char *diagnostico;
    char *regiaoCorpo;
    int malignidade;

};

tLesao* CriaLesao(){

    tLesao *l = malloc(sizeof(tLesao));

    l->id = malloc(TAM_ID * sizeof(char));

    l->diagnostico = malloc(TAM_DIAG * sizeof(char));

    l->regiaoCorpo = malloc(TAM_REG * sizeof(char));

    l->malignidade = 0;

    return l; 

}

void LeLesao(tLesao* l){

    scanf("%[^\n]", l->id);
    scanf("%*[\n]");

    scanf("%[^\n]", l->diagnostico);
    scanf("%*[\n]");

    scanf("%[^\n]", l->regiaoCorpo);
    scanf("%*[\n]");

    scanf("%d ", &l->malignidade);

}

void LiberaLesao(tLesao* l){

    free(l->diagnostico);

    free(l->id);

    free(l->regiaoCorpo);

    free(l);

}

char* GetIdLesao(tLesao* l){

    return l->id;

}

int PrecisaCirurgiaLesao(tLesao* l){

    if(l->malignidade > 50){
        
        return 1;

    } else {

        return 0;

    }

}