#include "utils.h"

int main(){

    int linhas = 0, colunas= 0;

    scanf("%d %d", &linhas, &colunas);

    int **matriz = CriaMatriz(linhas, colunas);

    LeMatriz(matriz, linhas, colunas);

    ImprimeMatrizTransposta(matriz, linhas, colunas);

    LiberaMatriz(matriz, linhas);

    return 0;

}