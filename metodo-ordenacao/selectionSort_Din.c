#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int data;
    struct No *next;
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

void selectionSort(No *list) {
  for (struct No *i = list; i->next != NULL; i = i->next) {
      for (struct No* j = i->next; j != NULL; j = j->next) {
            if (j->data < i->data) {
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}

void listar(No *list){
    printf("Value in stack: \n");
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
        selectionSort(list);
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