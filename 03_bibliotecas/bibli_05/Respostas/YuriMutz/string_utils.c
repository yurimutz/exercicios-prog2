#include "string_utils.h"
#include <stdio.h>

int string_length(char *str){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    // while(1){
    //     if(str[i] == '\0'){
    //         i++;
    //         break;
    //     } else {
    //         i++;
    //     }
    // }
return i+1;
}

void string_copy(char *src, char *dest){
    int i=0;
    while(src[i]!='\0'){
        dest[i]=src[i];
        i++;
    }
    dest[i]='\0';
}

void string_upper(char *str){
    int i=0;
    while(str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] + 'A' - 'a';
        } 
        i++;
    }
}

void string_lower(char *str){
    int i=0;
    while(str[i] != '\0'){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 'a' - 'A';
        } 
        i++;
    }    
}

void string_reverse(char *str){
    char teste[100];
    int soma=0, i=0, j=0;
    soma = string_length(str)-3;
    string_copy(str, teste);   
    for(i=soma; i>=0; i--){        
        str[j] = teste[i];       
        j++;
    }

}