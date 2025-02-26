#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct tHistograma Histograma;

struct tHistograma{

    int *pixelPorInter;
    int nIntervalos;
    int tamIntervalos;

};

/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos){

    Histograma *h = malloc(sizeof(Histograma));

    h->nIntervalos = nIntervalos;

    h->pixelPorInter = malloc(nIntervalos * sizeof(int));
    
    for(int i = 0; i < nIntervalos; i++){

        h->pixelPorInter[i] = NULL;

    }

    if((256 % nIntervalos) == 0){

        h->tamIntervalos = 256 / nIntervalos;

    } else {

        h->tamIntervalos = (256 / nIntervalos) + 1; 

    }

    void *aux = ObterDadosImagem(img);

    float fAux;
    int dAux;

    int menor = 0;
    int maior = h->tamIntervalos;

    for(int j = 0; j < nIntervalos; j++){

        for(int i = 0; i < ObterLargura(img) * ObterAltura(img); i++){

            if(ObterTipoImagem(img) == FLOAT){

                fAux = ((float*)aux)[i];

                dAux = (int)(fAux * 255);

                if(dAux >= menor && dAux < maior){

                    h->pixelPorInter[j]++;

                }

            } else {

                dAux = ((int*)aux)[i];

                if(dAux >= menor && dAux < maior){

                    h->pixelPorInter[j]++;

                }

            }

        }

        maior = maior + h->tamIntervalos;
        menor = menor + h->tamIntervalos;

    }

    return h;

}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma){

    int menor = 0;
    int maior = histograma->tamIntervalos;

    for(int i = 0; i < histograma->nIntervalos; i++){

        printf("[%d, %d): ", menor, maior);

        printf("%d\n", histograma->pixelPorInter[i]);

        menor = menor + histograma->tamIntervalos;
        maior = maior + histograma->tamIntervalos;

    }

}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma){

    free(histograma->pixelPorInter);

    free(histograma);

}