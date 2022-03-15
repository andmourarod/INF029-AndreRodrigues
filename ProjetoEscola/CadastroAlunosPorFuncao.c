#include <stdio.h>
#include <string.h>
#define qtdealuno 2
#define CADASTRO_REALIZADO 1
#define ERRO_CADASTRO_MATRICULA 2
#define ERRO_CADASTRO_SEXO 3
#define ERRO_CADASTRO_DATANASCIMENTO 4
#define ERRO_CADASTRO_CPF 5
#define ATUALIZACAO_REALIZADA 6
#define ERRO_ATUALIZACAO_SEXO 7
#define ERRO_ATUALIZACAO_DATANASCIMENTO 8
#define ERRO_ATUALIZACAO_CPF 9
#define ERRO_ATUALIZACAO_MATRICULA_INEXISTE 10
#define ERRO_EXCLUSAO_MATRICULA_INEXISTE 11
#define EXCLUSAO_REALIZADA 12

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
	char CPF[12];	
}incluir;

int main(void) //posteriormente chamará professor
{
	incluir Aluno;
	incluir vetorAluno[qtdealuno];
	
	int icont;	
	int opcao, retorno, retornoatualizacao, retornoexclusao;
	int  finalizar = 0;
	
	int funcMenuPrincipalAluno();
	int funcIncluirAluno(incluir *vetorAluno, int n);
	void funcListarAluno(incluir vetorAuno[], int n);
	int funcAtualizarAluno(incluir *vetorAluno, int n);
	int funcExcluirAluno(incluir *vetorAluno, int n);
		
	while(finalizar == 0)
	{
		opcao = funcMenuPrincipalAluno();
				
		if(opcao == 0)
		{
			printf("Finalizando Menu Professor. \n");
			return 1;
		}
		if(opcao == 1)
		{
			retorno = funcIncluirAluno(vetorAluno, icont);
			if(retorno == CADASTRO_REALIZADO )
			{
				printf("Cadastro Realizado. \n \n");
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
		if(opcao == 2)
		{
			funcListarAluno(vetorAluno, qtdealuno);
		}
		if(opcao == 3)
		{
			retornoatualizacao = funcAtualizarAluno(vetorAluno, qtdealuno);
			if(retornoatualizacao == ATUALIZACAO_REALIZADA )
			{
				printf("Atualização realizada com sucesso. \n\n");
			}
			else
			{
				if(retornoatualizacao == ERRO_ATUALIZACAO_MATRICULA_INEXISTE)
				{
					printf("Erro na atualização: matrícula informada não existe. \n");
				}
				if(retornoatualizacao == ERRO_ATUALIZACAO_SEXO)
				{
					printf("Erro na atualização de sexo. \n \n");	
				}
				if(retornoatualizacao == ERRO_ATUALIZACAO_DATANASCIMENTO)
				{
					printf("Erro na atualização de data de nascimento. \n \n");	
				}
				if(retornoatualizacao == ERRO_ATUALIZACAO_CPF)
				{
					printf("Erro na atualização de CPF \n \n");	
				}
			}
			
		}
		if(opcao ==4)
		{
			retornoexclusao = funcExcluirAluno(vetorAluno, qtdealuno);
			if(retornoatualizacao == EXCLUSAO_REALIZADA)
			{
				printf("Exclusão realizada com sucesso. \n\n");
				//qtdealuno--; //na função funcExcluirAluno o aluno a ser excluído foi sobreposto por todos os demais posteriores a ele, indo para a última posição do vetor. Sendo assim
							//esta linha o excluiria do vetor.
			}
			else
			{
				if(retornoatualizacao == ERRO_EXCLUSAO_MATRICULA_INEXISTE)
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

int funcMenuPrincipalAluno()
{
	int opcao;
	printf("--- Cadastro de Alunos --- \n");
	printf("0 - Sair \n");
	printf("1 - Incluir Aluno \n");
	printf("2 - Listar Aluno \n");
	printf("3 - Atualizar aluno \n");
	printf("4 - Excluir aluno \n");
	scanf("%d", &opcao);
	return opcao;
}

int funcIncluirAluno(incluir vetorAluno[], int n)
{
	printf("-- INCLUSÃO DE ALUNOS --\n");
		printf("- DADOS DO ALUNO - \n");
		printf("Matricula do Aluno: \n");
		scanf("%d", &vetorAluno[n].matricula);
		//getchar();
		
		if(vetorAluno[n].matricula <= 0)
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
		
		if((vetorAluno[n].sexo == 'M') || (vetorAluno[n].sexo == 'F'))
		{
			//printf("O sexo informado deve ser M para Masculino e F para Feminino.");											
		}
		else
		{
			return ERRO_CADASTRO_SEXO;	
		}         
		
		printf("Dia do Nascimento: \n");
		scanf("%d", &vetorAluno[n].dataNascimento.dia);
		printf("Mês do Nascimento: \n");
		scanf("%d", &vetorAluno[n].dataNascimento.mes);
		printf("Ano do Nascimento: \n");
		scanf("%d", &vetorAluno[n].dataNascimento.ano);
					
		//AVALIAR MELHORIA PARA INCLUIR ANO BISSEXTO.
		if((vetorAluno[n].dataNascimento.ano > 2021) || (vetorAluno[n].dataNascimento.ano <= 1930))
		{	
			//printf("Ano de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n");
			return ERRO_CADASTRO_DATANASCIMENTO;
		}
		else
		{
			if((vetorAluno[n].dataNascimento.mes == 1) || (vetorAluno[n].dataNascimento.mes == 3) || (vetorAluno[n].dataNascimento.mes == 5) || (vetorAluno[n].dataNascimento.mes == 7) || (vetorAluno[n].dataNascimento.mes == 8) || (vetorAluno[n].dataNascimento.mes == 10) || (vetorAluno[n].dataNascimento.mes == 12))
			{
				if((vetorAluno[n].dataNascimento.dia <= 0 || vetorAluno[n].dataNascimento.dia > 31))
				{
					//printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 31 \n");
					return ERRO_CADASTRO_DATANASCIMENTO;
				}
				else
				{
					
				}
			}
			else
			{
				if(vetorAluno[n].dataNascimento.mes == 2)
				{
					if((vetorAluno[n].dataNascimento.dia <= 0 || vetorAluno[n].dataNascimento.dia >= 29))
					{
						//printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 28 para anos não bissextos e 29 para anos bissextos \n");
						return ERRO_CADASTRO_DATANASCIMENTO;
					}
					else
					{
						
					}
				}
				else
				{
					if((vetorAluno[n].dataNascimento.dia <= 0 || vetorAluno[n].dataNascimento.dia >= 30))
					{
						//printf("Data de nascimento inválida. O dia de nascimento no mês informado deve ser um número entre 1 e 30 \n");
						return ERRO_CADASTRO_DATANASCIMENTO;
					}
					else
					{
						
					}	
				}
			}	
		}							
		printf("CPF: (Somente números) \n");
		fflush(stdin);
		fgets(vetorAluno[n].CPF, 15, stdin);
					
		ln = strlen(vetorAluno[n].CPF) - 1; //comando para retirar o \n gerado pelo fgets
		if (vetorAluno[n].CPF[ln] == '\n')
		{
		    vetorAluno[n].CPF[ln] = '\0';	
		}  				  
		
		return CADASTRO_REALIZADO;
	}
void funcListarAluno(incluir vetorAluno[], int n)
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

int funcAtualizarAluno(incluir vetorAluno[], int n)
{
	int matricula, icont, posvetor = 0;
	printf("Informe a matrícula do aluno que deseja atualizar os dados. \n");
	scanf("%d", &matricula);
	
	for(icont = 0; icont < n; icont++)
	{
		if(vetorAluno[icont].matricula == matricula)
		{
			posvetor = icont;
		}		
	}
	
	if(posvetor == 0)
	{
		return ERRO_ATUALIZACAO_MATRICULA_INEXISTE;
	}
	else
	{
		printf("--- DADOS DO ALUNO DE MATRICULA: %d --- \n", matricula);
		printf("Nome: %s \n", vetorAluno[posvetor].nome);
		printf("Sexo: %c \n", vetorAluno[posvetor].sexo);
		printf("Data Nascimento: %d/%d/%d \n", vetorAluno[posvetor].dataNascimento.dia, vetorAluno[posvetor].dataNascimento.mes, vetorAluno[posvetor].dataNascimento.ano);
		printf("CPF: %s \n", vetorAluno[posvetor].CPF);
		printf("________________________________________________ \n");
		
		printf("--- ATUALIZAÇÃO DE DADOS DO ALUNO --- \n");
		printf("Nome do Aluno (até 50 caracteres): \n");
		fflush(stdin);
		fgets(vetorAluno[posvetor].nome, 51, stdin);
						
		size_t ln = strlen(vetorAluno[posvetor].nome) - 1; //comando para retirar o \n gerado pelo fgets
		if (vetorAluno[posvetor].nome[ln] == '\n')
		{
			vetorAluno[posvetor].nome[ln] = '\0';	
		}
						
		printf("Sexo: (M)Masculino/(F)Feminino \n");
		scanf("%c", &vetorAluno[posvetor].sexo);
		
		if((vetorAluno[posvetor].sexo == 'M') || (vetorAluno[posvetor].sexo == 'F'))
		{
			//printf("O sexo informado deve ser M para Masculino e F para Feminino.");											
		}
		else
		{
			return ERRO_ATUALIZACAO_SEXO;	
		}
					          
		printf("Dia do Nascimento: \n");
		scanf("%d", &vetorAluno[posvetor].dataNascimento.dia);
		printf("Mês do Nascimento: \n");
		scanf("%d", &vetorAluno[posvetor].dataNascimento.mes);
		printf("Ano do Nascimento: \n");
		scanf("%d", &vetorAluno[posvetor].dataNascimento.ano);
		
		if((vetorAluno[posvetor].dataNascimento.ano > 2021) || (vetorAluno[posvetor].dataNascimento.ano <= 1930))
		{	
			//printf("Ano de nascimento inválido. O ano de nascimento deve ser entre 1930 e 2021. \n");
			return ERRO_ATUALIZACAO_DATANASCIMENTO;
		}
		else
		{
			if((vetorAluno[posvetor].dataNascimento.mes == 1) || (vetorAluno[posvetor].dataNascimento.mes == 3) || (vetorAluno[posvetor].dataNascimento.mes == 5) || (vetorAluno[posvetor].dataNascimento.mes == 7) || (vetorAluno[posvetor].dataNascimento.mes == 8) || (vetorAluno[posvetor].dataNascimento.mes == 10) || (vetorAluno[posvetor].dataNascimento.mes == 12))
			{
				if((vetorAluno[posvetor].dataNascimento.dia <= 0 || vetorAluno[posvetor].dataNascimento.dia > 31))
				{
					return ERRO_ATUALIZACAO_DATANASCIMENTO;
				}
				else
				{
					
				}
			}
			else
			{
				if(vetorAluno[posvetor].dataNascimento.mes == 2)
				{
					if((vetorAluno[posvetor].dataNascimento.dia <= 0 || vetorAluno[posvetor].dataNascimento.dia >= 29))
					{
						return ERRO_ATUALIZACAO_DATANASCIMENTO;
					}
					else
					{
						
					}
				}
				else
				{
					if((vetorAluno[posvetor].dataNascimento.dia <= 0 || vetorAluno[posvetor].dataNascimento.dia >= 30))
					{
						return ERRO_ATUALIZACAO_DATANASCIMENTO;
					}
					else
					{
						
					}	
				}
			}	
		}			
		printf("CPF: (Somente números) \n");
		fflush(stdin);
		fgets(vetorAluno[posvetor].CPF, 12, stdin);	
		
		//PENDENTE VALIDAÇÃO DO CPF
		
		return ATUALIZACAO_REALIZADA;
	}
}

int funcExcluirAluno(incluir vetorAluno[], int n)
{
	int matricula, icont, posvetor, jcont;
	printf("Informe a matrícula do aluno que deseja atualizar os dados. \n");
	scanf("%d", &matricula);
	
	for(icont = 0; icont<n; icont++)
	{
		if(vetorAluno[icont].matricula == matricula)
		{
			posvetor = icont;
		}		
		else
		{
			posvetor = ERRO_EXCLUSAO_MATRICULA_INEXISTE;
		}
	}
	
	if(posvetor == ERRO_ATUALIZACAO_MATRICULA_INEXISTE )
	{
		return ERRO_ATUALIZACAO_MATRICULA_INEXISTE;
	}
	else
	{
		printf("--- ALUNO A SER EXCLUÍDO %d --- \n", matricula);
		printf("Nome: %s \n", vetorAluno[posvetor].nome);
		printf("Sexo: %c \n", vetorAluno[posvetor].sexo);
		printf("Data Nascimento: %d/%d/%d \n", vetorAluno[posvetor].dataNascimento.dia, vetorAluno[posvetor].dataNascimento.mes, vetorAluno[posvetor].dataNascimento.ano);
		printf("CPF: %s \n", vetorAluno[posvetor].CPF);
		printf("________________________________________________ \n");
		
		/*for(icont = posvetor, jcont = icont + 1; icont < n; icont++)
		{
			vetorAluno[posvetor].matricula = vetorAluno[jcont].matricula;
			strcpy(vetorAluno[posvetor].nome, vetorAluno[jcont].nome);
			vetorAluno[posvetor].sexo = vetorAluno[jcont].sexo;
			vetorAluno[posvetor].dataNascimento.dia = vetorAluno[jcont].dataNascimento.dia;
			vetorAluno[posvetor].dataNascimento.mes = vetorAluno[jcont].dataNascimento.mes;
			vetorAluno[posvetor].dataNascimento.ano = vetorAluno[jcont].dataNascimento.ano;
			strcpy(vetorAluno[posvetor].CPF, vetorAluno[jcont].CPF);		
		}*/
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
