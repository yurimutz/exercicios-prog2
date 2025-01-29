#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

struct Usuario{

    char nome[25];
    char cpf[15];

};

tUsuario *CriaUsuario(){

    tUsuario *usuario = NULL;

    usuario = malloc(sizeof(tUsuario));

    if(usuario == NULL){
        printf("Erro ao alocar\n");
        exit(0);
    } else {
        return usuario;
    }

}

void DestroiUsuario(tUsuario *user){

    free(user);

}

void LeUsuario(tUsuario *user){

    scanf("%s", user->nome);

    scanf("%s", user->cpf);

}

void ImprimeUsuario(tUsuario *user){

    printf("Nome: %s\n", user->nome);
    printf("CPF: %s\n", user->cpf);
    printf("\n");

}