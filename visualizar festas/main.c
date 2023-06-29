#include <stdio.h>
void lerArquivo(const char* festas) {
    FILE* arquivo = fopen(festas, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha); 
    }
  
    fclose(arquivo); 
}

int main() {
    const char* festas = "festas.txt";
    lerArquivo(festas);

    return 0;
}
