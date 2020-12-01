#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 //sempre que a função receber null
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4


#include "../common/alunos.h"

typedef struct Fila Fila;


Fila *create_fila();
int fila_free(Fila *fl);
int fila_push(Fila *fl, struct aluno al);//insere no final
int fila_pop_front(Fila*fl);//remove inicio
int fila_size(Fila *fl);//tamanho da fila ou se está vazia
int fila_find(Fila *fl,struct aluno *al);//consulta o elemento do começo da fila