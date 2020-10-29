#include <stdlib.h>
#include "TDLinkedList.h"
#include <stdio.h>

typedef struct list_node list_node;
 
struct list_node { 
  struct aluno data;   
  list_node *next;   
  list_node *prev;
}; 

typedef struct TDLinkedList{   
  list_node *begin;  
  list_node *end;    
  int size;
}TDLinkedList; 

TDLinkedList* list_create(){// criar a lista

  TDLinkedList *li;
  li = malloc(sizeof(TDLinkedList));
  if(li != NULL){
    li->begin = NULL;
    li->end = NULL;
    li->size = 0;
  }
  return li;
}

int list_free(TDLinkedList *li){//liberar lista
    if(li == NULL){
      return INVALID_NULL_POINTER;
    }
    list_node *aux = li->begin;
    list_node *previous = NULL;
    int i = 1;
    while(i < li->size){
      previous = aux;
      aux = aux->next;
      free(previous);//liberar cada posição
      i++;
    }
    free(li);
    return SUCCESS;
}

int list_push_front(TDLinkedList *li, struct aluno al)//insere inicio
{
  if (li == NULL)
  {
    return INVALID_NULL_POINTER;
  }
  else
  {
    list_node *node;
    node = malloc(sizeof(list_node));
    if (node == NULL)
    {
      return OUT_OF_MEMORY;
    }
    else
    {
      node->data = al;
      node->prev = NULL;
      node->next = li->begin;
    }
   //ver se alista está vazia
    if (li->begin == NULL)
    {
      li->begin = node;
      li->end = node;
      li->size = 1;
    }
    else
    {
      li->begin->prev = node;
      li->begin = node;
      li->size = li->size + 1;
    }
    return SUCCESS;
  }
}

int list_push_back(TDLinkedList *li, struct aluno al){// insere no final
  if (li == NULL){
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
      node->prev = li->end;
      node->next = NULL;
    }
    //ver se a lista está vazia
     if (li->size == 0)
    {
      li->begin = node;
      li->end = node;
      li->size = 1;
    }
    else
    {
      li->end->next = node;
      li->end = node;
      li->size = li->size + 1;
    }
    return SUCCESS;

  }
}

int list_insert(TDLinkedList *li, int pos, struct aluno al){//insere posição
  if (li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    list_node *node;
    node = malloc(sizeof(list_node));
    if(node == NULL){
      return OUT_OF_MEMORY;
    }

    else{
      node->data = al;
      if(li->size == 0){
        node->prev = NULL;
        node->next = NULL;

        li->begin = node;//apontar a cabeça para o elemento
        li->end = node;//apontar o ultimo elemneto para o elemento inserido
        li->size++;
      }
      else if(pos == 1){
        node->prev = NULL;
        node->next = li->begin;

        li->begin->prev = node;
        li->begin = node;
        li->size++;
      }
      else if(pos == li->size + 1){
        node->prev = li->end;
        node->next = NULL;

        li->end->next = node;
        li->end = node;
        li->size++;
      }
      else{
        int i = 1;
        list_node *aux;
        aux = li->begin;
        while(i < pos -1){
          aux = aux->next;
          i++;
        }
        node->prev = aux;
        node->next = aux->next;
        node->next->prev = node;
        aux->next = node;
        li->size++;

      }
    }
  }
  return SUCCESS;
}

int list_size(TDLinkedList *li){
  if (li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    return li->size;
  }
}

int list_pop_front(TDLinkedList *li){ //remove começo
  if (li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
    else{
      if(li->size == 1){
        free(li->begin);
        li->begin =  NULL;
        li->end =   NULL;
        li->size = 0;
      }
      else{
        li->begin = li->begin->next;
        free(li->begin->prev);
        li->begin->prev = NULL;
        li->size--;
      }
    }
  }
  return SUCCESS;
}

int list_pop_back(TDLinkedList *li){//remove final
  if (li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
    else{
      if(li->size == 1){
        free(li->end);
        li->end = NULL;
        li->begin = NULL;
        li->size--;
      }
    else{
      li->end = li->end->prev;
      free(li->end->next);
      li->end->next = NULL;
      li->size--;
    }
    }
  }
  return SUCCESS;

}

