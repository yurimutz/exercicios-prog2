#include "banco.h"
#include "conta.h"
#include "vector.h"
#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct Banco tBanco;
 
struct Banco{

    Vector *agencia;
    char nome[50];

};

tBanco *CriaBanco(){

    tBanco *banco = malloc(sizeof(tBanco));

    banco->agencia = VectorConstruct();

    return banco;

}

void DestroiBanco(tBanco *banco){

    VectorDestroy(banco->agencia, DestroiAgencia);

    free(banco);

 }
 
void LeBanco(tBanco *banco){

    scanf("%[^\n]", banco->nome);
    scanf("%*[\n]");

 }

void AdicionaAgencia(tBanco *banco, tAgencia *agencia){

    VectorPushBack(banco->agencia, (tAgencia*)agencia);

}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){

    int aux = 0;

    for(int i = 0 ; i < VectorSize(banco->agencia); i++){

        if(ComparaAgencia(numAgencia, VectorGet(banco->agencia, i))){

            aux = i;

            break;

        }

    }

    AdicionaConta(VectorGet(banco->agencia, aux), cliente);

}

void ImprimeRelatorioBanco(tBanco *banco){

    printf("%s\n", banco->nome);

    printf("Lista de agencias:\n");

    int qtd = VectorSize(banco->agencia);

    for(int i = 0; i < qtd; i++){

        ImprimeDadosAgencia(VectorGet(banco->agencia, i));

    }

}