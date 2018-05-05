#include <stdio.h>

typedef int bool;

#define TRUE 1
#define FALSE 0

#define MAX 10

typedef int TIPOCHAVE;

typedef struct {
	TIPOCHAVE chave;
	// outros atributos
}REGISTRO;

typedef struct {
	REGISTRO A[MAX+1];
	int n;
}LISTA;

void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
void imprimirLista(LISTA* l);
int buscaSequencial(LISTA* l, TIPOCHAVE ch);
int buscaSentinela(LISTA* l, TIPOCHAVE ch);
int buscaBinaria(LISTA* l, TIPOCHAVE ch);
bool inserirElemLista(LISTA* l, REGISTRO reg, int pos);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
bool excluirElemLista(LISTA* l, TIPOCHAVE ch);
void reinicializarLista(LISTA* l);

void testesListaLinearSequencial();

int main() {
	printf("\n*** TESTES (Lista linear sequencial) ***\n");
	testesListaLinearSequencial();
	printf("\n");	
	return 0;
}


void inicializarLista(LISTA* l) {
	l->n = 0;
}

int tamanho(LISTA* l) {
	return l->n;
}

void imprimirLista(LISTA* l) {
	printf("LISTA: [");
	for (int i=0; i < l->n; i++)
		printf(" %d ", l->A[i].chave);
	printf("]\n");
}

/**
 * Busca por um elemento na lista de forma sequêncial.
 */
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
	for (int i=0; i < l->n; i++)
		if (l->A[i].chave == ch) return i; 
	return -1;
}

int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
	int i = 0;
	l->A[l->n].chave = ch;
	while (l->A[i].chave != ch) i++;
	if (i == l->n) return -1;
	else return i; 
}

int buscaBinaria(LISTA* l, TIPOCHAVE ch) {
	int esq, meio, dir;
	esq = 0;
	dir = l->n-1;
	while (esq <= dir) {
		meio = ((esq + dir) / 2);
		if (l->A[meio].chave == ch) return meio;
		else {
			if (l->A[meio].chave < ch) esq = meio + 1;
			else dir = meio - 1;
		}
	}
	return -1;
}

/**
 * Insere um novo elemento (se possível) na posição desejada pelo usuário.
 */
bool inserirElemLista(LISTA* l, REGISTRO reg, int pos) {
	if ((l->n == MAX) || (pos < 0) || (pos > l->n)) return FALSE;
	for (int i=l->n; i > pos; i--) l->A[i] = l->A[i-1];
	l->A[pos] = reg;
	l->n++;
	return TRUE; 
}

/**
 * Insere um novo elemento (se possível) de forma ordenada.
 */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
	if (l->n >= MAX) return FALSE;
	int pos = l->n;
	while (pos > 0 && l->A[pos-1].chave > reg.chave) {
		l->A[pos] = l->A[pos-1];
		pos--;
	}
	l->A[pos] = reg;
	l->n++;
	return TRUE;
}

/**
 * Remove um elemento da lista.
 */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
	int i, pos;
	pos = buscaBinaria(l, ch);
	if (pos == -1) return FALSE;
	for (i=pos; i < l->n-1; i++) l->A[i] = l->A[i+1];
	l->n--;
	return TRUE;
}

void reinicializarLista(LISTA* l) {
	l->n = 0;
}

void testesListaLinearSequencial() {

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

	excluirElemLista(&l, 22);

	imprimirLista(&l);

	printf("TAMANHO: %d\n", tamanho(&l));
}