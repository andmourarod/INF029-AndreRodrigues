#include <stdio.h>

int main()
{
	//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas
	int x, y;
	
    printf("Informe valor de X. \n");
    scanf("%d", &x);
    printf("Informe valor de Y. \n");
    scanf("%d", &y);

    x = x + y;
    x = x + y - x;
    y = x + y - y;
    
    printf("O valor de X é: %d \n", y);
    printf("O valor de Y é: %d \n", x);
    

    return 0;
}