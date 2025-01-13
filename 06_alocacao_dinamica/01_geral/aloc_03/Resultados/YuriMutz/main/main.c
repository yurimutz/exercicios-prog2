#include "utils_char.h"

int main(){

    int tamanho = 0;
    scanf("%d", &tamanho);
    scanf("%*c");

    char *vetor = CriaVetor(tamanho);

    ImprimeString(vetor, tamanho);

    LeVetor(vetor, tamanho);

    ImprimeString(vetor, tamanho);

    LiberaVetor(vetor);

    return 0;

}
