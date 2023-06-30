#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codUsuario;
    int qtd_convidados;
    char hrInicio[10];
    char hrFim[10];
    char tema[100];
} Festa;

void buscar_festas_por_horario(const char* horario_inicial)
{
    FILE* arquivo = fopen("festas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo 'festas.txt'\n");
        return;
    }

    Festa festa;
    int festas_encontradas = 0;

    while (fscanf(arquivo, "------ Festa %*d ------\n") != EOF)
    {
        fscanf(arquivo, "Codigo do usuario: %d\n", &festa.codUsuario);
        fscanf(arquivo, "Quantidade de convidados: %d\n", &festa.qtd_convidados);
        fscanf(arquivo, "Horario de inicio: %s\n", festa.hrInicio);
        fscanf(arquivo, "Horario de fim: %s\n", festa.hrFim);
        fscanf(arquivo, "Tema da festa: %[^\n]\n", festa.tema);
        fscanf(arquivo, "------------------\n");

        if (strcmp(festa.hrInicio, horario_inicial) == 0)
        {
            printf("Código do usuário: %d\n", festa.codUsuario);
            printf("Quantidade de convidados: %d\n", festa.qtd_convidados);
            printf("Horario de inicio: %s\n", festa.hrInicio);
            printf("Horario de fim: %s\n", festa.hrFim);
            printf("Tema da festa: %s\n", festa.tema);
            printf("------------------\n");
            festas_encontradas++;
        }
    }

    if (festas_encontradas == 0)
    {
        printf("Nenhuma festa encontrada no horário %s\n", horario_inicial);
    }

    fclose(arquivo);
}

void buscar_festas_por_data(const char* data)
{
    FILE* arquivo = fopen("festas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo 'festas.txt'\n");
        return;
    }

    Festa festa;
    int festas_encontradas = 0;

    while (fscanf(arquivo, "------ Festa %*d ------\n") != EOF)
    {
        fscanf(arquivo, "Codigo do usuario: %d\n", &festa.codUsuario);
        fscanf(arquivo, "Quantidade de convidados: %d\n", &festa.qtd_convidados);
        fscanf(arquivo, "Data: %s\n", festa.data);
        fscanf(arquivo, "Horario de inicio: %s\n", festa.hrInicio);
        fscanf(arquivo, "Horario de fim: %s\n", festa.hrFim);
        fscanf(arquivo, "Tema da festa: %[^\n]\n", festa.tema);
        fscanf(arquivo, "------------------\n");

        if (strcmp(festa.data, data) == 0)
        {
            printf("Código do usuário: %d\n", festa.codUsuario);
            printf("Quantidade de convidados: %d\n", festa.qtd_convidados);
            printf("Data: %s\n", festa.data);
            printf("Horario de inicio: %s\n", festa.hrInicio);
            printf("Horario de fim: %s\n", festa.hrFim);
            printf("Tema da festa: %s\n", festa.tema);
            printf("------------------\n");
            festas_encontradas++;
        }
    }

    if (festas_encontradas == 0)
    {
        printf("Nenhuma festa encontrada na data %s\n", data);
    }

    fclose(arquivo);
}


int main()
{
    char horario_inicial[10];
    printf("Digite o horário inicial da festa (HH:MM): ");
    scanf("%s", horario_inicial);

    buscar_festas_por_horario(horario_inicial);

    return 0;
}
