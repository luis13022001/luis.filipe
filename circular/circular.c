#include <stdlib.h>
#include <stdio.h>
#include "circular.h"

typedef struct list_node list_node;


struct list_node{
    struct aluno data;    
    list_node *next;
};

typedef struct TLinkedList {   
  list_node *end;
  list_node *nextno;
  int size; // quantidade de elementos na lista 
  int sorted; // indica se a lista é ordenada 
  }TLinkedList;  


TLinkedList* list_create(){//criar lista
    TLinkedList *li;
    li = malloc(sizeof(TLinkedList));
    if(li == NULL){
        return li;
    }
    li->end = NULL;
    li->size = 0;
    li->nextno = NULL;
    li->sorted = 0;
    
    // TLinkedList vazia tem que apontar para nulo pois ela nao tem elementos

    return li;

}
int list_free(TLinkedList *li){//liberar lista
    if(li == NULL){
      return INVALID_NULL_POINTER;
    }
    list_node *aux = li->end;
    list_node *previous = NULL;
    int i =0;
    while(i < li->size){
      previous = aux;
      aux = aux->next;
      free(previous);//liberar cada posição
    }
    li->size = 0;
    free(li);
    return SUCCESS;
}
int  list_push_front(TLinkedList* li, struct aluno al){//insere começo
  if(li == NULL){
    return INVALID_NULL_POINTER;
    }
  if(li->sorted == 1){
    return ERRO_SORTED;
  }

    list_node *node = malloc(sizeof(struct list_node));
    node->data = al; // ARMAZENAR o dado que entrou
    if(node == NULL){//verificar se foi alocado
        return -1;
    }
    else if(li->size == 0){
      li->end = node;
      li->end->next = node;
      li->size++;
    }
    else{
    node->next = li->end->next;
    li->end->next = node;
    li->size++;
    }
    return SUCCESS;
}

int list_push_back(TLinkedList* li, struct aluno al){//insere no final
  if(li == NULL){
    return INVALID_NULL_POINTER;
    }
  if(li->sorted == 1){
    return ERRO_SORTED;
  }    
    list_node *node = malloc(sizeof(struct list_node));
    if(node == NULL){//verificar se foi alocado
        return -1;
    }
    if(li->size == 0){
    node->data = al;
    li->end = node;
    li->end->next = node;
    }
    else{
    list_node *aux;
    node->data = al; // ARMAZENAR o dado que entrou

    node->next = li->end->next;//novo nó aponta para começo da lista
    li->end->next = node;
    li->end = node;
    }
    li->size++;
    return SUCCESS;

}
int list_insert(TLinkedList *li, int pos, struct aluno al){//inserir em uma posição
  if(li == NULL){
    return INVALID_NULL_POINTER;//mudar codigo de erro
  }
  if(li->sorted == 1){
    return ERRO_SORTED;
  }
  else{
    list_node *node = malloc(sizeof(list_node));
  if(node == NULL){
    return OUT_OF_MEMORY;
  } else{
    node->data = al;//receber os valores no nó
    //teste se a lista está vazia
    if(li->size == 0){
      li->end = node;
      li->end->next = node;
    }
    else if(pos == 1){
    node->next = li->end->next;
    li->end->next = node;
    }
    else if (pos == li->size){
    node->next = li->end->next;//novo nó aponta para começo da lista
    li->end->next = node;
    li->end = node;
    } 
    else{
    //a lista possui pelo menos 1 elemento
    list_node *aux,*previous; // prev apontar para o elemento anterior
    aux = li->end->next;
    int i = 0;
    while(pos > i){
      previous = aux;
      aux = aux->next;
      i++;
    }
  previous->next = node;//previou vai receber endedereço do nó(node)
  node->next = aux;// e o node na proxima posição recebe o aux 
}
}
}
li->size++;
return SUCCESS;
}


int list_insert_sorted(TLinkedList *li, struct aluno al){//insere em lista ordenada
  if(li == NULL){
    return INVALID_NULL_POINTER;//mudar codigo de erro
  }
  else{
    list_node *node = malloc(sizeof(list_node));
  if(node == NULL){
    return OUT_OF_MEMORY;
  } else{
    node->data = al;//receber os valores no nó
    //teste se a lista está vazia
    if(li->size == 0){
      li->end = node;
      li->end->next = node;
    } else{
      //a lista possui pelo menos 1 elemento
      list_node *aux,*previous; // prev apontar para o elemento anterior
      aux = li->end->next;//andar na lista precisa do auxiliar
      int i = 1;
      while(i < li->size && aux->data.matricula < al.matricula){//aux != NULL para verificar se chegamos no final da lista
        previous = aux;// pegar posição anterior para colocar o valor no lugar correto
        aux = aux->next;//vai alterar o aux e vai apontar para o prox
        i++;

      }
      if( aux == li->end->next){
    node->next = li->end->next;
    li->end->next = node;

      }
      else if( aux == li->end){
    node->next = li->end->next;//novo nó aponta para começo da lista
    li->end->next = node;
    li->end = node;

      }
    else{
      previous->next = node;//previou vai receber endedereço do nó(node)
      node->next = aux;// e o node na proxima posição recebe o aux
    }
    }
    li->size++;
    li->sorted = 1;
    return SUCCESS;
  }
  }
}




int list_size(TLinkedList *li){//tamanho da lista
    if(li == NULL){
    return INVALID_NULL_POINTER;//mudar codigo de erro
  }
  return li->size;
}

int list_pop_front(TLinkedList *li){//remova começo
    if(li == NULL){
      return INVALID_NULL_POINTER;
    }
    if(li->size == 0){
      return OUT_OF_RANGE;
    }
  list_node *aux = li->end->next;
  li->end->next = aux->next;
  li->size--;
  free(aux);
    return SUCCESS;
}


