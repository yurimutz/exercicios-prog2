#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){
    if( mes == 4 || mes == 6 || mes == 9 || mes == 11 ){
        if( dia > 30){
            return 0;
        }
    } else if( mes == 2 ){
        if( ano % 4 == 0 ){
            if( dia > 29 ){
                return 0;
            }
        } else {
            if( dia > 28 ){
                return 0;
            }
        }
    } else if( dia > 31){
        return 0;
    } else {
        return 1;
    }
return 1;
}

void imprimeMesExtenso(int mes){
    switch ( mes )
    {
    case 1:
        if( mes == 1 ){
            printf("Janeiro");
        }   
        break;
    case 2:
        if( mes == 2 ){
            printf("Fevereiro");
        }
        break;
    case 3:
        if( mes == 3 ){
            printf("Marco");
        }
        break;
    case 4:
        if( mes == 4 ){
            printf("Abril");
        }
        break;
    case 5:
        if( mes == 5 ){
            printf("Maio");
        }
        break;
    case 6:
        if( mes == 6 ){
            printf("Junho");
        }
        break;
    case 7:
        if( mes == 7 ){
            printf("Julho");
        }
        break;
    case 8:
        if( mes == 8 ){
            printf("Agosto");
        }
        break;
    case 9:
        if( mes == 9 ){
            printf("Setembro");
        }
        break;
    case 10:
        if( mes == 10 ){
            printf("Outubro");
        }
        break;
    case 11:
        if( mes == 11 ){
            printf("Novembro");
        }
        break;
    case 12:
        if( mes == 12 ){
            printf("Dezembro");
        }
        break;    
    default:
        break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int verificaBissexto(int ano){
    return (ano%4)==0;
}

int numeroDiasMes(int mes, int ano){
    if( mes==4 || mes==6 || mes==9 || mes==11){
        return 30;
    }
    if(mes==2){
        if( verificaBissexto(ano) ){
            return 29;
        } 
        else {
            return 28;
        }        
    } 
    return 31;    
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if( ano1 > ano2 ){
        return 1;
    } else if( ano1 < ano2 ){
        return -1;
    } else if( ano1 == ano2 ){
        if( mes1 > mes2 ){
            return 1;
        } else if( mes1 < mes2 ){
            return -1;
        } else if( mes1 == mes2 ){
            if( dia1 > dia2 ){
                return 1;
            } else if( dia1 < dia2 ){
                return -1;
            } 
        }   
    }
    return 0;
}

int calculaDiasAteMes(int mes, int ano);

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int soma=0, diaaux=0;
    if(comparaData( dia1, mes1, ano1, dia2, mes2, ano2 ) == 0 ){
        return 0;
    } else if(comparaData( dia1, mes1, ano1, dia2, mes2, ano2 ) == 1 ){
        while(comparaData( dia1, mes1, ano1, dia2, mes2, ano2 ) != 0){
            diaaux = numeroDiasMes( mes2 , ano2);
            if( dia2 < diaaux){
                dia2++;
                soma++;
            } else {
                dia2 = 1;
                soma++;
                if( mes2 < 12){
                    mes2++;
                } else {
                    soma++;
                    mes2 = 1;
                    ano2++;
                }
            }
        }
    } else if(comparaData( dia1, mes1, ano1, dia2, mes2, ano2 ) == -1 ){
        while(comparaData( dia1, mes1, ano1, dia2, mes2, ano2 ) != 0){
            diaaux = numeroDiasMes( mes1 , ano1);
            if( dia1 < diaaux){
                dia1++;
                soma++;
            } else {
                dia1 = 1;
                soma++;
                if( mes1 < 12){
                    mes1++;
                } else {
                    mes1 = 1;
                    ano1++;
                }
            }
        }
    }
return soma;
}