#include "estabelecimento.h"
#include "vector.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Estabelecimento tEstabelecimento;

struct Estabelecimento{

    Vector *dado;

};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento(){

    tEstabelecimento *est = malloc(sizeof(tEstabelecimento));

    est->dado = VectorConstruct();

    return est;

}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento){


    void(*destroy)(void*);

    destroy = DestroiProduto;

    VectorDestroy(estabelecimento->dado, destroy);

    free(estabelecimento);

}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto){

    VectorPushBack(estabelecimento->dado, produto);

}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento){

    char arquivo[50];

    scanf("%s", arquivo);

    FILE *fp;

    fp = fopen(arquivo, "r");

    int qtd = 0;

    fread(&qtd, sizeof(int), 1, fp);

    for(int i = 0; i < qtd; i++){

        tProduto *prodAux = LeProduto(fp);

        AdicionaProdutoEstabelecimento(estabelecimento, prodAux);

    }

    fclose(fp);

}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento){

    int contador = 0;

    printf("Produtos em falta:\n");
    printf("Codigo;Nome;Preco\n");

    for(int i = 0; i < VectorSize(estabelecimento->dado); i++){

        if(!TemEstoqueProduto(VectorGet(estabelecimento->dado, i))){

            contador++;

        }

    }

    if(contador == 0){

        printf("Nao ha produtos em falta!\n");

    } else {

        for(int i = 0; i < VectorSize(estabelecimento->dado); i++){

            if(!TemEstoqueProduto(VectorGet(estabelecimento->dado, i))){

                ImprimeProduto(VectorGet(estabelecimento->dado, i));

            }

        }

    }

}