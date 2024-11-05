#include <stdio.h>

int fibonacci(int n);

int main(){

    int numero=0;
    scanf("%d", &numero);
    printf("%d\n", fibonacci(numero));

return 0;    
}

int fibonacci(int n){
    if(n==0){
        return 0;
    } else if(n==1){
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}