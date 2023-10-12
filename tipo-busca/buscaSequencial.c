#include <stdio.h>
#define tam 5

int buscaSequencial(int vet[], int key, int tamanho);

int main(){
    int num[tam];
    int chave;
    for(int i = 0; i < tam; i++){
        printf("inform the number: ");
        scanf("%d", &num[i]);
    }
    printf("Inform the key: ");
    scanf("%d", &chave);
    int result = buscaSequencial(num,chave,tam);
    if(result == -1){
        printf("Value not found");
    } else {
        printf("The number is found in the position %d", result);
    }


    return 0;
}


int buscaSequencial(int vet[], int key, int tamanho){
    for(int i = 0; i<tamanho; i++){
        if(vet[i] == key)
            return i;
    }
    return -1;
}
