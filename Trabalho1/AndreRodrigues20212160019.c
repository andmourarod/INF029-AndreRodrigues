// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: André Moura Rodrigues
//  email: andmourarodrigues@gmail.com  
//  Matrícula: 20212160019  
//  Semestre: 2022/1.

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include "AndreRodrigues20212160019.h"

DataQuebrada quebraData(char data[])
{
  DataQuebrada dq;
  char sDia[15];
	char sMes[15];
	char sAno[15];
	int i, a;
  int caracterestranho = 0;
  
	if(data[0] == '/')
  {
    caracterestranho = 1;    
  }
  
  for (i = 0; data[i] != '/' && i<2; i++)
  {
		sDia[i] = data[i];
    if((data[i] < 48) || (data[i] > 57))
    {
      caracterestranho = 1;
    }
	}
    
  if(i == 1 || i == 2)
  { // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}
  else 
  {
    dq.valido = 0;
  }
  
  if(data[i] != '/')
  {
    caracterestranho = 1;
  }

  if(data[i+1] == '/')
  {
    caracterestranho = 1;  
  }
  
  int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (a = 0; data[j] != '/' && a<2 ; a++, j++)
  {
		sMes[i] = data[j];
    if((data[j] < 48) || (data[j] > 57))
    {
      caracterestranho = 1;
    }
		i++;
	}

	if(i == 1 || i == 2)
  { // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}
  else
  {
    dq.valido = 0;
  }	
 
  if(data[j] != '/')
  {
    caracterestranho = 1;
  }
     
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
  
	for(a = 0; data[j] != '\0' && a<4; a++, j++)
  {
	 	sAno[i] = data[j];
    if((data[j] < 48) || (data[j] > 57))
    {
      caracterestranho = 1;
    }    
	 	i++;
	}

	if(i == 2 || i == 4)
  { // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}
  else
  {
    dq.valido = 0;
  }	

  
  if(caracterestranho == 1)
  {
    dq.iDia = -1;
    dq.iMes = -1;
    dq.iAno = -1;
    dq.valido = 0;
  }
  else
  {
    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);
    dq.valido = 1;
  } 
  
  if((dq.iMes < 1) || (dq.iMes > 12))
  {    
    dq.valido = 0;    
  }
  else
  {
    if ((dq.iMes == 1) || (dq.iMes == 3) || (dq.iMes == 5) || (dq.iMes == 7) || (dq.iMes == 8) || (dq.iMes == 10) || (dq.iMes == 12))
    {
      if((dq.iDia < 1) || (dq.iDia > 31))
      {        
        dq.valido = 0;         
      }
    }
    else
    {
      if ((dq.iMes == 4) || (dq.iMes == 6) || (dq.iMes == 9) || (dq.iMes == 11))
      {
        if((dq.iDia < 1) || (dq.iDia > 30))
        {         
          dq.valido = 0;           
        }  
      }
      else //mes == 2
      {
        if((dq.iAno%4 == 0) || ((dq.iAno%100 == 0) && (dq.iAno%400 == 0))) //ano bissexto
        {
          if((dq.iDia < 1) || (dq.iDia > 29))
          {
            dq.valido = 0;               
          }          
        }
        else //ano não bissexto
        {
          if((dq.iDia < 1) || (dq.iDia > 28))
          {
            dq.valido = 0;              
          }           
        }
      }      
    }
  }   
  return dq;
}

int q1(char data[])
{
  DataQuebrada dataQuebrada;
  
  dataQuebrada = quebraData(data);

  if (dataQuebrada.valido == 1)
  {
    return 1;
  }
  else
  {
    return 0;  
  }        
}

DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  DiasMesesAnos dma;
  DataQuebrada datainicial1, datafinal2;
  
  if(q1(datainicial) == 0) // PARA DATA INICIAL INVÁLIDA
  {
    dma.retorno = 2;    
    return dma;
  }
  else // q1(datainicial) == 1 PARA DATA INICIAL VÁLIDA
  {
    datainicial1 = quebraData(datainicial);         
    if (q1(datafinal) == 0) // PARA DATA FINAL INVÁLIDA
    {
    dma.retorno = 3;      
    return dma;
      
    }      
    else        // q1(datafinal) == 1 PARA DATA FINAL VÁLIDA
    {
      datafinal2 = quebraData(datafinal);      
    }
  }

  if(datainicial1.iAno > datafinal2.iAno)
  {
    dma.retorno = 4;    
    return dma;    
  }
  else
  {
    if(datainicial1.iMes > datafinal2.iMes) 
    {
      dma.retorno = 4;       
      return dma;      
    }    
  }
  
  int datafinal2bissexto;
  
  if((datafinal2.iAno%4 == 0) || ((datafinal2.iAno%100 == 0) && (datafinal2.iAno%400 == 0)))
  {
     datafinal2bissexto = 1;
  }
  else
  {
    datafinal2bissexto = 0;
  }

  int datainicial1bissexto;
  
  if((datainicial1.iAno%4 == 0) || ((datainicial1.iAno%100 == 0) && (datainicial1.iAno%400 == 0)))
  {
    datainicial1bissexto = 1;
  }
  else
  {
    datainicial1bissexto = 0;
  }

  dma.qtdAnos = datafinal2.iAno - datainicial1.iAno;
  
  if(datainicial1.iDia > datafinal2.iDia)
  {
    dma.qtdMeses = datafinal2.iMes - datainicial1.iMes - 1;
    
    if(datainicial1.iMes == 4 || datainicial1.iMes == 6 || datainicial1.iMes == 8 || datainicial1.iMes == 11) //PARA MESES COM 30 DIAS.
    {
      dma.qtdDias = 30 - datainicial1.iDia + datafinal2.iDia;
    }    
    else
    { 
      if(datainicial1.iMes == 1 || datainicial1.iMes == 3 || datainicial1.iMes == 5 || datainicial1.iMes == 7 || datainicial1.iMes == 8 || datainicial1.iMes == 10 || datainicial1.iMes == 12) //PARA MESES COM 31 DIAS.
      {
        dma.qtdDias = 31 - datainicial1.iDia + datafinal2.iDia;
      }
      else //(datainicial1.iMes == 2)
      {
        if(datafinal2bissexto == 1 && datainicial1bissexto == 0)        
        {
          if(datafinal2.iMes != 2)
          {        
            dma.qtdDias = 29 - datainicial1.iDia + datafinal2.iDia; 
            
          }         
        }
        else //PARA ANOS NÃO BISSEXTOS
        {
          if(datafinal2bissexto == 0 && datainicial1bissexto == 1)
          {
            if(datafinal2.iMes == 2)
            {        
              if(datainicial1.iDia - datafinal2.iDia > 0)
              {                
                dma.qtdDias = datainicial1.iDia - datafinal2.iDia -1;
                dma.qtdMeses = 0;
              }                            
            } 
            else
            {
              dma.qtdDias = 28 - datainicial1.iDia + datafinal2.iDia;
            }
          }  
          if(datafinal2bissexto == 1 && datainicial1bissexto == 1)
          {
            if(datainicial1.iDia - datafinal2.iMes > 0)
            {   
            dma.qtdDias = 30;
            dma.qtdMeses = 11 - datainicial1.iMes + datafinal2.iMes;
            dma.qtdAnos =  datafinal2.iAno - datainicial1.iAno - 1;
            }
          }
        }
      }
    }
  }
  else //datainicial1.iDia <= datafinal2.iDia
  {    
    dma.qtdDias = datafinal2.iDia - datainicial1.iDia;
    dma.qtdMeses = datafinal2.iMes - datainicial1.iMes;
  }  
  
  dma.retorno = 1;
  
  /*printf("dma.retorno %d \n", dma.retorno);
  printf("Diferenca Dias %d \n", dma.qtdDias);
  printf("Diferenca Meses %d \n", dma.qtdMeses);
  printf("Diferenca Anos %d \n", dma.qtdAnos);*/ 
  
  return dma;      
}    
 
int q3(char *texto, char c, int isCaseSensitive)
{
  int icont, contador = 0;
  char cMinusculo, cMaiusculo;

  if((c >= 'A') && (c<= 'Z'))
  {
    cMaiusculo = c;
    cMinusculo = c + 32;    
  }

  if((c >= 'a') && (c<= 'z'))  
  {
    cMaiusculo = c - 32;
    cMinusculo = c;     
  }

  if(isCaseSensitive == 1)
  {
    for(icont = 0; texto[icont] != '\0'; icont++)
    {
      if(texto[icont] == c)
      {
        contador++;
      }  
    }
  }
  else
  {
    for(icont = 0; texto[icont] != '\0'; icont++)
    {
      if(texto[icont] == cMinusculo || texto[icont] == cMaiusculo)
      {
      
      contador++; 
      
      }    
    }
  }   
  return contador;
}

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int icont=0, wcont = 0, contador = 0, contadoracentos = 0, jcont=0, kcont=0, qcont = 0, okletra = 0, qtdecaracteres = 0; 
  int vetorAuxiliarTexto[250];
  char vetorAuxiliarBusca[50];

  for(icont = 0; icont < 250; icont++)
  {
    vetorAuxiliarTexto[icont] = 0;
  }

  for(icont = 0; icont < 50; icont++)
  {
    vetorAuxiliarBusca[icont] = 0;
  }
  
  for(icont = 0, jcont = 0; strTexto[icont] != '\0'; icont++)
  {    
    if(strTexto[icont] != -61)
    {
      vetorAuxiliarTexto[jcont] = strTexto[icont];      
      jcont = jcont + 1;
    }
  }

  for(icont = 0, jcont = 0; strBusca[icont] != '\0'; icont++)
  {    
    if(strBusca[icont] != -61)
    {
      vetorAuxiliarBusca[jcont] = strBusca[icont];      
      jcont = jcont + 1;
    }
  }  
  
  for(icont = 0; vetorAuxiliarTexto[icont] != '\0'; icont++)   
  {
    if(vetorAuxiliarTexto[icont] == vetorAuxiliarBusca[jcont]) 
    {
      jcont++;      
    }
    else
    {
      jcont = 0;
    }
    
    if(jcont == strlen(vetorAuxiliarBusca))
    {     
      contador = contador + 1;
      posicoes[kcont] = icont - strlen(vetorAuxiliarBusca) + 1 + 1; 
      //printf("posicao inicial %d ", posicoes[kcont]);    
      kcont++;
      posicoes[kcont] = icont + 1; 
      //printf("posicao final %d ", posicoes[kcont]);
      kcont++;  
      jcont = 0;
    }    
  }    
  
  return contador;
}

