#include <stdio.h>
#include "escalonador.h"

// Função para ordenar processos por tempo de chegada (FCFS)
void ordenar_por_chegada(Processo processos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processos[j].chegada > processos[j + 1].chegada) {
                Processo temp = processos[j];
                processos[j] = processos[j + 1];
                processos[j + 1] = temp;
            }
        }
    }
}

// Função que realiza o escalonamento FCFS + SJN
void escalonar_processos(Processo processos[], int n) {
    ordenar_por_chegada(processos, n);

    int tempo_atual = 0;
    int completados = 0;

    while (completados < n) {
        int menor_duracao = -1;

        for (int i = 0; i < n; i++) {
            if (processos[i].chegada <= tempo_atual && processos[i].conclusao == 0) {
                if (menor_duracao == -1 || processos[i].duracao < processos[menor_duracao].duracao) {
                    menor_duracao = i;
                }
            }
        }

        if (menor_duracao != -1) {
            if (processos[menor_duracao].resposta == -1) {
                processos[menor_duracao].resposta = tempo_atual - processos[menor_duracao].chegada;
            }
            tempo_atual += processos[menor_duracao].duracao;
            processos[menor_duracao].conclusao = tempo_atual;
            completados++;
        } else {
            tempo_atual++;
        }
    }
}
