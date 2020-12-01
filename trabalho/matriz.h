#ifndef matriz_h
#define matriz_h
#include <stdlib.h>

typedef struct TMat2D TMat2D; 


TMat2D *mat2D_create(int nrows, int ncolumns);
int mat2D_free(TMat2D *mat);
int mat2D_set_value(TMat2D *mat, int i, int j, unsigned char val);
int mat2D_get_value(TMat2D *mat, int i, int j, unsigned char *val);
int  mat2D_multiplicaescalar(TMat2D *mat,TMat2D **mat3,int x);
int  mat2D_somalinhas(TMat2D *mat,unsigned char **vet);
int  mat2D_somacols(TMat2D *mat,unsigned char **vet);
void exibirMatriz(TMat2D *mat);


#endif