#include <stdio.h>
#include "linkedstack3.h"
#include <stdlib.h>
#include <string.h>

int bem_formada(Stack *pilha, char string[]){
    int i = 0;
    for(i = 0; i<strlen(string); i++){
        char aux = string[i];
        char top;
        switch(aux){
            case ')':
                if(stack_size(pilha) == 0){
                    return -1;
                }
                stack_top(pilha, &top);
                if(top != '('){
                    return -1;
                }else {
                    stack_pop(pilha);
                }
                break;

            case ']':
                if(stack_size(pilha) == 0){
                    return -1;
                }
                stack_top(pilha, &top);
                if(top != '['){
                    return -1;
                }else {
                    stack_pop(pilha);
                }
                break;

            default:
                stack_push(pilha, aux);
        }
    }

    if(stack_size(pilha) != 0){
        return -1;
    }

    return 0;
}

char *infixa_posfixa(Stack *pilha, char string[]){
    int n = strlen(string);
    char *posf;
    posf = malloc ((n+1) * sizeof (char));
    int qtdposf = 0;

    for(int i = 0; i < n; i++){
        char aux = string[i];
        char x;
        switch(aux){
            case '(':
                stack_push(pilha, aux);
                break;
            case ')':
                stack_top(pilha, &x);
                stack_pop(pilha);
                while(x != '('){
                    posf[qtdposf++] = x;
                    stack_top(pilha, &x);
                    stack_pop(pilha);
                }
                break;
            case '-':
            case '+':
                stack_top(pilha, &x);
                stack_pop(pilha);
                while(x != '('){
                    posf[qtdposf++] = x;
                    stack_top(pilha, &x);
                    stack_pop(pilha);
                }
                stack_push(pilha, x);
                stack_push(pilha, aux);
                break;
            case '*':
            case '/':
                stack_top(pilha, &x);
                stack_pop(pilha);
                while(x != '(' && x != '+' && x != '-'){
                    posf[qtdposf++] = x;
                    stack_top(pilha, &x);
                    stack_pop(pilha);
                }
                stack_push(pilha, x);
                stack_push(pilha, aux);
                break;
            default:
                posf[qtdposf++] = aux;
        }

    }

   return posf;
}

int eval_posfix(Stack *stack, char posfix[]){
    int i = 0;
    for(i = 0; i<strlen(posfix); i++){
        if(posfix[i] == ' ') continue;

        if(isdigit(posfix[i])){
            int num = 0;
            while(isdigit(posfix[i])){
                num=num*10 + (int)(posfix[i]-'0');
                i++;
            }
            i--;

            stack_push(stack, num);
        } else {

            char val1;
            stack_top(stack, &val1);
            stack_pop(stack);

            char val2;
            stack_top(stack, &val2);
            stack_pop(stack);

            switch (posfix[i]){
                case '+': stack_push(stack, val2 + val1); break;
                case '-': stack_push(stack, val2 - val1); break;
                case '*': stack_push(stack, val2 * val1); break;
                case '/': stack_push(stack, val2/val1); break;
            }
        }
    }

    char retorno;
    stack_top(stack, &retorno);
    stack_pop(stack);
    return retorno;
}

int main(void){
    Stack *pilha = create_stack(100);

    char array[20];

    gets(array);
    puts(array);

/*    int x = bem_formada(pilha, array);
    if(x == 0){
        printf("Eh bem formada");
    } else {
        printf("Nao eh bem formada");
    }*/

    //strcpy(array, infixa_posfixa(pilha, array));
    //puts(array);


    /*Lembrar de alterar tanto as variaveis do eval_posfix quanto a estrutura de dados para float.*/
    printf("%d", eval_posfix(pilha, array));

    return 0;
}
