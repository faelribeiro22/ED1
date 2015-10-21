#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct fila {
    int inicio, fim, qtd;
    int x[MAX];
};

Fila* cria_fila(){
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->fim = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(Fila* fi){
    free(fi);
}

int tamanho(Fila* fi){
    if(fi == NULL)
        return -1;
    return fi->qtd;
}

int fila_cheia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int fila_vazia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->qtd == 0)
        return 1;
    else
        return 0;
}

int insere_fila(Fila* fi, int x){
    if(fi==NULL) return 0;
    if(fila_cheia(fi)) return 0;
    fi->x[fi->fim] = x;
    fi->fim = (fi->fim+1)%MAX;
    fi->qtd++;
    return 1;
}

int remove_fila(Fila* fi){
    if(fi == NULL || fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}

int consulta_fila(Fila* fi, int *x){
    if(fi == NULL || fila_vazia(fi))
        return 0;
    *x = fi->x[fi->inicio];
    return 1;
}

int verifica_ord(Fila* fi){
    int n,minimo,c=0,d,aux = 0,t=0;
    t = tamanho(fi);
    while(!fila_vazia(fi)){
        d = consulta_fila(fi,&n);
        if(c == 0){
            minimo = n;
            remove_fila(fi);
            c++;
            aux++;
        }else{
            if(minimo < n){
                minimo = n;
                remove_fila(fi);
                aux++;
            }else{
                break;
            }
        }
    }
    if(aux == t){
        printf("Esta ordenada!\n");
        return 1;
    }else{
        printf("nao esta ordenada!\n");
        return 0;
    }

}

Fila* inverte_fila(Fila* fi){
    int x,y;
    Fila *fi2 = cria_fila();
    while(!fila_vazia(fi)){
        y = consulta_fila(fi,&x);
        fi2->x[fi->qtd-1] = x;
        fi2->qtd++;
        remove_fila(fi);
    }
    fi2->inicio = 0;
    fi2->fim = fi2->qtd-1;
    return fi2;
}
