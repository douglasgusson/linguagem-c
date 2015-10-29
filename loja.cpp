#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//Struct. #########################################################################

struct produto{
	int cod, est_Min, est_Atua;
	char descricao[55];
	float preco;	
};

//Vari�veis globais. ###############################################################

	FILE *fp;
	int i;
	produto prod_Loja[2], prod_Arquivo[2];

//##################################################################################

void cad_Produto(){
	
		printf("\n\t### CADASTRO DE PRODUTOS ###\n\n");
		
		for(i = 0; i < 2; i++){
	
			fflush(stdin);
			
				printf("\n\tDigite a descri��o do %d� produto: ", i+1);
				gets(prod_Loja[i].descricao);
						
				printf("\n\tDigite o c�digo do %d� produto: ", i+1);
				scanf("%d", &prod_Loja[i].cod);
				
				printf("\n\tDigite o estoque minimo do %d� produto: ", i+1);
				scanf("%d", &prod_Loja[i].est_Min);
				
				printf("\n\tDigite o estoque atual do %d� produto: ", i+1);
				scanf("%d", &prod_Loja[i].est_Atua);
				
				printf("\n\tDigite o pre�o do %d� produto: ", i+1);
				scanf("%f", &prod_Loja[i].preco);
		
			puts("\n");
		
		}
	
	//Abertura do arquivo
	
	fp = fopen("produtos.dat", "wb");	
	
	//Escrita dos dados no arquivo
	
	fwrite(&prod_Loja, sizeof(prod_Loja), 1, fp);
	
	//Fechamento do arquivo
	
	fclose(fp);
	
}

// fun��o que lista produtos cadastrados. ################################################

void listar(){
	
	// Abre o arquivo para leitura no modo bin�rio.
	
	fp = fopen("produtos.dat", "rb");
	
	// L� o bloco de informa��es do arquivo e grava no vetor.
	
	fread(&prod_Arquivo, sizeof(prod_Arquivo), 1, fp);
	
	// Apresenta os dados lidos do arquivo para o usu�rio.
	
		printf("\n\t### LISTAGEM GERAL DOS PRODUTOS ###\n\n");
	
		for(i = 0; i < 2; i++){
			
			printf("\n\t-----------------------------------------------------\n");
			printf("\n\tDescricao do %d� produto: %s", i + 1, prod_Arquivo[i].descricao);
			printf("\n\tCodigo do %d� produto: %d", i + 1, prod_Arquivo[i].cod);
			printf("\n\tEstoque m�nimo do %d� produto: %d", i + 1, prod_Arquivo[i].est_Min);
			printf("\n\tEstoque atual do %d� produto: %d", i + 1, prod_Arquivo[i].est_Atua);
			printf("\n\tPre�o do %d� produto: %0.2f\n", i + 1, prod_Arquivo[i].preco);		
						
		}
		
		printf("\n\t-----------------------------------------------------\n");
			
		puts("\n");
	
	//Fechamento do arquivo
	
	fclose(fp);
	
}

//Fun��o que lista os produtos abaixo do estoque minimo. ##################################

void est_Baixo(){
				
	// Abre o arquivo para leitura no modo bin�rio.
	
	fp = fopen("produtos.dat", "rb");
	
	// L� o bloco de informa��es do arquivo e grava no vetor.
	
	fread(&prod_Arquivo, sizeof(prod_Arquivo), 1, fp);
	
	printf("\n\t### PRODUTOS ABAIXO DO ESTOQUE M�NIMO ###\n\n");
	
	for(i=0; i<2; i++){
		
		if(prod_Arquivo[i].est_Atua < prod_Arquivo[i].est_Min){
			printf("\n\t----------------------------------\n");
			printf("\n\t-> %d - %s\n", prod_Arquivo[i].cod, prod_Arquivo[i].descricao);
			printf("\n\t - Estoque M�nimo: %d", prod_Arquivo[i].est_Min);
			printf("\n\t - Estoque Atual: %d\n", prod_Arquivo[i].est_Atua);
		}
	}
	
	printf("\n\t----------------------------------\n");
	
	//Fechamento do arquivo
	
	fclose(fp);
	
	puts("\n");
}


// Fun��o para sair do programa. ##########################################################

void sair(){
	
		printf("\n----------------------------------\n\n");
		printf("\nPRESSIONE QUALQUER TECLA PARA SAIR\n\n");
		exit(0);
	
}

//Menu do programa.#######################################################################

void menu(){

	int op = 0;
	
		printf("\n\t--------- MENU ---------");
		printf("\n\t1 - Cadastrar Produtos");
		printf("\n\t2 - Listar Produtos");
		printf("\n\t3 - Listar Estoque Baixo");
		printf("\n\t9 - SAIR");
		printf("\n\t------------------------\n\n");
	
	printf("\n\t> Digite a op��o desejada: ");
	scanf("%d", &op);
	
	system("cls");
	
	switch (op){
		case 1:
			cad_Produto();
			system("pause");
			system("cls");
			break;
		case 2:
			listar();
			system("pause");
			system("cls");
			break;
		case 3:
			est_Baixo();
			system("pause");
			system("cls");
			break;
		case 9:
			sair();
	}
	
// Enquanto o usu�rio n�o digitar "9"(par�metro de sa�da), ele chama o menu.	
	
	while(op != 9){
		menu();
	}	

}

// int main apenas chamando o menu ################################################################

int main(){
	
	setlocale(LC_ALL, "Portuguese");
		
		menu();
	
	system("Pause");
	
	return 0;
	
}
