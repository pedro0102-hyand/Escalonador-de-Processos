#include <stdio.h>
#include <stdlib.h>
#include "escalonador.h"
#include "metricas.h"

// Função para ler os processos do arquivo de entrada
int ler_processos(const char *nome_arquivo, Processo processos[], int *quantidade) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de entrada");
        return -1;
    }

    fscanf(arquivo, "%d", quantidade); // Lê a quantidade de processos

    for (int i = 0; i < *quantidade; i++) {
        fscanf(arquivo, "%s %d %d", processos[i].id, &processos[i].chegada, &processos[i].duracao);
        processos[i].conclusao = 0;
        processos[i].espera = 0;
        processos[i].retorno = 0;
        processos[i].resposta = -1; // Indica que não foi calculado
    }

    fclose(arquivo);
    return 0;
}

int main() {
    const char *arquivo_entrada = "entradas/processos.txt"; // Nome do arquivo de entrada
    const char *arquivo_saida = "saidas/resultados.txt";    // Nome do arquivo de saída

    Processo processos[100]; // Lista de processos
    int quantidade;          // Quantidade de processos

    if (ler_processos(arquivo_entrada, processos, &quantidade) != 0) {
        return EXIT_FAILURE;
    }

    escalonar_processos(processos, quantidade); // Realiza o escalonamento
    calcular_metricas(processos, quantidade);   // Calcula as métricas

    // Exibe os resultados no terminal
    printf("P\tChegada\tDuração\tConclusão\tEspera\tRetorno\tResposta\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%s\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n", processos[i].id, processos[i].chegada,
               processos[i].duracao, processos[i].conclusao, processos[i].espera,
               processos[i].retorno, processos[i].resposta);
    }

    // Salva os resultados no arquivo de saída
    FILE *arquivo = fopen(arquivo_saida, "w");
    if (!arquivo) {
        perror("Erro ao criar o arquivo de saída");
        return EXIT_FAILURE;
    }
    fprintf(arquivo, "P\tChegada\tDuração\tConclusão\tEspera\tRetorno\tResposta\n");
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%s\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n", processos[i].id, processos[i].chegada,
                processos[i].duracao, processos[i].conclusao, processos[i].espera,
                processos[i].retorno, processos[i].resposta);
    }
    fclose(arquivo);

    printf("Resultados salvos em %s\n", arquivo_saida);
    return EXIT_SUCCESS;
}
