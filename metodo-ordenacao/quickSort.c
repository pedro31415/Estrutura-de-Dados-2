#include <stdio.h>
#define tam 5

int partition(int vet[], int inicio, int ultimo){
    int pivot = vet[inicio];
    int aux;
    int i = inicio;
    for(int j = inicio + 1; j < ultimo; j++){
        if(vet[j] <= pivot){
            i+=1;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }
    int meio = i;
    aux = vet[inicio];
    vet[inicio] = vet[meio];
    vet[meio] = aux;

    return meio;
}

void quickSort(int vet[], int inicio, int ultimo){
    if(inicio < ultimo){
        int indexPivot = partition(vet, inicio, ultimo);
        quickSort(vet, inicio, indexPivot-1);
        quickSort(vet, indexPivot+1, ultimo);
    }
}

void list(int vet[], int tamanho){
    printf("Values the array: \n\n");
    for(int i = 0; i<tamanho; i++){
        printf(" %d", vet[i]);
    }
    printf("\n\n");
}

int main(){
    int num[tam] = {6, 56, 3, 5, 10};
    list(num,tam);
    quickSort(num,0,5);
    list(num,tam);

    return 0;
}