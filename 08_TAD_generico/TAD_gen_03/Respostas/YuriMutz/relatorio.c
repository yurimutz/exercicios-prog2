#include "relatorio.h"
#include "vector.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

// @brief Imprime o relatorio de uma coleção de alunos.
//  * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
//  * 
//  * @param alunos Ponteiro para o vetor de alunos.

void ImprimeRelatorio(Vector *alunos){

    float totalNotas = 0, media = 0, masc = 0, fem = 0, outro = 0, porcAprov = 0;
    int aprovados = 0;

    for(int i = 0; i < VectorSize(alunos); i++){

        tAluno* aluno = VectorGet(alunos, i);

        if(GetNotaAluno(aluno) >= 6){

            aprovados++;

        }

        totalNotas += GetNotaAluno(aluno);

        char gen = GetGeneroAluno(aluno);

        switch (gen)
        {
        case 'M':
            
            masc++;

            break;
        
        case 'F':
            
            fem++;

            break;

        case 'O':
            
            outro++;

            break;
        
        default:
            break;
        }

    }

    media = totalNotas / (float)VectorSize(alunos);
    printf("Media das notas: %0.2f\n", media);

    porcAprov = aprovados / (float)VectorSize(alunos);
    printf("Porcentagem de alunos aprovados: %0.2f%%\n", 100 * porcAprov);

    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %0.2f%%\n", 100 * (masc / (float)VectorSize(alunos)));
    printf("Feminino: %0.2f%%\n", 100 * (fem / (float)VectorSize(alunos)));
    printf("Outro: %0.2f%%\n", 100 * (outro / (float)VectorSize(alunos)));


}