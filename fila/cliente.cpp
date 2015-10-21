#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    Fila *fi;
    int z;
    fi = cria_fila();
    int x = insere_fila(fi,2);
    x = insere_fila(fi,3);
    x = insere_fila(fi,4);
    x = insere_fila(fi,5);
    int y = consulta_fila(fi,&z);
    //x = remove_fila(fi);
    fi = inverte_fila(fi);
    /*
    printf("Primeiro valor %d\n",z);
    printf("Tamanho da fila %d",tamanho(fi));
    if(fila_cheia(fi) == 1){
        printf("Esta cheia");
    }else{
        printf("Nao esta cheia!");
    }*/

    //x = verifica_ord(fi);
    return 0;
}
