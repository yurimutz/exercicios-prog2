#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{

    int dia;
    int mes;
    int ano;

};

tData* LeData(){

    tData *data = malloc(sizeof(tData));

    scanf("%d/%d/%d ", &data->dia, &data->mes, &data->ano);

    return data;

}

tData* CriaData(int dia, int mes, int ano){

    tData *data = malloc(sizeof(tData));

    data->dia = dia;

    data->mes = mes;

    data->ano = ano;

    return data;

}

void LiberaData(tData* d){

    free(d);

}

int CalculaIdadeData(tData* nascimento, tData* diacalc){

    int idade = 0;

    idade = diacalc->ano - nascimento->ano;

    // if(diacalc->mes > nascimento->mes){

    //     idade++;

    // } 

    return idade;

}

void ImprimeData(tData* d){

    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);

}