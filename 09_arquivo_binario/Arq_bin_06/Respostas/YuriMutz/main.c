#include "estabelecimento.h"
#include "vector.h"
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    tEstabelecimento *est = CriaEstabelecimento();

    LeEstabelecimento(est);

    ImprimeRelatorioEstabelecimento(est);

    DestroiEstabelecimento(est);

    return 0;

}