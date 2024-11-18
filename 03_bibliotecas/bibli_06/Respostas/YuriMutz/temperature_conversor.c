#include "temperature_conversor.h"
#include <stdio.h>

float convert_celsius_to_kelvin(float temperature){
    float soma=0;
    soma = temperature + 273.15;
    return soma;    
}

float convert_celsius_to_fahrenheit(float temperature){
    float fah=0;
        fah = (1.8 * temperature) + 32;
        return fah;    
}

float convert_kelvin_to_celsius(float temperature){
    return temperature - 273.15;
}

float convert_kelvin_to_fahrenheit(float temperature){
    float fah=0;
    fah = ((temperature - 273.15) * 1.8) + 32;
    return fah;
}

float convert_fahrenheit_to_celsius(float temperature){
    float celsius=0;
    celsius = (temperature-32) * 5/9;
    return celsius;
}

float convert_fahrenheit_to_kelvin(float temperature){
    float kelvin=0;
    kelvin = (((temperature - 32) * 5) / 9) + 273.15;
    return kelvin;
}

float convert_temperature(float temperature, float convert_func(float temperature)){
    float temp=0;
    temp = convert_func(temperature);
    return temp;
}