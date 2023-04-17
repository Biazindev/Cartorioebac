#include <stdio.h>  //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca reponsável por cuidar das string

int regitro() //função responsavel por cadastrar usuários no sistema
{
    //início de criação de variáveis/string
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado:\n\n"); //coletando informações do usuário
	scanf("%s", cpf); //%s refere a string
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);// salva valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, ","); // virgula para separar dados, para melhor visualização usuário
	fclose(file); // fecha arquivo
	
	printf("Digite o nome a ser cadastrado:\n\n"); //coletando informações do usuário
	scanf("%s", nome); //%s refere a string
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, nome); // salva valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, ","); // virgula para separar dados, para melhor visualização usuário
	fclose(file); // fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado:\n\n"); //coletando informações do usuário
	scanf("%s", sobrenome); //%s refere a string
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, sobrenome); // salva valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, ","); // virgula para separar dados, para melhor visualização usuário
	fclose(file); // fecha arquivo
	
	printf("Digite o cargo a ser cadastrado:\n\n"); //coletando informações do usuário
	scanf("%s", cargo); //%s refere a string
	
	file = fopen(arquivo, "a"); // abre arquivo "a" significa atualizar dados ja existentes
	fprintf(file, cargo); // salva valor da variavel
	fclose(file); // fecha arquivo
	
	
	system("pause"); // pausa na tela para usuário
	
	
}

int consulta() //função responsável para consultas de dados ja cadastrados
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
    char cpf[40]; //armazenamento de valor inteiro
    char conteudo[200];// armazenamento conteudo variavel
    
    printf("Digite o cpf a ser consultado\n\n"); //coletando informações do usuário
    scanf("%s",cpf); //%s refere a string
    
    FILE *file; //cria o arquivo no banco de dados
    file = fopen(cpf, "r"); // cria o arquivo e o "r" significa ler
    
    if(file == NULL) //validação para valores não encontrados
       {
    	   printf("Não foi possivel abrir o arquivo, não localizado!.\n\n"); //aviso ao usuário, arquivo não encontrado
        }

           while(fgets(conteudo, 200,file) != NULL) //executa repetição, procura arquivo com valores inseridos
           {
           	printf("\nessas são as informações do usuário:"); //aviso ao usuário, dados encontrados
           	printf("%s", conteudo); //%s refere a string
           	printf("\n\n"); //pula uma linha
           	
		   }
		   
		   system("pause"); // pausa na tela para usuário
		   
}

int deletar() //função responsavel por deletar dados no banco de dados
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	char cpf[40]; //armazenamento de valor inteiro
	
	printf("Digite o CPF do usuario a ser deletado:"); // colentando informações do usuário
	scanf("%s",cpf); //%s refere a string
	
	remove(cpf); //comando responsável por deletar informações no banco de dados
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(cpf,"r");// cria o arquivo e o "r" significa ler
	
	if(file == NULL) // validação, caso arquivo não seja localizado
	{
		printf("O usuario não se encontra no sistema, e/ou deletado com sucesso!.\n\n");// mensagem ao usuário caso arquivo com valor descrito não seja localizado
		system("pause"); // pausa na tela para usuário
	}
		
		
	}
    


int main () //ponto de partida para execução do programa
                                          

{ 
                            
    int opcao=0;//Definindo variáveis
	int laco=1;
	for(laco=1;laco=1;)  //estrutura de repetição com valores digitados                       
	{
		system("cls"); //comando limpa a tela (clear)
							  					  
	  setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	                          
	  printf("###cartório da EBAC###\n\n");//inicio do menu
      printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar Nomes\n"); // \t usado para espaço anterior a frase
      printf("\t2 - Consultar Nomes\n");	
      printf("\t3 - Deletar Nomes\n");
	  printf("\t4 - Sair do sistema\n");
	  printf("Opção:"); //fim do menu
    
	  scanf("%d", & opcao); //armazenando a escolha do usuario
    
      system("cls"); //comando limpa a tela (clear)
      
      switch (opcao) //inicio da seleção, opção mais pratica do que if ou else, para estrurar menus
          {
      	    case 1:
      	    regitro(); //chamadas de funções
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
		    printf("Essa opção não esta disponivel!\n\n");
            system("pause");
            break;
			}//fim da seleção
    
 }    } 
	
