#include <stdio.h>

int somaDigitos(int n);

int main(){

    int numero=0;
    scanf("%d", &numero);
    printf("%d\n",  somaDigitos(numero));

return 0;    
}

int somaDigitos(int n){
    int soma=0;
    if((n/10)<1){
        return n;
    } else {
        soma+=n%10;
        return soma + somaDigitos(n/10);
    }
}