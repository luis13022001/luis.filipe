#include <stdio.h>
#include <stdlib.h>
#include "linkedstack2.h"
#include "../TLinkedlist2/TLinkedList.h"


struct Stack{
    TLinkedList *data;    
};


Stack *create_stack(){
    Stack *st;
    st = malloc(sizeof(Stack));
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        st->data = list_create();
        if(st->data == NULL){
            free(st);
            return INVALID_NULL_POINTER;
        }
    }

    return st;
}


int stack_push(Stack *st, struct aluno al){//insere final
    if(st == NULL){//
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_push_back(st->data,al);
    }

}


int stack_pop(Stack *st){//remove final
    if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_pop_back(st->data);
    }
}

int stack_size(Stack *st){//tamanho da pilha
    if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_size(st->data);
    }


}

int stack_find_pos(Stack *st, int pos, struct aluno *al){//consultar topo
     if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return list_back(st->data,al);
    }

}

int stack_free(Stack *st){//libera lista e pilha
 if(st == NULL){
   return -1;
 }else{
  list_free(st->data);  
  free(st);   
  return SUCCESS;
 }
}