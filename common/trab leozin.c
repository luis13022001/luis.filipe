#include <stdlib.h>
#include <string.h>
int calcular_preço(int cod, int qtd){
    int total;
    if(cod == 001){
        total = 10 * qtd;
    }
      else if(cod == 002){
        total = 17 * qtd;
    }
      else if(cod == 003){
        total = 15 * qtd;
    }
      else if(cod == 004){
        total = 15 * qtd;
    }
      else if(cod == 005){
        total = 17 * qtd;
    }
      else if(cod == 006){
        total = 5 * qtd;
    }
      else if(cod == 007){
        total = 4 * qtd;
    }
    return total;

}

void opcao(void)
{
    printf("1 - Iniciar Pedido \n");
    printf("2 - Apresentar Total de Pedidos \n");
    printf("3 - Sair \n\n");
}
int pegaropcao(void)
{
    
    int valor = 0;
    printf("Escolha uma opção: ");
    scanf("%u", &valor); //ler o valor da opção
    while ( !(0 <= valor && valor <= 3))
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
    int qtd,tam;
    while(1){
        opcao();
        switch (pegaropcao())
    {

        case 1:










int main(void)
{
    menu();
    return 0;
}
