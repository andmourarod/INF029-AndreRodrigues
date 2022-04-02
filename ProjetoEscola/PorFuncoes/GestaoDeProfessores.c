#include <stdio.h>
#include <string.h>
//#define qtdeprof 2
#define CADASTRO_REALIZADO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3
#define ERRO_CADASTRO_DATANASCIMENTO 4
#define ERRO_CADASTRO_CPF 5
#define ERRO_MATRICULA_INEXISTE 10
#define ERRO_EXCLUSAO_MATRICULA_INEXISTE 11
#define EXCLUSAO_REALIZADA 12
#define ERRO_LEITURA_LISTA 13

/*typedef struct 
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
	char CPF[12];	
}incluir;

int funcMenuPrincipalProf();
int funcIncluirProf(incluir *vetorProf, int n, int opc);
void funcListarProf(incluir *vetorProf, int n);
int funcAtualizarProf(incluir *vetorProf, int n, int opc);
int funcExcluirProf(incluir *vetorProf, int n);
int funcValidaMatriculaProf(incluir *vetorProf, int n);
int funcValidaSexoProf(incluir *vetorProf, int n);
int funcValidaDataProf(incluir *vetorProf, int n);
int funcValidaCPFProf(incluir *vetorProf, int n);*/

int mainProfessor() 
{
	/*incluir Prof;
	incluir vetorProf[qtdeprof];*/
	
	int icont = 0;	
	int opcao, retorno, retornoatualizacao, retornoexclusao;
	int  finalizar = 0;
		
	while(finalizar == 0)
	{
    //int funcMenuPrincipalProf();
		opcao = funcMenuPrincipalProf();
    
		if(opcao == 0)//OPÇÃO PARA SAIR DO MENU;
		{
			printf("Finalizando Menu Gestão de Professores. \n");
			return 1;
		}
    

  	if(opcao == 1)//OPÇÃO PARA INCLUIR PROFESSOR;
		{
      //int funcIncluirProf(incluir *vetorProf, int n);
			retorno = funcIncluirProf(vetorProf, icont, opcao); 
			if(retorno == CADASTRO_REALIZADO )
			{
				printf(" \n Cadastro Realizado. \n \n");
				icont++;
			}
			else
			{
				if(retorno == ERRO_CADASTRO_MATRICULA)
				{
					printf("Erro no cadastro de matrícula. \n \n");
				}
				if(retorno == ERRO_CADASTRO_SEXO)
				{
					printf("Erro no cadastro de sexo. \n \n");	
				}
				if(retorno == ERRO_CADASTRO_DATANASCIMENTO)
				{
					printf("Erro no cadastro de data de nascimento. \n \n");	
				}
				if(retorno == ERRO_CADASTRO_CPF)
				{
					printf("Erro no cadastro de CPF \n \n");	
				}
			}
		}

    
		if(opcao == 2) //OPÇÃO PARA LISTAR PROFESSORES
		{
      funcListarProf(vetorProf, icont);                 
    }

    
		if(opcao == 3) //OPÇÃO PARA ATUALIZAR PROFESSORES;
		{
      //int funcAtualizarProf(incluir *vetorProf, int n);
			retornoatualizacao = funcAtualizarProf(vetorProf, icont, opcao); 
      if(retornoatualizacao == CADASTRO_REALIZADO)
			{
				printf("Atualização realizada com sucesso. \n\n");
			}
			else
			{
				if(retornoatualizacao == ERRO_MATRICULA_INEXISTE)
				{
					printf("Erro na atualização: matrícula informada não existe. \n");
				}
        if(retornoatualizacao == ERRO_CADASTRO_MATRICULA)
				{
					printf("Erro na atualização de matrícula. \n \n");
				}
				if(retornoatualizacao == ERRO_CADASTRO_SEXO)
				{
					printf("Erro na atualização de sexo. \n \n");	
				}
				if(retornoatualizacao == ERRO_CADASTRO_DATANASCIMENTO)
				{
					printf("Erro na atualização de data de nascimento. \n \n");	
				}
				if(retornoatualizacao == ERRO_CADASTRO_CPF)
				{
					printf("Erro na atualização de CPF \n \n");	
				}
			}			
		}

    
		if(opcao == 4) //OPÇÃO PARA EXCLUIR Prof;
		{
      //int funcExcluirAluno(incluir *vetorProf, int n);
			retornoexclusao = funcExcluirProf(vetorProf, qtdeprof);
			if(retornoexclusao == EXCLUSAO_REALIZADA)
			{
				printf("Exclusão realizada com sucesso. \n\n");
			}
			else
			{
				if(retornoexclusao == ERRO_EXCLUSAO_MATRICULA_INEXISTE)
				{
					printf("Erro na exclusão: matrícula informada não existe. \n");
				}	
			}			
		}

    
		if(opcao > 5)
		{
			printf("Opção inexistente. \n");
		}
	}
    return 0;
}

//DESCRIÇÃO DE FUNÇÕES

