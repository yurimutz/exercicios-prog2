#include "lista_contato.h"
#include "vector.h"
#include "contato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//typedef struct ListaContato tListaContato;

struct ListaContato{

    Vector *dado;

};

/**
 * @brief Cria uma lista de contatos.
 * 
 * @return tListaContato* Retorna um ponteiro para a lista de contatos criada. Caso não seja possível alocar memória, encerra o programa.
*/
tListaContato *CriarListaContato(){

    tListaContato *lista = malloc(sizeof(tListaContato));

    lista->dado = VectorConstruct();

    return lista;

}

/**
 * @brief Libera a memória alocada para uma lista de contatos.
 * 
 * @param l Ponteiro para a lista de contatos a ser liberada.
*/
void DestruirListaContato(tListaContato *l){

    VectorDestroy(l->dado, DestruirContato);

    free(l);

}

/**
 * @brief Adiciona um contato a uma lista de contatos, somente se o contato ainda não existir na lista 
 * (não pode haver dois contatos com o mesmo nome e/ou número de telefone).
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param contato Ponteiro para o contato a ser adicionado.
*/
void AdicionarContatoListaContato(tListaContato *l, tContato *contato){

    int flag = 0;

    for(int j = 0; j < VectorSize(l->dado); j++){

        if(ComparaTelefoneContato(contato, VectorGet(l->dado, j)) || ComparaNomeContato(contato, VectorGet(l->dado, j))){

            flag++;
            break;
            
        }

    }

    if(flag == 0){

        VectorPushBack(l->dado, contato);
    
    } else {

        printf("\nJa existe um contato com esse nome e/ou numero de telefone\n");
        DestruirContato(contato);

    }

}

/**
 * @brief Carrega uma lista de contatos de um arquivo binário.
 * Se o arquivo não existir, a lista de contatos permanece vazia.
 * Dica: Se o arquivo não existir, o ponteiro para o arquivo será NULL. Portanto, se o ponteiro for NULL, a função deve retornar sem fazer nada.
 * 
 * Formato do arquivo binário (caso exista):
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário de onde a lista de contatos será carregada.
*/
void CarregarListaContato(tListaContato *l, char* nomeArquivo){

    int flag = 0;

    if(nomeArquivo != NULL){

        //printf("%s\n", nomeArquivo);

        FILE *fp;

        fp = fopen(nomeArquivo, "rb");

        if(fp != NULL){
            
            int qtd = 0;

            fread(&qtd, sizeof(int), 1, fp);

            for(int i = 0; i < qtd; i++){

                tContato *contato = CarregarContato(fp);
                
                AdicionarContatoListaContato(l, contato);

            }

            fclose(fp);

        }

    }

}

/**
 * @brief Salva uma lista de contatos em um arquivo binário.
 * 
 * Formato do arquivo binário:
 * - int: quantidade de contatos
 * - para cada contato:
 *  - char[100]: nome
 *  - char[20]: telefone
 * 
 * @param l Ponteiro para a lista de contatos.
 * @param nomeArquivo Nome do arquivo binário onde a lista de contatos será salva.
*/
void SalvarListaContato(tListaContato *l, char* nomeArquivo){

    FILE *fp = fopen(nomeArquivo, "w");

    int aux = 0;

    aux = VectorSize(l->dado);

    fwrite(&aux, sizeof(int), 1, fp);

    for(int i = 0; i < VectorSize(l->dado); i++){

        SalvarContato(VectorGet(l->dado, i), fp);

    }

    fclose(fp);

}

/**
 * @brief Busca um contato na lista de contatos pelo número de telefone e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNumeroTelefoneListaContato(tListaContato *l){

    int flag = 0;

    unsigned long int aux;

    scanf("%lu", &aux);
    scanf("%*[\n]");

    for(int i = 0; i < VectorSize(l->dado); i++){

        if(GetTelefoneContato(VectorGet(l->dado, i)) == aux){

            ImprimirContato(VectorGet(l->dado, i));
            flag = 1;
            break;

        }

    }

    if(flag == 0){

        printf("\nContato nao encontrado\n");

    }

    //scanf("%*c");

}

/**
 * @brief Busca um contato na lista de contatos pelo nome e imprime as informações do contato na tela.
 * Se o contato não existir, imprime "Contato nao encontrado".
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void BuscarPorNomeListaContato(tListaContato *l){

    int flag = 0;

    char nome[50];

    scanf("%*[^a-zA-Z]");
    scanf("%[^\n]", nome);
    scanf("%*[\n]");

    for(int i = 0; i < VectorSize(l->dado); i++){

        if(strcmp(GetNomeContato(VectorGet(l->dado, i)), nome)== 0){

            ImprimirContato(VectorGet(l->dado, i));
            flag = 1;
            break;

        }

    }

    if(flag == 0){

        printf("\nContato nao encontrado\n");

    }

    //scanf("%*c");

}

/**
 * @brief Imprime a lista de contatos na tela.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void ImprimirListaContato(tListaContato *l){

    printf("\nLista de contatos cadastrados\n");

    for(int i = 0; i < VectorSize(l->dado); i++){

        ImprimirContato(VectorGet(l->dado, i));

    }

}

/**
 * @brief Remove um contato da lista de contatos caso ele exista.
 * 
 * @param l Ponteiro para a lista de contatos.
*/
void RemoverContatoListaContato(tListaContato *l){

    int flag = 0;

    unsigned long int aux;

    scanf("%lu\n", &aux);

    for(int i = 0; i < VectorSize(l->dado); i++){

        if(GetTelefoneContato(VectorGet(l->dado, i)) == aux){

            DestruirContato(VectorGet(l->dado, i));
            VectorRemove(l->dado, i);
            flag++;
            break;

        }

    }

    if(flag == 0){

        printf("\nNao existe um contato cadastrado com esse numero de telefone\n");

    } else {

        printf("\nContato removido com sucesso\n");

    }


}