#include "matriz.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct TMat2D
{
  int nrows; // número de linhas
  int ncolumns; // número de colunas
  unsigned char *data; // ponteiro para os dados da matriz
};


TMat2D *mat2D_create(int nrows, int ncolumns){
 

  if ( (nrows <= 0 ) || (ncolumns <=0) ){
    return NULL;
  }

  TMat2D *mat;  
  mat = (TMat2D *)malloc(sizeof(TMat2D));// aloca 12 bytes // FFFFFF
                                // nrows, ncolumns, *data
  if (mat == NULL){
    return NULL;
  }
 
  mat->data = malloc(sizeof(unsigned char)*nrows*ncolumns); 
  if (mat->data == NULL){
      free(mat);
      return NULL;
  }

  mat->nrows = nrows;
  mat->ncolumns = ncolumns;

   
  return mat;

}



int mat2D_free(TMat2D *mat){
    if (mat == NULL){
        return -1;
    }
    if (mat->data != NULL){
        free(mat->data);    
    }
    free(mat);
    return 0;

}

int mat2D_set_value(TMat2D *mat, int i, int j, unsigned char val){
    if (mat == NULL){
    return -1;
  }
    if (mat->data == NULL){
      return -1;
  } 
  if(i < 0 || i >= mat->nrows || j < 0 || j >= mat->ncolumns){
      return -1;
  }

   mat->data[j * mat->nrows + i] = val;
    
    return 0;
}



int mat2D_get_value(TMat2D *mat, int i, int j, unsigned char *val){
       if (mat == NULL){
    return -1;
  }
    if (mat->data == NULL){
      return -1;
  } 
    if(i < 0 || i >= mat->nrows || j < 0 || j >= mat->ncolumns){
      return -1;
  }

   *val = mat->data[j * mat->nrows + i];
    
    return 0;
}



int  mat2D_somalinhas(TMat2D *mat,unsigned char **vet){
    if(mat == NULL){
        return -1;
    }
    for(int i = 0; i < mat->nrows; i++){
      for(int j = 0; j < mat->ncolumns; j++){
         (*vet)[i] += mat->data[j * mat->nrows + i];
      }
    }
    return 0;
}


int  mat2D_somacols(TMat2D *mat,unsigned char **vet){
    if(mat == NULL){
        return -1;
    }
    (*vet) =malloc(mat->ncolumns*sizeof(unsigned char));
    for(int j = 0; j <= mat->ncolumns; j++){
    for(int i = 0; i <= mat->nrows; i++){
         (*vet)[i] += mat->data[i * mat->nrows + j];
      }
    }
    return 0;
}

void exibirMatriz(TMat2D *mat){
	int i, j;
	for(i = 0; i < mat->nrows; i++){
		for(j = 0; j < mat->ncolumns; j++){
			printf("%3.hhu ", mat->data[j * mat->nrows + i]);
		}
		printf("\n");
	}
}
