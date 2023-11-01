#include <stdio.h>
#include <malloc.h>

typedef struct elemento{//estruct para definição do elemento
    int dado;
    struct elemento* anterior;
}elemento;

typedef struct fila{
    elemento* inicio;
    elemento* fim;
}fila;

int fila_vazia(fila* p);
int cria_fila(fila* p);
int emfileirar(fila*p, int *v);
void print_fila(fila*p);
int desenfileirar(fila* f, int *v);

int main() {
    int retorno_cria_fila;
    int retorno_emfileiramento;
    int retorno_desenfileiramento;
    int valor = 0;
    int controle = 0;
    int op;
    fila *f = (fila*)malloc(sizeof(fila));//criação do ponteiro do tipo fila


    retorno_cria_fila = cria_fila(f);
    if(retorno_cria_fila==0)
        printf("Erro na criação da fila\n");

    while ( controle == 0){
        printf("\n1-Emfileirar\n2-Desemfileirar\n3-Sair: ");//menu
        scanf("%d", &op);
    
        switch (op){
        case 1:
            printf("\nDigite o valor que sera sera emfileirado: ");
            scanf("%d", &valor);
            retorno_emfileiramento = emfileirar(f, valor);
            if(retorno_emfileiramento == 0)
                printf("Erro no emfileiramento\n");
            else{
                printf("Valor emfileirado\n");
                print_fila(f);
            break;
            }
        case 2:
            retorno_desenfileiramento = desenfileirar(f, &valor);
            if(retorno_desenfileiramento==1){
                printf("\nDesenfileiramento realizado com sucesso");
                printf("\nValor desenfileirado: %d", valor);
            }else{
                printf("\nErro no desenfileiramento\n");
            }
            break;
        default:
        printf("Programa encerrado");
            controle = 1;
            break;
        }
        
    }
    return 0;
}


int cria_fila(fila* f){
    f->inicio=NULL;//primeiro elemento da pilha
    if(f->inicio==NULL)//1 para sucesso e 0 para erro
        return 1;
    else
        return 0;
}

int fila_vazia(fila* f){
    if(f->inicio==NULL)//1 para sucesso e 0 para erro
        return 1;
    else
        return 0;
}


void print_fila(fila*f){
    elemento *atual = f->inicio;//ponteiro auxiliar para receber o topo
    printf("Elementos da fila:\n");
    while(atual!=NULL){//quando atual for igual a NULL a fila esta vazia
        printf("%d ", atual->dado);
        atual = atual->anterior;//diminuição do valor da fila, a atual recebendo a anterior
    }
    return;
}


int emfileirar(fila *f, int *v){
    int retorno_fila_vazia;
    elemento* novo = (elemento*)malloc(sizeof(elemento));//ponteiro para novo elemento
    if(novo!=NULL){
        novo->dado = v;//a parte dado do novo elemento recebendo o valor passado por paramentro na função
        novo->anterior = NULL;//configurando primeiramente o campo anterior do novo elemento antes do mesmo entrara na fila 
         if((retorno_fila_vazia = fila_vazia(f))==1){//verificação se a fila esta vazia
            f->inicio = novo;//se estiver vazia o elemento novo sera inicio e fim da fila
            f->fim = novo;
        }else{
            f->fim->anterior = novo;
            f-> fim = novo;
            return 1;//retorna 1 para sucesso e 0 para erro
        }
    }else{
        return 0;
    }
}
    
int desenfileirar(fila* f, int *v){
    int retorno_fila_vazia; 
    if((retorno_fila_vazia = fila_vazia(f))==0){
        elemento* aux = (elemento*)malloc(sizeof(elemento));//ponteiro para novo elemento
        aux = f->inicio;
        *v = aux->dado;
        f->inicio = f->inicio->anterior;
            return 1;
        free(aux);
    }else{
        return 0;
    }
}