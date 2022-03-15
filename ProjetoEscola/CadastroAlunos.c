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
	int opcao, icont, jcont, lista = 0, finalizar = 0, matricula, posvetor, naluno, validamatricula = 0, validacpf = 0, validadatadenascimento = 0, validasexo = 0, somacpf = 0;
	incluir vetorAlunos[qtdealunos]; //inicialmente definido em 2.
	     
  while(finalizar == 0)
  {
    printf("--- Cadastro de Alunos --- \n");
    printf("0 - Sair \n");
    printf("1 - Incluir Aluno \n");
    printf("2 - Listar Alunos \n");
    printf("3 - Atualizar Aluno \n");
    printf("4 - Excluir Aluno \n \n");
    scanf("%d", &opcao);
    
    if(opcao == 0)
    {
      finalizar = 1;
      printf("Finalizando Cadastro de Alunos. \n");    	
    }
    if(opcao == 1)
    {
      printf("-- INCLUSÃO DE ALUNOS --\n");
      for(icont = 0; icont < qtdealunos; icont++)
      {
        naluno = icont + 1;
        printf("- DADOS DO ALUNO %d - \n", naluno);
        
        while(validamatricula == 0)
        {
          printf("Matricula do Aluno: \n");
          scanf("%d", &vetorAlunos[icont].matricula);
          getchar();
          
          if(vetorAlunos[icont].matricula <= 0)
          {
            printf("Matrícula inválida. Este dado deve ser um número inteiro e positivo.  \n");
            printf("Informe novamente a ");	
          }
          else
          {
            validamatricula = 1;
          }
        }
            
        printf("Nome do Aluno (até 50 caracteres): \n");
        fflush(stdin);
        fgets(vetorAlunos[icont].nome, 51, stdin);
        
        size_t ln = strlen(vetorAlunos[icont].nome) - 1; //comando para retirar o \n gerado pelo fgets
        if (vetorAlunos[icont].nome[ln] == '\n')
        {
          vetorAlunos[icont].nome[ln] = '\0';	
        }
        
        while(validasexo == 0)
        {
          printf("Sexo: (M)Masculino/(F)Feminino \n");
          scanf("%c", &vetorAlunos[icont].sexo);
          getchar();
          
          if((vetorAlunos[icont].sexo == 'M') || (vetorAlunos[icont].sexo == 'F'))
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
                            
        while(validadatadenascimento == 0)
        {
          printf("Dia do Nascimento: \n");
          scanf("%d", &vetorAlunos[icont].dataNascimento.dia);
          printf("Mês do Nascimento: \n");
          scanf("%d", &vetorAlunos[icont].dataNascimento.mes);
          printf("Ano do Nascimento: \n");
          scanf("%d", &vetorAlunos[icont].dataNascimento.ano);
          
          if((vetorAlunos[icont].dataNascimento.mes == 1) || (vetorAlunos[icont].dataNascimento.mes == 3) || (vetorAlunos[icont].dataNascimento.mes == 5) || (vetorAlunos[icont].dataNascimento.mes == 7) || (vetorAlunos[icont].dataNascimento.mes == 8) || (vetorAlunos[icont].dataNascimento.mes == 10) || (vetorAlunos[icont].dataNascimento.mes == 12))
          {
            if((vetorAlunos[icont].dataNascimento.dia <= 0 || vetorAlunos[icont].dataNascimento.dia > 31))
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
            if(vetorAlunos[icont].dataNascimento.mes == 2)
            {
              if((vetorAlunos[icont].dataNascimento.dia <= 0 || vetorAlunos[icont].dataNascimento.dia >= 29))
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
              if((vetorAlunos[icont].dataNascimento.dia <= 0 || vetorAlunos[icont].dataNascimento.dia >= 30))
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
        
        //while(validacpf == 0)
        //{
          printf("CPF: (xxx.xxx.xxx-xx) \n");
          fflush(stdin);
          fgets(vetorAlunos[icont].CPF, 15, stdin);
          
          size_t ln = strlen(vetorAlunos[icont].CPF) - 1; //comando para retirar o \n gerado pelo fgets
              if (vetorAlunos[icont].CPF[ln] == '\n')
          {
                vetorAlunos[icont].CPF[ln] = '\0';	
          }					
          
          /*for(jcont = 0; vetorAlunos[jcont].CPF != '\0'; jcont++)
          {
            somacpf = somacpf + 1;
          }
          somacpf = somacpf - 1;
          
          if(somacpf < 14)
          {
            printf("CPF inválido. Este dado deve ter 15 caracteres. \n");
            printf("Informe novamente o");	
          }
          else
          {
            validacpf = 1;
          }*/	        	  	
        //}								  
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
        printf("\n--- LISTA DE ALUNOS --- \n \n");
            for (icont = 0; icont < qtdealunos; icont++)
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
    if(opcao == 3)
    {
      if(lista == 0)
      {
        printf("\n A lista está vazia. \n");
        printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
      }
      else
      {
        printf("Informe a matrícula do Aluno que deseja atualizar. \n");
        scanf("%d", &matricula);
        
        for(icont = 0; icont<qtdealunos; icont++)
        {
          if(vetorAlunos[icont].matricula == matricula)
          {
            posvetor = icont;
          }
        }
        
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
          
        printf("Sexo: M/F \n");
        scanf("%c", &vetorAlunos[posvetor].sexo);
              
            printf("Dia do Nascimento: \n");
        scanf("%d", &vetorAlunos[posvetor].dataNascimento.dia);
        printf("Mês do Nascimento: \n");
        scanf("%d", &vetorAlunos[posvetor].dataNascimento.mes);
        printf("Ano do Nascimento: \n");
        scanf("%d", &vetorAlunos[posvetor].dataNascimento.ano);
          
        printf("CPF: (xxx.xxx.xxx-xx) \n");
        fflush(stdin);
        fgets(vetorAlunos[posvetor].CPF, 15, stdin);		
      }
    }
    if(opcao == 4)
    {
      if(lista == 0)
      {
        printf("\n A lista está vazia. \n");
        printf("Primeiramente, você deve inserir/incluir alunos no sistema. \n \n");
      }
      else
      {
        printf("Informe a matrícula do Aluno que deseja EXCLUIR. \n");
        scanf("%d", &matricula);
        
        for(icont = 0; icont<qtdealunos; icont++)
        {
          if(vetorAlunos[icont].matricula == matricula)
          {
            posvetor = icont;
          }
        }
        
        printf("--- ALUNO A SER EXCLUÍDO %d --- \n", matricula);
        printf("Nome: %s \n", vetorAlunos[posvetor].nome);
        printf("Sexo: %c \n", vetorAlunos[posvetor].sexo);
        printf("Data Nascimento: %d/%d/%d \n", vetorAlunos[posvetor].dataNascimento.dia, vetorAlunos[posvetor].dataNascimento.mes, vetorAlunos[posvetor].dataNascimento.ano);
        printf("CPF: %s \n", vetorAlunos[posvetor].CPF);
        printf("________________________________________________ \n");
        
        printf("Excluindo dados... \n");
                  
        /*vetorAlunos[posvetor].nome = "Aluno excluído.";
        vetorAlunos[posvetor].dataNascimento.dia = 0;
        vetorAlunos[posvetor].dataNascimento.mes = 0;
        vetorAlunos[posvetor].dataNascimento.ano = 0;
        vetorAlunos[posvetor].CPF = "000.000.000-00";*/			
        
        printf("Aluno excluído. \n");		
      }
    }
    if(opcao > 5)
    {
      printf("Opção inválida. \n");
    }    
        
  }
  return 0;
}
    
    
		



