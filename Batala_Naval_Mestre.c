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

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origemLinha, int origemColuna) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha - centro + i;
            int colunaTabuleiro = origemColuna - centro + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    // Marca área afetada, mas mantém navio intacto
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0)
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // --- Posicionando dois navios horizontais e verticais ---
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;

    tabuleiro[4][7] = 3;
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;

    // --- Criando matrizes de habilidade ---
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // --- Aplicando habilidades no tabuleiro ---
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Origem no topo do cone
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Origem no centro da cruz
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Origem no centro do octaedro

    // --- Exibindo o tabuleiro final ---
    imprimirTabuleiro(tabuleiro);

    return 0;
}

