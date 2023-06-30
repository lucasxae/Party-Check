#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct {
    int codigo;
    char telefone[20];
    char nomeBuffet[50];
} Buffet;

void pesquisar_fornecedor_por_codigo() {
    int codigo_pesquisado;
    printf("Digite o código do fornecedor que deseja pesquisar: ");
    scanf("%d", &codigo_pesquisado);

    FILE* arquivo = fopen("fornecedores.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo fornecedores.txt\n");
        return;
    }

    int codigo;
    int telefone;
    char nome_buffet[SIZE];

    int encontrado = 0;

    while (fscanf(arquivo, " Codigo: %d", &codigo) == 1) {
        fscanf(arquivo, "\n Telefone: %d", &telefone);
        fscanf(arquivo, "\n Nome do buffet: %[^\n]", nome_buffet);
        fscanf(arquivo, "\n ------------------");

        if (codigo == codigo_pesquisado) {
            printf("\n--- Fornecedor Encontrado ---\n");
            printf("Código do fornecedor: %d\n", codigo);
            printf("Telefone: %d\n", telefone);
            printf("Nome do buffet: %s\n", nome_buffet);
            printf("-------------------------\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Fornecedor não encontrado.\n");
    }

    fclose(arquivo);
}


void pesquisar_fornecedor_por_nome() {
    char nome_pesquisado[SIZE];
    printf("Digite o nome do buffet do fornecedor que deseja pesquisar: ");
    scanf(" %[^\n]", nome_pesquisado);

    FILE* arquivo = fopen("fornecedores.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo fornecedores.txt\n");
        return;
    }

    int codigo;
    int telefone;
    char nome_buffet[SIZE];

    int encontrado = 0;

    while (fscanf(arquivo, " Codigo: %d", &codigo) == 1) {
        fscanf(arquivo, "\n Telefone: %d", &telefone);
        fscanf(arquivo, "\n Nome do buffet: %[^\n]", nome_buffet);
        fscanf(arquivo, "\n ------------------");

        if (nome_pesquisado == 0) {
            printf("\n--- Fornecedor Encontrado ---\n");
            printf("Código do fornecedor: %d\n", codigo);
            printf("Telefone: %d\n", telefone);
            printf("Nome do buffet: %s\n", nome_buffet);
            printf("-------------------------\n");
            encontrado = 1;
            break;  // Interrompe o loop assim que o fornecedor for encontrado
        }
    }

    if (!encontrado) {
        printf("Fornecedor não encontrado.\n");
    }

    fclose(arquivo);
}



int main() {
    pesquisar_fornecedor_por_codigo();
    return 0;
}
