#include <stdio.h>

typedef struct
{
	char nome[51];
	char datadenascimento[11];
	char CPF[15]; 
	char sexo;	
}st_cadastrocliente;
int main()
{
	st_cadastrocliente CadastroCliente;
	
	void funcLerDadosCliente (st_cadastrocliente *CadastroCliente);
	
	funcLerDadosCliente (&CadastroCliente);
    
	printf("Nome: %s \n", CadastroCliente.nome);
	printf("Nome: %s \n", CadastroCliente.datadenascimento);
	printf("Nome: %s \n", CadastroCliente.CPF);
	printf("Nome: %c \n", CadastroCliente.sexo);
    
    return 0;
}
void funcLerDadosCliente (st_cadastrocliente *CadastroCliente)
{
	printf("Informe o nome do Cliente. \n");
	fflush(stdin);
	fgets(CadastroCliente->nome, 51, stdin);
	
	printf("Informe a data de nascimento do Cliente. dd/mm/aaaa \n");
	fflush(stdin);
	fgets(CadastroCliente->datadenascimento, 11, stdin);
	
	printf("Informe o CPF do Cliente. xxx.xxx.xxx-xx \n");
	fflush(stdin);
	fgets(CadastroCliente->CPF, 15, stdin);
	
	getchar();
	printf("Informe a data de nascimento do Cliente. M/F \n");
	scanf("%c", &CadastroCliente->sexo);	
	
}