#include<stdio.h>
int input (int a)
{    
    scanf("%d",&a);
    return a;
}
int largest(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void output(int a,int b, int c)
{
    printf("Largest of %d and %d is: %d \n",a,b,c);
}
int main()
{
    int a,b;
      printf("Enter number a : \n");
      a=input(a);
      printf("Enter number b : \n");
      b=input(b);
      output(a,b,largest(a,b));
      return 0;
}

