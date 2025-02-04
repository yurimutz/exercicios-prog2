#include "biblioteca.h"
#include "livro.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int operacoes = 0, mode = 0;
    scanf("%d ", &operacoes);

    tBiblioteca *biblioteca = InicializarBiblioteca();

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    printf("\n");

    for(int i = 0; i < operacoes; i++){

        scanf("%d ", &mode);

        switch (mode){

        case 1:
            
            tLivros *livroAux = CriaLivro();

            LerLivro(&livroAux);

            AdicionarLivroNaBiblioteca(biblioteca, livroAux);

            ApagaLivro(livroAux);

            break;
            

        case 2:
            
            char *strAux;
            scanf("%[^\n]", strAux);
            scanf("%*[\n]");

            RemoverLivroDaBiblioteca(biblioteca, strAux);

            break;

        case 3:

            ListarLivrosDaBiblioteca(biblioteca);

            break;
        
        default:

            printf("Invalido\n");

            break;

        }


    }

    ApagaBiblioteca(biblioteca);

    return 0;

}