#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include "escalonador.h"

#define TAMANHO_MAX_FILA 100
#define TAMANHO_MAX_HEAP 100

// ====================== Definição da Fila ======================
typedef struct {
    Processo *dados[TAMANHO_MAX_FILA]; // Dados armazenados na fila
    int inicio, fim, tamanho;          // Controle da fila
} Fila;

// Funções para gerenciar a fila
void inicializar_fila(Fila *fila);                // Inicializa a fila
int fila_vazia(Fila *fila);                       // Verifica se a fila está vazia
void enfileirar(Fila *fila, Processo *processo);  // Adiciona um processo à fila
Processo *desenfileirar(Fila *fila);              // Remove um processo da fila

// ====================== Definição do Heap ======================
typedef struct {
    Processo *dados[TAMANHO_MAX_HEAP]; // Dados armazenados no heap
    int tamanho;                       // Tamanho do heap
} Heap;

// Funções para gerenciar o heap
void inicializar_heap(Heap *heap);               // Inicializa o heap
void inserir_heap(Heap *heap, Processo *processo); // Insere um processo no heap
Processo *remover_heap(Heap *heap);              // Remove o menor elemento do heap

#endif // ESTRUTURAS_H
