//Luiz Rodrigo Lacé Rodrigues, DRE: 118049873
//Ordenação Topologica através do algoritmo de Kahn

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//estrutura dos nós
typedef struct _tno{
    int chave;
    struct _tno *prox;
} tno;

//estrutura para o grafo
typedef struct grafo{
    int arestas;
    int vertices;
    tno **adjacencia;
}grafo;

grafo * initGrafo(int vertices){
    int arestas = vertices+1;
    grafo *graf = (grafo*) malloc (sizeof(grafo));

    if(graf == NULL){
        printf("ERRO - malloc");
        exit(1);
    }
    
    graf->vertices=vertices;
    graf->arestas= 0;
    graf->adjacencia = malloc((arestas)*sizeof(tno*));

    for(int i = 1; i<arestas; i++){
        graf->adjacencia[i] = NULL;
    }

    return graf;
}

//metodos para a fila
typedef struct fila{
    tno *inicio;
    tno *fim;
}fila;

fila* initFila(){
    fila* f = (fila*) malloc(sizeof(fila));
    f->inicio=NULL;
    f->fim= NULL;

    return f;
}

void pushFila(fila*f, int dado){
    tno *elem;
    elem = malloc(sizeof(tno));

    elem->chave =dado;
    elem->prox = NULL;

    if(f->inicio = NULL){
        f->inicio = elem;
    }
    else{
        f->fim->prox =elem;
    }

    f->fim =elem;
}

void printFila(fila *f){
    tno *aux;
    aux = f->inicio;
    while(aux!=NULL){
        printf("%d ", aux->chave);
        aux=aux->prox;
    }
}

void freeFila(fila*f){
    tno *aux;

    if(f->inicio!=NULL){
        aux=f->inicio;
        while(aux!=NULL){
            f->inicio=aux->prox;
            free(aux);
            aux=f->inicio;
        }
        free(f);
    }

}

//metodos para a pilha
typedef struct pilha{
    tno *topo;
} pilha;

pilha* initPilha(){
    pilha *p = (pilha*) malloc(sizeof(pilha));
    p->topo=NULL;
    return p;
}

void pushPilha(pilha *pi,int dado){
    tno* elem;
    elem = malloc(sizeof(tno));

    elem->chave= dado;
    elem->prox = pi->topo;
    pi->topo = elem;
}

int popPilha(pilha* pi){
    if(pi->topo==NULL){
        return -1;
    }

    int n = pi->topo->chave;
    tno * aux = pi->topo;
    pi->topo = pi->topo->prox;
    free(aux);

    return n;
}

void freePilha(pilha*pi){
    tno *aux;
    tno *aux2 = pi->topo;

    while(aux2!=NULL){
        aux=aux2;
        aux2 = aux2->prox;
        free(aux);
    }
    free(pi);
}



/*Ordenação Topologica, usando algoritmo de Khan, 
usando pilha para armazenar os vertices com grau de entrada 0, 
e fila para armazenar os vértices já ordenados para impressão*/
/*L - fila dos elementos ordenados
  S - pilha de vertices que com grau de entrada 0
  I - vetor dinamico com os graus de entrada
*/

void ordTopo (grafo *grafo){
    fila *L;
    L = initFila();
    pilha *S;
    S = initPilha();

    //calculando graus de entrada
    int n = grafo->vertices + 1;
    int *I;
    I= (int *) calloc(n,sizeof(int));

    for(int i=1; i<n; i++){
        tno *aux;
        for(aux = grafo->adjacencia[i]; aux!=NULL;aux=aux->prox){
            I[aux->chave]++;
        }
    }

    //inserindo graus de entrada 0 na pilha
    for(int i =1; i<n; i++){
        if(I[i]==0){
            pushPilha(S,i);
        }
    }

    while(S->topo!=NULL){
        int v = popPilha(S);
        pushFila(L,v);
        I[v]=-1;
        tno *aux;
        for(aux=grafo->adjacencia[v]; aux!=NULL; aux=aux->prox){
            //remover as arestas que partem de v
            I[aux->chave]--;
            grafo->arestas--;
            if(I[aux->chave]==0){
                pushPilha(S,aux->chave);
            }
        }
    }
    freePilha(S);
    free(I);

    if(grafo->arestas!=0){
        //grafo possui ciclo
        printf("Erro, o grafo é ciclico. Ainda há %d arestas",grafo->arestas);
    }
    else{
        printFila(L);
        freeFila(L);
    }
}

int main (void){
    int vertices, arestas;

    scanf("Digite o numero de vertices e arestas do grafo: %d %d", &vertices, &arestas);
    getchar();

    grafo *grafo;
    grafo = initGrafo(vertices);

    ordTopo(grafo);

    return 0;
}