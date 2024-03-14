#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:  "); // coletando informa��o do usu�rio
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Atualizar arquivo existente
	fprintf(file, "\tNome:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
    fflush(stdin); // Limpa o buffer de entrada
    fgets(nome, sizeof(nome), stdin); // L� toda a linha, incluindo espa�os
    nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha do final
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\tSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\tCargo:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); 
}
int consulta() // fun�ao responsavel por consultar os CPF no sistema
{
	  setlocale(LC_ALL, "Portuguese");// selecionando a linguagem
      char cpf[40];
      char conteudo[200];
      
      printf("Digite o CPF a ser consultado: ");
      scanf("%s",cpf);
      
      FILE *file;
      file = fopen(cpf,"r");//abrindo o banco de dados para consultar o cpf existente 
      
      if(file == NULL)
      {
      	 printf("N�o foi possivel abrir o arquivo, n�o localizado\n");
	  }
	  
	  while(fgets(conteudo, 200, file) != NULL)
	  {
	  	printf("\nEssas s�o as informa��es do usu�rio: ");
	  	printf("%s", conteudo);
	  	printf("\n\n");
	  }
      fclose(file);
      system("pause");
      
}
int deletar()
{
    char cpf[40];
    char arquivo[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Copia o CPF para a vari�vel arquivo
    
    if(remove(arquivo) == 0) // Tenta remover o arquivo correspondente ao CPF
    {
        printf("Arquivo deletado com sucesso!\n");
    }
    else
    {
        printf("O arquivo n�o p�de ser deletado ou n�o existe!\n");
    }
    
    system("pause"); // faz com que a tela espere antes de mudar
    return 0; 
}

int main () 
{

	int opcao=0; // Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) // Inicio do la�o
	{
	
	
	
	   system("cls"); // limpa a tela
	
	   setlocale(LC_ALL, "Portuguese"); // Defninindo a linguagem
	
   	   printf("### Cart�rio da EBAC ###\n\n"); // Inic�o do menu
	   printf("Escolha a op��o desejada do menu:\n\n");
	   printf("\t1 - Registrar Nomes\n");
	   printf("\t2 - Consultar Nomes\n");
	   printf("\t3 - Deletar Nomes\n\n"); 
	   printf("\t4 - Sair do Programa\n\n");
 	   printf("Op��o: ");// Fim do menu
	
	   scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	   system("cls"); // responsavel por limpar a tela
	   
	   switch(opcao)  // inicio da sele��o
	   {
	   	case 1:
	   	registro(); // chamada de fun��es
		break;
		
		case 2:
		consulta();
    	break;
    	
    	case 3:
    	deletar();
	 	break;
	 	
	 	case 4:
	 	printf("Obrigado por utilizar o sistema\n");
		return 0;
		break;	
	 	default:
	 	printf("Est� op��o n�o est� disponivel!\n");
		 system("pause");
		break; // fim da sele��o
	   }
  }
    
}
