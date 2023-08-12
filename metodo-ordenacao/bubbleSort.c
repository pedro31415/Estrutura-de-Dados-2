#include <stdio.h>
#define TAM 5

long bubbleSort(int num[], int tamanho){
    int aux;
    long count = 0;
    for(int i = 0; i<tamanho; i++){
        for(int j = 0; j<(tamanho - i - 1); j++){
            if(num[j]>num[j+1]){
                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
                count++;
            } 
            count++;
        }
    }
    return count;
}

void printNumbers(int num[], int tamanho){
    printf("\n\nList of Numbers\n\n");
    for(int i=0; i<tamanho; i++){
        printf(" %d", num[i]);
    }
}

int main(){
    int num[5];
    for(int i=0; i<TAM; i++){
        printf("Inform the number: ");
        scanf("%d", &num[i]);
    }
    printNumbers(num,TAM);
    long result = bubbleSort(num,TAM);  
    printNumbers(num,TAM);
    printf("\n\nHow many time did the loop run: %.2ld\n\n", result);

    return 0;
}

