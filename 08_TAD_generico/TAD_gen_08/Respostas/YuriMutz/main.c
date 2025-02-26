#include "fila.h"
#include "movel.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    Fila *fila = FilaConstruct();

    tMovel *movel = NULL;

    int casos = 0;
    scanf("%d\n", &casos);

    char tipo[25];

    for(int i = 0; i < casos; i++){

        scanf("%*[\n]");
        scanf("%[^ \n]", tipo);
        scanf("%*[ \n]");

        if(strcmp(tipo, "ENTRADA") == 0){

            movel = LeMovel();

            FilaPush(fila, (tMovel*)movel);


        } else {

            tMovel *movelPop = FilaPop(fila); 

            ImprimeMovel(movelPop);  

            DestroiMovel(movelPop);  

        }


    }

    FilaDestroy(fila, DestroiMovel);

    return 0;

}