#include<stdio.h>


void main() {

    int v[10] = {21,12,30,42,8,4,1,2,19,0};
    int i, j, aux;

    // ordenação
    for (i=0; i<(sizeof(v)/sizeof(int)); i++) {
        for (j=0; j<(sizeof(v)/sizeof(int)-1); j++) {
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }


    // imprime o vetor ordenado
    for (i=0; i<(sizeof(v)/sizeof(int)); i++) {
        printf(" %d |", v[i]);
    }


}
