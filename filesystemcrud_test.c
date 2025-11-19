#include <assert.h>
#include <string.h>
#include <stdio.h>

void criar_cha(int codigo, const char* nome);
char* ler_cha(int codigo);
void remover_cha(int codigo);

int main() {

    FILE *f = fopen("chas.txt", "w");
    fclose(f);

    criar_cha(1, "Camomila");
    criar_cha(2, "Hortela");

    assert(strcmp(ler_cha(1), "Camomila") == 0);
    assert(strcmp(ler_cha(2), "Hortela") == 0);

    remover_cha(1);

    assert(ler_cha(1) == NULL);       // Deve ter sido removido
    assert(strcmp(ler_cha(2), "Hortela") == 0); // Deve continuar existindo

    return 0;
}
