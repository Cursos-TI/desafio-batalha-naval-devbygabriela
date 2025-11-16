#include <stdio.h>

// Nivel Novato
void nivelNovato() {
    printf("\n========== NÍVEL NOVATO ==========\n");

    const int LIN = 5;
    const int COL = 5;

    const int navA_inicioX = 0;
    const int navA_inicioY = 1;
    const int navA_tamanho = 3;

    const int navB_inicioX = 3;
    const int navB_inicioY = 0;
    const int navB_tamanho = 4;

    printf("Tabuleiro: %dx%d\n", LIN, COL);

    printf("\nNavio A (vertical):\n");
    for (int i = 0; i < navA_tamanho; i++) {
        int x = navA_inicioX + i;
        int y = navA_inicioY;
        printf("Parte %d -> (%d, %d)\n", i + 1, x, y);
    }

    printf("\nNavio B (horizontal):\n");
    for (int i = 0; i < navB_tamanho; i++) {
        int x = navB_inicioX;
        int y = navB_inicioY + i;
        printf("Parte %d -> (%d, %d)\n", i + 1, x, y);
    }

    printf("\n(Obs: coordenadas começam em 0)\n");
    printf("====================================\n");
}

// Nivel Aventureiro
void nivelAventureiro() {
    printf("\n========== NÍVEL AVENTUREIRO ==========\n");

    const int N = 10;
    int tabuleiro[10][10];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tabuleiro[i][j] = 0;

    int n1_x = 2, n1_y = 3, n1_t = 4;
    for (int k = 0; k < n1_t; k++)
        tabuleiro[n1_x + k][n1_y] = 3;

    int n2_x = 7, n2_y = 5, n2_t = 3;
    for (int k = 0; k < n2_t; k++)
        tabuleiro[n2_x][n2_y + k] = 3;

    int n3_x = 0, n3_y = 0, n3_t = 3;
    for (int k = 0; k < n3_t; k++)
        tabuleiro[n3_x + k][n3_y + k] = 3;

    int n4_x = 1, n4_y = 9, n4_t = 3;
    for (int k = 0; k < n4_t; k++)
        tabuleiro[n4_x + k][n4_y - k] = 3;

    printf("\nTabuleiro 10x10:\n\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = vazio, 3 = navio\n");
    printf("====================================\n");
}

// Limpa matriz
void limpaMatriz(int M, int mat[20][20]) {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            mat[i][j] = 0;
}

// Cone
void habilidadeCone() {
    printf("\n--- Habilidade: CONE ---\n");

    const int M = 5;
    int mat[20][20];
    limpaMatriz(M, mat);

    mat[0][2] = 1;
    mat[1][1] = 1;
    mat[1][2] = 1;
    mat[1][3] = 1;

    for (int j = 0; j < 5; j++)
        mat[2][j] = 1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Octaedro
void habilidadeOctaedro() {
    printf("\n--- Habilidade: OCTAEDRO ---\n");

    const int M = 3;
    int mat[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Cruz
void habilidadeCruz() {
    printf("\n--- Habilidade: CRUZ ---\n");

    const int M = 3;
    int mat[3][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Nivel Mestre
void nivelMestre() {
    printf("\n========== NÍVEL MESTRE ==========\n");

    habilidadeCone();
    habilidadeOctaedro();
    habilidadeCruz();

    printf("====================================\n");
}

// Principal
int main() {
    int opcao;

    do {
        printf("\n=============================================\n");
        printf("              BATALHA NAVAL - MENU            \n");
        printf("=============================================\n");
        printf("1 - Nível Novato\n");
        printf("2 - Nível Aventureiro\n");
        printf("3 - Nível Mestre\n");
        printf("0 - Sair\n");
        printf("=============================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            nivelNovato();
            break;
        case 2:
            nivelAventureiro();
            break;
        case 3:
            nivelMestre();
            break;
        case 0:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
