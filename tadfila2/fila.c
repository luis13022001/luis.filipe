#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct list_node list_node;
struct list_node{
    struct aluno data;    
    list_node *next;
};

struct Fila{
    list_node *begin; 
    list_node *end;
    int size; // quantidade de elementos na lista 
    int inf;    
};

Fila *create_fila(){
    Fila *fl;
    fl = malloc(sizeof(Fila));
    if(fl == NULL){
        return fl;
    }
    fl->begin = NULL;
    fl->end = NULL;
    fl->size = 0;
    // TLinkedList vazia tem que apontar para nulo pois ela nao tem elementos

    return fl;
}

int fila_free(Fila *fl){
    if(fl == NULL){
   return INVALID_NULL_POINTER;
 }else{
    list_node *aux = fl->begin;
    while(aux != NULL){
      fl->end = aux;
      aux = aux->next;
      free(fl->end);//liberar cada posição
      fl->size--;
    }
    free(fl);
    return SUCCESS;
}
}

int fila_push(Fila *fl, struct aluno al){
    if (fl == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    list_node *node;
    node = malloc(sizeof(list_node));
    if (node == NULL)
    {
      return OUT_OF_MEMORY;
    }
    else{
      node->data = al;
      node->next = NULL;
    }
    //ver se a lista está vazia
     if (fl->size == 0)
    {
      fl->begin = node;
      fl->end = node;
      fl->size++;
      return SUCCESS;
    }
    else
    {
      fl->end->next = node;
      fl->end = node;
      fl->size++;
    }
    return SUCCESS;

  }
}

int fila_pop_front(Fila*fl){
    if(fl == NULL){
      return INVALID_NULL_POINTER;
    }
    if(fl->size == 0){
       return OUT_OF_RANGE;
    }
    list_node *aux = fl->begin;//aux recebe a cabeça
    fl->begin = aux->next;//cabeça recebe a proxima posição

    free(aux);
    fl->size--;

    return SUCCESS;

}

int fila_size(Fila *fl){
    if(fl == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        return fl->size;
    }
}

int fila_find(Fila *fl,struct aluno *al){
    if(fl == NULL){
        return INVALID_NULL_POINTER;
    }
    if(fl->size == 0){
        return OUT_OF_RANGE; 
    }
    else{
        list_node *aux = fl->begin;
        *al = aux->data;
    }
    return SUCCESS;
}


