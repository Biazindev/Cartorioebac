#include <stdio.h>  //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca repons�vel por cuidar das string

int regitro() //fun��o responsavel por cadastrar usu�rios no sistema
{
    //in�cio de cria��o de vari�veis/string
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:\n\n"); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere a string
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);// salva valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, ","); // virgula para separar dados, para melhor visualiza��o usu�rio
	fclose(file); // fecha arquivo
	
	printf("Digite o nome a ser cadastrado:\n\n"); //coletando informa��es do usu�rio
	scanf("%s", nome); //%s refere a string
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, nome); // salva valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, ","); // virgula para separar dados, para melhor visualiza��o usu�rio
	fclose(file); // fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado:\n\n"); //coletando informa��es do usu�rio
	scanf("%s", sobrenome); //%s refere a string
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, sobrenome); // salva valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, ","); // virgula para separar dados, para melhor visualiza��o usu�rio
	fclose(file); // fecha arquivo
	
	printf("Digite o cargo a ser cadastrado:\n\n"); //coletando informa��es do usu�rio
	scanf("%s", cargo); //%s refere a string
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, cargo); // salva valor da variavel
	fclose(file); // fecha arquivo
	
	
	system("pause"); // pausa na tela para usu�rio
	
	
}

int consulta() //fun��o respons�vel para consultas de dados ja cadastrados
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
    char cpf[40]; //armazenamento de valor inteiro
    char conteudo[200];// armazenamento conteudo variavel
    
    printf("Digite o cpf a ser consultado\n\n"); //coletando informa��es do usu�rio
    scanf("%s",cpf); //%s refere a string
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(cpf, "r"); // cria o arquivo e o "r" significa ler
    
    if(file == NULL) //valida��o para valores n�o encontrados
       {
    	   printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n\n"); //aviso ao usu�rio, arquivo n�o encontrado
        }

           while(fgets(conteudo, 200,file) != NULL) //executa repeti��o, procura arquivo com valores inseridos
           {
           	printf("\nessas s�o as informa��es do usu�rio:"); //aviso ao usu�rio, dados encontrados
           	printf("%s", conteudo); //%s refere a string
           	printf("\n\n"); //pula uma linha
           	
		   }
		   
		   system("pause"); // pausa na tela para usu�rio
		   
}

int deletar() //fun��o responsavel por deletar dados no banco de dados
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	char cpf[40]; //armazenamento de valor inteiro
	
	printf("Digite o CPF do usuario a ser deletado:"); // colentando informa��es do usu�rio
	scanf("%s",cpf); //%s refere a string
	
	remove(cpf); //comando respons�vel por deletar informa��es no banco de dados
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(cpf,"r");// cria o arquivo e o "r" significa ler
	
	if(file == NULL) // valida��o, caso arquivo n�o seja localizado
	{
		printf("O usuario n�o se encontra no sistema, e/ou deletado com sucesso!.\n\n");// mensagem ao usu�rio caso arquivo com valor descrito n�o seja localizado
		system("pause"); // pausa na tela para usu�rio
	}
		
		
	}
    


int main () //ponto de partida para execu��o do programa
                                          

{ 
                            
    int opcao=0;//Definindo vari�veis
	int laco=1;
	for(laco=1;laco=1;)  //estrutura de repeti��o com valores digitados                       
	{
		system("cls"); //comando limpa a tela (clear)
							  					  
	  setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	                          
	  printf("###cart�rio da EBAC###\n\n");//inicio do menu
      printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar Nomes\n"); // \t usado para espa�o anterior a frase
      printf("\t2 - Consultar Nomes\n");	
      printf("\t3 - Deletar Nomes\n");
	  printf("\t4 - Sair do sistema\n");
	  printf("Op��o:"); //fim do menu
    
	  scanf("%d", & opcao); //armazenando a escolha do usuario
    
      system("cls"); //comando limpa a tela (clear)
      
      switch (opcao) //inicio da sele��o, op��o mais pratica do que if ou else, para estrurar menus
          {
      	    case 1:
      	    regitro(); //chamadas de fun��es
      	    break;
      	    
      	    case 2:
      	    consulta();
			break;	
			
			case 3:
		    deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema!\n\n");
	        return 0;
	        break;
			
			default:
		    printf("Essa op��o n�o esta disponivel!\n\n");
            system("pause");
            break;
			}//fim da sele��o
    
 }    } 
	
