int verifica(char string[]){
    Stack *st;
    for(int i = 0; i<strlen(string); i++){
        char aux = string[i];
        char top;
        switch(aux){
            case ')':
                if(stack_size(st) == 0){
                    return -1;
                }
                stack_top(st, &top);
                if(top != '('){
                    return -1;
                }else {
                    stack_pop(st);
                }
                break;

            case ']':
                if(stack_size(st) == 0){
                    return -1;
                }
                stack_top(st, &top);
                if(top != '['){
                    return -1;
                }else {
                    stack_pop(st);
                }
                break;

            default:
                stack_push(st, aux);
        }
    }

    if(stack_size(st) != 0){
        return -1;
    }

    return 0;
}