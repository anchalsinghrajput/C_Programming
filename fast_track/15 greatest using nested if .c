#include<stdio.h>
int input(int a)
{
  scanf("%d ",&a);
  return a;
}
int largest ( int a, int b, int c)
{
  if(a>=b)
  {
    if(a>=c)
      return a;
    else
      return c;
  }
  else
  {
    if(b>=c)
      return b;
    else
      return c;
  }
}
void output(int a, int b, int c, int d)
{
  printf(" largest of %d %d and %d is : %d \n ",a,b,c,d);
}
int main()
{
int a, b,c ;
  printf("enter three number :\n ");
  a=input(a);
  b=input(b);
  c=input(c);
  output(a,b,c,largest(a,b,c));
  return 0;
}
