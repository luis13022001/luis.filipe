#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"
#include "../ListaSequencial/ListaSequencial.h"


struct Stack{
    Lista *data;    
};


Stack *create_stack(){
    Stack *st;
    st = malloc(sizeof(Stack));
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        st->data = cria_lista();
        if(st->data == NULL){
            free(st);
            return INVALID_NULL_POINTER;
        }
    }

    return st;
}

int stack_push(Stack *st, struct aluno al){//insere final
    if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
   
    return  insere_lista_final(st->data,al);
    }
}

int stack_pop(Stack *st){//remove final
    if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
    
    return remove_lista_final(st->data);
    }

}


int stack_find_pos(Stack *st, int pos, struct aluno *al){
    if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
    return consulta_lista_pos(st->data,pos,al);
    }
}

int stack_size(Stack *st){//ver se está vazia ou tamanho
    if(st == NULL){
        return INVALID_NULL_POINTER;    
    }
    else{
        return tamanho_lista(st->data);
    }


}

int stack_free(Stack *st){//libera lsita e pilha
 if(st == NULL){
   return -1;
 }else{
  libera_lista(st->data);  
  free(st);   
  return SUCCESS;
 }
}