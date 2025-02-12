#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct Conta{

    int id;
    float saldo;

};

tConta* CriaConta(int id){

    tConta *conta = malloc(sizeof(tConta));

    conta->id = id;

    conta->saldo = 0;

    return conta;

}

void DestroiConta(tConta* conta){

    free(conta);

}

void AlteraSaldoConta(tConta* conta, float valor){

    conta->saldo += valor;

}

int ConfereIdConta(tConta* conta, int id){

    return conta->id == id;

}

int RetornaIdConta(tConta* conta){

    return conta->id;

}

float RetornaSaldoConta(tConta* conta){

    return conta->saldo;

}