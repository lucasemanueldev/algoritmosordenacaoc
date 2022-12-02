#include <stdio.h>
#include <stdlib.h>
#define TAM 8
int main(){
    int vet[TAM];
    int i, cont, aux;

    i = 0;
    for(i = 0; i < TAM; i++){
        printf("Digite o %d numero inteiro(8X): \n", i+1);
        scanf("%d", &vet[i]);
        system("cls");
    }
    printf("Numeros Fora de Ordem\n");
    for(i = 0; i < TAM; i++){
        printf("%4d",vet[i]);
	}
    //Algoritmo de Ordenação  - BUBBLESORT
    for(cont = 1; cont < TAM; cont++){
    for(i = 0; i < TAM - 1; i++){
        if (vet [i] > vet [i + 1]){
            aux = vet [i];
            vet [i] = vet [i + 1];
            vet [i + 1] = aux;
        }
    }
    }
    printf("\nNumeros em Ordem Crescente\n");
    for(i = 0; i < TAM; i++){
        printf("%4d",vet[i]);
    }
}