int list_erase(TDLinkedList *li, int pos){//remove posição
  if (li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    list_node *aux, *prev;
    aux = li->begin;
    int i = 1;
    if(pos > li->size){
      return OUT_OF_RANGE;
    }
    else{
    if(pos == 0){
      return OUT_OF_RANGE;
    }
    else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
    else{
    if(pos == 1){
      li->begin = li->begin->next;
      free(li->begin->prev);
      li->begin->prev = NULL;
      li->size--;
    }
    else{
      if(pos == li->size){
        li->end = li->end->prev;
        free(li->end->next);
        li->end->next = NULL;
        li->size--;
      }

    
    else{
      while(i < pos ){
      aux = aux->next;
      i++;
      }
      aux->prev->next = aux->next;
      aux->next->prev = aux->prev;
      free(aux);
      li->size--;

    }
    }
    }
    }
  }
  }
  return SUCCESS;

}

int list_erase_mat(TDLinkedList *li, int mat){//remove matricula
  if (li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    list_node *aux, *prev;
    aux = li->begin;
    int i = 0;
    while(aux != NULL && aux->data.matricula != mat){
      aux = aux->next;
      i++;
    }
    if(aux == NULL){
      return OUT_OF_MEMORY;
    }
    else{
      if(li->size == 0){
        return OUT_OF_RANGE;
    }
    
    else{
      if(i == 1){
        li->begin = aux->next;
        free(aux);
        li->begin->prev = NULL;
        li->size--;
      }
    else{
      if(i == li->size){
        li->end = aux->prev;
        free(aux);
        li->end->next = NULL;
        li->size--;
      }
    else{
      aux->prev->next = aux->next;
      aux->next->prev = aux->prev;
      free(aux);
      li->size--;
    }
    }
    }
    }
  return SUCCESS;  
  }
}

int list_find_pos(TDLinkedList *li, int pos, struct aluno *al){//consultar aluno posição
  if (li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    list_node *aux, *prev;
    aux = li->begin;
    int i = 1;
    if(pos > li->size){
      return OUT_OF_RANGE;
    }
    else{
    if(pos == 0){
      return OUT_OF_RANGE;
    }
    else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
    else{
      while(aux != NULL && i < pos + 1 ){
        aux = aux->next;
        i++;
      }
      if(aux == NULL){
        return OUT_OF_RANGE;
      }
      *al = aux->data; 
    }
  }
  }
  return SUCCESS;
  }  
}

int list_find_mat(TDLinkedList *li, int nmat, struct aluno *al){//consultar aluno matricula
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
  else{
    list_node *aux;
    aux = li->begin;
    while(aux != NULL && aux->data.matricula != nmat){
      aux = aux->next;
    }
    *al = aux->data;

  }
  }
  return SUCCESS;
}

int list_front(TDLinkedList *li, struct aluno *al){//consultar elemento da frente 
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
  else{
    list_node *aux;
    aux = li->begin;
    *al = aux->data;

  }
  }
return SUCCESS;

}

int list_back(TDLinkedList *li, struct aluno *al){//consultar ultimo elemento 
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
  else{
    *al = li->end->data;
  }
  return SUCCESS;
  }  
}

int list_get_pos(TDLinkedList *li, int nmat, int *pos){//consultar em qual posição está uma matrícula 
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
    else{
      list_node *aux;
      aux = li->begin;
      int i = 1;
      while(aux != NULL && aux->data.matricula != nmat){
        aux = aux->next;
        i++;
      }
      if(aux == NULL){
        return OUT_OF_RANGE;
      }
      *pos = i;
    }
  }
  return SUCCESS;
}

int list_print_forward(TDLinkedList *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
  else{
  list_node *aux = li->begin;
  while(aux != NULL){
    printf("Matricula: %d\n",  aux->data.matricula);
    printf("Nome: %s\n",   aux->data.nome);
    printf("Notas: %.3f %.3f %.3f\n",aux->data.n1,aux->data.n2,aux->data.n3); 
    printf("-------------------------------\n"); 
    aux = aux->next;
  }
  }
  }
  return SUCCESS;
}

int list_print_reverse(TDLinkedList *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  else{
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
  else{
  list_node *aux = li->end;
  while(aux != NULL){
    printf("Matricula: %d\n",  aux->data.matricula);
    printf("Nome: %s\n",   aux->data.nome);
    printf("Notas: %.3f %.3f %.3f\n",aux->data.n1,aux->data.n2,aux->data.n3); 
    printf("-------------------------------\n"); 
    aux = aux->prev;
  }
  }
  }
  return SUCCESS;
}