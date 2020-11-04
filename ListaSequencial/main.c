#include <stdio.h>
#include "ListaSequencial.h"
#include <stdlib.h>
#include <string.h>

void opção(void)
{
    printf("1 - Criar a Lista  \n");
    printf("2 - Consultar lista posição  \n");
    printf("3 - Consultar lista matricula  \n");
    printf("4 - insere no final da lista   \n");
    printf("5 - insere no inicio da lista  \n");
    printf("6 - insere na lista ordenada  \n");
    printf("7 - remove aluno pela matricula  \n");
    printf("8 - remove a 1° posição da lista  \n");
    printf("9 - Tamanho da lista  \n");
    printf("10 - Ver se a lista está cheia \n");
    printf("11 - Ver se a lista está vazia \n");
    printf("12 - Imprime Lista \n");
    printf("13 - Remove lista otimizado \n");
    printf("14 - Liberar Lista \n");
    printf("15 - Multiplica notas \n");
    printf("0 - Sair \n\n");
}
unsigned int pegaropcao(void)
{
    
    unsigned int valor = 0;
    printf("Escolha uma opção: ");
    scanf("%u", &valor); //ler o valor da opção
    while ( !(0 <= valor && valor <= 15))
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
    Lista *alunos_ic;
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
  alunos_ic= cria_lista();
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
    Lista* alunos_ic = cria_lista(tam);
      for(int i=0; i< 10; i++){
        insere_lista_ordenada(alunos_ic, b[i]);
      }
    imprime_lista(alunos_ic);
break;  

    case 2:
    printf("qual posição voce deseja saber? ");
    scanf("%d", &pos);
    consulta_lista_pos(alunos_ic,pos,&al);
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
    printf("notas P1, P2, P3: %f, %f, %f\n", al.n1, al.n2, al.n3);
    
break;
    case 3:
    printf("qual matricula voce deseja saber? ");
    scanf("%d", &mat);
    consulta_lista_mat(alunos_ic,mat,&al);
    printf("\n%s\n", al.nome);
    printf("matricula : %d\n", al.matricula);
    printf("notas P1, P2, P3: %f, %f, %f\n", al.n1, al.n2, al.n3);
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
    ret = insere_lista_final(alunos_ic, al);
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
    ret = insere_lista_inicio(alunos_ic, al);
    if( ret == -1 ){
      printf("ERRO!\n");
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
    ret = insere_lista_ordenada(alunos_ic,al);
   if( ret == -1){
   printf("ERRO!\n");
   }
   imprime_lista(alunos_ic);
break;

    case 7:
    printf("qual matricula voce deseja remover? ");
     scanf("%d", &mat);
     ret = remove_lista(alunos_ic,mat);
     if(ret == -1){
       printf("ERRO!\n");
     }
     if(ret == 1){
       printf("essa matricula nao está na lista\n");
     }

   
break;

    case 8:
     remove_lista_inicio(alunos_ic);
     imprime_lista(alunos_ic);
    printf("\n");

break;

    case 9:
    qtd = tamanho_lista(alunos_ic);
    printf("\nO tamanho da lista é %d\n\n", qtd);
break;

    case 10:
    ret = lista_cheia(alunos_ic);
    
    if(ret == -1){
      printf("A lista está cheia.\n\n");
    }
    if(ret == 2){
      printf("A lista não está cheia.\n\n");
    }

break;





    case 11: 
    ret = lista_vazia(alunos_ic);
    if(ret == -1){
      printf("A lista está vazia.\n\n");
    }
    if(ret == 0){
      printf("A lista não está vazia.\n\n");
    }


    
break;
 case 12: 
  imprime_lista(alunos_ic);
  printf("\n");
break;

  case 13:
  printf("qual matricula voce deseja remover? ");
     scanf("%d", &mat);
  ret = remove_lista_otimizado(alunos_ic, mat);
  if(ret == -1){
    printf("ERROOO!!\n\n");
  }
   imprime_lista(alunos_ic);

break;
    case 14:
    libera_lista(alunos_ic);
break;
    case 15:
    printf("\n");
    printf("Quer multiplicar por quanto cada nota? ");
    scanf("%d", &val);
    multiplica_notas(alunos_ic,val);
    imprime_lista(alunos_ic);
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
