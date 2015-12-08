#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

struct pilha{
    int topo;
    char expre[MAX];
};
typedef struct pilha Pilha;

Pilha* criaPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int isEmpty(Pilha* p){
    return (p->topo == -1);
}

int Empty(Pilha* p){
    p->topo = -1;
    return 1;
}

int isFull(Pilha *p){
    return (p->topo == MAX-1);
}

int Push(Pilha* p, char letra){
    if(!isFull(p)){
        p->topo++;
        p->expre[p->topo] = letra;
        return 1;
    }
    return 0;
}

int Pop(Pilha* p, char* letra){
    if(!isEmpty(p)){
        *letra = p->expre[p->topo];
        p->topo--;
        return 1;
    }
    return 0;
}

char Topo(Pilha *p){
    return (p->expre[p->topo]);
}

int precedencia(char letra){
    switch(letra){
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
}

Pilha* desempilha(Pilha* p, Pilha* o)
{
        char t;
        Pop(o,&t);
        if(t == '('){
            return p;
        }else{
            Push(p,t);
            return (desempilha(p,o));
        }
}

Pilha* desempilha_op(Pilha* p, Pilha* o)
{
        char t;
        if(isEmpty(o)){
            free(o);
            return p;
        }else{
            Pop(o,&t);
            Push(p,t);
            return (desempilha_op(p,o));
        }
}

void exibe(Pilha* p){
    char letra;
    Pilha *inv = criaPilha();
    while(!isEmpty(p)){
        Pop(p,&letra);
        Push(inv,letra);
    }
    while(!isEmpty(inv)){
        Pop(inv,&letra);
        printf("%c",letra);
    }
    printf("\n");
}

int main(){
    Pilha *posfixa = criaPilha();
    Pilha *operadores = criaPilha();
    Pilha *infixa = criaPilha();
    char inf[MAX],letra,t;
    int testes,n,i,j,f=0;
    scanf("%d",&testes);
    while(testes > 0){
        testes--;
        scanf("%s",&inf);
        n = strlen(inf);
        for(i = n-1;i>=0;i--){
            Push(infixa,inf[i]);
        }
        while(!isEmpty(infixa))
        {
            Pop(infixa,&letra);
            if(letra != '+' && letra != '-' && letra != '*' && letra != '/' && letra != '^' && letra != '(' && letra != ')'){
                Push(posfixa,letra);
            }else if(letra == '('){
                Push(operadores,letra);
            }else if(letra == ')'){
                desempilha(posfixa,operadores);
            }else{
                while(precedencia(Topo(operadores)) > precedencia(letra) || precedencia(Topo(operadores)) == precedencia(letra)){
                    Pop(operadores,&t);
                    Push(posfixa,t);
                }
                Push(operadores,letra);
            }
        }
            if(!isEmpty(operadores))
            {
                desempilha_op(posfixa,operadores);
            }
        exibe(posfixa);
        Empty(posfixa);
        Empty(operadores);
    };

    return 0;
}
