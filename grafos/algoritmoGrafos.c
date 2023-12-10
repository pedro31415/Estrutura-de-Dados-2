#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define INFINITY INT_MAX


typedef struct SVertice{
	int dado;
	struct SVertice * next;
	struct SListaConexoes * listaConexoes;
	_Bool visitado;
} TVertice;

typedef struct SListaConexoes{
	struct SVertice * vertice;
	struct SListaConexoes * next;
} TListasConexoes;

//sentinela
TVertice * inicio = NULL;
TVertice * fim;

TVertice * buscarVertice(int key){
	TVertice * ultimo = inicio;

	while (ultimo != NULL){
		if (ultimo->dado == key)
			return ultimo;
		ultimo = ultimo->next;
	}

	return NULL;
}

TVertice * adicionarVertice(int info){
	TVertice * novo;

	novo = buscarVertice(info);
	if (novo != NULL)
		return novo;

	novo = malloc(sizeof(TVertice));
	novo->dado = info;
	novo->next = NULL;
	novo->listaConexoes = NULL;
	novo->visitado = FALSE;

	if (inicio == NULL){
		inicio = novo;
	}else {
		fim->next = novo;
	}

	fim = novo;
	return novo;
}

void conectarVertices(int info, int info2){
	TVertice * verticeOrigem, * verticeDestino;

	verticeOrigem = adicionarVertice(info);
	verticeDestino = adicionarVertice(info2);

	TListasConexoes * conexao = malloc(sizeof(TListasConexoes));
	conexao->vertice = verticeDestino;
	conexao->next = NULL;
	
	if (verticeOrigem->listaConexoes == NULL){
		verticeOrigem->listaConexoes = conexao;
	}else{
		TListasConexoes * ultimaConexao = verticeOrigem->listaConexoes;
		while (ultimaConexao->next != NULL){
			ultimaConexao = ultimaConexao->next;
		}
		ultimaConexao->next = conexao;
	}

}

void caminhoSimplesGrafo(TVertice * vertice){
	if (vertice == NULL)
		return;

	printf("%d ",vertice->dado);
	vertice->visitado = TRUE;

	TListasConexoes * listaConexoes = vertice->listaConexoes;
	while (listaConexoes != NULL){
		if (listaConexoes->vertice->visitado == FALSE)
		 	caminhoSimplesGrafo(listaConexoes->vertice);
		listaConexoes = listaConexoes->next;
	}
}

int calcularPesoConexoes(TVertice *vertice) {
    int pesoTotal = 0;

    if (vertice == NULL || vertice->listaConexoes == NULL) {
        printf("Vértice ou lista de conexões é nula.\n");
        return pesoTotal;
    }

    TListasConexoes *listaConexoes = vertice->listaConexoes;
    while (listaConexoes != NULL) {
        listaConexoes = listaConexoes->next;
    }

    return pesoTotal;
}

int main(){

	int leitura, leitura2;
	int peso;

	while (1){
		printf("Infome um ou dois número: ");
		scanf("%d %d",&leitura, &leitura2);
		if (leitura == 0)
			break;

		if (leitura2 == 0){
			adicionarVertice(leitura);
		}else {
			conectarVertices(leitura, leitura2);
		}
	}

	printf("\n\nCaminho simples\n");
	caminhoSimplesGrafo(inicio);


	return 0;
}