#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

struct aluno{
    int numero;
    int nota;
};
typedef struct aluno Aluno;

struct fila{
    int inicio, fim,total;
    Aluno alunos[MAX];
};
typedef struct fila Fila;

Fila* criaFila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    return f;
}

void esvaziaFila(Fila* f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    return;
}

int IsEmpty(Fila* f){
    return(f->total == 0);
}

int IsFull(Fila* f){
    return(f->total == MAX-1);
}

int entraFila(Fila *f,Aluno* p){
    if(!IsFull(f)){
        f->total++;
        f->alunos[f->fim] = *p;
        f->fim = (f->fim+1)%MAX;
        return 1;
    }
    return 0;
}

Fila* copiaFila(Fila* f){
    Fila *copia = criaFila();
    int i;
    for(i = 0;i<f->total;i++){
        entraFila(copia,&f->alunos[i]);
    }
    return copia;
}

Fila* ordenaFila(Fila* f){
    Fila* ordenada = criaFila();
    Fila *p = copiaFila(f);
    int i,j,maior;
    Aluno temp;
    for(i = 0; i<f->fim;i++){
        maior = i;
        for(j = i+1; j<f->fim;j++){
            if(p->alunos[j].nota > p->alunos[maior].nota){
                maior = j;
            }
        }
        entraFila(ordenada,&p->alunos[maior]);
        temp = p->alunos[maior];
        p->alunos[maior] = p->alunos[i];
        p->alunos[i] = temp;
    }
    return ordenada;
}

int verifica(Fila* f, Fila* ordenada){
    int c = 0,i;
    for(i=0;i<f->fim;i++){
        if(f->alunos[i].numero == ordenada->alunos[i].numero)
            c++;
    }
    return c;
}

int main(){
    int testes,alunos,notas,c;
    Aluno aluno;
    Fila* f = criaFila();
    Fila* ordenada;
    scanf("%d",&testes);
    while(testes != 0){
        scanf("%d",&alunos);
        for(int i = 0; i<alunos; i++){
            scanf("%d",&notas);
            aluno.numero = i+1;
            aluno.nota = notas;
            entraFila(f,&aluno);
        }
        ordenada = ordenaFila(f);
        c = verifica(f,ordenada);
        printf("%d\n",c);
        esvaziaFila(f);
        testes--;
    }
    return 0;
}
