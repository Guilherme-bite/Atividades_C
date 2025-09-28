#include <stdio.h>
#include <string.h>

#define TAM 10 // numero de produtos

// funcao para exibir os produtos com preço
void MostrarProdutos(char produtos[][20], float precos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%-12s -> R$ %.2f\n", produtos[i], precos[i]);
    }
    printf("\n");
}

// funcao Bubble Sort que ordena os preços e mantém os nomes juntos
void BubbleSort(char produtos[][20], float precos[], int n, int ordem) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int troca = 0;

            // ordem crescente
            if (ordem == 1 && precos[j] > precos[j + 1]) {
                troca = 1;
            }
            // ordem decrescente
            if (ordem == 0 && precos[j] < precos[j + 1]) {
                troca = 1;
            }

            if (troca) {
                // troca os preços
                float tempPreco = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = tempPreco;

                // troca os nomes dos produtos
                char tempNome[20];
                strcpy(tempNome, produtos[j]);
                strcpy(produtos[j], produtos[j + 1]);
                strcpy(produtos[j + 1], tempNome);
            }
        }
    }
}

int main() {
    // produtos fixos
    char produtos[TAM][20] = {
        "Arroz", "Feijao", "Batata", "Macarrao", "Acucar",
        "Leite", "Cafe", "Bolacha", "Salgadinho", "Biscoito"
    };

    float precos[TAM];

    // entrada de dados
    printf("Digite os precos dos produtos:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%s: R$ ", produtos[i]);
        scanf("%f", &precos[i]);
    }

    // exibe a tabela original
    printf("\nLista Original:\n");
    MostrarProdutos(produtos, precos, TAM);

    // em ordem crescente
    BubbleSort(produtos, precos, TAM, 1);
    printf("Lista em ordem crescente:\n");
    MostrarProdutos(produtos, precos, TAM);

    // em ordem decrescente
    BubbleSort(produtos, precos, TAM, 0);
    printf("Lista em ordem decrescente:\n");
    MostrarProdutos(produtos, precos, TAM);

    return 0;
}