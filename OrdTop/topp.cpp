#include <stdio.h>
#include <stdlib.h>
#include <string>
#include<stdbool.h>
#include<iostream>


using namespace std;


//estrutura para os nós
typedef struct no{
    int valor;
    struct no *prox;
}no;

//estrutura para iniciar a lista
typedef struct listaEncad{
    struct no *inicio;
}listaEncad;

listaEncad * iniciaLista(){
    listaEncad * lista;

    lista = (listaEncad *) malloc (sizeof(listaEncad));
    if (lista==NULL){
        printf("ERRO - MALLOC");
        exit(1);
    }

    lista->inicio=NULL;
    return lista;
}

void insereNaLista(listaEncad*lista, int num){
    no* novo;
    novo = (no *) malloc (sizeof(no));

    novo->valor= num;
    novo->prox= NULL;

    //colocando na lista caso a lista esteja vazia
    if(lista->inicio==NULL){
        lista->inicio= novo;
    }
    //caso não esteja vazia, percorre a lista para colocar no final
    else{
        no * aux;
        aux = (no *) malloc (sizeof(no));
        aux = lista->inicio;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void imprimeLista(listaEncad * lista){
    no* aux;
    aux = (no *) malloc (sizeof(no));

    aux = lista->inicio;
    
    while(aux!=NULL){
        printf("%d ",aux->valor);
        aux = aux->prox;
    }
}

bool pertenceNaLista(listaEncad*lista,int num){
    no * aux;
    aux = (no *) malloc (sizeof(no));
    aux = lista->inicio;

    
    while(aux!=NULL){
        if(aux->valor == num){
            return(1);
        }
        aux =aux->prox;
    }
    return(0);

}

int main(void){
    int vertices, arestas;

    printf("Digite o numero de vertices e arestas: ");
    scanf("%d %d", &vertices,&arestas);

    //criando um vetor de adjacencias;
    listaEncad * adj[vertices+1];

    //inicializando cada lista em uma posição do vetor
    for(int i = 1; i<=vertices; i++){
        adj[i] = iniciaLista();
    }

    //inserindo valores em cada lista


  
    for (int j=1; j<=vertices;j++){
        string linha;
        getline(cin,linha);
        printf("%d",linha[0]);
        int pos = 0;
        int num = 0;
        while(pos<sizeof(linha)){
            int v;
            sscanf(&linha[pos],"%d %n",&v,&num);
            insereNaLista(adj[j],v);
            pos+=num;
        }        
    }

    // for (int j=1; j<=vertices;j++){
    //     string linha;
    //     getline(cin,linha);
    //     int pos = 0;
    //     while(linha[pos]!=EOF){
    //         int v;
    //         int num;
    //         sscanf(&linha[pos],"%d %n",&v,&num);
    //         insereNaLista(adj[j],v);
    //         pos+=num;
    //     }        
    // }

    printf("printando\n");

    //printa cada lista do vetor
    for(int i=1; i<=vertices;i++){
        imprimeLista(adj[i]);
        printf("\n");
    }

    //------------------------IMPLEMENTANDO A ORDENAÇÃO TOPOLOGICA-----------------------
    int ordem[vertices];
    int grauEntrada[vertices+1];

    
    //verificando os graus de entrada e adicionando no vetor grauEntrada
    for (int i=1;i<=vertices;i++){
        for(int j = 1; j<=vertices; j++){
            if(pertenceNaLista(adj[j],i)){
                grauEntrada[i]++;
            }
        }
    }

    //pegando o primeiro vertice com grau de entrada zero e colocando na ordem
    int pos = 0;
    for(int i=1; i<=vertices;i++){
        if(grauEntrada[i] == 0){
            ordem[pos] = i;
            pos++;
        }
    }

    //colocando os outros vertices em ordem
    int i=0;
    while(i<pos){
        for(int v=1; v<=vertices;v++){
            if(pertenceNaLista(adj[ordem[i]],v)){
                grauEntrada[v]--;
                if(grauEntrada[v]==0){
                    ordem[pos]=v;
                    pos++;
                }
            }
        }
    }

    //printando resultado na ordem
    for(int i = 1; i<=vertices; i++){
        printf("%d ",ordem[i]);
    }
    


    return 0;
}