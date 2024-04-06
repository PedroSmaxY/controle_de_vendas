#ifndef MAIN_H
#define MAIN_H

typedef struct
{
    int codigo;
    char nome[50];
    char marca[50];
    float preco;
} Produto;

typedef struct
{
    char nome[50];
    Produto produtos[50];
    int quantidadeProdutos;
    float gastoTotal;
} Cliente;

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "limparBuffer.h"
#include "limparConsole.h"
#include "adicionarProdutoCatalogo.h"
#include "exibirProdutoCatalogo.h"
#include "registrarCliente.h"
#include "exibirResumoClientes.h"

#endif
