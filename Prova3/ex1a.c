
int list_erase_even(List *li){
  if(li == NULL){
    return -1;
  }
  else if(li->size == 0){
    return -1;
  }
  else{
    dlnode *aux;
    aux = li->begin;
    int i = 1;
    int x;
    while(aux != NULL){
      if(aux->data % 2 == 0){
        x =list_erase(li,i);//essa função dá o free, aloca os ponteiros e também diminui da lista se for par como está no if e testa os casos base
        if(x == -1){
          return -1;
        }
      }
      aux = aux->next;
      i++;
    }

  }
  return 0;
}