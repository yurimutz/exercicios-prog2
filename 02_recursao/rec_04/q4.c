#include <stdio.h>
#include <string.h>

int palindromo(char *string, int tamanho);

int main(){

    char string[100];
    int tamanho=0;
    while(scanf("%s", &string)==1){
        tamanho=strlen(string);
        if(palindromo(string, tamanho) || tamanho==1){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    
return 0;    
}

int palindromo(char *string, int tamanho){
    int maior=tamanho-1;
    if(tamanho<=0){
        return 1;
    }else if(string[0]==string[maior]){        
        return 1 * palindromo(string+1, tamanho-2);
    } else {
        return 0;
    }
}