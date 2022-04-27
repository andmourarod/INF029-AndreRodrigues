#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a, b;
  int *ptA = &a, *ptB = &b;

  printf("Informe a. \n");
  scanf("%d", &a);
  printf("Informe b. \n");
  scanf("%d", &b);
  
  void funcTroca (int *ptA, int *ptB);

  funcTroca(ptA, ptB);

  printf("Valor de a = %d \n", *ptA);
  printf("Valor de b = %d \n", *ptB);
  
  return 0;
}

void funcTroca (int *ptA, int *ptB)
{
  int aux;

  aux = *ptA;
  *ptA = *ptB;
  *ptB = aux;
}

