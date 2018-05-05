#include <stdio.h>

typedef int bool;

#define TRUE 1
#define FALSE 0

#define INVALIDO -1
#define MAX 10

typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	// outros atributos
}REGISTRO;

typedef struct {
	REGISTRO reg;
	int prox;
}ELEMENTO;

typedef struct {
	ELEMENTO A[MAX];
	int inicio;
	int dispo;
}LISTA;

void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
void imprimirLista(LISTA* l);
int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch);
int obterNo(LISTA* l);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
bool excluirElemLista(LISTA* l, TIPOCHAVE ch);
void devolverNo(LISTA* l, int i);
void reinicializarLista(LISTA* l);

void testesListaLigada();

int main() {
	printf("\n*** TESTES (Lista ligada) ***\n");
	testesListaLigada();
	printf("\n");	
	return 0;
}


void inicializarLista(LISTA* l) {
	for (int i = 0; i < MAX-1; i++)
		l->A[i].prox = i + 1;
	l->A[MAX-1].prox = INVALIDO;
	l->inicio = INVALIDO;
	l->dispo = 0;
}

int tamanho(LISTA* l) {
	int i = l->inicio;
	int tam = 0;
	while (i != INVALIDO) {
		tam++;
		i = l->A[i].prox;
	} 
	return tam;
}

void imprimirLista(LISTA* l) {
	int i = l->inicio;
	printf("LISTA: [");
	while (i != INVALIDO) {
		printf(" %d ", l->A[i].reg.chave);
		i = l->A[i].prox;
	} 
	printf("]\n");
}

int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch) {
	int i = l->inicio;
	while (i != INVALIDO && l->A[i].reg.chave < ch) 
		i = l->A[i].prox;
	if (i =! INVALIDO && l->A[i].reg.chave == ch)
		return i;
	else return INVALIDO; 
}

int obterNo(LISTA* l) {
	int resultado = l->dispo;
	if (l->dispo != INVALIDO)
		l->dispo = l->A[l->dispo].prox;
	return resultado; 
}

/**
 * Insere um novo elemento (se possível) de forma ordenada.
 */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
	if (l->dispo == INVALIDO) return FALSE;
	int ant = INVALIDO;
	int i = l->inicio;
	TIPOCHAVE ch = reg.chave;
	while ((i != INVALIDO) && (l->A[i].reg.chave < ch)) {
		ant = i;
		i = l->A[i].prox;
	}
	if (i != INVALIDO && l->A[i].reg.chave == ch) return FALSE;
	i = obterNo(l);
	l->A[i].reg = reg;
	if (ant == INVALIDO) {
		l->A[i].prox = l->inicio;
		l->inicio = i;
	} else {
		l->A[i].prox = l->A[ant].prox;
		l->A[ant].prox = i;
	}
	return TRUE;
}

/**
 * Remove um elemento da lista.
 */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
	int ant = INVALIDO;
	int i = l->inicio;
	while ((i != INVALIDO) && (l->A[i].reg.chave < ch)) {
		ant = i;
		i = l->A[i].prox;
	}
	if (i == INVALIDO && l->A[i].reg.chave != ch) return FALSE;
	if (ant == INVALIDO) l->inicio = l->A[i].prox;
	else l->A[ant].prox = l->A[i].prox;
	devolverNo(l, i);
	return TRUE;
}

void devolverNo(LISTA* l, int i) {
	l->A[i].prox = l->dispo;
	l->dispo = i;
}

void reinicializarLista(LISTA* l) {
	inicializarLista(l);
}

void testesListaLigada() {

	LISTA l;
	REGISTRO reg;

	inicializarLista(&l);
	
	imprimirLista(&l);
	printf("TAMANHO: %d\n", tamanho(&l));

	reg.chave = 22;
	if (!inserirElemListaOrd(&l, reg)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	reg.chave = 19;
	if (!inserirElemListaOrd(&l, reg)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	reg.chave = 12;
	if (!inserirElemListaOrd(&l, reg)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	reg.chave = 13;
	if (!inserirElemListaOrd(&l, reg)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	reg.chave = 14;
	if (!inserirElemListaOrd(&l, reg)) printf("** NAO FOI POSSIVEL INSERIR **\n"); 

	imprimirLista(&l);

	excluirElemLista(&l, 22);

	imprimirLista(&l);

	printf("TAMANHO: %d\n", tamanho(&l));
}