int q5(int num)
{ 
  int icont, jcont, algarismos, numeroinv = 0; 
    
  for(icont = 1; num/icont >= 1; )
  {
    icont = icont*10;
  }
    
  icont = icont/10;

  for(icont, jcont = 1; icont >=1; icont = icont/10)
  {
    algarismos = num/icont; 
    numeroinv = numeroinv + algarismos*jcont;     
    num = num%icont; 
    jcont = jcont*10;
  } 
  
  return numeroinv;
}

int q6(int numerobase, int numerobusca)
{
  //int icont, tamanhovetorbase = 0, tamanhovetorbusca = 0, jcont, encontros = 0, contador1 = 0, qcont = 0;  

  int algarismosbase, algarismosbusca, contador = 0, contadordealgarismosencontrados = 0, contadorfinal = 0;
  long long int icont, jcont, qcont, qcontinicial;

  for(icont = 1; numerobase/icont >= 1; )
  {
    icont = icont*10;
    //printf("icont %ld \n", icont);
  }
    
  icont = icont/10;

  //printf("icont %ld \n", icont);

  for(jcont = 1; numerobusca/jcont >= 1; )
  {
    contador = contador + 1;    
    jcont = jcont*10;    
  }

  qcontinicial = jcont/10;
  //printf("contador %d \n", contador);
  //printf("qcontinicial %d \n", qcontinicial);

  int numerobuscainicial = numerobusca;

  for(icont, qcont = qcontinicial; icont >= 1; )
  {
    /*printf("numerobase %d \n", numerobase);
    printf("numerobusca %d \n", numerobusca);
    printf("icont %ld \n", icont);
    printf("qcont %d \n", qcont);*/
    
    algarismosbase = numerobase/icont;
    algarismosbusca = numerobusca/qcont;
    
    /*printf("algarismosbase %d \n", algarismosbase);
    printf("algarismosbusca %d \n", algarismosbusca);*/

    if(algarismosbase == algarismosbusca)
    {
      contadordealgarismosencontrados = contadordealgarismosencontrados + 1;
      //printf("contadordealgarismosencontrados %d \n", contadordealgarismosencontrados);
      numerobase = numerobase%icont;
      icont = icont/10;
      numerobusca = numerobusca%qcont;
      qcont = qcont/10;
      if(qcont == 0)
      {
        qcont = 1;
      }
    }
    else
    {
      contadordealgarismosencontrados = 0;
      numerobase = numerobase%icont;        
      icont = icont/10;
      numerobusca = numerobuscainicial;
      qcont = qcontinicial;
    }

    if(contadordealgarismosencontrados == contador)
    {
      contadordealgarismosencontrados = 0;
      contadorfinal = contadorfinal + 1;
      numerobusca = numerobuscainicial;
      qcont = qcontinicial;
      //printf("CONTADOR FINAL %d \n", contadorfinal);
    }    
  }

  return contadorfinal;   
}


