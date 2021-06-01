
#include<stdio.h>
void input(int *a)
{
  scanf("%d", a);
}

int sum(int a , int b)
{
  int s=a+b;
  return s;
}

void output(int a,int b,int c)
{
  printf("sum of %d and %d is %d \n ",a,b,c);
}

int main()
{
int a,b;
  printf("Enter number 1 :\n ");
  input(&a);
  printf("Enter number 2 : \n");
  input(&b);
  output(a,b,sum(a,b));
  return 0;
}
