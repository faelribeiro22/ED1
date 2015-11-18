#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int numero;
    int nota;
    struct aluno *prox;
};

typedef struct aluno Aluno;

struct fila{
    int qtd;
    struct aluno *head;
};

typedef struct fila Fila;

Fila* criaFila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if(f == NULL)
        exit(1);
    f->qtd = 0;
    f->head = NULL;
    return f;
}

int insere(Fila* l, int num, int nota){
    Aluno* p = (Aluno*)malloc(sizeof(Aluno));
    p->numero = num;
    p->nota = nota;
    if(l->qtd == 0){
        l->head = p;
        p->prox = NULL;
        l->qtd++;
    }else{
        p->prox = l->head;
        l->head = p;
        l->qtd++;
    }
    return 1;
}

void exibe(Fila *f){
    Aluno *aux = f->head;
    while(aux != NULL){
        printf("Aluno: %d Nota: %d\n",aux->numero,aux->nota);
        aux = aux->prox;
    }
}

int main(){
    Fila* f = criaFila();
    int testes,alunos,notas;
    scanf("%d",&testes);
    while(testes != 0){
        scanf("%d",&alunos);
        for(int i = 0; i<alunos; i++){
            scanf("%d",&notas);
            insere(f,i+1,notas);
        }
        exibe(f);
        testes--;
    }
    return 0;
}
