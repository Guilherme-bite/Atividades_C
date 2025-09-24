#include <stdio.h>

int main() {
    char nome[50];
    float anterior;
    float atual;
    float variacao;

    for (int i = 0; i < 3; i++) {
        printf("\nDigite o nome do produto: ");
        scanf("%s", nome);

        printf("Digite o preco anterior: ");
        scanf("%f", &anterior);

        printf("Digite o preco atual: ");
        scanf("%f", &atual);

        variacao = ((atual - anterior) / anterior)*100;

        printf("\nResumo de variacao de precos:\n");
        printf("Produto: %s\n", nome);
        printf("Preco anterior: R$%.2f\n", anterior);
        printf("Preco atual: R$%.2f\n", atual);
        printf("Variacao: %.2f%%\n", variacao);

        if (variacao < 0) {
            printf("Situacao: Reducao de preco!.\n");
        } else if (variacao == 0) {
            printf("Situacao: Estavel!.\n");
        } else if (variacao > 0 && variacao <= 10) {
            printf("Situacao: Aumento de preco!.\n");
        } else {
            printf("Situacao: Preco abusivo!.\n");
        }
    }
    
    return 0;
}