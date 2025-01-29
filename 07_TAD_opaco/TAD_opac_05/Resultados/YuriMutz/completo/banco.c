#include "banco.h"
#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

struct Banco{

    tConta *contas[5];
    int contasCriadas;    

};

tBanco *CriaBanco(){

    tBanco *banco = NULL;

    banco = malloc(sizeof(tBanco));

    for(int i = 0; i < 5; i++){
        banco->contas[i] = NULL;
        banco->contas[i] = CriaConta();  
    }

    banco->contasCriadas = 0;

    return banco;

}

void DestroiBanco(tBanco *banco){

    for(int i = 0; i < 5; i++){
        DestroiConta(banco->contas[i]);
        banco->contas[i] = NULL;
    }

    free(banco);

}

void AbreContaBanco(tBanco *banco){

    LeConta(banco->contas[banco->contasCriadas]);

    banco->contasCriadas++;

}

void SaqueContaBanco(tBanco *banco){

    int numConta = 0;
    float valor = 0;

    scanf("%d %f ", &numConta, &valor);

    for(int i = 0; i < banco->contasCriadas; i++){
        if(VerificaConta(banco->contas[i], numConta)){
            SaqueConta(banco->contas[i], valor);
            break;
        }
    }

}

void DepositoContaBanco(tBanco *banco){

    int numConta = 0;
    float valor = 0;

    scanf("%d %f ", &numConta, &valor);

    for(int i = 0; i < banco->contasCriadas; i++){
        if(VerificaConta(banco->contas[i], numConta)){
            DepositoConta(banco->contas[i], valor);
            break;
        }
    }

}

void TransferenciaContaBanco(tBanco *banco){

    int numContaDestino = 0, numContaOrigem = 0;
    float valor = 0;

    scanf("%d %d %f ", &numContaDestino, &numContaOrigem, &valor);

    int i = 0;
    for(i = 0; i < banco->contasCriadas; i++){
        if(VerificaConta(banco->contas[i], numContaDestino)){
            break;
        }
    }

    int j = 0;
    for(j = 0; j < banco->contasCriadas; j++){
        if(VerificaConta(banco->contas[j], numContaOrigem)){
            break;
        }
    }

    TransferenciaConta(banco->contas[i], banco->contas[j], valor);


}

void ImprimeRelatorioBanco(tBanco *banco){

    printf("===| Imprimindo Relatorio |===\n");
    for(int i = 0; i < banco->contasCriadas; i++){
        ImprimeConta(banco->contas[i]);
    }

}
