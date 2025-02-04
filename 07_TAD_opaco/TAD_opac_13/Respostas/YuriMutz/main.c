#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pad.h"


int main(){

    tPad *pad = CriaPad();

    RodaPad(pad);

    ImprimeRelatorioPad(pad);

    LiberaPad(pad);

    return 0;

}