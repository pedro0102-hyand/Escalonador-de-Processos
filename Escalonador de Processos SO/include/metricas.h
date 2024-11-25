#ifndef METRICAS_H
#define METRICAS_H

#include "escalonador.h"

// Funções para cálculo de métricas
void calcular_metricas(Processo processos[], int n);           // Calcula métricas individuais
void imprimir_metricas_medias(Processo processos[], int n);    // Calcula e exibe as métricas médias

#endif // METRICAS_H
