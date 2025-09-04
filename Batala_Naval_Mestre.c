#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5  // Tamanho das matrizes de habilidade

// Função para imprimir o tabuleiro com diferentes elementos
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro com navios e áreas de habilidade:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 "); // Água
            else if (tabuleiro[i][j] == 3)
                printf("3 "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf("5 "); // Área afetada por habilidade
            else
                printf("? "); // Caso inesperado
        }
        printf("\n");
    }
    printf("\n");
}

// Função para criar a matriz de habilidade "cone"
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Condicional para formar um cone apontando para baixo
            if (j >= (TAM_HABILIDADE/2 - i) && j <= (TAM_HABILIDADE/2 + i))
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para criar a matriz de habilidade "cruz"
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para criar a matriz de habilidade "octaedro" (losango)
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= centro - abs(centro - i) && j <= centro + abs(centro - i))
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

