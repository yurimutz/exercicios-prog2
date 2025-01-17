#include <stdio.h>
#include "pessoa.h"


tPessoa CriaPessoa(){

    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL; 

    return pessoa;

}

void LePessoa(tPessoa *pessoa){

    
        scanf("%[^\n]", &pessoa->nome);
        scanf("%*[\n]");
        printf("%s\n", pessoa->nome);
    
    // int i = 0;
    // while(1){
    //     scanf("%c", &pessoa->nome[i]);
    //     if(pessoa->nome[i] == '\n' && i != 0){
    //         pessoa->nome[i] = '\0';
    //         break;
    //     } else {
    //         i++;
    //         continue;
    //     }
    // }
    // printf("%s\n", pessoa->nome);
    
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai != NULL || pessoa->mae != NULL){
        return 1;
    } else {
        return 0;
    }
}

void ImprimePessoa(tPessoa *pessoa){
    
    if(VerificaSeTemPaisPessoa(pessoa) == 1){
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        if(pessoa->pai != NULL){
            printf("PAI: %s\n", pessoa->pai->nome);
        } else {
            printf("PAI: NAO INFORMADO\n");
        }
        if(pessoa->mae != NULL){
            printf("MAE: %s\n", pessoa->mae->nome);
        } else {
            printf("MAE: NAO INFORMADO\n");
        }
    }

    printf("\n");

}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){




    int familias = 0;
    scanf("%d", &familias);
    if(familias != 0){
        printf("oi %d oi\n", familias);
    } else {
        printf("Errado\n");
    }

    int mae = 0, pai = 0, filho = 0;

    char lixo[100];

    for(int i=0; i<familias; i++){
        printf("oi2\n");
        scanf("%[a-zA-Z:]", &lixo);
        scanf("%*[a-zA-Z:]");
        scanf("%d", &mae);

        scanf("%*[, ]");
        scanf("%[a-zA-Z:]", &lixo);
        scanf("%*[a-zA-Z:]");
        scanf("%d", &pai);

        scanf("%*[, ]");
        scanf("%[a-zA-Z:]", &lixo);
        scanf("%*[a-zA-Z:]");
        scanf("%d", &filho);
        scanf("%*c");

        printf("%d %d %d\n", mae, pai, filho);

        if(mae != -1){
            pessoas[filho].mae = &pessoas[mae]; 
        }
        if(pai != -1){
            pessoas[filho].pai = &pessoas[pai];     
        }

    }


}