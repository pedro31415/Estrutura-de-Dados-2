#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef struct SVertice {
    int dado;
    struct SVertice *next;
    struct SListaConexoes *listaConexoes;
    _Bool visitado;
    int distancia; 
} TVertice;

typedef struct SListaConexoes {
    struct SVertice *vertice;
    struct SListaConexoes *next;
    int distancia;
} TListasConexoes;

TVertice *inicio = NULL;
TVertice *fim;

TVertice *buscarVertice(int key) {
    TVertice *ultimo = inicio;

    while (ultimo != NULL) {
        if (ultimo->dado == key)
            return ultimo;
        ultimo = ultimo->next;
    }

    return NULL;
}

TVertice *adicionarVertice(int info) {
    TVertice *novo;

    novo = buscarVertice(info);
    if (novo != NULL)
        return novo;

    novo = malloc(sizeof(TVertice));
    novo->dado = info;
    novo->next = NULL;
    novo->listaConexoes = NULL;
    novo->visitado = FALSE;
    novo->distancia = INT_MAX; 

    if (inicio == NULL) {
        inicio = novo;
    } else {
        fim->next = novo;
    }

    fim = novo;
    return novo;
}

void conectarVertices(int info, int info2, int peso) {
    TVertice *verticeOrigem, *verticeDestino;

    verticeOrigem = adicionarVertice(info);
    verticeDestino = adicionarVertice(info2);

    TListasConexoes *conexao = malloc(sizeof(TListasConexoes));
    conexao->vertice = verticeDestino;
    conexao->next = NULL;
    conexao->distancia = peso;

    if (verticeOrigem->listaConexoes == NULL) {
        verticeOrigem->listaConexoes = conexao;
    } else {
        TListasConexoes *ultimaConexao = verticeOrigem->listaConexoes;
        while (ultimaConexao->next != NULL) {
            ultimaConexao = ultimaConexao->next;
        }
        ultimaConexao->next = conexao;
    }
}

void caminhoSimplesGrafo(TVertice *vertice) {
    if (vertice == NULL)
        return;

    printf("%d ", vertice->dado);
    vertice->visitado = TRUE;

    TListasConexoes *listaConexoes = vertice->listaConexoes;
    while (listaConexoes != NULL) {
        if (listaConexoes->vertice->visitado == FALSE)
            caminhoSimplesGrafo(listaConexoes->vertice);
        listaConexoes = listaConexoes->next;
    }
}

void dijkstra(TVertice *origem) {
    origem->distancia = 0; 

    
    while (1) {
        TVertice *verticeAtual = NULL;

        
        TVertice *vertice = inicio;
        while (vertice != NULL) {
            if (!vertice->visitado && (verticeAtual == NULL || vertice->distancia < verticeAtual->distancia)) {
                verticeAtual = vertice;
            }
            vertice = vertice->next;
        }

     
        if (verticeAtual == NULL) {
            break;
        }

        verticeAtual->visitado = TRUE;

        
        TListasConexoes *conexaoAtual = verticeAtual->listaConexoes;
        while (conexaoAtual != NULL) {
            int novaDistancia = verticeAtual->distancia + conexaoAtual->distancia;

           
            if (novaDistancia < conexaoAtual->vertice->distancia) {
                conexaoAtual->vertice->distancia = novaDistancia;
            }

            conexaoAtual = conexaoAtual->next;
        }
    }


    printf("\nDistâncias após o algoritmo de Dijkstra:\n");
    TVertice *vertice = inicio;
    while (vertice != NULL) {
        printf("Vértice %d: %d\n", vertice->dado, vertice->distancia);
        vertice = vertice->next;
    }
}

int main() {
    int leitura, leitura2;
    int peso;

    while (1) {
        printf("Informe um ou dois números (ou 0 para sair): ");
        scanf("%d %d", &leitura, &leitura2);
        if (leitura == 0 || leitura2 == 0)
            break;

        printf("Informe os pesos de cada valor: ");
        scanf("%d", &peso);

        if (leitura2 == 0) {
            adicionarVertice(leitura);
        } else {
            conectarVertices(leitura, leitura2, peso);
        }
    }

    printf("\n\nCaminho simples:\n");
    caminhoSimplesGrafo(inicio);

    
    TVertice *verticeOrigem = buscarVertice(1);
    if (verticeOrigem != NULL) {
        dijkstra(verticeOrigem);
    } else {
        printf("Vértice de origem não encontrado!\n");
    }

    return 0;
}
