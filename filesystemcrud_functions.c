#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define ARQUIVO "chas.txt"

void criar_cha(int codigo, const char* nome) {
    FILE *f = fopen(ARQUIVO, "a");
    if (f == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    fprintf(f, "%d:%s\n", codigo, nome);
    fclose(f);
}

char* ler_cha(int codigo) {
    FILE *f = fopen(ARQUIVO, "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return NULL;
    }

    static char resultado[MAX];
    char linha[MAX];

    while (fgets(linha, MAX, f)) {
        int codigo_lido;
        char nome[MAX];

        sscanf(linha, "%d:%[^\n]", &codigo_lido, nome);

        if (codigo_lido == codigo) {
            fclose(f);
            strcpy(resultado, nome);
            return resultado;
        }
    }

    fclose(f);
    return NULL;
}

void remover_cha(int codigo) {
    FILE *f = fopen(ARQUIVO, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!f || !temp) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    char linha[MAX];
    int codigo_lido;
    char nome[MAX];

    while (fgets(linha, MAX, f)) {
        sscanf(linha, "%d:%[^\n]", &codigo_lido, nome);

        if (codigo_lido != codigo) {
            fprintf(temp, "%d:%s\n", codigo_lido, nome);
        }
    }

    fclose(f);
    fclose(temp);

    remove(ARQUIVO);
    rename("temp.txt", ARQUIVO);
}
