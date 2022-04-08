#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//estrutura para criar o vetor de listas encadeadas
typedef struct tno{
    int valor;
    struct tno *prox;
}tno;

typedef struct lista{
    struct tno *inicio;
}lista;

lista * iniciaLista(){
    lista* list;

    list = (lista *) malloc (sizeof(lista));
    
    if(list == NULL){
        printf("ERRO - malloc");
        exit(1);
    }

    list->inicio= NULL;

    return list;
}

void insereNaLista(lista* lista, int valor ){
    tno * aux;

    aux = malloc (sizeof(struct tno));
    aux->valor = valor;
    aux->prox = NULL;

    //se for o primeiro a entrar na lista
    if(lista->inicio == NULL){
        lista->inicio = aux;
    }
    else{
        //percorrendo até o final da lista para adicionar o novo
        tno * atual = lista->inicio;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = aux;
    }
}

void imprimeLista(lista *lista){

    tno * aux;
    aux = (tno *) malloc (sizeof(tno));

    aux = lista->inicio;

    while(aux->prox!=NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

int main(void){
    int vertices,arestas;
    
    printf("Digite o numero de vertices e arestas:");
    scanf("%d %d",&vertices,&arestas);

    lista * vetor[vertices+1];

    //inicializando um vetor de listas encadeadas
    for(int i = 1; i<vertices+1;i++){
        vetor[i] = iniciaLista();
    }

    //inserindo adjacencias 
    for(int i = 1;i<vertices+1;i++){
        int adj;
        scanf("%d", &adj);
        if(adj == '\n'){
            continue;
        }
        insereNaLista(vetor[i],adj);
    }

    for(int i = 1; i<vertices+1;i++){
        imprimeLista(vetor[i]);
    }
    
    return 0;
}