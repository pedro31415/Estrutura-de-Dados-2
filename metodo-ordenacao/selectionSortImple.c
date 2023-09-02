#include <stdio.h>
#define tam 5


int selectionSort(int num[], int tamanho){
    int aux, count = 0;
    for(int i = 0; i<tamanho-1; i++){
        int menor = i;
        for(int j = i + 1; j<tamanho; j++){
            if(num[j]<num[menor]){
                menor = j;
                count++;
            }   
        }
          if(menor != i){
            aux = num[i];
           num[i] = num[menor];
           num[menor] = aux;
           count++;
          }
    }
    return count++;
}

void print(int num[], int tamanho){
    printf("\n\nNumbers\n\n");
    for(int i = 0; i<tamanho; i++){
        printf(" %d", num[i]);
    }
    printf("\n");
}


int main(){
    int num[tam];
    for(int i = 0; i<tam; i++){
        printf("Inform the number: ");
        scanf("%d", &num[i]);
    }
    print(num,tam);
    int result = selectionSort(num,tam);
    print(num,tam);
    printf("\n\nHow many time did the loop run: %d\n\n", result);

    return 0;
}