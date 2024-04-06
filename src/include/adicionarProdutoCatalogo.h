#ifndef ADICIONARPRODUTOCATALOGO_H
#define ADICIONARPRODUTOCATALOGO_H
#include "main.h"

void adicionarProdutoCatalogo(Produto produtosCatalogo[], int tamanho, int *contador)
{
    char continuar;

    limparConsole();

    for (int i = 0; i < tamanho; i++)
    {
        if (i > 0)
        {
            printf("Deseja continuar? [S/N]: ");
            scanf(" %c", &continuar);
            limparBuffer();
            if (continuar == 'N' || continuar == 'n')
                break;
        }
        produtosCatalogo[i].codigo = i + 1;
        *contador = i + 1;

        printf("\nProduto %d\n", i + 1);
        printf("\nNome: ");
        fgets(produtosCatalogo[i].nome, sizeof(produtosCatalogo[i].nome) / sizeof(produtosCatalogo[i].nome[0]), stdin);

        printf("\nMarca: ");
        fgets(produtosCatalogo[i].marca, sizeof(produtosCatalogo[i].marca) / sizeof(produtosCatalogo[i].marca[0]), stdin);

        printf("\nPreço: ");
        scanf("%f", &produtosCatalogo[i].preco);
        limparBuffer();
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