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
    int quantidadeClientes = 0;
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
        printf("\n-------- Loja de Roupas ---------");
        printf("\n=================================");
        printf("\n1 - Adicionar Itens ao Catálogo");
        printf("\n2 - Exibir Catálogo");
        printf("\n3 - Registrar Cliente");
        printf("\n4 - Resumo Geral");
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
            if (contador == 0)
            {
                printf("\nO catálogo está vazio.");
                printf("\n\nPressione ENTER para continuar. . .");
                getchar();
                break;
            }
            limparConsole();
            exibirProdutoCatalogo(produtosCatalogo, contador);
            printf("\n\nPressione ENTER para continuar. . .");
            getchar();
            break;
        case 3:
            if (contador == 0)
            {
                printf("\nErro: Não há produtos no catálogo. Adicione um produto antes de registrar um cliente.");
                printf("\n\nPressione ENTER para continuar. . .");
                getchar();
                break;
            }
            if (arquivoDat != NULL)
            {
                fclose(arquivoDat);
            }
            arquivoDat = fopen("loja_roupa.dat", "ab");
            if (arquivoDat == NULL)
            {
                printf("\nErro: Arquivo loja_roupa.dat não foi possivel ser criado!");
                exit(1);
            }
            limparConsole();
            registrarCliente(arquivoDat, &cliente, produtosCatalogo, contador, &quantidadeClientes);
            break;
        case 4:
            fclose(arquivoDat);
            arquivoDat = fopen("loja_roupa.dat", "rb");
            if (arquivoDat == NULL)
            {
                printf("\nErro: Arquivo loja_roupa.dat não foi possivel ser criado!");
            }

            fseek(arquivoDat, 0, SEEK_END);
            long tamanhoArquivo = ftell(arquivoDat);
            rewind(arquivoDat);

            if (tamanhoArquivo == 0)
            {
                printf("\nErro: Não há clientes cadastrados.");
                printf("\n\nPressione ENTER para continuar. . .");
                getchar();
                break;
            }

            limparConsole();

            exibirResumoClientes(arquivoDat, quantidadeClientes);
            exibirResumoVendas(produtosCatalogo, contador);

            printf("\n\nPressione ENTER para continuar. . .");
            getchar();
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
        {
            fclose(arquivoDat);
            break;
        }
    }

    return 0;
}
