#include <stdio.h>
#include "fila.h"
#include <stdlib.h>
#include <string.h>

void opcao(void)
{
    printf("1 - Criar a fila\n");
    printf("2 - insere na fila \n");
    printf("3 - tamanho da fila\n");
    printf("4 - remove na fila  \n");
    printf("5 - consulta elemento fila\n");
    printf("6 - consulta se é vazia \n");

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
    Fila *alunos_ic;
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
  alunos_ic= create_fila();
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
    Fila* alunos_ic = create_fila();
      for(int i=0; i< 10; i++){
        fila_push(alunos_ic, b[i]);
      }
break;  

    case 2:
    printf("qual nome do aluno? ");
    scanf("%s", al.nome);
    printf("qual numero de matricula? ");
    scanf("%d", &al.matricula);
    printf("quais foram suas notas na P1, P2 e P3: \n");
    scanf("%f", &al.n1);
    scanf("%f", &al.n2);
    scanf("%f", &al.n3);
    ret = fila_push(alunos_ic,al);
    if(ret == -1){
        printf("ERRO!!!\n\n");
    }
    
break;
    case 3:
    ret = fila_size(alunos_ic);
    printf("o tamanho é : %d\n\n", ret);
  break;

    case 4: 
    ret = fila_pop_front(alunos_ic);
    if( ret== -1 ){
      printf("ERRO!\n");
    }
break;

    case 5:
    if( fila_find(alunos_ic,&al) == SUCCESS ){
    printf("Matricula: %d\n",  al.matricula);
    printf("Nome: %s\n",   al.nome);
    printf("Notas: %.3f %.3f %.3f\n",al.n1,al.n2,al.n3); 
    printf("-------------------------------\n"); 
    }
    else{
    printf("Não foi encontrado nenhum valor no inicio da fila!!!\n\n");

    }


break;

    case 6:
    ret = fila_size(alunos_ic);
    if(ret == -1){
        printf("ERROO!!!\n\n");
    }
    else{
        printf("A lista não está vazia ela tem %d", ret);
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
