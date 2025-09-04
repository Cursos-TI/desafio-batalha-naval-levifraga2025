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
