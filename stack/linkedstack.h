#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 //sempre que a função receber null
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4
#define ERRO_SORTED -5


typedef struct Stack Stack;
#include "../common/alunos.h"

Stack *create_stack();
int stack_free(Stack *st);//libera lista
int stack_push(Stack *st, struct aluno al);//insere no final
int stack_pop(Stack *st);//remove final
int stack_find_pos(Stack *st, int pos, struct aluno *al);//consulta topo
int stack_size(Stack *st);//ver tamanho ou se está vazia