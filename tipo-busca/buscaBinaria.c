#include <stdio.h>

#define tam 5

int buscaBinaria(int vet[], int key, int tamanho);

int main(){
    int num[tam] = {18,45,67,89,100};
    int chave;
    printf("Informe o valor de busca: ");
    scanf("%d", &chave);
    int result = buscaBinaria(num,chave,tam);
    if(result == -1){
        printf("Chave não encontrada");
    } else {
        printf("Chave encontrada na posição %d", result);
    }

    return 0;
}


int buscaBinaria(int vet[], int key, int tamanho){
    int inicio = 0;
    int fim  = tamanho - 1;
    while (inicio <= fim){
        int meio = (inicio+fim)/2;
        if(vet[meio] == key){
            return meio;
        }
        else if(vet[meio] > key){
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return -1;
}