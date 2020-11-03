#include <stdio.h>
#include "TDLinkedList.h"
#include <stdlib.h>
#include <string.h>

void opção(void)
{
    printf("1 - Criar a Lista  \n");
    printf("2 - Consultar lista posição  \n");
    printf("3 - Consultar lista matricula  \n");
    printf("4 - insere no final da lista   \n");
    printf("5 - insere no inicio da lista  \n");
    printf("6 - imprime lista reversa  \n");
    printf("7 - remove aluno pela posição  \n");
    printf("8 - remove a 1° posição da lista  \n");
    printf("9 - Tamanho da lista  \n");
    printf("10 - Consulta cabeça da lista \n");
    printf("11 - consulta ultimo elemento da lista \n");
    printf("12 - Imprime Lista \n");
    printf("13 - Ver qual posição está uma matricula \n");
    printf("14 - Liberar Lista \n");
    printf("15 - remove ultima posição \n");
    printf("16 - remove matricula \n");
    printf("0 - Sair \n\n");
}
unsigned int pegaropcao(void)
{
    
    unsigned int valor = 0;
    printf("Escolha uma opção: ");
    scanf("%u", &valor); //ler o valor da opção
    while ( !(valor >= 0 && valor <= 16))
    {
    printf("opção inválida!\n");
    printf("Digite uma opção: ");
    scanf("%d", &valor);
    printf("\n\n");
    }
    return valor;
}
void menu()
{
    TDLinkedList *alunos_ic;
    struct aluno al;
    int qtd,tam;
    int ret;
    int val;
    int pos, mat;
    while(1){
        opção();
        switch (pegaropcao())
    {

        case 1:
  alunos_ic= list_create();
  struct aluno b[10] = {{1,"Izaac",7.0,8.0,9.0},
                          {2,"Luis",7.5,8.7,6.8},
                          {3,"Gabriel",9.7,6.7,8.4},
                          {4,"Carlos",5.7,6.1,7.4},
                          {5,"Fabiola",9.0,5.1,8.4},
                          {6,"Mariana",6.7,6.4,7.5},
                          {7,"Gabriella",4.7,9.1,7.8},
                          {8,"Mila",8.7,6.8,7.5},
                          {9,"Heitor",6.5,6.8,9.4},
                          {10,"Bruno",9.7,7.3,8.6}};

printf("Tamanho da lista que deseja criar (valor minimo  10)? ");
  scanf("%d", &tam);
    if (tam<10){
      printf("\nError!\n\n");
        return menu();
    }
    TDLinkedList* alunos_ic = list_create(tam);
      for(int i=0; i< 10; i++){
        list_push_back(alunos_ic, b[i]);
      }
    list_print_forward(alunos_ic);
break;  

    case 2:
 
    printf("qual posição voce deseja saber? ");
    scanf("%d", &pos);
    list_find_pos(alunos_ic,pos,&al);
    if(ret == -1 ){
      printf("ERRO! lista não alocada\n");
      break;
    }
    else if(ret == -4){
      printf("ERRO! não encontrou matricula\n");
      break;
    }
    else{
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
    printf("notas P1, P2, P3: %.3f, %.3f, %.3f\n", al.n1, al.n2, al.n3);
    break;
    }
break;


    case 3:
    printf("qual matricula voce deseja saber? ");
    scanf("%d", &mat);
    list_find_mat(alunos_ic,mat,&al);
    if(ret == -1 ){
      printf("ERRO! lista não alocada\n");
      break;
    }
    else if(ret == -4){
      printf("ERRO! não encontrou matricula\n");
      break;
    }
    else{
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
     printf("notas P1, P2, P3: %.3f, %.3f, %.3f\n", al.n1, al.n2, al.n3);
    break;
    }
  break;

    case 4: 
    printf("qual nome do aluno? ");
    scanf("%s", al.nome);
    printf("qual numero de matricula? ");
    scanf("%d", &al.matricula);
    printf("quais foram suas notas na P1, P2 e P3: \n");
    scanf("%f", &al.n1);
    scanf("%f", &al.n2);
    scanf("%f", &al.n3);
    ret = list_push_back(alunos_ic, al);
    if( ret== -1 ){
      printf("ERRO!\n");
    }
break;

    case 5:
    printf("qual nome do aluno? ");
    scanf("%s", al.nome);
    printf("qual numero de matricula? ");
    scanf("%d", &al.matricula);
    printf("quais foram suas notas na P1, P2 e P3: \n");
    scanf("%f", &al.n1);
    scanf("%f", &al.n2);
    scanf("%f", &al.n3);
    ret = list_push_front(alunos_ic, al);
    if( ret == -1 ){
      printf("ERRO!\n");
    }
break;
/*
    case 6:
    printf("qual nome do aluno? ");
    scanf("%s", al.nome);
    printf("qual numero de matricula? ");
    scanf("%d", &al.matricula);
    printf("quais foram suas notas na P1, P2 e P3: \n");
    scanf("%f", &al.n1);
    scanf("%f", &al.n2);
    scanf("%f", &al.n3);
    ret = list_insert_sorted(alunos_ic,al);
   if( ret == -1){
   printf("ERRO!\n");
   }
   list_print(alunos_ic);
break;
*/
    case 6:
    list_print_reverse(alunos_ic);
    printf("\n\n");
break;
    case 7:
    printf("qual posição voce deseja remover? ");
     scanf("%d", &pos);
     ret = list_erase(alunos_ic,pos);
     if(ret == -1 ){
       printf("ERRO! -1\n");
     }
     if(ret == -3){
       printf("ERRO! -3\n");
     }
     list_print_forward(alunos_ic);

   
break;

    case 8:
     list_pop_front(alunos_ic);
     list_print_forward(alunos_ic);
    printf("\n");

break;

    case 9:
    qtd = list_size(alunos_ic);
    printf("\nO tamanho da lista é %d\n\n", qtd);
break;

    case 10:
    ret =list_front(alunos_ic,&al);
    
    if(ret == -1){
      printf("Erro. lista não alocada ou não preenchida\n\n");
    }
    else{
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
    printf("notas P1, P2, P3: %.3f, %.3f, %.3f\n", al.n1, al.n2, al.n3);
    break;
    }


break;


    case 11:
    
    ret = list_back(alunos_ic,&al);
    if(ret == -1){
      printf("Erro. lista não alocada ou não preenchida\n\n");
    }
    else if(ret == -3){
      printf("Erro. não tem nenhum elemento na lista\n\n");
    }
    else{
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
    printf("notas P1, P2, P3: %.3f, %.3f, %.3f\n", al.n1, al.n2, al.n3);
    }


break;

 case 12: 

  list_print_forward(alunos_ic);
  printf("\n");

break;

  case 13:

  printf("qual matricula voce deseja saber a posição? ");
    scanf("%d", &mat);
  ret = list_get_pos(alunos_ic, mat, &pos);
  if(ret == -1){
    printf("ERROOO!!\n\n");
  }
  printf("A posição é %d\n\n", pos);

break;
    case 14:
    list_free(alunos_ic);

break;

    case 15:
    printf("\n");
    list_pop_back(alunos_ic);
    list_print_forward(alunos_ic);

break;
    case 16:
    printf("qual matricula voce deseja remover? ");
    scanf("%d", &mat);
    ret = list_erase_mat(alunos_ic, mat);
    if(ret == -1){
      printf("ERROOO!!\n\n");
    }
    else if(ret == -3){
      printf("não há elementos na matriz!!\n\n");
    }
    else{
      printf("elemento removido com sucesso!!\n\n");
    }

break;

    case 0:

return;//sair do programa
break;
    }
    }
}

int main(void)
{
    menu();
    return 0;
}
