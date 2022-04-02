#include <stdio.h>
#include <string.h>
//#define qtdedisc 2
#define CADASTRO_REALIZADO 1
#define ERRO_CADASTRO_CODIGO 6
#define ERRO_CADASTRO_SEMESTRE 7
#define ERRO_CADASTRO_PROFESSOR 8
#define ERRO_CADASTRO_DISCIPLINA 15
#define ERRO_EXCLUSAO_CODIGO_INEXISTE 16
#define ERRO_CODIGO_INEXISTE 17
#define EXCLUSAO_REALIZADA 12

/*typedef struct
{
  int codigo;
  char nome[51];
  int semestre;
  char professor[51];
}incluirdisc;

int funcMenuPrincipalDisc();
int funcIncluirDisc(incluirdisc *vetorDisc, int n, int opc);
void funcListarDisc(incluirdisc *vetorDisc, int n);
int funcAtualizarDisc(incluirdisc *vetorDisc, int n, int opc);
int funcExcluirDisc(incluirdisc *vetorDisc, int n);
int funcValidaCodigoDisc(incluirdisc *vetorDisc, int n);
int funcValidaSemestre(incluirdisc *vetorDisc, int n);
int funcValidaProf(incluirdisc *vetorDisc, int n, incluir *vetorProf, int m);*/


