#include <stdio.h>

#define tam 5

void selectionSort(int num[], int tamanho ){
    int aux;
    for(int i = 0; i<tamanho; i++){
        for(int j = i + 1; j<tamanho; j++){
            if(num[i]>num[j]){
                aux = num[j];
                num[j] = num[i];
                num[i] = aux; 
            }
        }
    }
}

void printNumbers(int num[], int tamanho){
    printf("\n\nNumbers:\n\n");
    for(int i = 0; i<tamanho; i++){
        printf(" %d", num[i]);
    }
}

int main(){
    int num[tam];
    for(int i = 0; i<tam; i++){
        printf("Inform the numbers: ");
        scanf("%d", &num[i]);
    }
    printNumbers(num,tam);
    selectionSort(num,tam);
    printNumbers(num,tam);

    return 0;
}