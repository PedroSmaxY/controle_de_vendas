#ifndef EXIBIRPRODUTOCATALOGO_H
#define EXIBIRPRODUTOCATALOGO_H
#include "main.h"

void exibirProdutoCatalogo(Produto produtosCatalogo[], int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        printf("\n\nCódigo: %d", produtosCatalogo[i].codigo);
        printf("\nNome: %s", produtosCatalogo[i].nome);
        printf("Marca: %s", produtosCatalogo[i].marca);
        printf("Preço: %.2f", produtosCatalogo[i].preco);
    }
}

#endif