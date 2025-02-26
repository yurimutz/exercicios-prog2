#include "histograma.h"
#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int nIntervalos = 0;
    scanf("%d\n", &nIntervalos);

    // int altura = 0, largura = 0, tipo = 0;
    // scanf("%d %d %d\n", &altura, &largura, &tipo);

    // Imagem *img;

    // if(tipo == 0){

    //     img = CriarImagem(altura, largura, FLOAT);

    // } else {

    //     img = CriarImagem(altura, largura, INT);

    // }   

    Imagem *img = LerImagem();

    Histograma *h = CalcularHistograma(img, nIntervalos);

    MostrarHistograma(h);

    DestruirHistograma(h);

    DestruirImagem(img);

    return 0;

}