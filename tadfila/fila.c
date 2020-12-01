#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#include "../TLinkedlist2/TLinkedList.h"

struct Fila{
    TLinkedList *data;  
};

Fila *create_fila(){
Fila *fl;
    fl = malloc(sizeof(Fila));
    if(fl == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        fl->data = list_create();
        if(fl->data == NULL){
            free(fl);
            return INVALID_NULL_POINTER;
        }
    }

    return fl;
}

int fila_push(Fila *fl, struct aluno al){//insere final
    if(fl == NULL){//
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_push_back(fl->data,al);
    }

}

int fila_pop_front(Fila *fl){//remove comeco
    if(fl == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_pop_front(fl->data);
    }
}



int fila_size(Fila *fl){//tamanho da pilha
    if(fl == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_size(fl->data);
    }


}

int fila_find(Fila *fl,struct aluno *al){//consultar topo
     if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_front(st->data,al);
    }

}

int fila_free(Fila *fl){//libera lista e pilha
 if(fl == NULL){
   return -1;
 }else{
  list_free(fl->data);  
  free(fl);   
  return SUCCESS;
 }
}