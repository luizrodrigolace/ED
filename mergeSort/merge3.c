#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int *vetor, int inicio, int meio, int fim) {
    //criando um array para o segurar o array mergeado
    int aux [fim - inicio];

    int p = inicio;
    int q =

}

void mergeSort(int *vetor, int inicio, int fim){
    //checando se o mergesort consegue resolver

    if (inicio==fim) {
        return;
    }
    //achando o meio do vetor (divisao inteira)
    int meio = (fim+inicio)/2;

    //chamando a função recursivamente
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio+1, fim);
    //combinando as metades de forma ordenada
    merge(vetor, inicio, meio, fim);
}


int main (void){
    int*vetor;
    int contador = 1;
    int num;

    vetor = (int *) malloc (sizeof(int)*100000);
    if(vetor == NULL){
        fprintf(stderr,"ERRO - malloc");
        return 2;
    }


    while(scanf("%d", &num) != EOF){
        vetor[contador-1] = num;
        contador+=1;
    }
    

    for(int i=0;i<contador;i++){
        printf("%d ",vetor[i]);
    }

    printf("\n");

    mergeSort(vetor,0,contador);

    for(int i=0;i<contador;i++){
        printf("%d ",vetor[i]);
    }

    printf("\n");



    return 0;
}