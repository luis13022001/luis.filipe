#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 //sempre que a função receber null
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4
#define FULL 2


#include "../common/alunos.h"

typedef struct TQueue TQueue;


TQueue *create_queue();
int free_queue(TQueue *fl);
int fila_push(TQueue *fl, struct aluno al);//insere no final
int fila_pop_front(TQueue*fl);//remove inicio
int size_queue(TQueue* fl)//tamanho da fila ou se está vazia
int queue_front(TQueue *fl, struct student *al);//consulta o elemento do começo da fila
int print_queue(TQueue *fl);
int compact_queue(TQueue* fl);
int queuefull(TQueue* fl);//ver se está full