#include "imm.h"
#include <string.h>
#include <stdio.h>
#include "matriz.h"
#include "stack.h"
#include <stdbool.h>

struct Img
{
    TMat2D *data;
};

int openImage(char *file)
{
    if (verificatxtimm(file) == TXT)
    {
        if (openImagetxt(file) == SUCCESS)
        {
            return SUCCESS;
        }
    }
    else
    {
        if (openImageimm(file) == 0)
        {
            return SUCCESS;
        }
    }
}

Img *lerImage(char *file)
{
    Img *img;
    if (verificatxtimm(file) == TXT)
    {
        img = lerImagetxt(file);
    }
    else
    {
        img = lerImageimm(file);
    }
}

Img *lerImagetxt(char *arquivotxt)
{
    int i = 0, linha, coluna;
    int dados;
    int retorno[2];
    char c;

    FILE *arq;

    Img *img = (Img *)malloc(sizeof(Img));
    arq = fopen(arquivotxt, "r");
    if (arq == NULL)
    {
        return NULL;
    }

    //Preenche linha coluna
    get_linha_coluna(arq, retorno);
    linha = retorno[0];
    coluna = retorno[1];

    img->data = mat2D_create(linha, coluna);

    rewind(arq);
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            fscanf(arq, "%d", &dados);
            if (mat2D_set_value(img->data, i, j, (int)dados) != SUCCESS)
            {
                return NULL;
            }
        }
    }

    fclose(arq);
    return img;
}

Img *lerImageimm(char *arquivoimm)
{
    int i = 0, linha, coluna;
    int dados; // in

    FILE *arq;
    Img *img = (Img *)malloc(sizeof(Img));
    arq = fopen(arquivoimm, "rb");
    if (arq == NULL)
    {
        return NULL;
    }

    fread(&linha, sizeof(int), 1, arq);
    fread(&coluna, sizeof(int), 1, arq);
    img->data = mat2D_create(linha, coluna);

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            fread(&dados, sizeof(int), 1, arq);
            if (mat2D_set_value(img->data, i, j, dados) != SUCCESS)
            {
                return NULL;
            }
        }
    }
    fclose(arq);
    return img;
}

int liberaImage(Img *arquivo)
{
    if (arquivo == NULL)
    {
        return INVALID_FILE;
    }
    free(arquivo->data);
    free(arquivo);
    return SUCCESS;
}

int openImagetxt(char *arquivotxt)
{
    Img *img = lerImagetxt(arquivotxt);
    exibirMatriz(img->data);
    liberaImage(img);
    return 0;
}

int openImageimm(char *arquivoimm)
{
    Img *img = lerImageimm(arquivoimm);
    exibirMatriz(img->data);
    liberaImage(img);
    return 0;
}
int convertTxtImm(char *arquivotxt, char *arquivoimm)
{
    Img *img = lerImagetxt(arquivotxt);
    int lin, col;
    int dados;

    if (mat2D_get_lincol(img->data, &lin, &col) != SUCCESS)
    {
        return INVALID_FILE;
    }

    int result;
    int i;

    FILE *arq;
    arq = fopen(arquivoimm, "wb");
    if (arq == NULL)
    {
        return INVALID_FILE;
    }

    fwrite(&lin, sizeof(int), 1, arq);
    fwrite(&col, sizeof(int), 1, arq);
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat2D_get_value(img->data, i, j, &dados) == SUCCESS)
            {
                fwrite(&dados, sizeof(int), 1, arq);
            }
        }
    }
    fclose(arq);
    return 0;
}

int segmentImage(int thr, char *arq_entrada, char *arq_saida)
{

    Img *img = lerImage(arq_entrada);
    int lin, col;
    int dados;

    if (mat2D_get_lincol(img->data, &lin, &col) != SUCCESS)
    {
        return INVALID_FILE;
    }

    Img *img_saida = (Img *)malloc(sizeof(Img));
    if (img_saida == NULL)
    {
        return INVALID_FILE;
    }

    img_saida->data = mat2D_create(lin, col);

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat2D_get_value(img->data, i, j, &dados) == SUCCESS)
            {
                mat2D_set_value(img_saida->data, i, j, dados >= thr);
            }
        }
    }
    if (imagemParaArquivo(img_saida, arq_saida) == SUCCESS)
        return SUCCESS;
    else
        return INVALID_FILE;
}

