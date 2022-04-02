#include <stdio.h>
#include <string.h>
#define qtdealunos 2

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
	int opcao, icont, jcont, kcont, lista = 0, finalizar = 0, matricula, posvetor, naluno, validamatricula = 0, validacpf = 0, validadatadenascimento = 0, validasexo = 0, soma = 0, somaiguais = 0, contaluno=0;
	incluir vetorAlunos[qtdealunos]; //inicialmente definido em 2.
	     
    while(finalizar == 0)
    {
    	printf("--- Gestão de Alunos --- \n");
	    printf("0 - Sair \n");
	    printf("1 - Incluir Aluno \n");
	    printf("2 - Listar Alunos \n");
	    printf("3 - Atualizar Aluno \n");
	    printf("4 - Excluir Aluno \n");
	    printf("Informe o que deseja fazer: \n");
	    scanf("%d", &opcao);
	    //printf("\n");
	    
		if(opcao == 0) // Opção para Sair do Gestão Alunos.
	  {
	    finalizar = 1;
			printf("Finalizando Gestão de Alunos. \n");    	
		}
		if(opcao == 1)
		{
      if(contaluno>=qtdealunos) // Verificando se ainda há slots no vetor.
      {
        printf(" \n Não há mais vagas para incluir. \n \n");
      }
      else
      {
        printf("-- INCLUSÃO DE ALUNOS --\n");
			//while(validacadastro == 0)
			//{
    			naluno = contaluno + 1;
    			printf("- DADOS DO ALUNO %d - \n", naluno);				
    			while(validamatricula == 0)
    			{
    				printf("Matricula do Aluno: \n");
    				scanf("%d", &vetorAlunos[contaluno].matricula);
    				getchar();

            if(contaluno > 0) // Condição para evitar repetição de matrícula.
            {
              for(kcont = 0; kcont < contaluno; kcont++)
              {
                if (vetorAlunos[kcont].matricula == vetorAlunos[contaluno].matricula)
                {
                   vetorAlunos[contaluno].matricula = 0;  
                }                  
              }
            }            
    				if(vetorAlunos[contaluno].matricula <= 0) // Condição para permitir matrículas somente positivas.
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
    					
    			printf("Nome do Aluno (até 50 caracteres): \n");
    			fflush(stdin);
    			fgets(vetorAlunos[contaluno].nome, 51, stdin);
    				
    			size_t ln = strlen(vetorAlunos[contaluno].nome) - 1; //comando para retirar o \n gerado pelo fgets
    	        if (vetorAlunos[contaluno].nome[ln] == '\n')
    	        {
    	        	vetorAlunos[contaluno].nome[ln] = '\0';	
    			}
    				
    			while(validasexo == 0)
    			{
    				printf("Sexo: (M)Masculino/(F)Feminino \n");
    				scanf("%c", &vetorAlunos[contaluno].sexo);
    				getchar();
    				
    				if((vetorAlunos[contaluno].sexo == 'M') || (vetorAlunos[contaluno].sexo == 'F'))
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
    				scanf("%d", &vetorAlunos[contaluno].dataNascimento.dia);
    				printf("Mês do Nascimento: (mm) \n");
    				scanf("%d", &vetorAlunos[contaluno].dataNascimento.mes);
    				printf("Ano do Nascimento: (aaaa) \n");
    				scanf("%d", &vetorAlunos[contaluno].dataNascimento.ano);
    				getchar();
    				
    				// SUGESTÃO DE MELHORIA: ANÁLISE DE ANO POR BISSEXTO. **SOMENTE DEPOIS QUE ESTIVERMOS VALIDADO O BÁSICO.
    				if((vetorAlunos[contaluno].dataNascimento.ano > 2021) || (vetorAlunos[contaluno].dataNascimento.ano <= 1930))
    				{	
    					printf("Ano de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n");
    					printf("Informe novamente os dados abaixo. \n");
    				}
    				else
    				{
    					if((vetorAlunos[contaluno].dataNascimento.mes <= 12) || (vetorAlunos[contaluno].dataNascimento.ano > 0))
    					{
    						if((vetorAlunos[contaluno].dataNascimento.mes == 1) || (vetorAlunos[contaluno].dataNascimento.mes == 3) || (vetorAlunos[contaluno].dataNascimento.mes == 5) || (vetorAlunos[contaluno].dataNascimento.mes == 7) || (vetorAlunos[contaluno].dataNascimento.mes == 8) || (vetorAlunos[contaluno].dataNascimento.mes == 10) || (vetorAlunos[contaluno].dataNascimento.mes == 12))
    						{
    							if((vetorAlunos[contaluno].dataNascimento.dia <= 0 || vetorAlunos[contaluno].dataNascimento.dia > 31))
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
    							if(vetorAlunos[contaluno].dataNascimento.mes == 2)
    							{
    								if((vetorAlunos[contaluno].dataNascimento.dia <= 0 || vetorAlunos[contaluno].dataNascimento.dia >= 29))
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
    								if((vetorAlunos[contaluno].dataNascimento.dia <= 0 || vetorAlunos[contaluno].dataNascimento.dia >= 30))
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
    			while(validacpf == 0)
    			{
    				printf("CPF: (Somente números) \n");
    				fflush(stdin);
    				fgets(vetorAlunos[contaluno].CPF, 15, stdin);
    					
    				ln = strlen(vetorAlunos[contaluno].CPF) - 1; //comando para retirar o \n gerado pelo fgets
    		    if (vetorAlunos[contaluno].CPF[ln] == '\n')
    				{
    		      vetorAlunos[contaluno].CPF[ln] = '\0';	
    				}			
            
            soma = strlen(vetorAlunos[contaluno].CPF);
            
            if(soma < 11)
            {
              printf("CPF com tamanho inválido. Deve ter 11 caracteres. \n");
      			  printf("Por favor, informe o ");
            }
            else
            {
              validacpf = 1;
            }
          }
      validacpf = 0;    				
			contaluno++;
			lista = 1;
      }			
		}
		if (opcao == 2) // Opção de Listar Alunos
		{
			if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
				finalizar = 0;
			}
			else
			{        
				printf("\n--- LISTA DE ALUNOS --- \n \n");
	        	for (icont = 0; icont < contaluno; icont++) //imprime a quantidade de alunos que foram incluídos.              
				{
			        printf("Matrícula: %d \n", vetorAlunos[icont].matricula);
			        printf("Nome: %s \n", vetorAlunos[icont].nome);
			        printf("Sexo: %c \n", vetorAlunos[icont].sexo);
			        printf("Data Nascimento: %d/%d/%d \n", vetorAlunos[icont].dataNascimento.dia, vetorAlunos[icont].dataNascimento.mes, vetorAlunos[icont].dataNascimento.ano);
			        printf("CPF: %s \n \n", vetorAlunos[icont].CPF);
			    }		
			    printf("________________________________________________ \n");
	        }		
		}
		if(opcao == 3) // Opção de atualizar alunos.
		{
			if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
			}
			else
			{
        posvetor = -1;		
        while(posvetor == -1)
			  {
          printf("Informe a matrícula do Aluno que deseja atualizar. \n");
    			scanf("%d", &matricula);
    			getchar();
          if(matricula <= 0) //Verificação de matrículas negativas.
          {
            printf("Matrícula informada não existe. \n");
      			printf("Por favor, ");
          }
          else
          {
            for(icont = 0; icont<qtdealunos; icont++)
      			{
      				if(vetorAlunos[icont].matricula == matricula)
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
              printf("--- DADOS DO ALUNO DE MATRICULA: %d --- \n", matricula);
        			printf("Nome: %s \n", vetorAlunos[posvetor].nome);
        			printf("Sexo: %c \n", vetorAlunos[posvetor].sexo);
        			printf("Data Nascimento: %d/%d/%d \n", vetorAlunos[posvetor].dataNascimento.dia, vetorAlunos[posvetor].dataNascimento.mes, vetorAlunos[posvetor].dataNascimento.ano);
        			printf("CPF: %s \n", vetorAlunos[posvetor].CPF);
        			printf("________________________________________________ \n");
        			
        			printf("--- ATUALIZAÇÃO DE DADOS DO ALUNO --- \n");
        			printf("Nome do Aluno (até 50 caracteres): \n");
        			fflush(stdin);
        			fgets(vetorAlunos[posvetor].nome, 51, stdin);
        				
        			size_t ln = strlen(vetorAlunos[posvetor].nome) - 1; //comando para retirar o \n gerado pelo fgets
        		  if (vetorAlunos[posvetor].nome[ln] == '\n')
        		  {
        	      vetorAlunos[posvetor].nome[ln] = '\0';	
        			}

              validasexo = 0;  
              while(validasexo == 0)
        			{
        				printf("Sexo: (M)Masculino/(F)Feminino \n");
        				scanf("%c", &vetorAlunos[posvetor].sexo);
        				getchar();
        				
        				if((vetorAlunos[posvetor].sexo == 'M') || (vetorAlunos[posvetor].sexo == 'F'))
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
    				  /*printf("Sexo: (M)Masculino/(F)Feminino \n");
      				scanf("%c", &vetorAlunos[posvetor].sexo);*/

              validadatadenascimento = 0;
              while(validadatadenascimento == 0)
    			    {
        				printf("Dia do Nascimento: (dd) \n");
        				scanf("%d", &vetorAlunos[posvetor].dataNascimento.dia);
        				printf("Mês do Nascimento: (mm) \n");
        				scanf("%d", &vetorAlunos[posvetor].dataNascimento.mes);
        				printf("Ano do Nascimento: (aaaa) \n");
        				scanf("%d", &vetorAlunos[posvetor].dataNascimento.ano);
        				getchar();
        				
        				// SUGESTÃO DE MELHORIA: ANÁLISE DE ANO POR BISSEXTO. **SOMENTE DEPOIS QUE ESTIVERMOS VALIDADO O BÁSICO.
        				if((vetorAlunos[posvetor].dataNascimento.ano > 2021) || (vetorAlunos[posvetor].dataNascimento.ano <= 1930))
        				{	
        					printf("Ano de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n");
        					printf("Informe novamente os dados abaixo. \n");
        				}
        				else
        				{
        					if((vetorAlunos[posvetor].dataNascimento.mes <= 12) || (vetorAlunos[posvetor].dataNascimento.ano > 0))
        					{
        						if((vetorAlunos[posvetor].dataNascimento.mes == 1) || (vetorAlunos[posvetor].dataNascimento.mes == 3) || (vetorAlunos[posvetor].dataNascimento.mes == 5) || (vetorAlunos[posvetor].dataNascimento.mes == 7) || (vetorAlunos[posvetor].dataNascimento.mes == 8) || (vetorAlunos[posvetor].dataNascimento.mes == 10) || (vetorAlunos[posvetor].dataNascimento.mes == 12))
        						{
        							if((vetorAlunos[posvetor].dataNascimento.dia <= 0 || vetorAlunos[posvetor].dataNascimento.dia > 31))
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
        							if(vetorAlunos[posvetor].dataNascimento.mes == 2)
        							{
        								if((vetorAlunos[posvetor].dataNascimento.dia <= 0 || vetorAlunos[posvetor].dataNascimento.dia >= 29))
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
        								if((vetorAlunos[posvetor].dataNascimento.dia <= 0 || vetorAlunos[posvetor].dataNascimento.dia >= 30))
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

              /*printf("Dia do Nascimento: (dd) \n");
        			scanf("%d", &vetorAlunos[posvetor].dataNascimento.dia);
        			getchar();
        			printf("Mês do Nascimento: (mm) \n");
        			scanf("%d", &vetorAlunos[posvetor].dataNascimento.mes);
        			getchar();
        			printf("Ano do Nascimento: (aaaa)\n");
        			scanf("%d", &vetorAlunos[posvetor].dataNascimento.ano);
        			getchar();*/

              //while validade CPF  
              validacpf = 0;
              while(validacpf == 0)
        			{
        				printf("CPF: (Somente números) \n");
        				fflush(stdin);
        				fgets(vetorAlunos[posvetor].CPF, 15, stdin);
        					
        				ln = strlen(vetorAlunos[posvetor].CPF) - 1; //comando para retirar o \n gerado pelo fgets
        		    if (vetorAlunos[posvetor].CPF[ln] == '\n')
        				{
        		      vetorAlunos[posvetor].CPF[ln] = '\0';	
        				}			
                
                soma = strlen(vetorAlunos[posvetor].CPF);
                
                if(soma < 11)
                {
                  printf("CPF com tamanho inválido. Deve ter 11 caracteres. \n");
          			  printf("Por favor, informe o ");
                }
                else
                {
                  validacpf = 1;
                }
              }
              /*printf("CPF: (Somente Números) \n");
        			fflush(stdin);
        			fgets(vetorAlunos[posvetor].CPF, 15, stdin);
        			
        			ln = strlen(vetorAlunos[posvetor].CPF) - 1; //comando para retirar o \n gerado pelo fgets
        		  if (vetorAlunos[posvetor].CPF[ln] == '\n')
        		  {
        	      vetorAlunos[posvetor].CPF[ln] = '\0';	
        			}*/ 
            }
          }
    		} 				
      }      		
		}
		if(opcao == 4) // Opção para Excluir aluno
		{
			if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
			}
			else
			{
        posvetor = -1;
        while(posvetor == -1)
        {
          printf("Informe a matrícula do Aluno que deseja EXCLUIR. \n");
  				scanf("%d", &matricula);
          getchar();

          if(matricula <=0)
          {
            printf("Matrícula informada não existe. \n");
      			printf("Por favor, ");
          }
          else
          {
            for(icont = 0; icont<qtdealunos; icont++)
    				{
    					if(vetorAlunos[icont].matricula == matricula)
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
              printf("--- ALUNO A SER EXCLUÍDO %d --- \n", matricula);
      				printf("Nome: %s \n", vetorAlunos[posvetor].nome);
      				printf("Sexo: %c \n", vetorAlunos[posvetor].sexo);
      				printf("Data Nascimento: %d/%d/%d \n", vetorAlunos[posvetor].dataNascimento.dia, vetorAlunos[posvetor].dataNascimento.mes, vetorAlunos[posvetor].dataNascimento.ano);
      				printf("CPF: %s \n", vetorAlunos[posvetor].CPF);
      				printf("________________________________________________ \n");
      				
      				printf("Excluindo dados... \n");
      									
      				vetorAlunos[posvetor].matricula = 0;		
      				strcpy(vetorAlunos[posvetor].nome, "Aluno excluído.");
      				vetorAlunos[posvetor].sexo = '0';
      				vetorAlunos[posvetor].dataNascimento.dia = 0;
      				vetorAlunos[posvetor].dataNascimento.mes = 0;
      				vetorAlunos[posvetor].dataNascimento.ano = 0;
      				strcpy(vetorAlunos[posvetor].CPF, "0");									
      							
      				printf("Aluno excluído. \n");	
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
    
    
		



