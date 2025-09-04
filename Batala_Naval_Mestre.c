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
