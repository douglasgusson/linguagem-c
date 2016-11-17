#include<stdio.h>


typedef struct {
    int codigo;
	char descricao[100];
	char marca[80];
	double valorCompra;
	double valorVenda;
	int qtEstoque;
}PECA;


void main() {

    PECA *peca;

    FILE *f = fopen("DB_ARMANDO.DAT", "rb");

    while(fread(peca, sizeof(PECA), 1, f)) {

        printf("Codigo: %d\n", peca->codigo);
        printf("Descricao: %s\n", peca->descricao);
        printf("Marca: %s\n", peca->marca);
        printf("---------------------------------\n");

    }

    fclose(f);

}
