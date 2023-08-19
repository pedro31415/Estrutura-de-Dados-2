#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    struct No *next;
    int data;
}No;

int valor(){
    int x;
    printf("informe the number: ");
    scanf("%d", &x);
    return x;
}

No *insert(No *list){
    No *novo = malloc(sizeof(No));
    if(novo != NULL){
        novo->data = valor();
        novo->next = list;
        return novo;
    } else {
        printf("Erro on try");
    }
    return NULL;
}

void bubbleSort(No *novo){
    int aux;
    while(novo->next != NULL){
         if(novo->data > novo->next->data){
            aux = novo->data;
            novo->data = novo->next->data;
            novo->next->data = aux;
         }
         novo = novo->next;
    }
}

void listar(No *list){
    printf("Valores da pilha: \n");
    while(list != NULL){
        printf(" %d", list->data);
        list = list->next;
    }
    printf("\n");
}


int main(){
   No *list = NULL;
   int op;
   do {
    printf("0 - Exit\n1 - Insert\n2 - print\n3 - order\n");
    scanf("%d", &op);
    switch(op) {
    case 1:
         list = insert(list);
         break;
    case 2:
         listar(list);
         break;
    case 3:
        bubbleSort(list);
        break;
   default:
     if(op != 0) {
        printf("This number is invalad");
       }
         break;
     }
   } while( op != 0);

    return 0;
}
