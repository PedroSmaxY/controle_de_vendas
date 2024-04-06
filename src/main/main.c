#include "../include/main.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Produto produtosCatalogo[50];

    // Inicializando as variáveis do Array
    for (int i = 0; i < 50; i++)
    {
        produtosCatalogo[i].codigo = 0;
        produtosCatalogo[i].preco = 0.0;
        produtosCatalogo[i].nome[0] = '\0';
        produtosCatalogo[i].marca[0] = '\0';
    }

    Cliente cliente;
    int escolhaMenu;
    int contador = 0;

    FILE *arquivoDat = fopen("loja_roupa.dat", "wb");
    if (arquivoDat == NULL)
    {
        printf("\nErro: Arquivo loja_roupa.dat não foi possivel ser criado!");
        exit(1);
    }

    while (1)
    {
        limparConsole();
        printf("\n=================================");
        printf("\nLoja de Roupas");
        printf("\n=================================");
        printf("\n1 - Adicionar Itens ao Catálogo");
        printf("\n2 - Exibir Catálogo");
        printf("\n3 - Registrar Cliente");
        printf("\n4 - Resumo dos Clientes");
        printf("\n5 - Sair");
        printf("\n=================================");
        printf("\nDigite: ");
        scanf("%d", &escolhaMenu);
        limparBuffer();

        switch (escolhaMenu)
        {
        case 1:
            adicionarProdutoCatalogo(produtosCatalogo, sizeof(produtosCatalogo) / sizeof(produtosCatalogo[0]), &contador);
            break;
        case 2:
            limparConsole();
            exibirProdutoCatalogo(produtosCatalogo, contador);
            printf("\n\nPressione ENTER para continuar. . .");
            getchar();
            break;
        case 3:
            limparConsole();
            registrarCliente(arquivoDat, &cliente, produtosCatalogo, contador);
            break;
        case 4:
            limparConsole();
            fclose(arquivoDat);
            arquivoDat = fopen("loja_roupa.dat", "rb");
            if (arquivoDat == NULL)
            {
                printf("\nErro: Arquivo loja_roupa.dat não foi possivel ser criado!");
            }

            exibirResumoClientes(arquivoDat);
            break;
        default:
            if (escolhaMenu != 5)
            {
                printf("\nDigite uma opção correta!");
                printf("\n\nPressione ENTER para continuar. . .");
                getchar();
            }
            break;
        }

        if (escolhaMenu == 5)
            break;
    }

    return 0;
}
