#include <stdio.h>
#include "tDepartamento.h"

int main(){

    int  numDep = 0;
    scanf("%d", &numDep);

    tDepartamento departamento[numDep];

    char c1[STRING_MAX];
    char c2[STRING_MAX];
    char c3[STRING_MAX];
    char dir[STRING_MAX];
    char nome[STRING_MAX];
    int n1, n2, n3;

    for(int i=0; i<numDep; i++){

        while(1){
            scanf("%s", nome);
            scanf("%s", dir);
            scanf("%s", c1);
            scanf("%s", c2);
            scanf("%s", c3);
            scanf("%d %d %d", &n1, &n2, &n3);

            if(n1 < 0 || n2 < 0 || n3 < 0){\
                printf("\n");
                printf("Digite um departamento com médias válidas");
                continue;
            } else {
                break;
            }   

        }

        departamento[i] = CriaDepartamento( c1, c2, c3,
                                nome, n1, n2, n3, dir );

    }

    OrdenaDepartamentosPorMedia( departamento, numDep );

    for(int i=0; i<numDep; i++){
        ImprimeAtributosDepartamento(departamento[i]); 
    } 


    return 0;
}