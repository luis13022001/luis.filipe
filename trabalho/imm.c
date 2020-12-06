#include "imm.h"
#include <string.h>
#include <stdio.h>
#include "matriz.h"

struct Img{
    TMat2D *data;
    char formato[3];
    int max;
};

Img* lerImagetxt(char* arquivotxt){
int i=0, linha = 0, coluna = 0, max;
    unsigned char dados;
    char p2[3];
    FILE *arq;
    Img *img = (Img *)malloc(sizeof(Img));
    arq = fopen(arquivotxt, "rt");
    if (arq == NULL)
        return NULL;
    fscanf(arq, "%s\n", &p2);
    fscanf(arq, "%d %d\n", &coluna, &linha);
    while((c = fgetc(arq)) != EOF){
        if(linha == 0 && c == " "){
            coluna++;
        }
        else if(c == "\n"){
            linha++;
        }
        else{
            //continuar
        }
    }
    fscanf(arq, "%d\n", &max);


    img->max = max;
    strcpy (img->formato, p2);
    img->data = mat2D_create(linha,coluna);
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            fscanf(arq, "%hhu", &dados);
            if (mat2D_set_value(img->data,i,j,dados) != SUCCESS){
                return NULL;
            }
        }
    }
    fclose(arq);
 return img;
}

Img* lerImageimm(char* arquivoimm){

}

int liberaImage(Img *arquivo){
    if(arquivo == NULL){
        return -1;
    }
    free(arquivo->data);
    free(arquivo);
    return SUCCESS;
}

int setImagetxt(char* arquivoitxt, Img* aux){

    return 0;
}
int setImageimm(char* arquivoimm, Img* aux){
    return 0;
}

int openImagetxt(char* arquivotxt){
    Img *img = lerImagetxt(arquivotxt);
    exibirMatriz(img->data);
    liberaImage(img);
    return 0;
}

int openImageimm(char* arquivoimm){
    return 0;
}
int convertTxtImm(char* arquivotxt, char* arquivoimm){
    return 0;
}
int segmentImage(int thr,char* aquivoimm, char* arquivoimm){
    return 0;
}
int compConexo(char* arquivoimm, char* arquivoSaida){
    return 0;
}
int labirinto(char* arquivotxt, char* arquivoSaida){
    return 0;
}