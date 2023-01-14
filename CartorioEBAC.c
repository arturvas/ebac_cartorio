#include <stdio.h> // include programa��es ja prontas - stdio transmitir pro usuario; utiliza somente texto
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regiao
#include <string.h> //biblioteca responsavel pelas strings

int registrar()
{ //fun��o de registrar
	
	//inicio variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usuario
	scanf("%s", cpf); //%s -> ir� salvar uma string
	
	strcpy(arquivo, cpf); //puxando do cpf pro arquivo
	
	FILE *file; //FILE = chamando uma fun��o ja pronta; *file = comando
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
	
	printf("\n# Informa��es registradas com sucesso! #\n\n");
    system("pause");
	
}

int consultar()
{ //fun��o de consultar
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	system("cls"); //limpar tela 
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado!\n");
	}
	
	printf("Essas s�o as informa��es do usu�rio: \n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	printf("\n\n");
	system("pause"); 
	
}

int deletar()
{ //fun��o de deletar
	
	char cpf[40];
	int confirma=0;
	
	printf("Digite o CPF do usu�rio a ser DELETADO: ");
	scanf("%s", cpf); //%s -> receber string
	
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("Arquivo n�o encontrado. Tente novamente. \n");
		system("pause");
	}else
	{
		printf("Tem certeza? digite [1] para confirmar ou [2] para cancelar: ");
		scanf("%d", &confirma);
		switch(confirma)
		{
			case 1:
				remove(cpf);
			
				FILE *file;
				file = fopen(cpf, "r");
			
				if(file == NULL)
				{
					printf("Arquivo DELETADO com sucesso! \n");
					system("pause");
				}
			break;
		
			case 2:
				printf("Opera��o CANCELADA pelo usu�rio!\n");
				system("pause");
			break;
				
			default:
				printf("Essa op��o n�o esta dispon�vel. \n");
				system("pause");
			break;
		}
	}
}

int main ()
{ //� o n�cleo do nosso projeto / o parenteses mostra que � uma fun��o
 	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma	
	
	#define usuario "admin"
	#define senha "admin"
	
	int opcao = 0; //Definindo vari�veis
	int x=1;
	char nomeUsuario[10], senhaUsuario[10];
	int valido = 0;
	
	printf("### Cart�rio da EBAC ###\n");
	printf("-------Bem Vindo--------\n");
	
	do
	{
		printf("Usu�rio: ");
		scanf("%s", &nomeUsuario);
		printf("Senha: ");
		scanf("%s", &senhaUsuario);
		
		valido = strcmp(nomeUsuario, usuario) == 0 && strcmp(senhaUsuario, senha) == 0; //strcmp -> compara strings; comparando com usuario e senha predefinidos
		
		if(!valido)
		{
			printf("\nUsu�rio ou senha incorreto, tente novamente!\n\n");
		}
		
	} while (!valido);
	
	printf("\n-----Acesso Permitido-----\n");
	system("pause");
	
	if(valido = 1)
	{
		for(x=1; x=1;)
		{
			system("cls"); // limpar tela
			printf("### Cart�rio da EBAC ### \n\n");
			printf("Escolha a op��o desejada no menu: \n\n"); //inicio do menu
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n");
			printf("\n\t4 - Sair\n\n");
			printf("Op��o: "); //fim do menu
			
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
			system("cls"); // limpar tela
			
			switch(opcao)
			{
				case 1:
					registrar(); //chamar fun��o
					break;
				
				case 2:
					consultar(); //chamar fun��o
					break;
					
				case 3:
					deletar(); //chamar fun��o
					break;
					
				case 4:
					printf("Obrigado por utilizar o sistema.\n");
					return 0;
					break;
					
				default:
					printf("Essa op��o n�o esta dispon�vel. \n\n");
					system("pause");
					break;
			}
		}
	}
}

