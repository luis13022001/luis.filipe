#ifndef imm_h
#define imm_h
#include "matriz.h"
#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 //sempre que a função receber null
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4
#define ERRO_SORTED -5

typedef struct Img Img;

Img* lerImagetxt(char* arquivotxt);
Img* lerImageimm(char* arquivoimm);
int liberaImage(Img *aquivo);
int setImagetxt(char* arquivoitxt, Img *aux);
int setImageimm(char* arquivoimm, Img *aux);
int openImagetxt(char* arquivotxt);
int openImageimm(char* arquivoimm);
int convertTxtImm(char* arquivotxt, char* arquivoimm);
int segmentImage(int thr,char* aquivoimm, char* arquivoimm);//tirar dúvida
int compConexo(char* arquivoimm, char* arquivoSaida);
int labirinto(char* arquivotxt, char* arquivoSaida);
//empilhar (comparar duas matrizes) conexo
#endif



