#include <stdio.h>
#include <string.h>
//#define qtdealuno 2
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

int funcMenuPrincipalAluno();
int funcIncluirAluno(incluir *vetorAluno, int n, int opc);
void funcListarAluno(incluir *vetorAluno, int n);
int funcAtualizarAluno(incluir *vetorAluno, int n, int opc);
int funcExcluirAluno(incluir *vetorAluno, int n);
int funcValidaMatricula(incluir *vetorAluno, int n);
int funcValidaSexo(incluir *vetorAluno, int n);
int funcValidaData(incluir *vetorAluno, int n);
int funcValidaCPF(incluir *vetorAluno, int n);*/

int mainAluno() 
{
	/*incluir Aluno;
	incluir vetorAluno[qtdealuno];*/
	
	int icont = 0;	
	int opcao, retorno, retornoatualizacao, retornoexclusao;
	int  finalizar = 0;
		
	while(finalizar == 0)
	{
    //int funcMenuPrincipalAluno();
		opcao = funcMenuPrincipalAluno();
    
		if(opcao == 0)//OPÇÃO PARA SAIR DO MENU;
		{
			printf("Finalizando Menu Gestão de Alunos. \n");
			return 1;
		}
    

  	if(opcao == 1)//OPÇÃO PARA INCLUIR ALUNO;
		{
      //int funcIncluirAluno(incluir *vetorAluno, int n);
			retorno = funcIncluirAluno(vetorAluno, icont, opcao); 
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

    
		if(opcao == 2) //OPÇÃO PARA LISTAR ALUNOS
		{
      funcListarAluno(vetorAluno, icont);                 
    }

    
		if(opcao == 3) //OPÇÃO PARA ATUALIZAR ALUNO;
		{
      //int funcAtualizarAluno(incluir *vetorAluno, int n);
			retornoatualizacao = funcAtualizarAluno(vetorAluno, icont, opcao); 
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

    
		if(opcao == 4) //OPÇÃO PARA EXCLUIR ALUNO;
		{
      //int funcExcluirAluno(incluir *vetorAluno, int n);
			retornoexclusao = funcExcluirAluno(vetorAluno, qtdealuno);
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

int funcMenuPrincipalAluno() //FUNÇÃO DE MENU PRINCIPAL
{
	int opcao;
	printf("--- Gestão de Alunos --- \n");
	printf("0 - Sair \n");
	printf("1 - Incluir Aluno \n");
	printf("2 - Listar Aluno \n");
	printf("3 - Atualizar aluno \n");
	printf("4 - Excluir aluno \n");
	scanf("%d", &opcao);
	return opcao;
}

//FUNÇÃO PARA INCLUIR ALUNO
int funcIncluirAluno(incluir *vetorAluno, int n, int opc) 
{ 
  if(n >= qtdealuno) //CONDIÇÃO QUE VERIFICA SE A TENTATIVA DE INCLUSÃO EXCEDE O TAMANHO DO VETOR ALUNOS.
  {
    printf("Não há mais vagas para alunos. \n");
    return ERRO_CADASTRO_MATRICULA;
  }
  
	//printf("-- INCLUSÃO DE ALUNOS --\n");
	printf("- DADOS DO ALUNO - \n");
	if(opc == 1) //CONDIÇÃO QUE PERMITE A INFORMAÇÃO DA MATRÍCULA SOMENTE QUANDO O USUÁRIO OPTA POR INCLUIR ALUNO NO MENU.
  {
    printf("Matricula do Aluno: \n");
	  scanf("%d", &vetorAluno[n].matricula);
	  getchar(); 
  }
 
  if (funcValidaMatricula(vetorAluno, n) == 0) //FUNÇÃO PARA VALIDAR MATRÍCULA
  {
    return ERRO_CADASTRO_MATRICULA;
  }
			
	printf("Nome do Aluno (até 50 caracteres): \n");
	fflush(stdin);
	fgets(vetorAluno[n].nome, 51, stdin);
					
	size_t ln = strlen(vetorAluno[n].nome) - 1; //comando para retirar o \n gerado pelo fgets
	if (vetorAluno[n].nome[ln] == '\n')
	{
		  vetorAluno[n].nome[ln] = '\0';	
	}
					
	printf("Sexo: M(Masculino)/F(Feminino) \n");
	scanf("%c", &vetorAluno[n].sexo);
	getchar();		

  if (funcValidaSexo(vetorAluno, n) == 0) //FUNÇÃO PARA VALIDAR SEXO
  {
    return ERRO_CADASTRO_SEXO;
  }	

  printf("Dia do Nascimento: \n");
	scanf("%d", &vetorAluno[n].dataNascimento.dia);
	printf("Mês do Nascimento: \n");
	scanf("%d", &vetorAluno[n].dataNascimento.mes);
	printf("Ano do Nascimento: \n");
	scanf("%d", &vetorAluno[n].dataNascimento.ano);								
  getchar();

  if (funcValidaData(vetorAluno, n) == 0) //FUNÇÃO PARA VALIDAR DATA
  {
    return ERRO_CADASTRO_DATANASCIMENTO;
  }  
  
	printf("CPF: (Somente números) \n");
	fflush(stdin);
	fgets(vetorAluno[n].CPF, 12, stdin);
					
	ln = strlen(vetorAluno[n].CPF) - 1; //comando para retirar o \n gerado pelo fgets
	if (vetorAluno[n].CPF[ln] == '\n')
	{
	  vetorAluno[n].CPF[ln] = '\0';	
  }  	
  
  if (funcValidaCPF(vetorAluno, n) == 0) //FUNÇÃO PARA VALIDAR CPF
  {
    return ERRO_CADASTRO_CPF;
  } 
  
  return CADASTRO_REALIZADO;
}

void funcListarAluno(incluir *vetorAluno, int n) //n = icont.
{
  if(n == 0) //CONDIÇÃO QUE VERIFICA A EXISTÊNCIA DE ALGUM ALUNO NA LISTA.
  {
    printf(" \n A lista de Alunos está vazia. Primeiramente, você deve incluir um Aluno. \n \n");    
  }
  else //HÁ ALUNOS NA LISTA.
  {
    int icont;
	  printf("\n--- LISTA DE ALUNOS --- \n");
	  for (icont = 0; icont < n; icont++)
	  {
		  printf("Matrícula: %d \n", vetorAluno[icont].matricula);
		  printf("Nome: %s \n", vetorAluno[icont].nome);
		  printf("Sexo: %c \n", vetorAluno[icont].sexo);
		  printf("Data Nascimento: %d/%d/%d \n", vetorAluno[icont].dataNascimento.dia, vetorAluno[icont].dataNascimento.mes, vetorAluno[icont].dataNascimento.ano);
		  printf("CPF: %s \n \n", vetorAluno[icont].CPF);
    }
    printf("________________________________________________ \n");    
  }
}		

int funcAtualizarAluno(incluir *vetorAluno, int n, int opc) //FUNÇÃO PARA ATUALIZAR ALUNO.
{
	int matricula, icont, posvetor = -2;
  
  if(n == 0) //CONDIÇÃO QUE VERIFICA A EXISTÊNCIA DE ALGUM ALUNO NA LISTA.
  {
    printf("\n A lista de Alunos está vazia. Primeiramente, você deve incluir um Aluno. \n \n");
    return ERRO_CADASTRO_MATRICULA;
  }
  else //HÁ ALUNOS NA LISTA.
  {
    printf("\n Informe a matrícula do aluno que deseja atualizar os dados. \n");
	  scanf("%d", &matricula);
    getchar();
    
    for(icont = 0; icont < n; icont++) // LAÇO PARA VERIFICAR SE A MATRÍCULA INFORMADA EXISTE
    {
    	if(vetorAluno[icont].matricula == matricula)
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
      return funcIncluirAluno(vetorAluno, posvetor, opc); 
    }    
  }  
}	   
		
//FUNÇÃO PARA INCLUIR ALUNO
int funcExcluirAluno(incluir *vetorAluno, int n)
{
	int matricula, icont, posvetor = -2, jcont;
	printf("Informe a matrícula do aluno que deseja atualizar os dados. \n ");
	scanf("%d", &matricula);
  getchar();
	
	for(icont = 0; icont < n; icont++)
	{
		if(vetorAluno[icont].matricula == matricula)
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
		printf("--- ALUNO A SER EXCLUÍDO %d --- \n", matricula);
		printf("Nome: %s \n", vetorAluno[posvetor].nome);
		printf("Sexo: %c \n", vetorAluno[posvetor].sexo);
		printf("Data Nascimento: %d/%d/%d \n", vetorAluno[posvetor].dataNascimento.dia, vetorAluno[posvetor].dataNascimento.mes, vetorAluno[posvetor].dataNascimento.ano);
		printf("CPF: %s \n", vetorAluno[posvetor].CPF);
		printf("________________________________________________ \n");
			
		printf("Excluindo dados... \n");
		
		vetorAluno[posvetor].matricula = 0;		
		strcpy(vetorAluno[posvetor].nome, "0");
		vetorAluno[posvetor].sexo = '0';
		vetorAluno[posvetor].dataNascimento.dia = 0;
		vetorAluno[posvetor].dataNascimento.mes = 0;
		vetorAluno[posvetor].dataNascimento.ano = 0;
		strcpy(vetorAluno[posvetor].CPF, "0");

		return EXCLUSAO_REALIZADA;	
	}	
}

//FUNÇÃO PARA VALIDAR MATRÍCULA
int funcValidaMatricula(incluir *vetorAluno, int n)
{
  if(vetorAluno[n].matricula <= 0)
	{
    printf("\n O número de matrícula deve ser maior que 0. \n \n");
		return 0;
	}  
}

//FUNÇÃO PARA VALIDAR SEXO
int funcValidaSexo(incluir *vetorAluno, int n)
{
  if((vetorAluno[n].sexo == 'M') || (vetorAluno[n].sexo == 'F'))
	{			
  }
  else
  {
    printf("\n O sexo informado deve ser M para Masculino e F para Feminino. \n \n");
		return 0;	
	}         
}	

//FUNÇÃO PARA VALIDAR DATA
int funcValidaData(incluir *vetorAluno, int n)
{
  if((vetorAluno[n].dataNascimento.ano > 2021) || (vetorAluno[n].dataNascimento.ano <= 1930))
  {
    printf("\nAno de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n \n");
    return 0;
  }
  else
  {
    if((vetorAluno[n].dataNascimento.mes > 12) && (vetorAluno[n].dataNascimento.ano <= 0))
    {
      printf("\nMês de nascimento inválido. O mês de nascimento deve ser entre 1 e 12 \n \n");  
      return 0;
    }
    else
    {
      if((vetorAluno[n].dataNascimento.mes == 1) || (vetorAluno[n].dataNascimento.mes == 3) || (vetorAluno[n].dataNascimento.mes == 5) || (vetorAluno[n].dataNascimento.mes == 7) || (vetorAluno[n].dataNascimento.mes == 8) || (vetorAluno[n].dataNascimento.mes == 10) || (vetorAluno[n].dataNascimento.mes == 12))
      {
        if((vetorAluno[n].dataNascimento.dia <= 0 || vetorAluno[n].dataNascimento.dia > 31))
        {
          printf("\nData de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 31 \n\n");
          return 0;          
        }        
      }
      else
      {
        if(vetorAluno[n].dataNascimento.mes == 2)
			  {
          if((vetorAluno[n].dataNascimento.dia <= 0 || vetorAluno[n].dataNascimento.dia >= 29))
          {
            printf("\n Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 28 para anos não bissextos e 29 para anos bissextos \n \n");
            return 0;
          }          
        }
        else
        {
          if((vetorAluno[n].dataNascimento.dia <= 0 || vetorAluno[n].dataNascimento.dia >= 30))
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
int funcValidaCPF(incluir *vetorAluno, int n)
{
  int somaaluno = strlen(vetorAluno[n].CPF);                
  if(somaaluno < 11)
  {
    printf("\n O número informado deve ter 11 números. \n \n");
    return 0;
  }  
}

