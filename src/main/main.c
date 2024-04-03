#include "../include/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura de um item
typedef struct {
    int codigo;
    char nome[50];
    char marca[50];
    int quantidade;
    float preco_unitario;
} Item;

// Função para calcular o preço total da venda de um item
float calcular_preco_total(Item item) {
    float preco_total = item.quantidade * item.preco_unitario;
    // Aplicando desconto de 10% se a quantidade for maior ou igual a três
    if (item.quantidade >= 3) {
        preco_total *= 0.9;
    }
    return preco_total;
}

int main()
{
    exemplo();
    return 0;
}