int compConexo(char *arquivoimm, char *arquivoSaida)
{
    // considerando que a borda da imagem são zeros
    // im - imagem original
    Img *im = lerImage(arquivoimm);
    int lin, col;
    int dadosim;
    int dadosrot;
    if (mat2D_get_lincol(im->data, &lin, &col) != SUCCESS)
    {
        return INVALID_FILE;
    }
    Img *im_rot = (Img *)malloc(sizeof(Img));
    if (im_rot == NULL)
    {
        return INVALID_FILE;
    }
    im_rot->data = mat2D_create(lin, col);
    // im_rot - imagem rotulada - inicialmente zerada
    int label = 1;
    Stack *lista_proximos = create_stack();
    struct Ponto p, p_atual, a;
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        { // percorre toda a imagem em busca de um pixel foreground (valor 1)
            p.x = i;
            p.y = j;
            mat2D_get_value(im->data, p.x, p.y, &dadosim);
            mat2D_get_value(im_rot->data, p.x, p.y, &dadosrot);
            if ((dadosim == 1) && (dadosrot == 0))
            {
                mat2D_set_value(im_rot->data, p.x, p.y, label); //im_rot(p.x,p.y) = label; // atribui o label a posição (i,j)
                stack_push(lista_proximos, p);                   // inclui na lista de busca dos vizinhos
                while (stack_size(lista_proximos) != 0)
                { // busca o próximo ponto da lista

                    stack_find(lista_proximos, &p_atual);
                    stack_pop(lista_proximos);

                    for (int d = 0; d < 4; d++)
                    {
                        a.x = p.x;
                        a.y = p.y;
                        p.x = p_atual.x - (d == 0) + (d == 1);
                        p.y = p_atual.y - (d == 2) + (d == 3);

                        mat2D_get_value(im->data, p.x, p.y, &dadosim);
                        mat2D_get_value(im_rot->data, p.x, p.y, &dadosrot);

                        if ((dadosim == 1) && (dadosrot == 0))
                        {                                                   // verifica if o ponto acima não é um e não foi rotulado
                            mat2D_set_value(im_rot->data, p.x, p.y, label); //im_rot(p.x,p.y) = label;// atribui o label a posição atual
                            stack_push(lista_proximos, p);                   // adiciona o ponto na lista para verificar vizinhos posteriormente
                        }
                        p.x = a.x;
                        p.y = a.y;

                    } //for

                } // while
                label++;
            } // if
        }     //for
    }         // for
    imagemParaArquivo(im_rot, arquivoSaida);
    stack_free(lista_proximos);
    return SUCCESS;
}





