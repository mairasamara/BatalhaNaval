#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ ");  // Representa água
            } else if (tabuleiro[i][j] == 3) {
                printf("N ");  // Representa navio
            } else if (tabuleiro[i][j] == 5) {
                printf("X ");  // Representa área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para posicionar um navio no tabuleiro (horizontal ou vertical)
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    if (direcao == 0) {  // Horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;  // Verifica se cabe no tabuleiro

        // Verifica se as posições estão livres
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }

        // Posiciona o navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3;
        }
    } else {  // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;  // Verifica se cabe no tabuleiro

        // Verifica se as posições estão livres
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }

        // Posiciona o navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }

    return 1;  // Sucesso
}

// Função para aplicar a habilidade Cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplica a habilidade no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha - 2 + i;  // Ajusta para a origem
                int coluna = origemColuna - 2 + j;

                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linha][coluna] == 0 || tabuleiro[linha][coluna] == 3) {  // Não sobrescrever navios
                        tabuleiro[linha][coluna] = 5;  // Marca a área afetada
                    }
                }
            }
        }
    }
}

// Função para aplicar a habilidade Cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplica a habilidade no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha - 2 + i;  // Ajusta para a origem
                int coluna = origemColuna - 2 + j;

                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linha][coluna] == 0 || tabuleiro[linha][coluna] == 3) {  // Não sobrescrever navios
                        tabuleiro[linha][coluna] = 5;  // Marca a área afetada
                    }
                }
            }
        }
    }
}

// Função para aplicar a habilidade Octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int origemLinha, int origemColuna) {
    int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplica a habilidade no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha - 2 + i;  // Ajusta para a origem
                int coluna = origemColuna - 2 + j;

                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linha][coluna] == 0 || tabuleiro[linha][coluna] == 3) {  // Não sobrescrever navios
                        tabuleiro[linha][coluna] = 5;  // Marca a área afetada
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios no tabuleiro
    posicionarNavio(tabuleiro, 2, 1, 0);  // Navio horizontal
    posicionarNavio(tabuleiro, 6, 5, 1);  // Navio vertical

    // Aplica as habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, 3, 3);
    aplicarHabilidadeCruz(tabuleiro, 5, 5);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);

    // Exibe o tabuleiro final
    printf("\nTabuleiro final:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
