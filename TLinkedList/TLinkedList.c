#include <stdlib.h>
#include "TLinkedList.h"
#include <stdio.h>

typedef struct list_node list_node;


struct list_node{
    struct aluno data;    
    list_node *next;
};

typedef struct TLinkedList{   
    list_node *head;// ponteiro pro primeiro dado da TLinkedList
    
}TLinkedList; 


TLinkedList* list_create(){//criar lista

    TLinkedList *li;
    li = malloc(sizeof(TLinkedList));
    if(li == NULL){
        return li;
    }
    li->head = NULL;// TLinkedList vazia tem que apontar para nulo pois ela nao tem elementos

    return li;

}
int list_free(TLinkedList *li){//liberar lista
    if(li == NULL){
      return INVALID_NULL_POINTER;
    }
    list_node *aux = li->head;
    list_node *previous = NULL;
    while(aux != NULL){
      previous = aux;
      aux = aux->next;
      free(previous);//liberar cada posição
    }
    free(li);
    return SUCCESS;
}
int  list_push_front(TLinkedList* li, struct aluno al){//insere começo
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }
    list_node *novo_no = malloc(sizeof(struct list_node));
    if(novo_no == NULL){//verificar se foi alocado
        return -1;
    }
    novo_no->data = al; // ARMAZENAR o dado que entrou
    novo_no->next = li->head;//mover o elemento que estava na cabeça da lista
    li->head = novo_no;//adicionar o elemento na cabeça da lista

    return 0;
}

int list_push_back(TLinkedList* li, struct aluno al){//insere no final
    if(li == NULL){
        return INVALID_NULL_POINTER;
    }
    list_node *novo_no = malloc(sizeof(struct list_node));
    if(novo_no == NULL){//verificar se foi alocado
        return -1;
    }
    novo_no->data = al; // ARMAZENAR o dado que entrou
    novo_no->next = NULL;//mostrar que o prox elemento depois do elemento inserido vai ser igual a NULL

    if(li->head == NULL){
        li->head = novo_no;
        return 0;
    }


    list_node *aux = li->head;//para nao mexer com a cabeça criamos um auxiliar para andar na lista

    while(aux->next != NULL){//andar no vetor até achar o final da lista
        aux = aux->next;
    }
    
    aux->next = novo_no;

    return 0;

}
int list_insert(TLinkedList *li, int pos, struct aluno al){//inserir em uma posição
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
    if(li->head == NULL){
      node->next = NULL;//proximo elemento recebe null para informar final da lista
      li->head = node;// a cabeça aponta pro novo no
    } else{
    //a lista possui pelo menos 1 elemento
    list_node *aux,*previous; // prev apontar para o elemento anterior
    aux = li->head;//andar na lista precisa do auxiliar
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
    if(li->head == NULL){
      node->next = NULL;//proximo elemento recebe null para informar final da lista
      li->head = node;// a cabeça aponta pro novo no
    } else{
      //a lista possui pelo menos 1 elemento
      list_node *aux,*previous; // prev apontar para o elemento anterior
      aux = li->head;//andar na lista precisa do auxiliar
      while(aux != NULL && aux->data.matricula < al.matricula){//aux != NULL para verificar se chegamos no final da lista
        previous = aux;// pegar posição anterior para colocar o valor no lugar correto
        aux = aux->next;//vai alterar o aux e vai apontar para o prox

      }
      if( aux == li->head){
        node->next = li->head;
        li->head = node;
      }else{
      previous->next = node;//previou vai receber endedereço do nó(node)
      node->next = aux;// e o node na proxima posição recebe o aux
    }
    }
    return SUCCESS;
  }
  }
}




int list_size(TLinkedList *li){
    if(li == NULL){
    return INVALID_NULL_POINTER;//mudar codigo de erro
  }
  list_node *aux = li->head;
  int i = 0;
  if(aux == NULL){
    return OUT_OF_RANGE;
  }
  while(aux != NULL){
    aux = aux->next;
    i++;
  }
  return i;
}

int list_pop_front(TLinkedList *li){//remova começo
    if(li == NULL){
      return INVALID_NULL_POINTER;
    }
    list_node *aux = li->head;//aux recebe a cabeça
    li->head = aux->next;//cabeça recebe a proxima posição

    free(aux);

    return SUCCESS;
}


int list_pop_back(TLinkedList* li){// remove final
    if(li == NULL){
      return INVALID_NULL_POINTER;
    }
    if(li->head->next == NULL){
        free(li->head);
        li->head = NULL;
    }
    list_node *previous; 
    list_node *aux = li->head;//aux recebe a cabeça
    while(aux->next != NULL){
      previous = aux;
      aux = aux->next;
    }
    previous->next = NULL;
    free(aux->next);
    return SUCCESS;
}


int list_erase(TLinkedList *li, int pos){//remover posição
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux,*previous; // prev apontar para o elemento anterior
  aux = li->head;//andar na lista precisa do auxiliar
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
  previous->next = aux->next;//apontar para o proximo da posição que foi removida(aux);
  free(aux);//remover a posição
  return SUCCESS;
}

int list_erase_mat(TLinkedList *li, int nmat){
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux,*previous; // prev apontar para o elemento anterior
  aux = li->head;//andar na lista precisa do auxiliar
 
  int i = 1;
  while(aux->data.matricula != nmat){
    previous = aux;
    aux = aux->next;
    i++;
  }
  if(aux == NULL){
    return OUT_OF_RANGE;
  }
  previous->next = aux->next;
  free(aux);
  return SUCCESS;
}


int list_find_pos(TLinkedList *li, int pos, struct aluno *al){//consulta pos
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux; // prev apontar para o elemento anterior
  aux = li->head;//andar na lista precisa do auxiliar
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
  aux = li->head;//andar na lista precisa do auxiliar
  while(aux != NULL && aux->data.matricula != nmat ){
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
  if(li->head == NULL){
     return INVALID_NULL_POINTER;
  }
  list_node *aux;
  aux = li->head;
  *al = aux->data;  
 
 return SUCCESS;
}


int list_back(TLinkedList *li, struct aluno *al){// ver ultimo elemento 
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  if(li->head == NULL){
    return OUT_OF_RANGE;
  }
  list_node *aux;
  aux = li->head;
  while(aux->next != NULL){// pegar a prox posição para nao dar erro e acabar pegando o nó NULL
    aux = aux->next;
  }
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
  aux = li->head;//andar na lista precisa do auxiliar
  if(nmat == aux->data.matricula){
    return SUCCESS;
  }
  while(nmat != aux->data.matricula){
    aux = aux->next;// andar vetor
    i++;
    *pos = i;
  }
 
  return SUCCESS;
}




int list_print(TLinkedList *li){
  if(li == NULL){
    return INVALID_NULL_POINTER;// lista não alocada
  }
  list_node *aux = li->head;
  while(aux != NULL){
    printf("Matricula: %d\n",  aux->data.matricula);
    printf("Nome: %s\n",   aux->data.nome);
    printf("Notas: %.3f %.3f %.3f\n",aux->data.n1,aux->data.n2,aux->data.n3); 
    printf("-------------------------------\n"); 
    aux = aux->next;
  }

return SUCCESS;
}