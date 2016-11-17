#include <stdio.h>


typedef struct {
    int r, g, b;
}PIXEL;

int coluna, linha, max;
char padrao[3];
PIXEL img[1024][1024];


void lerImagem (){

    FILE *f = fopen("img.ppm", "r");
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
    printf("X: %d, Y: %d",coluna,linha);

}


void GrayScale (){

    lerImagem();

    FILE *f = fopen("img_gray.ppm", "w");

    fprintf(f, "%s\n", padrao);
    fprintf(f, "%d %d\n", coluna, linha);
    fprintf (f, "%d\n", max);

    int x,y;

    for(x = 0; x < linha; x++){
        for(y = 0; y < coluna; y++){
            int gray;
            gray = (img[x][y].r * 0.299) + (img[x][y].g * 0.587) + (img[x][y].b * 0.144);
            gray = gray > 255 ? 255 : gray;
            fprintf(f, "%d ", gray);
            fprintf(f, "%d ", gray);
            fprintf(f, "%d\n",gray);

        }
    }

    fclose(f);

}


void main(){

    GrayScale();

}
