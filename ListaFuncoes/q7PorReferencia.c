#include <stdio.h>

typedef struct
{
	char string1[11];
	char string2[11];
	char string3[11];
}st_strings;
int main()
{
	st_strings palavras;
		
	void funcLer3Palavras(st_strings *palavras);
	
	funcLer3Palavras(&palavras);
	
    printf("As 3 palavras informadas foram:");
    printf("%s %s %s", palavras.string1, palavras.string2, palavras.string3);

    return 0;
}
void funcLer3Palavras(st_strings *palavras)
{
	printf("Informe 3 palavras. \n");
	fflush(stdin);
	fgets(palavras->string1, 11, stdin);
	fflush(stdin);
	fgets(palavras->string2, 11, stdin);
	fflush(stdin);
	fgets(palavras->string3, 11, stdin);
	
}


