#include <stdio.h>
#include <stdlib.h>

struct pessoa{
	int num;
	struct pessoa *prox;
};
typedef struct pessoa Pessoa;

typedef struct
{
	int qtd;
	Pessoa *head;
}Lista;

Lista* cria_lista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->head = NULL;
    l->qtd = 0;
    return l;
}

int lista_vazia(Lista* l){
    return l->qtd == 0;
}

int insere_vitima(Lista* l, int num){
    Pessoa *vitima = (Pessoa*)malloc(sizeof(Pessoa));
    Pessoa *aux = l->head;
    if(lista_vazia(l)){
        l->qtd++;
        vitima->prox = vitima;
        vitima->num = num;
        l->head = vitima;
        return 1;
    }else{
        while(aux->prox != l->head){
            aux = aux->prox;
        }
        l->qtd++;
        vitima->num = num;
        vitima->prox = l->head;
        aux->prox = vitima;
        return 1;
    }
}

Pessoa* busca(Lista* l, int x){
    Pessoa *vitima = l->head;
    int cont;
    for(cont=1;cont<x;cont++){
        vitima = vitima->prox;
    }
    return vitima;
}

void mata_vitima(Lista* l, Pessoa* vitima){
    Pessoa* aux = l->head,*p;
    if(vitima == l->head){
        while(aux->prox != l->head){
            aux = aux->prox;
        }
        p = l->head;
        aux->prox = p->prox;
        l->head = aux->prox;
        free(p);
        l->qtd--;
    }else{
        while(aux != vitima){
        p = aux;
        aux = aux->prox;
        }
        p->prox = aux->prox;
        free(aux);
        l->head = p->prox;
        l->qtd--;
    }
}

int main(){
    Pessoa *vitima;
    int casos,k,n;
    scanf("%d",&casos);
    for(int i = 1; i <= casos; i++){
        Lista *l = cria_lista();
        scanf("%d",&n);
        for(int j = 1; j<=n; j++){
            insere_vitima(l,j);
        }
        scanf("%d",&k);
        while(l->qtd != 1){
            vitima = busca(l,k);
            mata_vitima(l,vitima);
        }
        printf("Case %d: %d\n",i,l->head->num);
    }
    return 0;
}
