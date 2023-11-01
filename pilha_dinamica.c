#include <stdio.h>
#include <malloc.h>

typedef struct elemento{//estruct para definição do elemento
    int dado;
    struct elemento* anterior;
}elemento;

typedef struct pilha{
    elemento* topo;
}pilha;

int pilha_vazia(pilha* p);
int cria_pilha(pilha* p);
int empilhar(pilha *p, int *v);
void print_pilha(pilha *p);
int retorno_desenpilhamento;

int main() {
    int retorno_cria_pilha;
    int retorno_empilhamento;
    int retorno_desempilhamento;
    int valor;
    int controle = 0;
    int op;
    pilha *p = (pilha*)malloc(sizeof(pilha));//criação do ponteiro do tipo pilha 


    retorno_cria_pilha = cria_pilha(p);
    if(retorno_cria_pilha==0)
        printf("Erro na criação da pilha\n");

    while ( controle == 0){
        printf("\n1-Emplihar\n2-Desenpilhar\n3-Sair: ");//menu
        scanf("%d", &op);
    
        switch (op){
        case 1:
            printf("\nDigite o valor que sera sera empilhado: ");
            scanf("%d", &valor);
            retorno_empilhamento = empilhar(p, valor);
            if(retorno_empilhamento == 0)
                printf("Erro no empilhamento\n");
            else{
                printf("Valor emplilhado\n");
                print_pilha(p);
            }
            break;
        case 2:
            retorno_desempilhamento = desempilhar(p, &valor);
            if(retorno_desempilhamento==1){
                printf("\nDesenpilhamento realizado com sucesso");
                printf("\nValor desenpilhado: %d", valor);
            }else{
                printf("\nErro no desenpilhamento\n");
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


int cria_pilha(pilha* p){
    p->topo=NULL;//primeiro elemento da pilha
    if(p->topo==NULL)//1 para sucesso e 0 para erro
        return 1;
    else
        return 0;
}

int pilha_vazia(pilha* p){
    if(p->topo==NULL)//1 para sucesso e 0 para erro
        return 1;
    else
        return 0;
}


void print_pilha(pilha*p){
    elemento *atual = p->topo;//ponteiro auxiliar para receber o topo
    printf("Elementos da pilha:\n");
    while(atual!=NULL){//quando atual for igual a NULL a pilha esta vazia
        printf("%d ", atual->dado);
        atual = atual->anterior;//diminuição do valor da pilha, a atual recebendo a anterior
    }
    return;
}


int empilhar(pilha *p, int *v){
    elemento* novo = (elemento*)malloc(sizeof(elemento));//ponteiro para novo elemento
    if(novo!=NULL){
        novo->dado = v;//a parte dado do novo elemento recebendo o valor passado por paramentro na função
        novo->anterior = p->topo;//parte anterior do novo elemento recebe o antigo topo
        p->topo = novo;//o topo é atualizado recebendo o novo elemento
         if(p->topo ==novo)//1 para sucesso e 0 para erro
            return 1;
        else
            return 0;
    }else{
        return 0;
    }
}

int desempilhar(pilha* p, int *v){
    int retorno_pilha_vazia; 
    if((retorno_pilha_vazia = pilha_vazia(p))==0){
        elemento* aux = (elemento*)malloc(sizeof(elemento));//ponteiro para novo elemento
        aux = p->topo;
        *v = aux->dado;
        p->topo = p->topo->anterior;
            return 1;
        free(aux);
    }else{
        return 0;
    }
}
    
