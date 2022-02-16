#include <stdio.h>

int main()
{
	//Faça um programa que verifique se um número é primo
	
	int numero, resto, soma = 0, icont;
	
	printf("Informe um número \n");
	    scanf("%d", &numero);	
    
    for(icont = 1; icont <= numero; icont++)
    {
    	resto = numero%icont;     	
    	if(resto == 0) //verificação se número é divisível por icont;
    	{
    		soma = soma + 1;
		}
		  	
	}
	
	if(soma == 2) //soma dos números divisíveis.
	{
		printf("O número informado é primo. \n");
	}	
	else
	{
		printf("O número informado não é primo. \n");
	}
	
    return 0;
}