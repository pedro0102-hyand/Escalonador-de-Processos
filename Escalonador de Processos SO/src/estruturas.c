#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"

// ====================== Implementação da Fila ======================

// Inicializa a fila
void inicializar_fila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

// Verifica se a fila está vazia
int fila_vazia(Fila *fila) {
    return fila->tamanho == 0;
}

// Adiciona um processo na fila
void enfileirar(Fila *fila, Processo *processo) {
    if (fila->tamanho == TAMANHO_MAX_FILA) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    fila->fim = (fila->fim + 1) % TAMANHO_MAX_FILA;
    fila->dados[fila->fim] = processo;
    fila->tamanho++;
}

// Remove um processo da fila
Processo *desenfileirar(Fila *fila) {
    if (fila_vazia(fila)) {
        printf("Erro: Fila vazia!\n");
        return NULL;
    }
    Processo *processo = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAMANHO_MAX_FILA;
    fila->tamanho--;
    return processo;
}

// ====================== Implementação do Heap ======================

// Inicializa o heap
void inicializar_heap(Heap *heap) {
    heap->tamanho = 0;
}

// Adiciona um processo no heap (Min-Heap)
void inserir_heap(Heap *heap, Processo *processo) {
    if (heap->tamanho == TAMANHO_MAX_HEAP) {
        printf("Erro: Heap cheio!\n");
        return;
    }

    int i = heap->tamanho++;
    while (i > 0 && heap->dados[(i - 1) / 2]->duracao > processo->duracao) {
        heap->dados[i] = heap->dados[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->dados[i] = processo;
}

// Remove o menor elemento do heap
Processo *remover_heap(Heap *heap) {
    if (heap->tamanho == 0) {
        printf("Erro: Heap vazio!\n");
        return NULL;
    }

    Processo *menor = heap->dados[0];
    Processo *ultimo = heap->dados[--heap->tamanho];

    int i = 0;
    while (2 * i + 1 < heap->tamanho) {
        int esquerda = 2 * i + 1;
        int direita = 2 * i + 2;
        int menor_filho = esquerda;

        if (direita < heap->tamanho && heap->dados[direita]->duracao < heap->dados[esquerda]->duracao) {
            menor_filho = direita;
        }

        if (ultimo->duracao <= heap->dados[menor_filho]->duracao) {
            break;
        }

        heap->dados[i] = heap->dados[menor_filho];
        i = menor_filho;
    }
    heap->dados[i] = ultimo;

    return menor;
}
