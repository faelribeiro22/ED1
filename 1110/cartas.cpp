#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int elem;
typedef struct{
    int topo;
    elem cartas[MAX];
}Pilha;

Pilha* Create(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int IsEmpty(Pilha* p){
    return (p->topo == -1);
}

int IsFull(Pilha* p){
    return (p->topo == MAX-1);
}

void Empty(Pilha* p){
    p->topo = -1;
}

int push(Pilha* p,elem carta){
    if(!IsFull(p)){
        p->topo++;
        p->cartas[p->topo] = carta;
        return 1;
    }
    return 0;
}

int pop(Pilha *p, elem carta){
    if(!IsEmpty(p)){
        carta = p->cartas[p->topo];
        p->topo--;
        return carta;
    }
    return 0;
}

int fora(Pilha* p){
    elem cartinha;
    if(!IsEmpty(p)){
        cartinha = p->cartas[p->topo];
        p->cartas[p->topo] = p->cartas[p->topo-1];
        for(int i = p->topo-1; i>0;i--){
            p->cartas[i] = p->cartas[i-1];
        }
        p->cartas[0] = cartinha;
        return 1;
    }
    return 0;
}

int main(){
    int n,i;
    elem carta;
    Pilha *p = Create();
    scanf("%d",&n);
    while(n != 0){
        for(i=n;i>0;i--){
            push(p,i);
        }
        printf("Discarded cards:");
        while(p->topo != 0){
            carta = pop(p,carta);
            fora(p);
            if(p->topo == 0){
                printf(" %d",carta);
            }else
                printf(" %d,",carta);
        }
        printf("\nRemaining card: %d\n",p->cartas[p->topo]);
        Empty(p);
        scanf("%d",&n);
    }
    return 0;
}