int list_pop_back(TLinkedList* li){// remove final
    if(li == NULL){
      return INVALID_NULL_POINTER;
    }
    if(li->size == 1){
        free(li->end);
        free(li->end->next);
        li->end = NULL;
        li->end->next = NULL;
        //li->end->next = li->head;
        li->size--;
        return SUCCESS;
    }
    list_node *previous; 
    list_node *aux = li->end->next;//aux recebe a cabeça
    /*int i = 1;
    while(i < li->size){
      previous = aux;
      aux = aux->next;
      i++;
    }
*/
    while(aux != li->end){
      previous = aux;
      aux = aux->next;
    }
    
    previous->next = li->end->next;
    li->end = previous;
    free(aux);
    li->size--;
    return SUCCESS;
}


int list_erase(TLinkedList *li, int pos){//remover posição
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux,*previous; // prev apontar para o elemento anterior
  aux = li->end->next;//andar na lista precisa do auxiliar
  int i = 1;
  while(i < pos){
    previous = aux;
    aux = aux->next;
    i++;
  }
  if(pos > i){
    return OUT_OF_RANGE;
  }
  else if(pos < i){
    return OUT_OF_RANGE;//não tem essa posição
  } 
  else if (li->size == 1){
    free(li->end);
    free(li->end->next);
    li->end = NULL;
    li->end->next = NULL;
    li->size--;
    return SUCCESS;

  }
  else if(pos == 1){
    aux = li->end->next;//aux recebe a cabeça
    li->end->next = aux->next;//cabeça recebe a proxima posição

    free(aux);
    li->size--;
  }else if(pos == li->size){
  previous->next = aux->next;
  li->end = previous;
  free(aux);
  li->size--;
  }
  else{

    previous->next = aux->next;
    free(aux);
    li->size--;


  }
    return SUCCESS;
}

int list_erase_mat(TLinkedList *li, int nmat){//remover matricula
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux,*previous; // prev apontar para o elemento anterior
  aux = li->end->next;//andar na lista precisa do auxiliar
 
  int i = 1;
  while(aux->data.matricula != nmat){
    previous = aux;
    aux = aux->next;

    i++;
  }

  if(aux == NULL){
    return OUT_OF_RANGE;
  }
  if(i == 1){
    aux = li->end->next;//aux recebe a cabeça
    li->end->next = aux->next;//cabeça recebe a proxima posição

    free(aux);
    li->size--;
  }else if(i == li->size){
  previous->next = aux->next;
  li->end = previous;
  free(aux);
  li->size--;
  }
  else{

    previous->next = aux->next;
    free(aux);
    li->size--;


  }
  return SUCCESS;
}


int list_find_pos(TLinkedList *li, int pos, struct aluno *al){//consulta pos
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux; // prev apontar para o elemento anterior
  aux = li->end->next;//andar na lista precisa do auxiliar
  int i = 1;
  while(i < pos){
    aux = aux->next;
    i++;
  }
  if(pos > i){
    return ELEM_NOT_FOUND;//não tem essa posição
  }
  else if(pos < i){
    return ELEM_NOT_FOUND;//não tem essa posição
  } 
  *al = aux->data;// receber valor do nó
  return SUCCESS;
}

int list_find_mat(TLinkedList *li, int nmat, struct aluno *al){//consulta pela matricula 
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux; // prev apontar para o elemento anterior
  aux = li->end->next;//andar na lista precisa do auxiliar
  int i = 1;
  while(i < li->size && aux->data.matricula != nmat ){
    aux = aux->next;
  }
  if(aux->data.matricula != nmat){
    return ELEM_NOT_FOUND;// elemento não encontrado
  } else{
    *al = aux->data;
  }
  return SUCCESS;

}


int list_front(TLinkedList *li, struct aluno *al){//ver eleemnto 1° posição
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  if(li->end->next == NULL){
     return INVALID_NULL_POINTER;
  }
  list_node *aux;
  aux = li->end->next;
  *al = aux->data;  
 
 return SUCCESS;
}


int list_back(TLinkedList *li, struct aluno *al){// ver ultimo elemento 
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  if(li->end->next == NULL){
    return OUT_OF_RANGE;
  }
    list_node *aux;
  aux = li->end;

  *al = aux->data;

  return SUCCESS;
}

int list_get_pos(TLinkedList *li, int nmat, int *pos){// ver qual posição está uma matricula
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  int i = 1;
  *pos = i;
  list_node *aux; // prev apontar para o elemento anterior
  aux = li->end->next;//andar na lista precisa do auxiliar
  if(nmat == aux->data.matricula){
    return SUCCESS;
  }
  while(nmat != aux->data.matricula){
    aux = aux->next;// andar vetor
    i++;
    *pos = i;
    if(i >= li->size){
        return OUT_OF_RANGE;
    }
  }
 
  return SUCCESS;
}

int list_next(TLinkedList *li, struct aluno *al){
  if(li == NULL){
    return INVALID_NULL_POINTER;
  }
  if(li->size == 0){
    return OUT_OF_RANGE;
  }
  if(li->size == 1){
  li->nextno = li->end->next;
  }
  else{
 li->nextno = li->nextno>next;
  }
  *al = li->nextno->data;
 

  return SUCCESS;
}





int list_print(TLinkedList *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux = li->end->next;
  int i = 0;
  while(i < li->size ){
    printf("Matricula: %d\n",  aux->data.matricula);
    printf("Nome: %s\n",   aux->data.nome);
    printf("Notas: %.3f %.3f %.3f\n",aux->data.n1,aux->data.n2,aux->data.n3); 
    printf("-------------------------------\n"); 
    aux = aux->next;
    i++;
  }

return SUCCESS;
}