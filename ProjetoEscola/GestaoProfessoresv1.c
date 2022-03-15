#include <stdio.h>
#include <string.h>
#define qtdeprofessores 2

typedef struct 
{
	int dia;
	int mes;
	int ano;
}st_datanascimento;

typedef struct 
{
	int matricula;
	char nome[51];
	char sexo;
	st_datanascimento dataNascimento;
	char CPF[15];	
}incluir;

int main()
{
	int opcao, icont, jcont, kcont, lista = 0, finalizar = 0, matricula, posvetor = -1, nprofessor, validamatricula = 0, validacpf = 0, validadatadenascimento = 0, validasexo = 0, somacpf = 0, contprofessor=0;
	incluir vetorProfessores[qtdeprofessores]; //inicialmente definido em 2.
	     
    while(finalizar == 0)
    {
    	printf("--- Gestão de Professores --- \n");
	    printf("0 - Sair \n");
	    printf("1 - Incluir Professor \n");
	    printf("2 - Listar Professor \n");
	    printf("3 - Atualizar Professor\n");
	    printf("4 - Excluir Professor \n");
	    printf("Informe o que deseja fazer: \n");
	    scanf("%d", &opcao);
	    //printf("\n");
	    
		if(opcao == 0)
	    {
	    	finalizar = 1;
			printf("Finalizando Gestão de Professores. \n");    	
		}
		if(opcao == 1)
		{
		    if(contprofessor >= qtdeprofessores)
		    {
		        printf("Não há mais vagas para inclusão. \n");
		    }
		    else
		    {
		      printf("-- INCLUSÃO DE PROFESSORES --\n");
			//Inserir condição de contaluno < qtdealunos, printar que não há mais vagas.
			//while(validacadastro == 0)
			//{
    			nprofessor = contprofessor + 1;
    			printf("- DADOS DO PROFESSOR %d - \n", nprofessor);				
    			while(validamatricula == 0)
    			{
    				printf("Matricula do Professor: \n");
    				scanf("%d", &vetorProfessores[contprofessor].matricula);
    				getchar();
    				if(contprofessor > 0) // condição para evitar repetição de matrícula.
                    {
                        for(kcont = 0; kcont < contprofessor; kcont++)
                        {
                            if (vetorProfessores[kcont].matricula == vetorProfessores[contprofessor].matricula)
                            {
                            vetorProfessores[contprofessor].matricula = 0;  
                            }                  
                        }
                    }      	
    				if(vetorProfessores[contprofessor].matricula <= 0)
    				{
    					printf("Matrícula inválida. Este dado deve ser um número inteiro e positivo.  \n");
    					printf("Informe novamente a ");	
    				}
    				else
    				{
    					validamatricula = 1;
    				}
    			}		
    			validamatricula = 0;
    					
    			printf("Nome do Professor (até 50 caracteres): \n");
    			fflush(stdin);
    			fgets(vetorProfessores[contprofessor].nome, 51, stdin);
    				
    			size_t ln = strlen(vetorProfessores[contprofessor].nome) - 1; //comando para retirar o \n gerado pelo fgets
    	        if (vetorProfessores[contprofessor].nome[ln] == '\n')
    	        {
    	        	vetorProfessores[contprofessor].nome[ln] = '\0';	
    			}
    				
    			while(validasexo == 0)
    			{
    				printf("Sexo: (M)Masculino/(F)Feminino \n");
    				scanf("%c", &vetorProfessores[contprofessor].sexo);
    				getchar();
    				
    				if((vetorProfessores[contprofessor].sexo == 'M') || (vetorProfessores[contprofessor].sexo == 'F'))
    				{
    						validasexo = 1;								
    				}				
    				else
    				{						
    					validasexo = 0;	
    					printf("Sexo Inválido. Digite M para Masculino, F para Feminino. \n");
    					printf("Informe novamente o ");
    				}	
    			}
    			validasexo = 0;		
    				       				
    			while(validadatadenascimento == 0)
    			{
    				printf("Dia do Nascimento: (dd) \n");
    				scanf("%d", &vetorProfessores[contprofessor].dataNascimento.dia);
    				printf("Mês do Nascimento: (mm) \n");
    				scanf("%d", &vetorProfessores[contprofessor].dataNascimento.mes);
    				printf("Ano do Nascimento: (aaaa) \n");
    				scanf("%d", &vetorProfessores[contprofessor].dataNascimento.ano);
    				getchar();
    				
    				// SUGESTÃO DE MELHORIA: ANÁLISE DE ANO POR BISSEXTO. **SOMENTE DEPOIS QUE ESTIVERMOS VALIDADO O BÁSICO.
    				if((vetorProfessores[contprofessor].dataNascimento.ano > 2021) || (vetorProfessores[contprofessor].dataNascimento.ano <= 1930))
    				{	
    					printf("Ano de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n");
    					printf("Informe novamente os dados abaixo. \n");
    				}
    				else
    				{
    					if((vetorProfessores[contprofessor].dataNascimento.mes <= 12) || (vetorProfessores[contprofessor].dataNascimento.ano > 0))
    					{
    						if((vetorProfessores[contprofessor].dataNascimento.mes == 1) || (vetorProfessores[contprofessor].dataNascimento.mes == 3) || (vetorProfessores[contprofessor].dataNascimento.mes == 5) || (vetorProfessores[contprofessor].dataNascimento.mes == 7) || (vetorProfessores[contprofessor].dataNascimento.mes == 8) || (vetorProfessores[contprofessor].dataNascimento.mes == 10) || (vetorProfessores[contprofessor].dataNascimento.mes == 12))
    						{
    							if((vetorProfessores[contprofessor].dataNascimento.dia <= 0) || (vetorProfessores[contprofessor].dataNascimento.dia > 31))
    							{
    								printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 31 \n");
    								printf("Informe novamente os dados abaixo. \n");
    							}
    							else
    							{
    								validadatadenascimento = 1;
    							}
    						}
    						else
    						{
    							if(vetorProfessores[contprofessor].dataNascimento.mes == 2)
    							{
    								if((vetorProfessores[contprofessor].dataNascimento.dia <= 0) || (vetorProfessores[contprofessor].dataNascimento.dia >= 29))
    								{
    								printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 28 para anos não bissextos e 29 para anos bissextos \n");
    								printf("Informe novamente os dados abaixo. \n");
    								}
    								else
    								{
    								validadatadenascimento = 1;
    								}
    							}
    							else
    							{
    								if((vetorProfessores[contprofessor].dataNascimento.dia <= 0) || (vetorProfessores[contprofessor].dataNascimento.dia >= 30))
    								{
    									printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 30 \n");
    									printf("Informe novamente os dados abaixo. \n");
    								}
    								else
    								{
    									validadatadenascimento = 1;
    								}	
    							}	
    						}
    					}
    					else
    					{	
    						printf("Data de nascimento inválida. O mês de nascimento deve ser informado um número entre 1 e 12 \n");
    						printf("Informe novamente os dados abaixo. \n");	
    					}
    				}	
    			}	
    			validadatadenascimento = 0;
    			//while(validacpf == 0)
    			//{
    				printf("CPF: (Somente números) \n");
    				fflush(stdin);
    				fgets(vetorProfessores[contprofessor].CPF, 15, stdin);
    					
    				ln = strlen(vetorProfessores[contprofessor].CPF) - 1; //comando para retirar o \n gerado pelo fgets
    		        if (vetorProfessores[contprofessor].CPF[ln] == '\n')
    				{
    		        	vetorProfessores[contprofessor].CPF[ln] = '\0';	
    				}					
    				//INSERIR CÓDIGO DE VALIDAÇÃO DO CPF.	
    		    //validacadastro = 1;
			//}
			//validacadastro = 0;
		    contprofessor++;
			lista = 1;
		    }
		    finalizar = 0;
		}
		if (opcao == 2)
		{
			if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir professores no sistema. \n \n");
				finalizar = 0;
			}
			else
			{
        
				printf("\n--- LISTA DE PROFESSORES --- \n \n");
	        	for (icont = 0; icont < contprofessor; icont++) //imprime a quantidade de alunos que foram incluídos.              
				{
			        printf("Matrícula: %d \n", vetorProfessores[icont].matricula);
			        printf("Nome: %s \n", vetorProfessores[icont].nome);
			        printf("Sexo: %c \n", vetorProfessores[icont].sexo);
			        printf("Data Nascimento: %d/%d/%d \n", vetorProfessores[icont].dataNascimento.dia, vetorProfessores[icont].dataNascimento.mes, vetorProfessores[icont].dataNascimento.ano);
			        printf("CPF: %s \n \n", vetorProfessores[icont].CPF);
			    }		
			    printf("________________________________________________ \n");
	        }		
		}
		if(opcao == 3)
		{
			if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir professores no sistema. \n \n");
			}
			else
			{
        posvetor = -1;
			  while(posvetor == -1)
			  {
    			printf("Informe a matrícula do Professor que deseja atualizar. \n");
    			scanf("%d", &matricula);
    			getchar();

          if(matricula <= 0) //Verificação de matrículas negativas.
          {
            printf("Matrícula informada não existe. \n");
      			printf("Por favor, ");
          }
          else
          {
            for(icont = 0; icont<qtdeprofessores; icont++)
    			  {
    				  if(vetorProfessores[icont].matricula == matricula)
    				  {
    					posvetor = icont;
    				  }
    			  }      	
          
      			if(posvetor == -1)
      			{
      			  printf("Matrícula informada não existe. \n");
      			  printf("Por favor, ");
      			}
      			else
      			{
        			printf("--- DADOS DO PROFESSOR DE MATRICULA: %d --- \n", matricula);
        			printf("Nome: %s \n", vetorProfessores[posvetor].nome);
          		printf("Sexo: %c \n", vetorProfessores[posvetor].sexo);
          		printf("Data Nascimento: %d/%d/%d \n", vetorProfessores[posvetor].dataNascimento.dia, vetorProfessores[posvetor].dataNascimento.mes, vetorProfessores[posvetor].dataNascimento.ano);
          		printf("CPF: %s \n", vetorProfessores[posvetor].CPF);
          		printf("________________________________________________ \n");
          			
          		printf("--- ATUALIZAÇÃO DE DADOS DO PROFESSOR --- \n");
          		printf("Nome do Professor (até 50 caracteres): \n");
          		fflush(stdin);
          		fgets(vetorProfessores[posvetor].nome, 51, stdin);
          				
          		size_t ln = strlen(vetorProfessores[posvetor].nome) - 1; //comando para retirar o \n gerado pelo fgets
      	      if (vetorProfessores[posvetor].nome[ln] == '\n')
       	      {
      		     	vetorProfessores[posvetor].nome[ln] = '\0';	
          		}
          					
          		printf("Sexo: (M)Masculino/(F)Feminino \n");
          		scanf("%c", &vetorProfessores[posvetor].sexo);
        		          
    		      printf("Dia do Nascimento: (aa) \n");
          		scanf("%d", &vetorProfessores[posvetor].dataNascimento.dia);
          		getchar();
        			printf("Mês do Nascimento: (mm) \n");
        			scanf("%d", &vetorProfessores[posvetor].dataNascimento.mes);
        			getchar();
        			printf("Ano do Nascimento: (aaaa)\n");
         			scanf("%d", &vetorProfessores[posvetor].dataNascimento.ano);
          		getchar();
          			
          		printf("CPF: (Somente Números) \n");
          		fflush(stdin);
          		fgets(vetorProfessores[posvetor].CPF, 15, stdin);
          			
          		ln = strlen(vetorProfessores[posvetor].CPF) - 1; //comando para retirar o \n gerado pelo fgets
              if (vetorProfessores[posvetor].CPF[ln] == '\n')
              {
    		      	vetorProfessores[posvetor].CPF[ln] = '\0';	
        			}    
      			}            
          }    			
			  }			   
			}
		}
		if(opcao == 4)
		{
		  if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir professores no sistema. \n \n");
			}
			else
			{
        posvetor = -1;
			  while(posvetor == -1)
			  {
    			printf("Informe a matrícula do Professor que deseja EXCLUIR. \n");
    			scanf("%d", &matricula);

          if(matricula <= 0) //Verificação de matrículas negativas.
          {
            printf("Matrícula informada não existe. \n");
      			printf("Por favor, ");
          }
          else
          {
            for(icont = 0; icont<qtdeprofessores; icont++)
      			{
        			if(vetorProfessores[icont].matricula == matricula)
        			{
        				posvetor = icont;
        			}
      	  	}            
      			if(posvetor == -1)
      			{
      		    printf("Matrícula informada não existe. \n");
      		    printf("Por favor, ");
      			}
      			else
      			{
          		printf("--- PROFESSOR A SER EXCLUÍDO %d --- \n", matricula);
          		printf("Nome: %s \n", vetorProfessores[posvetor].nome);
        			printf("Sexo: %c \n", vetorProfessores[posvetor].sexo);
      				printf("Data Nascimento: %d/%d/%d \n", vetorProfessores[posvetor].dataNascimento.dia, vetorProfessores[posvetor].dataNascimento.mes, vetorProfessores[posvetor].dataNascimento.ano);
       				printf("CPF: %s \n", vetorProfessores[posvetor].CPF);
          		printf("________________________________________________ \n");
          				
          		printf("Excluindo dados... \n");
          									
        			vetorProfessores[posvetor].matricula = 0;		
      				strcpy(vetorProfessores[posvetor].nome, "Aluno excluído.");
          		vetorProfessores[posvetor].sexo = '0';
          		vetorProfessores[posvetor].dataNascimento.dia = 0;
        			vetorProfessores[posvetor].dataNascimento.mes = 0;
      				vetorProfessores[posvetor].dataNascimento.ano = 0;
      				strcpy(vetorProfessores[posvetor].CPF, "0");									
          							
      				printf("Professor excluído. \n \n");	  
      			}  
          }    			 
			  }
			}
		}
		if(opcao >= 5)
		{
			printf("Opção inválida. \n \n");
		}    
    }
    return 0;
}