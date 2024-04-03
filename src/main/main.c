#include "../include/main.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Produto produtosCatalogo[50];
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
        printf("\n4 - Sair");
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
            break;
        case 3:
            registrarCliente(arquivoDat, &cliente, produtosCatalogo, contador);
            break;
        default:
            break;
        }
        if (escolhaMenu == 4)
        {
            break;
        }
    }

    return 0;
}
