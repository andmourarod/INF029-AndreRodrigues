#include <stdio.h>

int main()
{
    char string[4];
    
    void funcler3letras(char *string, int n);
    
    funcler3letras(string, 4);
    
    printf("As três letras digitadas foram: \n");
    printf("%s", string);

    return 0;
}

void funcler3letras(char *string, int n)
{
	printf("Informe 3 letras. \n");
	fflush(stdin);
	fgets(string, n, stdin);	
}

