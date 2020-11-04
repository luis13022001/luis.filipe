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

            return INVALID_NULL_POINTER;
        }
    }

}