#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro nesta posição.\n");
        return 0;  // Retorna 0 em caso de erro
    }

    // Verifica se a posição está livre
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            printf("Erro: Navio horizontal sobrepõe-se a outro navio.\n");
            return 0;  // Retorna 0 em caso de erro
        }
    }

    // Posiciona o navio no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;  // 3 representa a parte do navio
    }
    return 1;  // Retorna 1 se o navio foi posicionado com sucesso
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro nesta posição.\n");
        return 0;  // Retorna 0 em caso de erro
    }

    // Verifica se a posição está livre
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            printf("Erro: Navio vertical sobrepõe-se a outro navio.\n");
            return 0;  // Retorna 0 em caso de erro
        }
    }

    // Posiciona o navio no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;  // 3 representa a parte do navio
    }
    return 1;  // Retorna 1 se o navio foi posicionado com sucesso
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declara o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (representando água)
    inicializarTabuleiro(tabuleiro);

    // Definindo as posições dos navios diretamente no código
    int linhaNavioVertical = 2, colunaNavioVertical = 4;  // Posição do navio vertical
    int linhaNavioHorizontal = 6, colunaNavioHorizontal = 1;  // Posição do navio horizontal

    // Tenta posicionar os navios no tabuleiro
    if (posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Navio vertical posicionado com sucesso.\n");
    }

    if (posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Navio horizontal posicionado com sucesso.\n");
    }

    // Exibe o tabuleiro final
    printf("Tabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

