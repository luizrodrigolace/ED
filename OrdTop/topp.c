//Luiz Rodrigo Lacé Rodrigues - DRE:118049873 - Ordenação Topologica

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>

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

    //printf("Digite o numero de vertices e arestas: ");
    scanf("%d %d\n", &vertices,&arestas);

    //criando um vetor de adjacencias;
    listaEncad * adj[vertices+1];

    //inicializando cada lista em uma posição do vetor
    for(int i = 1; i<=vertices; i++){
        adj[i] = iniciaLista();
    }

    //inserindo valores em cada lista
    char *linha = NULL;
    size_t tamLinha = 0;
    //printf("Li vertices = %d e arestas = %d\n",vertices,arestas);
    for(int i = 1; i <= vertices; i++){
        getline(&linha,&tamLinha,stdin);
        int pos = 0;
        int numLido = 0;
        int numChars;
    
        while (sscanf(&linha[pos], " %d %n", &numLido, &numChars) > 0) {
            pos += numChars;
            insereNaLista(adj[i],numLido);
        }
    }
    // for (int j=1; j<=vertices;j++){
    //     for(int i=0; i<2; i++){
    //         int num;
    //         scanf("%d",&num);
    //         insereNaLista(adj[j],num);
    //     }
    // }

    //printf("printando\n");

    //printa cada lista do vetor
    // for(int i=1; i<=vertices;i++){
    //     imprimeLista(adj[i]);
    //     printf("\n");
    // }

    //------------------------IMPLEMENTANDO A ORDENAÇÃO TOPOLOGICA-----------------------
    int ordem[vertices];
    int grauEntrada[vertices+1];

    //inicianto todas as adjacencias com 0
    for(int i = 0;i<=vertices;i++){
        grauEntrada[i] = 0;
    }

    
    //verificando os graus de entrada e adicionando no vetor grauEntrada
    for (int i=1;i<=vertices;i++){
        for(int j = 1; j<=vertices; j++){
            if(pertenceNaLista(adj[j],i)){
                grauEntrada[i]++;
            }
        }
    }
    //printando o que temos no grau de entrada até então
    // for(int i = 1;i<=vertices;i++){
    //     printf("%d ",grauEntrada[i]);
    // }
    // printf("\n");

    //encontrando o primeiro vertice com grau de entrada 0 e colocando na ordem
    int pos = 0;
    for(int i=1; i<=vertices;i++){
        if(grauEntrada[i] == 0){
            ordem[pos] = i;
            pos++;
        }
    }
    //printando a ordem até então
    // for(int i =0; i<vertices; i++){
    //     printf("%d ", ordem[i]);
    // }

    /*percorrendo as listas de forma eficiente, com a ajuda de um ponteiro de nó, eu decremento
    os vertices que são apontados por cada vertice que já foi colocado no vetor ordem*/
    int i=0;
    no* aux;
    aux = (no *) malloc (sizeof(no));
    while(i<pos){
            aux = adj[ordem[i]]->inicio;
        while(aux!=NULL){
            grauEntrada[aux->valor]--;
            if(grauEntrada[aux->valor]==0){
                ordem[pos]=aux->valor;
                pos++;
            }
            aux = aux->prox;
        }
        i++;
    }

    free(aux);


    // percorrendo as listas de forma não eficiente
    // int i=0;
    // while(i<pos){
    //     for(int v=1; v<=vertices;v++){
    //         if(pertenceNaLista(adj[ordem[i]],v)){
    //             grauEntrada[v]--;
    //             if(grauEntrada[v]==0){
    //                 ordem[pos]=v;
    //                 pos++;
    //             }
    //         }
    //     }
    //     i++;
    // }

    for(int i=0;i<vertices;i++){
        if(i==0){
            printf("%d", ordem[i]);
        }
        else{
            printf(" %d",ordem[i]);
        }
    }
    printf("\n");


    return 0;
}