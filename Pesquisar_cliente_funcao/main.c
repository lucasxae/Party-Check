#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
} Cliente;

void pesquisarClientePorNome() {
    char nomePesquisado[50];
    printf("Digite o nome do cliente que deseja pesquisar: ");
    scanf("%s", nomePesquisado);

    FILE* arquivo = fopen("clientes.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        return;
    }

    Cliente cliente;

    int encontrado = 0;

    while (fscanf(arquivo, "------ Cliente %*d ------\n") == 0) {
        if (fscanf(arquivo, "C�digo do cliente: %d\n", &cliente.codigo) == 1 &&
            fscanf(arquivo, "Nome do cliente: %[^\n]\n", cliente.nome) == 1 &&
            fscanf(arquivo, "Endere�o do cliente: %[^\n]\n", cliente.endereco) == 1) {

            if (strcmp(cliente.nome, nomePesquisado) == 0) {
                printf("\n--- Cliente Encontrado ---\n");
                printf("C�digo do cliente: %d\n", cliente.codigo);
                printf("Nome do cliente: %s\n", cliente.nome);
                printf("Endere�o do cliente: %s\n", cliente.endereco);
                printf("-------------------------\n");
                encontrado = 1;
            }
        }
    }

    if (!encontrado) {
        printf("Cliente nao encontrado.\n");
    }

    fclose(arquivo);
}

//////////////////


void pesquisarClientePorCodigo() {
    int codigoPesquisado;
    printf("Digite o c�digo do cliente que deseja pesquisar: ");
    scanf("%d", &codigoPesquisado);

    FILE* arquivo = fopen("clientes.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        return;
    }

    Cliente cliente;

    int encontrado = 0;

    while (fscanf(arquivo, "------ Cliente %d ------\n", &cliente.codigo) == 1) {
        fscanf(arquivo, "C�digo do cliente: %d\n", &cliente.codigo);
        fscanf(arquivo, "Nome do cliente: %[^\n]\n", cliente.nome);
        fscanf(arquivo, "Endere�o do cliente: %[^\n]\n", cliente.endereco);

        if (cliente.codigo == codigoPesquisado) {
            printf("\n--- Cliente Encontrado ---\n");
            printf("C�digo do cliente: %d\n", cliente.codigo);
            printf("Nome do cliente: %s\n", cliente.nome);
            printf("Endere�o do cliente: %s\n", cliente.endereco);
            printf("-------------------------\n");
            encontrado = 1;
            break;  // Encerra o loop ap�s encontrar o cliente
        }
    }

    if (!encontrado) {
        printf("Cliente n�o encontrado.\n");
    }

    fclose(arquivo);
}








int main() {
    printf("------- Cadastro de Cliente -------\n");
    pesquisarClientePorNome();
    return 0;
}
