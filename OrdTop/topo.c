#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct _tno{
    struct _tno * ant;
    int chave;
    struct _tno * prox;
} tno;

void imprime(tno *ptlista){
    if (ptlista != NULL){
        printf("%d\n",ptlista->chave);
    }
}

void push(tno *ptopo,int x){
    tno* novo;
    novo = (tno *) malloc(sizeof(tno));
    if (novo == NULL){
        printf("ERRO Malloc");
        return;
    }
    novo->chave = x;
    novo->prox = ptopo;
    ptopo = novo;
}

int main(void){

    tno *ptlista;
    
    push(ptlista,2);
    imprime(ptlista);


    return 0;
}