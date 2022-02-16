#include <stdio.h>

int main()
{
	//Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada
    int idadefulano = 0;
	
	while(idadefulano>=0)
	{
		printf("Informe a idade de Fulano. \n");
	    scanf("%d", &idadefulano);
	    if(idadefulano >= 18)
	    {
	    	printf("Fulano é maior de idade. \n");    	
		}
		else
		{	
			printf("Fulano é menor de idade. \n \n");  	
		}	
	}
    

    return 0;
}
