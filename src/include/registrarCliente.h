#ifndef REGISTRARCLIENTE_H
#define REGISTRARCLIENTE_H
#include "registrarCliente.h"
#include "main.h"

void registrarCliente(FILE *arquivoDat, Cliente *cliente, Produto produtosCatalogo[], int contador)
{
    int escolha;

    limparConsole();
    printf("Digite seu Nome: ");
    fgets(cliente->nome, sizeof(cliente->nome) / sizeof(cliente->nome[0]), stdin);

    limparConsole();
    exibirProdutoCatalogo(produtosCatalogo, contador);

    for (size_t i = 0; i < sizeof(cliente->produtos) / sizeof(cliente->produtos[0]); i++)
    {
        printf("Escolha seu item pelo id [-1 para sair, -2 para mostrar a lista]: ");
        scanf("%d", escolha);
        limparBuffer();
        if (escolha > 0)
        {
            cliente->produtos[i] = produtosCatalogo[escolha];
        }
        else if (escolha == -1)
        {
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