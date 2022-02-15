#include <stdio.h>
#define tam 5

struct tp_dados
{
	char nome[51];
	int idade;
	char sexo[15];
	char cpf[15];
}dadospessoas[5];

int main()
{
	
	int icont;
	//Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.
    printf("\n --- CADASTRO DE DADOS --- \n \n");    
    for(icont = 0; icont<tam; icont++)
    {
    	printf("Nome: \n");
    	fflush(stdin);
    	gets(dadospessoas[icont].nome);
    	printf("Idade: \n");
    	scanf("%d", &dadospessoas[icont].idade);
    	printf("Sexo: \n");
    	fflush(stdin);
    	gets(dadospessoas[icont].sexo);
    	printf("CPF: xxx.xxx.xxx-xx \n");
    	fflush(stdin);
    	gets(dadospessoas[icont].cpf);   	
	}
	
	printf("\n --- DADOS PESSOAS --- \n \n");    
    for(icont = 0; icont<tam; icont++)
    {
    	printf("Nome: %s \n", dadospessoas[icont].nome);
    	printf("Idade: %d \n", dadospessoas[icont].idade);
    	printf("Sexo: %s \n", dadospessoas[icont].sexo);
    	printf("CPF: %s \n", dadospessoas[icont].cpf);   	    	
	}
    
    return 0;
}
