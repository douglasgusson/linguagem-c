#include <stdio.h>


typedef struct {
    int r, g, b;
}PIXEL;

int coluna, linha, max;
char padrao[3];
PIXEL img[1024][1024];

void poster();
void grayScale();
void negativo();
void espelhoHorizontal();
void espelhoVertical();
void tamanhoArquivo(char *arq);


int main() {

    lerImagem();
    poster();
    grayScale();
    negativo();
    espelhoHorizontal();
    espelhoVertical();

    return 0;
}


void tamanhoArquivo(char *arq) {

    FILE *f = fopen(arq, "r");

    fseek(f, 0, SEEK_END);
	int tamanho = ftell(f);

	 printf("\t=== Tamanho do arquivo: %d kB \n\n", (tamanho/1024));

}

void arquivoSaida(char *arq) {
    printf("\t--- Arquivo %s gerado \n", arq);
}


void lerImagem (){

    char *nome = "img_original.ppm";
    FILE *f = fopen(nome, "r");

    int x,y;

    fscanf (f, "%s", padrao);
    fscanf (f, "%d", &coluna);
    fscanf (f, "%d", &linha);
    fscanf (f, "%d", &max);

    for(x = 0; x < linha; x++){
        for(y = 0; y < coluna; y++){
            fscanf(f, "%d", &img[x][y].r);
            fscanf(f, "%d", &img[x][y].g);
            fscanf(f, "%d", &img[x][y].b);

        }
    }

    fclose(f);
    printf("\n\t--- Imagem %s (%d x %d pixels) lida.\n", nome, linha, coluna);
    tamanhoArquivo(nome);

}


void grayScale(){

    char *nome = "img_grayscale.ppm";

    FILE *f = fopen(nome, "w");

    fprintf(f, "%s\n", padrao);
    fprintf(f, "%d %d\n", coluna, linha);
    fprintf (f, "%d\n", max);

    int x,y;

    for(x = 0; x < linha; x++){
        for(y = 0; y < coluna; y++){
            int gray;
            gray = (img[x][y].r + img[x][y].g + img[x][y].b) / 3;
            gray = gray > 255 ? 255 : gray;
            fprintf(f, "%d ", gray);
            fprintf(f, "%d ", gray);
            fprintf(f, "%d\n",gray);

        }
    }

    fclose(f);

    arquivoSaida(nome);
    tamanhoArquivo(nome);

}


void poster(){

    char *nome = "img_poster.ppm";

    FILE *f = fopen(nome, "w");

    fprintf(f, "%s\n", padrao);
    fprintf(f, "%d %d\n", coluna, linha);
    fprintf (f, "%d\n", max);

    int x,y;

    for(x = 0; x < linha; x++){
        for(y = 0; y < coluna; y++){
            fprintf(f, "%d ", img[x][y].r > 127 ? 255 : 0);
            fprintf(f, "%d ", img[x][y].g > 127 ? 255 : 0);
            fprintf(f, "%d\n",img[x][y].b > 127 ? 255 : 0);

        }
    }

    fclose(f);

    arquivoSaida(nome);
    tamanhoArquivo(nome);

}



void negativo(){

    char *nome = "img_negativo.ppm";

    FILE *f = fopen(nome, "w");

    fprintf(f, "%s\n", padrao);
    fprintf(f, "%d %d\n", coluna, linha);
    fprintf (f, "%d\n", max);

    int x,y;

    for(x = 0; x < linha; x++){
        for(y = 0; y < coluna; y++){
            fprintf(f, "%d ", 255 - img[x][y].r);
            fprintf(f, "%d ", 255 - img[x][y].g);
            fprintf(f, "%d\n", 255 - img[x][y].b);

        }
    }

    fclose(f);

    arquivoSaida(nome);
    tamanhoArquivo(nome);

}

void espelhoHorizontal() {

    char *nome = "img_espelho_hor.ppm";

    FILE *f = fopen(nome, "w");

    fprintf(f, "%s\n", padrao);
    fprintf(f, "%d %d\n", coluna, linha);
    fprintf (f, "%d\n", max);

    int x,y;

    for(x = linha; x > 0; x--){
        for(y = 0; y < coluna; y++){
            fprintf(f, "%d ", img[x][y].r);
            fprintf(f, "%d ", img[x][y].g);
            fprintf(f, "%d\n", img[x][y].b);

        }
    }

    fclose(f);

    arquivoSaida(nome);
    tamanhoArquivo(nome);

}


void espelhoVertical() {

    char *nome = "img_espelho_ver.ppm";

    FILE *f = fopen(nome, "w");

    fprintf(f, "%s\n", padrao);
    fprintf(f, "%d %d\n", coluna, linha);
    fprintf (f, "%d\n", max);

    int x,y;

    for(x = 0; x < linha; x++){
        for(y = coluna; y > 0; y--){
            fprintf(f, "%d ", img[x][y].r);
            fprintf(f, "%d ", img[x][y].g);
            fprintf(f, "%d\n", img[x][y].b);

        }
    }

    fclose(f);

    arquivoSaida(nome);
    tamanhoArquivo(nome);

}
