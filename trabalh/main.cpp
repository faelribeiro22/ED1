#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct elem{
    char letra;
    struct elem *prox;
};

typedef struct elem Elem;

struct lista{
    Elem *head;
};

typedef struct lista Lista;

Lista* cria_lista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->head = NULL;
    return l;
}

int insere(Lista* l, char letra){
    Elem *no = (Elem*)malloc(sizeof(Elem));
    no->letra = letra;
    if(l->head == NULL){
        l->head = no;
        no->prox = NULL;
        return 1;
    }else{
       no->letra = letra;
       no->prox = l->head;
       l->head = no;
       return 1;
    }
}

Lista* inverte(Lista* l){
    Lista *invertida = cria_lista();
    Elem *aux = l->head;
    while(aux != NULL){
        insere(invertida,aux->letra);
        aux = aux->prox;
    }
    return invertida;
}

Elem* busca(Lista *l1, Lista *l2, Elem *raiz){
    Elem *aux = l1->head;
    Elem *folha_dir;
    while(aux->letra != raiz->letra){
        insere(l2,aux->letra);
        aux = aux->prox;
    }
    folha_dir = aux->prox;
    insere(l2,folha_dir->letra);
    return folha_dir;
}

void galho_direito(Lista *l1, Lista* l2, Elem* folha_dir){
    Elem *aux;
    Lista *invertelis = cria_lista();
    invertelis = inverte(l1);
    aux = invertelis->head;
    while(aux->letra != folha_dir->letra){
        insere(l2,aux->letra);
        aux = aux->prox;
    }
}

void exibe(Lista *l){
    Elem *aux = l->head;
    while(aux != NULL){
        printf("%c",aux->letra);
        aux = aux->prox;
    }
}

int main(){
    int testes,nos,i;
    scanf("%d",&testes);
        while(testes != 0){
            Lista *prefixa = cria_lista();
            Lista *infixa = cria_lista();
            Lista *posfixa = cria_lista();
            Elem *raiz;
            Elem *folha_dir;
            scanf("%d",&nos);
            char s1[nos-1],s2[nos-1];
            scanf("%s",&s1);
            scanf("%s",&s2);
            if(strcmp(s1,s2) == 0){
                for(i = nos; i>=0;i--){
                insere(posfixa,s1[i]);
                }
                posfixa = inverte(posfixa);
            }else{
                for(i = nos; i>=0;i--){
                insere(prefixa,s1[i]);
                insere(infixa,s2[i]);
                }
                raiz = prefixa->head;
                folha_dir = busca(infixa,posfixa,raiz);
                galho_direito(infixa,posfixa,folha_dir);
                insere(posfixa,raiz->letra);
                posfixa = inverte(posfixa);
            }

            exibe(posfixa);
            printf("\n");
            testes--;
        }
    return 0;
}
