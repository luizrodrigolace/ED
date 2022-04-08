void inserir(arvore* arvore, int valor){
   if(arvore-> raiz == NULL){
       tno * novo = (tno*) malloc(sizeof(tno)));
       novo->chave = valor;
       novo->esq = NULL;
       novo->dir = NULL;
       novo->soma = chave;
       return novo;
   }
   else{
       if(valor< raiz->chave){
           raiz->esq = inserir(raiz->esq, valor);
           raiz->soma += chave;
       }
       if(valor > raiz->chave){
           raiz->dir = inserir(raiz->dir, valor);
           raiz->soma += chave;
       }
       return raiz;
   }
}
