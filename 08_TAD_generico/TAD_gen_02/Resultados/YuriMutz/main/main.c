#include "gerenciadorpacotes.h"
#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("tad_gen_02\n");
    printf("\n");

    tGerenciador *geren = CriaGerenciador();

    int mode = 0, flag = 0, tipo = 0, numElem = 0, indAux = 0;

    // char c = getchar();

    while(1){        

        if(flag != 0){
            
            break;

        }

        //printf("\n");
        printf("Escolha uma opcao:\n");
        printf("	(1) Cadastrar um novo pacote\n");
        printf("	(2) Imprimir um pacote específico\n");
        printf("	(3) Imprimir todos os pacotes e sair\n");

        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            
            
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:");

            scanf("%d %d", &tipo, &numElem);

            if(tipo !=0 && tipo != 1){

                printf("\n");
                printf("Digite um tipo valido!\n");
                break;

            } else if(tipo == 0){

                tPacote *pacote = CriaPacote(2, numElem);

                LePacote(pacote);

                printf("\n");

                AdicionaPacoteNoGerenciador(geren, pacote);

            } else {
            
                tPacote *pacote = CriaPacote(1, numElem);

                LePacote(pacote);

                printf("\n");

                AdicionaPacoteNoGerenciador(geren, pacote);

            }

            break;

        case 2:
            
            scanf("%d", &indAux);

            ImprimirPacoteNoIndice( geren, indAux);

            break;

        case 3:
            
            ImprimirTodosPacotes(geren);

            flag++;

            break;
        
        default:

            printf("Escolha uma opcao valida para o menu!\n");
            
            break;
        }


    }

    DestroiGerenciador(geren);

    return 0;

}