#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codUsuario;
    int qtd_convidados;
    char hrInicio[10];
    char hrFim[10];
    char tema[100];
} Festa;

//codigo para cadastrar a festa
void cadastro_festa()
{
    int qtd_festas;
    printf("Quantas festas deseja cadastrar? ");
    scanf("%d", &qtd_festas);

    Festa* festas = (Festa*) malloc(qtd_festas * sizeof(Festa));

    for (int i = 0; i < qtd_festas; i++)
    {
        printf("\n--- Cadastro da Festa %d ---\n", i+1);

        printf("Codigo do usuario: ");
        scanf("%d", &festas[i].codUsuario);

        printf("Quantidade de convidados: ");
        scanf("%d", &festas[i].qtd_convidados);

        printf("Horario de inicio (HH:MM): ");
        scanf("%s", festas[i].hrInicio);

        printf("Horario de fim (HH:MM): ");
        scanf("%s", festas[i].hrFim);

        printf("Tema da festa: ");
        scanf(" %[^\n]s", festas[i].tema);
    }

    FILE *arquivo;
    arquivo = fopen("festas.txt", "w");


    if (arquivo == NULL)
    {
        printf("Erro ao abrir\n");
        return 1;
    }

    for (int i = 0; i < qtd_festas; i++)
    {
        fprintf(arquivo, "------ Festa %d ------\n", i+1);
        fprintf(arquivo, "Codigo do usuario: %d\n", festas[i].codUsuario);
        fprintf(arquivo, "Quantidade de convidados: %d\n", festas[i].qtd_convidados);
        fprintf(arquivo, "Horario de inicio: %s\n", festas[i].hrInicio);
        fprintf(arquivo, "Horario de fim: %s\n", festas[i].hrFim);
        fprintf(arquivo, "Tema da festa: %s\n", festas[i].tema);
        fprintf(arquivo, "------------------\n");
    }

    fclose(arquivo);
    free(festas);

    printf("Todo que foi digitado foi salvo no 'festas.txt'.\n");

    return 0;
}

//rodando todo o codigo
int main()
{
    printf("-------CADASTRO DA FESTA-------\n");
    cadastro_festa();
}
