#include "imm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int argc, char *argv[]){

    if (strcmp(argv[1], "-open") == 0)//comparar a 2° frase de entrada com o argumento "-open"
    {
        if((openImage(argv[2])) == SUCCESS){ //o arquivo que o usuário digitou
            printf("Aberto com sucesso!\n");}
        else {
            printf("error\n");
        }

    }
    else if (strcmp(argv[1], "-convert") == 0)
    {
        if (convertTxtImm(argv[2], argv[3]) == SUCCESS) //converte de pgm para imm
            printf("Convertido com sucesso!\n");
        else
            printf("Error!\n");
    }
    else if (strcmp(argv[1], "-segment") == 0)
    {                              //fazer função para ver se arquivo é pgm ou imm
        segmentImage(atoi(argv[2]), argv[3], argv[4]); //converte de pgm para imm
    }

    else if(strcmp(argv[1],"-cc") == 0){
        compConexo(argv[2], argv[3]); //achar componente conexo VER O QUE SIGNIFICA O OUTFILE DO ENUNCIADO
    }
    else if(strcmp(argv[1],"-lab") == 0){
       if( labirinto(argv[2], argv[3]) == -4){
           printf("Labirinto sem saída");
       }
    }
    else{
        system("clear");
        printf("comando não encontrado");
    }

return 0;
}
