#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>// biblioteca de aloca��o de mem�ria em espa�o
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema.
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis.
	
	printf("Digite o CPF a ser cadastrado:   "); // colentando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string, escanea e salva na cpf
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings, copia o valor do cpf para o arquivo
	
	FILE *file;// acessa a fun��o FILE em uma biblioteca j� existente e cria o file
	file= fopen(arquivo, "w");  // aqui n�s atribuimos o file como a vari�vel arquivo, o W refere-se a WRITE, � um comando para arquivo novo.
	fprintf(file, cpf); // � o mesmo printf, ao inv�s de mostrar ao usu�rio ele est� salvando no arquivo
	fclose(file);// fecho o arquivo
	
	file= fopen(arquivo,"a"); // abri o arquivo, o A siginifica que quero atualizar a informa��o.
	fprintf (file, ",");
	fclose(file); // fecho o arquivo
	
	printf( "Digite o nome a ser cadastrado: "); // colentando informa��o do usu�rio
	scanf("%s", nome); // %s refere-se a string, escaneia e salva na vari�vel nome
	
	file= fopen(arquivo,"a"); // abri o arquivo, o A significa que quero atualizar a informa��o
	fprintf( file, nome); // coloca as informa��es dentro do arquivo, neste caso a vari�vel nome
	fclose(file); // fecho o arquivo
	
	file= fopen(arquivo,"a"); // abri o arquivo, o A siginifica que quero atualizar a informa��o
	fprintf (file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:"); // coletando informa��o do usu�rio
	scanf("%s", sobrenome); // %s refere-se a string, escaneia e salva na vari�vel sobrenome
	
	file=fopen(arquivo, "a"); // abre o arquivo e atualiza
	fprintf(file, sobrenome); // coloca as informa��es dentro do arquivo, neste caso a vari�vel sobrenome
	fclose(file);// fecha o arquivo
	
	file= fopen(arquivo,"a"); // abre o arquivo e atualiza
	fprintf (file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); // coletando informa��o do usu�rio
	scanf("%s", cargo); //%s refere-se a strinf, escaneia e salva na vari�vel cargo
	
	file=fopen(arquivo,"a"); // abre o arquivo e atualiza
	fprintf(file, cargo); // coloca as informa��es dentro do arquivo, neste caso a vari�vel cargo (informa��o)
	fclose(file); // fecha o arquivo
	
	system("pause"); // pausa a tela
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // definindo a linguagem, outra fu��o ent�o � necess�rio.
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	
	scanf("%s", cpf); // escaneia o cpf, armazena.
	
	FILE *file; // vai l� o arquivo file
	file=fopen (cpf, "r"); // abre o arquivo file e l� (r) read.
	
	if(file == NULL) // se o arquivo procurado for nulo (null)
	{ 
        printf("N�o foi poss�vel encontrar o seu arquivo, n�o localizado.");
	}
	
	while( fgets(conteudo,200,file)!= NULL); //busca no arquivo( fgets - file). Enquanto ele estiver escrevendo dentro do conteudo, at� 200 caracteres, diferente � nulo
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
	
	printf("Digite o CPF do usu�rio que gostaria de deletar: ");
	
	scanf("%s",cpf); // escaneia/salva dentro da vari�vel/string cpf
	
	remove(cpf); // assim como a fun��o scanf a remove j� � importada de uma biblioteca e automativamente vai deletar a vari�vel apresentada na pasta, cpf.
	
	FILE *file; // acessa a fun��o FILE na biblioteca e acessa o parametro arquivo
	file=fopen (cpf,"r"); // abre a pasta e procura o arquivo cpf e l� "r"
	
	
	if(file== NULL) // aqui a fun��o quer dizer que se o arquivo aberto for nulo vai para a mensagem dos colchetes.
	{
		printf("O usu�rio n�o se encontra no sistema. \n");
		system("pause");
	}
	
	fclose(file);
}

int main()
{
	int opcao=0; // definindo as vari�veis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system ("cls");
	
    	setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
	    printf ("### Cart�rio da EBAC ### \n\n"); // in�cio do menu
    	printf ("Escolha a op��o desejada no menu:\n\n");
	    printf ("\t1 - Registrar nomes \n");
    	printf ("\t2 - Consultar nomes \n");
    	printf ("\t3 - Deletar nomes \n\n"); 
    	printf("op��o:  "); // fim do menu
	
    	scanf("%d", &opcao); // scanf vai scanear tudo que est� dentro da vari�vel. Letra d, � refer�ncia da vari�vel int. O & mostra onde o usu�rio vai digitar
	
    	system ("cls"); // aqui a comunica��o � com o sistema (windowns), este comando limpa a tela, deleta tudo anteriormente apresentado para o usu�rio.
	
    	switch(opcao)
		{
			case 1:
			registro();
        	break;
        	
        	case 2:
        	consulta();
	    	break;
	    	
	    	case 3:
	        deletar();
        	break;	
        	
        	default:
    		printf("Essa op��o n�o est� dispon�vel! \n");
	    	system("pause");
	    	break;
        		
		}
		
}
}
