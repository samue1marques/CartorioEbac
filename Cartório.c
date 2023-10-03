#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>// biblioteca de alocação de memória em espaço
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // função responsável por cadastrar os usuários no sistema.
{
	//início da criação de variáveis/strings
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis.
	
	printf("Digite o CPF a ser cadastrado:   "); // colentando informação do usuário
	scanf("%s", cpf); // %s refere-se a string, escanea e salva na cpf
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings, copia o valor do cpf para o arquivo
	
	FILE *file;// acessa a função FILE em uma biblioteca já existente e cria o file
	file= fopen(arquivo, "w");  // aqui nós atribuimos o file como a variável arquivo, o W refere-se a WRITE, é um comando para arquivo novo.
	fprintf(file, cpf); // é o mesmo printf, ao invés de mostrar ao usuário ele está salvando no arquivo
	fclose(file);// fecho o arquivo
	
	file= fopen(arquivo,"a"); // abri o arquivo, o A siginifica que quero atualizar a informação.
	fprintf (file, ",");
	fclose(file); // fecho o arquivo
	
	printf( "Digite o nome a ser cadastrado: "); // colentando informação do usuário
	scanf("%s", nome); // %s refere-se a string, escaneia e salva na variável nome
	
	file= fopen(arquivo,"a"); // abri o arquivo, o A significa que quero atualizar a informação
	fprintf( file, nome); // coloca as informações dentro do arquivo, neste caso a variável nome
	fclose(file); // fecho o arquivo
	
	file= fopen(arquivo,"a"); // abri o arquivo, o A siginifica que quero atualizar a informação
	fprintf (file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:"); // coletando informação do usuário
	scanf("%s", sobrenome); // %s refere-se a string, escaneia e salva na variável sobrenome
	
	file=fopen(arquivo, "a"); // abre o arquivo e atualiza
	fprintf(file, sobrenome); // coloca as informações dentro do arquivo, neste caso a variável sobrenome
	fclose(file);// fecha o arquivo
	
	file= fopen(arquivo,"a"); // abre o arquivo e atualiza
	fprintf (file, ",");
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); // coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a strinf, escaneia e salva na variável cargo
	
	file=fopen(arquivo,"a"); // abre o arquivo e atualiza
	fprintf(file, cargo); // coloca as informações dentro do arquivo, neste caso a variável cargo (informação)
	fclose(file); // fecha o arquivo
	
	system("pause"); // pausa a tela
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // definindo a linguagem, outra fução então é necessário.
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	
	scanf("%s", cpf); // escaneia o cpf, armazena.
	
	FILE *file; // vai lá o arquivo file
	file=fopen (cpf, "r"); // abre o arquivo file e lê (r) read.
	
	if(file == NULL) // se o arquivo procurado for nulo (null)
	{ 
        printf("Não foi possível encontrar o seu arquivo, não localizado.");
	}
	
	while( fgets(conteudo,200,file)!= NULL); //busca no arquivo( fgets - file). Enquanto ele estiver escrevendo dentro do conteudo, até 200 caracteres, diferente é nulo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que gostaria de deletar: ");
	
	scanf("%s",cpf); // escaneia/salva dentro da variável/string cpf
	
	remove(cpf); // assim como a função scanf a remove já é importada de uma biblioteca e automativamente vai deletar a variável apresentada na pasta, cpf.
	
	FILE *file; // acessa a função FILE na biblioteca e acessa o parametro arquivo
	file=fopen (cpf,"r"); // abre a pasta e procura o arquivo cpf e lê "r"
	
	
	if(file== NULL) // aqui a função quer dizer que se o arquivo aberto for nulo vai para a mensagem dos colchetes.
	{
		printf("O usuário não se encontra no sistema. \n");
		system("pause");
	}
	
	fclose(file);
}

int main()
{
	int opcao=0; // definindo as variáveis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system ("cls");
	
    	setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
	    printf ("### Cartório da EBAC ### \n\n"); // início do menu
    	printf ("Escolha a opção desejada no menu:\n\n");
	    printf ("\t1 - Registrar nomes \n");
    	printf ("\t2 - Consultar nomes \n");
    	printf ("\t3 - Deletar nomes \n\n"); 
    	printf("opção:  "); // fim do menu
	
    	scanf("%d", &opcao); // scanf vai scanear tudo que está dentro da variável. Letra d, é referência da variável int. O & mostra onde o usuário vai digitar
	
    	system ("cls"); // aqui a comunicação é com o sistema (windowns), este comando limpa a tela, deleta tudo anteriormente apresentado para o usuário.
	
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
    		printf("Essa opção não está disponível! \n");
	    	system("pause");
	    	break;
        		
		}
		
}
}
