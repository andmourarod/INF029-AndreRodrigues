#include <stdio.h>
#include <string.h>

int menuGeral()
{
  int opcaomenugeral, finalizarmenugeral = 0;
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
      mainAluno();
    }

    if(opcaomenugeral == 2)
    {
      
      mainProfessor();
    }

    if(opcaomenugeral == 3)
    {
      mainDisciplina();
    }

    if(opcaomenugeral == 4)
    {
      mainMatriculaAluno();
    }

    if(opcaomenugeral == 5)
    {
      mainRelatorios();
    }

    if(opcaomenugeral > 5)
		{
			printf("Opção inexistente. \n");
		}
  }
  
  return 0;  
}





