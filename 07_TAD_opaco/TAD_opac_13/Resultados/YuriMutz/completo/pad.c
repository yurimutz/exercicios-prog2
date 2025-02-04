#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lesao.h"
#include "data.h"
#include "pad.h"
#include "data.h"
#include "paciente.h"

struct pad{

    tPaciente **paciente;
    int numPaciente;
    tData *data;

};

tPad* CriaPad(){

    tPad *pad = malloc(sizeof(tPad));

    pad->paciente = malloc(100 * sizeof(tPaciente *));

    for(int i = 0; i < 100; i++){

        pad->paciente[i] = NULL;

    }

    pad->numPaciente = 0;

    pad->data = CriaData(DIA_PAD, MES_PAD, ANO_PAD);

    return pad;

}

void RodaPad(tPad *p){

    char mode;

    while(1){

        scanf("%c ", &mode);

        if(mode == '\n'){

            break;

        } else {

            switch (mode) {

            case 'P':

                p->paciente[p->numPaciente] = CriaPaciente();

                LePaciente(p->paciente[p->numPaciente]);

                p->numPaciente++;

                break;

            case 'L':
                
                char sus[100];

                scanf("%[^\n]", sus);
                scanf("%*[\n]");

                for(int i = 0; i < p->numPaciente; i++){

                    if((p->paciente[i]) != NULL){

                        if(strcmp(GetCartaoSusPaciente(p->paciente[i]), sus) == 0){

                            tLesao *lesao = CriaLesao();

                            LeLesao(lesao);

                            AdicionaLesaoPaciente((p->paciente[i]), lesao);

                            break;

                        }

                    }

                } 
            
            default:

                break;
            }


        }

    }


}

void ImprimeRelatorioPad(tPad *p){

    printf("TOTAL PACIENTES: %d\n", p->numPaciente);

    int somaIdades = 0;

    for(int i = 0; i < p->numPaciente; i++){

        if(p->paciente[i] != NULL){

            somaIdades += CalculaIdadeData(GetNascimentoPaciente(p->paciente[i]), p->data);

        }

    }

    int mediaIdades = 0;

    mediaIdades = somaIdades / p->numPaciente;

    printf("MEDIA IDADE (ANOS): %d\n", mediaIdades);

    int totalLesoes = 0;
    int totalCirurgias = 0;

    for(int i = 0; i < p->numPaciente; i++){

        if(p->paciente[i] != NULL){

            totalLesoes += GetQtdLesoesPaciente(p->paciente[i]);
            totalCirurgias += GetQtdCirurgiasPaciente(p->paciente[i]);

        }

    }

    printf("TOTAL LESOES: %d\n", totalLesoes);

    printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);

    printf("LISTA DE PACIENTES:\n");

    for(int i = 0; i < p->numPaciente; i++){

        if(p->paciente[i] != NULL){

            ImprimePaciente(p->paciente[i]);

        }

    }


}

void LiberaPad(tPad *p){

    for(int i = 0; i < p->numPaciente; i++){

        if(p->paciente[i] != NULL){

            LiberaPaciente(p->paciente[i]);

        }

    }

    free(p->paciente);

    free(p->data);

    free(p);

}