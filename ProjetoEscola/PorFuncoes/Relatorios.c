#include <stdio.h>
#include <string.h>

int mainRelatorios() 
{
	/*incluir Aluno;
	incluir vetorAluno[qtdealuno];*/
	
	//int icont = 0;	
	int opcao, retorno;
	int  finalizar = 0;
		
	while(finalizar == 0)
	{
    //int funcMenuPrincipalAluno();
		opcao = funcMenuRelatorios();
    
		if(opcao == 0)//OPÇÃO PARA SAIR DO MENU;
		{
			printf("Finalizando Menu Gestão de Alunos. \n");
			return 1;
		}    

  	if(opcao == 1)//OPÇÃO PARA LISTAR ALUNO
		{
      //int funcIncluirAluno(incluir *vetorAluno, int n);
			printf("Por favor, dirija-se ao Menu de Gestão de Alunos e opte por Listar Alunos. \n");
      return 1;
    }
			    
		if(opcao == 2) //OPÇÃO PARA LISTAR PROFESSORES
		{
      printf("Por favor, dirija-se ao Menu de Gestão de Professores e opte por Listar Professores.\n");
      return 1;
    }
    
		if(opcao == 3) //OPÇÃO PARA LISTAR DISCIPLINAS;
		{
      printf("Por favor, dirija-se ao Menu de Gestão de Disciplinas e opte por Listar Disciplinas. \n" );
      return 1;  
    }
			    
		if(opcao == 4) //OPÇÃO PARA LISTAR UMA DISCIPLINA DE OS ALUNOS MATRICULADOS;
		{      
			printf("Função ainda não implementada. \n");		
      return 1;
		}
    
		if(opcao == 5) //OPÇÃO PARA LISTAR ALUNOS POR SEXO
		{
      funcListarAlunoPorSexo(vetorAluno, qtdealuno);
  	}
      
      if(opcao == 6) //OPÇÃO PARA LISTAR ALUNOS POR NOME
		{
			funcListarAlunoPorNome(vetorAluno, qtdealuno);
		}
      
      if(opcao == 7) //OPÇÃO PARA LISTAR ALUNOS POR DATA DE NASCIMENTO
		{
      funcListarAlunoPorDataDeNascimento(vetorAluno, qtdealuno);
		}
      
      if(opcao == 8) //OPÇÃO PARA LISTAR PROFESSORES POR SEXO
		{
			funcListarProfessorPorSexo(vetorProf, qtdeprof);
  	}		
      
      if(opcao == 9) //OPÇÃO PARA LISTAR PROFESSORES POR NOME
		{
			funcListarProfessorPorNome(vetorProf, qtdeprof);
		}
      
      if(opcao == 10) //OPÇÃO PARA LISTAR PROFESSORES POR DATA DE NASCIMENTO
		{
			funcListarProfessorPorDataDeNascimento(vetorProf, qtdeprof);
		}
      
      if(opcao == 11) //LISTAR ANIVERSARIANTES DO MÊS
		{
			funcListarAniversarianteDoMes(vetorProf, vetorAluno, qtdealuno, qtdeprof);
		}
      
      if(opcao == 12) //BUSCAR PROFESSORES E ALUNOS
		{
			printf("Função ainda não implementada. \n");
      return 1;
		}
      
      if(opcao == 13) //LISTAR ALUNOS MATRICULADOS EM TRÊS DISCIPLINAS
		{
			printf("Função ainda não implementada \n");
      return 1;
		}
      
      if(opcao == 14) //LISTAR DISCIPLINAS COM MAIS DE 40 VAGAS (CONTENDO NOME DO PROFESSOR)
		{
			printf("Função ainda não implementada. \n");
      return 1;
		}

      if(opcao > 14)
		{
			printf("Opção inexistente. \n");
		}      
	}
    return 0;
}

//DESCRIÇÃO DE FUNÇÕES

int funcMenuRelatorios() //FUNÇÃO DE MENU PRINCIPAL
{
	int opcao;
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
	scanf("%d", &opcao);
	return opcao;
}

