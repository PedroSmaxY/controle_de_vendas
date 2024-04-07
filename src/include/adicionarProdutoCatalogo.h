#ifndef ADICIONARPRODUTOCATALOGO_H
#define ADICIONARPRODUTOCATALOGO_H
#include "main.h"

void adicionarProdutoCatalogo(Produto produtosCatalogo[], int tamanho, int *contador)
{
    char continuar;

    limparConsole();

    for (int i = *contador; i < tamanho; i++)
    {

        produtosCatalogo[i].quantidadeVendida = 0;
        (*contador)++;

        printf("\nProduto %d\n", i + 1);
        printf("\nNome: ");
        fgets(produtosCatalogo[i].nome, sizeof(produtosCatalogo[i].nome) / sizeof(produtosCatalogo[i].nome[0]), stdin);

        printf("\nMarca: ");
        fgets(produtosCatalogo[i].marca, sizeof(produtosCatalogo[i].marca) / sizeof(produtosCatalogo[i].marca[0]), stdin);

        int codigoExistente;
        do
        {
            codigoExistente = 0;
            printf("\nCódigo: ");
            scanf("%d", &produtosCatalogo[i].codigo);
            limparBuffer();

            for (int j = 0; j < i; j++)
            {
                if (produtosCatalogo[j].codigo == produtosCatalogo[i].codigo)
                {
                    printf("Este código já existe. Por favor, insira um novo código.\n");
                    codigoExistente = 1;
                    break;
                }
            }

        } while (codigoExistente);

        printf("\nPreço: R$");
        scanf("%f", &produtosCatalogo[i].preco);
        limparBuffer();

        printf("\nQuantidade: ");
        scanf("%d", &produtosCatalogo[i].quantidade);
        limparBuffer();

        if (i < tamanho - 1)
        {
            printf("Deseja continuar? [S/N]: ");
            scanf(" %c", &continuar);
            limparBuffer();
            if (continuar == 'N' || continuar == 'n')
                break;
        }
    }

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (produtosCatalogo[j].preco < produtosCatalogo[j + 1].preco)
            {
                Produto temp = produtosCatalogo[j];
                produtosCatalogo[j] = produtosCatalogo[j + 1];
                produtosCatalogo[j + 1] = temp;
            }
        }
    }
}

#endif