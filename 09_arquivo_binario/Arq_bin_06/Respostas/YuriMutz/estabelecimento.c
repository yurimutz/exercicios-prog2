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
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento){

    float total = 0;

    for(int i = 0; i < VectorSize(estabelecimento->dado); i++){

        total += GetPrecoProduto(VectorGet(estabelecimento->dado, i)) * (float)GetQuantidadeVendidaProduto(VectorGet(estabelecimento->dado, i));

    }

    return total;

}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento){

    float porcento = 0;

    printf("Valor total vendido: R$ %0.2f\n", GetValorTotalVendidoEstabelecimento(estabelecimento));

    printf("Produtos vendidos:\n");

    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");

    for(int i = 0; i < VectorSize(estabelecimento->dado); i++){

        ImprimeProduto(VectorGet(estabelecimento->dado, i));

        porcento = (GetPrecoProduto(VectorGet(estabelecimento->dado, i)) * (float)GetQuantidadeVendidaProduto(VectorGet(estabelecimento->dado, i))) / GetValorTotalVendidoEstabelecimento(estabelecimento);

        printf(";%0.2f%%\n", 100 * porcento);

    }

}