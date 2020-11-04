#include "ListaSequencial.h"
#include <stdio.h>
#include <stdlib.h>



struct lista{
  int qtd;
  struct aluno dados[MAX];
};

Lista* cria_lista(){
  Lista *li;       
  li = (Lista*) malloc(sizeof(struct lista));      
  if(li != NULL)        
  li->qtd = 0;     
  return li; 

}


void libera_lista(Lista* li){
  free(li);
}

int consulta_lista_pos(Lista* li, int pos, struct aluno*al){
  if(li == NULL || pos <= 0 ||  pos > li->qtd )
  return -1;
  *al = li->dados[pos-1];
  return 0;

}

int consulta_lista_mat(Lista* li, int mat, struct aluno*al){
  if(li == NULL){      
   return -1;
      }    
      int i= 0  ;
      while(i < li->qtd && li->dados[i].matricula != mat){
      i++;     
      if(i  == li->qtd){//elementonao encontrado
      return -1;
      }
      *al = li->dados[i];
      }
      return 0;
}


int insere_lista_final(Lista *li, struct aluno al){
  if (li == NULL)
    return -1;
  
  if (li->qtd == MAX)
    return -1;


  li->dados[li->qtd]  = al;
  li->qtd = li->qtd + 1;

  return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
   if(li == NULL){      
   return -1;
  }
  if(li->qtd >= MAX){
    return -1;
  }
  
  for(int k=  li->qtd ; k >= 0; k--) {       
  li->dados[k+1] = li->dados[k];
  }
  li->qtd++;
  li->dados[0] = al;
  return 0;
}
int insere_lista_ordenada(Lista* li, struct aluno al){
  struct aluno aux;
  if(li == NULL){        
  return -1;
  }
  if(li ->qtd == MAX){         
  return -1;
  }
  for(int j = 0; j < li->qtd-1 ; j++){
    if(li->dados[j+1].matricula < li->dados[j].matricula){
      aux = li->dados[j];
      li->dados[j] = li->dados[j+1];
      li->dados[j+1] = aux;
    }

  }
 
  int k,i  = 0;
  while(i < li->qtd && li->dados[i].matricula < al.matricula){
  i++;
  }
  for(k = li->qtd-1 ; k >= i; k--){
  li->dados[k+1] = li->dados[k];
 
  }
   li->dados[i] = al;
  li->qtd++;

return 0;
}

int remove_lista(Lista* li, int mat){
if(li == NULL){        
  return -1;
  }
  if(li ->qtd == MAX){         
  return -1;
  }
  int k,i  = 0;
  while(i < li->qtd && li->dados[i].matricula != mat){
  i++;
  if(i == li-> qtd + 1){
    return 1;
  }
  }
  for(k = i ; k <li->qtd-1; k++){
  li->dados[k] = li->dados[k+1];
  }

 
li->qtd--;
 return 0;
}

int remove_lista_inicio(Lista* li){
  if(li == NULL){        
  return -1;
  }
  if(li ->qtd == 0){         
  return -1;
  }

  for(int k = 0 ; k < li->qtd-1; k++){
  li->dados[k] = li->dados[k+1];
 }
  li->qtd--;
return 0;
}
int remove_lista_final(Lista* li){
  if(li == NULL){        
  return -1;
  }
  li->qtd--;
  return 0;
}

int tamanho_lista(Lista* li){
   if(li == NULL){        
  return -1;
  }
  return li->qtd;

}

int lista_cheia(Lista* li){
  if(li ->qtd == MAX){         
  return -1;
  }
  return 2;
}
int lista_vazia(Lista* li){
if(li ->qtd == 0){         
  return -1;
  }
return 0;
}
int remove_lista_otimizado(Lista* li, int mat){
  struct aluno aux;
  if(li == NULL){        
  return -1;
  }
   if(li ->qtd == MAX){         
  return -1;
  }
  for(int j = 0; j < li->qtd-1 ; j++){
    if(li->dados[j+1].matricula < li->dados[j].matricula){
      aux = li->dados[j];
      li->dados[j] = li->dados[j+1];
      li->dados[j+1] = aux;
    }

  }
  
  int k,i  = 0;
  while(i < li->qtd && li->dados[i].matricula != mat){
  i++;
  }
  li->qtd--;
  li->dados[i] = li->dados[li->qtd];
 
  

return 0;
}
int multiplica_notas(Lista *li, int val){
        if(li == NULL){
         return -1;    
        }
  for(int i =0; i< li->qtd; i++){
    li->dados[i].n1 *= val;
    li->dados[i].n2 *= val;
    li->dados[i].n3 *= val;
  }
  
return 0;
}
int imprime_lista(Lista* li){
        if(li == NULL){
         return -1;    
        }
         int i;
         for(i =0;   i< li->qtd; i++){
        printf("Matricula: %d\n",li->dados[i].matricula);
        printf("Nome: %s\n",   li->dados[i].nome);
        printf("Notas: %.3f %.3f %.3f\n",li->dados[i].n1,li->dados[i].n2,li->dados[i].n3); printf("-------------------------------\n");} 

return 0;
}