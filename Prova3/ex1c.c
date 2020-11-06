int list_splice(List *dest, List *source, int pos){
    if(dest == NULL){
        return -1;
    }
    if(source == NULL){
        return -1;
    }
    if(pos <= 0 || pos > dest->size + 1){
        return -1;
    }
    else{
    dlnode *aux;
    if(pos == dest->size || pos == dest->size +1){
        dest->end->next = source->begin;
        source->begin->prev = dest->end;
        dest->end = source->end;
        source->begin = NULL;
        source->end = NULL;
        dest->size = dest->size + source->size;
        source->size = 0;
    }
    else{
        if(pos == 1){
            dest->begin->prev = source->next;
            source->end->next = dest->begin;
            dest->begin = source->begin;
            source->begin = NULL;
            source->end = NULL;
            dest->size = dest->size + source->size;
            source->size = 0;
        }
    else{
    aux = dest->begin;
    int i = 1;
    while(i < pos){
        aux = aux->next;
        i++;
    }
    aux->next = source->begin;
    source->begin->prev = aux;
    source->end->next = aux->next->prev;
    aux->next->prev = source->end;
    source->begin = NULL;
    source->end = NULL;
    dest->size = dest->size + source->size;
    source->size = 0;

}
    



}
}
return 0;//sucesso
}