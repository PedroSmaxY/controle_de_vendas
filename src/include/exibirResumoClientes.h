#ifndef EXIBIRRESUMOCLIENTES_H
#define EXIBIRRESUMOCLIENTES_H
#include "calcularDesconto.h"
#include "main.h"

void exibirResumoClientes(FILE *arquivoDat, int quantidadeClientes)
{
    Cliente clientes[100];
    int i = 0;
    float faturamentoBruto = 0;

    rewind(arquivoDat);

    while (fread(&clientes[i], sizeof(Cliente), 1, arquivoDat))
    {
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k < i - j - 1; k++)
        {
            if (clientes[k].gastoTotal < clientes[k + 1].gastoTotal)
            {
                Cliente temp = clientes[k];
                clientes[k] = clientes[k + 1];
                clientes[k + 1] = temp;
            }
        }
    }

    printf("\n-------------- CLIENTES --------------");
    printf("\nClientes Cadastrados: %d", quantidadeClientes);
    printf("\n--------------------------------------");

    for (int j = 0; j < i; j++)
    {
        printf("\nNome do cliente: %s", clientes[j].nome);
        printf("\nGasto total: R$%.2f", clientes[j].gastoTotal);
        printf("\nQuantidade de produtos comprados: %d", clientes[j].quantidadeProdutos);
        float precoComDesconto = calcularDesconto(clientes[j]);
        if (precoComDesconto > 0)
        {
            printf("\n10%% de desconto aplicado a cada produto: R$%.2f", precoComDesconto);
            faturamentoBruto += precoComDesconto;
        }
        else
        {
            faturamentoBruto += clientes[j].gastoTotal;
        }

        printf("\n--------------------------------------");
    }
    printf("\nFaturamento Bruto da Loja: R$%.2f", faturamentoBruto);
}

#endif