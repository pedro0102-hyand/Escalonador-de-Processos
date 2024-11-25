#include <stdio.h>
#include "metricas.h"

// Calcula as métricas por processo
void calcular_metricas(Processo processos[], int n) {
    for (int i = 0; i < n; i++) {
        processos[i].retorno = processos[i].conclusao - processos[i].chegada;
        processos[i].espera = processos[i].retorno - processos[i].duracao;
    }
}

// Exibe as médias das métricas
void imprimir_metricas_medias(Processo processos[], int n) {
    double total_retorno = 0, total_espera = 0, total_resposta = 0;

    for (int i = 0; i < n; i++) {
        total_retorno += processos[i].retorno;
        total_espera += processos[i].espera;
        total_resposta += processos[i].resposta;
    }

    printf("\nMétricas Médias:\n");
    printf("Tempo de Retorno Médio: %.2f\n", total_retorno / n);
    printf("Tempo de Espera Médio: %.2f\n", total_espera / n);
    printf("Tempo de Resposta Médio: %.2f\n", total_resposta / n);
}
