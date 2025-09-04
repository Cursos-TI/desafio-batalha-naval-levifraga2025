#include <stdio.h>

#define TAM_TABULEIRO 10  // Tamanho do tabuleiro
#define TAM_NAVIO 3       // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0}; // Inicializa o tabuleiro com 0 (água)

    // --- Definindo coordenadas iniciais dos navios ---
    int navioHorizontalLinha = 2; // Linha inicial do navio horizontal
    int navioHorizontalColuna = 1; // Coluna inicial do navio horizontal

    int navioVerticalLinha = 5;    // Linha inicial do navio vertical
    int navioVerticalColuna = 7;   // Coluna inicial do navio vertical

    // --- Posicionando navio horizontal ---
    // Validar limites do tabuleiro
    if (navioHorizontalColuna + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[navioHorizontalLinha][navioHorizontalColuna + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // --- Posicionando navio vertical ---
    // Validar limites do tabuleiro
    if (navioVerticalLinha + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Validar se não há sobreposição
            if (tabuleiro[navioVerticalLinha + i][navioVerticalColuna] == 3) {
                printf("Erro: navio vertical se sobrepõe a outro navio.\n");
                return 1;
            }
            tabuleiro[navioVerticalLinha + i][navioVerticalColuna] = 3;
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // --- Exibindo o tabuleiro ---
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
