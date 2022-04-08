//Luiz Rodrigo Lacé Rodrigues
// DRE: 118049873
// Arvore AVL

#include <stdio.h>
#include <stdlib.h>

//Estrutura para representar a arvore
typedef struct tno{
    int valor; 
    int nivel;
    struct tno *esquerda; 
    struct tno *direita; 
}tno;

tno *criaNo (int valorInserido){
    //alocando memoria
    tno *novo = (tno*) malloc(sizeof(tno));
    if (novo == NULL){
        printf ("ERRO MALLOC");
        exit(1);
    }

    novo->valor = valorInserido;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->nivel = 1;

    return novo;
}

int getNumeroMaximo(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int getNivel(tno * no){
    //caso a arvore estiver vazia
    if(no == NULL){
        return 0;
    }

    //caso não esteja vazia, retorna o nivel do nó passado
    return no->nivel;
}

int getFatorBalanceamento(tno *no){
    //caso a arvore esteja vazia
    if (no == NULL){
        return 0;
    }

    //Encontramos o equilibrio da arvore fazendo a diferença dos niveis
    // da sub-arvore da esquerda  e da sub-arvore da direita
    return getNivel(no->esquerda) - getNivel(no->direita);
}

int atualizaNivel(tno * no){
    return getNumeroMaximo(getNivel(no->esquerda),getNivel(no->direita)) + 1;
}

tno *rotacaoEsquerdaSimples(tno *subarv){
    tno *aux = subarv->direita; 
    subarv->direita = aux->esquerda;
    aux->esquerda = subarv;

    //atualiza os niveis
    subarv->nivel = atualizaNivel(subarv);
    aux->nivel = atualizaNivel(aux);

    //retorna a nova raiz
    return aux;
}

tno *rotacaoDireitaSimples (tno *subarv){
    tno *aux = subarv->esquerda; 
    subarv->esquerda = aux->direita;
    aux->direita = subarv;

    // atualiza o niveis 
    subarv->nivel = atualizaNivel(subarv);
    aux->nivel = atualizaNivel(aux);

    //retorna nova raiz
    return aux;
}

tno *rotacaoDireitaDupla(tno *y){
    y->direita = rotacaoEsquerdaSimples(y->esquerda);
    return rotacaoDireitaSimples(y);
}

tno *rotacaoEsquerdaDupla(tno*x){
    x->direita = rotacaoDireitaSimples(x->direita);
    return rotacaoEsquerdaSimples(x);
}



tno *insereNaArvore(tno *no, int valor){
    //caso a arvore esteja vazia, insere nó sem restrição
    if (no == NULL){
        return(criaNo(valor));
    }

    // insere novos nós na arvore
    if(valor< no->valor){
        no->esquerda = insereNaArvore(no->esquerda, valor);
    }
    else if (valor > no->valor){
        no->direita = insereNaArvore(no->direita,valor);
    }
    else{
        return no;
    }

    //atualizacao do nivel
    no->nivel = atualizaNivel(no);

    int balanco = getFatorBalanceamento(no);

    if( balanco <-1){
        if(valor > no->direita->valor){
            return rotacaoEsquerdaSimples(no);
        }
        else if(valor < no -> direita -> valor){
            return rotacaoEsquerdaDupla(no);
        }
    }

    if (balanco > 1){
        if(valor < no->esquerda->valor){
            return rotacaoDireitaSimples(no);
        }
        else if (valor > no->esquerda->valor){
            return rotacaoDireitaDupla(no);
        }
    }



    return no;

}

//imprimindo a arvore em pre ordem com o seu nivel (altura) do lado
void imprimeArvore(tno *raiz){
    if (raiz != NULL){
        printf("%d(%d) ", raiz->valor, raiz->nivel);
        imprimeArvore(raiz->esquerda);
        imprimeArvore(raiz->direita);
    }
}

int main (int argc, char *argv[]){
    tno *raiz = NULL;
    int criaNovoNo;
    char le;
    
    // loop que le os numeros de entrada
    while (scanf("%c", &le)==1){
        //inserindo na arvore os valores novos
        //scanf("%c", &le);
        if (le == 'p'){
            imprimeArvore(raiz);
            printf("\n");
        }
        scanf("%d", &criaNovoNo);
        if (le == 'i'){
            raiz = insereNaArvore(raiz,criaNovoNo);
        }
    }


    //imprimindo a arvore em pre ordem
    //imprimeArvore(raiz);

    return 0;
}