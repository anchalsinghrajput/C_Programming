
#include<stdio.h>
int input(int a)
{
scanf("%d",&a);
return a;
}
int largest(int a, int b, int c)
{
  int i=a;
  
  if(i<b)
  {
    i=b;
  }
  if(i<c)
  {
    i=c;
  }
  return i;
}
int output(int a, int b, int c , int l)
{
    printf("largest of %d  , %d and %d is : %d ",a,b,c,l);
}
int main()
{
int a,b,c;
    printf("enter three number : \n");
    a=input(a);
    b=input(b);
    c=input(c);
    output(a,b,c,largest(a,b,c));
    return 0;
}

