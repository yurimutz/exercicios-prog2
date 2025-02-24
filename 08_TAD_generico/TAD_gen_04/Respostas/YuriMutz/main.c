#include "banco.h"
#include "conta.h"
#include "vector.h"
#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    tBanco *banco = CriaBanco();

    LeBanco(banco);

    char aux;

    int flag = 0;

    while(1){

        if(flag != 0){

            break;

        }

        scanf("%c", &aux);
        scanf("%*[\n]");

        switch (aux)
        {
        case 'A':
            
            tAgencia *agencia = CriaAgencia();

            LeAgencia(agencia);

            AdicionaAgencia(banco, agencia);

            break;

        case 'C':

            tConta *conta = CriaConta();

            LeConta(conta);

            int numAgencia = 0;

            scanf("%d\n", &numAgencia);

            InsereContaBanco(banco, numAgencia, conta);

            break;
            
        case 'F':
            
            flag++;

            break;
        
        default:
            break;
        }


    }

    ImprimeRelatorioBanco(banco);

    DestroiBanco(banco);

    return 0;

}