/*void funcListarAluno(incluir *vetorAluno, int n)
{
  
}
void funcListarProfessores(incluir *vetorProf, int n)
{
  
}
void funcListarDisciplinas(incluirdisc *vetorDisc, int n)
{
  
}*/
//void
void funcListarAlunoPorSexo(incluir *vetorAluno, int n ) // FUNÇÃO PARA LISTAR ALUNOS POR SEXO
{
  int icont, jcont;
  if(vetorAluno[0].matricula <= 0 )
  {
    printf("\n A lista de Alunos está vazia. \n");
    printf("Primeiramente, você deve inserir/incluir um aluno no sistema. \n \n");
  }
  else
  {
    for (icont = 0; icont<n; icont++) 
    {
      for(jcont = icont; jcont<n; jcont++)            
      {
        if(vetorAluno[icont].sexo > vetorAluno[jcont].sexo)
        {
          vetorAuxAlunosProfessores.matricula = vetorAluno[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorAluno[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorAluno[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorAluno[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorAluno[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorAluno[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorAluno[icont].CPF);
                              
          vetorAluno[icont].matricula = vetorAluno[jcont].matricula;
          strcpy(vetorAluno[icont].nome, vetorAluno[jcont].nome);
          vetorAluno[icont].sexo = vetorAluno[jcont].sexo;
          vetorAluno[icont].dataNascimento.dia = vetorAluno[jcont].dataNascimento.dia;
          vetorAluno[icont].dataNascimento.mes = vetorAluno[jcont].dataNascimento.mes;
          vetorAluno[icont].dataNascimento.ano = vetorAluno[jcont].dataNascimento.ano;
          strcpy(vetorAluno[icont].CPF, vetorAluno[jcont].CPF);
          
          vetorAluno[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorAluno[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorAluno[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorAluno[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
          vetorAluno[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorAluno[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorAluno[jcont].CPF, vetorAuxAlunosProfessores.CPF);
        }                
      }
    }
    
    printf("\n--- LISTA DE ALUNOS ORDENADOS POR SEXO--- \n \n");
    for(icont = 0; icont < n; icont++)
    {       
      printf("Sexo: %c \n", vetorAluno[icont].sexo);
      printf("Matrícula: %d \n", vetorAluno[icont].matricula);
      printf("Nome: %s \n", vetorAluno[icont].nome);
      printf("Data Nascimento: %d/%d/%d \n", vetorAluno[icont].dataNascimento.dia, vetorAluno[icont].dataNascimento.mes, vetorAluno[icont].dataNascimento.ano);
		  printf("CPF: %s \n \n", vetorAluno[icont].CPF);     
    }          
  }        
  printf(" \n________________________________________________ \n");          
}


void funcListarAlunoPorNome(incluir *vetorAluno, int n) //FUNÇÃO PARA LISTAR ALUNOS POR NOME
{
  int icont, jcont;
  if(vetorAluno[0].matricula <= 0 )
  {
    printf("\n A lista de Alunos está vazia. \n");
    printf("Primeiramente, você deve inserir/incluir um aluno no sistema. \n \n");
  }
  else
  {
    for (icont = 0; icont<n; icont++) 
    {
      for(jcont = icont+1; jcont<n; jcont++)            
      {
        if (strcmp(vetorAluno[icont].nome,vetorAluno[jcont].nome) > 0)
        {
          vetorAuxAlunosProfessores.matricula = vetorAluno[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorAluno[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorAluno[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorAluno[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorAluno[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorAluno[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorAluno[icont].CPF);
                              
          vetorAluno[icont].matricula = vetorAluno[jcont].matricula;
          strcpy(vetorAluno[icont].nome, vetorAluno[jcont].nome);
          vetorAluno[icont].sexo = vetorAluno[jcont].sexo;
          vetorAluno[icont].dataNascimento.dia = vetorAluno[jcont].dataNascimento.dia;
          vetorAluno[icont].dataNascimento.mes = vetorAluno[jcont].dataNascimento.mes;
          vetorAluno[icont].dataNascimento.ano = vetorAluno[jcont].dataNascimento.ano;
          strcpy(vetorAluno[icont].CPF, vetorAluno[jcont].CPF);
          
          vetorAluno[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorAluno[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorAluno[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorAluno[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
          vetorAluno[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorAluno[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorAluno[jcont].CPF, vetorAuxAlunosProfessores.CPF);
        }                
      }
    }
    
    printf("\n--- LISTA DE ALUNOS ORDENADOS POR NOME--- \n \n");
    for(icont = 0; icont < n; icont++)
    {      
      printf("Nome: %s \n", vetorAluno[icont].nome);
      printf("Sexo: %c \n", vetorAluno[icont].sexo);
      printf("Matrícula: %d \n", vetorAluno[icont].matricula);      
      printf("Data Nascimento: %d/%d/%d \n", vetorAluno[icont].dataNascimento.dia, vetorAluno[icont].dataNascimento.mes, vetorAluno[icont].dataNascimento.ano);
		  printf("CPF: %s \n \n", vetorAluno[icont].CPF);     
    }          
  }        
  printf(" \n________________________________________________ \n");          
}

void funcListarAlunoPorDataDeNascimento(incluir *vetorAluno, int n) //FUNÇÃO PARA LISTAR ALUNOS POR DATA DE NASCIMENTO
{
  int icont, jcont;
  if(vetorAluno[0].matricula <= 0 )
  {
    printf("\n A lista de Alunos está vazia. \n");
    printf("Primeiramente, você deve inserir/incluir um aluno no sistema. \n \n");
  }
  else
  {
    for (icont = 0; icont<n; icont++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O ANO.
    {
      for(jcont= icont; jcont < n; jcont++)            
      {
        if (vetorAluno[icont].dataNascimento.ano > vetorAluno[jcont].dataNascimento.ano)
        {
          vetorAuxAlunosProfessores.matricula = vetorAluno[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorAluno[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorAluno[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorAluno[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorAluno[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorAluno[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorAluno[icont].CPF);
                              
          vetorAluno[icont].matricula = vetorAluno[jcont].matricula;
          strcpy(vetorAluno[icont].nome, vetorAluno[jcont].nome);
          vetorAluno[icont].sexo = vetorAluno[jcont].sexo;
          vetorAluno[icont].dataNascimento.dia = vetorAluno[jcont].dataNascimento.dia;
          vetorAluno[icont].dataNascimento.mes = vetorAluno[jcont].dataNascimento.mes;
          vetorAluno[icont].dataNascimento.ano = vetorAluno[jcont].dataNascimento.ano;
          strcpy(vetorAluno[icont].CPF, vetorAluno[jcont].CPF);
          
          vetorAluno[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorAluno[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorAluno[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorAluno[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
          vetorAluno[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorAluno[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorAluno[jcont].CPF, vetorAuxAlunosProfessores.CPF);                    
        }
      }
    }  

    for (icont = 0; icont<n; icont++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O MES
    {
      for(jcont= icont; jcont < n; jcont++)            
      {
        if ((vetorAluno[icont].dataNascimento.mes > vetorAluno[jcont].dataNascimento.mes) && (vetorAluno[icont].dataNascimento.ano == vetorAluno[jcont].dataNascimento.ano))
        {
          vetorAuxAlunosProfessores.matricula = vetorAluno[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorAluno[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorAluno[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorAluno[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorAluno[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorAluno[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorAluno[icont].CPF);
                              
          vetorAluno[icont].matricula = vetorAluno[jcont].matricula;
          strcpy(vetorAluno[icont].nome, vetorAluno[jcont].nome);
          vetorAluno[icont].sexo = vetorAluno[jcont].sexo;
          vetorAluno[icont].dataNascimento.dia = vetorAluno[jcont].dataNascimento.dia;
          vetorAluno[icont].dataNascimento.mes = vetorAluno[jcont].dataNascimento.mes;
          vetorAluno[icont].dataNascimento.ano = vetorAluno[jcont].dataNascimento.ano;
          strcpy(vetorAluno[icont].CPF, vetorAluno[jcont].CPF);
          
          vetorAluno[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorAluno[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorAluno[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorAluno[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
          vetorAluno[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorAluno[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorAluno[jcont].CPF, vetorAuxAlunosProfessores.CPF);                    
        }
      }
    }
  
    for (icont = 0; icont<n; icont++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O DIA
    {
      for(jcont = icont; jcont < n; jcont++)            
      {
        if ((vetorAluno[icont].dataNascimento.dia > vetorAluno[jcont].dataNascimento.dia) && (vetorAluno[icont].dataNascimento.mes == vetorAluno[jcont].dataNascimento.mes) && (vetorAluno[icont].dataNascimento.dia == vetorAluno[jcont].dataNascimento.dia))
        {
          vetorAuxAlunosProfessores.matricula = vetorAluno[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorAluno[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorAluno[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorAluno[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorAluno[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorAluno[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorAluno[icont].CPF);
                              
          vetorAluno[icont].matricula = vetorAluno[jcont].matricula;
          strcpy(vetorAluno[icont].nome, vetorAluno[jcont].nome);
          vetorAluno[icont].sexo = vetorAluno[jcont].sexo;
          vetorAluno[icont].dataNascimento.dia = vetorAluno[jcont].dataNascimento.dia;
          vetorAluno[icont].dataNascimento.mes = vetorAluno[jcont].dataNascimento.mes;
          vetorAluno[icont].dataNascimento.ano = vetorAluno[jcont].dataNascimento.ano;
          strcpy(vetorAluno[icont].CPF, vetorAluno[jcont].CPF);
          
          vetorAluno[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorAluno[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorAluno[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorAluno[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.dia;
          vetorAluno[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorAluno[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorAluno[jcont].CPF, vetorAuxAlunosProfessores.CPF);                    
        }
      }
    }
  
    printf("\n--- LISTA DE ALUNOS ORDENADOS POR DATA DE NASCIMENTO --- \n \n");
    for(icont = 0; icont < n; icont++)
    {      
      printf("Nome: %s \n", vetorAluno[icont].nome);
      printf("Sexo: %c \n", vetorAluno[icont].sexo);
      printf("Matrícula: %d \n", vetorAluno[icont].matricula);      
      printf("Data Nascimento: %d/%d/%d \n", vetorAluno[icont].dataNascimento.dia, vetorAluno[icont].dataNascimento.mes, vetorAluno[icont].dataNascimento.ano);
		  printf("CPF: %s \n \n", vetorAluno[icont].CPF);     
    }     
  }
  printf("____________________________________________________ \n"); 
}

void funcListarProfessorPorSexo(incluir *vetorProf, int n) // FUNÇÃO PARA LISTAR PROFESSORES POR SEXO
{
  int icont, jcont;
  if(vetorProf[0].matricula <= 0 )
  {
    printf("\n A lista de Professores está vazia. \n");
    printf("Primeiramente, você deve inserir/incluir um professor no sistema. \n \n");
  }
  else
  {
    for (icont = 0; icont<n; icont++) 
    {
      for(jcont = icont; jcont<n; jcont++)            
      {
        if(vetorProf[icont].sexo > vetorProf[jcont].sexo)
        {
          vetorAuxAlunosProfessores.matricula = vetorProf[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorProf[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorProf[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorProf[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorProf[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorProf[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorProf[icont].CPF);
                              
          vetorProf[icont].matricula = vetorProf[jcont].matricula;
          strcpy(vetorProf[icont].nome, vetorProf[jcont].nome);
          vetorProf[icont].sexo = vetorProf[jcont].sexo;
          vetorProf[icont].dataNascimento.dia = vetorProf[jcont].dataNascimento.dia;
          vetorProf[icont].dataNascimento.mes = vetorProf[jcont].dataNascimento.mes;
          vetorProf[icont].dataNascimento.ano = vetorProf[jcont].dataNascimento.ano;
          strcpy(vetorProf[icont].CPF, vetorProf[jcont].CPF);
          
          vetorProf[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorProf[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorProf[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorProf[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorProf[jcont].CPF, vetorAuxAlunosProfessores.CPF);
        }                
      }
    }
    
    printf("\n--- LISTA DE PROFESSORES ORDENADOS POR SEXO --- \n \n");
    for(icont = 0; icont < n; icont++)
    {       
      printf("Sexo: %c \n", vetorProf[icont].sexo);
      printf("Matrícula: %d \n", vetorProf[icont].matricula);
      printf("Nome: %s \n", vetorProf[icont].nome);
      printf("Data Nascimento: %d/%d/%d \n", vetorProf[icont].dataNascimento.dia, vetorProf[icont].dataNascimento.mes, vetorProf[icont].dataNascimento.ano);
		  printf("CPF: %s \n \n", vetorProf[icont].CPF);     
    }          
  }        
  printf(" \n________________________________________________ \n");   
}

void funcListarProfessorPorNome(incluir *vetorProf, int n) //FUNÇÃO PARA LISTAR PROFESSORES POR NOME
{
  int icont, jcont;
  if(vetorProf[0].matricula <= 0 )
  {
    printf("\n A lista de Professores está vazia. \n");
    printf("Primeiramente, você deve inserir/incluir um professor no sistema. \n \n");
  }
  else
  {
    for (icont = 0; icont<n; icont++) 
    {
      for(jcont = icont+1; jcont<n; jcont++)            
      {
        if (strcmp(vetorProf[icont].nome,vetorProf[jcont].nome) > 0)
        {
          vetorAuxAlunosProfessores.matricula = vetorProf[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorProf[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorProf[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorProf[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorProf[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorProf[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorProf[icont].CPF);
                              
          vetorProf[icont].matricula = vetorProf[jcont].matricula;
          strcpy(vetorProf[icont].nome, vetorProf[jcont].nome);
          vetorProf[icont].sexo = vetorProf[jcont].sexo;
          vetorProf[icont].dataNascimento.dia = vetorProf[jcont].dataNascimento.dia;
          vetorProf[icont].dataNascimento.mes = vetorProf[jcont].dataNascimento.mes;
          vetorProf[icont].dataNascimento.ano = vetorProf[jcont].dataNascimento.ano;
          strcpy(vetorProf[icont].CPF, vetorProf[jcont].CPF);
          
          vetorProf[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorProf[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorProf[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorProf[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorProf[jcont].CPF, vetorAuxAlunosProfessores.CPF);
        }                
      }
    }
    
    printf("\n--- LISTA DE PROFESSORES ORDENADOS POR NOME--- \n \n");
    for(icont = 0; icont < n; icont++)
    {      
      printf("Nome: %s \n", vetorProf[icont].nome);      
      printf("Matrícula: %d \n", vetorProf[icont].matricula);
      printf("Sexo: %c \n", vetorProf[icont].sexo);
      printf("Data Nascimento: %d/%d/%d \n", vetorProf[icont].dataNascimento.dia, vetorProf[icont].dataNascimento.mes, vetorProf[icont].dataNascimento.ano);
		  printf("CPF: %s \n \n", vetorProf[icont].CPF);     
    }          
  }        
  printf(" \n________________________________________________ \n");  
}

void funcListarProfessorPorDataDeNascimento(incluir *vetorProf, int n) //FUNÇÃO PARA LISTAR PROFESSORES POR DATA DE NASCIMENTO
{
  int icont, jcont;
  if(vetorProf[0].matricula < 0 )
  {
    printf("\n A lista de Professores está vazia. \n");
    printf("Primeiramente, você deve inserir/incluir um professor no sistema. \n \n");
  }
  else
  {
    for (icont = 0; icont<n; icont++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O ANO.
    {
      for(jcont= icont; jcont < n; jcont++)            
      {
        if (vetorProf[icont].dataNascimento.ano > vetorProf[jcont].dataNascimento.ano)
        {
          vetorAuxAlunosProfessores.matricula = vetorProf[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorProf[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorProf[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorProf[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorProf[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorProf[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorProf[icont].CPF);
                              
          vetorProf[icont].matricula = vetorProf[jcont].matricula;
          strcpy(vetorProf[icont].nome, vetorProf[jcont].nome);
          vetorProf[icont].sexo = vetorProf[jcont].sexo;
          vetorProf[icont].dataNascimento.dia = vetorProf[jcont].dataNascimento.dia;
          vetorProf[icont].dataNascimento.mes = vetorProf[jcont].dataNascimento.mes;
          vetorProf[icont].dataNascimento.ano = vetorProf[jcont].dataNascimento.ano;
          strcpy(vetorProf[icont].CPF, vetorProf[jcont].CPF);
          
          vetorProf[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorProf[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorProf[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorProf[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorProf[jcont].CPF, vetorAuxAlunosProfessores.CPF);                    
        }
      }
    }  

    for (icont = 0; icont<n; icont++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O MES
    {
      for(jcont= icont; jcont < n; jcont++)            
      {
        if ((vetorProf[icont].dataNascimento.mes > vetorProf[jcont].dataNascimento.mes) && (vetorProf[icont].dataNascimento.ano == vetorProf[jcont].dataNascimento.ano))
        {
          vetorAuxAlunosProfessores.matricula = vetorProf[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorProf[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorProf[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorProf[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorProf[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorProf[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorProf[icont].CPF);
                              
          vetorProf[icont].matricula = vetorProf[jcont].matricula;
          strcpy(vetorProf[icont].nome, vetorProf[jcont].nome);
          vetorProf[icont].sexo = vetorProf[jcont].sexo;
          vetorProf[icont].dataNascimento.dia = vetorProf[jcont].dataNascimento.dia;
          vetorProf[icont].dataNascimento.mes = vetorProf[jcont].dataNascimento.mes;
          vetorProf[icont].dataNascimento.ano = vetorProf[jcont].dataNascimento.ano;
          strcpy(vetorProf[icont].CPF, vetorProf[jcont].CPF);
          
          vetorProf[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorProf[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorProf[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorProf[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorProf[jcont].CPF, vetorAuxAlunosProfessores.CPF);                    
        }
      }
    }
  
    for (icont = 0; icont<n; icont++) // LAÇO PARA DEFINIR A ORDEM DE ACORDO COM O DIA
    {
      for(jcont = icont; jcont < n; jcont++)            
      {
        if ((vetorProf[icont].dataNascimento.dia > vetorProf[jcont].dataNascimento.dia) && (vetorProf[icont].dataNascimento.mes == vetorProf[jcont].dataNascimento.mes) && (vetorProf[icont].dataNascimento.dia == vetorProf[jcont].dataNascimento.dia))
        {
          vetorAuxAlunosProfessores.matricula = vetorProf[icont].matricula;
          strcpy(vetorAuxAlunosProfessores.nome, vetorProf[icont].nome);
          vetorAuxAlunosProfessores.sexo = vetorProf[icont].sexo;
          vetorAuxAlunosProfessores.dataNascimento.dia = vetorProf[icont].dataNascimento.dia;
          vetorAuxAlunosProfessores.dataNascimento.mes = vetorProf[icont].dataNascimento.mes;
          vetorAuxAlunosProfessores.dataNascimento.ano = vetorProf[icont].dataNascimento.ano;
          strcpy(vetorAuxAlunosProfessores.CPF, vetorProf[icont].CPF);
                              
          vetorProf[icont].matricula = vetorProf[jcont].matricula;
          strcpy(vetorProf[icont].nome, vetorProf[jcont].nome);
          vetorProf[icont].sexo = vetorProf[jcont].sexo;
          vetorProf[icont].dataNascimento.dia = vetorProf[jcont].dataNascimento.dia;
          vetorProf[icont].dataNascimento.mes = vetorProf[jcont].dataNascimento.mes;
          vetorProf[icont].dataNascimento.ano = vetorProf[jcont].dataNascimento.ano;
          strcpy(vetorProf[icont].CPF, vetorProf[jcont].CPF);
          
          vetorProf[jcont].matricula = vetorAuxAlunosProfessores.matricula;
          strcpy(vetorProf[jcont].nome, vetorAuxAlunosProfessores.nome);
          vetorProf[jcont].sexo = vetorAuxAlunosProfessores.sexo;
          vetorProf[jcont].dataNascimento.dia = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.mes = vetorAuxAlunosProfessores.dataNascimento.mes;
          vetorProf[jcont].dataNascimento.ano = vetorAuxAlunosProfessores.dataNascimento.ano;
          strcpy(vetorProf[jcont].CPF, vetorAuxAlunosProfessores.CPF);                    
        }
      }
    }
  
    printf("\n--- LISTA DE PROFESSORES ORDENADOS POR DATA DE NASCIMENTO --- \n \n");
    for(icont = 0; icont < n; icont++)
    {      
      printf("Nome: %s \n", vetorProf[icont].nome);      
      printf("Matrícula: %d \n", vetorProf[icont].matricula);
      printf("Sexo: %c \n", vetorProf[icont].sexo);
      printf("Data Nascimento: %d/%d/%d \n", vetorProf[icont].dataNascimento.dia, vetorProf[icont].dataNascimento.mes, vetorProf[icont].dataNascimento.ano);
		  printf("CPF: %s \n \n", vetorProf[icont].CPF);     
    }     
  }
  printf("____________________________________________________ \n");
  
}

void funcListarAniversarianteDoMes(incluir *vetorProf, incluir *vetorAluno, int n, int m) //FUNÇÃO PARA LISTAR ANIVERSARIANTES DO MÊS
{
  int prints = 0, mes, icont;
  printf("Informe o mês que deseja verificar os aniversariantes. \n");
  scanf("%d", &mes);
  printf(" \n--ANIVERSARIANTES DO MÊS %d-- \n", mes);          
  for(icont = 0; icont < n; icont++)
  {
    if(vetorAluno[icont].dataNascimento.mes == mes)
    {
      printf("Aluno: %s \n", vetorAluno[icont].nome);
      prints++;
    }   
  }
  for(icont = 0; icont < m; icont++)
  {
    if(vetorProf[icont].dataNascimento.mes == mes)
    {
      printf("Professor: %s \n", vetorProf[icont].nome);
      prints++;
    }   
  }    
  if(prints == 0)
  {
    printf("Não há aniversariantes neste mês ou a lista professores e/ou alunos estão vazias.\n ");            
  }
  printf("_______________________________________________________ \n \n");  
}

//void
//void
//void
