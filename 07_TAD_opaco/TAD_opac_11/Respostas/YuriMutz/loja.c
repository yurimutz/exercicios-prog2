#include "loja.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Loja {

    int id;
    tVendedor **vendedor;
    float aluguel;
    int numeroVendedores;
    float lucro;

};

tLoja* AbreLoja(int id, float aluguel){

    tLoja *loja = malloc(sizeof(tLoja));

    loja->id = id;

    loja->aluguel = aluguel;

    loja->numeroVendedores = 0;

    loja->lucro = 0;

    loja->vendedor = NULL;

    return loja;

}

void ApagaLoja(tLoja* loja){

    for(int i = 0; i < loja->numeroVendedores; i++){

        ApagaVendedor(loja->vendedor[i]);

    }

    free(loja->vendedor);

    free(loja);

}

int VerificaIdLoja(tLoja* loja, int id){

    return loja->id == id;

}

void ContrataVendedor(tLoja* loja, tVendedor* vendedor){

    if(loja->numeroVendedores == 0){

        loja->vendedor = malloc(sizeof(tVendedor*));

        loja->vendedor[loja->numeroVendedores] = vendedor;

        loja->numeroVendedores++;

    } else {

        loja->vendedor = realloc(loja->vendedor , (loja->numeroVendedores + 1) * sizeof(tVendedor*));

        loja->vendedor[loja->numeroVendedores] = vendedor;

        loja->numeroVendedores++;

    }

}

void RegistraVenda(tLoja* loja, char* nome, float valor){

    for(int i = 0; i < loja->numeroVendedores; i++){

        if(VerificaNomeVendedor(loja->vendedor[i], nome)){

            ContabilizaVenda(loja->vendedor[i], valor);

            break;

        }

    }

}

void CalculaLucro(tLoja* loja){

    float lucro = 0;

    for(int i = 0; i < loja->numeroVendedores; i++){

        lucro += GetTotalVendido(loja->vendedor[i]);

        lucro -= GetTotalRecebido(loja->vendedor[i]);

    }

    lucro -= loja->aluguel;

    loja->lucro = lucro;

}

void ImprimeRelatorioLoja(tLoja* loja){

    CalculaLucro(loja);

    printf("Loja %d: Lucro total: R$ %0.2f\n", loja->id, loja->lucro);

    for(int i = 0; i < loja->numeroVendedores; i++){

        ImprimeRelatorioVendedor(loja->vendedor[i]);

    }

}