int funcMenuPrincipalProf() //FUNÇÃO DE MENU PRINCIPAL
{
	int opcao;
	printf("--- Gestão de Professores --- \n");
	printf("0 - Sair \n");
	printf("1 - Incluir Professor \n");
	printf("2 - Listar Professor \n");
	printf("3 - Atualizar Professor \n");
	printf("4 - Excluir Professor \n");
	scanf("%d", &opcao);
	return opcao;
}

//FUNÇÃO PARA INCLUIR PROFESSOR
int funcIncluirProf(incluir *vetorProf, int n, int opc) 
{ 
  if(n >= qtdeprof) //CONDIÇÃO QUE VERIFICA SE A TENTATIVA DE INCLUSÃO EXCEDE O TAMANHO DO VETOR PROFESSOR.
  {
    printf("Não há mais vagas para alunos. \n");
    return ERRO_CADASTRO_MATRICULA;
  }
  
	//printf("-- INCLUSÃO DE PROFESSOR --\n");
	printf("- DADOS DO PROFESSOR - \n");
	if(opc == 1) //CONDIÇÃO QUE PERMITE A INFORMAÇÃO DA MATRÍCULA SOMENTE QUANDO O USUÁRIO OPTA POR INCLUIR PROFESSOR NO MENU.
  {
    printf("Matricula do Professor: \n");
	  scanf("%d", &vetorProf[n].matricula);
	  getchar(); 
  }
 
  if (funcValidaMatriculaProf(vetorProf, n) == 0) //FUNÇÃO PARA VALIDAR MATRÍCULA
  {
    return ERRO_CADASTRO_MATRICULA;
  }
			
	printf("Nome do Professor (até 50 caracteres): \n");
	fflush(stdin);
	fgets(vetorProf[n].nome, 51, stdin);
					
	size_t ln = strlen(vetorProf[n].nome) - 1; //comando para retirar o \n gerado pelo fgets
	if (vetorProf[n].nome[ln] == '\n')
	{
		  vetorProf[n].nome[ln] = '\0';	
	}
					
	printf("Sexo: M(Masculino)/F(Feminino) \n");
	scanf("%c", &vetorProf[n].sexo);
	getchar();		

  if (funcValidaSexoProf(vetorProf, n) == 0) //FUNÇÃO PARA VALIDAR SEXO
  {
    return ERRO_CADASTRO_SEXO;
  }	

  printf("Dia do Nascimento: \n");
	scanf("%d", &vetorProf[n].dataNascimento.dia);
	printf("Mês do Nascimento: \n");
	scanf("%d", &vetorProf[n].dataNascimento.mes);
	printf("Ano do Nascimento: \n");
	scanf("%d", &vetorProf[n].dataNascimento.ano);								
  getchar();

  if (funcValidaDataProf(vetorProf, n) == 0) //FUNÇÃO PARA VALIDAR DATA
  {
    return ERRO_CADASTRO_DATANASCIMENTO;
  }  
  
	printf("CPF: (Somente números) \n");
	fflush(stdin);
	fgets(vetorProf[n].CPF, 12, stdin);
					
	ln = strlen(vetorProf[n].CPF) - 1; //comando para retirar o \n gerado pelo fgets
	if (vetorProf[n].CPF[ln] == '\n')
	{
	  vetorProf[n].CPF[ln] = '\0';	
  }  	
  
  if (funcValidaCPFProf(vetorProf, n) == 0) //FUNÇÃO PARA VALIDAR CPF
  {
    return ERRO_CADASTRO_CPF;
  } 
  
  return CADASTRO_REALIZADO;
}

void funcListarProf(incluir *vetorProf, int n) //n = icont.
{
  if(n == 0) //CONDIÇÃO QUE VERIFICA A EXISTÊNCIA DE ALGUM PROFESSOR NA LISTA.
  {
    printf(" \n A lista de professores está vazia. Primeiramente, você deve incluir um professor. \n \n");    
  }
  else //HÁ PROFESSORES NA LISTA.
  {
    int icont;
	  printf("\n--- LISTA DE PROFESSORES --- \n");
	  for (icont = 0; icont < n; icont++)
	  {
		  printf("Matrícula: %d \n", vetorProf[icont].matricula);
		  printf("Nome: %s \n", vetorProf[icont].nome);
		  printf("Sexo: %c \n", vetorProf[icont].sexo);
		  printf("Data Nascimento: %d/%d/%d \n", vetorProf[icont].dataNascimento.dia, vetorProf[icont].dataNascimento.mes, vetorProf[icont].dataNascimento.ano);
		  printf("CPF: %s \n \n", vetorProf[icont].CPF);
    }
    printf("________________________________________________ \n");    
  }
}		

int funcAtualizarProf(incluir *vetorProf, int n, int opc) //FUNÇÃO PARA ATUALIZAR PROFESSOR
{
	int matricula, icont, posvetor = -2;
  
  if(n == 0) //CONDIÇÃO QUE VERIFICA A EXISTÊNCIA DE ALGUM PROFESSOR NA LISTA.
  {
    printf("\n A lista de Professores está vazia. Primeiramente, você deve incluir um Professor. \n \n");
    return ERRO_CADASTRO_MATRICULA;
  }
  else //HÁ PROFESSORES NA LISTA.
  {
    printf("\n Informe a matrícula do professor que deseja atualizar os dados. \n");
	  scanf("%d", &matricula);
    getchar();
    
    for(icont = 0; icont < n; icont++) // LAÇO PARA VERIFICAR SE A MATRÍCULA INFORMADA EXISTE
    {
    	if(vetorProf[icont].matricula == matricula)
    	{
    		posvetor = icont;
    	}		
    }
    
    if(posvetor == -2)
	  {
		return ERRO_MATRICULA_INEXISTE;
	  }
    else
    {
      return funcIncluirProf(vetorProf, posvetor, opc); 
    }    
  }  
}	   
		
