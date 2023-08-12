#include <stdio.h>

#define tam 5

int selectionSort(int num[], int tamanho ){
    int aux, count = 0;
    for(int i = 0; i<tamanho; i++){
        for(int j = i + 1; j<tamanho; j++){
            if(num[i]>num[j]){
                aux = num[j];
                num[j] = num[i];
                num[i] = aux;
                count++; 
            }
        }
        count++;
    }
    return count;
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
    int result = selectionSort(num,tam);
    printNumbers(num,tam);
    printf("\n\nHow many time did the loop run: %d\n\n", result);

    return 0;
}