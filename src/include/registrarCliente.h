#ifndef REGISTRARCLIENTE_H
#define REGISTRARCLIENTE_H
#include "main.h"

void registrarCliente(FILE *arquivoDat, Cliente *cliente, Produto produtosCatalogo[], int contador, int *quantidadeClientes)
{
    int escolha;
    cliente->gastoTotal = 0;
    cliente->quantidadeProdutos = 0;
    (*quantidadeClientes)++;

    printf("Digite seu Nome: ");
    fgets(cliente->nome, sizeof(cliente->nome) / sizeof(cliente->nome[0]), stdin);

    printf("\n-------------- Selecione os itens do catálogo --------------");
    printf("\n\n10%% de Desconto se Comprar Três ou Mais Itens! [APLICADO NO RESUMO!]");

    exibirProdutoCatalogo(produtosCatalogo, contador);

    for (size_t i = 0; i < sizeof(cliente->produtos) / sizeof(cliente->produtos[0]); i++)
    {
        printf("\n\n[Carrinho: %.2f] Escolha seu item pelo Código [-1 -> finalizar, -2 -> mostrar a lista]: ", cliente->gastoTotal);
        scanf("%d", &escolha);
        limparBuffer();
        if (escolha >= 0)
        {
            int encontrado = 0;
            for (int j = 0; j < contador; j++)
            {
                if (produtosCatalogo[j].codigo == escolha)
                {
                    encontrado = 1;
                    if (produtosCatalogo[j].quantidade > 0)
                    {
                        cliente->produtos[i] = produtosCatalogo[j];
                        cliente->gastoTotal += produtosCatalogo[j].preco;
                        cliente->quantidadeProdutos += 1;
                        produtosCatalogo[j].quantidade--;
                        produtosCatalogo[j].quantidadeVendida++;
                        break;
                    }
                    else
                    {
                        printf("\nERRO: PRODUTO ESGOTADO");
                        i--;
                        break;
                    }
                }
            }
            if (!encontrado)
            {
                printf("\nERRO: CÓDIGO do produto não encontrado");
                i--;
            }
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