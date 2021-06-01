#include<stdio.h>
void input(int *a,int *b, int *c)
{
    printf("enter three number :\n");
    scanf("%d %d %d",a,b,c);
}
int largest(int a, int b, int c)
{
    if (a>b && a>c)
      return a;
        else if (b>c)
          return b;
    else
      return c;
}
void output(int a, int b, int c , int d)
{
     if(a==b && b==c)
    {
        printf("All number are equal \n");
    }
    else if(a==b || b==c || a==c )
    {
        printf("two numbers are equal \n");
        printf("largest of %d , %d and %d is : %d \n", a,b,c,largest(a,b,c));    
    }
    else
    printf("largest of %d , %d and %d is : %d \n", a,b,c,largest(a,b,c));
}
int main()
{
    int a,b,c,d;
    input(&a,&b,&c);
    output(a,b,c,d);
return 0;
}
