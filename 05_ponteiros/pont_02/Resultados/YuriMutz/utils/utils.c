#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n){
    int v1 = 0, v2 = 0;
    
    scanf("%d%d", &v1, &v2);

    *m = v1;
    *n = v2;

}

int EhPrimo(int n){
    int i = 0, soma = 0;

    for(i=1; i<=n; i++){
        if(n % i == 0){
            soma++;
        }
    }

    if(soma <= 2){
        return 1;
    } else {
        return 0;
    }

}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    int i = 0, menorp = 10000, maiorp = 0;

    for(i=m; i<=n; i++){
        if(EhPrimo(i)){
            if(i > maiorp){
                maiorp = i;
            }
            if(i < menorp){
                menorp = i;
            }
        }
    }

    *menor = menorp;
    
    *maior = maiorp;

}