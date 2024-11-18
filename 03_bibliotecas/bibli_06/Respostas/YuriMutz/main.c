#include <stdio.h>
#include "temperature_conversor.h"

int main(){

    float temperature=0;
    char mode1, mode2;
    scanf("%f %1c %1c", &temperature, &mode1, &mode2);
    
    switch (mode1)
    {
    case 'c':
        if(mode2 == 'f'){
            printf("Temperature: %0.2fFº", convert_celsius_to_fahrenheit(temperature));
        } else {
            printf("Temperature: %0.2fK", convert_celsius_to_kelvin(temperature));    
        }
        break;

    case 'f':
        if(mode2 == 'c'){
            printf("Temperature: %0.2fCº", convert_fahrenheit_to_celsius(temperature));
        } else {
            printf("Temperature: %0.2fK", convert_fahrenheit_to_kelvin(temperature));
        }
        break;

    case 'k':
        if(mode2 == 'c'){
            printf("Temperature: %0.2fCº", convert_kelvin_to_celsius(temperature));
        } else {
            printf("Temperature: %0.2fFº", convert_kelvin_to_fahrenheit(temperature));
        }
        break;

    default:
        break;
    }



return 0;
}