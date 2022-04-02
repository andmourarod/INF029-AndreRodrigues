#include <stdio.h>
#include <string.h>
#define qtdedisciplina 2
//#define qtdealunos 2

typedef struct st_disciplina
{
	char nome[51];
	int codigo;
	int semestre;  
	char professor[51];
			
}Disciplina;

int main()
{
	int opcao, icont, jcont, kcont, lista = 0, finalizar = 0, codigo, posvetor = -1, ndisciplina, validacodigo = 0, validasemestre = 0, validaprofessor = 0, contdisciplina=0;
	incluir vetorDisciplinas[qtdedisciplina]; //inicialmente definido em 2.
	     
    while(finalizar == 0)
    {
    	printf("--- Gestão de Disciplinas --- \n");
	    printf("0 - Sair \n");
	    printf("1 - Incluir Disciplinas \n");
	    printf("2 - Listar Disciplinas \n");
	    printf("3 - Atualizar Disciplinas \n");
	    printf("4 - Excluir Disciplinas \n");
	    printf("Informe o que deseja fazer: \n");
	    scanf("%d", &opcao);
	    //printf("\n");
	    
		if(opcao == 0)
	    {
	    	finalizar = 1;
			printf("Finalizando Gestão de Disciplinas. \n");    	
		}
		if(opcao == 1)
		{
		    if(contdisciplina >= qtdedisciplina)
		    {
		        printf("Não há mais vagas para inclusão. \n");
		    }
		    else
		    {
		      printf("-- INCLUSÃO DE DISCIPLINAS --\n");
			//Inserir condição de contaluno < qtdealunos, printar que não há mais vagas.
			//while(validacadastro == 0)
			//{
    			ndisciplina = contdisciplina + 1;
    			printf("- DADOS DA DISCIPLINA %d - \n", ndisciplina);				
    			while(validacodigo == 0)
    			{
    				printf("Código da Disciplina \n");
    				scanf("%d", &vetorDisciplinas[contdisciplina].codigo);
    				getchar();
    				if(contdisciplina > 0) // condição para evitar repetição de código.
                    {
                        for(kcont = 0; kcont < contdisciplina; kcont++)
                        {
                            if (vetorDisciplinas[kcont].codigo == vetorDisciplinas[contdisciplina].codigo)
                            {
                            vetorDisciplinas[contdisciplina].codigo = 0;  
                            }                  
                        }
                    }      	
    				if(vetorDisciplinas[contdisciplina].codigo <= 0)
    				{
    					printf("Código inválido. Este dado deve ser um número inteiro e positivo.  \n");
    					printf("Informe novamente o ");	
    				}
    				else
    				{
    					validacodigo= 1;
    				}
    			}		
    			validacodigo = 0;
    					
    			printf("Nome da Disciplina (até 50 caracteres): \n");
    			fflush(stdin);
    			fgets(vetorDisciplinas[contdisciplina].nome, 51, stdin);
    				
    			size_t ln = strlen(vetorDisciplinas[contdisciplina].nome) - 1; //comando para retirar o \n gerado pelo fgets
    	    if (vetorDisciplinas[contdisciplina].nome[ln] == '\n')
    	    {
    	      vetorDisciplinas[contdisciplina].nome[ln] = '\0';	
    			}
    			validasemestre = 0;
    			while(validasemestre == 0)
    			{
    				printf("Informe o semestre da Disciplina \n");
    				scanf("%c", &vetorDisciplinas[contdisciplina].semestre);
    				getchar();
    				
    				if((vetorDisciplinas[contdisciplina] >= 1))
    				{
    						validasemestre = 1;								
    				}				
    				else
    				{						
    					validasemestre = 0;	
    					printf("Semestre inválido. O número de semestre deve ser maior que 1. \n");
    					printf("Informe novamente o ");
    				}	
    			}
    			   				       				
    			while(validaprofessor == 0)
    			{
    				printf("Informe o nome do Professor. \n");
            fflush(stdin);
      			fgets(vetorDisciplinas[contdisciplina].professor, 51, stdin);
      				
      			size_t ln = strlen(vetorDisciplinas[contdisciplina].professor) - 1; //comando para retirar o \n gerado pelo fgets
      	    if (vetorDisciplinas[contdisciplina].professor[ln] == '\n')
      	    {
      	      vetorDisciplinas[contdisciplina].professor[ln] = '\0';	
      			}

            nomesiguais = 2;
            for(kcont=0; kcont < qtdeprofessores && nomesiguais != 0 ; kcont++)
            {
              nomesiguais = (strcmp(vetorDisciplinas[contdisciplina].professor), vetorProfessores[kcont].nome) 
            }

            if(nomesiguais == 0)
            {
              validaprofessor = 1;  
            }
            else
            {
              printf("Nome de Professor não encontrado no Banco de Dados de Professores. \n");
              printf("Por favor, ");
            }
          }            
		    contdisciplina++;
			lista = 1;
		  }
		  finalizar = 0;
		}
		if (opcao == 2)
		{
			if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir uma disciplina no sistema. \n \n");
				finalizar = 0;
			}
			else
			{        
				printf("\n--- LISTA DE DISCIPLINAS --- \n \n");
	      for (icont = 0; icont < contdisciplina; icont++) //imprime a quantidade de alunos que foram incluídos.              
				{
			    printf("Nome: %s \n", vetorDisciplinas[icont].nome);
			    printf("Código: %d \n", vetorDisciplinas[icont].codigo);
			    printf("Semestre: %d \n", vetorDisciplinas[icont].semestre);
			    printf("Professor: %s \n \n", vetorDisciplinas[icont].professor);
			  }		
			  printf("________________________________________________ \n");
	    }		
		}
		if(opcao == 3)
		{
			if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir de disciplina no sistema. \n \n");
			}
			else
			{
        posvetor = -1;
			  while(posvetor == -1)
			  {
    			printf("Informe o código da Matrícula que deseja atualizar. \n");
    			scanf("%d", &codigo);
    			getchar();

          if(codigo <= 0) //Verificação de matrículas negativas.
          {
            printf("Código informado não existe. \n");
      			printf("Por favor, ");
          }
          else
          {
            for(icont = 0; icont<qtdedisciplina; icont++)
    			  {
    				  if(vetorDisciplinas[icont].codigo == codigo)
    				  {
    					posvetor = icont;
    				  }
    			  }      	          
      			if(posvetor == -1)
      			{
      			  printf("Código informado não existe. \n");
      			  printf("Por favor, ");
      			}
      			else
      			{
        			printf("--- DADOS DA MATRÍCULA DE CÓDIGO: %d --- \n", codigo);
        			printf("Nome: %s \n", vetorDisciplinas[posvetor].nome);
			        printf("Código: %d \n", vetorDisciplinas[posvetor].codigo);
			        printf("Semestre: %d \n", vetorDisciplinas[posvetor].semestre);
			        printf("Professor: %s \n \n", vetorDisciplinas[posvetor].professor);
          		printf("________________________________________________ \n");
          			
          		printf("--- ATUALIZAÇÃO DE DADOS DA MATRÍCULA --- \n");
              validacodigo = 0;
          		while(validacodigo == 0)
    			    {
      				  printf("Código da Disciplina \n");
      				  scanf("%d", &vetorDisciplinas[posvetor].codigo);
      				  getchar();
      				  if(posvetor > 0) // condição para evitar repetição de código.
                {
                  for(kcont = 0; kcont < posvetor; kcont++)
                  {
                  if (vetorDisciplinas[kcont].codigo == vetorDisciplinas[posvetor].codigo)
                    {
                      vetorDisciplinas[posvetor].codigo = 0;  
                    }                  
                  }
                }      	
      				  if(vetorDisciplinas[posvetor].codigo <= 0)
        				{
        					printf("Código inválido. Este dado deve ser um número inteiro e positivo.  \n");
        					printf("Informe novamente o ");	
        				}
        				else
        				{
        					validacodigo= 1;
        				}
    			    }	            
    			    validacodigo = 0;    					
    			    printf("Nome da Disciplina (até 50 caracteres): \n");
    			    fflush(stdin);
    			    fgets(vetorDisciplinas[posvetor].nome, 51, stdin);
    					size_t ln = strlen(vetorDisciplinas[posvetor].nome) - 1; //comando para retirar o \n gerado pelo fgets
        	    if (vetorDisciplinas[posvetor].nome[ln] == '\n')
        	    {
        	      vetorDisciplinas[posvetor].nome[ln] = '\0';	
        			}
    			    validasemestre = 0;
    			    while(validasemestre == 0)
    			    {
      				  printf("Informe o semestre da Disciplina \n");
      				  scanf("%c", &vetorDisciplinas[posvetor].semestre);
      				  getchar();
      				
        				if((vetorDisciplinas[posvetor] >= 1))
        				{
        						validasemestre = 1;								
        				}				
        				else
        				{						
        					validasemestre = 0;	
        					printf("Semestre inválido. O número de semestre deve ser maior que 1. \n");
        					printf("Informe novamente o ");
        				}	
      			  }    			   				       				
    			    while(validaprofessor == 0)
    			    {
        				printf("Informe o nome do Professor. \n");
                fflush(stdin);
          			fgets(vetorDisciplinas[posvetor].professor, 51, stdin);
          				
          			size_t ln = strlen(vetorDisciplinas[posvetor].professor) - 1; //comando para retirar o \n gerado pelo fgets
          	    if (vetorDisciplinas[posvetor].professor[ln] == '\n')
          	    {
          	      vetorDisciplinas[posvetor].professor[ln] = '\0';	
          			}
    
                nomesiguais = 2;
                for(kcont=0; kcont < qtdeprofessores && nomesiguais != 0 ; kcont++)
                {
                  nomesiguais = (strcmp(vetorDisciplinas[posvetor].professor), vetorProfessores[kcont].nome) 
                }
    
                if(nomesiguais == 0)
                {
                  validaprofessor = 1;  
                }
                else
                {
                  printf("Nome de Professor não encontrado no Banco de Dados de Professores. \n");
                  printf("Por favor, ");
                }
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
				printf("Primeiramente, você deve inserir/incluir disciplinas no sistema. \n \n");
			}
			else
			{
        posvetor = -1;
			  while(posvetor == -1)
			  {
    			printf("Informe o código da Disciplina que deseja EXCLUIR. \n");
    			scanf("%d", &codigo);

          if(codigo <= 0) //Verificação de matrículas negativas.
          {
            printf("Código informado não existe. \n");
      			printf("Por favor, ");
          }
          else
          {
            for(icont = 0; icont<qtdedisciplinas; icont++)
      			{
        			if(vetorDisciplinas[icont].matricula == codigo)
        			{
        				posvetor = icont;
        			}
      	  	}            
      			if(posvetor == -1)
      			{
      		    printf("Código informado não existe. \n");
      		    printf("Por favor, ");
      			}
      			else
      			{
          		printf("--- DISCIPLINA A SER EXCLUÍDA %d --- \n", codigo);
          		printf("Nome: %s \n", vetorDisciplinas[posvetor].nome);
			        printf("Código: %d \n", vetorDisciplinas[posvetor].codigo);
			        printf("Semestre: %d \n", vetorDisciplinas[posvetor].semestre);
			        printf("Professor: %s \n \n", vetorDisciplinas[posvetor].professor);
          		printf("________________________________________________ \n");
          				
          		printf("Excluindo dados... \n");
          									
        			vetorDisciplinas[posvetor].codigo = 0;		
      				strcpy(vetorvetorDisciplinas[posvetor].nome, "Disciplina excluída.");
          		vetorDisciplinas[posvetor].semestre = 0;          		
      				strcpy(vetorDisciplinas[posvetor].professor, "0");	        							
      				printf("Disciplina excluído. \n \n");	  
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

      
			/*for(icont = 0; icont < qtdedisciplina; icont++)
			{
				ndisciplina = icont + 1;
				printf("- DADOS DA DISCIPLINA %d - \n", ndisciplina);
				printf("Nome da Disciplina (até 50 caracteres): \n");
				fflush(stdin);
				fgets(vetorDisciplinas[icont].nome, 51, stdin);
				
				size_t ln = strlen(vetorDisciplinas[icont].nome) - 1; //comando para retirar o \n gerado pelo fgets
	        	if (vetorDisciplinas[icont].nome[ln] == '\n')
	        	{
	        		vetorDisciplinas[icont].nome[ln] = '\0';	
				}
				
				printf("Código da Disciplina (Somente Números): \n");
				scanf("%d", &vetorDisciplinas[icont].codigo);
				getchar();
				
				printf("Semestre: \n");
				scanf("%d", &vetorDisciplinas[icont].semestre);
				
				
				printf("Professor da Disciplina (até 50 caracteres): \n");
				fflush(stdin);
				fgets(vetorDisciplinas[icont].professor, 51, stdin);
				
				ln = strlen(vetorDisciplinas[icont].professor) - 1; //comando para retirar o \n gerado pelo fgets
	        	if (vetorDisciplinas[icont].professor[ln] == '\n')
	        	{
	        		vetorDisciplinas[icont].professor[ln] = '\0';	
				}	 
			}
			lista = 1; //informa que há alunos listados.
		}
		if (opcao == 2)
		{
			if(lista == 0)
			{
				printf("\n A lista está vazia. \n");
				printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
			}
			else
			{
				printf("\n--- LISTA DE DISCIPLINAS --- \n");
	        	for (icont = 0; icont < qtdealunos; icont++)
				{
			        printf("Nome: %s \n", vetorDisciplinas[icont].nome);
			        printf("Código: %d \n", vetorDisciplinas[icont].codigo);
			        printf("Semestre: %d \n", vetorDisciplinas[icont].semestre);
			        printf("Professor: %s \n \n", vetorDisciplinas[icont].professor); 			        
				}
			    printf("______________________________________________\n");
	        }		
		}
		if(opcao == 3) //codigo é uma char. Tenho que comparar 2 strings. Usar strcomp
		{
			printf("Informe o código da Disciplina que deseja atualizar. \n");
			scanf("%d", &codigo);
			
			for(icont = 0; icont<qtdealunos; icont++)
			{
				if(vetorDisciplinas[icont].codigo == codigo)
				{
					posvetor = icont;
				}
			}
			
			printf("--- DADOS DA DISCIPLINA - CÓDIGO: %d --- \n", codigo);
			printf("Nome: %s \n", vetorDisciplinas[posvetor].nome);
			printf("Semestre: %d \n", vetorDisciplinas[posvetor].semestre);
			printf("Professor: %s \n", vetorDisciplinas[posvetor].professor); 	
			
			
			printf("--- ATUALIZAÇÃO DE DADOS DA DISCIPLINA ---");
			printf("Nome da Disciplina (até 50 caracteres): \n");
				fflush(stdin);
				fgets(vetorDisciplinas[posvetor].nome, 51, stdin);
				
				size_t ln = strlen(vetorDisciplinas[posvetor].nome) - 1; //comando para retirar o \n gerado pelo fgets
	        	if (vetorDisciplinas[posvetor].nome[ln] == '\n')
	        	{
	        		vetorDisciplinas[posvetor].nome[ln] = '\0';	
				}
				
				printf("Código da Disciplina (até 9 caracteres): \n");
				scanf("%d", &vetorDisciplinas[posvetor].codigo);
				
				printf("Semestre: \n");
				scanf("%d", &vetorDisciplinas[posvetor].semestre);
				
				printf("Professor da Disciplina (até 50 caracteres): \n");
				fflush(stdin);
				fgets(vetorDisciplinas[posvetor].professor, 51, stdin);
				
				ln = strlen(vetorDisciplinas[posvetor].professor) - 1; //comando para retirar o \n gerado pelo fgets
	        	if (vetorDisciplinas[posvetor].professor[ln] == '\n')
	        	{
	        		vetorDisciplinas[posvetor].professor[ln] = '\0';	
				}	 
		}
		if(opcao == 4)
		{
			printf("Informe o código da Disciplina que deseja EXCLUIR. \n");
			scanf("%d", &codigo);
			
			for(icont = 0; icont<qtdedisciplina; icont++)
			{
				if(vetorDisciplinas[icont].codigo == codigo)
				{
					posvetor = icont;
				}
			}
			
			printf("--- DISCIPLINA A SER EXCLUÍDA --- \n");
			printf("Nome: %s \n", vetorDisciplinas[posvetor].nome);
			printf("Código: %d \n", vetorDisciplinas[posvetor].codigo);
			printf("Semestre: %d \n", vetorDisciplinas[posvetor].semestre);
			printf("Professor: %s \n", vetorDisciplinas[posvetor].professor); 	
			
			printf("Excluindo dados... \n");
			
			strcpy(vetorDisciplinas[posvetor].nome, "0");
			vetorDisciplinas[posvetor].codigo = 0;
			vetorDisciplinas[posvetor].semestre = 0;
			strcpy(vetorDisciplinas[posvetor].professor, "0");
			  
			printf("Disciplina Excluída. \n");		
		}
		/*if(opcao == 5)
		{
			
			printf("--- MATRÍCULAS DE ALUNO EM DISCIPLINAS --- \n");
						
			do
			{
				for(icont = 0; icont < qtdedisciplina; icont++)
				{
					printf("Informe o código da matéria que deseja inserir o aluno. \n");
					scanf("%d", &codigo);
					if(vetorDisciplinas[icont].codigo == codigo)
					{
						validacao = 1;
					}
					else
					{
						printf("Código invalido. Favor informar um código de matéria cadastrada anteriormente. \n");
						validacao = 0;
					}
				}	
			}while(validacao == 0);
			
			if(validacao == 1)
			{
				printf("Informe a matrícula do(s) aluno(s) a ser incluído na matéria %d \n", codigo);
				for(icont = 0; icont < qtdealunos; icont++)
				{
					scanf("%d", &vetoralunosmatriculados[icont]);
				}
			}			
		}
		if(opcao == 6)
		{
			
		}*/
		if(opcao > 4)
		{
			printf("Opção inválida. \n");
		}    
    }
	return 0;	
}


