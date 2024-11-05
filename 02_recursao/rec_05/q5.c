#include <stdio.h>

int fatorial(int n);

int main(){

    int n=0;
    scanf("%d", &n);
    printf("%d\n", fatorial(n));

return 0;    
}

int fatorial(int n){
    if(n==0){
        return 1;
    } else {
        return n * fatorial(n-1);
    }
}