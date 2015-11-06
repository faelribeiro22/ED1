#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha {
    int topo;
    elem A[TamPilha];
};

Pilha* Create(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p == NULL) exit(1);
    p->topo = -1;
    return p;
}

void Empty(Pilha* p){
    p->topo = -1;
}

int IsEmpty(Pilha* p){
    return (p->topo == -1);
}

int IsFull(Pilha* p){
    return (p->topo == TamPilha-1);
}

int Push(Pilha* p, elem x){
    if(!IsFull(p)){
        p->topo++;
        p->A[p->topo] = x;
        return 1;
    }
    return 0;
}

int Pop(Pilha* p, elem *x){
    if(!IsEmpty(p)){
        *x = p->A[p->topo];
        p->topo--;
        return 1;
    }
    return 0;
}
