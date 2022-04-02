#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define qtdealuno 3
#define qtdedisc 3
#define qtdeprof 3


int matricula_aluno();
int codigo_disciplina();
int achar_matricula();
int atualizar_vinculo_disci();
int excluir_vinculo_disci();
void menu_gestao_disci();
void listar_disciplina();
int incluir_aluno();
char outra_matricula ();
void relatorio_menos_3_disci ();
void relatorio_mais_40_aluno ();
void receber_aluno(incluir *vetorAluno);


int mainMatriculaAluno()
{
    int m_matricula[qtdealuno+1][qtdedisc+1];
    int n_matricula_main[qtdealuno];
    int n_codigo_disciplina[qtdedisc];
    int i, j;
    int escolha;
    int linha_do_aluno, codigo;
    char um_ou_zero, um_ou_dois;




        // recebe a função aluno e gera  um vetor com matriculas que irá preencher a coluna zero da matriz matricula,
    for(i=0; i<qtdealuno; i++){
        n_matricula_main[i] = matricula_aluno(i);
        //printf("%d\t", n_matricula_main[i]);
    }
    //printf("\n");
    for(i=0; i<qtdedisc; i++){
        n_codigo_disciplina[i] = codigo_disciplina(i);
      //  printf("%d\t", n_codigo_disciplina[i]);
    }

    //printf("\n");
    for(i=1; i<=qtdealuno; i++){
       m_matricula[i][0] = n_matricula_main[i-1];

    }
    //printf("\n");
    for(j=1; j<=qtdedisc; j++){
       m_matricula[0][j] = n_codigo_disciplina[j-1];
       //printf("%d\t", m_matricula[0][j]);
    }
    do{
        menu_gestao_disci();
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                printf("\n#### SECAO INCLUIR ALUNO ####\n ");
                do{
                    linha_do_aluno = achar_matricula(m_matricula);
                    listar_disciplina(n_codigo_disciplina);
                    do{
                        codigo = incluir_aluno(linha_do_aluno,m_matricula);
                        if (codigo<qtdedisc && codigo>0)
                            m_matricula[linha_do_aluno][codigo]=1;
                    }while(codigo!=0);
                    printf("Digite (1) para matricular outro aluno, (0) para retornar ao menu gestao de disciplina ou qualquer tecla para finalizar: ");
                    um_ou_zero = outra_matricula ();
                }while(um_ou_zero=='1');
                break;
            case 2:
                 printf("\n#### SECAO EXCLUIR ALUNO ####\n ");
                 do{
                 linha_do_aluno = achar_matricula(m_matricula);
                    //printf("\nA linha do aluno e: %d\n",linha_do_aluno);
                    listar_disciplina(n_codigo_disciplina);
                    do{
                        codigo = incluir_aluno();
                       //printf("\nO codigo da disciplina é: %d\n",codigo);
                        if (codigo<qtdedisc && codigo>0)
                            m_matricula[linha_do_aluno][codigo]=0;
                    }while(codigo!=0);
                    printf("Digite (1) para EXCLUIR DISCIPLINA de outro aluno, (0) para retornar ao menu gestao de disciplina ou qualquer tecla para finalizar: ");
                    um_ou_zero = outra_matricula ();
                }while(um_ou_zero=='1');
                break;
            case 3:{
                fflush(stdin);
                printf("\n#### RELATORIOS DISCIPLINA #### \n\n");
                printf("Digite (1) para listar alunos matriculados em menos de 3 disciplinas:\n");
                printf("Digite (2) para listar disciplinas com mais de 40 alunos:\n");
                printf("Digite qualquer tecla para voltar ao menu anterior: \n ");
                printf("---------------------------------------------------------> ");
                scanf("%c", &um_ou_dois);
                switch(um_ou_dois){
                    case '1':
                        relatorio_menos_3_disci(m_matricula);
                        break;
                    case '2':
                        relatorio_mais_40_aluno(m_matricula);
                        break;
                    default:
                        um_ou_zero = '0';
                        break;
                    }
                um_ou_zero='0';
                break;
            }
            case 4:
                printf("\n#### CADASTRO FINALIZADO ####\n\n ");
                um_ou_zero='1';
                break;
        }
    }while(um_ou_zero=='0');

    m_matricula[0][0] = 0;
    for(i=0; i<=qtdealuno; i++){
       for(j=0; j<=qtdedisc; j++){
           if(i != 0 && j!=0 && m_matricula[i][j] != 1){
                m_matricula[i][j]=0;}
        printf("%d\t", m_matricula[i][j]);
        }
    printf("\n");
    }

    printf ("\n\n");

    return 0;
}

