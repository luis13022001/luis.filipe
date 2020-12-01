#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <math.h>


struct TQueue{
  int size;
  int front;
  int rear;
  int taminic, tamatual;// para usar no compacta lista com o ceil precisa ser float
  struct aluno *data;
};

TQueue *create_queue(int tam){
  TQueue *fl;       
  fl =  malloc(sizeof(TQueue));      
  if(fl == NULL){  
    return   NULL;
}
  fl->size = 0;
  fl->front = 0;
  fl->rear = 0;
  fl->taminic = tam;
  fl->tamatual = tam;
  fl->data = malloc(tam *sizeof(struct aluno));
    if(fl->dados == NULL){  
    free(fl);
    return   NULL;
}
  return li; 

}
int free_queue(TQueue *fl){
  if(fl == NULL)
    return INVALID_NULL_POINTER;
  free(fl);
  return SUCCESS;
}

int realoca_lista(Lista *li){
  struct aluno *aux;
  int tam;
  li->tamatual += li->taminic;
  
    if(li == NULL){  
    return -1;
  }
  aux = realloc(li->dados,li->tamatual * sizeof(struct aluno));
  li->dados = aux;
  
  if(li == NULL){  
    return -1;
  }
  return 0;
}


int enqueue(TQueue *fl, struct aluno al){
  
  if(fl == NULL){
    return INVALID_NULL_POINTER;
  }
  if(fl->size == 0){
    fl->data[fl->size] = al;
  }
  else {
    if(fl->size == fl->tamatual ){
    int newsize = (fl->size/fl->taminic +1) * fl->taminic;
    aluno *aux = realloc(fl->data, sizeof(aluno) * newsize);

    if(aux == NULL){
      return INVALID_NULL_POINTER;
    }
    else{
      fl->tamatual = newsize;
      for(int i = fl->front; i < newsize; i++){
        fl->data[i+1] = fl->data[i];
      }
      fl->data = aux;
  
    }
  }
  }
   if(fl->rear > fl->front && fl->rear + 1 == fl->tamatual){
    fl->rear = 0;
    fl->data[fl->rear] = al;
  }
  else if(fl->rear < fl->front && fl->rear + 1 == fl->front){
    fl->data[fl->front + 1] = fl->data[fl->front];
    fl->data[fl->front] = al;
    fl->front++;
    fl->rear++;
  }
  else{
    fl->data[++fl->rear] = al;
  }

  fl->size++;





  return SUCCESS;
}




int dequeue(TQueue *fl){//remover inicio
  if(fl == NULL){
    return INVALID_NULL_POINTER;
  }
  if(fl->size == 0){
    return OUT_OF_RANGE;
}
  fl->front = (fl->front+1)%fl->tamatual;
  fi->size--;
  return SUCCESS;
}

int queue_front(TQueue *fl, struct student *al){//pegar o 1° elemento
  if(fl == NULL){
    return INVALID_NULL_POINTER;
  }
  if(fl->size == 0){
    return OUT_OF_RANGE;
}
  *al = fl->data[fl->front];
  return SUCCESS;
}


int size_queue(TQueue* fl){
   if(fl== NULL){        
  return INVALID_NULL_POINTER;
  }
  return fl->size;
}

int queuefull(TQueue* fl){
  if(fl == NULL){
    return INVALID_NULL_POINTER;
  }
  else if(fl->size == fl->tamatual){         
  return FULL;
  }
  else{
  return SUCCESS;
  }
}


int compact_queue(TQueue* fl){
  struct student *newlist;
  if(fl == NULL)
    return INVALID_NULL_POINTER;
  int aux = ceil(fl->size/fl->taminic)*fl->MIN;
  fl->tamatual = aux;
  newlist = realloc(fl->data,aux*sizeof(struct student));
  fl->data = newlist;
  fl->front = 0;
  fl->rear = fl->size;
  
  return SUCCESS;
}


int print_queue(TQueue *fl){
  if(fl == NULL){
    return INVALID_NULL_POINTER;    
  }
  int i;
  for(i =0;   i< fl->size; i++){
  printf("Matricula: %d\n",fl->data[i].matricula);
  printf("Nome: %s\n",   fl->data[i].nome);
  printf("Notas: %f %f %f\n",fl->data[i].n1,fl->data[i].n2,fl->data[i].n3);       
  printf("-------------------------------\n");} 

return 0;
}
