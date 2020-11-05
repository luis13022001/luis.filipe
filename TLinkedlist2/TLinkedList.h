#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 //sempre que a função receber null
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4
#define ERRO_SORTED -5
#include "../common/alunos.h"

typedef struct TLinkedList TLinkedList;

TLinkedList* list_create();//fiz
int list_free(TLinkedList *li);//fiz
int list_push_front(TLinkedList *li, struct aluno al);//insere no começo (fiz)
int list_push_back(TLinkedList *li, struct aluno al); // insere no final(fiz)
int list_insert(TLinkedList *li, int pos, struct aluno al); //isere posição (fiz)
int list_insert_sorted(TLinkedList *li, struct aluno al); //insere lista ordenada
int list_size(TLinkedList *li);//tamanho anda com for ate achar null i++  (fiz)
int list_pop_front(TLinkedList *li);//remove começo(fiz)
int list_pop_back(TLinkedList *li); //remove final(fiz)
int list_erase(TLinkedList *li, int pos); //remove posição (fiz)
int list_erase_mat(TLinkedList *li, int nmat); //remove matricula
int list_find_pos(TLinkedList *li, int pos, struct aluno *al); //consulta pos(fiz)
int list_find_mat(TLinkedList *li, int nmat, struct aluno *al);//consulta pela matricula (fiz)
int list_front(TLinkedList *li, struct aluno *al);//ver 1° elemento lista 
int list_back(TLinkedList *li, struct aluno *al);// ver ultimo elemento 
int list_get_pos(TLinkedList *li, int nmat, int *pos);// ver qual posição está uma matricula
int list_print(TLinkedList *li);//printar lista 

/*
TLinkedList* list_create();
void libera_lista(TLinkedList* li);
int consulta_lista_pos(TLinkedList* li, int pos, struct aluno *al);
int consulta_lista_mat(TLinkedList* li, int mat, struct aluno *al);
int insere_lista_final(TLinkedList* li, struct aluno al);
int insere_lista_inicio(TLinkedList* li, struct aluno al); 
int insere_lista_pos(TLinkedList* li, int pos, struct aluno al);
int insere_lista_ordenada(TLinkedList* li, struct aluno al);
int remove_lista(TLinkedList* li, int mat);
int remove_lista_inicio(TLinkedList* li);
int remove_lista_final(TLinkedList* li);
int tamanho_lista(TLinkedList* li);
int lista_cheia(TLinkedList* li);
int lista_vazia(TLinkedList* li);
void imprime_lista(TLinkedList* li);
*/

