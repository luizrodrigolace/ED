#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

  char *linha = NULL;
  size_t tamLinha = 0;
  int vertices, arestas;
  scanf("%d %d\n", &vertices, &arestas);

  printf("Li vertices = %d e arestas = %d\n",vertices,arestas);
  for(int i = 1; i <= vertices; i++){

    getline(&linha,&tamLinha,stdin);
    int pos = 0;
    int numLido = 0;
    int numChars;
    
    while (sscanf(&linha[pos], " %d %n", &numLido, &numChars) > 0) {
      pos += numChars;
      if(strlen(linha) != 0){
	  printf(" insere em adj [ %d ] o vertice %d\n",i, numLido);      
      }
    }
  }
  
  
}