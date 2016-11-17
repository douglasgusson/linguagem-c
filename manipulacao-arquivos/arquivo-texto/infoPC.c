#include <stdio.h>

typedef struct {
    int id;
    char processador[30];
    int memoriaGB;
    int hdGB;
    char placaVideo[30];
} COMPUTADOR;

void main(){

    COMPUTADOR pc;
    FILE *f = fopen("computador.txt", "r");
    FILE *fn = fopen("computador2.txt", "w+");

    char linha[80];

    while (fgets(linha,sizeof(COMPUTADOR), f)) {

        sscanf(linha, "%d;%[^;];%d;%d;%[^;\n]", &pc.id, pc.processador,
            &pc.memoriaGB, &pc.hdGB, pc.placaVideo);

        printf("ID: %d\nProcessador: %s\nMemoria: %d GB\nHD: %d GB\nPlaca de Video: %s\n",
            pc.id, pc.processador, pc.memoriaGB,pc.hdGB, pc.placaVideo);
        printf("-------------------------------\n");

        if (pc.id == 2) {
            strcpy(pc.placaVideo, "Radeon Graphics");
        }

        fprintf(fn, "%d;%s;%d;%d;%s\n", pc.id, pc.processador, pc.memoriaGB,
        pc.hdGB, pc.placaVideo);

    }

    fclose(f);
    fclose(fn);

    rename("computador2.txt", "computador.txt");
    remove("computador2.txt");

}
