#include <stdio.h>
#include <stdlib.h>

typedef struct Sarvore {
    int dado;
    struct Sarvore * esq;
    struct Sarvore * dir;
}Tarvore;

//sentinela
Tarvore * raiz;

void preOrdem(Tarvore * no){
    if(no == NULL){
        return;
    }

    printf(" %d", no->dado);
    preOrdem(no->esq);
    preOrdem(no->dir);
}

int main(){
    raiz = malloc(sizeof(Tarvore));
    raiz->dado = 1;
    raiz->esq = raiz->dir = NULL;
    
    Tarvore * filho = malloc(sizeof(Tarvore));
    filho->dado = 2;
    filho->esq = filho->dir = NULL;
    raiz->esq = filho;

    filho = malloc(sizeof(Tarvore));
    filho->dado = 4;
    filho->esq = filho->dir = NULL;
    raiz->esq->esq = filho;

    filho = malloc(sizeof(Tarvore));
    filho->dado = 5;
    filho->esq = filho->dir = NULL;
    raiz->esq->dir = filho;

    filho = malloc(sizeof(Tarvore));
    filho->dado = 3;
    filho->esq = filho->dir = NULL;
    raiz->dir = filho;

    filho = malloc(sizeof(Tarvore));
    filho->dado = 6;
    filho->esq = filho->dir = NULL;
    raiz->dir->esq = filho;
    
    filho = malloc(sizeof(Tarvore));
    filho->dado = 7;
    filho->esq = filho->dir = NULL;
    raiz->dir->dir = filho;

    preOrdem(raiz);

    return 0;
}