#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
} Cliente;

void cadastrarCliente() {
    Cliente cliente;
    FILE *arquivo;

    arquivo = fopen("clientes.dat", "rb+");

    if (arquivo == NULL) {
      
        arquivo = fopen("clientes.dat", "wb+");
        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo.\n");
            return;
        }
    }

    printf("Digite o código do cliente: ");
    scanf("%d", &cliente.codigo);

    Cliente temp;
    while (fread(&temp, sizeof(Cliente), 1, arquivo)) {
        if (temp.codigo == cliente.codigo) {
            printf("Já existe um cliente com o código informado.\n");
            fclose(arquivo);
            return;
        }
    }

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", cliente.nome);

    printf("Digite o endereço do cliente: ");
    scanf(" %[^\n]s", cliente.endereco);
  
    fseek(arquivo, 0, SEEK_END);

    fwrite(&cliente, sizeof(Cliente), 1, arquivo);

    printf("Cliente cadastrado com sucesso.\n");
  
    fclose(arquivo);
}

int main() {
    cadastrarCliente();
    return 0;
}
