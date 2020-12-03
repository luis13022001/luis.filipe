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
    if(fl->data == NULL){  
    free(fl);
    return   NULL;
}
  return fl; 

}
int free_queue(TQueue *fl){
  if(fl == NULL)
    return INVALID_NULL_POINTER;
  free(fl);
  return SUCCESS;
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
    struct aluno *aux = realloc(fl->data, sizeof(struct aluno) * newsize);

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
  fl->size--;
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


int queue_compact(TQueue* fl){
if(fl == NULL) //Se não tiver sido carregada
return -1;

 if(fl->size == 0)
 return INVALID_NULL_POINTER;

 int quantidade; //recebe qtd como float
 quantidade = fl->size; //Para usar ceil a qtd deveria ser float

 int count = 0;
  if(fl->front < fl->rear){
    while(count < fl->size){
      fl->data[count] = fl->data[fl->front];
      count++;
      fl->front++;
    }
    fl->front = 0;
    fl->rear = fl->size;
    fl->size = (ceil((float)quantidade/fl->taminic))*fl->taminic;
    return 0;
  }else if(fl->front > fl->rear){
    struct aluno temp[fl->size];
    while(fl->front < fl->size){
        temp[count] = fl->data[fl->front];
        count++;
        fl->front++;
    }
    int count2 = 0;
    while(count2 < fl->rear){
      temp[count] = fl->data[count2];
      count++;
      count2++;
    }
    for(count = 0; count < fl->size; count++){
      fl->data[count] = temp[count];
/*printf("     %d\t    %s\t%.3f\t\t%.3f\t\t%.3f\n",
fl->data[count].matricula,
fl->data[count].nome,fl->data[count].n1,
fl->data[count].n2,
fl->data[count].n3);
printf("\n");
  
  */  }
    fl->front = 0;
    fl->rear = fl->size;
    fl->size = (ceil((float)quantidade/fl->taminic))*fl->taminic;
  }
  fl->data = realloc(fl->data,(((float)fl->size/fl->taminic))*sizeof(struct aluno));

return 0;
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
