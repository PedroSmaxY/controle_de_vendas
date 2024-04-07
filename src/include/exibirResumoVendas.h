#ifndef EXIBIRRESUMOVENDAS_H
#define EXIBIRRESUMOVENDAS_H
#include "main.h"

void exibirResumoVendas(Produto produtosCatalogo[], int contador)
{
    int maxVendas = 0;
    Produto maisVendido;
    int minVendas = __INT_MAX__;
    Produto menosVendido;

    for (int i = 0; i < contador; i++)
    {
        if (produtosCatalogo[i].quantidadeVendida > maxVendas)
        {
            maxVendas = produtosCatalogo[i].quantidadeVendida;
            maisVendido = produtosCatalogo[i];
        }
        if (produtosCatalogo[i].quantidadeVendida < minVendas)
        {
            minVendas = produtosCatalogo[i].quantidadeVendida;
            menosVendido = produtosCatalogo[i];
        }
    }
    printf("\n\nO produto mais vendido foi %s da marca %s com %d vendas.", maisVendido.nome, maisVendido.marca, maxVendas);
    printf("\n\nO produto menos vendido foi %s da marca %s com %d vendas.", menosVendido.nome, menosVendido.marca, minVendas);
}

#endif