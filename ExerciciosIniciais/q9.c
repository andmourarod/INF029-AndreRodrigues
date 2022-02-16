#include <stdio.h>

int main()
{
	//Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.
	
	int icont, numero, kcont, soma, resto, somaprimos = 0;
	
	icont = 0;
	while(icont<10)
	{
		printf("Informe um número \n");
		scanf("%d", &numero);
			
	    soma = 0;
	    for(kcont = 1; kcont <= numero; kcont++)
	    {	    	
	    	resto = numero%kcont;     	
	    	if(resto == 0) //verificação se número é divisível por icont;
	    	{
	    		soma = soma + 1;
			}			  	
		}
		
		if(soma == 2) //soma dos números divisíveis.
		{
			printf("O número informado %d é primo. \n", numero);
			somaprimos = somaprimos+numero;		
		}	
	icont++;
	}
	
	printf("A soma dos números primos é: %d \n", somaprimos);

    return 0;
}