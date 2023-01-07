#include <stdio.h> // include programações ja prontas - stdio transmitir pro usuario; utiliza somente texto
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocação de texto por regiao
#include <string.h> //biblioteca responsavel pelas strings

int registrar(){ //função de registrar
	
	//inicio variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuario
	scanf("%s", cpf); //%s -> irá salvar uma string
	
	strcpy(arquivo, cpf); //puxando do cpf pro arquivo
	
	FILE *file; //FILE = chamando uma função ja pronta; *file = comando
	file = fopen(arquivo, "w"); //file = cria o arquivo e o 'w' significa write
	fprintf(file,"\nCPF:\t\t"); // adicionando texto antes do arquivo 'CPF'
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,"\nNome:\t\t"); //adiciona uma virgula ao arquivo
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: \t");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo:\t\t");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	printf("\n# Informações registradas com sucesso! #\n\n");
    system("pause");
	
}

int consultar(){ //função de consultar
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	system("cls"); //limpar tela 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("Arquivo não localizado!\n");
	}
	
	printf("Essas são as informações do usuário: \n");
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("%s", conteudo);
	}
	
	printf("\n\n");
	system("pause"); 
	
}

int deletar(){ //função de deletar
	
	char cpf[40];
	int confirma=0;
	
	printf("Digite o CPF do usuário a ser DELETADO: ");
	scanf("%s", cpf); //%s -> receber string
	
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL){
		printf("Arquivo não encontrado. Tente novamente. \n");
		system("pause");
	}
	
	else{
		printf("Tem certeza? digite [1] para confirmar ou [2] para cancelar: ");
		scanf("%d", &confirma);
		
		switch(confirma){
		
			case 1:
				remove(cpf);
			
				FILE *file;
				file = fopen(cpf, "r");
			
				if(file == NULL){
					printf("Arquivo deletado com sucesso! \n");
					system("pause");
				}
			break;
		
			case 2:
				printf("Operação CANCELADA pelo usuário!\n");
				system("pause");
				break;
				
			default:
				printf("Essa opção não esta disponível. \n");
				system("pause");
				break;
		}
	}
}

int main (){ //é o núcleo do nosso projeto / o parenteses mostra que é uma função
 
	int opcao=0; //Definindo variáveis
	int x=1;
	
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	
	for(x=1; x=1;){
		
		system("cls"); // limpar tela
	
		printf("\n### Cartório da EBAC ### \n\n");
		
		printf("Escolha a opção desejada no menu: \n\n"); //inicio do menu
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); // limpar tela
		
		switch(opcao){
			
			case 1:
				registrar(); //chamar função
				break;
			
			case 2:
				consultar(); //chamar função
				break;
				
			case 3:
				deletar(); //chamar função
				break;
				
			default:
				printf("Essa opção não esta disponível. \n\n");
				system("pause");
				break;
		}
	}
}

