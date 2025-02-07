#include <stdio.h>
#include <stdlib.h>
#include "array.h"


int main(){

    Array *vet = CriarArray();

    LerArray(vet);

    OrdenarArray(vet);

    int elemento = 0;

    scanf("%d ", &elemento);

    if(BuscaBinariaArray(vet, elemento) != -1){

        printf("Elemento %d encontrado no índice %d.\n", elemento, BuscaBinariaArray(vet, elemento));

    } else {

        printf("Elemento %d não encontrado no array (-1).\n", elemento);

    }

    DestruirArray(vet);

    return 0;

}