//FUNÇÃO PARA INCLUIR PROFESSOR
int funcExcluirProf(incluir *vetorProf, int n)
{
	int matricula, icont, posvetor = -2, jcont;
	printf("Informe a matrícula do professor que deseja atualizar os dados. \n ");
	scanf("%d", &matricula);
  getchar();
	
	for(icont = 0; icont < n; icont++)
	{
		if(vetorProf[icont].matricula == matricula)
		{
			posvetor = icont;
		}		
	}
	
	if(posvetor == -2 )
	{
		return ERRO_EXCLUSAO_MATRICULA_INEXISTE;
	}
	else
	{
		printf("--- PROFESSOR A SER EXCLUÍDO %d --- \n", matricula);
		printf("Nome: %s \n", vetorProf[posvetor].nome);
		printf("Sexo: %c \n", vetorProf[posvetor].sexo);
		printf("Data Nascimento: %d/%d/%d \n", vetorProf[posvetor].dataNascimento.dia, vetorProf[posvetor].dataNascimento.mes, vetorProf[posvetor].dataNascimento.ano);
		printf("CPF: %s \n", vetorProf[posvetor].CPF);
		printf("________________________________________________ \n");
			
		printf("Excluindo dados... \n");
		
		vetorProf[posvetor].matricula = 0;		
		strcpy(vetorProf[posvetor].nome, "0");
		vetorProf[posvetor].sexo = '0';
		vetorProf[posvetor].dataNascimento.dia = 0;
		vetorProf[posvetor].dataNascimento.mes = 0;
		vetorProf[posvetor].dataNascimento.ano = 0;
		strcpy(vetorProf[posvetor].CPF, "0");

		return EXCLUSAO_REALIZADA;	
	}	
}

//FUNÇÃO PARA VALIDAR MATRÍCULA
int funcValidaMatriculaProf(incluir *vetorProf, int n)
{
  if(vetorProf[n].matricula <= 0)
	{
    printf("\n O número de matrícula deve ser maior que 0. \n \n");
		return 0;
	}  
}

//FUNÇÃO PARA VALIDAR SEXO
int funcValidaSexoProf(incluir *vetorProf, int n)
{
  if((vetorProf[n].sexo != 'M') && (vetorProf[n].sexo != 'F'))
	{	
    printf("\n O sexo informado deve ser M para Masculino e F para Feminino. \n \n");
		return 0;	
  }           
}	

//FUNÇÃO PARA VALIDAR DATA
int funcValidaDataProf(incluir *vetorProf, int n)
{
  if((vetorProf[n].dataNascimento.ano > 2021) || (vetorProf[n].dataNascimento.ano <= 1930))
  {
    printf("\nAno de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n \n");
    return 0;
  }
  else
  {
    if((vetorProf[n].dataNascimento.mes > 12) && (vetorProf[n].dataNascimento.ano <= 0))
    {
      printf("\nMês de nascimento inválido. O mês de nascimento deve ser entre 1 e 12 \n \n");  
      return 0;
    }
    else
    {
      if((vetorProf[n].dataNascimento.mes == 1) || (vetorProf[n].dataNascimento.mes == 3) || (vetorProf[n].dataNascimento.mes == 5) || (vetorProf[n].dataNascimento.mes == 7) || (vetorProf[n].dataNascimento.mes == 8) || (vetorProf[n].dataNascimento.mes == 10) || (vetorProf[n].dataNascimento.mes == 12))
      {
        if((vetorProf[n].dataNascimento.dia <= 0 || vetorProf[n].dataNascimento.dia > 31))
        {
          printf("\nData de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 31 \n\n");
          return 0;          
        }        
      }
      else
      {
        if(vetorProf[n].dataNascimento.mes == 2)
			  {
          if((vetorProf[n].dataNascimento.dia <= 0 || vetorProf[n].dataNascimento.dia >= 29))
          {
            printf("\n Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 28 para anos não bissextos e 29 para anos bissextos \n \n");
            return 0;
          }          
        }
        else
        {
          if((vetorProf[n].dataNascimento.dia <= 0 || vetorProf[n].dataNascimento.dia >= 30))
          {        
            printf("\n Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 30 \n \n");
            return 0;
          }
        }        
      }      
    }    
  }
}

//FUNÇÃO PARA VALIDAR CPF
int funcValidaCPFProf(incluir *vetorProf, int n)
{
  int somanum = strlen(vetorProf[n].CPF);                
  if(somanum < 11)
  {
    printf("\n O número informado deve ter 11 números. \n \n");
    return 0;
  }
}

