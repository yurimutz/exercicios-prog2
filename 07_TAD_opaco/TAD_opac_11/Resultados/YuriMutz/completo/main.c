#include "loja.h"
#include "vendedor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int numLojas = 0, mode = 0;
    scanf("%d ", &numLojas);

    tLoja **loja = malloc(numLojas * sizeof(tLoja*));

    for(int i = 0; i < numLojas; i++){

        loja[i] = NULL;

    }

    while(1){

        scanf("%d ", &mode);

        switch (mode){

            case 1:
                
                int idAux = 0;
                
                float Aluguel = 0;

                scanf("%d %f ", &idAux, &Aluguel);

                loja[idAux-1] = AbreLoja(idAux, Aluguel);

                break;

            case 2:
                
                char nome[50];
                float salario = 0, comissao = 0;

                scanf("%s", nome);
                scanf("%*[\n]");

                scanf("%f %f ", &salario, &comissao);


                tVendedor *vendedor = RegistraVendedor(nome, salario, comissao); 

                int idAux2 = 0;

                scanf("%d ", &idAux2);

                ContrataVendedor(loja[idAux2-1], vendedor);

                break;

            case 3:
                
                char nome2[50];
                int idAux3 = 0;
                float valor = 0;

                scanf("%d ", &idAux3);

                scanf("%s", nome2);
                scanf("%*[\n]");

                scanf("%f ", &valor);

                RegistraVenda(loja[idAux3-1], nome2, valor);

                break;

            case 4:
                
                for(int i = 0; i < numLojas; i++){
                    
                    CalculaLucro(loja[i]);
                    ImprimeRelatorioLoja(loja[i]);

                }

                break;
            
            default:

                for(int i = 0; i < numLojas; i++){

                    ApagaLoja(loja[i]);

                }

                free(loja);

                return 0;

                break;
        }

    }

    return 0;

}
