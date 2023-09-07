#include <stdio.h>
#define tam 5

int insertionSort(int num[], int tamanho){
    int count = 0;
    for(int i = 1; i<tamanho; i++){
        int key = num[i];
        int j = i - 1;

        while( j >= 0 && key < num[j]){
            num[j + 1] = num[j];
            --j;
            count++;
        }
        num[j+1] = key;
        count++;
    }
    return count;
}

void print(int num[], int tamanho){
    printf("\n\nNumbers!\n\n");
    for(int i = 0; i < tamanho; i++){
        printf(" %d", num[i]);
    }
    printf("\n");
}

int main(){
    int num[tam];
    for(int i = 0; i <tam; i++){
        printf("inform the number: ");
        scanf("%d", &num[i]);
    }
    print(num,tam);
    int result = insertionSort(num,tam);
    print(num,tam);
    printf("\ninterations: %d\n", result);

    return 0;
}