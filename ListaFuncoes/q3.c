#include <stdio.h>

int main()
{
	int numero, validade, fatorial;
	int funCalcFatorial (int x);
	int validadeFatorial (int x);
	
	printf("Informe um número. \n");
	scanf("%d", &numero);
	
	validade = validadeFatorial(numero);	
	
	if(validade == 0)
	{
		printf("Não é possível calcular o fatorial. \n");
	}
	if(validade == 1)
	{
		fatorial = funCalcFatorial(numero);
		printf("O fatorial do número é: %d. \n", fatorial);
	}  
	
    return 0;
}

int validadeFatorial (int x)
{
	int validade;
	
	if(x<0)
	{
		validade = 0;	
	}
	else
	{
		validade = 1;
	}
	
	return validade;	
}

int funCalcFatorial (int x)
{
	int icont, fatorial;
	
	if(x == 0)
	{
	fatorial = 1;	
	}
	else
	{
		for(icont = 1; icont <= x; icont++ )
		{
			fatorial = fatorial*icont;
		}
	}		
	
	return fatorial;	
}