int matricula_aluno(int i){

    int n_matricula;

    n_matricula = 1000+i;
    //printf("%d\t", n_matricula);

    return n_matricula;



}
int codigo_disciplina(int i){

    int n_disciplina;

    n_disciplina = 9+i;
    //printf(" %d\t", n_disciplina);

    return n_disciplina;



}

int achar_matricula (int m[qtdealuno+1][qtdedisc+1]){

    int i;
    int valido = 0;
    int matricula;


    printf("\n Digite o numero de matricula do aluno: ");
    do{
        scanf("%d",&matricula);
        for(i=1; i<=qtdealuno; i++){
            if (matricula == m[i][0]){
                printf("Matricula valida.");
                valido = i;}
        }
        if (valido==0)
            printf("Matricula invalida. Digite outro número de matricula: ");
    }while(valido==0);


    return valido;

}

void listar_disciplina(int n_codigo_disciplina[qtdedisc]){

    int i, cont=1;

    printf("\nNUM----->\tNOME\n");
    for(i=0; i<qtdedisc; i++){
        printf("(%02d)----->\tINF%03d\n", cont+i, n_codigo_disciplina[i]);
    }
}

int incluir_aluno(int linha_do_aluno){

    int codigo;

    do{
        printf("\nDigite um número da disciplina VALIDO que deseja matricular ou (0) para sair:");
        scanf("%d",&codigo);
        if (codigo<qtdedisc && codigo>0)
            return codigo;
    }while(codigo!=0);

}

void menu_gestao_disci(){

    printf("\n\n\nSISTEMA DE GESTAO DE MATRICULA.");
    printf("\n\n Digite (1) para incluir aluno em disciplinas: ");
    printf("\n Digite (2) para excluir disciplinas de um aluno: ");
    printf("\n Digite (3) para entrar em relatórios sobre disciplinas: ");
    printf("\n Digite (4) para finalizar:\n\t\t\t \t\t\t ");

}

char outra_matricula (){

    char um_ou_zero;

    fflush(stdin);
    scanf("%c",&um_ou_zero);
    printf("\n\n");
    if (um_ou_zero=='1' || um_ou_zero=='0')
        return um_ou_zero;

}

void relatorio_menos_3_disci (int m_matricula[qtdealuno][qtdedisc]){

    int i, j;
    int contador_disci=3;

    printf("\n\n#### Relatorios sobre disciplinas ####\n\n");
    printf("Lista de alunos matriculados em menos de 3 disciplinas:\n\n");
    for(i=1; i<=qtdealuno; i++){
        if (contador_disci<3)
                printf("%d\n", m_matricula[i-1][0]);
        contador_disci=0;
        for(j=1; j<qtdedisc; j++){
            if (m_matricula[i][j] == 1)
                contador_disci++;

        }
    }

}

void relatorio_mais_40_aluno (int m_matricula[qtdealuno][qtdedisc]){

    int i, j;
    int contador_aluno=0;

    printf("\n\n#### Relatorios sobre disciplinas ####\n\n");
    printf("Lista de disciplinas com mais de 40 alunos:\n\n");
    for(i=1; i<=qtdedisc; i++){
        if (contador_aluno>2)
                printf("%d\n", m_matricula[0][i-1]);
        contador_aluno=0;
        for(j=1; j<qtdealuno; j++){
            if (m_matricula[j][i] == 1)
                contador_aluno++;

        }
    }

}

