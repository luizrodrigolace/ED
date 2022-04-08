#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdbool.h>
#include <iostream>

using namespace std;


int main(void){
    int num;

    int numeros[3];

    string linha;

    getline(cin,linha);

    int pos = 0;
    int posNum =0;
    while(linha[pos] != EOF){
        sscanf(&linha[pos],"%d %n",&numeros[posNum],&num);
        pos+=num;
        posNum++;
    }
    

    for(int i=0;i<2;i++){
        printf("%d ", numeros[i]);   
    }




    return 0;
}