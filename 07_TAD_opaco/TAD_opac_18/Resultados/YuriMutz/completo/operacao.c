#include <stdio.h>
#include <stdlib.h>
#include "operacao.h"

struct Operacao{

    tConta *conta;
    float valorOp;

};

tOperacao* CriaOperacao(tConta* conta, float valor){

    tOperacao *operacao = malloc(sizeof(tOperacao));

    operacao->conta = conta;

    operacao->valorOp = valor;

    return operacao;

}

void DestroiOperacao(tOperacao* op){

    // if(op->conta != NULL){

    //     DestroiConta(op->conta);

    // }

    free(op);

}

float ConsultaValorOperacao(tOperacao* op){

    return op->valorOp;

}

void ImprimeOperacao(tOperacao* op){

    printf("\n");
    printf("Operação na conta %d com valor %0.2f", RetornaIdConta(op->conta), op->valorOp);

}