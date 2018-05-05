#include <stdio.h>

#define MAX 10

typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	// outros atributos
}REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int n;
}LISTA;

void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
int imprimirLista(LISTA* l);
int buscaSequencial(LISTA* l, TIPOCHAVE ch);
int inserirElemLista(LISTA* l, REGISTRO reg, int pos);

int main() {

	LISTA l;
	REGISTRO reg;

	inicializarLista(&l);
	
	reg.chave = 10;
	if (!inserirElemLista(&l, reg, 0)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	reg.chave = 11;
	if (!inserirElemLista(&l, reg, 1)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	reg.chave = 12;
	if (!inserirElemLista(&l, reg, 2)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	reg.chave = 13;
	if (!inserirElemLista(&l, reg, 3)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	imprimirLista(&l);

	printf("TAMANHO DA LISTA: %d\n", tamanho(&l));

	return 0;
}


void inicializarLista(LISTA* l) {
	l->n = 0;
}

int tamanho(LISTA* l) {
	return l->n;
}

int imprimirLista(LISTA* l) {
	printf("-- LISTA --\n");
	for (int i=0; i < l->n; i++)
		printf(" # %d\n", l->A[i].chave);
	printf("-----------\n");
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
	for (int i=0; i < l->n; i++)
		if (l->A[i].chave == ch) return i; 
	return -1;
}

int inserirElemLista(LISTA* l, REGISTRO reg, int pos) {
	if ((l->n == MAX) || (pos < 0) || (pos > l->n)) return 0;
	for (int i=l->n; i > pos; i--) l->A[i] = l->A[i-1];
	l->A[pos] = reg;
	l->n++;
	return 1; 
}