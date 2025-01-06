#include "tDepartamento.h"
#include <stdio.h>
#include "string.h"

tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor ){
    
    tDepartamento dep;

    strcpy(dep.curso1, curso1);
    strcpy(dep.curso2, curso2);
    strcpy(dep.curso3, curso3);
    strcpy(dep.nome, nome);
    strcpy(dep.diretor, diretor);
   
    dep.m1 = m1;
    dep.m2 = m2;
    dep.m3 = m3;

    return dep;
                                
}

void ImprimeAtributosDepartamento(tDepartamento depto){

    float media;
    int soma = depto.m1 + depto.m2 + depto.m3;
    media =  (float)soma / 3.0;

    printf("Departamento: %s\n", depto.nome);
    printf("\t");
    printf("Diretor: %s\n", depto.diretor);
    printf("\t");
    printf("1o curso: %s\n", depto.curso1);
    printf("\t");
    printf("Media do 1o curso: %d\n", depto.m1);
    printf("\t");
    printf("2o curso: %s\n", depto.curso2);
    printf("\t");
    printf("Media do 2o curso: %d\n", depto.m2);
    printf("\t");
    printf("3o curso: %s\n", depto.curso3);
    printf("\t");
    printf("Media do 3o curso: %d\n", depto.m3);
    printf("\t");
    printf("Media dos cursos: %0.2f\n", media);

}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    int media[3];

    tDepartamento depAux;

    for(int i=0; i<num_deptos; i++){
        media[i] = vetor_deptos[i].m1 + vetor_deptos[i].m2 + vetor_deptos[i].m3;
    }

    for(int i=0; i<num_deptos-1; i++){
        for(int j=i+1; i<num_deptos; i++){
            if(media[j] > media[i]){
                depAux = vetor_deptos[i];
                vetor_deptos[i] = vetor_deptos[j];
                vetor_deptos[j] = depAux;
            }
        }
    }

    printf("\n");

}