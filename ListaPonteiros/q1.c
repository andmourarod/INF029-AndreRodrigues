#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a;
  int *ptA = &a;
  char b; 
  char *ptB = &b;
  char string[10];
  char *ptString = string;
  float c;
  float *ptC = &c;
  double d;
  double *ptD = &d;

  printf("Informe a. \n");
  scanf("%d", &a);
  getchar();
  printf("Informe b. \n");
  scanf("%c", &b);
  getchar();
  printf("Informe string. \n");
  fflush(stdin);
  fgets(string, 10, stdin);  
  printf("Informe d. \n");
  scanf("%lf", &d);

  printf("a = %d \n", a);
  printf("b = %c \n", b);
  printf("String %s \n", string);
  printf("d = %lf \n", d);

  printf("Informe a. \n");
  scanf("%d", ptA);
  getchar();
  printf("Informe b. \n");
  scanf("%c", ptB);
  getchar();
  printf("Informe string. \n");
  fflush(stdin);
  fgets(ptString, 10, stdin);  
  printf("Informe d. \n");
  scanf("%lf", ptD);

  printf("a = %d \n", a);
  printf("b = %c \n", b);
  printf("String %s \n", string);
  printf("d = %lf \n", d); 
  
  return 0;
}