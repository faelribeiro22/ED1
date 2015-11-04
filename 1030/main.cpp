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

int insere_vitima(Lista* l, int num){
    int i;
    Pessoa *p;
    for(i=1;i<=num;i++){
        Pessoa *vitima = (Pessoa*)malloc(sizeof(Pessoa));
        vitima->num = i;
        vitima->prox = NULL;
        l->qtd++;
        if(i != 1){
            l->head->prox = vitima;
            l->head = vitima;
        }else{
            l->head = vitima;
            p = l->head;
        }
        if(i == num){
            vitima->prox = p;
            l->head = p;
        }
    }
}

void busca(Lista* l, int x){
    Pessoa *vitima = l->head,*p;
    int cont;
    for(cont=1;cont<x;cont++){
        p = vitima;
        vitima = vitima->prox;
    }
    l->head = vitima->prox;
    l->qtd--;
    p->prox = vitima->prox;
    free(vitima);
}


int main(){
    int casos,k,n;
    scanf("%d",&casos);
    for(int i = 1; i <= casos; i++){
        Lista *l = cria_lista();
        scanf("%d",&n);
        insere_vitima(l,n);
        scanf("%d",&k);
        while(l->qtd != 1){
            busca(l,k);
        }
        printf("Case %d: %d\n",i,l->head->num);
        }
    return 0;
}
