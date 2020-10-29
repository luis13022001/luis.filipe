#define SUCCESS 0 
#define INVALID_NULL_POINTER -1 //sempre que a função receber null
#define OUT_OF_MEMORY -2 
#define OUT_OF_RANGE -3 
#define ELEM_NOT_FOUND -4

struct aluno{
  int matricula;
  char nome[30];
  float n1,n2,n3;
};
typedef struct TDLinkedList TDLinkedList;

TDLinkedList* list_create();//cria lista (fiz)
int list_free(TDLinkedList *li); //libera lista (fiz)
int list_push_front(TDLinkedList *li, struct aluno al);//insere no começo(fiz)
int list_push_back(TDLinkedList *li, struct aluno al); //insere no final(fiz)
int list_insert(TDLinkedList *li, int pos, struct aluno al);//insere posição(fiz)
int list_size(TDLinkedList *li); //tamanho da lsita(fiz)
int list_pop_front(TDLinkedList *li); //remove começo(fiz)
int list_pop_back(TDLinkedList *li); //remove final(fiz)
int list_erase(TDLinkedList *li, int pos); //remove posição(fiz)
int list_erase_mat(TDLinkedList *li, int mat);//remove matricula(fiz)
int list_find_pos(TDLinkedList *li, int pos, struct aluno *al);//consultar aluno posição(fiz) 
int list_find_mat(TDLinkedList *li, int nmat, struct aluno *al);//consultar aluno matricula(fiz)  
int list_front(TDLinkedList *li, struct aluno *al);//consultar elemento da frente 
int list_back(TDLinkedList *li, struct aluno *al);//consultar ultimo elemento 
int list_get_pos(TDLinkedList *li, int nmat, int *pos);//consultar em qual posição está uma matrícula(fiz)
int list_print_forward(TDLinkedList *li); 
int list_print_reverse(TDLinkedList *li);