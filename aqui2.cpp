#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>

struct cliente {
        char nome[50];
        char produto[200];
        char marca[100];
        float valor;
        char code[50];

    };
typedef struct cliente cliente;
    


int main(void) {
	FILE* teste;
	teste = fopen("Vendas.txt", "a");
    int cont = 0;
    int pos[1000];
    int cont3 = 0;
    char escolha[3];
    char escolha2[3];
    int valorCarrinho = 0;
    int quantidade = 0;
    int cont2 = 0;
    cliente pessoa[1000];


    system("cls");

    setlocale(LC_ALL, "Portuguese");
    
    
    while(true){
    	printf("Deseja processar uma nova compra?: ");
    	fgets(escolha2, 3, stdin);
    	if(escolha2[0] == '0'){
    		break;
		}
		cont2++;
    	
    	printf("Nome do cliente: ");
    	fgets(pessoa[cont].nome, 30, stdin);

		fflush(stdin);
    	while(true){
		
    

    printf("Qual produto deseja comprar? ");
    fgets(pessoa[cont].produto, 100, stdin);

    printf("Qual a marca do produto? ");
    fgets(pessoa[cont].marca, 100, stdin);
	
	printf("Qual o código do produto? ");
    fgets(pessoa[cont].code, 100, stdin);

    printf("Qual o valor do produto? ");
    scanf("%f", &pessoa[cont].valor);
    
    fflush(stdin);
    
    printf("Deseja realizar outra compra? (1 = sim, 0 = não): ");
    fgets(escolha, 3, stdin);
    cont++;
   
     if(escolha[0] == '0'){
     	system("cls");
     	pos[cont] = 7;
    	break;
	}
	 system("cls");

    
		}
	}
	
	for(int i = 0; i<cont2; i++){
		fprintf(teste, "=======================\n");
		fprintf(teste, "Nome: %s", pessoa[i].nome);
		while(true){
		if(pos[cont3] == 7){
			printf("%d", cont3);
			cont3++;
			break;
		}
		fprintf(teste, "- Produto: %s- Marca: %s- Código: %s- Valor: %.2f R$\n", pessoa[cont3].produto, pessoa[cont3].marca, pessoa[cont3].code, pessoa[cont3].valor);
		cont3++;
	}
	}
	fprintf(teste, "=======================");
	fclose(teste);
	
	
	
    return 0;
}
