#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

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

Pilha* inverte(Pilha* p){
    Pilha *inv = criaPilha();
    char t;
    while(!isEmpty(p)){
        Pop(p,&t);
        Push(inv,t);
    }
    return inv;
}

int main(){
	Pilha *infixa = criaPilha();
	Pilha *posfixa = criaPilha();
	Pilha *aux = criaPilha();
	Pilha *operadores = criaPilha();
	char inf[MAX],letra,t;
	int testes,n,i,j;
	scanf("%d",&testes);
	while(testes != 0){
		j = 0;
		scanf("%s",&inf);
		n = strlen(inf);
		for(i=strlen(inf)-1;i>=0;i--){
			Push(infixa,inf[i]);
		}
		while(!isEmpty(infixa)){
			Pop(infixa,&letra);
			if(letra == '+' || letra == '-' || letra == '/' || letra == '*' || letra == '^' || letra == '('){
				if(!isEmpty(operadores)){
                    if(precedencia(Topo(operadores)) > precedencia(letra) || precedencia(Topo(operadores)) == precedencia(letra)){
                        if(letra != '('){
                            Pop(operadores,&t);
                            Push(posfixa,t);
                            Push(operadores,letra);
                        }
                    }else{
                        Push(operadores,letra);
                    }
				}else{
                    Push(operadores,letra);
				}
			}else if(letra != ')'){
                Push(posfixa,letra);
			}
			if(letra == ')'){
                Pop(operadores,&t);
				while(t != '('){
					Push(posfixa,t);
					Pop(operadores,&t);
				}
			}
		}
		if(!isEmpty(operadores)){
            while(!isEmpty(operadores)){
                Pop(operadores,&t);
                Push(posfixa,t);
            }
		}
		posfixa = inverte(posfixa);
		while(!isEmpty(posfixa)){
			Pop(posfixa,&letra);
			printf("%c",letra);
		}
		printf("\n");
		testes--;
	}

	return 0;
}
