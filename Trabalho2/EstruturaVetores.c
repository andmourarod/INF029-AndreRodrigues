#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

estruturaPrincipal vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
  int retorno = 0;
  // a posicao pode já existir estrutura auxiliar
    
  if(vetorPrincipal[posicao - 1].vetorAux != NULL)
  {
    //printf("1 \n");
    retorno = JA_TEM_ESTRUTURA_AUXILIAR; 
    return retorno;
  }
  
  // se posição é um valor válido {entre 1 e 10}
  if(posicao < 1 || posicao > 10)
  {
    //printf("2 \n");
    retorno = POSICAO_INVALIDA;  
    return retorno;
  }  

  // o tamanho nao pode ser menor que 1
  if(tamanho < 1)
  {
    //printf("3 \n");
    retorno = TAMANHO_INVALIDO;
    return retorno;
  }

  vetorPrincipal[posicao - 1].vetorAux = malloc(tamanho*sizeof(int));

  if(vetorPrincipal[posicao - 1].vetorAux == NULL)
  {
    //printf("4 \n");
    retorno = SEM_ESPACO_DE_MEMORIA; 
    return retorno;
  }
  else
  {
    //printf("5 \n");
    vetorPrincipal[posicao - 1].tamanho = tamanho;
    vetorPrincipal[posicao - 1].contadorElementos = 0;
  }
  
    retorno = SUCESSO;

   
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if (posicao < 1 || posicao > 10)
    {
      //printf("1 \n");
      retorno = POSICAO_INVALIDA; 
    }       
    else
    {
      // testar se existe a estrutura auxiliar
      if (vetorPrincipal[posicao - 1].vetorAux != NULL)
      {
        if (vetorPrincipal[posicao - 1].contadorElementos < vetorPrincipal[posicao - 1].tamanho)
        {
          vetorPrincipal[posicao - 1].vetorAux[vetorPrincipal[posicao - 1].contadorElementos] = valor;          
          vetorPrincipal[posicao - 1].contadorElementos++;
          //printf("2 \n");
          retorno = SUCESSO;
        }
        else
        {
          //printf("3 \n");
          retorno = SEM_ESPACO;
        }
      }
      else
      {
        //printf("4 \n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
      }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  int icont;
  int retorno = SUCESSO;

  if (posicao < 1 || posicao > 10)
  {
    //printf("1 \n");
    retorno = POSICAO_INVALIDA; 
    return retorno;
  }

  if (vetorPrincipal[posicao - 1].vetorAux == NULL)
  {
    retorno = SEM_ESTRUTURA_AUXILIAR; 
    return retorno;    
  }

  if (vetorPrincipal[posicao - 1].contadorElementos == 0)
  {
    retorno = ESTRUTURA_AUXILIAR_VAZIA; 
    return retorno;    
  }

  vetorPrincipal[posicao - 1].contadorElementos--;

  return retorno;  
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  int retorno = SUCESSO;
  int icont;
  int alvo;

  if (posicao < 1 || posicao > 10)
  {
    //printf("*1 \n");
    retorno = POSICAO_INVALIDA; 
    
    return retorno;
  }

  if (vetorPrincipal[posicao - 1].vetorAux == NULL)
  {
    //printf("*2 \n");
    retorno = SEM_ESTRUTURA_AUXILIAR; 
    return retorno;    
  }

  if (vetorPrincipal[posicao - 1].contadorElementos == 0)
  {
    //printf("*3 \n");
    retorno = ESTRUTURA_AUXILIAR_VAZIA; 
    return retorno;    
  }
  
  int finalizarProcura = 0;
  
  for(icont = 0; icont < vetorPrincipal[posicao-1].contadorElementos && finalizarProcura == 0; icont++)
  {
    /*printf("icont %d \n", icont);
    printf("vetorPrincipal[posicao-1].vetorAux[icont] %d \n", vetorPrincipal[posicao-1].vetorAux[icont]);
    printf("valor %d \n", valor);*/
    if(vetorPrincipal[posicao-1].vetorAux[icont] != valor)
    {
      retorno = NUMERO_INEXISTENTE;  
    }    
    else
    {
      finalizarProcura = 1;
      alvo = icont; 
      retorno = SUCESSO;
    }
  }

  /*printf("alvo %d \n", alvo);
  printf("vetor sem exclusão: \n");

  for(int jcont = 0; jcont < vetorPrincipal[posicao-1].contadorElementos; jcont++)
    {
      printf("%d \n", vetorPrincipal[posicao-1].vetorAux[jcont] );
    }

  printf("fim vetor: \n");

  printf("alvo %d \n", alvo);*/

  //int aux = vetorPrincipal[posicao-1].vetorAux[alvo];
  
  if(retorno == SUCESSO)
  {
   for(icont = alvo; icont < vetorPrincipal[posicao-1].contadorElementos; icont++)
    {    
      vetorPrincipal[posicao-1].vetorAux[alvo] = vetorPrincipal[posicao-1].vetorAux[alvo+1];
      vetorPrincipal[posicao-1].contadorElementos--;
    } 
  }

  /*printf("vetor com exclusão: \n");

  for(int jcont = 0; jcont < vetorPrincipal[posicao-1].contadorElementos; jcont++)
    {
      printf("%d \n", vetorPrincipal[posicao-1].vetorAux[jcont] );
      ;
    }

  printf("fim vetor: \n");*/

  //printf("----------- \n");
  //vetorPrincipal[posicao-1].vetorAux[vetorPrincipal[posicao-1].contadorElementos] = aux;

  //vetorPrincipal[posicao-1].contadorElementos--;
  
  return retorno;
  
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  
  int retorno = 0;
  int tamanho = vetorPrincipal[posicao - 1].contadorElementos;
  int icont = 0;

  if (posicao < 1 || posicao > 10)
  {
    //printf("1 \n");
    retorno = POSICAO_INVALIDA; 
  }       
  else
  {
    // testar se existe a estrutura auxiliar
    if (vetorPrincipal[posicao - 1].vetorAux != NULL)
    {
      for(icont = 0; icont < tamanho; icont++)
      {
        vetorAux[icont] = vetorPrincipal[posicao - 1].vetorAux[icont] ;      
      }        
        //printf("2 \n");
        retorno = SUCESSO;         
    }
    else
    {
      //printf("3 \n");
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }  

  return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

  int retorno = 0;
  int tamanho = vetorPrincipal[posicao - 1].contadorElementos;
  int icont = 0, jcont, aux;

  if (posicao < 1 || posicao > 10)
  {
    //printf("1 \n");
    retorno = POSICAO_INVALIDA; 
  }       
  else
  {
    // testar se existe a estrutura auxiliar
    if (vetorPrincipal[posicao - 1].vetorAux != NULL)
    {
      for(icont = 0; icont < tamanho; icont++)
      {
        vetorAux[icont] = vetorPrincipal[posicao - 1].vetorAux[icont] ;      
      }      

      for(jcont=tamanho-1; jcont>=1; jcont--)
      {    
    		for(icont=0; icont<jcont; icont++)
        {
    			if(vetorAux[icont]>vetorAux[icont+1])
          {
    				aux=vetorAux[icont];
            vetorAux[icont]=vetorAux[icont+1];
            vetorAux[icont+1]=aux;
          }
        }
      }

      /*printf("i vetor \n");
      for(icont = 0; icont < tamanho; icont++)
        {
          printf("%d ", vetorAux[icont]);
        }

      printf("f vetor \n");*/
        //printf("2 \n");
        retorno = SUCESSO;         
    }
    else
    {
      //printf("3 \n");
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }  

    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int retorno = SUCESSO;
  int icont, contadorVazias = 0, jcont, kcont, aux;

  for(icont = 0; icont < TAM; icont++)
  {
    //printf("vetorPrincipal[icont].contadorElementos | icont %d | %d \n", vetorPrincipal[icont].contadorElementos, icont+1);
    if (vetorPrincipal[icont].contadorElementos == 0)
    {
      //printf("vetorPrincipal[icont].contadorElementos | icont %d | %d \n", vetorPrincipal[icont].contadorElementos, icont+1);
      //printf("vazio. \n");
      contadorVazias++;        
    }      
  }

  if(contadorVazias == TAM)
  {
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS; 
    return retorno;  
  }

  kcont = 0;
  for(icont = 0; icont < TAM; icont++)
  {
    if (vetorPrincipal[icont].contadorElementos != 0)
    {
      for(jcont = 0; jcont < vetorPrincipal[icont].contadorElementos; jcont++, kcont++)
      {
        vetorAux[kcont] = vetorPrincipal[icont].vetorAux[jcont];
      }
    }          
  }  
  
  return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

  int retorno = SUCESSO;
  int icont, contadorVazias = 0, jcont, kcont, aux;

  for(icont = 0; icont < TAM; icont++)
  {
    //printf("vetorPrincipal[icont].contadorElementos | icont %d | %d \n", vetorPrincipal[icont].contadorElementos, icont+1);
    if (vetorPrincipal[icont].contadorElementos == 0)
    {
      //printf("vetorPrincipal[icont].contadorElementos | icont %d | %d \n", vetorPrincipal[icont].contadorElementos, icont+1);
      //printf("vazio. \n");
      contadorVazias++;        
    }      
  }

  if(contadorVazias == TAM)
  {
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS; 
    return retorno;  
  }

  kcont = 0;
  for(icont = 0; icont < TAM; icont++)
  {
    if (vetorPrincipal[icont].contadorElementos != 0)
    {
      for(jcont = 0; jcont < vetorPrincipal[icont].contadorElementos; jcont++, kcont++)
      {
        vetorAux[kcont] = vetorPrincipal[icont].vetorAux[jcont];
      }
    }          
  }

  /*printf("vetor \n");
  for(icont = 0; icont < kcont; icont++)
  {
    printf("%d ", vetorAux[icont]);  
  }
  printf("fim vetor \n");*/

  //REVER 

  for(jcont=kcont-1; jcont>=1; jcont--)
  {    
		for(icont=0; icont<jcont; icont++)
    {
			if(vetorAux[icont]>vetorAux[icont+1])
      {
				aux=vetorAux[icont];
        vetorAux[icont]=vetorAux[icont+1];
        vetorAux[icont+1]=aux;
      }
    }
  }
  
        
  /*for(icont = 0; icont < kcont; icont++)
      {
        for(jcont = icont + 1; jcont<kcont; jcont++)
        {
          if(vetorAux[icont] > vetorAux[jcont]);
          {
            aux = vetorAux[icont];
            vetorAux[icont] = vetorAux[jcont];
            vetorAux[jcont] = aux;
          }
        }
      }*/

  /*printf("vetor \n");
  for(icont = 0; icont < kcont; icont++)
  {
    printf("%d ", vetorAux[icont]);  
  }
  printf("fim vetor \n");*/


  
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
  int retorno = 0;

  if (posicao < 1 || posicao > 10)
  {
    //printf("1 \n");
    retorno = POSICAO_INVALIDA; 
    return retorno;
  } 

  if (vetorPrincipal[posicao - 1].tamanho + novoTamanho < 1)
  {
    retorno = NOVO_TAMANHO_INVALIDO;
    return retorno;
  }

  if (vetorPrincipal[posicao - 1].vetorAux == NULL)
  {
    retorno = SEM_ESTRUTURA_AUXILIAR;
    return retorno;
  }

  //printf("vetorPrincipal[posicao - 1].tamanho %d \n", vetorPrincipal[posicao - 1].tamanho);

  //printf("novo tamanho %d \n", novoTamanho);

  int soma = vetorPrincipal[posicao - 1].tamanho + novoTamanho;

  //printf("soma %d \n", soma);
  
  vetorPrincipal[posicao - 1].vetorAux = realloc(vetorPrincipal[posicao - 1].vetorAux, (vetorPrincipal[posicao - 1].tamanho + novoTamanho)*sizeof(int));  

  if(vetorPrincipal[posicao - 1].vetorAux == NULL)
  {
    //printf("4 \n");
    retorno = SEM_ESPACO_DE_MEMORIA; 
    return retorno;
  }
  else
  {
    //printf("5 \n");
    vetorPrincipal[posicao - 1].tamanho = soma;
    vetorPrincipal[posicao - 1].contadorElementos = vetorPrincipal[posicao - 1].contadorElementos;    
  }
  
    //printf("5 \n");
  //vetorPrincipal[posicao - 1].tamanho = soma;
   

  /*printf("vetorPrincipal[posicao - 1].tamanho + novoTamanho %d \n", soma);
  printf("tamanho vetor: %d \n", vetorPrincipal[posicao - 1].tamanho);
  printf("contadorElementos: %d \n", vetorPrincipal[posicao - 1].contadorElementos);*/

  return SUCESSO;
  
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
  int retorno = 0;

  if (posicao < 1 || posicao > 10)
  {
    //printf("1 \n");
    retorno = POSICAO_INVALIDA; 
    return retorno;
  }

  if (vetorPrincipal[posicao - 1].vetorAux == NULL)
  {
    retorno = SEM_ESTRUTURA_AUXILIAR; 
    return retorno;    
  }

  if (vetorPrincipal[posicao - 1].contadorElementos == 0)
  {
    retorno = ESTRUTURA_AUXILIAR_VAZIA; 
    return retorno;    
  }
  else
  {    
    //vetorPrincipal[posicao - 1].contadorElementos = vetorPrincipal[posicao - 1].tamanho;
    if(vetorPrincipal[posicao - 1].contadorElementos >= vetorPrincipal[posicao - 1].tamanho)
    {
      vetorPrincipal[posicao - 1].contadorElementos = vetorPrincipal[posicao - 1].tamanho;    
    }
    
    
    retorno = vetorPrincipal[posicao - 1].contadorElementos;  
  }

  
  /*printf("vetor \n");
  printf("tamanho vetor: %d \n", vetorPrincipal[posicao - 1].tamanho);
  
  for(int icont = 0; icont < vetorPrincipal[posicao - 1].contadorElementos; icont++)
    {
      printf("vetorPrincipal %d ", vetorPrincipal[posicao - 1].vetorAux[icont]);
    }

  printf("fim vetor \n");


  
  printf("vetorPrincipal[posicao - 1].contadorElementos %d \n", vetorPrincipal[posicao - 1].tamanho);*/
    
  return retorno;
}

int todasEstruturasAuxiliaresVazias(){ 

    int vazia = 0;
    int icont;

    for (icont = 0; icont < TAM; icont++)
        if (vetorPrincipal[icont].contadorElementos == 0)
            vazia++;
    
    if (vazia == TAM)
        return 1;

    return 0;
}

int inserirNaLista(No *inicio, int valor){

    if (inicio == NULL) // Nao existe lista
        return 0;

    No *novo = (No*)malloc(sizeof(No)); // Alocando memória para novo

    if (novo == NULL) // Não conseguiu alocar memória
        return 0;

    novo->conteudo = valor;
    novo->prox = NULL;

    if (inicio->prox == NULL){ //Lista vazia, nsira no início
        inicio->prox = novo;
        return 1;
    }

    No *ultimo = inicio->prox;

    while (ultimo->prox != NULL)
        ultimo = ultimo->prox;

    ultimo->prox = novo;
}


/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote*/

No* montarListaEncadeadaComCabecote(){

    No *inicio = (No*)malloc(sizeof(No)); // Alocando memória para inicio

    if (inicio == NULL) // Não consegui alocar
        return NULL;

    inicio->prox = NULL; // início só vai servir para apontar para o próximo
   
    if (todasEstruturasAuxiliaresVazias()) // Se todas as estruturas auxiliares estiverem vazias, retorne NULL
        return NULL;
   
    int icont, jcont;
    int qtd;

    for (icont = 0; icont < TAM; icont++)
        if (vetorPrincipal[icont].vetorAux!= NULL){ // Se a estrutura auxiliar não estiver vazia, execute
            qtd = vetorPrincipal[icont].contadorElementos; // qtd vai estar sempre mudando o seu valor, pois ele depende de cada posicao da estrutura auxliar
            for (jcont = 0; jcont < qtd; jcont++)
                inserirNaLista(inicio, vetorPrincipal[icont].vetorAux[jcont]);
        }
            
    return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
RetorPrincipal void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){

    No *atual = inicio->prox;
    int icont = 0;

    while (atual != NULL){
        vetorAux[icont] = atual->conteudo; // Atribuindo o conteudo de atual para o vetorAux   
        atual = atual->prox; // Atual passa a ser o próximo
        icont++; // I passa a ocupar a próximo posicao
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
*/
void destruirListaEncadeadaComCabecote(No** inicio){
   
    if (inicio == NULL) // Lista não existe
        return;

    No *atual = (*inicio)->prox;

    while (*inicio != NULL){

        atual = (*inicio)->prox;

        free(*inicio);

        *inicio = atual;
    }

    *inicio = NULL;
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/
void inicializar(){
  int icont;

  for (icont = 0; icont < TAM; icont++){
    vetorPrincipal[icont].vetorAux = NULL;
    vetorPrincipal[icont].contadorElementos = 0;
    vetorPrincipal[icont].tamanho = 0;
  }
}

void finalizar(){
    int icont;
    for(icont = 0; icont < TAM; icont++)
        free(vetorPrincipal[icont].vetorAux);
}















/*No *montarListaEncadeadaComCabecote()
{
  int valor, x, y;
	No *v;
	
	v = (No*) malloc(*sizeof(No));
	if(v==NULL){
		return NULL;
	}
  
	for(x=0; x<10; x++)
  {
		valor=getQuantidadeElementosEstruturaAuxiliar(x);
		if(valor==0){
			return NULL;
		}
		else 
    {
			for (y=0;y<valor; y++) // ou y<=
      {
				v->conteudo=vetorPrincipal[x].vetorAux[y];
   			v->prox = NULL;
   				
   			if (inicio==NULL)
        {
   				inicio=v;
				}	
   			else 
        {
	  			v->prox=inicio;
	  			inicio=v;
				}
			  return inicio;
		  }
		}
	}  
}

*/

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/

/* 
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  No *vetor;
	int icont=0;
	vetor = inicio;
	while (vetor !=NULL) 
  {
	  vetorAux[icont] = vetor ->conteudo;
	  vetor = vetor ->prox;
	  icont++;
	}
}
*/

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno void.
  */

/*void destruirListaEncadeadaComCabecote(No **inicio)
{
  
}


Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 


void inicializar()
{
  int x;
	inicio=NULL;
	
	for(x=0;x<10;x++)
  {
		vetorPrincipal[x].vetorAux=NULL;
		vetorPrincipal[x].tamanho=0;
		vetorPrincipal[x].contadorElementos=0;
	}
}


Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.


void finalizar()
{
  int x=0;
  
  for(x=0;x<10;x++)
  {
      free(vetorPrincipal[x].vetorAux);
  }
}*/