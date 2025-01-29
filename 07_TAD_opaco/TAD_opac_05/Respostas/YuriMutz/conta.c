#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

struct Conta{

    tUsuario *usuario;
    int numConta;
    float saldo;

};

tConta *CriaConta(){

    tConta *conta = NULL;

    conta = malloc(sizeof(tConta));

    conta->numConta = -1;
    conta->saldo = 0;
    conta->usuario = CriaUsuario();

    if(conta == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    } else {
        return conta;
    }

}

void DestroiConta(tConta *conta){

    DestroiUsuario(conta->usuario);

    free(conta);

}

void LeConta(tConta *conta){

    
    LeUsuario(conta->usuario);

    scanf("%d ", &conta->numConta);

}

void ImprimeConta(tConta *conta){

    printf("Conta: %d\n", conta->numConta);
    printf("Saldo: R$ %0.2f\n", conta->saldo);
    ImprimeUsuario(conta->usuario);

}

int VerificaConta(tConta *conta, int numero){

    if(conta->numConta == numero){
        return 1;
    } else {
        return 0;
    }

}

void SaqueConta(tConta *conta, float valor){

    if(conta->saldo >= valor){
        conta->saldo -= valor;
    }

}

void DepositoConta(tConta *conta, float valor){

    conta->saldo += valor;

}

void TransferenciaConta(tConta *destino, tConta *origem, float valor){

    if(origem->saldo >= valor){    
        DepositoConta(destino, valor);
        SaqueConta(origem, valor);
    } else {
        printf("Sem money\n");
    }

}