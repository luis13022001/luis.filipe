#include "imm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int verificatxtimm(char *arquivo){
    char txt[5] = ".txt";
    char imm[5] = ".imm";
    int tam = strlen(arquivo);
    for (int i=0; i<tam; i++){
        if (txt[0] == arquivo[i] && txt[1] == arquivo[i+1] && txt[2] == arquivo[i+2] && txt[3] == arquivo[i+3]){
            return TXT;
        }
        if (imm[0] == arquivo[i] && imm[1] == arquivo[i+1] && imm[2] == arquivo[i+2] && imm[3] == arquivo[i+3]){
            return IMM;
        }
    }
    return INVALID_FILE;
}


int main(int argc, char *argv[]){

    if (strcmp(argv[2], "-open") == 0)//comparar a 2° frase de entrada com o argumento "-open"
    {
        if ((verificatxtimm(argv[3])) == TXT)
        {                     //arquivo txt
            if((openImagetxt(argv[3])) == SUCCESS){ //o arquivo que o usuário digitou
                printf("Aberto com sucesso!\n");}
            else {
                printf("error\n");
           }
        }
        else if ((verificatxtimm(argv[3])) == IMM)
        {
            if((openImageimm(argv[3])) == SUCCESS)
                printf("Aberto com sucesso!\n");
            else 
                printf("error\n");
        }
        else
        {
            printf("Arquivo não é pgm nem imm");
        }
    }
    else if (strcmp(argv[2], "-convert") == 0)
    {
        convertTxtImm(argv[3], argv[4]); //converte de pgm para imm
    }
    else if (strcmp(argv[2], "-segment") == 0)
    {                              //fazer função para ver se arquivo é pgm ou imm
        segmentImage(argv[3], argv[4], argv[5]); //converte de pgm para imm
    }

    else if(strcmp(argv[2],"-cc") == 0){
        compConexo(argv[3], argv[3]); //achar componente conexo VER O QUE SIGNIFICA O OUTFILE DO ENUNCIADO
    }
    else if(strcmp(argv[2],"-lab") == 0){
        labirinto(argv[3], argv[3]);
    }
    else{
        system("clear");
        printf("comando não encontrado");
    }

return 0;
}