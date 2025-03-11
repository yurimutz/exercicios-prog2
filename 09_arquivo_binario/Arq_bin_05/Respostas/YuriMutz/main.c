#include "estabelecimento.h"
#include "vector.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    tEstabelecimento *est = CriaEstabelecimento();

    LeEstabelecimento(est);

    ImprimeProdutosEmFaltaEstabelecimento(est);

    DestroiEstabelecimento(est);

    return 0;

}