#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);

void leVetor(int* vet, int tam);

int main(){
    
    int numVet=0, i=0, tamVet=0;
    int vet[50];
    scanf("%d", &numVet);
    for(i=0; i<numVet; i++){
        scanf("%d", &tamVet);
        leVetor(vet, tamVet);       
        printf("%d\n", SomaElementosPares(vet, tamVet));
    }

return 0;    
}

void leVetor(int* vet, int tam){
    int i=0;
    for(i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }
}

int SomaElementosPares(int* vet, int numElementos){
    int soma=0;
    if(numElementos<=0){
        return soma;    
    } else if((vet[numElementos-1]%2)==0){
        soma+=vet[numElementos-1];
        return soma + SomaElementosPares(vet, numElementos-1);
    } else {
        return soma + SomaElementosPares(vet, numElementos-1);
    }
}