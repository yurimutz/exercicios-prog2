#include "contato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Contato tContato;

struct Contato{

    char nome[100];
    unsigned long int numero;

};

/**
 * @brief Cria um novo contato.
 * 
 * @param nome Nome do contato.
 * @param telefone Telefone do contato.
 * @return tContato* Retorna um ponteiro para o contato criado. Caso não seja possível alocar memória, encerra o programa.
*/
tContato *CriarContato(char *nome, unsigned long int telefone){

    tContato *contato = malloc(sizeof(tContato));

    memset(contato->nome, 0, 100);

    strcpy(contato->nome, nome);

    contato->numero = telefone;

    return contato;

}

/**
 * @brief Libera a memória alocada para um contato.
 * 
 * @param contato Ponteiro para o contato a ser liberado.
*/
void DestruirContato(tContato *contato){

    free(contato);

}

/**
 * @brief Imprime as informações de um contato.
 * Formato de impressão:
 * Nome: <nome>
 * Telefone: <telefone>
 * 
 * @param contato Ponteiro para o contato a ser impresso.
*/
void ImprimirContato(tContato *contato){

    printf("Nome: %s\n", contato->nome);

    printf("Telefone: %lu\n\n", contato->numero);

}

/**
 * @brief Salva as informações de um contato em um arquivo binario.
 * 
 * @param contato Ponteiro para o contato a ser salvo.
 * @param arquivo Ponteiro para o arquivo binario onde o contato será salvo.
*/
void SalvarContato(tContato *contato, FILE *arquivo){

    fwrite(contato->nome, sizeof(char), 100, arquivo);

    fwrite(&contato->numero, sizeof(unsigned long int), 1 ,arquivo);


}

/**
 * @brief Le as informações de um contato da entrada padrão, primeiro lendo o nome e depois o telefone.
 * 
 * @return tContato* Retorna um ponteiro para o contato lido.
*/
tContato *LeContato(){

    char nome[100];
    unsigned long int numero;

    scanf("%*[\n]");
    scanf("%s", nome);
    scanf("%*[\n]");

    scanf("%lu", &numero);
    scanf("%*[\n]");

    tContato *contato = CriarContato(nome, numero);

    return contato;

}

/**
 * @brief Carrega as informações de um contato de um arquivo binario, primeiro lendo o nome e depois o telefone.
 * 
 * @param arquivo Ponteiro para o arquivo binario de onde o contato será carregado.
 * @return tContato* Retorna um ponteiro para o contato carregado.
*/
tContato *CarregarContato(FILE *arquivo){

    char nome[100];
    unsigned long int numero;

    fread(nome, sizeof(char), 100, arquivo);

    fread(&numero, sizeof(unsigned long int), 1, arquivo);

    tContato *contato = CriarContato(nome, numero);

    return contato;

}

/**
 * @brief Compara dois contatos pelo número de telefone.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os números de telefone dos contatos são iguais e 0 caso contrário.
*/
int ComparaTelefoneContato(tContato *c1, tContato *c2){

    return c1->numero == c2->numero;

}

/**
 * @brief Compara dois contatos pelo nome.
 * 
 * @param c1 Ponteiro para o primeiro contato a ser comparado.
 * @param c2 Ponteiro para o segundo contato a ser comparado.
 * @return int Retorna 1 se os nomes dos contatos são iguais e 0 caso contrário.
*/
int ComparaNomeContato(tContato *c1, tContato *c2){

    if(strcmp(c1->nome, c2->nome) == 0){

        return 1;

    } else {

        return 0;

    }

}

/**
 * @brief Retorna o número de telefone de um contato.
 * 
 * @param contato Ponteiro para o contato.
 * @return unsigned long int Retorna o número de telefone do contato.
*/
unsigned long int GetTelefoneContato(tContato *contato){

    return contato->numero;

}

/**
 * @brief Retorna o nome de um contato.
 * 
 * @param contato Ponteiro para o contato.
 * @return char* Retorna o nome do contato.
*/
char *GetNomeContato(tContato *contato){

    return contato->nome;

}