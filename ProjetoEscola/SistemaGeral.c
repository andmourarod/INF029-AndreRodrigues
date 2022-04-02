#include <stdio.h>
#include <string.h>
#define qtdealunos 3
#define qtdeprofessores 3
#define qtdedisciplina 2

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

typedef struct
{
  int codigo;
  char nome[51];
  int semestre;
  char professor[51];
}incluirdisc;

int main()
{
  int opcaomenugeral, finalizarmenugeral = 0, opcaoaluno, icontaluno, jcontaluno, kcontaluno, listaaluno = 0, finalizaraluno = 0, matriculaaluno, posvetoraluno, naluno, validamatriculaaluno = 0, validacpfaluno = 0, validadatadenascimentoaluno = 0, validasexoaluno = 0, somaaluno = 0, somaiguaisaluno = 0, contaluno=0;
	incluir vetorAlunos[qtdealunos]; //inicialmente definido em 2. 

  int opcaoprof, icontprof, jcontprof, kcontprof, listaprof = 0, finalizarprof = 0, matriculaprof, posvetorprof = -1, nprofessor, validamatriculaprof = 0, validacpfprof = 0, validadatadenascimentoprof = 0, validasexoprof = 0, somaprof = 0, contprofessor=0;
	incluir vetorProfessores[qtdeprofessores]; //inicialmente definido em 2.

  int opcaodisc, icontdisc, jcondisct, kcontdisc, listadisc = 0, finalizardisc = 0, codigodisc, posvetordisc = -1, ndisciplinadisc, validacodigodisc = 0, validasemestredisc = 0, validaprofessordisc = 0, contdisciplinadisc=0, nomesiguaisdisc;
	incluirdisc vetorDisciplinas[qtdedisciplina]; //inicialmente definido em 2.

  incluir vetorAuxAlunosProfessores;
  incluir vetorAuxDisciplinas;
  
  int finalizarrel, opcaorel;  
  int prints = 0, mes;
  while(finalizarmenugeral == 0)
  {
    printf("--- SISTEMA DE GERENCIAMENTO DA ESCOLA INF-029---\n");
  	printf("(0) - Sair \n");
  	printf("(1) - Gestão de Alunos \n");
    printf("(2) - Gestão de Professores \n");
  	printf("(3) - Gestão de Disciplinas \n");
  	printf("(4) - Matrícula de Aluno \n");
    printf("(5) - Relatórios\n"); 
    printf("Informe o que deseja fazer: \n");
  	scanf("%d", &opcaomenugeral); 
    getchar();
  
    if(opcaomenugeral == 0)
    {
      finalizarmenugeral = 1;
      printf("Finalizado Sistema de Gerenciamento Escolar. \n");
    }
    if(opcaomenugeral == 1)
    {    
      finalizaraluno = 0;
      while(finalizaraluno == 0)
      {
      	printf("--- Gestão de Alunos --- \n");
  	    printf("0 - Sair \n");
  	    printf("1 - Incluir Aluno \n");
  	    printf("2 - Listar Alunos \n");
  	    printf("3 - Atualizar Aluno \n");
  	    printf("4 - Excluir Aluno \n");
  	    printf("Informe o que deseja fazer: \n");
  	    scanf("%d", &opcaoaluno);
        getchar();  	    
  	    
    		if(opcaoaluno == 0) // Opção para Sair do Gestão Alunos.
    	  {
    	    finalizaraluno = 1;
    			printf("Finalizando Gestão de Alunos. \n");    	
    		}
    		if(opcaoaluno == 1)
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
        			while(validamatriculaaluno == 0)
        			{
        				printf("Matricula do Aluno: \n");
        				scanf("%d", &vetorAlunos[contaluno].matricula);
        				getchar();
    
                if(contaluno > 0) // Condição para evitar repetição de matrícula.
                {
                  for(kcontaluno = 0; kcontaluno < contaluno; kcontaluno++)
                  {
                    if (vetorAlunos[kcontaluno].matricula == vetorAlunos[contaluno].matricula)
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
        					validamatriculaaluno = 1;
        				}
        			}		
        			validamatriculaaluno = 0;
        					
        			printf("Nome do Aluno (até 50 caracteres): \n");
        			fflush(stdin);
        			fgets(vetorAlunos[contaluno].nome, 51, stdin);
        				
        			size_t ln = strlen(vetorAlunos[contaluno].nome) - 1; //comando para retirar o \n gerado pelo fgets
        	        if (vetorAlunos[contaluno].nome[ln] == '\n')
        	        {
        	        	vetorAlunos[contaluno].nome[ln] = '\0';	
        			}
        				
        			while(validasexoaluno == 0)
        			{
        				printf("Sexo: (M)Masculino/(F)Feminino \n");
        				scanf("%c", &vetorAlunos[contaluno].sexo);
        				getchar();
        				
        				if((vetorAlunos[contaluno].sexo == 'M') || (vetorAlunos[contaluno].sexo == 'F'))
        				{
        						validasexoaluno = 1;								
        				}				
        				else
        				{						
        					validasexoaluno = 0;	
        					printf("Sexo Inválido. Digite M para Masculino, F para Feminino. \n");
        					printf("Informe novamente o ");
        				}	
        			}
        			validasexoaluno = 0;		
        				       				
        			while(validadatadenascimentoaluno == 0)
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
        					if((vetorAlunos[contaluno].dataNascimento.mes <= 12) && (vetorAlunos[contaluno].dataNascimento.mes > 0))
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
        								validadatadenascimentoaluno = 1;
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
        								validadatadenascimentoaluno = 1;
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
        									validadatadenascimentoaluno = 1;
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
        			validadatadenascimentoaluno = 0;
        			while(validacpfaluno == 0)
        			{
        				printf("CPF: (Somente números) \n");
        				fflush(stdin);
        				fgets(vetorAlunos[contaluno].CPF, 15, stdin);
        					
        				ln = strlen(vetorAlunos[contaluno].CPF) - 1; //comando para retirar o \n gerado pelo fgets
        		    if (vetorAlunos[contaluno].CPF[ln] == '\n')
        				{
        		      vetorAlunos[contaluno].CPF[ln] = '\0';	
        				}			
                
                somaaluno = strlen(vetorAlunos[contaluno].CPF);
                
                if(somaaluno < 11)
                {
                  printf("CPF com tamanho inválido. Deve ter 11 caracteres. \n");
          			  printf("Por favor, informe o ");
                }
                else
                {
                  validacpfaluno = 1;
                }
              }
          validacpfaluno = 0;    				
    			contaluno++;
    			listaaluno = 1;
          }	  
        }
    		if (opcaoaluno == 2) // Opção de Listar Alunos
    		{
    			if(listaaluno == 0)
    			{
    				printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
    				finalizaraluno = 0;
    			}
    			else
    			{        
    				printf("\n--- LISTA DE ALUNOS --- \n \n");
    	        	for (icontaluno = 0; icontaluno < contaluno; icontaluno++) //imprime a quantidade de alunos que foram incluídos.              
    				{
    			        printf("Matrícula: %d \n", vetorAlunos[icontaluno].matricula);
    			        printf("Nome: %s \n", vetorAlunos[icontaluno].nome);
    			        printf("Sexo: %c \n", vetorAlunos[icontaluno].sexo);
    			        printf("Data Nascimento: %d/%d/%d \n", vetorAlunos[icontaluno].dataNascimento.dia, vetorAlunos[icontaluno].dataNascimento.mes, vetorAlunos[icontaluno].dataNascimento.ano);
    			        printf("CPF: %s \n \n", vetorAlunos[icontaluno].CPF);
    			  }		
    			    printf("________________________________________________ \n");
    	    }		
    		}
    		if(opcaoaluno == 3) // Opção de atualizar alunos.
    		{
    			if(listaaluno == 0)
    			{
    				printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
    			}
    			else
    			{
            posvetoraluno = -1;		
            while(posvetoraluno == -1)
    			  {
              printf("Informe a matrícula do Aluno que deseja atualizar. \n");
        			scanf("%d", &matriculaaluno);
        			getchar();
              if(matriculaaluno <= 0) //Verificação de matrículas negativas.
              {
                printf("Matrícula informada não existe. \n");
          			printf("Por favor, ");
              }
              else
              {
                for(icontaluno = 0; icontaluno<qtdealunos; icontaluno++)
          			{
          				if(vetorAlunos[icontaluno].matricula == matriculaaluno)
          				{
          					posvetoraluno = icontaluno;
          				}
          			}  
                if(posvetoraluno == -1)
                {
                  printf("Matrícula informada não existe. \n");
            			printf("Por favor, ");            
                }
                else
                {
                  printf("--- DADOS DO ALUNO DE MATRICULA: %d --- \n", matriculaaluno);
            			printf("Nome: %s \n", vetorAlunos[posvetoraluno].nome);
            			printf("Sexo: %c \n", vetorAlunos[posvetoraluno].sexo);
            			printf("Data Nascimento: %d/%d/%d \n", vetorAlunos[posvetoraluno].dataNascimento.dia, vetorAlunos[posvetoraluno].dataNascimento.mes, vetorAlunos[posvetoraluno].dataNascimento.ano);
            			printf("CPF: %s \n", vetorAlunos[posvetoraluno].CPF);
            			printf("________________________________________________ \n");
            			
            			printf("--- ATUALIZAÇÃO DE DADOS DO ALUNO --- \n");
            			printf("Nome do Aluno (até 50 caracteres): \n");
            			fflush(stdin);
            			fgets(vetorAlunos[posvetoraluno].nome, 51, stdin);
            				
            			size_t ln = strlen(vetorAlunos[posvetoraluno].nome) - 1; //comando para retirar o \n gerado pelo fgets
            		  if (vetorAlunos[posvetoraluno].nome[ln] == '\n')
            		  {
            	      vetorAlunos[posvetoraluno].nome[ln] = '\0';	
            			}
    
                  validasexoaluno = 0;  
                  while(validasexoaluno == 0)
            			{
            				printf("Sexo: (M)Masculino/(F)Feminino \n");
            				scanf("%c", &vetorAlunos[posvetoraluno].sexo);
            				getchar();
            				
            				if((vetorAlunos[posvetoraluno].sexo == 'M') || (vetorAlunos[posvetoraluno].sexo == 'F'))
            				{
            					validasexoaluno = 1;								
            				}				
            				else
            				{						
            					validasexoaluno = 0;	
            					printf("Sexo Inválido. Digite M para Masculino, F para Feminino. \n");
            					printf("Informe novamente o ");
            				}	
            			}
        				  /*printf("Sexo: (M)Masculino/(F)Feminino \n");
          				scanf("%c", &vetorAlunos[posvetor].sexo);*/
    
                  validadatadenascimentoaluno = 0;
                  while(validadatadenascimentoaluno == 0)
        			    {
            				printf("Dia do Nascimento: (dd) \n");
            				scanf("%d", &vetorAlunos[posvetoraluno].dataNascimento.dia);
            				printf("Mês do Nascimento: (mm) \n");
            				scanf("%d", &vetorAlunos[posvetoraluno].dataNascimento.mes);
            				printf("Ano do Nascimento: (aaaa) \n");
            				scanf("%d", &vetorAlunos[posvetoraluno].dataNascimento.ano);
            				getchar();
            				
            				// SUGESTÃO DE MELHORIA: ANÁLISE DE ANO POR BISSEXTO. **SOMENTE DEPOIS QUE ESTIVERMOS VALIDADO O BÁSICO.
            				if((vetorAlunos[posvetoraluno].dataNascimento.ano > 2021) || (vetorAlunos[posvetoraluno].dataNascimento.ano <= 1930))
            				{	
            					printf("Ano de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n");
            					printf("Informe novamente os dados abaixo. \n");
            				}
            				else
            				{
            					if((vetorAlunos[posvetoraluno].dataNascimento.mes <= 12) &&(vetorAlunos[posvetoraluno].dataNascimento.mes > 0))
            					{
            						if((vetorAlunos[posvetoraluno].dataNascimento.mes == 1) || (vetorAlunos[posvetoraluno].dataNascimento.mes == 3) || (vetorAlunos[posvetoraluno].dataNascimento.mes == 5) || (vetorAlunos[posvetoraluno].dataNascimento.mes == 7) || (vetorAlunos[posvetoraluno].dataNascimento.mes == 8) || (vetorAlunos[posvetoraluno].dataNascimento.mes == 10) || (vetorAlunos[posvetoraluno].dataNascimento.mes == 12))
            						{
            							if((vetorAlunos[posvetoraluno].dataNascimento.dia <= 0 || vetorAlunos[posvetoraluno].dataNascimento.dia > 31))
            							{
            								printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 31 \n");
            								printf("Informe novamente os dados abaixo. \n");
            							}
            							else
            							{
            								validadatadenascimentoaluno = 1;
            							}
            						}
            						else
            						{
            							if(vetorAlunos[posvetoraluno].dataNascimento.mes == 2)
            							{
            								if((vetorAlunos[posvetoraluno].dataNascimento.dia <= 0 || vetorAlunos[posvetoraluno].dataNascimento.dia >= 29))
            								{
            								printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 28 para anos não bissextos e 29 para anos bissextos \n");
            								printf("Informe novamente os dados abaixo. \n");
            								}
            								else
            								{
            								validadatadenascimentoaluno = 1;
            								}
            							}
            							else
            							{
            								if((vetorAlunos[posvetoraluno].dataNascimento.dia <= 0 || vetorAlunos[posvetoraluno].dataNascimento.dia >= 30))
            								{
            									printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 30 \n");
            									printf("Informe novamente os dados abaixo. \n");
            								}
            								else
            								{
            									validadatadenascimentoaluno = 1;
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
                  validacpfaluno = 0;
                  while(validacpfaluno == 0)
            			{
            				printf("CPF: (Somente números) \n");
            				fflush(stdin);
            				fgets(vetorAlunos[posvetoraluno].CPF, 15, stdin);
            					
            				ln = strlen(vetorAlunos[posvetoraluno].CPF) - 1; //comando para retirar o \n gerado pelo fgets
            		    if (vetorAlunos[posvetoraluno].CPF[ln] == '\n')
            				{
            		      vetorAlunos[posvetoraluno].CPF[ln] = '\0';	
            				}			
                    
                    somaaluno = strlen(vetorAlunos[posvetoraluno].CPF);
                    
                    if(somaaluno < 11)
                    {
                      printf("CPF com tamanho inválido. Deve ter 11 caracteres. \n");
              			  printf("Por favor, informe o ");
                    }
                    else
                    {
                      validacpfaluno = 1;
                    }
                  }                  
                }
              }
        		} 				
          }      		
    		}
    		if(opcaoaluno == 4) // Opção para Excluir aluno
    		{
    			if(listaaluno == 0)
    			{
    				printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
    			}
    			else
    			{
            posvetoraluno = -1;
            while(posvetoraluno == -1)
            {
              printf("Informe a matrícula do Aluno que deseja EXCLUIR. \n");
      				scanf("%d", &matriculaaluno);
              getchar();
    
              if(matriculaaluno <=0)
              {
                printf("Matrícula informada não existe. \n");
          			printf("Por favor, ");
              }
              else
              {
                for(icontaluno = 0; icontaluno<qtdealunos; icontaluno++)
        				{
        					if(vetorAlunos[icontaluno].matricula == matriculaaluno)
        					{
        						posvetoraluno = icontaluno;
        					}
        				}
                
                if(posvetoraluno == -1)
                {
                  printf("Matrícula informada não existe. \n");
          				printf("Por favor, ");
                }
                else
                {
                  printf("--- ALUNO A SER EXCLUÍDO %d --- \n", matriculaaluno);
          				printf("Nome: %s \n", vetorAlunos[posvetoraluno].nome);
          				printf("Sexo: %c \n", vetorAlunos[posvetoraluno].sexo);
          				printf("Data Nascimento: %d/%d/%d \n", vetorAlunos[posvetoraluno].dataNascimento.dia, vetorAlunos[posvetoraluno].dataNascimento.mes, vetorAlunos[posvetoraluno].dataNascimento.ano);
          				printf("CPF: %s \n", vetorAlunos[posvetoraluno].CPF);
          				printf("________________________________________________ \n");
          				
          				printf("Excluindo dados... \n");
          									
          				vetorAlunos[posvetoraluno].matricula = 0;		
          				strcpy(vetorAlunos[posvetoraluno].nome, "Aluno excluído.");
          				vetorAlunos[posvetoraluno].sexo = '0';
          				vetorAlunos[posvetoraluno].dataNascimento.dia = 0;
          				vetorAlunos[posvetoraluno].dataNascimento.mes = 0;
          				vetorAlunos[posvetoraluno].dataNascimento.ano = 0;
          				strcpy(vetorAlunos[posvetoraluno].CPF, "0");			
          							
          				printf("Aluno excluído. \n");	
                }  
              }  				
      			}        
          }				
    		}
    		if(opcaoaluno >= 5)
    		{
    			printf("Opção inválida. \n \n");
    		}    
      }  
    }
    if(opcaomenugeral == 2)
    { 
      finalizarprof = 0;
      while(finalizarprof == 0)
      {
      	printf("--- Gestão de Professores --- \n");
  	    printf("0 - Sair \n");
  	    printf("1 - Incluir Professor \n");
  	    printf("2 - Listar Professor \n");
  	    printf("3 - Atualizar Professor\n");
  	    printf("4 - Excluir Professor \n");
  	    printf("Informe o que deseja fazer: \n");
  	    scanf("%d", &opcaoprof);
  	    //printf("\n");
  	    
    		if(opcaoprof == 0)
    	    {
    	    	finalizarprof = 1;
    			printf("Finalizando Gestão de Professores. \n");    	
    		}
    		if(opcaoprof == 1)
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
        			while(validamatriculaprof == 0)
        			{
        				printf("Matricula do Professor: \n");
        				scanf("%d", &vetorProfessores[contprofessor].matricula);
        				getchar();
        				if(contprofessor > 0) // condição para evitar repetição de matrícula.
                        {
                            for(kcontprof = 0; kcontprof < contprofessor; kcontprof++)
                            {
                                if (vetorProfessores[kcontprof].matricula == vetorProfessores[contprofessor].matricula)
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
        					validamatriculaprof = 1;
        				}
        			}		
        			validamatriculaprof = 0;
        					
        			printf("Nome do Professor (até 50 caracteres): \n");
        			fflush(stdin);
        			fgets(vetorProfessores[contprofessor].nome, 51, stdin);
        				
        			size_t ln = strlen(vetorProfessores[contprofessor].nome) - 1; //comando para retirar o \n gerado pelo fgets
        	        if (vetorProfessores[contprofessor].nome[ln] == '\n')
        	        {
        	        	vetorProfessores[contprofessor].nome[ln] = '\0';	
        			}
        				
        			while(validasexoprof == 0)
        			{
        				printf("Sexo: (M)Masculino/(F)Feminino \n");
        				scanf("%c", &vetorProfessores[contprofessor].sexo);
        				getchar();
        				
        				if((vetorProfessores[contprofessor].sexo == 'M') || (vetorProfessores[contprofessor].sexo == 'F'))
        				{
        						validasexoprof = 1;								
        				}				
        				else
        				{						
        					validasexoprof = 0;	
        					printf("Sexo Inválido. Digite M para Masculino, F para Feminino. \n");
        					printf("Informe novamente o ");
        				}	
        			}
        			validasexoprof = 0;		
        				       				
        			while(validadatadenascimentoprof == 0)
        			{
        				printf("Dia do Nascimento: (dd) \n");
        				scanf("%d", &vetorProfessores[contprofessor].dataNascimento.dia);
        				printf("Mês do Nascimento: (mm) \n");
        				scanf("%d", &vetorProfessores[contprofessor].dataNascimento.mes);
        				printf("Ano do Nascimento: (aaaa) \n");
        				scanf("%d", &vetorProfessores[contprofessor].dataNascimento.ano);
        				getchar();
        				
        				// SUGESTÃO DE MELHORIA: ANÁLISE DE ANO POR BISSEXTO. **SOMENTE DEPOIS QUE ESTIVERMOS VALIDADO O BÁSICO.
        				if((vetorProfessores[contprofessor].dataNascimento.ano > 2021) ||(vetorProfessores[contprofessor].dataNascimento.ano <= 1930))
        				{	
        					printf("Ano de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n");
        					printf("Informe novamente os dados abaixo. \n");
        				}
        				else
        				{
        					if((vetorProfessores[contprofessor].dataNascimento.mes <= 12) && (vetorProfessores[contprofessor].dataNascimento.mes > 0))
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
        								validadatadenascimentoprof = 1;
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
        								validadatadenascimentoprof = 1;
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
        									validadatadenascimentoprof = 1;
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
        			validadatadenascimentoprof = 0;
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
    			listaprof = 1;
    		    }
    		    finalizarprof = 0;
    		}
    		if (opcaoprof == 2)
    		{
    			if(listaprof == 0)
    			{
    				printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir professores no sistema. \n \n");
    				finalizarprof = 0;
    			}
    			else
    			{
            
    				printf("\n--- LISTA DE PROFESSORES --- \n \n");
    	        	for (icontprof = 0; icontprof < contprofessor; icontprof++) //imprime a quantidade de alunos que foram incluídos.              
    				{
    			        printf("Matrícula: %d \n", vetorProfessores[icontprof].matricula);
    			        printf("Nome: %s \n", vetorProfessores[icontprof].nome);
    			        printf("Sexo: %c \n", vetorProfessores[icontprof].sexo);
    			        printf("Data Nascimento: %d/%d/%d \n", vetorProfessores[icontprof].dataNascimento.dia, vetorProfessores[icontprof].dataNascimento.mes, vetorProfessores[icontprof].dataNascimento.ano);
    			        printf("CPF: %s \n \n", vetorProfessores[icontprof].CPF);
    			    }		
    			    printf("________________________________________________ \n");
    	        }		
    		}
    		if(opcaoprof == 3)
    		{
    			if(listaprof == 0)
    			{
    				printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir professores no sistema. \n \n");
    			}
    			else
    			{
            posvetorprof = -1;
    			  while(posvetorprof == -1)
    			  {
        			printf("Informe a matrícula do Professor que deseja atualizar. \n");
        			scanf("%d", &matriculaprof);
        			getchar();
    
              if(matriculaprof <= 0) //Verificação de matrículas negativas.
              {
                printf("Matrícula informada não existe. \n");
          			printf("Por favor, ");
              }
              else
              {
                for(icontprof = 0; icontprof<qtdeprofessores; icontprof++)
        			  {
        				  if(vetorProfessores[icontprof].matricula == matriculaprof)
        				  {
        					posvetorprof = icontprof;
        				  }
        			  }      	
              
          			if(posvetorprof == -1)
          			{
          			  printf("Matrícula informada não existe. \n");
          			  printf("Por favor, ");
          			}
          			else
          			{
            			printf("--- DADOS DO PROFESSOR DE MATRICULA: %d --- \n", matriculaprof);
            			printf("Nome: %s \n", vetorProfessores[posvetorprof].nome);
              		printf("Sexo: %c \n", vetorProfessores[posvetorprof].sexo);
              		printf("Data Nascimento: %d/%d/%d \n", vetorProfessores[posvetorprof].dataNascimento.dia, vetorProfessores[posvetorprof].dataNascimento.mes, vetorProfessores[posvetorprof].dataNascimento.ano);
              		printf("CPF: %s \n", vetorProfessores[posvetorprof].CPF);
              		printf("________________________________________________ \n");
              			
              		printf("--- ATUALIZAÇÃO DE DADOS DO PROFESSOR --- \n");
              		printf("Nome do Professor (até 50 caracteres): \n");
              		fflush(stdin);
              		fgets(vetorProfessores[posvetorprof].nome, 51, stdin);
              				
              		size_t ln = strlen(vetorProfessores[posvetorprof].nome) - 1; //comando para retirar o \n gerado pelo fgets
          	      if (vetorProfessores[posvetorprof].nome[ln] == '\n')
           	      {
          		     	vetorProfessores[posvetorprof].nome[ln] = '\0';	
              		}
    
                  validasexoprof = 0;  
                  while(validasexoprof == 0)
            			{
            				printf("Sexo: (M)Masculino/(F)Feminino \n");
            				scanf("%c", &vetorProfessores[posvetorprof].sexo);
            				getchar();
            				
            				if((vetorProfessores[posvetorprof].sexo == 'M') || (vetorProfessores[posvetorprof].sexo == 'F'))
            				{
            					validasexoprof = 1;								
            				}				
            				else
            				{						
            					validasexoprof = 0;	
            					printf("Sexo Inválido. Digite M para Masculino, F para Feminino. \n");
            					printf("Informe novamente o ");
            				}	
            			}
    
                  /*printf("Sexo: (M)Masculino/(F)Feminino \n");
              		scanf("%c", &vetorProfessores[posvetor].sexo);*/
    
                  validadatadenascimentoprof = 0;
                  while(validadatadenascimentoprof == 0)
        			    {
            				printf("Dia do Nascimento: (dd) \n");
            				scanf("%d", &vetorProfessores[posvetorprof].dataNascimento.dia);
            				printf("Mês do Nascimento: (mm) \n");
            				scanf("%d", &vetorProfessores[posvetorprof].dataNascimento.mes);
            				printf("Ano do Nascimento: (aaaa) \n");
            				scanf("%d", &vetorProfessores[posvetorprof].dataNascimento.ano);
            				getchar();
            				
            				// SUGESTÃO DE MELHORIA: ANÁLISE DE ANO POR BISSEXTO. **SOMENTE DEPOIS QUE ESTIVERMOS VALIDADO O BÁSICO.
            				if((vetorProfessores[posvetorprof].dataNascimento.ano > 2021) || (vetorProfessores[posvetorprof].dataNascimento.ano <= 1930))
            				{	
            					printf("Ano de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n");
            					printf("Informe novamente os dados abaixo. \n");
            				}
            				else
            				{
            					if((vetorProfessores[posvetorprof].dataNascimento.mes <= 12) && (vetorProfessores[posvetorprof].dataNascimento.mes > 0))
            					{
            						if((vetorProfessores[posvetorprof].dataNascimento.mes == 1) || (vetorProfessores[posvetorprof].dataNascimento.mes == 3) || (vetorProfessores[posvetorprof].dataNascimento.mes == 5) || (vetorProfessores[posvetorprof].dataNascimento.mes == 7) || (vetorProfessores[posvetorprof].dataNascimento.mes == 8) || (vetorProfessores[posvetorprof].dataNascimento.mes == 10) || (vetorProfessores[posvetorprof].dataNascimento.mes == 12))
            						{
            							if((vetorProfessores[posvetorprof].dataNascimento.dia <= 0 || vetorProfessores[posvetorprof].dataNascimento.dia > 31))
            							{
            								printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 31 \n");
            								printf("Informe novamente os dados abaixo. \n");
            							}
            							else
            							{
            								validadatadenascimentoprof = 1;
            							}
            						}
            						else
            						{
            							if(vetorProfessores[posvetorprof].dataNascimento.mes == 2)
            							{
            								if((vetorProfessores[posvetorprof].dataNascimento.dia <= 0 || vetorProfessores[posvetorprof].dataNascimento.dia >= 29))
            								{
            								printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 28 para anos não bissextos e 29 para anos bissextos \n");
            								printf("Informe novamente os dados abaixo. \n");
            								}
            								else
            								{
            								validadatadenascimentoprof = 1;
            								}
            							}
            							else
            							{
            								if((vetorProfessores[posvetorprof].dataNascimento.dia <= 0 || vetorProfessores[posvetorprof].dataNascimento.dia >= 30))
            								{
            									printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 30 \n");
            									printf("Informe novamente os dados abaixo. \n");
            								}
            								else
            								{
            									validadatadenascimentoprof = 1;
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
                  validacpfprof = 0;
                  while(validacpfprof == 0)
            			{
            				printf("CPF: (Somente números) \n");
            				fflush(stdin);
            				fgets(vetorProfessores[posvetorprof].CPF, 15, stdin);
            					
            				ln = strlen(vetorProfessores[posvetorprof].CPF) - 1; //comando para retirar o \n gerado pelo fgets
            		    if (vetorProfessores[posvetorprof].CPF[ln] == '\n')
            				{
            		      vetorProfessores[posvetorprof].CPF[ln] = '\0';	
            				}			
                    
                    somaprof = strlen(vetorProfessores[posvetorprof].CPF);
                    
                    if(somaprof < 11)
                    {
                      printf("CPF com tamanho inválido. Deve ter 11 caracteres. \n");
              			  printf("Por favor, informe o ");
                    }
                    else
                    {
                      validacpfprof = 1;
                    }
                  } 
          			}            
              }    			
    			  }			   
    			}
    		}
    		if(opcaoprof == 4)
    		{
    		  if(listaprof == 0)
    			{
    				printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir professores no sistema. \n \n");
    			}
    			else
    			{
            posvetorprof = -1;
    			  while(posvetorprof == -1)
    			  {
        			printf("Informe a matrícula do Professor que deseja EXCLUIR. \n");
        			scanf("%d", &matriculaprof);
    
              if(matriculaprof <= 0) //Verificação de matrículas negativas.
              {
                printf("Matrícula informada não existe. \n");
          			printf("Por favor, ");
              }
              else
              {
                for(icontprof = 0; icontprof<qtdeprofessores; icontprof++)
          			{
            			if(vetorProfessores[icontprof].matricula == matriculaprof)
            			{
            				posvetorprof = icontprof;
            			}
          	  	}            
          			if(posvetorprof == -1)
          			{
          		    printf("Matrícula informada não existe. \n");
          		    printf("Por favor, ");
          			}
          			else
          			{
              		printf("--- PROFESSOR A SER EXCLUÍDO %d --- \n", matriculaprof);
              		printf("Nome: %s \n", vetorProfessores[posvetorprof].nome);
            			printf("Sexo: %c \n", vetorProfessores[posvetorprof].sexo);
          				printf("Data Nascimento: %d/%d/%d \n", vetorProfessores[posvetorprof].dataNascimento.dia, vetorProfessores[posvetorprof].dataNascimento.mes, vetorProfessores[posvetorprof].dataNascimento.ano);
           				printf("CPF: %s \n", vetorProfessores[posvetorprof].CPF);
              		printf("________________________________________________ \n");
              				
              		printf("Excluindo dados... \n");
              									
            			vetorProfessores[posvetorprof].matricula = 0;		
          				strcpy(vetorProfessores[posvetorprof].nome, "Professor excluído.");
              		vetorProfessores[posvetorprof].sexo = '0';
              		vetorProfessores[posvetorprof].dataNascimento.dia = 0;
            			vetorProfessores[posvetorprof].dataNascimento.mes = 0;
          				vetorProfessores[posvetorprof].dataNascimento.ano = 0;
          				strcpy(vetorProfessores[posvetorprof].CPF, "0");									
              							
          				printf("Professor excluído. \n \n");	  
          			}  
              }  				
      			}        
          }				
    		}
    		if(opcaoprof >= 5)
    		{
    			printf("Opção inválida. \n \n");
    		}    
      }  
    }
    if(opcaomenugeral == 3)
    {
      finalizardisc = 0;
      while(finalizardisc == 0)
      {
      	printf("--- Gestão de Disciplinas --- \n");
  	    printf("0 - Sair \n");
  	    printf("1 - Incluir Disciplinas \n");
  	    printf("2 - Listar Disciplinas \n");
  	    printf("3 - Atualizar Disciplinas \n");
  	    printf("4 - Excluir Disciplinas \n");
  	    printf("Informe o que deseja fazer: \n");
  	    scanf("%d", &opcaodisc);
  	    //printf("\n");
  	    
  		  if(opcaodisc == 0)
  	    {
  	    finalizardisc = 1;
  			printf("Finalizando Gestão de Disciplinas. \n");    	
  		  }
  		  if(opcaodisc == 1)
  		  {
  		    if(contdisciplinadisc >= qtdedisciplina)
  		    {
  		        printf("Não há mais vagas para inclusão. \n");
  		    }
  		    else
  		    {
  		      printf("-- INCLUSÃO DE DISCIPLINAS --\n");
  			//Inserir condição de contaluno < qtdealunos, printar que não há mais vagas.
  			//while(validacadastro == 0)
  			//{
      			ndisciplinadisc = contdisciplinadisc + 1;
      			printf("- DADOS DA DISCIPLINA %d - \n", ndisciplinadisc);				
      			while(validacodigodisc == 0)
      			{
      				printf("Código da Disciplina \n");
      				scanf("%d", &vetorDisciplinas[contdisciplinadisc].codigo);
      				getchar();
      				if(contdisciplinadisc > 0) // condição para evitar repetição de código.
              {
                for(kcontdisc = 0; kcontdisc < contdisciplinadisc; kcontdisc++)
                {
                  if (vetorDisciplinas[kcontdisc].codigo == vetorDisciplinas[contdisciplinadisc].codigo)               
                  {  
                    vetorDisciplinas[contdisciplinadisc].codigo = 0;  
                  }                  
                }
              }      	
      				if(vetorDisciplinas[contdisciplinadisc].codigo <= 0)
      				{
      					printf("Código inválido. Este dado deve ser um número inteiro e positivo.  \n");
      					printf("Informe novamente o ");	
      				}
      				else
      				{
      					validacodigodisc= 1;
      				}
      			}		
      			validacodigodisc = 0;
      					
      			printf("Nome da Disciplina (até 50 caracteres): \n");
      			fflush(stdin);
      			fgets(vetorDisciplinas[contdisciplinadisc].nome, 51, stdin);
      				
      			size_t ln = strlen(vetorDisciplinas[contdisciplinadisc].nome) - 1; //comando para retirar o \n gerado pelo fgets
      	    if (vetorDisciplinas[contdisciplinadisc].nome[ln] == '\n')
      	    {
      	      vetorDisciplinas[contdisciplinadisc].nome[ln] = '\0';	
      			}
      			validasemestredisc = 0;
      			while(validasemestredisc == 0)
      			{
      				printf("Informe o semestre da Disciplina \n");
      				scanf("%d", &vetorDisciplinas[contdisciplinadisc].semestre);
      				getchar();
      				
      				if((vetorDisciplinas[contdisciplinadisc].semestre >= 1))
      				{
      						validasemestredisc = 1;								
      				}				
      				else
      				{						
      					validasemestredisc = 0;	
      					printf("Semestre inválido. O número de semestre deve ser maior que 1. \n");
      					printf("Informe novamente o ");
      				}	
      			}
      			validaprofessordisc = 0;   				       				
      			while(validaprofessordisc == 0)
      			{
              if(contprofessor == 0)
              {
                printf("Nenhum professor foi cadastro. Por favor, retorne ao campo de Gestão de Professor e realize a inclusão. \n");   
                validaprofessordisc = 2;
              }
              else
              {
                printf("Professores disponíveis: \n");
                for(icontprof = 0; icontprof<contprofessor; icontprof++)
                {
                printf("%s", vetorProfessores[icontprof].nome);                      
                }           
                printf("\n Informe o nome de algum Professor disponível para esta matéria. \n");
                fflush(stdin);    
                fgets(vetorDisciplinas[contdisciplinadisc].professor, 51, stdin);
          				
        			  size_t ln = strlen(vetorDisciplinas[contdisciplinadisc].professor) - 1; //comando para retirar o \n gerado pelo fgets
            	  if (vetorDisciplinas[contdisciplinadisc].professor[ln] == '\n')
                {
                  vetorDisciplinas[contdisciplinadisc].professor[ln] = '\0';	
        			  }
                  
                nomesiguaisdisc = 3;
                for(kcontdisc=0; kcontdisc < qtdeprofessores && nomesiguaisdisc != 0 ; kcontdisc++)
                {
                  nomesiguaisdisc = strcmp(vetorDisciplinas[contdisciplinadisc].professor, vetorProfessores[kcontdisc].nome);
                }      
                if(nomesiguaisdisc == 0)
                {
                  validaprofessordisc = 1;  
                }
                else
                {
                 printf("Nome de Professor não encontrado no Banco de Dados de Professores. \n");
                 printf("Por favor,  ");
                }
              }
            }
            if(validaprofessordisc == 2)
            {
              listadisc = 0;            
            }
            else
            {
              if(validaprofessordisc == 0)
              {
              listadisc = 0;
              }
              else
              {
              contdisciplinadisc++;
    			    listadisc = 1;  
              }
            }  		   
  		    }
  		  finalizardisc = 0; 
  		  }
  		  if (opcaodisc == 2)
  		  {
    			if(listadisc == 0)
    			{
    				printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir uma disciplina no sistema. \n \n");
    				finalizardisc = 0;
    			}
    			else
    			{        
    				printf("\n--- LISTA DE DISCIPLINAS --- \n \n");
    	      for (icontdisc = 0; icontdisc < contdisciplinadisc; icontdisc++) //imprime a quantidade de alunos que foram incluídos.              
    				{
    			    printf("Nome: %s \n", vetorDisciplinas[icontdisc].nome);
    			    printf("Código: %d \n", vetorDisciplinas[icontdisc].codigo);
    			    printf("Semestre: %d \n", vetorDisciplinas[icontdisc].semestre);
    			    printf("Professor: %s \n \n", vetorDisciplinas[icontdisc].professor);
    			  }		
    			 printf("________________________________________________ \n");
    	    }		
  		  }
  		  if(opcaodisc == 3)
  		  {
  			  if(listadisc == 0)
  			  {
  				  printf("\n A lista está vazia. \n");
  				  printf("Primeiramente, você deve inserir/incluir de disciplina no sistema. \n \n");
  			  }
  			  else
  			  {
            posvetordisc = -1;
    			  while(posvetordisc == -1)
  			    {
        			printf("Informe o código da Matrícula que deseja atualizar. \n");
        			scanf("%d", &codigodisc);
        			getchar();
    
              if(codigodisc <= 0) //Verificação de matrículas negativas.
              {
                printf("Código informado não existe. \n");
          			printf("Por favor, ");
              }
              else
              {
                for(icontdisc = 0; icontdisc<qtdedisciplina; icontdisc++)
        			  {
        				  if(vetorDisciplinas[icontdisc].codigo == codigodisc)
        				  {
        					posvetordisc = icontdisc;
        				  }
        			  }      	          
          			if(posvetordisc == -1)
          			{
          			  printf("Código informado não existe. \n");
          			  printf("Por favor, ");
          			}
          			else
          			{
            			printf("--- DADOS DA MATRÍCULA DE CÓDIGO: %d --- \n", codigodisc);
            			printf("Nome: %s \n", vetorDisciplinas[posvetordisc].nome);
    			        printf("Código: %d \n", vetorDisciplinas[posvetordisc].codigo);
    			        printf("Semestre: %d \n", vetorDisciplinas[posvetordisc].semestre);
    			        printf("Professor: %s \n \n", vetorDisciplinas[posvetordisc].professor);
              		printf("________________________________________________ \n");
              			
              		printf("--- ATUALIZAÇÃO DE DADOS DA MATRÍCULA --- \n");
                  validacodigodisc = 0;
              		while(validacodigodisc == 0)
        			    {
          				  printf("Código da Disciplina \n");
          				  scanf("%d", &vetorDisciplinas[posvetordisc].codigo);
          				  getchar();
          				  if(posvetordisc> 0) // condição para evitar repetição de código.
                    {
                      for(kcontdisc = 0; kcontdisc < posvetordisc; kcontdisc++)
                    {
                    if (vetorDisciplinas[kcontdisc].codigo == vetorDisciplinas[posvetordisc].codigo)
                      {
                        vetorDisciplinas[posvetordisc].codigo = 0;  
                      }                  
                    }
                  }      	
        				  if(vetorDisciplinas[posvetordisc].codigo <= 0)
          				{
          					printf("Código inválido. Este dado deve ser um número inteiro e positivo.  \n");
          					printf("Informe novamente o ");	
          				}
          				else
          				{
          					validacodigodisc = 1;
          				}
      			    }	            
      			    validacodigodisc = 0;    					
      			    printf("Nome da Disciplina (até 50 caracteres): \n");
      			    fflush(stdin);
      			    fgets(vetorDisciplinas[posvetordisc].nome, 51, stdin);
      					size_t ln = strlen(vetorDisciplinas[posvetordisc].nome) - 1; //comando para retirar o \n gerado pelo fgets
          	    if (vetorDisciplinas[posvetordisc].nome[ln] == '\n')
          	    {
          	      vetorDisciplinas[posvetordisc].nome[ln] = '\0';	
          			}
      			    validasemestredisc = 0;
      			    while(validasemestredisc == 0)
      			    {
        				  printf("Informe o semestre da Disciplina \n");
        				  scanf("%d", &vetorDisciplinas[posvetordisc].semestre);
        				  getchar();
        				
          				if((vetorDisciplinas[posvetordisc].semestre >= 1))
          				{
          						validasemestredisc = 1;								
          				}				
          				else
          				{						
          					validasemestredisc = 0;	
          					printf("Semestre inválido. O número de semestre deve ser maior que 1. \n");
          					printf("Informe novamente o ");
          				}	
        			  }    			   	
                validaprofessordisc = 0;
      			    while(validaprofessordisc == 0)
      			    {
                  if(contprofessor == 0)
                  {
                    printf("Nenhum professor foi cadastro. Por favor, retorne ao campo de Gestão de Professor e realize a inclusão. \n");   
                    validaprofessordisc = 1;
                  }
                  else
                  {
                    printf("Professores disponíveis: \n");
                    for(icontprof = 0; icontprof<contprofessor; icontprof++)
                    {
                    printf("%s \n", vetorProfessores[icontprof].nome);                      
                    }                    
                    printf("Informe o nome de algum Professor disponível para esta matéria. \n");
                    fflush(stdin);                 
          
                    fgets(vetorDisciplinas[posvetordisc].professor, 51, stdin);
            				
            			  size_t ln = strlen(vetorDisciplinas[posvetordisc].professor) - 1; //comando para retirar o \n gerado pelo fgets
            	      if (vetorDisciplinas[posvetordisc].professor[ln] == '\n')
            	      {            	        vetorDisciplinas[posvetordisc].professor[ln] = '\0';	
            			  }                  
                    nomesiguaisdisc = 3;
                    for(kcontdisc=0; kcontdisc < qtdeprofessores && nomesiguaisdisc != 0 ; kcontdisc++)
                    {
                      nomesiguaisdisc = strcmp(vetorDisciplinas[posvetordisc].professor, vetorProfessores[kcontdisc].nome);
                    }      
                    if(nomesiguaisdisc == 0)
                    {
                      validaprofessordisc = 1;  
                    }
                    else
                    {
                      printf("Nome de Professor não encontrado no Banco de Dados de Professores. \n");
                      printf("Por favor,  ");                               
                    }                    
                  }
                }
              }
            }
          }
        }
      }
    		if(opcaodisc == 4)
    		{
    		  if(listadisc == 0)
    			{
    				printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir disciplinas no sistema. \n \n");
    			}
    			else
    			{
            posvetordisc = -1;
    			  while(posvetordisc == -1)
    			  {
        			printf("Informe o código da Disciplina que deseja EXCLUIR. \n");
        			scanf("%d", &codigodisc);
    
              if(codigodisc <= 0) //Verificação de matrículas negativas.
              {
                printf("Código informado não existe. \n");
          			printf("Por favor, ");
              }
              else
              {
                for(icontdisc = 0; icontdisc<qtdedisciplina; icontdisc++)
          			{
            			if(vetorDisciplinas[icontdisc].codigo == codigodisc)
            			{
            				posvetordisc= icontdisc;
            			}
          	  	}            
          			if(posvetordisc == -1)
          			{
          		    printf("Código informado não existe. \n");
          		    printf("Por favor, ");
          			}
          			else
          			{
              		printf("--- DISCIPLINA A SER EXCLUÍDA %d --- \n", codigodisc);
              		printf("Nome: %s \n", vetorDisciplinas[posvetordisc].nome);
    			        printf("Código: %d \n", vetorDisciplinas[posvetordisc].codigo);
    			        printf("Semestre: %d \n", vetorDisciplinas[posvetordisc].semestre);
    			        printf("Professor: %s \n \n", vetorDisciplinas[posvetordisc].professor);
              		printf("________________________________________________ \n");
              				
              		printf("Excluindo dados... \n");
              									
            			vetorDisciplinas[posvetordisc].codigo = 0;		
          				strcpy(vetorDisciplinas[posvetordisc].nome, "Disciplina excluída.");
              		vetorDisciplinas[posvetordisc].semestre = 0;          		
          				strcpy(vetorDisciplinas[posvetordisc].professor, "0");	       							
          				printf("Disciplina excluído. \n \n");	  
          			}  
              }  				
          	}        
          }				
    		}
        if(opcaodisc >= 5)
        {
      		printf("Opção inválida. \n \n");
      	}    
      }  
    }     
    if(opcaomenugeral == 4) // Matrícula de Aluno
    {    
      	 
    
    
    
      
    }
    if(opcaomenugeral == 5) // Relatórios
    {
      finalizarrel = 0;
      while(finalizarrel== 0)
      {
      	printf("--- Relatórios --- \n");
  	    printf("0 - Sair \n");
        printf("1 - Listar Alunos \n");
    	  printf("2 - Listar Professores \n");
    	  printf("3 - Listar Disciplinas  \n");
        printf("4 - Listar uma disciplina e os alunos matriculados. \n");
        printf("5 - Listar alunos por sexo. (Masculino/Feminino) \n");
        printf("6 - Listar alunos ordenados por nome. \n");
        printf("7 - Listar alunos por data de nascimento. \n");
        printf("8 - Listar professores por sexo (Masculino/Feminino) \n");
        printf("9 - Listar professores ordenados por nome. \n");
        printf("10 - Listar professores por data de nascimento. \n");
        printf("11 - Aniversariante do mês \n");
        printf("12 - Busca Professores e Alunos. \n");
        printf("13 - Lista de alunos matriculados em 3 disciplinas\n");
        printf("14 - Lista de disciplina com mais de 40 vagas (Contendo nome do professor) \n");       
        printf("Informe o que deseja fazer: \n");
  	    scanf("%d", &opcaorel);
        getchar();
        if(opcaorel == 0)
        {
          finalizarrel = 1;
          printf("Finalizando Menu relatórios. \n");  
        }
        if(opcaorel == 1)
        {
          if(contaluno == 0)
          {
            printf("\n A lista está vazia. \n");
    				printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
    				finalizaraluno = 0;
    			}
    			else
    			{        
    				printf("\n--- LISTA DE ALUNOS --- \n \n");
    	      for (icontaluno = 0; icontaluno < contaluno; icontaluno++) //imprime a quantidade de alunos que foram incluídos.              
    				{
    			    printf("Matrícula: %d \n", vetorAlunos[icontaluno].matricula);
    			    printf("Nome: %s \n", vetorAlunos[icontaluno].nome);
    			    printf("Sexo: %c \n", vetorAlunos[icontaluno].sexo);
    			    printf("Data Nascimento: %d/%d/%d \n", vetorAlunos[icontaluno].dataNascimento.dia, vetorAlunos[icontaluno].dataNascimento.mes, vetorAlunos[icontaluno].dataNascimento.ano);
    			    printf("CPF: %s \n \n", vetorAlunos[icontaluno].CPF);
    			  }	    			  
          }
          printf("________________________________________________ \n");
        }
        if(opcaorel == 2)
        {
          if(contprofessor == 0)
      		{
      			printf("\n A lista está vazia. \n");
      			printf("Primeiramente, você deve inserir/incluir professores no sistema. \n \n");
      			finalizarprof = 0;
      		}
      		else
      		{              
      			printf("\n--- LISTA DE PROFESSORES --- \n \n");
      	    for (icontprof = 0; icontprof < contprofessor; icontprof++) //imprime a quantidade de alunos que foram incluídos.              
      			{
      			  printf("Matrícula: %d \n", vetorProfessores[icontprof].matricula);
      			  printf("Nome: %s \n", vetorProfessores[icontprof].nome);
      			  printf("Sexo: %c \n", vetorProfessores[icontprof].sexo);
      		    printf("Data Nascimento: %d/%d/%d \n", vetorProfessores[icontprof].dataNascimento.dia, vetorProfessores[icontprof].dataNascimento.mes, vetorProfessores[icontprof].dataNascimento.ano);
      			  printf("CPF: %s \n \n", vetorProfessores[icontprof].CPF);
      			}		
      		  printf("________________________________________________ \n");
      	  }	  
        }
        if(opcaorel == 3)
        {
          if(contdisciplinadisc == 0)
      		{
      			printf("\n A lista está vazia. \n");
      			printf("Primeiramente, você deve inserir/incluir uma disciplina no sistema. \n \n");
    				finalizardisc = 0;
    			}
    			else
      		{        
      			printf("\n--- LISTA DE DISCIPLINAS --- \n \n");
    	      for (icontdisc = 0; icontdisc < contdisciplinadisc; icontdisc++) //imprime a quantidade de alunos que foram incluídos.              
    				{
      		    printf("Nome: %s \n", vetorDisciplinas[icontdisc].nome);
      		    printf("Código: %d \n", vetorDisciplinas[icontdisc].codigo);
      		    printf("Semestre: %d \n", vetorDisciplinas[icontdisc].semestre);
    			    printf("Professor: %s \n \n", vetorDisciplinas[icontdisc].professor);
    			  }		
    			 printf("________________________________________________ \n");
      	  }  
        }
        if(opcaorel == 4)
        {
          //PENDENTE ELABORAR MATRIZ.
        }
        if(opcaorel == 5) //ESTÁ OK
        {
          if(contaluno == 0)
      		{
      			printf("\n A lista de Alunos está vazia. \n");
      			printf("Primeiramente, você deve inserir/incluir um aluno no sistema. \n \n");
    				finalizarrel = 1;
    			}
          else
          {
            for (icontaluno = 0; icontaluno<contaluno; icontaluno++) 
              {
                for(jcontaluno = icontaluno; jcontaluno < contaluno; jcontaluno++)            
                {
                  if(vetorAlunos[icontaluno].sexo > vetorAlunos[jcontaluno].sexo)
                  {
                    vetorAuxAlunosProfessores.matricula = vetorAlunos[icontaluno].matricula;
                    strcpy(vetorAuxAlunosProfessores.nome, vetorAlunos[icontaluno].nome);
                    vetorAuxAlunosProfessores.sexo = vetorAlunos[icontaluno].sexo;
                    vetorAuxAlunosProfessores.dataNascimento.dia = vetorAlunos[icontaluno].dataNascimento.dia;
                    vetorAuxAlunosProfessores.dataNascimento.mes = vetorAlunos[icontaluno].dataNascimento.mes;
                    vetorAuxAlunosProfessores.dataNascimento.ano = vetorAlunos[icontaluno].dataNascimento.ano;
                    strcpy(vetorAuxAlunosProfessores.CPF, vetorAlunos[icontaluno].CPF);
                            
                    vetorAlunos[icontaluno].matricula = vetorAlunos[jcontaluno].matricula;
                    strcpy(vetorAlunos[icontaluno].nome, vetorAlunos[jcontaluno].nome);
                    vetorAlunos[icontaluno].sexo = vetorAlunos[jcontaluno].sexo;
                    vetorAuxAlunosProfessores.dataNascimento.dia = vetorAlunos[icontaluno].dataNascimento.dia;
                    vetorAuxAlunosProfessores.dataNascimento.mes = vetorAlunos[icontaluno].dataNascimento.mes;
                    vetorAuxAlunosProfessores.dataNascimento.ano = vetorAlunos[icontaluno].dataNascimento.ano;
                    strcpy(vetorAuxAlunosProfessores.CPF, vetorAlunos[icontaluno].CPF);
        
                    vetorAlunos[jcontaluno].matricula = vetorAuxAlunosProfessores.matricula;
                    strcpy(vetorAlunos[jcontaluno].nome, vetorAuxAlunosProfessores.nome);
                    vetorAlunos[jcontaluno].sexo = vetorAuxAlunosProfessores.sexo;
                    vetorAuxAlunosProfessores.dataNascimento.dia = vetorAlunos[icontaluno].dataNascimento.dia;
                    vetorAuxAlunosProfessores.dataNascimento.mes = vetorAlunos[icontaluno].dataNascimento.mes;
                    vetorAuxAlunosProfessores.dataNascimento.ano = vetorAlunos[icontaluno].dataNascimento.ano;
                    strcpy(vetorAuxAlunosProfessores.CPF, vetorAlunos[icontaluno].CPF);
                  }                
                }
              }            
            printf("\n--- LISTA DE ALUNOS ORDENADOS POR SEXO--- \n \n");
            for(icontaluno = 0; icontaluno < contaluno; icontaluno++)
            {       
              printf("Sexo: %c \n", vetorAlunos[icontaluno].sexo);
            	printf("Matrícula: %d \n", vetorAlunos[icontaluno].matricula);
            	printf("Nome: %s \n", vetorAlunos[icontaluno].nome);        		 
            }          
          }        
          printf(" \n________________________________________________ \n");
        }
        if(opcaorel == 6) // ESTÁ OK!
        {
          if(contaluno == 0)
      		{
      			printf("\n A lista de Alunos está vazia. \n");
      			printf("Primeiramente, você deve inserir/incluir um aluno no sistema. \n \n");
    				finalizarrel = 1;
    			}
          else
          {
            for (icontaluno = 0; icontaluno<contaluno; icontaluno++) 
              {
                for(jcontaluno = icontaluno+1; jcontaluno < contaluno; jcontaluno++)            
                {
                  if (strcmp(vetorAlunos[icontaluno].nome,vetorAlunos[jcontaluno].nome) > 0)
                  {
                    vetorAuxAlunosProfessores.matricula = vetorAlunos[icontaluno].matricula;
                    strcpy(vetorAuxAlunosProfessores.nome, vetorAlunos[icontaluno].nome);
                    vetorAuxAlunosProfessores.sexo = vetorAlunos[icontaluno].sexo;
                    vetorAuxAlunosProfessores.dataNascimento.dia = vetorAlunos[icontaluno].dataNascimento.dia;
                    vetorAuxAlunosProfessores.dataNascimento.mes = vetorAlunos[icontaluno].dataNascimento.mes;
                    vetorAuxAlunosProfessores.dataNascimento.ano = vetorAlunos[icontaluno].dataNascimento.ano;
                    strcpy(vetorAuxAlunosProfessores.CPF, vetorAlunos[icontaluno].CPF);           
                  
                    vetorAlunos[icontaluno].matricula = vetorAlunos[jcontaluno].matricula;
                    strcpy(vetorAlunos[icontaluno].nome, vetorAlunos[jcontaluno].nome);
                    vetorAlunos[icontaluno].sexo = vetorAlunos[jcontaluno].sexo;
                    vetorAlunos[icontaluno].dataNascimento.dia = vetorAlunos[jcontaluno].dataNascimento.dia;
                    vetorAlunos[icontaluno].dataNascimento.mes = vetorAlunos[jcontaluno].dataNascimento.mes;
                    vetorAlunos[icontaluno].dataNascimento.ano = vetorAlunos[jcontaluno].dataNascimento.ano;
                    strcpy(vetorAlunos[icontaluno].CPF, vetorAlunos[jcontaluno].CPF);
        
                      vetorAlunos[jcontaluno].matricula = vetorAuxAlunosProfessores.matricula;
                      strcpy(vetorAlunos[jcontaluno].nome, vetorAuxAlunosProfessores.nome);
                      vetorAlunos[jcontaluno].sexo = vetorAuxAlunosProfessores.sexo;
                      vetorAlunos[jcontaluno].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                      vetorAlunos[jcontaluno].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                      vetorAlunos[jcontaluno].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                      strcpy(vetorAlunos[jcontaluno].CPF, vetorAuxAlunosProfessores.CPF);
                  }
                }
              }            
            printf("\n--- LISTA DE ALUNOS ORDENADOS POR NOME --- \n \n");
            for(icontaluno = 0; icontaluno < contaluno; icontaluno++)
            {             
            	printf("Nome: %s \n", vetorAlunos[icontaluno].nome);
              printf("Matrícula: %d \n", vetorAlunos[icontaluno].matricula);
            }
          } 
          printf(" \n________________________________________________ \n");
        }
        if(opcaorel == 7)//ESTÁ OK
        {
          for (icontaluno = 0; icontaluno<contaluno; icontaluno++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O ANO.
          {
            for(jcontaluno = icontaluno; jcontaluno < contaluno; jcontaluno++)            
            {
              if (vetorAlunos[icontaluno].dataNascimento.ano > vetorAlunos[jcontaluno].dataNascimento.ano)
                {
                  vetorAuxAlunosProfessores.matricula = vetorAlunos[icontaluno].matricula;
                  strcpy(vetorAuxAlunosProfessores.nome, vetorAlunos[icontaluno].nome);
                  vetorAuxAlunosProfessores.sexo = vetorAlunos[icontaluno].sexo;
                  vetorAuxAlunosProfessores.dataNascimento.dia = vetorAlunos[icontaluno].dataNascimento.dia;
                  vetorAuxAlunosProfessores.dataNascimento.mes = vetorAlunos[icontaluno].dataNascimento.mes;
                  vetorAuxAlunosProfessores.dataNascimento.ano = vetorAlunos[icontaluno].dataNascimento.ano;
                  strcpy(vetorAuxAlunosProfessores.CPF, vetorAlunos[icontaluno].CPF);           
                  
                  vetorAlunos[icontaluno].matricula = vetorAlunos[jcontaluno].matricula;
                  strcpy(vetorAlunos[icontaluno].nome, vetorAlunos[jcontaluno].nome);
                  vetorAlunos[icontaluno].sexo = vetorAlunos[jcontaluno].sexo;
                  vetorAlunos[icontaluno].dataNascimento.dia = vetorAlunos[jcontaluno].dataNascimento.dia;
                  vetorAlunos[icontaluno].dataNascimento.mes = vetorAlunos[jcontaluno].dataNascimento.mes;
                  vetorAlunos[icontaluno].dataNascimento.ano = vetorAlunos[jcontaluno].dataNascimento.ano;
                  strcpy(vetorAlunos[icontaluno].CPF, vetorAlunos[jcontaluno].CPF);
        
                  vetorAlunos[jcontaluno].matricula = vetorAuxAlunosProfessores.matricula;
                  strcpy(vetorAlunos[jcontaluno].nome, vetorAuxAlunosProfessores.nome);
                  vetorAlunos[jcontaluno].sexo = vetorAuxAlunosProfessores.sexo;
                  vetorAlunos[jcontaluno].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                  vetorAlunos[jcontaluno].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                  vetorAlunos[jcontaluno].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                  strcpy(vetorAlunos[jcontaluno].CPF, vetorAuxAlunosProfessores.CPF);                    
                }
            }
          }

          for (icontaluno = 0; icontaluno<contaluno; icontaluno++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM o MÊS
          {
            for(jcontaluno = icontaluno; jcontaluno < contaluno; jcontaluno++)            
            {
              if ((vetorAlunos[icontaluno].dataNascimento.mes > vetorAlunos[jcontaluno].dataNascimento.mes) && (vetorAlunos[icontaluno].dataNascimento.ano == vetorAlunos[jcontaluno].dataNascimento.ano))
                {
                  vetorAuxAlunosProfessores.matricula = vetorAlunos[icontaluno].matricula;
                  strcpy(vetorAuxAlunosProfessores.nome, vetorAlunos[icontaluno].nome);
                  vetorAuxAlunosProfessores.sexo = vetorAlunos[icontaluno].sexo;
                  vetorAuxAlunosProfessores.dataNascimento.dia = vetorAlunos[icontaluno].dataNascimento.dia;
                  vetorAuxAlunosProfessores.dataNascimento.mes = vetorAlunos[icontaluno].dataNascimento.mes;
                  vetorAuxAlunosProfessores.dataNascimento.ano = vetorAlunos[icontaluno].dataNascimento.ano;
                  strcpy(vetorAuxAlunosProfessores.CPF, vetorAlunos[icontaluno].CPF);           
                  
                  vetorAlunos[icontaluno].matricula = vetorAlunos[jcontaluno].matricula;
                  strcpy(vetorAlunos[icontaluno].nome, vetorAlunos[jcontaluno].nome);
                  vetorAlunos[icontaluno].sexo = vetorAlunos[jcontaluno].sexo;
                  vetorAlunos[icontaluno].dataNascimento.dia = vetorAlunos[jcontaluno].dataNascimento.dia;
                  vetorAlunos[icontaluno].dataNascimento.mes = vetorAlunos[jcontaluno].dataNascimento.mes;
                  vetorAlunos[icontaluno].dataNascimento.ano = vetorAlunos[jcontaluno].dataNascimento.ano;
                  strcpy(vetorAlunos[icontaluno].CPF, vetorAlunos[jcontaluno].CPF);
        
                  vetorAlunos[jcontaluno].matricula = vetorAuxAlunosProfessores.matricula;
                  strcpy(vetorAlunos[jcontaluno].nome, vetorAuxAlunosProfessores.nome);
                  vetorAlunos[jcontaluno].sexo = vetorAuxAlunosProfessores.sexo;
                  vetorAlunos[jcontaluno].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                  vetorAlunos[jcontaluno].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                  vetorAlunos[jcontaluno].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                  strcpy(vetorAlunos[jcontaluno].CPF, vetorAuxAlunosProfessores.CPF);                    
                }
            }
          }

          for (icontaluno = 0; icontaluno<contaluno; icontaluno++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O DIA
          {
            for(jcontaluno = icontaluno; jcontaluno < contaluno; jcontaluno++)            
            {
              if ((vetorAlunos[icontaluno].dataNascimento.dia > vetorAlunos[jcontaluno].dataNascimento.dia) && (vetorAlunos[icontaluno].dataNascimento.mes == vetorAlunos[jcontaluno].dataNascimento.mes) && (vetorAlunos[icontaluno].dataNascimento.dia == vetorAlunos[jcontaluno].dataNascimento.dia))
                {
                  vetorAuxAlunosProfessores.matricula = vetorAlunos[icontaluno].matricula;
                  strcpy(vetorAuxAlunosProfessores.nome, vetorAlunos[icontaluno].nome);
                  vetorAuxAlunosProfessores.sexo = vetorAlunos[icontaluno].sexo;
                  vetorAuxAlunosProfessores.dataNascimento.dia = vetorAlunos[icontaluno].dataNascimento.dia;
                  vetorAuxAlunosProfessores.dataNascimento.mes = vetorAlunos[icontaluno].dataNascimento.mes;
                  vetorAuxAlunosProfessores.dataNascimento.ano = vetorAlunos[icontaluno].dataNascimento.ano;
                  strcpy(vetorAuxAlunosProfessores.CPF, vetorAlunos[icontaluno].CPF);           
                  
                  vetorAlunos[icontaluno].matricula = vetorAlunos[jcontaluno].matricula;
                  strcpy(vetorAlunos[icontaluno].nome, vetorAlunos[jcontaluno].nome);
                  vetorAlunos[icontaluno].sexo = vetorAlunos[jcontaluno].sexo;
                  vetorAlunos[icontaluno].dataNascimento.dia = vetorAlunos[jcontaluno].dataNascimento.dia;
                  vetorAlunos[icontaluno].dataNascimento.mes = vetorAlunos[jcontaluno].dataNascimento.mes;
                  vetorAlunos[icontaluno].dataNascimento.ano = vetorAlunos[jcontaluno].dataNascimento.ano;
                  strcpy(vetorAlunos[icontaluno].CPF, vetorAlunos[jcontaluno].CPF);
        
                  vetorAlunos[jcontaluno].matricula = vetorAuxAlunosProfessores.matricula;
                  strcpy(vetorAlunos[jcontaluno].nome, vetorAuxAlunosProfessores.nome);
                  vetorAlunos[jcontaluno].sexo = vetorAuxAlunosProfessores.sexo;
                  vetorAlunos[jcontaluno].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                  vetorAlunos[jcontaluno].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                  vetorAlunos[jcontaluno].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                  strcpy(vetorAlunos[jcontaluno].CPF, vetorAuxAlunosProfessores.CPF);                    
                }
            }
          }
          printf("\n--- LISTA DE ALUNOS ORDENADOS POR DATA DE NASCIMENTO --- \n \n");
          for(icontaluno = 0; icontaluno < contaluno; icontaluno++)
          {             
            printf("Nome: %s \n", vetorAlunos[icontaluno].nome);
            printf("Data de Nascimento: %d/%d/%d \n", vetorAlunos[icontaluno].dataNascimento.dia, vetorAlunos[icontaluno].dataNascimento.mes, vetorAlunos[icontaluno].dataNascimento.ano);
          }
        printf("____________________________________________________ \n");
        }   
        
        if(opcaorel == 8) //ESTÁ OK
        {
          if(contprofessor == 0)
      		{
      			printf("\n A lista de Professores está vazia. \n");
      			printf("Primeiramente, você deve inserir/incluir um professor no sistema. \n \n");
    				finalizarrel = 1;
    			}
          else
          {
            for (icontprof = 0; icontprof<contprofessor; icontprof++) 
              {
                for(jcontprof = icontprof; jcontprof < contprofessor; jcontprof++)            
                {
                  if(vetorProfessores[icontprof].sexo > vetorProfessores[jcontprof].sexo)
                  {
                    vetorAuxAlunosProfessores.matricula = vetorProfessores[icontprof].matricula;
                    strcpy(vetorAuxAlunosProfessores.nome, vetorProfessores[icontprof].nome);
                    vetorAuxAlunosProfessores.sexo = vetorProfessores[icontprof].sexo;
                    vetorAuxAlunosProfessores.dataNascimento.dia = vetorProfessores[icontprof].dataNascimento.dia;
                    vetorAuxAlunosProfessores.dataNascimento.mes = vetorProfessores[icontprof].dataNascimento.mes;
                    vetorAuxAlunosProfessores.dataNascimento.ano = vetorProfessores[icontprof].dataNascimento.ano;
                    strcpy(vetorAuxAlunosProfessores.CPF, vetorProfessores[icontprof].CPF);
                            
                    vetorProfessores[icontprof].matricula = vetorProfessores[jcontprof].matricula;
                    strcpy(vetorProfessores[icontprof].nome, vetorProfessores[jcontprof].nome);
                    vetorProfessores[icontprof].sexo = vetorProfessores[jcontprof].sexo;
                    vetorProfessores[icontprof].dataNascimento.dia = vetorProfessores[jcontprof].dataNascimento.dia;
                    vetorProfessores[icontprof].dataNascimento.mes = vetorProfessores[jcontprof].dataNascimento.mes;
                    vetorProfessores[icontprof].dataNascimento.ano = vetorProfessores[jcontprof].dataNascimento.ano;
                    strcpy(vetorProfessores[icontprof].CPF, vetorProfessores[jcontprof].CPF);
        
                    vetorProfessores[jcontprof].matricula = vetorAuxAlunosProfessores.matricula;
                    strcpy(vetorProfessores[jcontprof].nome, vetorAuxAlunosProfessores.nome);
                    vetorProfessores[jcontprof].sexo = vetorAuxAlunosProfessores.sexo;
                    vetorProfessores[jcontprof].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                    vetorProfessores[jcontprof].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                    vetorProfessores[jcontprof].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                    strcpy(vetorProfessores[jcontprof].CPF, vetorAuxAlunosProfessores.CPF);
                  }                
                }
              }            
            printf("\n--- LISTA DE PROFESSORES ORDENADOS POR SEXO--- \n \n");
            for(icontprof = 0; icontprof  < contprofessor; icontprof ++)
            {       
              printf("Sexo: %c \n", vetorProfessores[icontprof].sexo);
            	printf("Matrícula: %d \n", vetorProfessores[icontprof].matricula);
            	printf("Nome: %s \n", vetorProfessores[icontprof].nome); 		 
            }          
          }
        printf(" \n________________________________________________ \n"); 
        } 
        
        if(opcaorel == 9) // ESTÁ OK!
        {
          if(contprofessor == 0)
      		{
      			printf("\n A lista de Professores está vazia. \n");
      			printf("Primeiramente, você deve inserir/incluir um professor no sistema. \n \n");
    				finalizarrel = 1;
    			}
          else
          {
            for (icontprof = 0; icontprof<contprofessor; icontprof++) 
              {
                for(jcontprof = icontprof+1; jcontprof < contprofessor; jcontprof++)            
                {
                  if (strcmp(vetorProfessores[icontprof].nome,vetorProfessores[jcontprof].nome) > 0)
                  {
                    vetorAuxAlunosProfessores.matricula = vetorProfessores[icontprof].matricula;
                    strcpy(vetorAuxAlunosProfessores.nome, vetorProfessores[icontprof].nome);
                    vetorAuxAlunosProfessores.sexo = vetorProfessores[icontprof].sexo;
                    vetorAuxAlunosProfessores.dataNascimento.dia = vetorProfessores[icontprof].dataNascimento.dia;
                    vetorAuxAlunosProfessores.dataNascimento.mes = vetorProfessores[icontprof].dataNascimento.mes;
                    vetorAuxAlunosProfessores.dataNascimento.ano = vetorProfessores[icontprof].dataNascimento.ano;
                    strcpy(vetorAuxAlunosProfessores.CPF, vetorProfessores[icontprof].CPF);           
                  
                    vetorProfessores[icontprof].matricula = vetorProfessores[jcontprof].matricula;
                    strcpy(vetorProfessores[icontprof].nome, vetorProfessores[jcontprof].nome);
                    vetorProfessores[icontprof].sexo = vetorProfessores[jcontprof].sexo;
                    vetorProfessores[icontprof].dataNascimento.dia = vetorProfessores[jcontprof].dataNascimento.dia;
                    vetorProfessores[icontprof].dataNascimento.mes = vetorProfessores[jcontprof].dataNascimento.mes;
                    vetorProfessores[icontprof].dataNascimento.ano = vetorProfessores[jcontprof].dataNascimento.ano;
                    strcpy(vetorAlunos[icontprof].CPF, vetorProfessores[jcontprof].CPF);
        
                      vetorProfessores[jcontprof].matricula = vetorAuxAlunosProfessores.matricula;
                      strcpy(vetorProfessores[jcontprof].nome, vetorAuxAlunosProfessores.nome);
                      vetorProfessores[jcontprof].sexo = vetorAuxAlunosProfessores.sexo;
                      vetorProfessores[jcontprof].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                      vetorProfessores[jcontprof].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                      vetorProfessores[jcontprof].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                      strcpy(vetorProfessores[jcontprof].CPF, vetorAuxAlunosProfessores.CPF);
                  }
                }
              }            
            printf("\n--- LISTA DE PROFESSORES ORDENADOS POR NOME --- \n \n");
            for(icontprof = 0; icontprof < contprofessor; icontprof++)
            {             
            	printf("Nome: %s \n", vetorProfessores[icontprof].nome);
              printf("Matrícula: %d \n", vetorProfessores[icontprof].matricula);
            }
          }            
          printf(" \n________________________________________________ \n");
        }      
        if(opcaorel == 10)//ESTÁ OK
        {
          if(contprofessor == 0)
      		{
      			printf("\n A lista de Professores está vazia. \n");
      			printf("Primeiramente, você deve inserir/incluir um professor no sistema. \n \n");
    				finalizarrel = 1;
    			}
          else
          {          
            for (icontprof = 0; icontprof<contprofessor; icontprof++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O ANO.
            {
              for(jcontprof = icontprof; jcontprof < contprofessor; jcontprof++)            
              {
                if (vetorProfessores[icontprof].dataNascimento.ano > vetorProfessores[jcontprof].dataNascimento.ano)
                  {
                    vetorAuxAlunosProfessores.matricula = vetorProfessores[icontprof].matricula;
                      strcpy(vetorAuxAlunosProfessores.nome, vetorProfessores[icontprof].nome);
                      vetorAuxAlunosProfessores.sexo = vetorProfessores[icontprof].sexo;
                      vetorAuxAlunosProfessores.dataNascimento.dia = vetorProfessores[icontprof].dataNascimento.dia;
                      vetorAuxAlunosProfessores.dataNascimento.mes = vetorProfessores[icontprof].dataNascimento.mes;
                      vetorAuxAlunosProfessores.dataNascimento.ano = vetorProfessores[icontprof].dataNascimento.ano;
                      strcpy(vetorAuxAlunosProfessores.CPF, vetorProfessores[icontprof].CPF);           
                    
                      vetorProfessores[icontprof].matricula = vetorProfessores[jcontprof].matricula;
                      strcpy(vetorProfessores[icontprof].nome, vetorProfessores[jcontprof].nome);
                      vetorProfessores[icontprof].sexo = vetorProfessores[jcontprof].sexo;
                      vetorProfessores[icontprof].dataNascimento.dia = vetorProfessores[jcontprof].dataNascimento.dia;
                      vetorProfessores[icontprof].dataNascimento.mes = vetorProfessores[jcontprof].dataNascimento.mes;
                      vetorProfessores[icontprof].dataNascimento.ano = vetorProfessores[jcontprof].dataNascimento.ano;
                      strcpy(vetorAlunos[icontprof].CPF, vetorProfessores[jcontprof].CPF);
          
                        vetorProfessores[jcontprof].matricula = vetorAuxAlunosProfessores.matricula;
                        strcpy(vetorProfessores[jcontprof].nome, vetorAuxAlunosProfessores.nome);
                        vetorProfessores[jcontprof].sexo = vetorAuxAlunosProfessores.sexo;
                        vetorProfessores[jcontprof].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                        vetorProfessores[jcontprof].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                        vetorProfessores[jcontprof].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                        strcpy(vetorProfessores[jcontprof].CPF, vetorAuxAlunosProfessores.CPF);                  
                  }
              }
            }
  
            for (icontprof = 0; icontprof <contprofessor; icontprof ++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM o MÊS
            {
              for(jcontprof  = icontprof ; jcontprof  < contprofessor; jcontprof ++)            
              {
                if((vetorProfessores[icontprof].dataNascimento.mes > vetorProfessores[jcontprof].dataNascimento.mes) && (vetorProfessores[icontprof].dataNascimento.ano == vetorProfessores[jcontprof].dataNascimento.ano))
                  {
                    vetorAuxAlunosProfessores.matricula = vetorProfessores[icontprof].matricula;
                      strcpy(vetorAuxAlunosProfessores.nome, vetorProfessores[icontprof].nome);
                      vetorAuxAlunosProfessores.sexo = vetorProfessores[icontprof].sexo;
                      vetorAuxAlunosProfessores.dataNascimento.dia = vetorProfessores[icontprof].dataNascimento.dia;
                      vetorAuxAlunosProfessores.dataNascimento.mes = vetorProfessores[icontprof].dataNascimento.mes;
                      vetorAuxAlunosProfessores.dataNascimento.ano = vetorProfessores[icontprof].dataNascimento.ano;
                      strcpy(vetorAuxAlunosProfessores.CPF, vetorProfessores[icontprof].CPF);           
                    
                      vetorProfessores[icontprof].matricula = vetorProfessores[jcontprof].matricula;
                      strcpy(vetorProfessores[icontprof].nome, vetorProfessores[jcontprof].nome);
                      vetorProfessores[icontprof].sexo = vetorProfessores[jcontprof].sexo;
                      vetorProfessores[icontprof].dataNascimento.dia = vetorProfessores[jcontprof].dataNascimento.dia;
                      vetorProfessores[icontprof].dataNascimento.mes = vetorProfessores[jcontprof].dataNascimento.mes;
                      vetorProfessores[icontprof].dataNascimento.ano = vetorProfessores[jcontprof].dataNascimento.ano;
                      strcpy(vetorAlunos[icontprof].CPF, vetorProfessores[jcontprof].CPF);
          
                        vetorProfessores[jcontprof].matricula = vetorAuxAlunosProfessores.matricula;
                        strcpy(vetorProfessores[jcontprof].nome, vetorAuxAlunosProfessores.nome);
                        vetorProfessores[jcontprof].sexo = vetorAuxAlunosProfessores.sexo;
                        vetorProfessores[jcontprof].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                        vetorProfessores[jcontprof].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                        vetorProfessores[jcontprof].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                        strcpy(vetorProfessores[jcontprof].CPF, vetorAuxAlunosProfessores.CPF);                    
                  }
              }
            }
  
            for (icontprof = 0; icontprof<contprofessor; icontprof++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O DIA
            {
              for(icontprof = icontprof; icontprof < contprofessor; icontprof++)            
              {
                if ((vetorProfessores[icontprof].dataNascimento.dia > vetorProfessores[icontprof].dataNascimento.dia) && (vetorProfessores[icontprof].dataNascimento.mes == vetorProfessores[icontprof].dataNascimento.mes) && (vetorProfessores[icontprof].dataNascimento.dia == vetorProfessores[icontprof].dataNascimento.dia))
                  {
                    vetorAuxAlunosProfessores.matricula = vetorProfessores[icontprof].matricula;
                      strcpy(vetorAuxAlunosProfessores.nome, vetorProfessores[icontprof].nome);
                      vetorAuxAlunosProfessores.sexo = vetorProfessores[icontprof].sexo;
                      vetorAuxAlunosProfessores.dataNascimento.dia = vetorProfessores[icontprof].dataNascimento.dia;
                      vetorAuxAlunosProfessores.dataNascimento.mes = vetorProfessores[icontprof].dataNascimento.mes;
                      vetorAuxAlunosProfessores.dataNascimento.ano = vetorProfessores[icontprof].dataNascimento.ano;
                      strcpy(vetorAuxAlunosProfessores.CPF, vetorProfessores[icontprof].CPF);           
                    
                      vetorProfessores[icontprof].matricula = vetorProfessores[jcontprof].matricula;
                      strcpy(vetorProfessores[icontprof].nome, vetorProfessores[jcontprof].nome);
                      vetorProfessores[icontprof].sexo = vetorProfessores[jcontprof].sexo;
                      vetorProfessores[icontprof].dataNascimento.dia = vetorProfessores[jcontprof].dataNascimento.dia;
                      vetorProfessores[icontprof].dataNascimento.mes = vetorProfessores[jcontprof].dataNascimento.mes;
                      vetorProfessores[icontprof].dataNascimento.ano = vetorProfessores[jcontprof].dataNascimento.ano;
                      strcpy(vetorAlunos[icontprof].CPF, vetorProfessores[jcontprof].CPF);
          
                        vetorProfessores[jcontprof].matricula = vetorAuxAlunosProfessores.matricula;
                        strcpy(vetorProfessores[jcontprof].nome, vetorAuxAlunosProfessores.nome);
                        vetorProfessores[jcontprof].sexo = vetorAuxAlunosProfessores.sexo;
                        vetorProfessores[jcontprof].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
                        vetorProfessores[jcontprof].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
                        vetorProfessores[jcontprof].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
                        strcpy(vetorProfessores[jcontprof].CPF, vetorAuxAlunosProfessores.CPF);                    
                  }
              }
            }
            printf("\n--- LISTA DE PROFESSORES ORDENADOS POR DATA DE NASCIMENTO --- \n \n");
            for(icontprof = 0; icontprof < contprofessor; icontprof++)
            {             
              printf("Nome: %s \n", vetorProfessores[icontprof].nome);
              printf("Data de Nascimento: %d/%d/%d \n", vetorProfessores[icontprof].dataNascimento.dia, vetorProfessores[icontprof].dataNascimento.mes, vetorProfessores[icontprof].dataNascimento.ano);
            }
          }
          printf("____________________________________________________ \n");
        }
        if(opcaorel == 11)
        {
          prints = 0;
          printf("Informe o mês que deseja verificar os aniversariantes. \n");
          scanf("%d", &mes);
          printf(" \n--ANIVERSARIANTES DO MÊS %d-- \n", mes);          
          for(icontaluno = 0; icontaluno < contaluno; icontaluno++)
          {
            if(vetorAlunos[icontaluno].dataNascimento.mes == mes)
            {
              printf("Aluno: %s \n", vetorAlunos[icontaluno].nome);
              prints++;
            }                        
            if(vetorProfessores[icontaluno].dataNascimento.mes == mes)
            {
              printf("Professor: %s \n", vetorProfessores[icontaluno].nome);
              prints++;
            }
          }
          if(prints == 0)
          {
            printf("Não há aniversariantes neste mês ou a lista professores e/ou alunos estão vazias.\n ");            
          }
          printf("_______________________________________________________ \n \n");
        }                      
        if(opcaorel == 12)
        {
        }
        if(opcaorel == 13)
        {
        }
        if(opcaorel == 14)
        {
        }        
        if(opcaorel >= 15)
        { 
        printf("Opção inválida. \n \n");
        }
      }   
    }   
  }//Chave do Finalizar Menu Geral
  return 0;
}
