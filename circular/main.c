#include <stdio.h>
#include "circular.h"
#include <stdlib.h>
#include <string.h>

void opcao(void)
{
    printf("1 - Criar a Lista  \n");
    printf("2 - Consultar lista posicao  \n");
    printf("3 - Consultar lista matricula  \n");
    printf("4 - insere no final da lista   \n");
    printf("5 - insere no inicio da lista  \n");
    printf("6 - insere na lista ordenada  \n");
    printf("7 - remove aluno pela posicao  \n");
    printf("8 - remove a 1° posicao da lista  \n");
    printf("9 - Tamanho da lista  \n");
    printf("10 - Consulta cabeça da lista \n");
    printf("11 - consulta ultimo elemento da lista \n");
    printf("12 - Imprime Lista \n");
    printf("13 - Ver qual posicao esta uma matricula \n");
    printf("14 - Liberar Lista \n");
    printf("15 - remove ultima posicao \n");
    printf("16 - remove matricula \n");
    printf("17 - pegar proximo elemento \n");
    printf("0 - Sair \n\n");
}
unsigned int pegaropcao(void)
{
    
    unsigned int valor = 0;
    printf("Escolha uma opcao: ");
    scanf("%u", &valor); //ler o valor da opcao
    while ( !(0 <= valor && valor <=18))
    {
    printf("opcao invalida!\n");
    printf("Digite uma opcao: ");
    scanf("%d", &valor);
    printf("\n\n");
    }
    return valor;
}
void menu()
{
    TLinkedList *alunos_ic;
    struct aluno al;
    int qtd,tam;
    int ret;
    int val;
    int pos, mat;
    while(1){
        opcao();
        switch (pegaropcao())
    {

        case 1:
  alunos_ic= list_create();

break;  

    case 2:
 
    printf("qual posicao voce deseja saber? ");
    scanf("%d", &pos);
    list_find_pos(alunos_ic,pos,&al);
    if(ret == -1 ){
      printf("ERRO! lista nao alocada\n");
      break;
    }
    else if(ret == -4){
      printf("ERRO! nao encontrou matricula\n");
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
      printf("ERRO! lista nao alocada\n");
      break;
    }
    else if(ret == -4){
      printf("ERRO! nao encontrou matricula\n");
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
    if( ret == -5){
      printf("LISTA ESTÁ ORDENADA!!!!\n\n");
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
    if( ret == -5){
      printf("LISTA ESTÁ ORDENADA!!!!\n\n");
    }

break;

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


    case 7:
    printf("qual posicao voce deseja remover? ");
     scanf("%d", &pos);
     ret = list_erase(alunos_ic,pos);
     if(ret == -1 ){
       printf("ERRO! -1\n");
     }
     if(ret == -3){
       printf("ERRO! -3\n");
     }
     list_print(alunos_ic);

   
break;

    case 8:
     list_pop_front(alunos_ic);
     list_print(alunos_ic);
    printf("\n");

break;

    case 9:
    qtd = list_size(alunos_ic);
    printf("\nO tamanho da lista e %d\n\n", qtd);
break;

    case 10:
    ret =list_front(alunos_ic,&al);
    
    if(ret == -1){
      printf("Erro. lista nao alocada ou nao preenchida\n\n");
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
      printf("Erro. lista nao alocada ou nao preenchida\n\n");
    }
    else if(ret == -3){
      printf("Erro. nao tem nenhum elemento na lista\n\n");
    }
    else{
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
    printf("notas P1, P2, P3: %.3f, %.3f, %.3f\n", al.n1, al.n2, al.n3);
    }


break;

 case 12: 

  list_print(alunos_ic);
  printf("\n");

break;

  case 13:

  printf("qual matricula voce deseja saber a posicao? ");
    scanf("%d", &mat);
  ret = list_get_pos(alunos_ic, mat, &pos);
  if(ret == -1){
    printf("ERROOO!!\n\n");
  }
  printf("A posicao é %d\n\n", pos);

break;
    case 14:
    list_free(alunos_ic);

break;

    case 15:
    printf("\n");
    list_pop_back(alunos_ic);
    list_print(alunos_ic);

break;
    case 16:
    printf("qual matricula voce deseja remover? ");
    scanf("%d", &mat);
    ret = list_erase_mat(alunos_ic, mat);
    if(ret == -1){
      printf("ERROOO!!\n\n");
    }
    else if(ret == -3){
      printf("nao ha elementos na lista!!\n\n");
    }
    else{
      printf("elemento removido com sucesso!!\n\n");
    }

break;

    case 17:
    ret =list_next(alunos_ic,&al);
    
    if(ret == -1){
      printf("Erro. lista nao alocada ou nao preenchida\n\n");
    }
    else if(ret == -3){
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
    printf("notas P1, P2, P3: %.3f, %.3f, %.3f\n", al.n1, al.n2, al.n3);
    printf("Chegou ao final da Lista circular!!");
    }
    else{
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
    printf("notas P1, P2, P3: %.3f, %.3f, %.3f\n", al.n1, al.n2, al.n3);
    }

break;

    case 0:

return;//sair do programa
break;
    }
    }
}

int main(void){
    menu();
    return 0;
}