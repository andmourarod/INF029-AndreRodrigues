#include <stdio.h>

int main(void)
{
	int numero1, numero2, numero3, diferenca;
	int funcSubtrair(int x, int y, int c);
	
    printf("Informe três valores. \n");
    scanf("%d %d %d", &numero1, &numero2, &numero3);
    
    diferenca = funcSubtrair (numero1, numero2, numero3);
    
    printf("A diferenca dos números informados é: %d \n", diferenca);
    

    return 0;
}

int funcSubtrair(int x, int y, int c)
{
	int resultado;
	resultado = x - y - c;
	return resultado;
}


