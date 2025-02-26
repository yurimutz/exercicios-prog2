#include "histograma.h"
#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int nIntervalos = 0;
    scanf("%d\n", &nIntervalos);  

    Imagem *img = LerImagem();

    Histograma *h = CalcularHistograma(img, nIntervalos);

    MostrarHistograma(h);

    DestruirHistograma(h);

    DestruirImagem(img);

    return 0;

}