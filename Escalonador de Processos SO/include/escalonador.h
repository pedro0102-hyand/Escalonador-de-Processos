#ifndef ESCALONADOR_H
#define ESCALONADOR_H

// Estrutura para representar um processo
typedef struct {
    char id[10];         // Identificador do processo
    int chegada;         // Tempo de chegada
    int duracao;         // Tempo de execução
    int conclusao;       // Tempo de conclusão
    int espera;          // Tempo de espera
    int retorno;         // Tempo de retorno
    int resposta;        // Tempo de resposta
} Processo;

// Funções do escalonador
void escalonar_processos(Processo processos[], int n); // Escalonamento combinado FCFS + SJN
void ordenar_por_chegada(Processo processos[], int n); // Ordena por chegada para FCFS

#endif // ESCALONADOR_H
