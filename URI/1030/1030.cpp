#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

struct pessoa{
	int num;
	struct pessoa *prox,*ant;
};
typedef struct pessoa Pessoa;
typedef struct 
{
	int qtd;
	Pessoa *head;
}Lista;

Lista* cria_lista(){
	Lista *l;
	l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL) exit(1);
	l->head = NULL;
	l->qtd = 0;
}

int lista_vazia(Lista* l){
	return l->qtd == 0;
}

int insere_lista(Lista* l, int x){
	Pessoa *prisioneiro = (Pessoa*)malloc(sizeof(Pessoa));
	if(lista_vazia(l)){
		l->head = prisioneiro;
		l->qtd++;
		prisioneiro->ant = NULL;
		prisioneiro->prox = prisioneiro;
		prisioneiro->num = x;
		return 1;
	}else
	{
		l->qtd++;
		prisioneiro->prox = l->head;
		l->head->ant = prisioneiro;
		l->head = prisioneiro;
		prisioneiro->num = x;
		return 1;
	}
}

int main(){
	Lista *l;
	int x;
	l = cria_lista();
	if(lista_vazia(l)){
		printf("lista esta vazia\n");
	}
	x = insere_lista(l,1);
	x = insere_lista(l,2);
	printf("A lista tem %d elementos\n",l->qtd);
	return 0;
}