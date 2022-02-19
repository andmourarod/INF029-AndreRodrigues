#include <stdio.h>

int main(void)
{
	float numero1, numero2, resultado, soma;
	float funcSoma(float x, float y);
		
	printf("Informe o primeiro número. \n");
	scanf("%f" , &numero1);
	printf("Informe o segundo número. \n");
	scanf("%f" , &numero2);
	
	resultado = funcSoma(numero1, numero2);
	printf("A soma dos números informados é: %0.2f \n", resultado);
	
	return 0;
}
float funcSoma(float x, float y)
{
	float soma;
	
	soma = x + y;
	
	return soma;
	
}

