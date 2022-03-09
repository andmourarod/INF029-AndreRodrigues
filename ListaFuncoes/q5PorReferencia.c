#include <stdio.h>

typedef struct
{
	int numero1;
	int numero2;
	int numero3;
	int numero4;
}st_numeros;

int main()
{
	st_numeros numeros;
		
	void funcLer4Numeros(st_numeros *pt_numeros);
    
    funcLer4Numeros(&numeros);
    
    printf("Os 4 números informados são: %d %d %d %d \n", numeros.numero1, numeros.numero2, numeros.numero3, numeros.numero4);    

    return 0;
}

void funcLer4Numeros(st_numeros *pt_numeros)
{
	printf("Informe quatros números. \n");
	scanf("%d %d %d %d", &pt_numeros->numero1, &pt_numeros->numero2, &pt_numeros->numero3, &pt_numeros->numero4);	
	
}