#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerStatus(const char* arquivo)
{
    FILE* file = fopen(arquivo, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char linha[100];
    int linhaAtual = 1;

    while (fgets(linha, sizeof(linha), file) != NULL)
    {
        if (linhaAtual == 3)
        {
            int status = atoi(linha);
            if (status == 1)
            {
                printf("O contrato foi pago\n");
            }
            else if (status == 2)
            {
                printf("O contrato foi cancelado\n");
            }
            else
            {
                printf("Erro!!!\n");
            }
            break;
        }
        linhaAtual++;
    }
    fclose(file);
}

int main()
{
    const char* arquivo = "total_a_ser_pago.txt";

    lerStatus(arquivo);

    return 0;
}
