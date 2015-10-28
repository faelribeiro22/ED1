#include <stdio.h>
#include <stdlib.h>
#include "fila_d.h"

struct fila{
    int qtd;
    struct elemento *inicio;
    struct elemento *fim;
};

struct elemento{
    struct dados dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->qtd = 0;
        fi->inicio = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL) return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL) return 1;
    return fi->inicio == NULL;
}

int insere_Fila(Fila* fi, struct dados valores){
    if(fi == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    fi->qtd++;
    no->dado = valores;
    no->prox = NULL;
    if(Fila_vazia(fi)){
        fi->inicio = no;
    }else{
        fi->fim->prox = no;
    }
    fi->fim = no;
}

int remove_Fila(Fila* fi){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL) return 0;
    Elem *no = fi->inicio;
    fi->qtd--;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL) fi->fim = NULL;
    free(no);
    return 1;
}
