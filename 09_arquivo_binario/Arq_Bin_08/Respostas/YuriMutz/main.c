#include "lista_contato.h"
#include "vector.h"
#include "contato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printaMenu(){

    printf("1 - Cadastrar contato\n");
    printf("2 - Remover contato\n");
    printf("3 - Realizar busca\n");
    printf("4 - Exibir todos os contatos\n");
    printf("0 - Sair da lista de contatos\n");
    printf("Opcao escolhida:\n");

}

int main(){

    tListaContato *lista = CriarListaContato();

    char file1[50];
    scanf("%[^\n]", file1);
    scanf("%*[\n]");

    CarregarListaContato(lista, file1);

    int mode = 0;
    int flag = 0;

    tContato *contatoAux;

    while(1){


        if(flag != 0){

            break;

        }

        printaMenu();

        scanf("%d\n", &mode);

        switch (mode)
        {
        case 1:
            
            contatoAux = LeContato();

            AdicionarContatoListaContato(lista, contatoAux);

            break;

        case 2:
            
            RemoverContatoListaContato(lista);

            break;

        case 3:
            
            printf("\n1 - Buscar pelo nome\n");
            printf("2 - Buscar pelo numero de telefone\n");
            printf("Opcao escolhida:\n");

            int opcao = 0;
            scanf("%d\n", &opcao);

            if(opcao == 1){

                BuscarPorNomeListaContato(lista);

            } else if(opcao == 2){

                BuscarPorNumeroTelefoneListaContato(lista);

            }

            break;

        case 4:
            
            ImprimirListaContato(lista);

            break;

        case 0:
            
            char nome2[50];

            scanf("%[^\n]", nome2);
            scanf("%*[\n]");

            SalvarListaContato(lista, nome2);

            flag++;

            break;
        
        default:
            break;
        }

    }

    DestruirListaContato(lista);

}