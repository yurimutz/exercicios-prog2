#include "vendedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vendedor{

    char *nome;
    float valorVend;
    float salario;
    float porcentagem;

};

tVendedor* RegistraVendedor(char* nome, float salario, float prct_comissao){

    tVendedor *vendedor = (tVendedor *)malloc(sizeof(tVendedor));

    vendedor->nome = malloc(50 * sizeof(char));

    strcpy(vendedor->nome, nome);

    vendedor->salario = salario;

    vendedor->porcentagem = prct_comissao;

    vendedor->valorVend = 0;

    return vendedor;

}

void ApagaVendedor(tVendedor* vendedor){

    free(vendedor->nome);

    free(vendedor);

}

int VerificaNomeVendedor(tVendedor* vendedor, char* nome){

    if(strcmp(vendedor->nome, nome) == 0){

        return 1;

    } else {

        return 0;

    }

}

void ContabilizaVenda(tVendedor* vendedor, float valor){

    vendedor->valorVend += valor;

}

float GetSalario(tVendedor* vendedor){

    return vendedor->salario;

}

float GetComissao(tVendedor* vendedor){

    return vendedor->valorVend * vendedor->porcentagem;

}

float GetTotalVendido(tVendedor* vendedor){

    return vendedor->valorVend;

}

float GetTotalRecebido(tVendedor* vendedor){

    //printf("%s %f %f\n", vendedor->nome, vendedor->salario, vendedor->porcentagem);

    float aux = 0;

    aux = vendedor->valorVend * vendedor->porcentagem;

    aux += vendedor->salario;

    return aux;

}

void ImprimeRelatorioVendedor(tVendedor* vendedor){

    printf("\t");
    printf("%s > Total vendido: R$%0.2f\n", vendedor->nome, vendedor->valorVend);
    printf("\t");
    printf("\t");
    printf("Total recebido: R$%0.2f\n", GetTotalRecebido(vendedor));

}