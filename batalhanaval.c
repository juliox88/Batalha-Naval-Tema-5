#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

int main() {
    // ==========================================
    // INICIALIZAÇÃO DO TABULEIRO E NAVIOS
    // ==========================================
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    for (int l = 0; l < TAM_TABULEIRO; l++) {
        for (int c = 0; c < TAM_TABULEIRO; c++) {
            tabuleiro[l][c] = 0; 
        }
    }

    // Posicionando 4 navios (Valor 3)
    for (int i = 0; i < 3; i++) tabuleiro[1][1 + i] = 3;       // Horizontal
    for (int i = 0; i < 3; i++) tabuleiro[4 + i][8] = 3;       // Vertical
    for (int i = 0; i < 3; i++) tabuleiro[5 + i][1 + i] = 3;   // Diagonal
    for (int i = 0; i < 3; i++) tabuleiro[1 + i][7 - i] = 3;   // Diagonal

    // ==========================================
    // CRIAÇÃO DINÂMICA DAS HABILIDADES (5x5)
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    for (int l = 0; l < TAM_HABILIDADE; l++) {
        for (int c = 0; c < TAM_HABILIDADE; c++) {
            
            int dist_l = (l > 2) ? (l - 2) : (2 - l);
            int dist_c = (c > 2) ? (c - 2) : (2 - c);

            // CONE
            if (l <= 2 && dist_c <= l) {
                cone[l][c] = 1;
            } else {
                cone[l][c] = 0;
            }

            // CRUZ
            if (l == 2 || c == 2) {
                cruz[l][c] = 1;
            } else {
                cruz[l][c] = 0;
            }

            // OCTAEDRO
            if (dist_l + dist_c <= 2) {
                octaedro[l][c] = 1;
            } else {
                octaedro[l][c] = 0;
            }
        }
    }

    // ==========================================
    // SOBREPOSIÇÃO NO TABULEIRO PRINCIPAL

    int orig_cone_l = 2, orig_cone_c = 4;
    int orig_cruz_l = 7, orig_cruz_c = 7;
    int orig_octa_l = 8, orig_octa_c = 2;

    for (int l = 0; l < TAM_HABILIDADE; l++) {
        for (int c = 0; c < TAM_HABILIDADE; c++) {
            
            int tab_cone_l = orig_cone_l + (l - 2), tab_cone_c = orig_cone_c + (c - 2);
            int tab_cruz_l = orig_cruz_l + (l - 2), tab_cruz_c = orig_cruz_c + (c - 2);
            int tab_octa_l = orig_octa_l + (l - 2), tab_octa_c = orig_octa_c + (c - 2);

            if (cone[l][c] == 1 && tab_cone_l >= 0 && tab_cone_l < TAM_TABULEIRO && tab_cone_c >= 0 && tab_cone_c < TAM_TABULEIRO) {
                tabuleiro[tab_cone_l][tab_cone_c] = 5;
            }
            if (cruz[l][c] == 1 && tab_cruz_l >= 0 && tab_cruz_l < TAM_TABULEIRO && tab_cruz_c >= 0 && tab_cruz_c < TAM_TABULEIRO) {
                tabuleiro[tab_cruz_l][tab_cruz_c] = 5;
            }
            if (octaedro[l][c] == 1 && tab_octa_l >= 0 && tab_octa_l < TAM_TABULEIRO && tab_octa_c >= 0 && tab_octa_c < TAM_TABULEIRO) {
                tabuleiro[tab_octa_l][tab_octa_c] = 5;
            }
        }
    }

    // ==========================================
    // EXIBIÇÃO DOS RESULTADOS
    
    printf("\n========================================\n");
    printf("--- TABULEIRO FINAL (BATALHA NAVAL)  ---\n");
    printf("========================================\n");
    for (int l = 0; l < TAM_TABULEIRO; l++) {
        for (int c = 0; c < TAM_TABULEIRO; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    return 0;
}