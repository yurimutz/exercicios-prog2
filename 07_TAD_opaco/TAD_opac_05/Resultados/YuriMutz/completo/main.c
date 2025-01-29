#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "conta.h"
#include "usuario.h"

int main(){

    char modo;

    tBanco *banco = CriaBanco();
    
    while(1){

        scanf("%c ", &modo);
        if(modo == 'F'){
            break;
        }

        switch (modo)
        {
            case 'A':
                AbreContaBanco(banco);
                break;
            
            case 'D':
                DepositoContaBanco(banco);
                break;           
            
            case 'S':
                SaqueContaBanco(banco);
                break;
                        
            case 'T':
                TransferenciaContaBanco(banco);
                break;
                        
            case 'R':
                ImprimeRelatorioBanco(banco);
                break;
                      
            default:
                printf("Comando invalido\n");
                break;
        }
    }

    DestroiBanco(banco);

    return 0;

}