int mainDisciplina() 
{
	/*incluirdisc Disc;
	incluirdisc vetorDisc[qtdedisc];*/
	
	int icont = 0;	
	int opcao, retorno, retornoatualizacao, retornoexclusao;
	int  finalizar = 0;
		
	while(finalizar == 0)
	{
    //int funcMenuPrincipalDisc();
		opcao = funcMenuPrincipalDisc();
    
		if(opcao == 0)//OPÇÃO PARA SAIR DO MENU;
		{
			printf("Finalizando Menu Gestão de Disciplinas. \n");
			return 1;
		}
    

  	if(opcao == 1)//OPÇÃO PARA INCLUIR DISCIPLINA;
		{
      //int funcIncluirDisc(incluirdisc *vetorDisc, int n);
			retorno = funcIncluirDisc(vetorDisc, icont, opcao); 
			if(retorno == CADASTRO_REALIZADO )
			{
				printf(" \n Cadastro Realizado. \n \n");
				icont++;
			}
			else
			{
        if(retorno == ERRO_CADASTRO_DISCIPLINA)
				{
					printf("Erro no cadastro da disciplina. \n \n");
				}
				if(retorno == ERRO_CADASTRO_CODIGO)
				{
					printf("Erro no cadastro do código. \n \n");
				}
				if(retorno == ERRO_CADASTRO_SEMESTRE)
				{
					printf("Erro no cadastro de semestre. \n \n");	
				}
				if(retorno == ERRO_CADASTRO_PROFESSOR)
				{
					printf("Erro no cadastro de professor. \n \n");	
				}				
			}
		}

    
		if(opcao == 2) //OPÇÃO PARA LISTAR DISCIPLINAS
		{
      funcListarDisc(vetorDisc, icont);                 
    }

    
		if(opcao == 3) //OPÇÃO PARA ATUALIZAR DISCIPLINAS;
		{
      //int funcAtualizarDisc(incluir *vetorDisc, int n);
			retornoatualizacao = funcAtualizarDisc(vetorDisc, icont, opcao); 
      if(retornoatualizacao == CADASTRO_REALIZADO)
			{
				printf("Atualização realizada com sucesso. \n\n");
			}
			else
			{
        if(retorno == ERRO_CADASTRO_DISCIPLINA)
				{
					printf("Erro no cadastro da disciplina. \n \n");
				}
				if(retorno == ERRO_CADASTRO_CODIGO)
				{
					printf("Erro no cadastro do código. \n \n");
				}
				if(retorno == ERRO_CADASTRO_SEMESTRE)
				{
					printf("Erro no cadastro de semestre. \n \n");	
				}
				if(retorno == ERRO_CADASTRO_PROFESSOR)
				{
					printf("Erro no cadastro de professor. \n \n");	
				}
        if(retorno == ERRO_CODIGO_INEXISTE)
				{
					printf("Erro na atualização: código de disciplina informada não existe. \n");	
				}		
        
			}			
		}

    
		if(opcao == 4) //OPÇÃO PARA EXCLUIR DISCIPLINA;
		{
      //int funcExcluirDisc(incluir *vetorDisc, int n);
			retornoexclusao = funcExcluirDisc(vetorDisc, qtdedisc);
			if(retornoexclusao == EXCLUSAO_REALIZADA)
			{
				printf("Exclusão realizada com sucesso. \n\n");
			}
			else
			{
				if(retornoexclusao == ERRO_EXCLUSAO_CODIGO_INEXISTE)
				{
					printf("Erro na exclusão: código de disciplina informada não existe. \n");
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

int funcMenuPrincipalDisc() //FUNÇÃO DE MENU PRINCIPAL
{
	int opcao;
	printf("--- Gestão de Disciplinas --- \n");
	printf("0 - Sair \n");
	printf("1 - Incluir Disciplina \n");
	printf("2 - Listar Disciplina \n");
	printf("3 - Atualizar Disciplina \n");
	printf("4 - Excluir Disciplina \n");
	scanf("%d", &opcao);
	return opcao;
}

//FUNÇÃO PARA INCLUIR DISCIPLINA
int funcIncluirDisc(incluirdisc *vetorDisc, int n, int opc) 
{ 
  if(n >= qtdedisc) //CONDIÇÃO QUE VERIFICA SE A TENTATIVA DE INCLUSÃO EXCEDE O TAMANHO DO VETOR DISCIPLINAS.
  {
    printf("Não há mais vagas para disciplinas. \n");
    return ERRO_CADASTRO_CODIGO;
  }
  
	//printf("-- INCLUSÃO DE DISCIPLINAS --\n");
	printf("- DADOS DA DISCIPLINA - \n");
	if(opc == 1) //CONDIÇÃO QUE PERMITE A INFORMAÇÃO DO CÓDIGO SOMENTE QUANDO O USUÁRIO OPTA POR INCLUIR DISCIPLINA NO MENU.
  {
    printf("Código da Disciplina: \n");
	  scanf("%d", &vetorDisc[n].codigo);
	  getchar(); 
  }
 
  if (funcValidaCodigoDisc(vetorDisc, n) == 0) //FUNÇÃO PARA VALIDAR CODIGO
  {
    return ERRO_CADASTRO_CODIGO;
  }
			
	printf("Nome da Disciplina (até 50 caracteres): \n");
	fflush(stdin);
	fgets(vetorDisc[n].nome, 51, stdin);
					
	size_t ln = strlen(vetorDisc[n].nome) - 1; //comando para retirar o \n gerado pelo fgets
	if (vetorDisc[n].nome[ln] == '\n')
	{
		  vetorDisc[n].nome[ln] = '\0';	
	}
					
	printf("Semestre: \n");
	scanf("%d", &vetorDisc[n].semestre);
	getchar();

  if (funcValidaSemestre(vetorDisc, n) == 0) //FUNÇÃO PARA VALIDAR MATRÍCULA
  {
    return ERRO_CADASTRO_SEMESTRE;
  }
    
  return CADASTRO_REALIZADO;


 if (funcValidaProf(vetorDisc, n, vetorProf, qtdeprof) == 0) //FUNÇÃO PARA VALIDAR MATRÍCULA
  {
    return ERRO_CADASTRO_PROFESSOR;
  }

}

//FUNÇÃO PARA LISTAR DISCIPLINAS
void funcListarDisc(incluirdisc *vetorDisc, int n) 
{
  if(n == 0) //CONDIÇÃO QUE VERIFICA A EXISTÊNCIA DE ALGUMA DISCIPLINA NA LISTA.
  {
    printf(" \n A lista de Disciplinas está vazia. Primeiramente, você deve incluir uma Disciplina. \n \n");    
    
  }
  else //HÁ DISCIPLINAS NA LISTA.
  {
    int icont;
	  printf("\n--- LISTA DE DISCIPLINAS --- \n");
	  for (icont = 0; icont < n; icont++)
	  {
		  printf("Código: %d \n", vetorDisc[icont].codigo);
		  printf("Nome: %s \n", vetorDisc[icont].nome);
		  printf("Semestre: %d \n", vetorDisc[icont].semestre);		  
    }
    printf("________________________________________________ \n");    
  }
}		

int funcAtualizarDisc(incluirdisc *vetorDisc, int n, int opc) //FUNÇÃO PARA ATUALIZAR DISCIPLINAS
{
	int codigo, icont, posvetor = -2;
  
  if(n == 0) //CONDIÇÃO QUE VERIFICA A EXISTÊNCIA DE ALGUMA DISCIPLINA NA LISTA.
  {
    printf("\n A lista de Disciplinas está vazia. Primeiramente, você deve incluir uma Disciplina. \n \n");
    return ERRO_CADASTRO_CODIGO;
  }
  else //HÁ DISCIPLINAS NA LISTA.
  {
    printf("\n Informe o código da disciplina que deseja atualizar os dados. \n");
	  scanf("%d", &codigo);
    getchar();
    
    for(icont = 0; icont < n; icont++) // LAÇO PARA VERIFICAR SE O CÓDIGO DA DISCIPLINA
    {
    	if(vetorDisc[icont].codigo == codigo)
    	{
    		posvetor = icont;
    	}		
    }
    
    if(posvetor == -2)
	  {
		return ERRO_CODIGO_INEXISTE;
	  }
    else
    {
      return funcIncluirDisc(vetorDisc, posvetor, opc); 
    }    
  }  
}	   
		
//FUNÇÃO PARA EXCLUIR ALUNO
int funcExcluirDisc(incluirdisc *vetorDisc, int n)
{
	int codigo, icont, posvetor = -2, jcont;
	printf("Informe o código da matricula que deseja atualizar os dados. \n ");
	scanf("%d", &codigo);
  getchar();
	
	for(icont = 0; icont < n; icont++)
	{
		if(vetorDisc[icont].codigo == codigo)
		{
			posvetor = icont;
		}		
	}
	
	if(posvetor == -2 )
	{
		return ERRO_EXCLUSAO_CODIGO_INEXISTE;
	}
	else
	{
		printf("--- DISCIPLINA A SER EXCLUÍDA %d --- \n", codigo);
		printf("Nome: %s \n", vetorDisc[posvetor].nome);
		printf("Semestre: %d \n", vetorDisc[posvetor].semestre);
		
		printf("________________________________________________ \n");
			
		printf("Excluindo dados... \n");
		
		vetorDisc[posvetor].codigo = 0;		
		strcpy(vetorDisc[posvetor].nome, "0");
		vetorDisc[posvetor].semestre = '0';		

		return EXCLUSAO_REALIZADA;	
	}	
}

//FUNÇÃO PARA VALIDAR MATRÍCULA
int funcValidaCodigoDisc(incluirdisc *vetorDisc, int n)
{
  if(vetorDisc[n].codigo <= 0)
	{
    printf("\n O número de código da disciplina deve ser maior que 0. \n \n");
		return 0;
	}  
}

int funcValidaSemestre(incluirdisc *vetorDisc, int n)
{
  if(vetorDisc[n].semestre <= 0)
	{
    printf("\n O número do semestre da disciplina deve ser maior que 0. \n \n");
		return 0;
  }
}

//FUNÇÃO PARA VALIDAR PROFESSOR
int funcValidaProf(incluirdisc *vetorDisc, int n, incluir *vetorProf, int m)
{
  int posvetor = -2;
  for(int icont = 0; icont < m || posvetor != -2; icont++)
  {    
    if(strcmp(vetorDisc[n].nome, vetorProf[icont].nome) == 0)
  	{
      posvetor = 1;
  	}  
  }

  if(posvetor == -2)
  {
    printf("\nO nome informado do professor não consta na lista de professores. O nome do professor da matrícula precisa constar na lista de professores. \n \n");
      return 0;
  }
}
    
  



