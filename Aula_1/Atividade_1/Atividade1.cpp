#include <stdio.h>

int main(){

    char nome[30];
    int idade;

    printf("Digite seu nome: "); // escrever
    scanf("%s", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Ola, %s você tem %d anos.\n", nome, idade);

    return 0;
}
