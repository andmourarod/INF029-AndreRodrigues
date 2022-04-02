#include <stdio.h>
#include <string.h>
#define qtdealuno 3
#define qtdedisc 3
#define qtdeprof 3

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

typedef struct
{
  int codigo;
  char nome[51];
  int semestre;
  char professor[51];
}incluirdisc;

incluir Aluno;
incluir vetorAluno[qtdealuno];

incluir Prof;
incluir vetorProf[qtdeprof];

incluirdisc Disc;
incluirdisc vetorDisc[qtdedisc];

incluir vetorAuxAlunosProfessores;

int funcMenuPrincipalAluno();
int funcIncluirAluno(incluir *vetorAluno, int n, int opc);
void funcListarAluno(incluir *vetorAluno, int n);
int funcAtualizarAluno(incluir *vetorAluno, int n, int opc);
int funcExcluirAluno(incluir *vetorAluno, int n);
int funcValidaMatricula(incluir *vetorAluno, int n);
int funcValidaSexo(incluir *vetorAluno, int n);
int funcValidaData(incluir *vetorAluno, int n);
int funcValidaCPF(incluir *vetorAluno, int n);

int funcMenuPrincipalDisc();
int funcIncluirDisc(incluirdisc *vetorDisc, int n, int opc);
void funcListarDisc(incluirdisc *vetorDisc, int n);
int funcAtualizarDisc(incluirdisc *vetorDisc, int n, int opc);
int funcExcluirDisc(incluirdisc *vetorDisc, int n);
int funcValidaCodigoDisc(incluirdisc *vetorDisc, int n);
int funcValidaSemestre(incluirdisc *vetorDisc, int n);
int funcValidaProf(incluirdisc *vetorDisc, int n, incluir *vetorProf, int m);

int funcMenuPrincipalProf();
int funcIncluirProf(incluir *vetorProf, int n, int opc);
void funcListarProf(incluir *vetorProf, int n);
int funcAtualizarProf(incluir *vetorProf, int n, int opc);
int funcExcluirProf(incluir *vetorProf, int n);
int funcValidaMatriculaProf(incluir *vetorProf, int n);
int funcValidaSexoProf(incluir *vetorProf, int n);
int funcValidaDataProf(incluir *vetorProf, int n);
int funcValidaCPFProf(incluir *vetorProf, int n);

void funcListarAluno(incluir *vetorAluno, int n);
void funcListarProfessores(incluir *vetorProf, int n);
void funcListarDisciplinas(incluirdisc *vetorDisc, int n);
//void
void funcListarAlunoPorSexo(incluir *vetorAluno, int n);
void funcListarAlunoPorNome(incluir *vetorAluno, int n);
void funcListarAlunoPorDataDeNascimento(incluir *vetorAluno, int n);
void funcListarProfessorPorSexo(incluir *vetorProf, int n);
void funcListarProfessorPorNome(incluir *vetorProf, int n);
void funcListarProfessorPorDataDeNascimento(incluir *vetorProf, int n);
void funcListarAniversarianteDoMes(incluir *vetorProf, incluir *vetorAluno, int n, int m);
//void
//void
//void

#include "GestaoDeAlunos.c"
#include "GestaoDeDisciplinas.c"
#include "GestaoDeProfessores.c"
#include "MenuGeral.c"
#include "Relatorios.c"
#include "MatriculaAluno.c"// Só entrará quando Diego terminar de elaborar a matriz.

int main()
{

  menuGeral();

  return 0;
} 


