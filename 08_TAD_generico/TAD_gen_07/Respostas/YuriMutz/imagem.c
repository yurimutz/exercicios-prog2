#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

// typedef enum {
//     FLOAT = 0, 
//     INT = 1    
// } Tipo;

/**
 * @brief Estrutura para representar uma imagem.
 */
//typedef struct tImagem Imagem;

struct tImagem{

    int altura;
    int largura;
    Tipo tipo;
    void *vet;

};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img){

    return img->altura;

}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img){

    return img->largura;

}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img){

    return img->tipo;

}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img){

    return img->vet;

}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo){

    Imagem *img = malloc(sizeof(Imagem));

    img->altura = altura;

    img->largura = largura;

    img->tipo = tipo;

    if(tipo == FLOAT){

        img->vet = malloc(altura * largura *sizeof(float));

    } else {

        img->vet = malloc(altura * largura *sizeof(int));

    }

    return img;

}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem(){

    int altura = 0, largura = 0;
    int tipo;

    scanf("%d %d %d\n", &altura, &largura, &tipo);

    Imagem *img;

    if(tipo == FLOAT){

        img = CriarImagem(altura, largura, FLOAT);

    } else {

        img = CriarImagem(altura, largura, INT);

    }

    float fAux = 0;
    int iAux = 0;

    for(int i = 0; i < img->altura * img->largura; i++){

        if(img->tipo == FLOAT){

            scanf("%f ", &fAux);
        
            ((float*)img->vet)[i] = fAux;

        } else {

            scanf("%d ", &iAux);

            ((int*)img->vet)[i] = iAux;

        }

    }

    return img;

}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img){

    printf("oi\n");

}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img){

    free(img->vet);

    free(img);

}