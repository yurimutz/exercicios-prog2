#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

//typedef struct Conta tConta;

struct Conta{

    int numConta;
    char nome[50];
    float saldo;

};

tConta *CriaConta(){

    tConta *conta = malloc(sizeof(tConta));

    conta->numConta = 0;

    conta->saldo = 0;

    return conta;

}

void DestroiConta(DataType conta){

    free(conta);

}

void LeConta(tConta *conta){

    char aux[50];

    scanf("%*[\n]");
    scanf("%[^\n]", aux);
    scanf("%*[\n]");

    sscanf(aux, "%d;%[^;];%f", &conta->numConta, conta->nome, &conta->saldo);

}

float GetSaldoConta(tConta *conta){

    return conta->saldo;

}