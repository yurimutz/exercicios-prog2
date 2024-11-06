#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

void preencheVetor(int* vet, int numElementos);   

int main(){

    int numero=0, i=0, numElementos=0, numeroProcurado=0;
    int vet[100];
    
    scanf("%d", &numero);
    for(i=0; i<numero; i++){
        scanf("%d %d", &numeroProcurado, &numElementos);
        preencheVetor(vet, numElementos);
        printf("%d\n", ContaOcorrencias(vet, numElementos, numeroProcurado));
    }

return 0;
}

void preencheVetor(int* vet, int numElementos){
    int i=0;
    for(i=0; i<numElementos; i++){
        scanf("%d", &vet[i]);
    } 
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    int soma=0;
    if(numElementos==0){
        return soma;
    } else if(vet[numElementos-1]==numeroProcurado){
        soma+=1;
        return soma + ContaOcorrencias(vet, numElementos-1, numeroProcurado);
    } else {
        return soma + ContaOcorrencias(vet, numElementos-1, numeroProcurado); 
    }
}