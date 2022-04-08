#include <stdio.h>
#include <stdlib.h>

typedef struct tno{
    int valor;
    struct tno* prox;
}tno;

void insere(tno*lista, int x){
    tno * novo;
    novo = (tno*) malloc (sizeof(tno*));

    //inicializando o nó novo
    novo->prox = NULL;  
    novo->valor = x;

    //criando um auxiliar
    tno * aux;
    aux = lista;

    //caso seja o primeiro valor inserido da lista, vira o primeiro valor da lista
    if(lista == NULL){
        novo->prox = NULL;
        lista = novo;
    }
    
    // caso seja menor
    else if(x < lista->valor){
        novo->prox = lista;
        lista = novo;
    }

    else{
        while(aux->prox != NULL && x > aux->prox->valor){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

void imprimeLista(tno * lista){
    while(lista != NULL){
        printf("%d ",lista->valor);
        lista = lista->prox;
    }

}


int main (void){
    tno * listaSemCabeca;
    
    listaSemCabeca = NULL;
        
    int num;
    while(scanf("%d",&num) == 1){
        insere(listaSemCabeca,num);
    }

    imprimeLista(listaSemCabeca);

    //printf("\n");

}

