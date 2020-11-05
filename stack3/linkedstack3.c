#include <stdio.h>
#include <stdlib.h>
#include "linkedstack3.h"

struct Stack{
    char* data;
    int max;
    int pos;
};

Stack *create_stack(int n){
    Stack *st;
    st = malloc(sizeof(Stack));
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        st->data = malloc(n * sizeof(char));
        if(st->data != NULL){
            st->max = n;
            st->pos = 0;
        } else {
            free(st);
            return INVALID_NULL_POINTER;
        }
    }

    return st;
}

int stack_push(Stack *st, char ch){//insere final
    if(st == NULL){//
        return INVALID_NULL_POINTER;
    }
    else{
        if(st->pos < st->max){
            st->data[st->pos++] = ch;//aumenta contador
        } else {
            return -100;
        }
    }
    return 0;
}

int stack_pop(Stack *st){//remove final
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        if(st->pos == 0){
            return -100;
        } else {
            st->pos--;
        }
    }
    return 0;
}

int stack_size(Stack *st){//tamanho da pilha
    if(st == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        return st->pos;
    }
}

int stack_top(Stack *st, char *ch){//consultar topo
     if(st == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        if(st->pos == 0){
            return -100;
        } else {
            *ch = st->data[st->pos-1];
        }
        return ;
    }
}
