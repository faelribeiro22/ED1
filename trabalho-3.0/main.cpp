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
    Lista *l = (Lista*)malloc(sizeof(Lista));
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
//insere elementos de uma lista em outra
void envia(Lista* aux,Lista* posfixa){
    int i = aux->topo-1;
    for(;i>=0;i--){
        insere(posfixa,aux->letras[i]);
    }
}

//função responsvel na construção da posfixa
Lista* monta_pos(Lista* prefixa, Lista* infixa, char raiz){
    Lista* posfixa = cria_lista();
    Lista* aux = cria_lista();
    int c = 0;
    //percorre toda a lista
    for(int i=0;i<prefixa->topo;i++){
        //compara se um caracter é maior que o outro(código ASCII)
        if(infixa->letras[i]>prefixa->letras[i] || i == 0){
            //esse if impede que a raiz da árvore seja inserida no ínico da posfixa
            if(infixa->letras[i] != raiz){
                insere(posfixa,infixa->letras[i]);
            }
            //se não for maior e não for a riz, ira inserir em uma lista auxiliar
        }else if(infixa->letras[i] != raiz){
            c++;
            insere(aux,infixa->letras[i]);
        }
        //quando chegar no caracter raiz na infixa, teremos os galhos a esquerda, com isso grava todos os valores que foram salvos na lista auxiliar
        if(infixa->letras[i] == raiz){
            envia(aux,posfixa);
            libera(aux);
        }
    }
    //apos sair do for teremos os galhos a direita, com isso grava os elementos que foram salvo na lista auxiliar
    if(c != 0){
        envia(aux,posfixa);
    }
    insere(posfixa,raiz);
    return posfixa;
}

int main(){
    int testes,nos,i;
    Lista *prefixa;
    Lista *infixa;
    scanf("%d",&testes);
    while(testes != 0){
        prefixa = cria_lista();
        infixa = cria_lista();
        char s1[MAX],s2[MAX],raiz;
        scanf("%d %s %s",&nos,&s1,&s2);
        Lista *posfixa;
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
