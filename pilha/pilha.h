#define TamPilha 100
typedef int elem;
typedef struct pilha Pilha;

Pilha* Create();
void Empty(Pilha *p);
int IsEmpty(Pilha* p);
int IsFull(Pilha* p);
int Push(Pilha *p, elem x);
int Pop(Pilha* p, elem *x);
