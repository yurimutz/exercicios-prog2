#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data{

    int dia;
    int mes;
    int ano;

};

tData* CriaData(){

    tData *data = malloc(sizeof(tData));

    data->dia = -1;
    data->mes = -1;
    data->ano = -1;

    return data;

}

void LeData(tData* data){

    scanf("%d/%d/%d ", &data->dia, &data->mes, &data->ano);

}

void LiberaData(tData* data){

    free(data);

}

int VerificaDataValida(tData* data){

    if(data->dia > NumeroDiasMes(data)){
        return 0;
    } else if(data->mes > 12){
            return 0;
    } else {
        return 1;
    }
        
}

void ImprimeMesExtenso(tData* data){

    switch (data->mes)
    {
    case 1:
        printf("Janeiro ");
        break;

    case 2:
        printf("Fevereiro ");
        break;
    
    case 3:
        printf("Marco ");
        break;
    
    case 4:
        printf("Abril ");
        break;
    
    case 5:
        printf("Maio ");
        break;
    
    case 6:
        printf("Junho");
        break;
    
    case 7:
        printf("Julho ");
        break;
    
    case 8:
        printf("Agosto ");
        break;
    
    case 9:
        printf("Setembro ");
        break;
    
    case 10:
        printf("Outubro ");
        break;
    
    case 11:
        printf("Novembro ");
        break;
    
    case 12:
        printf("Dezembro ");
        break;
    
    default:
        break;
    }


}

void ImprimeDataExtenso(tData* data){

    printf("%02d de ", data->dia);
    ImprimeMesExtenso(data);
    printf("de %d\n", data->ano);

}

int VerificaBissexto(tData* data){

    if(data->ano % 4 != 0){
        return 0;
    } else {
        return 1;
    }

}

int NumeroDiasMes(tData* data){

    if(data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11){
        return 30;
    } if(data->mes == 2){
        if(VerificaBissexto(data)){
            return 29;
        } else {
            return 28;
        }
    }

    return 31;

}

int ComparaData(tData* data1, tData* data2){

    if(data1->ano > data2->ano){
        return 1; 
    } else if(data1->ano < data2->ano){
        return -1;
    } else if(data1->ano == data2->ano){
        if(data1->mes > data2->mes){
            return 1;
        } else if(data1->mes < data2->mes){
            return -1;
        } else if(data1->mes == data2->mes){
            if(data1->dia > data2->dia){
                return 1;
            } else if(data1->dia < data2->dia){
                return -1;
            } else {
                return 0;
            }
        }
    }

}

int CalculaDiasAteMes(tData* data){

    int diff = 0;

    diff = NumeroDiasMes(data) - data->dia;

    return diff;

}

int CalculaDiferencaDias(tData* data1, tData* data2){

    int soma = 0, diaAux = 0;

    if(ComparaData(data1, data2) == 0){

        return 0;

    } else {

        if(ComparaData(data1, data2) == 1){ 

            while(ComparaData(data1, data2) != 0){

                diaAux = NumeroDiasMes(data2); 

                if(data2->dia < diaAux){

                    data2->dia++;

                    soma++;

                } else {

                    soma++;

                    data2->dia = 1;

                    if(data2->mes < 12){

                        data2->mes++;

                    } else {

                        data2->mes = 1;

                        data2->ano++;

                    }

                }   

            }
        } else if(ComparaData(data1, data2) == -1){  

            while(ComparaData(data1, data2) != 0){

                diaAux = NumeroDiasMes(data1); 

                if(data1->dia < diaAux){

                    data1->dia++;

                    soma++;

                } else {

                    data1->dia = 1;

                    soma++;

                    if(data1->mes < 12){

                        data1->mes++;

                    } else {

                        data1->mes = 1;

                        data1->ano++;

                    }

                }

            }
        
        }

    }

    return soma;

}