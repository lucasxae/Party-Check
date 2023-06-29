#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

void cadastrar_fornecedor();

int main()
{
    cadastrar_fornecedor();
    return 0;
}

void cadastrar_fornecedor()
{
    int codigo[SIZE], telefone[SIZE];
    char nome_buffet[SIZE][SIZE];

    int posicao_vetor = 0;
    FILE *file;
    file = fopen("fornecedores.txt", "w");

    while (1)
    {
        int novo_codigo;

        printf("Digite o seu codigo ou um valor negativo para sair: ");
        scanf("%d", &novo_codigo);
        if (novo_codigo < 0)
            break;

        // Verificar se o código já existe
        int codigo_repetido = 0;
        for (int i = 0; i < posicao_vetor; i++)
        {
            if (codigo[i] == novo_codigo)
            {
                codigo_repetido = 1;
                break;
            }
        }

        if (codigo_repetido)
        {
            printf("Esse código já foi cadastrado. Digite outro código.\n");
            continue;
        }

        codigo[posicao_vetor] = novo_codigo;
        fprintf(file, "\n Codigo: %d", codigo[posicao_vetor]);


        printf("Digite o seu telefone: ");
        scanf("%d", &telefone[posicao_vetor]);
        fprintf(file, "\n Telefone: %d", telefone[posicao_vetor]);

        printf("Digite o nome do seu buffet: ");
        scanf("%199s", nome_buffet[posicao_vetor]);
        fprintf(file, "\n Nome do buffet: %s \n ------------------", nome_buffet[posicao_vetor]);

        posicao_vetor++;
    }

    fclose(file);

    for(int i = 0; i < posicao_vetor; i++)
    {
        printf("\n\n Codigo: %d", codigo[i]);
        printf("\n\n Telefone: %d", telefone[i]);
        printf("\n\n Nome do buffet: %s\n\n ------- \n \n", nome_buffet[i]);
    }

}
