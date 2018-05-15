#include <stdio.h>

#define LIN 3
#define COL 4
#define MAX (LIN*COL)

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
}REGISTRO;

typedef struct {
    int topo;
    REGISTRO ar[MAX];
}PILHA;


void imprimirMatriz(int m[LIN][COL]);

void inicializar(PILHA* p);
int empilhar(PILHA* p, REGISTRO reg);
REGISTRO desempilhar(PILHA* p);
void imprimir(PILHA* p);

int topo(PILHA* p);
int vazia(PILHA* p);
int cheia(PILHA* p);


int main() {

    PILHA p;
    REGISTRO reg;

    int m[LIN][COL], r[LIN][COL];
    int i, j, aux=1;

    inicializar(&p);

    for (i=0;i<LIN;i++) {
        for (j=0;j<COL;j++) {
            reg.chave = aux;
            m[i][j] = reg.chave;
            empilhar(&p, reg);
            aux++;
        }
    }

    imprimir(&p);
    if (cheia(&p)) {
        printf("PILHA CHEIA\n");
    }

    for (i=0;i<LIN;i++) {
        for (j=0;j<COL;j++) {
            reg = desempilhar(&p);
            r[i][j] = reg.chave;
        }
    }

    printf("\n\t- MATRIZ M -");
    imprimirMatriz(m);
    printf("\n\t- MATRIZ R -");
    imprimirMatriz(r);

    return 0;
}

void imprimirMatriz(int m[LIN][COL]) {
    int i, j;
    for (i=0; i<LIN; i++) {
        printf("\n");
        for (j=0; j<COL; j++) {
            printf("%d\t", m[i][j]);
        }
    }
    printf("\n");
}

void inicializar(PILHA* p) {
    p->topo = -1;
}

int empilhar(PILHA* p, REGISTRO reg) {
    if (p->topo > MAX-1) return 0;
    p->topo++;
    p->ar[p->topo] = reg;
    return 1;
}

REGISTRO desempilhar(PILHA* p) {
    REGISTRO regAux = p->ar[p->topo];
    p->topo--;
    return regAux;
}

void imprimir(PILHA* p) {
    int i;
    printf("- PILHA -\n");
    for (i=0; i<=p->topo; i++) {
        printf("# %d\t#\n", p->ar[i].chave);
    }
    printf("---------\n");
}

int topo(PILHA* p) {
    return p->topo;
}

int vazia(PILHA* p) {
    if (p->topo == -1) return 1;
    else return 0;
}


int cheia(PILHA* p) {
    if (p->topo == MAX-1) return 1;
    else return 0;
}
