#include <stdio.h>
#include <stdlib.h>


int main()
{
  int tamvetor = 5;
  int vetor[tamvetor], i;
  void funcOrdena(int *vetor, int n);

  printf("Informe %d valores. \n", tamvetor);
  
  for(i = 0; i<tamvetor; i++)
  {
    scanf("%d", &vetor[i]);
  }

  funcOrdena(vetor, tamvetor);

  printf("O vetor ordenado é: \n");
  
  for(i = 0; i<tamvetor; i++)
  {
    printf("%d ", vetor[i]);
  }
  
  return 0;
}

void funcOrdena(int *vetor, int n)
{
  int i, j, aux;

  for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
      {
        if(vetor[i] < vetor[j])
        {
          aux = vetor[j];
          vetor[j] = vetor[i];
          vetor[i] = aux;          
        }
      }
    }
}