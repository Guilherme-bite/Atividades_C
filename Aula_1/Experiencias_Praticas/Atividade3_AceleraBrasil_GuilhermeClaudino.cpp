#include <stdio.h>
#include <stdlib.h>

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

    printf("=== BEM VINDO AO ACELERA BRASIL ===\n");
    for (dia = 0; dia < DIAS; dia++) {
        printf("\nDia %d:\n", dia + 1);
        arrecadacao[dia] = 0;
        for (tipo = 0; tipo < TIPOS; tipo++) {
            if (tipo == 0) printf("Quantos CAMINHOES passaram: ");
            else if (tipo == 1) printf("Quantos ONIBUS passaram: ");
            else if (tipo == 2) printf("Quantos CARROS passaram: ");
            else if (tipo == 3) printf("Quantas MOTOS passaram: ");

            scanf("%d", &veiculos[dia][tipo]);
            // Calcula a arrecadacao
            arrecadacao[dia] += veiculos[dia][tipo] * tarifa[tipo];
            somaTipos[tipo] += veiculos[dia][tipo];
        }
        totalGeral += arrecadacao[dia];
    }
    // Entrada de dados
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
    // Qual veiculo passou mais pelo pedagio
    char *nome[4] = {"Caminhao","Onibus","Carro","Moto"};
    printf("O tipo de automovel que mais passou foi: %s (%d passagens)\n",
           nome[passouMais], somaTipos[passouMais]);

    return 0;
}