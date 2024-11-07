#include "esfera_utils.h"
#include <stdio.h>

int main(){

    float raio=0;
    scanf("%f", &raio);
    
    printf("Area: %0.2f\n", calcula_area(raio));
    printf("Volume: %0.2f\n", calcula_volume(raio));

return 0;
}