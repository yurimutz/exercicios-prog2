#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct Agencia tAgencia;

struct Agencia{

    Vector *conta;
    int numAgen;
    char nome[15];

};

tAgencia *CriaAgencia(){

    tAgencia *agencia = malloc(sizeof(tAgencia));

    agencia->numAgen = 0;

    agencia->conta = VectorConstruct();

    return agencia;


}

void DestroiAgencia(DataType agencia){

    tAgencia *aux = (tAgencia*)agencia;

    VectorDestroy(aux->conta, DestroiConta);

    free(agencia);

}

void LeAgencia(tAgencia *agencia){

    char aux[50];

    scanf("%*[\n]");
    scanf("%[^\n]", aux);
    scanf("%*[\n]");

    sscanf(aux, "%d;%[^\n]", &agencia->numAgen, agencia->nome);

}

void AdicionaConta(tAgencia *agencia, tConta *conta){

    VectorPushBack(agencia->conta, (tConta*)conta);

}

int ComparaAgencia(int numAgencia, tAgencia *agencia2){

    return numAgencia == agencia2->numAgen;

}

float GetSaldoMedioAgencia (tAgencia *agencia){

    int qtd = VectorSize(agencia->conta);

    float saldoTotal = 0;

    for(int i = 0; i < qtd; i++){

        saldoTotal += GetSaldoConta(VectorGet(agencia->conta, i));

    }

    return saldoTotal / (float)qtd;

}

void ImprimeDadosAgencia(tAgencia *agencia){

    printf("\t");
    printf("Nome: %s\n", agencia->nome);

    printf("\t");
    printf("Numero: %d\n", agencia->numAgen);

    printf("\t");
    printf("Numero de contas cadastradas: %d\n", VectorSize(agencia->conta));

    printf("\t");
    printf("Saldo médio: R$%0.2f\n", GetSaldoMedioAgencia(agencia));
    printf("\n");
    
}