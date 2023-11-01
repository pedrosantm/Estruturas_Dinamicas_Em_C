#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    int cont;
    struct elemento* prox;
}elemento;

typedef struct{
    elemento* inicio;
}lista;


void inicializa_lista(lista* l);
int lista_vazia(lista*l);
int contagem(lista* l);
int inserir_final(lista* l, int v);
void inserir_inicio(lista* l, int v);
int inseir_indice(lista* l, int v, int ind);
void print_lista(lista* l);
void destruir_lista(lista* l);

int main(){

    lista* l = (lista*)malloc(sizeof(lista));






    return 0;

}

void inicializa_lista(lista* l){
    l->inicio = NULL;
    return;
}

int lista_vazia(lista*l){
    if(l->inicio==NULL)
        return 1;
    else
        return 0;
}

int contagem(lista* l){
    int cont=0;
    elemento* aux = l->inicio;

    while(aux != NULL){
        aux = aux->prox;
        cont++;
    }

    return cont;
}

int inserir_final(lista* l, int v){
    elemento* novo = (elemento*)malloc(sizeof(elemento));
    elemento* aux = l->inicio;
    novo->valor = v;
    novo->prox = NULL;
    while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox = novo;
    if(novo->prox==NULL)
        return 1;
    else
        return 0;
}

void inserir_inicio(lista* l, int v){
    elemento* novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = v;    
    novo->prox = NULL;
    novo->prox = l->inicio;
    l->inicio = novo;

    return;
}

int inseir_indice(lista* l, int v, int ind){
    elemento* novo = (elemento*)malloc(sizeof(elemento));
    elemento* aux = l->inicio;
    novo->valor = v;
    novo->prox = NULL;
    int retorno_contagem = contagem(l);
    int i=0;
    ind = ind-1;

    if(retorno_contagem<ind)
        return 0;
    else{
        while(i<ind&&aux->prox!=NULL){
            aux=aux->prox;
            i++;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    return 1;
 }
    
}


int retirar_fim(lista*l, int* v){
    elemento* aux_atual = l->inicio;
    elemento* aux_anterior = NULL;
    int retorno_vazia = lista_vazia(l);

    if(retorno_vazia == 1)
        return 0;
    else{
        while(aux_atual->prox!=NULL){
            aux_anterior=aux_atual;
            aux_atual=aux_atual->prox;
        }

        *v = aux_atual->valor;
        aux_anterior->prox = NULL;
        free(aux_atual);
        return 1;
  }
    
}

int retirar_inicio(lista*l, int* v){
    elemento* aux = l->inicio;
    int retorno_vazia = lista_vazia(l);

    if(retorno_vazia == 1)
        return 0;
    else{
        *v = aux->valor;
        l->inicio = aux->prox;
        aux->prox = NULL;
        free(aux);
        return 1;
    }
}

int retirar_indice(lista* l, int* v, int indice){
    elemento* aux_atual = l->inicio;
    elemento* aux_anterior = NULL;
    indice = indice - 1;
    int retorno_vazia = lista_vazia(l);
    int i = 0;

    if(retorno_vazia == 1)
        return 0;
    else{
        while(i<indice&&aux_atual->prox!=NULL){
            aux_anterior=aux_atual;
            aux_atual=aux_atual->prox;
            i++;
        }

        *v = aux_atual->valor;
        aux_anterior->prox = NULL;
        free(aux_atual);
        return 1;
    }

}

void print_lista(lista* l){
    elemento* aux = l->inicio;
    int retorno_contagem = contagem(l);
    int retorno_vazia = lista_vazia(l);

    if(retorno_vazia == 1)
        return 0;
    else{
        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
     return 1;
    }
}

void destruir_lista(lista* l){
    elemento* aux_atual = l->inicio;
    elemento* aux_anterior = NULL;
    int retorno_vazia = lista_vazia(l);
    int retorno_contagem = contagem(l);

    if(retorno_vazia == 1)
        return 0;
    else{
        while(aux_atual != NULL){
            aux_anterior=aux_atual;
            aux_atual=aux_atual->prox;
            aux_anterior->prox = NULL;
            free(aux_atual);

        }
        return 1;
    }
}

