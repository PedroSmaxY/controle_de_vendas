#ifndef EXIBIRRESUMOCLIENTES_H
#define EXIBIRRESUMOCLIENTES_H
#include "main.h"

void exibirResumoClientes(FILE *arquivoDat)
{
    Cliente cliente;

    limparConsole();

    rewind(arquivoDat);

    while (fread(&cliente, sizeof(Cliente), 1, arquivoDat))
    {
        printf("\n\nNome do cliente: %s", cliente.nome);
        printf("Gasto total: %.2f", cliente.gastoTotal);
        printf("\nQuantidade de produtos comprados: %d", cliente.quantidadeProdutos);

    }

    printf("\n\nPressione ENTER para continuar. . .");
    getchar();
}

#endif