#include <stdio.h>

int main() {
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18 && idade < 65) {
        printf("O voto é obrigatório.\n");
    } 
    else if (idade >= 65) {
        printf("O voto é facultativo.\n");
    } 
    else if (idade >= 16 && idade < 18) {
        printf("O voto é facultativo.\n");
    } 
    else {
        printf("Você não pode votar.\n");
    }

    return 0;
}