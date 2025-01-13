#include "utils.h"

int main(){

    int tamanho = 0;
    scanf("%d", &tamanho);

    int *p = CriaVetor(tamanho);

    LeVetor(p, tamanho);

    //float media = CalculaMedia(p, tamanho);

    printf("%0.2f\n", CalculaMedia(p, tamanho));

    LiberaVetor(p);

    return 0;

}