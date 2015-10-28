#include <stdio.h>
#include <stdlib.h>
#include "fila_d.h"

int main(){
    Fila *fi;
    struct dados valores;
    valores.x = 5;
    int x;
    fi = cria_Fila();
    x = tamanho_Fila(fi);
    //testando criação da fila e verificação se fila esta vazia
    printf("Tamanho da fila eh %d\n",x);
    if(Fila_vazia(fi)){
        printf("Fila esta vazia!\n");
    }else{
        printf("fila nao esta vazia!\n");
    }
    //inserção
    x = insere_Fila(fi, valores);
    x = tamanho_Fila(fi);
    printf("Tamanho da fila eh %d\n",x);
    if(Fila_vazia(fi)){
        printf("Fila esta vazia!\n");
    }else{
        printf("fila nao esta vazia!\n");
    }

    x = remove_Fila(fi);
    x = tamanho_Fila(fi);
    printf("Tamanho da fila eh %d\n",x);
    if(Fila_vazia(fi)){
        printf("Fila esta vazia!\n");
    }else{
        printf("fila nao esta vazia!\n");
    }

    return 0;
}
