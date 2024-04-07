#ifndef CALCULARDESCONTO_H
#define CALCULARDESCONTO_H
#include "main.h"

float calcularDesconto(Cliente cliente)
{
    float precoComDesconto = 0;
    if (cliente.quantidadeProdutos >= 3)
    {
        for (int i = 0; i < cliente.quantidadeProdutos; i++)
        {
            precoComDesconto += cliente.produtos[i].preco * 0.9;
        }
    }
    return precoComDesconto;
}

#endif