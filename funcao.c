#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    if(inicio < fim){                 //verifica se inicio é menor que o fim
        meio = floor((inicio+fim)/2); //divide ao meio
        mergeSort(V,inicio,meio);      //CHAMA A FUNÇÃO PARA AS METADES
        mergeSort(V,meio+1,fim);       //CHAMA A FUNÇÃO PARA AS METADES
        merge(V,inicio,meio,fim); //JUNTA AS METADES DE FORMA ORDENADA
    }
}
