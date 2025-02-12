#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "operacao.h"
#include "conta.h"

int main(){

    tAgencia *agencia =  CriaAgencia();

    printf("--- Agencia Bancaria ---");

    LeOperacoes(agencia);

    ImprimeOperacoesSuspeitas(agencia);

    ImprimeDoisCorrentistasComMaiorSaldo(agencia);

    ImprimeSaldoTotal(agencia);

    DestroiAgencia(agencia);

    return 0;

}