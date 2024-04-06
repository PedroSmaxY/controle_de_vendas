#ifndef REGISTRARCLIENTE_H
#define REGISTRARCLIENTE_H
#include "main.h"

void registrarCliente(FILE *arquivoDat, Cliente *cliente, Produto produtosCatalogo[], int contador)
{
    int escolha;
    cliente->gastoTotal = 0;
    cliente->quantidadeProdutos = 0;

    printf("Digite seu Nome: ");
    fgets(cliente->nome, sizeof(cliente->nome) / sizeof(cliente->nome[0]), stdin);

    printf("\n-------------- Selecione os itens do catálogo --------------");

    exibirProdutoCatalogo(produtosCatalogo, contador);

    for (size_t i = 0; i < sizeof(cliente->produtos) / sizeof(cliente->produtos[0]); i++)
    {
        printf("\n\nCarrinho: %.2f, Escolha seu item pelo id [-1 -> finalizar, -2 -> mostrar a lista]: ", cliente->gastoTotal);
        scanf("%d", &escolha);
        limparBuffer();
        if (escolha > 0)
        {
            cliente->produtos[i] = produtosCatalogo[escolha - 1];
            cliente->gastoTotal += produtosCatalogo[escolha - 1].preco;
            cliente->quantidadeProdutos += 1;
        }
        else if (escolha == -1)
        {
            if (cliente->gastoTotal == 0)
            {
                printf("\nERRO: Escolha pelo menos um item do catálogo");
                printf("\nPressione ENTER para continuar. . .");
                getchar();
                continue;
            }
            break;
        }
        else
        {
            exibirProdutoCatalogo(produtosCatalogo, contador);
        }
    }

    fwrite(cliente, sizeof(Cliente), 1, arquivoDat);

    printf("\nDados salvos com sucesso!");
}

#endif