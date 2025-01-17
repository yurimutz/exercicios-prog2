#include <stdio.h>
#include "pessoa.h"
// int main(){

//     char oi[100];
//     char oi2[100];
//     int num = 0;
//     int num2 = 0;

//     scanf("%[a-zA-Z:]");
//     scanf("%*[a-zA-Z:]");
//     scanf("%d", &num);
    
//     scanf("%*[, ]");
//     scanf("%[a-zA-Z:]", oi2);
//     scanf("%*[a-zA-Z:]");
//     scanf("%d", &num2);

//     printf("%d %d", num, num2);

//     return 0;
// }

int main(){

    int numPes = 0;
    scanf("%d", &numPes);
    scanf("%*[\n]");

    tPessoa individuos[numPes];

    for(int i=0; i<numPes; i++){

        individuos[i] = CriaPessoa();
        LePessoa(&individuos[i]);

    }

    AssociaFamiliasGruposPessoas(individuos);

    for(int i=0; i<numPes; i++){
        ImprimePessoa(&individuos[i]);
    }


    return 0;

}