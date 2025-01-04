#include "data.h"
#include <stdio.h>


void InicializaDataParam( int dia, int mes, int ano, tData *data){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData( tData *data ){   
    scanf("%2d %2d %4d", &data->dia, &data->mes, &data->ano);

    if(data->mes > 12){
        data->mes = 12;
    } 
    if(data->dia > InformaQtdDiasNoMes( data )){
        data->dia = InformaQtdDiasNoMes( data );  
    }

    InicializaDataParam(data->dia, data->mes, data->ano, data);

}

void ImprimeData( tData *data ){
    printf("\'%02d/%02d/%04d\'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){
    if((data->ano % 4 == 0)){
        return 1;
    } else {
        return 0;
    }
}

int InformaQtdDiasNoMes( tData *data ){
    if(data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12 ){
        return 31;
    } else if(data->mes == 2){
        if(EhBissexto( data )){
            return 29;
        } else {
            return 28;
        }
    } else {
        return 30;
    }
}

void AvancaParaDiaSeguinte( tData *data ){
    if(data->dia < InformaQtdDiasNoMes( data )){
        data->dia++;
    } else {
        if(data->mes < 12){
            data->dia = 1;
            data->mes++;
        } else if(data->mes == 12){
            data->dia = 1;
            data->mes = 1;
            data->ano++;
        }
    }
}

int EhIgual( tData *data1, tData *data2 ){
    if(data1->ano == data2->ano){
        if(data1->mes == data2->mes){
            if(data1->dia == data2->dia){
                return 1;
            }
        }
    }
    return 0;
}