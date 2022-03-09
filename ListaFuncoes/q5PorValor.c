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
	st_numeros numeroslidos;
	
	st_numeros funcLer4Numeros();
    
    numeroslidos = funcLer4Numeros();
    
    printf("Os 4 números informados são: %d %d %d %d \n", numeroslidos.numero1, numeroslidos.numero2, numeroslidos.numero3, numeroslidos.numero4);    

    return 0;
}
st_numeros funcLer4Numeros()
{
	st_numeros numeros;
	printf("Informe quatros números. \n");
	scanf("%d %d %d %d", &numeros.numero1, &numeros.numero2, &numeros.numero3, &numeros.numero4);	
	
	return numeros;
}

