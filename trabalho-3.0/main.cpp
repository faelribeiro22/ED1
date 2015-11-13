#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 52

struct lista{
    int topo;
    char letras[MAX];
};

typedef struct lista Lista;

//cria lista estatica, com uma string tamanho 52
Lista* cria_lista(){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->topo = 0;
    return l;
}

//insere um elemento na lista
int insere(Lista* l, char letra){
    l->letras[l->topo] = letra;
    l->topo++;
    return 1;
}

//esvazia a lista logicamente
void libera(Lista* l){
    l->topo = 0;
    free(l);
}

//exibe os elementos da lista
void exibe(Lista* l){
    int i;
    for(i=0;i<l->topo;i++){
        printf("%c",l->letras[i]);
    }
    printf("\n");
}

//função para retornar o topo da lista
char retorna(Lista* l){
    return l->letras[0];
}

void envia(Lista* aux,Lista* posfixa){
    int i = aux->topo-1;
    for(;i>=0;i--){
        insere(posfixa,aux->letras[i]);
    }
}

Lista* monta_pos(Lista* prefixa, Lista* infixa, char raiz){
    Lista* posfixa = cria_lista();
    Lista* aux = cria_lista();
    int c = 0;
    for(int i=0;i<prefixa->topo;i++){
        if(infixa->letras[i]>prefixa->letras[i]){
            insere(posfixa,infixa->letras[i]);
        }else if(infixa->letras[i] != raiz){
            insere(aux,infixa->letras[i]);
        }
        if(infixa->letras[i] == raiz){
            envia(aux,posfixa);
            libera(aux);
        }
    }
    envia(aux,posfixa);
    insere(posfixa,raiz);
    return posfixa;
}

int main(){
    Lista *prefixa = cria_lista();
    Lista *infixa = cria_lista();

    int testes,nos,i;
    char s1[MAX],s2[MAX],raiz;
    scanf("%d",&testes);
    while(testes != 0){
        Lista *posfixa;
        scanf("%d %s %s",&nos,&s1,&s2);
        for(i=0;i<nos;i++){
            insere(prefixa,s1[i]);
            insere(infixa,s2[i]);
        }
        raiz = retorna(prefixa);
        posfixa = monta_pos(prefixa,infixa,raiz);
        exibe(posfixa);
        libera(posfixa);
        testes--;
    }
}
