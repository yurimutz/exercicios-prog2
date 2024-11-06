#include <stdio.h>

void ImprimeInvertido(char* string);

int main(){

    char string[1000];
    while(scanf("%s", &string)==1){
        ImprimeInvertido(string);
        printf(" ");    
    }

return 0;    
}

void ImprimeInvertido(char* string){
    if(string[0]!='\0'){
        ImprimeInvertido(string+1);
        printf("%c", string[0]);   
    }
}