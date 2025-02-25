#include "agendatarefas.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int num = 0, pri = 0;
    char mode;

    printf("Digite o numero de tarefas:");

    scanf("%d\n", &num);

    tAgendaTarefas *agenda = CriaAgendaDeTarefas(num);

    for(int i = 0; i < num; i++){

        scanf("%d", &pri);
        scanf(" %c ", &mode);
        //scanf("%*[\n]");

        switch (mode)
        {
        case 'I':

            char msg[50];
            scanf("%*[\n]");
            scanf("%[^\n]", msg);
            scanf("%*[\n]");

            tImpr *imp = CriaTarefaImprimir(msg);

            CadastraTarefaNaAgenda(agenda, pri, imp, ExecutaTarefaImprimir, DestroiTarefaImprimir);

            break;

        case 'M':
            
            float n1 = 0, n2 = 0;
            scanf("%f %f\n", &n1, &n2);

            tMult *mult = CriaTarefaMultiplicar(n1, n2);

            CadastraTarefaNaAgenda(agenda, pri, mult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);

            break;

        case 'S':
            
            float s1 = 0, s2 = 0;
            scanf("%f %f\n", &s1, &s2);

            tSoma *soma = CriaTarefaSoma(s1, s2);

            CadastraTarefaNaAgenda(agenda, pri, soma, ExecutaTarefaSoma, DestroiTarefaSoma);

            break;
        
        default:

            printf("\n");
            printf("Digite um tipo de tarefa suportado (I/S/M))");
            scanf("%[^\n]", msg);
            scanf("%*[\n]");
            i--;
            
            break;
        }



    }

    ExecutarTarefasDaAgenda(agenda);

    DestroiAgendaDeTarefas(agenda);

    return 0;

}