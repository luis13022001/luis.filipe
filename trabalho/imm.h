#ifndef imm_h
#define imm_h
#include "matriz.h"
#include <stdio.h>// FILE
#define SUCCESS 0
#define TXT 1
#define IMM 2
#define INVALID_FILE -1
#define MAP_SEM_SAIDA -4

typedef struct Img Img;

Img* lerImagetxt(char* arquivotxt);
Img* lerImageimm(char* arquivoimm);
int liberaImage(Img *arquivo);
int openImagetxt(char* arquivotxt);
int openImageimm(char* arquivoimm);
int convertTxtImm(char* arquivotxt, char* arquivoimm);
int segmentImage(int thr,char* aquivoimm, char* arquivoimm);//tirar dúvida
int compConexo(char* arquivoimm, char* arquivoSaida);
int labirinto(char* arquivotxt, char* arquivoSaida);
void get_linha_coluna(FILE* arq, int *retorno);
int verificatxtimm(char *arquivo);
int openImage(char *file);
int imagemParaArquivo(Img *img, char *arquivo);

#endif






