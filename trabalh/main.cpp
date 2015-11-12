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
        Elem *aux = l->head;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = NULL;
        return 1;
    }
}

Lista* inverte(Lista* l){
    Lista *invertida = cria_lista();
    Elem *aux = l->head;
    while(aux != NULL){
        Elem *no = (Elem*)malloc(sizeof(Elem));
        if(invertida->head == NULL){
            no->letra = aux->letra;
            invertida->head = no;
            no->prox = NULL;
        }else{
            no->letra = aux->letra;
            no->prox = invertida->head;
            invertida->head = no;
        }

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

void libera(Lista *li){
    if(li != NULL){
        Elem *no;
        while(li != NULL){
            no = li->head;
            li->head = no->prox;
            free(no);
        }
        free(li);
    }
}

int main(){
    int testes,nos;
    scanf("%d",&testes);
        while(testes != 0){
            Lista *prefixa = cria_lista();
            Lista *infixa = cria_lista();
            Lista *posfixa = cria_lista();
            Elem *raiz;
            Elem *folha_dir;
            scanf("%d",&nos);
            char s1[nos],s2[nos];
            scanf("%s",&s1);
            scanf("%s",&s2);
            for(int i = 0; i<nos;i++){
                insere(prefixa,s1[i]);
                insere(infixa,s2[i]);
            }
            raiz = prefixa->head;
            folha_dir = busca(infixa,posfixa,raiz);
            galho_direito(infixa,posfixa,folha_dir);
            insere(posfixa,raiz->letra);
            exibe(posfixa);
            printf("\n");
            testes--;
        }
    return 0;
}
