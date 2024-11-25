#include <stdio.h>
#include <assert.h>
#include "escalonador.h"
#include "metricas.h"

void teste_escalonador() {
    Processo processos[4] = {
        {"P1", 0, 5, 0, 0, 0, -1},
        {"P2", 1, 3, 0, 0, 0, -1},
        {"P3", 2, 8, 0, 0, 0, -1},
        {"P4", 3, 2, 0, 0, 0, -1}
    };

    escalonar_processos(processos, 4);
    calcular_metricas(processos, 4);

    assert(processos[0].conclusao == 5);
    assert(processos[1].conclusao == 8);
    assert(processos[2].conclusao == 16);
    assert(processos[3].conclusao == 18);

    printf("Teste do escalonador concluído com sucesso!\n");
}

int main() {
    teste_escalonador();
    return 0;
}