int labirinto(char *arquivotxt, char *arquivoSaida)
{
Img *mapa1 = lerImage(arquivotxt);
    int lin, col;
    int valmap;
    int valmap2;
    if(mat2D_get_lincol(mapa1->data, &lin, &col) != SUCCESS){
        return INVALID_FILE;
    }
    Img *mapa2 = (Img*) malloc(sizeof(Img));
    if(mapa2 == NULL){
        return INVALID_FILE;
    }

    bool mapa_sem_saida;
    mapa2->data = mat2D_create(lin, col);
    // mapa2 - mapa 2 - inicialmente zerado
    Stack *lista_proximos = create_stack();
    struct Ponto p, p_atual,a, inicio;
    inicio.x = -1;
    for (int i =  0; i < lin; i++) {
        for (int j = 0; j < col; j++){// percorre toda a imagem em busca de inicio e fim (valor 1)
            if (i == 0 || j == 0 || i == lin-1 || j == col-1){ //andar nas bordas da matriz;
                mat2D_get_value(mapa1->data,i,j, &valmap);
                if (valmap == 1) {
                    inicio.x = i;
                    inicio.y = j;
                    break;
                }
            }
        }
        if(inicio.x != -1){
            break;
        }
    }//ACHAR INICIO
    p_atual = inicio;
    while (true){ // busca o próximo ponto da lista
        mat2D_get_value(mapa1->data,p_atual.x,p_atual.y,&valmap);
        if (
            (p_atual.x != inicio.x || p_atual.y != inicio.y ) &&
            valmap == 1 &&
            (p_atual.x == 0 || p_atual.y == 0 || p_atual.x == lin-1 || p_atual.y == col-1)
            ){
                stack_push(lista_proximos, p_atual);
                break;
        }


                    
        for (int d = 0; d < 4; d++){
            p.x = p_atual.x - (d == 0) + (d == 1);
            p.y = p_atual.y - (d == 2) + (d == 3);
            

            if(p.x < 0 || p.x >= lin || p.y < 0 || p.y >= col){
                continue;
            }
            mat2D_get_value(mapa1->data ,p.x, p.y, &valmap);
            mat2D_get_value(mapa2->data ,p.x, p.y, &valmap2);
            if ((valmap == 1) && (valmap2 == 0)) {
                mat2D_set_value(mapa2->data, p_atual.x, p_atual.y, 1);
                stack_push(lista_proximos, p_atual);
                p_atual = p;
                break;
            }//for
             if( d == 3){
                    mat2D_set_value(mapa2->data, p_atual.x, p_atual.y, 3);//im_rot(p.x,p.y) = label;// atribui o label a posição atual
                    if(stack_size(lista_proximos) == 0){
                        mapa_sem_saida = true;
                        break;
                    }
                    stack_find(lista_proximos, &p_atual);
                    stack_pop(lista_proximos);
                }//if

                     
            }//for
        if (mapa_sem_saida){
            break;
        }

    }//while

    while(stack_size(lista_proximos) != 0){
        stack_find(lista_proximos, &p_atual);
        stack_pop(lista_proximos);
        mat2D_set_value(mapa1->data, p_atual.x, p_atual.y, 2);
    }                                                               
    imagemParaArquivo(mapa1, arquivoSaida);
    stack_free(lista_proximos);
    if(mapa_sem_saida){
        return -4;
    }

    return SUCCESS;

}

int imagemParaArquivo(Img *img, char *arquivo)
{

int lin, col;

char tipoAbertura[3] = {'w', '\0', '\0'};
if (verificatxtimm(arquivo) == IMM)
{
    tipoAbertura[1] = 'b';
}

FILE *arq;
arq = fopen(arquivo, tipoAbertura);
if (arq == NULL)
{
    return INVALID_FILE;
}

if (mat2D_get_lincol(img->data, &lin, &col) != SUCCESS)
{
    return INVALID_FILE;
}

int dados;
if (verificatxtimm(arquivo) == TXT)
{ //TXT
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat2D_get_value(img->data, i, j, &dados);
            if (j == col - 1)
            {
                fprintf(arq, "%d\0", dados);
            }
            else
            {
                fprintf(arq, "%d\t", dados);
            }
        }
        if (i != lin - 1)
            fprintf(arq, "\n");
    }
}
else
{ //IMM
    fwrite(&lin, sizeof(int), 1, arq);
    fwrite(&col, sizeof(int), 1, arq);
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat2D_get_value(img->data, i, j, &dados);
            fwrite(&dados, sizeof(int), 1, arq);
        }
    }
}

return SUCCESS;
}

int verificatxtimm(char *arquivo)
{
char txt[5] = ".txt";
char imm[5] = ".imm";
int tam = strlen(arquivo);
for (int i = 0; i < tam; i++)
{
    if (txt[0] == arquivo[i] && txt[1] == arquivo[i + 1] && txt[2] == arquivo[i + 2] && txt[3] == arquivo[i + 3])
    {
        return TXT;
    }
    if (imm[0] == arquivo[i] && imm[1] == arquivo[i + 1] && imm[2] == arquivo[i + 2] && imm[3] == arquivo[i + 3])
    {
        return IMM;
    }
}
return INVALID_FILE;
}

void get_linha_coluna(FILE *arq, int *retorno)
{
char c;
int linha = 1, coluna = 1;
while ((c = fgetc(arq)) != EOF)
{
    if (linha == 1 && c == '\t')
    {
        coluna++;
    }
    else if (c == '\n')
    {
        linha++;
    }
    else
    {
        continue;
    }
}
retorno[0] = linha;
retorno[1] = coluna;
}
