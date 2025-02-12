#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "operacao.h"

struct Agencia{

    tConta **contas;
    int numContas;

    tOperacao **operacao;
    int numOp;

};

tAgencia* CriaAgencia(){

    tAgencia *agencia = malloc(sizeof(tAgencia));

    agencia->contas = NULL;

    agencia->numContas = 0;

    agencia->operacao = NULL;

    agencia->numOp = 0;

    return agencia;

}

void DestroiAgencia(tAgencia* agencia){

    for(int i = 0; i < agencia->numOp; i++){

        if(agencia->operacao[i] != NULL){

            DestroiOperacao(agencia->operacao[i]);
            agencia->operacao[i] = NULL;

        }

    }
    
    for(int i = 0; i < agencia->numContas; i++){

        if(agencia->contas[i] != NULL){

            DestroiConta(agencia->contas[i]);
            agencia->contas[i] = NULL;

        }

    }


    free(agencia->operacao);
    agencia->operacao = NULL;


    free(agencia->contas);
    agencia->contas = NULL;

    free(agencia);

}

void LeOperacoes(tAgencia *agencia){

    int contaAux = 0, opAux = 0;

    float valor = 0;

    scanf("%d ", &agencia->numContas);

    agencia->contas = malloc(agencia->numContas * sizeof(tConta*));

    for(int i = 0; i < agencia->numContas; i++){

        agencia->contas[i] = NULL;

    }

    for(int i = 0; i < agencia->numContas; i++){

        scanf("%d ", &contaAux);

        if(contaAux < 0){

            printf("\n");
            printf("Digite um id valido para a conta a ser cadastrada!");

            i--;

        } else {

            int flag = 0;

            for(int j = 0; j < i; j++){

                
                if(contaAux == RetornaIdConta(agencia->contas[j])){

                    printf("\n");
                    printf("Este id ja esta cadastrado na agencia. Digite um id diferente!");

                    flag = 1;

                    i--;

                    break;

                }


            }

            if(flag == 0){

                agencia->contas[i] = CriaConta(contaAux);

            }

        }

    }

    scanf("%d ", &agencia->numOp);

    agencia->operacao = malloc(agencia->numOp * sizeof(tOperacao*));

    for(int i = 0; i < agencia->numOp; i++){

        agencia->operacao[i] = NULL;  

    }

    for(int i = 0; i < agencia->numOp; i++){

        int flag2 = 0;

        scanf("%d %f ", &opAux, &valor);

        for(int j = 0; j < agencia->numContas; j++){

            if(ConfereIdConta(agencia->contas[j], opAux)){

                agencia->operacao[i] = CriaOperacao(agencia->contas[j], valor);

                AlteraSaldoConta(agencia->contas[j], valor);

                flag2 = 1;

                break;

            } 

        }

        if(flag2 == 0){

            i--;

            printf("\n");
            printf("Conta Invalida! Repita a operacao, mas com uma conta valida!");

        }

    }

}

tConta* BuscaContaPorId(tAgencia *agencia, int id){

    for(int i = 0; i < agencia->numContas; i++){

        if(ConfereIdConta(agencia->contas[i], id)){

            return agencia->contas[i];

        }

    }

    return NULL;

}

void ImprimeOperacoesSuspeitas(tAgencia* agencia){

    printf("\n");
    printf("A lista de operações suspeitas:");

    for(int i = 0; i < agencia->numOp; i++){

        if(agencia->operacao[i] != NULL){

            if(ConsultaValorOperacao(agencia->operacao[i]) > 20000 || ConsultaValorOperacao(agencia->operacao[i]) < -20000){

                ImprimeOperacao(agencia->operacao[i]);

            }

        }

    }

}

void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia* agencia){

    float valor1 = 0, valor2 = 0;
    int id1 = 0, id2 = 0;

    for(int i = 0; i < agencia->numContas; i++){

        if((RetornaSaldoConta(agencia->contas[i]) > valor1)){

            
            id1 = RetornaIdConta(agencia->contas[i]);
            valor1 = RetornaSaldoConta(agencia->contas[i]);

        }

    }

    for(int i = 0; i < agencia->numContas; i++){

        if((RetornaSaldoConta(agencia->contas[i]) > valor2 && RetornaSaldoConta(agencia->contas[i]) != valor1)){

            id2 = RetornaIdConta(agencia->contas[i]);
            valor2 = RetornaSaldoConta(agencia->contas[i]);

        }

    }

    printf("\n");
    printf("Os dois correntistas com maior saldo são:\n");
    printf("Id: %d, Saldo: %0.2f\n", id1, valor1);
    printf("Id: %d, Saldo: %0.2f\n", id2, valor2);


}

void ImprimeSaldoTotal(tAgencia* agencia){

    float saldoTotal = 0;

    for(int i = 0; i < agencia->numContas; i++){

        saldoTotal += RetornaSaldoConta(agencia->contas[i]);

    }

    printf("O saldo total da agencia eh: %0.2f", saldoTotal);

}