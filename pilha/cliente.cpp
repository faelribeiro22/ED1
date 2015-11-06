#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(){
    Pilha *p = Create();
    int x,y;
    x = Push(p,1);
    if(IsEmpty(p)){
        printf("Esta vazia");
    }
    x = Pop(p,&y);
    printf("%d\n",y);

    return 0;
}
