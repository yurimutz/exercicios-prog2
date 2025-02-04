#include "livro.h"
#include <stdio.h>

struct Livros{

    char *titulo;
    char *autor;
    int anoPubli;

};



tLivros* CriaLivro(){

    tLivros *livro = malloc(sizeof(tLivros));

    livro->titulo = NULL;
    livro->titulo = malloc(50 * sizeof(char));
    
    livro->autor = NULL;
    livro->autor = malloc(50 * sizeof(char));
   
    livro->anoPubli = -1;

    return livro;

}

void LerLivro(tLivros* livro){

    //scanf("%*[\n]");
    scanf("%[^\n]", livro->titulo);
    scanf("%*[\n]");

    scanf("%[^\n]", livro->autor);
    scanf("%*[\n]");

    scanf("%d ", &livro->anoPubli);

}

void ImprimeLivro(tLivros* livro){

    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->anoPubli);
    printf("\n");    

}

char *getTitulo(tLivros* livro){

    return livro->titulo;

}

void ApagaLivro(tLivros* livro){

    free(livro->titulo);

    free(livro->autor);

    free(livro);

}