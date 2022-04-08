//Luiz Rodrigo Lacé Rodrigues - DRE: 118049873
// Merge Sort

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1,p2, tamanho, i,j,k;
    int fim1 =0, fim2=0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio +1;

    temp = (int *) malloc(tamanho * sizeof(int));
    
    if (temp != NULL){
        for(i =0;i<tamanho;i++){
            if(!fim1 && !fim2){
                //combinar ordenadamente
                if(V[p1] < V[p2]){
                    temp[i] =V[p1++];
                }
                else{
                    temp [i] = V[p2++];
                }
                //verificando se o vetor acabou
                if(p1>meio){
                    fim1=1;
                }
                if(p2>fim){
                    fim2=1;
                }
            }
            else{
                //copia o que sobra
                if(!fim1){
                    temp[i] =V[p1++];
                }
                else{
                    temp[i] = V[p2++];
                }
            }
            for(j=0,k=inicio;j<tamanho;j++,k++){
                V[k] = temp[j];
            }
        }
        //free(temp);
    }
}

void mergesort(int * V, int inicio,int fim){
    int meio;
    //checando se o mergesort consegue resolver
    if(fim - inicio>1){
        meio = /*floor*/((fim + inicio)/2); //divisão inteira
        //passando recursivamente
        mergesort(V, inicio, meio);
        mergesort(V, meio+1, fim);
        //combina as 2 metades de forma ordenada
        merge(V,inicio,meio,fim);
    }
}

int main (void){
    int*vetor;
    int contador = 0;
    int num;

    vetor = (int *) malloc (sizeof(int));
    if(vetor == NULL){
        fprintf(stderr,"ERRO - malloc");
        return 2;
    }

    while(1){
        scanf("%d", &num);
        getchar();
        if(num == 0){
            break;
        }
        vetor[contador] = num;
        contador+=1;
    }

    for(int i=0;i<contador;i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");

    mergesort(vetor,0,contador);

    
    for(int i=0;i<contador;i++){
        printf("%d ",vetor[i]);
    }

    printf("\n");



    return 0;
}