#include <stdio.h>
#include <stdlib.h>

typedef struct Sarvore {
    int dado;
    struct Sarvore * esq;
    struct Sarvore * dir;
}Tarvore;

//sentinela
Tarvore * raiz;


void inserirElemento(Tarvore * no, int informacao){
    if (no == NULL){
        return;
    }

    Tarvore * novo;
    if(informacao > no->dado){
        if(no->dir == NULL){
            novo = malloc(sizeof(Tarvore));
            novo->dado = informacao;
            novo->esq = novo->dir = NULL;
            no->dir = novo;
        } else {
            inserirElemento(no->dir, informacao);
        }
    } else if(informacao < no->dado){
        if(no->esq == NULL){
            novo = malloc(sizeof(Tarvore));
            novo->dado = informacao;
            novo->esq = novo->dir = NULL;
            no->esq = novo;
        } else {
            inserirElemento(no->esq, informacao);
        }
    } else {
        printf("Não é possível inserir valores duplicados em uma ABB");
    }

}

void preOrdem(Tarvore * no){
    if(no == NULL){
        return;
    }

    printf("[%d] -> [%p]\n", no->dado, no);
    preOrdem(no->esq);
    preOrdem(no->dir);
}

void ordem(Tarvore * no){
    if(no == NULL){
        return;
    }
    ordem(no->esq);
    printf("[%d] -> [%p]\n", no->dado, no);
    ordem(no->dir);
}

void posOrdem(Tarvore * no){
    if(no == NULL){
        return;
    }
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("[%d] -> [%p]\n", no->dado, no);
}

Tarvore * buscaBinaria(Tarvore * no, int key){
    if(no == NULL)
        return NULL;
    if(no->dado == key){
        return no;
    } else if(key > no->dado){
        return buscaBinaria(no->dir, key);
    } else {
        return buscaBinaria(no->esq, key);
    }
}

int main(){
    int leitura, chave;
    printf("Informe a raiz da Arvore: ");
    raiz = malloc(sizeof(Tarvore));
    raiz->esq = raiz->dir = NULL;
    scanf("%d", &raiz->dado);

    while (1) {
        printf("Informe o valor: ");
        scanf("%d", &leitura);
        if(leitura == 0)
            break;
        inserirElemento(raiz, leitura);
    }
    

    printf("\n\nPreOrdem\n\n");
    preOrdem(raiz);
    printf("\n\nOrdem\n\n");
    ordem(raiz);
    printf("\n\nPosOrdem\n\n");
    posOrdem(raiz);

    printf("Informe a chave de busca: ");
    scanf("%d", &chave);
    Tarvore * valorEncontrado;
    valorEncontrado = buscaBinaria(raiz,chave);
    if(valorEncontrado != NULL){
        printf("\n\nChave encontrada na posicao = %p", valorEncontrado);
    } else {
        printf("Chave não encontrada!!!");
    }

    return 0;
}