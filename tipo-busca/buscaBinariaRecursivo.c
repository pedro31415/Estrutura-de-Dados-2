#include <stdio.h>

#define tam 5

int buscaBinaria(int vet[], int key, int inicio, int fim);

int main(){
    int num[tam] = {89, 100, 120, 344, 567};
    int chave;
    printf("informe a chave de busca: ");
    scanf("%d", &chave);
    int final = tam - 1;
    int result = buscaBinaria(num,chave,0,final);
    if(result == -1){
        printf("Chave não encontrada");
    } else {
        printf("Chave encontrada na posição %d", result);
    }

    return 0;
}


int buscaBinaria(int vet[], int key, int inicio, int fim){
    int meio = (inicio+fim)/2;
    if(fim >= inicio){
        if(vet[meio] == key){
        return meio;
        } 
        if(vet[meio] > key){
            return buscaBinaria(vet,key,inicio, meio - 1);
        } else {
            return buscaBinaria(vet,key,meio + 1, fim);
        }
    }
    return -1;
}

