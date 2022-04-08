//Luiz Rodrigo Lacé Rodrigues - DRE:11804873

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int *vetor, int comeco, int meio, int fim) {
    int comeco1 = comeco, comeco2 = meio+1, comecoAux = 0, tamanhoVetor = (fim-comeco)+1;
    int *vetorAux;

    //alocando memoria pro vetor auxiliar
    vetorAux = (int*)malloc(tamanhoVetor * sizeof(int));

    //pegando cada vetor passado e percorrenco como se fossem 2 vetores, onde comeco1 seria o inicio de um e comeco2 o inicio de outro vetor.
    //colocando os valores no vetor auxiliar
    while(comeco1 <= meio && comeco2 <= fim){
        if(vetor[comeco1] < vetor[comeco2]) {
            vetorAux[comecoAux] = vetor[comeco1];
            comeco1++;
        } else {
            vetorAux[comecoAux] = vetor[comeco2];
            comeco2++;
        }
        comecoAux++;
    }

    //Verificando a existencia de elementos restantes nas metades criadas
    while(comeco1 <= meio){  
        vetorAux[comecoAux] = vetor[comeco1];
        comecoAux++;
        comeco1++;
    }

    while(comeco2 <= fim) {   
        vetorAux[comecoAux] = vetor[comeco2];
        comecoAux++;
        comeco2++;
    }

    //Move os elementos de volta para o vetor original

    for(int j=0,k=comeco;j<tamanhoVetor;j++,k++){
            vetor[k] = vetorAux[j];
    }    
    //liberando memoria alocada do vetor auxiliar
    free(vetorAux);
}

void mergeSort(int *vetor, int comeco, int fim){
    //checando se o mergesort consegue resolver
    if (comeco < fim) {
        //achando o meio do vetor (divisao inteira)
        int meio = (fim+comeco)/2;

        //chamando a função recursivamente
        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main (void){
    int*vetor;
    int contador = 0;
    int num;

    vetor = (int *) malloc (sizeof(int)*100000);
    if(vetor == NULL){
        fprintf(stderr,"ERRO - malloc");
        return 2;
    }

    while(scanf("%d", &num) != EOF){
        vetor[contador] = num;
        contador+=1;
    }
    //printf("contador: %d\n", contador);

    mergeSort(vetor,0,contador-1);

    for(int i=0;i<contador;i++){
        printf("%d\n",vetor[i]);
    }



    return 0;
}