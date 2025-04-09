#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro nesta posição.\n");
        return 0;
    }

    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            printf("Erro: Navio horizontal sobrepõe-se a outro navio.\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro nesta posição.\n");
        return 0;
    }

    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            printf("Erro: Navio vertical sobrepõe-se a outro navio.\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1;
}

// Função para posicionar um navio diagonalmente (descendente)
int posicionarNavioDiagonalDescendente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio diagonal descendente não cabe no tabuleiro nesta posição.\n");
        return 0;
    }

    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) {
            printf("Erro: Navio diagonal descendente sobrepõe-se a outro navio.\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    return 1;
}

// Função para posicionar um navio diagonalmente (ascendente)
int posicionarNavioDiagonalAscendente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha - TAMANHO_NAVIO < -1 || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio diagonal ascendente não cabe no tabuleiro nesta posição.\n");
        return 0;
    }

    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha - i][coluna + i] != 0) {
            printf("Erro: Navio diagonal ascendente sobrepõe-se a outro navio.\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha - i][coluna + i] = 3;
    }
    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios no tabuleiro
    if (posicionarNavioHorizontal(tabuleiro, 2, 1)) {
        printf("Navio horizontal posicionado com sucesso.\n");
    }

    if (posicionarNavioVertical(tabuleiro, 6, 5)) {
        printf("Navio vertical posicionado com sucesso.\n");
    }

    if (posicionarNavioDiagonalDescendente(tabuleiro, 1, 1)) {
        printf("Navio diagonal descendente posicionado com sucesso.\n");
    }

    if (posicionarNavioDiagonalAscendente(tabuleiro, 8, 2)) {
        printf("Navio diagonal ascendente posicionado com sucesso.\n");
    }

    // Exibe o tabuleiro final
    printf("\nTabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
