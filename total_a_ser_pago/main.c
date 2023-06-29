#include <stdio.h>

float calcValorTotal(int convidados, int fimDeSemana)
{
    float tabela1[2][4] =
    {
        {1899.00, 2099.00, 2199.00, 2299.00},
        {3199.00, 3499.00, 3799.00, 3999.00}
    };

    int linha = (convidados - 1) / 50; // Ajuste para o índice da linha
    int coluna = fimDeSemana ? 1 : 0;

    return tabela1[linha][coluna];
}

float calcuValorFinal(float valorTotal, int formaPagamento)
{
    float tabela2[4] = {0.10, 0.05, 0.02, 0.00};

    return valorTotal - (valorTotal * tabela2[formaPagamento - 1]);
}

int main()
{
    int convidados, fimDeSemana, formaPagamento;

    printf("Informe a quantidade de convidados: ");
    scanf("%d", &convidados);

    printf("Informe 1 para fim de semana ou 0 para durante semana: ");
    scanf("%d", &fimDeSemana);

    printf("Informe a forma de pagamento (1 - A vista, 2 - Duas vezes, 3 - Três vezes, 4 - Quatro ou mais vezes): ");
    scanf("%d", &formaPagamento);

    float valTotal = calcValorTotal(convidados, fimDeSemana);
    float valFinal = calcuValorFinal(valTotal, formaPagamento);

    FILE *arquivo = fopen("total_a_ser_pago.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo\n");
        return 1;
    }

    fprintf(arquivo, "Valor total a ser pago: R$ %.2f\n", valTotal);
    fprintf(arquivo, "Valor final a ser pago: R$ %.2f\n", valFinal);

    fclose(arquivo);

    printf("odo que foi digitado foi salvo no 'total_a_ser_pago.txt.txt'.\n");

    return 0;
}
