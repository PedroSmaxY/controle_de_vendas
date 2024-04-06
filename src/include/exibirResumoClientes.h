#ifndef EXIBIRRESUMOCLIENTES_H
#define EXIBIRRESUMOCLIENTES_H
#include "main.h"

void exibirResumoClientes(FILE *arquivoDat)
{
    Cliente clientes[100];
    int i = 0;

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

    for (int j = 0; j < i; j++)
    {
        printf("\n\nNome do cliente: %s", clientes[j].nome);
        printf("Gasto total: %.2f", clientes[j].gastoTotal);
        printf("\nQuantidade de produtos comprados: %d", clientes[j].quantidadeProdutos);
    }

    printf("\n\nPressione ENTER para continuar. . .");
    getchar();
}

#endif