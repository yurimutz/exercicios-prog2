#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Biblioteca{

    tLivros **livro;
    int tamanho;

};

tBiblioteca* InicializarBiblioteca(){

    tBiblioteca *biblioteca = malloc(sizeof(tBiblioteca));

    biblioteca->livro = (tLivros **)malloc(NUM_INICIAL_LIVROS * sizeof(tLivros*));

    for(int i = 0; i < NUM_INICIAL_LIVROS; i++){
  
        biblioteca->livro[i] = NULL;

    }

    biblioteca->tamanho = 0;

    return biblioteca;

}

void ApagaBiblioteca(tBiblioteca* biblioteca){

    for(int i = 0; i < biblioteca->tamanho; i++){

        if(biblioteca->livro[i] != NULL){ 

            ApagaLivro(biblioteca->livro[i]);

        }

    }

    free(biblioteca->livro);

    free(biblioteca);

}

void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro){

    if(biblioteca->tamanho < NUM_INICIAL_LIVROS){

        biblioteca->livro[biblioteca->tamanho] = livro;

        printf("Livro adicionado com sucesso!\n");

        biblioteca->tamanho++;

    } else {

        biblioteca->livro = realloc(biblioteca->livro, 10 * NUM_INICIAL_LIVROS * sizeof(tLivros*));

        biblioteca->livro[biblioteca->tamanho] = livro;

        printf("Livro adicionado com sucesso!\n");

        biblioteca->tamanho++;
        

    }

}

void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char *titulo){

    int flag = 0;

    for(int i = 0; i < biblioteca->tamanho; i++){


        if(biblioteca->livro[i] != NULL){

            if(VerificaTituloDoLivroNaBiblioteca(biblioteca->livro[i], titulo) == 0){

                ApagaLivro(biblioteca->livro[i]);

                biblioteca->livro[i] = NULL;

                printf("Livro removido com sucesso!\n");   

                flag = 1;

                break;

            }

        }

    }

    if(flag == 0){

        printf("Livro nao encontrado na biblioteca.\n");

    }

}

int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo){

    char *tituloAux = getTitulo(livro);

    if(strcmp(tituloAux, titulo) == 0){

        return 0;
 
    } else {  

        return 1;

    }


}

void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca){

    int flag = 0;

    for(int i = 0; i < biblioteca->tamanho; i++){

        if(biblioteca->livro[i] != NULL){

            flag++;

        }

    }

    if(flag == 0){

        printf("A biblioteca esta vazia!\n");

    } else {

        printf("\n");
        printf("Lista de Livros na Biblioteca:\n");

        for(int i = 0; i < biblioteca->tamanho; i++){

            if(biblioteca->livro[i] != NULL){

                ImprimeLivro(biblioteca->livro[i]);

            }

        }

    }

}