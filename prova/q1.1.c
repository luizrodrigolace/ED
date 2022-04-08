#include <stdio.h>
#include <stdlib.h>

typedef struct tno{
    int valor;
    struct tno *prox;
} tno;

void insere(tno **lista, int x){
    tno *aux;
    tno *novo;
    tno *anterior;

    //aloca memoria para o novo
    novo = (tno *) malloc(sizeof(tno));
    novo->valor = x;
    // faz o auxiliar ser igual a lista
    aux = *lista;
    anterior = NULL;

    //Caso a lista comece vazia o nosso valor inserido
    if(aux == NULL){
        novo->prox = NULL;
        *lista = novo;
    }
    // caso a lista já tenha elementos
    else{
        while(aux != NULL && aux->valor < x){
            anterior = aux;
            aux = aux->prox;
        }
        novo->prox = aux;

        if(anterior == NULL){
            *lista = novo;
        } 
        else{
            anterior->prox = novo;
        }
    }
}

void imprime(tno *p){
    while(p != NULL){
        printf("%d ", p->valor);
        p = p->prox;
    }
}

tno * soma ( tno * ptraiz){
    if(ptraiz == NULL){
        return 0
    }

    ptraiz-> soma = (raiz-> chave + soma(ptraiz -> esq) + soma(ptraiz->dir));

    return ptraiz->chave;
}

int main(void){
    tno *listaSemCabeca = NULL;
    
    int num;
    while(scanf("%d",&num) == 1){
        insere(&listaSemCabeca,num);
    }
    
    imprime(listaSemCabeca);
    return 0;
}