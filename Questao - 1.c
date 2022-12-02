#include <stdio.h>
#include <stdlib.h>

void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2])
                    temp[i]=V[p1++];    
                else	               // ====> COMBINAR ORDENANDO
                    temp[i]=V[p2++];

                if(p1>meio) fim1=1;    // ====> VERIFICA SE O VETOR ACABOU
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i]=V[p1++];
                else                   // ====> COPIA O QUE SOBRAR
                    temp[i]=V[p2++];
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
            V[k]=temp[j];                       //COPIA E COLA DO VETOR AUXILIAR PARA O ORIGINAL
    }
    free(temp);
}

void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V,inicio,meio);      //CHAMA A FUNÇÃO PARA AS METADES
        mergeSort(V,meio+1,fim);       //CHAMA A FUNÇÃO PARA AS METADES
        merge(V,inicio,meio,fim); //JUNTA AS METADES DE FORMA ORDENADA
    }
}

int main(){
    int i;     // 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
    int vet[15] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
    int N = 15;


    printf("\nSem ordenar:\n");
    for(i=0; i<N; i++){
        printf("%d ",vet[i]);
    }

    mergeSort(vet,0,N);
    printf("\nOrdenado:\n");
    for(i=0; i<N; i++){
        printf("%d ",vet[i]);
    }
    
    printf("\n");

    system("pause");
    return 0;
}
