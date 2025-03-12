#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Produto tProduto;

struct Produto{

    int codigo;
    char nome[50];
    float preco;
    int qtd;

};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida){

    tProduto *produto = malloc(sizeof(tProduto));

    produto->codigo = codigo;

    strcpy(produto->nome, nome);

    produto->preco = preco;

    produto->qtd = quantidadeVendida;

    return produto;

}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto){

    free(produto);

}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo: 
 * Código (int) 
 * Nome (string) 
 * Preço (float) 
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo){

    int codigo = 0;

    fread(&codigo, sizeof(int), 1, arquivo);

    char nome[50];

    fread(nome, sizeof(char), 50, arquivo);

    float preco = 0;

    fread(&preco, sizeof(float), 1, arquivo);

    int qtd = 0;

    fread(&qtd, sizeof(int), 1, arquivo);

    tProduto *produto = CriaProduto(codigo, nome, preco, qtd);

    return produto;

}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco;Quantidade vendida".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto){

    printf("%d;%s;R$ %0.2f;%d", produto->codigo, produto->nome, produto->preco, produto->qtd);

}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto){

    return produto->qtd;

}

/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
*/
float GetPrecoProduto(tProduto *produto){

    return produto->preco;

}