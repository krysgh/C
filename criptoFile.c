#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARQUIVO "criptoFile.txt"
#define TAM 1024
#define CHAVE_CESAR 3

// --- Funções de Criptografia ---
void cifra_cesar(char *texto, int chave) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            char base = islower(texto[i]) ? 'a' : 'A';
            texto[i] = (texto[i] - base + chave) % 26 + base;
        }
    }
}

void decifra_cesar(char *texto, int chave) {
    cifra_cesar(texto, 26 - (chave % 26)); // inverso da cifra
}

// --- CRUD ---
void adicionar() {
    char entrada[TAM];
    printf("Digite o texto a ser adicionado: ");
    getchar(); // limpar buffer
    fgets(entrada, TAM, stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // remove \n

    cifra_cesar(entrada, CHAVE_CESAR);

    FILE *fp = fopen(ARQUIVO, "a");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    fprintf(fp, "%s\n", entrada);
    fclose(fp);
    printf("Registro adicionado com sucesso!\n");
}


void listar() {
    char linha[TAM];
    FILE *fp = fopen(ARQUIVO, "r");
    if (fp == NULL) {
        printf("Arquivo vazio ou não encontrado.\n");
        return;
    }

    printf("\n--- Arquivo Descriptografado ---\n");
    while (fgets(linha, TAM, fp)) {
        linha[strcspn(linha, "\n")] = '\0';
        decifra_cesar(linha, CHAVE_CESAR);
        printf("- %s\n", linha);
    }
    fclose(fp);
}

void atualizar() {
    char alvo[TAM], novo[TAM], linha[TAM];
    int encontrou = 0;

    printf("Digite o texto a ser atualizado: ");
    getchar();
    fgets(alvo, TAM, stdin);
    alvo[strcspn(alvo, "\n")] = '\0';

    printf("Digite o novo texto: ");
    fgets(novo, TAM, stdin);
    novo[strcspn(novo, "\n")] = '\0';

    FILE *fp = fopen(ARQUIVO, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    cifra_cesar(alvo, CHAVE_CESAR);
    cifra_cesar(novo, CHAVE_CESAR);

    while (fgets(linha, TAM, fp)) {
        linha[strcspn(linha, "\n")] = '\0';
        if (!encontrou && strcmp(linha, alvo) == 0) {
            fprintf(temp, "%s\n", novo);
            encontrou = 1;
        } else {
            fprintf(temp, "%s\n", linha);
        }
    }

    fclose(fp);
    fclose(temp);
    remove(ARQUIVO);
    rename("temp.txt", ARQUIVO);

    if (encontrou)
        printf("Registro atualizado com sucesso.\n");
    else
        printf("Registro não encontrado.\n");
}

void excluir() {
    char alvo[TAM], linha[TAM];
    int encontrou = 0;

    printf("Digite o texto a ser excluído: ");
    getchar();
    fgets(alvo, TAM, stdin);
    alvo[strcspn(alvo, "\n")] = '\0';

    FILE *fp = fopen(ARQUIVO, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    cifra_cesar(alvo, CHAVE_CESAR);

    while (fgets(linha, TAM, fp)) {
        linha[strcspn(linha, "\n")] = '\0';
        if (!encontrou && strcmp(linha, alvo) == 0) {
            encontrou = 1;
            continue; // pula a linha
        }
        fprintf(temp, "%s\n", linha);
    }

    fclose(fp);
    fclose(temp);
    remove(ARQUIVO);
    rename("temp.txt", ARQUIVO);

    if (encontrou)
        printf("Registro excluído com sucesso.\n");
    else
        printf("Registro não encontrado.\n");
}

// --- Menu ---
void menu() {
    int op;
    do {
        printf("\n---- MENU ----\n");
        printf("1. Adicionar\n");
        printf("2. Listar\n");
        printf("3. Atualizar\n");
        printf("4. Excluir\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1: adicionar(); break;
            case 2: listar(); break;
            case 3: atualizar(); break;
            case 4: excluir(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (op != 0);
}

int main() {
    menu();
    return 0;
}
