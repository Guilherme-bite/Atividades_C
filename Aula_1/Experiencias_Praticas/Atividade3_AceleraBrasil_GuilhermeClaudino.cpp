#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIAS 15
#define TIPOS 4

int main() {

    //Vetores
    int veiculos[DIAS][TIPOS];
    int somaTipos[TIPOS] = {0};
    int dia, tipo;
    // Ordem: Caminhao, Onibus, Carro e Moto
    float tarifa[TIPOS] = {10.0, 7.0, 5.0, 3.0};
    float arrecadacao[DIAS];
    float totalGeral = 0;

    srand(time(NULL));

    char *nome[4] = {"Caminhao","Onibus","Carro","Moto"};

    printf("=== BEM VINDO AO ACELERA BRASIL ===\n");
    for (dia = 0; dia < DIAS; dia++) {
        printf("\nDia %d:\n", dia + 1);
        arrecadacao[dia] = 0;
        for (tipo = 0; tipo < TIPOS; tipo++) {
            veiculos[dia][tipo] = rand() % 451 + 50;

            printf("%-8s: %d\n", nome[tipo], veiculos[dia][tipo]);
            // Calcula a arrecadacao
            arrecadacao[dia] += veiculos[dia][tipo] * tarifa[tipo];
            somaTipos[tipo] += veiculos[dia][tipo];

        }
        totalGeral += arrecadacao[dia];
    }

    printf("\n=== RELATORIO ACELERA BRASIL ===\n");
    for (dia = 0; dia < DIAS; dia++) {
        printf("Dia %2d - Arrecadacao: R$ %.2f\n", dia + 1, arrecadacao[dia]);
    }
    //Saida de dados
    printf("\nTotal arrecadacao em %d dias: R$ %.2f\n", DIAS, totalGeral);

    int passouMais = 0;
    for (tipo = 1; tipo < TIPOS; tipo++) {
        if (somaTipos[tipo] > somaTipos[passouMais]) {
            passouMais = tipo;
        }
    }
    
    printf("O tipo de automovel que mais passou foi: %s (%d passagens)\n",
           nome[passouMais], somaTipos[passouMais]);

    return 0;
}