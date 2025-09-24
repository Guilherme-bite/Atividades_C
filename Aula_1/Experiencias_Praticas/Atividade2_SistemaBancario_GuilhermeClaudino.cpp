#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACOES 100 // Constante que ira armazenar o extrato

// Variáveis globais
float saldo = 0.0;
float extrato[MAX_TRANSACOES];
char tipo[MAX_TRANSACOES];
int quantidade_transacoes = 0;

int main() {
    int opcao;
    float valor;

    printf("=====================================\n");
    printf("   Bem-vindo ao K4Bank\n");
    printf("   Voce podera realizar:\n");
    printf("   - Depositos\n");
    printf("   - Saques\n");
    printf("   - Consultar Saldo\n");
    printf("   - Visualizar Extrato\n");
    printf("=====================================\n");

    while (1) {
        printf("\n========= MENU =========\n");
        printf("1 - Deposito\n");
        printf("2 - Saque\n");
        printf("3 - Saldo\n");
        printf("4 - Extrato\n");
        printf("0 - Sair\n");
        printf("Escolha uma das Opcoes: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Caractere Invalido!! Digite apenas numeros validos.\n");
            while (getchar() != '\n'); // limpa entrada
            continue;
        }

        switch (opcao) {
            case 1: // Deposito
                printf("Digite o valor para o deposito: ");
                if(scanf("%f", &valor) != 1 || valor <= 0) {
                    printf("Valor Invalido!! Informe um valor valido.\n");
                    while (getchar() != '\n');
                }else{
                    saldo += valor;
                    extrato[quantidade_transacoes] = valor;
                    tipo[quantidade_transacoes] = 'D';
                    quantidade_transacoes++;
                    printf("Deposito de R$ %.2f realizado com sucesso!!\n", valor);
                }
                break;

            case 2: // Saque
                printf("Digite o valor do saque: ");
                if(scanf("%f", &valor) != 1) {
                    printf("Valor Invalido!! Informe apenas numeros.\n");
                    while(getchar() != '\n');
                }else if(valor <= 0) {
                    printf("Valor Invalido!! Informe um valor valido.\n");
                }else if(valor > saldo) {
                    printf("Saldo Insuficiente!! Seu saldo atual e R$ %.2f\n", saldo);
                }else{
                    saldo -= valor;
                    extrato[quantidade_transacoes] = valor;
                    tipo[quantidade_transacoes] = 'S';
                    quantidade_transacoes++;
                    printf("Saque de R$ %.2f realizado com sucesso!!\n", valor);
                }
                break;

            case 3: // Saldo
                printf("Saldo Atual: R$ %.2f\n", saldo);
                break;

            case 4: // Extrato
                printf("\n===== EXTRATO ====\n");
                if(quantidade_transacoes == 0) {
                    printf("Nenhuma movimentacao realizada.\n");
                }else{
                    for(int i = 0; i < quantidade_transacoes; i++) {
                        if(tipo[i] == 'D')
                            printf("%d) Deposito: +R$ %.2f\n", i + 1, extrato[i]);
                        else
                            printf("%d) Saque: -R$ %.2f\n", i + 1, extrato[i]);
                    }
                }
                printf("Saldo atual: R$ %.2f\n", saldo);
                break;

            case 0: // Sair
                printf("\n=====================================\n");
                printf(" Obrigado por usar K4Bank! \n");
                printf(" Volte sempre. Encerrando...\n");
                printf("=====================================\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}