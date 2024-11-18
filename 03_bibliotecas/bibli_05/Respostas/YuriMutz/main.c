#include <stdio.h>
#include "string_utils.h"


int main(){

    int mode=0, i=0;
    char string[100], dest[100];

    scanf("%c", &string[0]);
    while(string[i]!='\n'){
        i++;
        scanf("%c", &string[i]);            
    }
    string[i+1] = '\0';

    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");

    while(scanf("%d", &mode)==1){
        switch (mode)
        {
            case 1:
                printf("Tamanho da string: %d\n", string_length(string)); 
                printf("\n");   
                break;

            case 2:
                string_copy(string, dest);
                printf("String copiada: %s", dest);
                break;
                
            case 3:
                string_upper(string);
                printf("String convertida para maiusculas: %s", string);
                break;

            case 4:
                string_lower(string);
                printf("String convertida para minusculas: %s", string);
                break;

            case 5:
                string_reverse(string);
                printf("String invertida: %s\n", string);
                break;

            case 6:
                return 0;
                break;

            default:
                break;
            }
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");
    }


return 0;    
}