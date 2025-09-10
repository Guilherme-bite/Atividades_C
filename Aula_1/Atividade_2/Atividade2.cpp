#include <stdio.h>

int main(){

    int num;

    printf("DIgite um numero: ");
    scanf("%d", &num);

    if(num % 2 == 0){
        printf("O numero %d e par.", num);
    }
    else{
        printf("O numero %d e impar.", num);
    }

    return 0;
}