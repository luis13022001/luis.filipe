#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#include "../TLinkedlist2/TLinkedList.h"

struct TQueue{
    TLinkedList *data;  
};

TQueue *create_fila(){
TQueue *fl;
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

int enqueue(TQueue *fl, struct aluno al){//insere final
    if(fl == NULL){//
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_push_back(fl->data,al);
    }

}

int dequeue(TQueue *fl){//remove comeco
    if(fl == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_pop_front(fl->data);
    }
}



int size_queue(TQueue *fl){//tamanho da pilha
    if(fl == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_size(fl->data);
    }


}

int queue_front(TQueue *fl,struct aluno *al){//consultar topo
     if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_front(st->data,al);
    }

}

int free_queue(TQueue *fl){//libera lista e pilha
 if(fl == NULL){
   return -1;
 }else{
  list_free(fl->data);  
  free(fl);   
  return SUCCESS;
 }
}

int print_queue(TQueue *fl){
    if(fl == NULL){
   return -1;
 }else{
    list_print(fl->data);
 }
 return SUCCESS;
}